#include "backend.h"

#include "log/log.h"
#include "log/abort.h"

#include "config/config.h"
#include "config/paths.h"

#include "config/device_profile.h"

#include "input_profile.h"
#include "input_profiles/oculus_touch.h"
#include "input_profiles/vive_controller.h"

#include "pose_set.h"
#include "legacy_input.h"

#include <GL/glx.h>
#include <GL/glext.h>

#include <string>
#include <cmath>
#include <cstring>

using namespace vapor;

Backend::Backend()
{
    config::paths::setDataDirs();
    config::config::loadConfig();

    this->instance = new OpenXR::Instance("VapoR", {"XR_KHR_convert_timespec_time"});
    this->session = new OpenXR::Session(*this->instance, this->instance->getSystem());
    xrGetInstanceProcAddr(this->instance->handle, "xrConvertTimespecTimeToTimeKHR", (PFN_xrVoidFunction*) &xrConvertTimespecTimeToTimeKHR);

    int v;
    this->instance->getViewConfiguration(this->session->system, &this->renderWidth, &this->renderHeight, &v, &v, &v, &v);
    this->swapchains[0] = new OpenXR::Swapchain(*this->session, this->renderWidth, this->renderHeight, 1, GL_SRGB8_ALPHA8);
    this->swapchains[1] = new OpenXR::Swapchain(*this->session, this->renderWidth, this->renderHeight, 1, GL_SRGB8_ALPHA8);
    this->framebuffer = new OpenGL::Framebuffer(this->renderWidth, this->renderHeight);
    for (int i = 0; i < 4; i++)
    {
        this->srcTextures[i] = new OpenGL::Texture();
    }
    this->srcFramebuffer = new OpenGL::Framebuffer(this->renderWidth, this->renderHeight);
    PFNGLCREATEMEMORYOBJECTSEXTPROC glCreateMemoryObjectsEXT = (PFNGLCREATEMEMORYOBJECTSEXTPROC) glXGetProcAddress((const GLubyte*) "glCreateMemoryObjectsEXT");
    glCreateMemoryObjectsEXT(4, this->externalMemory);
    ABORT_ON_OPENGL_ERROR();

    this->viewSpace = new OpenXR::Space(*this->session, XR_REFERENCE_SPACE_TYPE_VIEW, OpenXR::IDENTITY_POSE);
    this->localSpace = new OpenXR::Space(*this->session, XR_REFERENCE_SPACE_TYPE_LOCAL, OpenXR::IDENTITY_POSE);
    this->localFloorSpace = new OpenXR::Space(*this->session, XR_REFERENCE_SPACE_TYPE_LOCAL_FLOOR, OpenXR::IDENTITY_POSE);

    LOG("Using device profile %s", config::config::deviceProfileName.c_str());
    config::DeviceProfile deviceProfile;
    if (!deviceProfile.populateFromJSON(config::paths::selectDataDirForFile("device_profiles/" + config::config::deviceProfileName + ".json")))
    {
        ABORT("Failed to load device profile");
    }
    if (deviceProfile.inputProfileName == "oculus_touch")
    {
        this->inputProfile = new input_profile::profiles::OculusTouch();
    }
    else if (deviceProfile.inputProfileName == "vive_controller")
    {
        this->inputProfile = new input_profile::profiles::ViveController();
    }
    else
    {
        ABORT("Unknown input profile %s", deviceProfile.inputProfileName.c_str());
    }
    this->devicePropertySets = new DevicePropertySet[3];
    if (!this->devicePropertySets[0].populateFromJSON(config::paths::selectDataDirForFile("property_sets/" + deviceProfile.hmdPropertySetName + ".json")))
    {
        ABORT("Failed to load property set %s", deviceProfile.hmdPropertySetName.c_str());
    }
    if (!this->devicePropertySets[1].populateFromJSON(config::paths::selectDataDirForFile("property_sets/" + deviceProfile.controllerPropertySetNames[0] + ".json")))
    {
        ABORT("Failed to load property set %s", deviceProfile.controllerPropertySetNames[0].c_str());
    }
    if (!this->devicePropertySets[2].populateFromJSON(config::paths::selectDataDirForFile("property_sets/" + deviceProfile.controllerPropertySetNames[1] + ".json")))
    {
        ABORT("Failed to load property set %s", deviceProfile.controllerPropertySetNames[1].c_str());
    }
    this->renderModelLoader = new RenderModelLoader();
    this->deviceRenderModelNames = new std::string[3];
    this->deviceRenderModelNames[0] = deviceProfile.hmdRenderModelName;
    this->deviceRenderModelNames[1] = deviceProfile.controllerRenderModelNames[0];
    this->deviceRenderModelNames[2] = deviceProfile.controllerRenderModelNames[1];
    for (int i = 0; i < 3; i++)
    {
        if (!this->renderModelLoader->addDefinitionFromJSON(config::paths::selectDataDirForFile("render_models/" + this->deviceRenderModelNames[i] + ".json")))
        {
            LOG("Failed to load render model %s", this->deviceRenderModelNames[i].c_str());
        }
    }

    int inputsCount = this->inputProfile->getOpenXRInputsCount();
    const input_profile::OpenXRInputDescription* inputs = this->inputProfile->getOpenXRInputs();
    this->openXRInputs = std::vector<input_profile::OpenXRInputDescription>(inputs, inputs + inputsCount);
    this->actionSet = new OpenXR::ActionSet(*this->instance, "vapor", "VapoR", 0);
    std::vector<OpenXR::ActionSet::ActionBinding> actionSetBindings;
    for (int i = 0; i < inputsCount; i++)
    {
        XrActionType actionType;
        switch (inputs[i].type)
        {
            case input_profile::OpenXRInputType::BOOLEAN:
                actionType = XR_ACTION_TYPE_BOOLEAN_INPUT;
                break;
            case input_profile::OpenXRInputType::FLOAT:
                actionType = XR_ACTION_TYPE_FLOAT_INPUT;
                break;
            case input_profile::OpenXRInputType::VECTOR2:
                actionType = XR_ACTION_TYPE_VECTOR2F_INPUT;
                break;
            case input_profile::OpenXRInputType::POSE:
                actionType = XR_ACTION_TYPE_POSE_INPUT;
                break;
            case input_profile::OpenXRInputType::HAPTIC:
                actionType = XR_ACTION_TYPE_VIBRATION_OUTPUT;
                break;
        }
        OpenXR::Action* action = new OpenXR::Action(*this->actionSet, "input_" + std::to_string(i), "Input " + std::to_string(i), actionType, {});
        this->actions.push_back(action);
        OpenXR::ActionSet::ActionBinding binding(*action, inputs[i].path);
        actionSetBindings.push_back(binding);
    }
    this->actionSet->suggestBindings(this->inputProfile->getOpenXRInteractionProfileName(), actionSetBindings);
    this->session->attachActionSets({this->actionSet});
    for (int i = 0; i < inputsCount; i++)
    {
        OpenXR::Space* actionSpace = nullptr;
        if (inputs[i].type == input_profile::OpenXRInputType::POSE)
        {
            actionSpace = new OpenXR::Space(*this->session, *this->actions[i], "", OpenXR::IDENTITY_POSE);
        }
        this->actionSpaces.push_back(actionSpace);
    }

    this->frameQueue = new FrameQueue(this->renderWidth, this->renderHeight);

    this->hapticQueue = new HapticQueue();
}

Backend::~Backend()
{
    delete this->srcFramebuffer;
    for (int i = 0; i < 4; i++)
    {
        delete this->srcTextures[i];
    }
    delete this->framebuffer;
    delete this->swapchains[0];
    delete this->swapchains[1];
    PFNGLDELETEMEMORYOBJECTSEXTPROC glDeleteMemoryObjectsEXT = (PFNGLDELETEMEMORYOBJECTSEXTPROC) glXGetProcAddress((const GLubyte*) "glDeleteMemoryObjectsEXT");
    glDeleteMemoryObjectsEXT(4, this->externalMemory);
    ABORT_ON_OPENGL_ERROR();

    delete this->viewSpace;
    delete this->localSpace;
    delete this->localFloorSpace;

    delete this->session;

    delete this->actionSet;
    /*for (int i = 0; i < this->actions.size(); i++)
    {
        if (this->actionSpaces[i] != nullptr)
        {
            delete this->actionSpaces[i];
        }
        delete this->actions[i];
    }*/
    this->actions.clear();
    this->actionSpaces.clear();

    delete this->instance;

    delete this->frameQueue;
    delete this->hapticQueue;

    delete this->inputProfile;
    delete[] this->devicePropertySets;
    delete this->renderModelLoader;
}

void Backend::loop()
{
    bool sessionRunning = false;
    XrEventDataBuffer event;
    for (;;)
    {
        bool haveWaitedFrame;
        XrTime displayTime;
        XrDuration displayDuration;
        bool shouldRender;
        if (sessionRunning)
        {
            displayTime = this->session->waitFrame(&shouldRender, &displayDuration);
            haveWaitedFrame = true;
        }
        else
        {
            haveWaitedFrame = false;
        }

        bool exit = false;
        while (this->instance->pollEvent(&event))
        {
            if (event.type == XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED)
            {
                switch ((*reinterpret_cast<XrEventDataSessionStateChanged*>(&event)).state)
                {
                    case XR_SESSION_STATE_READY:
                        this->session->begin();
                        sessionRunning = true;
                        break;
                    case XR_SESSION_STATE_STOPPING:
                        if (sessionRunning)
                        {
                            this->session->end();
                            sessionRunning = false;
                            haveWaitedFrame = false;
                        }
                        break;
                    case XR_SESSION_STATE_EXITING:
                        exit = true;
                        break;
                }
            }
            else if (event.type == XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING)
            {
                XrReferenceSpaceType referenceSpaceType = (*reinterpret_cast<XrEventDataReferenceSpaceChangePending*>(&event)).referenceSpaceType;
                XrTime changeTime = (*reinterpret_cast<XrEventDataReferenceSpaceChangePending*>(&event)).changeTime;
                switch (referenceSpaceType)
                {
                    case XR_REFERENCE_SPACE_TYPE_LOCAL:
                        localReferenceSpaceChangeTime = changeTime;
                        break;
                    case XR_REFERENCE_SPACE_TYPE_LOCAL_FLOOR:
                        localFloorReferenceSpaceChangeTime = changeTime;
                        break;
                }
            }
        }
        if (exit)
        {
            break;
        }

        if (haveWaitedFrame)
        {
            this->step(displayTime, displayDuration);
            this->session->beginFrame();
            std::vector<OpenXR::Layer> layers = this->render(displayTime);
            this->session->endFrame(displayTime, layers);
        }
    }
}

void Backend::waitForFirstFrame()
{
    if (this->frameStates.getFrameCounter() == 0)
    {
        this->frameStates.waitForNextFrame();
    }
}

void Backend::requestExit()
{
    this->session->requestExit();
}

//

void Backend::queueResetSeatedZeroPose(bool fromSystemMenu)
{
    if (fromSystemMenu)
    {
        this->needSeatedZeroPoseResetFromSystemMenu = true;
    }
    else
    {
        this->needSeatedZeroPoseReset = true;
    }
}

void Backend::queueResetStandingZeroPose(bool fromSystemMenu)
{
    if (fromSystemMenu)
    {
        this->needStandingZeroPoseResetFromSystemMenu = true;
    }
    else
    {
        this->needStandingZeroPoseReset = true;
    }
}

//

static inline int calculateRefreshRateFromPredictedDisplayDuration(XrDuration duration)
{
    return (int) std::lround(1000000000.0 / (double) duration);
}

static inline float extractYaw(const XrQuaternionf& orientation)
{
    XrQuaternionf q = {
        .x = 1.0f,
        .y = 0.0f,
        .z = 0.0f,
        .w = 0.0f
    };

    q = {
        .x = - q.w * orientation.x + q.x * orientation.w - q.y * orientation.z + q.z * orientation.y,
        .y = - q.w * orientation.y + q.y * orientation.w - q.z * orientation.x + q.x * orientation.z,
        .z = - q.w * orientation.z + q.z * orientation.w - q.x * orientation.y + q.y * orientation.x,
        .w = + q.w * orientation.w + q.x * orientation.x + q.y * orientation.y + q.z * orientation.z
    };

    q = {
        .x = orientation.w * q.x + orientation.x * q.w + orientation.y * q.z - orientation.z * q.y,
        .y = orientation.w * q.y + orientation.y * q.w + orientation.z * q.x - orientation.x * q.z,
        .z = orientation.w * q.z + orientation.z * q.w + orientation.x * q.y - orientation.y * q.x,
        .w = orientation.w * q.w - orientation.x * q.x - orientation.y * q.y - orientation.z * q.z
    };

    return std::atan2(q.z, q.x);
}

static inline OpenXR::PoseAndVelocity offsetPose(OpenXR::PoseAndVelocity pose, const Backend::ZeroPose& zeroPose)
{
    if (pose.poseValid)
    {
        pose.pose.position.x -= zeroPose.position.x;
        pose.pose.position.y -= zeroPose.position.y;
        pose.pose.position.z -= zeroPose.position.z;
        float x2 = pose.pose.position.x * std::cos(zeroPose.yaw) + pose.pose.position.z * std::sin(zeroPose.yaw);
        float z2 = pose.pose.position.z * std::cos(zeroPose.yaw) - pose.pose.position.x * std::sin(zeroPose.yaw);
        pose.pose.position.x = x2;
        pose.pose.position.z = z2;

        float w = std::cos(zeroPose.yaw / 2.0f);
        float y = std::sin(zeroPose.yaw / 2.0f);
        float w1 = w * pose.pose.orientation.w - y * pose.pose.orientation.y;
        float x1 = w * pose.pose.orientation.x + y * pose.pose.orientation.z;
        float y1 = w * pose.pose.orientation.y + y * pose.pose.orientation.w;
        float z1 = w * pose.pose.orientation.z - y * pose.pose.orientation.x;
        pose.pose.orientation.w = w1;
        pose.pose.orientation.x = x1;
        pose.pose.orientation.y = y1;
        pose.pose.orientation.z = z1;
    }

    if (pose.linearVelocityValid)
    {
        float x = pose.linearVelocity.x * std::cos(zeroPose.yaw) + pose.linearVelocity.z * std::sin(zeroPose.yaw);
        float z = pose.linearVelocity.z * std::cos(zeroPose.yaw) - pose.linearVelocity.x * std::sin(zeroPose.yaw);
        pose.linearVelocity.x = x;
        pose.linearVelocity.z = z;
    }

    if (pose.angularVelocityValid)
    {
        float x = pose.angularVelocity.x * std::cos(zeroPose.yaw) + pose.angularVelocity.z * std::sin(zeroPose.yaw);
        float z = pose.angularVelocity.z * std::cos(zeroPose.yaw) - pose.angularVelocity.x * std::sin(zeroPose.yaw);
        pose.angularVelocity.x = x;
        pose.angularVelocity.z = z;
    }

    return pose;
}

void Backend::step(XrTime displayTime, XrDuration displayDuration)
{
    if (this->localReferenceSpaceChangeTime != 0 && displayTime >= this->localReferenceSpaceChangeTime)
    {
        this->needSeatedZeroPoseResetFromSystemMenu = true;
        this->localReferenceSpaceChangeTime = 0;
    }
    if (this->localFloorReferenceSpaceChangeTime != 0 && displayTime >= this->localFloorReferenceSpaceChangeTime)
    {
        this->needStandingZeroPoseResetFromSystemMenu = true;
        this->localFloorReferenceSpaceChangeTime = 0;
    }

    if (this->needSeatedZeroPoseReset || this->needSeatedZeroPoseResetFromSystemMenu || !this->seatedZeroPoseInitialised)
    {
        OpenXR::Pose pose = this->viewSpace->locate(*this->localSpace, displayTime);
        if (pose.poseValid)
        {
            this->seatedZeroPose.position = pose.pose.position;
            this->seatedZeroPose.yaw = extractYaw(pose.pose.orientation);
            TRACE_F("Reset seated zero pose %f %f %f %f", this->seatedZeroPose.position.x, this->seatedZeroPose.position.y, this->seatedZeroPose.position.z, this->seatedZeroPose.yaw);

            bool emitEvent = this->needSeatedZeroPoseReset || this->needSeatedZeroPoseResetFromSystemMenu;
            bool fromSystemMenu = this->needSeatedZeroPoseResetFromSystemMenu;
            this->needSeatedZeroPoseReset = false;
            this->needSeatedZeroPoseResetFromSystemMenu = false;
            this->seatedZeroPoseInitialised = true;

            if (emitEvent)
            {
                openvr::Event_0_9_15 event {
                    .type = openvr::EventType::SEATED_ZERO_POSE_RESET,
                    .trackedDeviceIndex = 0,
                    .ageSeconds = 0.0f,
                    .data {
                        .zeroPoseReset {
                            .resetBySystemMenu = fromSystemMenu
                        }
                    }
                };
                eventQueue.putEvent(event);
            }
        }
    }
    if (this->needStandingZeroPoseReset || this->needStandingZeroPoseResetFromSystemMenu || !this->standingZeroPoseInitialised)
    {
        OpenXR::Pose pose = this->viewSpace->locate(*this->localFloorSpace, displayTime);
        if (pose.poseValid)
        {
            this->standingZeroPose.position = pose.pose.position;
            this->standingZeroPose.position.y = 0.0f;
            this->standingZeroPose.yaw = extractYaw(pose.pose.orientation);
            TRACE_F("Reset standing zero pose %f %f %f %f", this->standingZeroPose.position.x, this->standingZeroPose.position.y, this->standingZeroPose.position.z, this->standingZeroPose.yaw);

            bool emitEvent = this->needStandingZeroPoseReset || this->needStandingZeroPoseResetFromSystemMenu;
            bool fromSystemMenu = this->needStandingZeroPoseResetFromSystemMenu;
            this->needStandingZeroPoseReset = false;
            this->needStandingZeroPoseResetFromSystemMenu = false;
            this->standingZeroPoseInitialised = true;

            if (emitEvent)
            {
                openvr::Event_0_9_15 event {
                    .type = openvr::EventType::STANDING_ZERO_POSE_RESET,
                    .trackedDeviceIndex = 0,
                    .ageSeconds = 0.0f,
                    .data {
                        .zeroPoseReset {
                            .resetBySystemMenu = fromSystemMenu
                        }
                    }
                };
                eventQueue.putEvent(event);
            }
        }
    }

    //

    this->session->syncActions({this->actionSet});

    input_profile::OpenXRInputState* openXRInputStates = new input_profile::OpenXRInputState[this->openXRInputs.size()];
    for (int i = 0; i < this->openXRInputs.size(); i++)
    {
        input_profile::OpenXRInputDescription& input = this->openXRInputs[i];
        OpenXR::Action* action = this->actions[i];
        input_profile::OpenXRInputState& state = openXRInputStates[i];
        state.type = input.type;
        switch (input.type)
        {
            case input_profile::OpenXRInputType::BOOLEAN:
                state.data.b = action->getStateBool(*this->session, "", &state.changeTime);
                break;
            case input_profile::OpenXRInputType::FLOAT:
                state.data.f = action->getStateFloat(*this->session, "", &state.changeTime);
                break;
            case input_profile::OpenXRInputType::VECTOR2:
                state.data.vec2 = action->getStateVector(*this->session, "", &state.changeTime);
                break;
            case input_profile::OpenXRInputType::POSE:
                state.data.pose.local = offsetPose(this->actionSpaces[i]->locateWithVelocity(*this->localSpace, displayTime), this->seatedZeroPose);
                state.data.pose.localFloor = offsetPose(this->actionSpaces[i]->locateWithVelocity(*this->localFloorSpace, displayTime), this->standingZeroPose);
                state.data.pose.localNextFrame = offsetPose(this->actionSpaces[i]->locateWithVelocity(*this->localSpace, displayTime + displayDuration), this->seatedZeroPose);
                state.data.pose.localFloorNextFrame = offsetPose(this->actionSpaces[i]->locateWithVelocity(*this->localFloorSpace, displayTime + displayDuration), this->standingZeroPose);
                {
                    static float identityOffset[3][4] = {{1.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f, 0.0f}};
                    std::memcpy(state.data.pose.offsetMatrix, identityOffset, sizeof(float[3][4]));
                }
                state.changeTime = displayTime;
                break;
        }
    }

    std::vector<input_profile::OpenVRInputState> openVRInputStates;
    int openVRInputsCount = this->inputProfile->getOpenVRInputsCount();
    openVRInputStates.reserve(openVRInputsCount);
    for (int i = 0; i < openVRInputsCount; i++)
    {
        openVRInputStates.push_back(this->inputProfile->getOpenVRInputState(i, openXRInputStates));
    }

    //

    this->frameStates.lock();

    this->frameStates.postFrame(FrameState {
        .index = 0,

        .displayTime = displayTime,

        .views = this->session->locateViews(displayTime, *this->viewSpace),

        .renderViews = this->session->locateViews(displayTime, *this->localSpace),

        .head = PoseSet {
            .local = offsetPose(this->viewSpace->locateWithVelocity(*this->localSpace, displayTime), this->seatedZeroPose),
            .localFloor = offsetPose(this->viewSpace->locateWithVelocity(*this->localFloorSpace, displayTime), this->standingZeroPose),
            .localNextFrame = offsetPose(this->viewSpace->locateWithVelocity(*this->localSpace, displayTime + displayDuration), this->seatedZeroPose),
            .localFloorNextFrame = offsetPose(this->viewSpace->locateWithVelocity(*this->localFloorSpace, displayTime + displayDuration), this->standingZeroPose),
            .offsetMatrix = {{1.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f, 0.0f}}
        },
        .inputStates = openVRInputStates,
        .controllerPoses = {
            this->inputProfile->getOpenVRControllerPose(0, openVRInputStates.data()).data.pose,
            this->inputProfile->getOpenVRControllerPose(1, openVRInputStates.data()).data.pose
        },
        .legacyInputStates = {
            this->inputProfile->getOpenVRLegacyInputState(0, openVRInputStates.data()),
            this->inputProfile->getOpenVRLegacyInputState(1, openVRInputStates.data())
        }
    });

    LegacyInputHelper::emitChangeEvents(this->frameStates, this->eventQueue);

    this->refreshRate = calculateRefreshRateFromPredictedDisplayDuration(displayDuration);

    this->frameStates.unlock();

    //

    HapticQueue::HapticEvent hapticEvent;
    while (this->hapticQueue->pollHapticEvent(&hapticEvent))
    {
        XrDuration duration = hapticEvent.durationUs != 0 ? hapticEvent.durationUs * 1000l : XR_MIN_HAPTIC_DURATION;
        float frequency;
        float amplitude;
        int actionIndex;
        if (hapticEvent.fromLegacyInput)
        {
            frequency = XR_FREQUENCY_UNSPECIFIED;
            amplitude = 1.0f;
            actionIndex = this->inputProfile->getOpenXRHapticActionIndexForLegacyInput(hapticEvent.inputOrControllerIndex);
        }
        else
        {
            frequency = hapticEvent.frequency;
            amplitude = hapticEvent.amplitude;
            actionIndex = this->inputProfile->getOpenXRHapticActionIndex(hapticEvent.inputOrControllerIndex);
        }
        this->actions[actionIndex]->applyHapticFeedback(*this->session, "", duration, frequency, amplitude);
    }
}

std::vector<OpenXR::Layer> Backend::render(XrTime displayTime)
{
    this->frameQueue->lockBufferSwap();

    glViewport(0, 0, this->renderWidth, this->renderHeight);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, framebuffer->id);

    OpenXR::ViewPair views = this->frameQueue->hasDisplayFrame() ? this->frameQueue->getDisplayViews() : this->session->locateViews(displayTime, *this->localSpace);

    for (int eye = 0; eye < 2; eye++)
    {
        GLuint image = swapchains[eye]->acquireImage();
        if (!swapchains[eye]->waitSwapchain(10000000l))
        {
            ABORT("Timeout waiting for swapchain image");
        }
        framebuffer->bindTexture(image);

        if (this->frameQueue->hasDisplayFrame())
        {
            if (!this->externalMemoryImported)
            {
                PFNGLIMPORTMEMORYFDEXTPROC glImportMemoryFdEXT = (PFNGLIMPORTMEMORYFDEXTPROC) glXGetProcAddress((const GLubyte*) "glImportMemoryFdEXT");
                PFNGLTEXSTORAGEMEM2DEXTPROC glTexStorageMem2DEXT = (PFNGLTEXSTORAGEMEM2DEXTPROC) glXGetProcAddress((const GLubyte*) "glTexStorageMem2DEXT");
                for (int i = 0; i < 4; i++)
                {
                    glImportMemoryFdEXT(this->externalMemory[i], this->frameQueue->memory[i].size, GL_HANDLE_TYPE_OPAQUE_FD_EXT, this->frameQueue->memory[i].fd);
                    ABORT_ON_OPENGL_ERROR();
                    glBindTexture(GL_TEXTURE_2D, this->srcTextures[i]->id);
                    glTexStorageMem2DEXT(GL_TEXTURE_2D, 1, GL_RGBA8, this->renderWidth, this->renderHeight, this->externalMemory[i], 0);
                    ABORT_ON_OPENGL_ERROR();
                }
                glBindTexture(GL_TEXTURE_2D, 0);
                this->externalMemoryImported = true;
            }

            OpenGL::Texture* srcTexture = this->srcTextures[this->frameQueue->getDisplayBufferIndex(eye)];
            glBindFramebuffer(GL_READ_FRAMEBUFFER, srcFramebuffer->id);
            glFramebufferTexture2D(GL_READ_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, srcTexture->id, 0);
            ABORT_ON_OPENGL_ERROR();
            glBlitFramebuffer(0, 0, this->renderWidth, this->renderHeight, 0, 0, this->renderWidth, this->renderHeight, GL_COLOR_BUFFER_BIT, GL_NEAREST);
            ABORT_ON_OPENGL_ERROR();
        }
        else
        {
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            ABORT_ON_OPENGL_ERROR();
        }

        swapchains[eye]->releaseImage();
    }

    std::vector<OpenXR::Layer> layers = {
        OpenXR::Layer {
            .space = *this->localSpace,

            .leftPose = views.left.pose,
            .leftFov = views.left.fov,
            .leftSwapchain = *swapchains[0],
            .leftImageX = 0,
            .leftImageY = 0,
            .leftImageWidth = this->renderWidth,
            .leftImageHeight = this->renderHeight,
            .leftImageIndex = 0,

            .rightPose = views.right.pose,
            .rightFov = views.right.fov,
            .rightSwapchain = *swapchains[1],
            .rightImageX = 0,
            .rightImageY = 0,
            .rightImageWidth = this->renderWidth,
            .rightImageHeight = this->renderHeight,
            .rightImageIndex = 0
        }
    };

    this->frameQueue->unlockBufferSwap();

    return layers;
}
