#include "openxr.h"

#include <cstring>

using namespace OpenXR;

Instance::Instance(const std::string& applicationName, const std::vector<std::string>& extensions)
{
    const char* layers[] = {};

    int extensionsCount = extensions.size();
    int extensionsActualCount = extensionsCount + 2;
    const char* extensionsActual[extensionsActualCount];
    extensionsActual[0] = (const char*) XR_KHR_OPENGL_ENABLE_EXTENSION_NAME;
    extensionsActual[1] = (const char*) XR_EXT_LOCAL_FLOOR_EXTENSION_NAME;
    for (int i = 0; i < extensionsCount; i++)
    {
        extensionsActual[i + 2] = extensions[i].c_str();
    }

    XrInstanceCreateInfo instanceCreateInfo {
        .type = XR_TYPE_INSTANCE_CREATE_INFO,
        .next = nullptr,
        .createFlags = 0,
        .applicationInfo = {
            .applicationVersion = 1, .engineName = "none", .engineVersion = 1, .apiVersion = XR_API_VERSION_1_0
        },
        .enabledApiLayerCount = 0,
        .enabledApiLayerNames = layers,
        .enabledExtensionCount = (uint32_t) extensionsActualCount,
        .enabledExtensionNames = extensionsActual
    };
    std::strcpy(instanceCreateInfo.applicationInfo.applicationName, applicationName.c_str());

    ABORT_ON_OPENXR_ERROR(xrCreateInstance(&instanceCreateInfo, &this->handle));
}

Instance::~Instance()
{
    xrDestroyInstance(this->handle);
    this->handle = XR_NULL_HANDLE;
}

XrPath Instance::getPath(const std::string& pathString) const
{
    XrPath path;
    ABORT_ON_OPENXR_ERROR(xrStringToPath(this->handle, pathString.c_str(), &path));
    return path;
}

XrSystemId Instance::getSystem() const
{
    XrSystemGetInfo systemGetInfo {
        .type = XR_TYPE_SYSTEM_GET_INFO,
        .next = nullptr,
        .formFactor = XR_FORM_FACTOR_HEAD_MOUNTED_DISPLAY
    };
    XrSystemId systemId;
    ABORT_ON_OPENXR_ERROR(xrGetSystem(this->handle, &systemGetInfo, &systemId));
    return systemId;
}

void Instance::getViewConfiguration(XrSystemId system, int* recommendedWidth, int* recommendedHeight, int* recommendedSampleCount, int* maxWidth, int* maxHeight, int* maxSampleCount) const
{
    uint32_t count;
    ABORT_ON_OPENXR_ERROR(xrEnumerateViewConfigurationViews(this->handle, system, XR_VIEW_CONFIGURATION_TYPE_PRIMARY_STEREO, 0, &count, nullptr));
    XrViewConfigurationView* views = new XrViewConfigurationView[count];
    for (int i = 0; i < count; i++)
    {
        views[i].type = XR_TYPE_VIEW_CONFIGURATION_VIEW;
        views[i].next = nullptr;
    }
    ABORT_ON_OPENXR_ERROR(xrEnumerateViewConfigurationViews(this->handle, system, XR_VIEW_CONFIGURATION_TYPE_PRIMARY_STEREO, count, &count, views));
    *recommendedWidth = views[0].recommendedImageRectWidth;
    *recommendedHeight = views[0].recommendedImageRectHeight;
    *recommendedSampleCount = views[0].recommendedSwapchainSampleCount;
    *maxWidth = views[0].maxImageRectWidth;
    *maxHeight = views[0].maxImageRectHeight;
    *maxSampleCount = views[0].maxSwapchainSampleCount;
    delete[] views;
}

bool Instance::pollEvent(XrEventDataBuffer* event) const
{
    event->type = XR_TYPE_EVENT_DATA_BUFFER;
    event->next = nullptr;
    XrResult result = xrPollEvent(this->handle, event);
    ABORT_ON_OPENXR_ERROR(result);
    return result != XR_EVENT_UNAVAILABLE;
}

Session::Session(const Instance& instance, XrSystemId system): instance(instance), system(system)
{
    this->xDisplay = XOpenDisplay(nullptr);
    if (!this->xDisplay)
    {
        ABORT("Failed to open X11 display");
    }
    int fbConfigsCounts;
    GLXFBConfig* fbConfigs = glXChooseFBConfig(this->xDisplay, DefaultScreen(this->xDisplay), (int[]) {
        GLX_X_RENDERABLE, True,
        GLX_DRAWABLE_TYPE, GLX_PBUFFER_BIT,
        GLX_RENDER_TYPE, GLX_RGBA_BIT,
        GLX_RED_SIZE, 8,
        GLX_GREEN_SIZE, 8,
        GLX_BLUE_SIZE, 8,
        GLX_ALPHA_SIZE, 8,
        GLX_DEPTH_SIZE, 24,
        None
    }, &fbConfigsCounts);
    if (!fbConfigs || fbConfigsCounts == 0)
    {
        ABORT("Failed to find framebuffer configuration");
    }
    GLXFBConfig fbConfig = fbConfigs[0];
    XFree(fbConfigs);
    this->glxContext = glXCreateNewContext(this->xDisplay, fbConfig, GLX_RGBA_TYPE, NULL, True);
    if (!this->glxContext) {
        ABORT("Failed to create OpenGL context");
    }
    this->glxPbuffer = glXCreatePbuffer(this->xDisplay, fbConfig, (int[]) {
        GLX_WIDTH, 16,
        GLX_HEIGHT, 16,
        None
    });
    if (!this->glxPbuffer)
    {
        ABORT("Failed to create OpenGL pbuffer");
    }
    if (!glXMakeContextCurrent(this->xDisplay, this->glxPbuffer, this->glxPbuffer, this->glxContext))
    {
        ABORT("Failed to make OpenGL context current");
    }

    PFN_xrGetOpenGLGraphicsRequirementsKHR xrGetOpenGLGraphicsRequirementsKHR;
    xrGetInstanceProcAddr(this->instance.handle, "xrGetOpenGLGraphicsRequirementsKHR", (PFN_xrVoidFunction*) &xrGetOpenGLGraphicsRequirementsKHR);
    XrGraphicsRequirementsOpenGLKHR graphicsRequirementsOpenGlKHR {
        .type = XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_KHR,
        .next = nullptr
    };
    xrGetOpenGLGraphicsRequirementsKHR(this->instance.handle, this->system, &graphicsRequirementsOpenGlKHR);

    XrSessionCreateInfo sessionCreateInfo {
        .type = XR_TYPE_SESSION_CREATE_INFO,
        .next = nullptr,
        .createFlags = 0,
        .systemId = this->system
    };
    XrGraphicsBindingOpenGLXlibKHR graphicsBindingOpenGlXlibKhr {
        .type = XR_TYPE_GRAPHICS_BINDING_OPENGL_XLIB_KHR,
        .next = nullptr,
        .xDisplay = this->xDisplay,
        .glxFBConfig = fbConfig,
        .glxDrawable = this->glxPbuffer,
        .glxContext = this->glxContext
    };
    sessionCreateInfo.next = &graphicsBindingOpenGlXlibKhr;
    ABORT_ON_OPENXR_ERROR(xrCreateSession(this->instance.handle, &sessionCreateInfo, &this->handle));
}

Session::~Session()
{
    xrDestroySession(this->handle);
    this->handle = XR_NULL_HANDLE;

    glXDestroyContext(this->xDisplay, this->glxContext);
    glXDestroyPbuffer(this->xDisplay, this->glxPbuffer);
    XCloseDisplay(this->xDisplay);
}

void Session::attachActionSets(const std::vector<const ActionSet*>& actionSets) const
{
    int actionSetsCount = actionSets.size();
    XrActionSet* actionSetsArray = new XrActionSet[actionSetsCount];
    for (int i = 0; i < actionSetsCount; i++)
    {
        actionSetsArray[i] = actionSets[i]->handle;
    }
    XrSessionActionSetsAttachInfo sessionActionSetsAttachInfo {
        .type = XR_TYPE_SESSION_ACTION_SETS_ATTACH_INFO,
        .next = nullptr,
        .countActionSets = (uint32_t) actionSetsCount,
        .actionSets = actionSetsArray
    };
    ABORT_ON_OPENXR_ERROR(xrAttachSessionActionSets(this->handle, &sessionActionSetsAttachInfo));
    delete[] actionSetsArray;
}

void Session::begin() const
{
    XrSessionBeginInfo sessionBeginInfo {
        .type = XR_TYPE_SESSION_BEGIN_INFO,
        .next = nullptr,
        .primaryViewConfigurationType = XR_VIEW_CONFIGURATION_TYPE_PRIMARY_STEREO
    };
    ABORT_ON_OPENXR_ERROR(xrBeginSession(this->handle, &sessionBeginInfo));
}

void Session::end() const
{
    ABORT_ON_OPENXR_ERROR(xrEndSession(this->handle));
}

void Session::requestExit() const
{
    ABORT_ON_OPENXR_ERROR(xrRequestExitSession(this->handle));
}

XrTime Session::waitFrame(bool* shouldRender, XrDuration* displayDuration) const
{
    XrFrameWaitInfo frameWaitInfo {
        .type = XR_TYPE_FRAME_WAIT_INFO,
        .next = nullptr
    };
    XrFrameState frameState {
        .type = XR_TYPE_FRAME_STATE,
        .next = nullptr
    };
    ABORT_ON_OPENXR_ERROR(xrWaitFrame(this->handle, &frameWaitInfo, &frameState));
    if (shouldRender != nullptr)
    {
        *shouldRender = (frameState.shouldRender == XR_TRUE);
    }
    if (displayDuration != nullptr)
    {
        *displayDuration = frameState.predictedDisplayPeriod;
    }
    return frameState.predictedDisplayTime;
}

void Session::beginFrame() const
{
    XrFrameBeginInfo frameBeginInfo {
        .type = XR_TYPE_FRAME_BEGIN_INFO,
        .next = nullptr
    };
    ABORT_ON_OPENXR_ERROR(xrBeginFrame(this->handle, &frameBeginInfo));
}

void Session::endFrame(XrTime displayTime, const std::vector<Layer>& layers) const
{
    int layersCount = layers.size();
    XrCompositionLayerBaseHeader** layersArray = new XrCompositionLayerBaseHeader*[layersCount];
    for (int i = 0; i < layersCount; i++)
    {
        const Layer& layer = layers[i];
        XrCompositionLayerProjectionView* views = new XrCompositionLayerProjectionView[2];
        views[0] = {
            .type = XR_TYPE_COMPOSITION_LAYER_PROJECTION_VIEW,
            .next = nullptr,
            .pose = layer.leftPose,
            .fov = layer.leftFov,
            .subImage = XrSwapchainSubImage {
                .swapchain = layer.leftSwapchain.handle,
                .imageRect = XrRect2Di {
                    .offset = XrOffset2Di {
                        .x = layer.leftImageX,
                        .y = layer.leftImageY
                    },
                    .extent = XrExtent2Di {
                        .width = layer.leftImageWidth,
                        .height = layer.leftImageHeight
                    }
                },
                .imageArrayIndex = (uint32_t) layer.leftImageIndex
            }
        };
        views[1] = {
            .type = XR_TYPE_COMPOSITION_LAYER_PROJECTION_VIEW,
            .next = nullptr,
            .pose = layer.rightPose,
            .fov = layer.rightFov,
            .subImage = XrSwapchainSubImage {
                .swapchain = layer.rightSwapchain.handle,
                .imageRect = XrRect2Di {
                    .offset = XrOffset2Di {
                        .x = layer.rightImageX,
                        .y = layer.rightImageY
                    },
                    .extent = XrExtent2Di {
                        .width = layer.rightImageWidth,
                        .height = layer.rightImageHeight
                    }
                },
                .imageArrayIndex = (uint32_t) layer.rightImageIndex
            }
        };
        XrCompositionLayerProjection* projectionLayer = new XrCompositionLayerProjection {
            .type = XR_TYPE_COMPOSITION_LAYER_PROJECTION,
            .next = nullptr,
            .layerFlags = XR_COMPOSITION_LAYER_BLEND_TEXTURE_SOURCE_ALPHA_BIT,
            .space = layer.space.handle,
            .viewCount = 2,
            .views = views
        };
        layersArray[i] = (XrCompositionLayerBaseHeader*) projectionLayer;
    }

    XrFrameEndInfo frameEndInfo {
        .type = XR_TYPE_FRAME_END_INFO,
        .next = nullptr,
        .displayTime = displayTime,
        .environmentBlendMode = XR_ENVIRONMENT_BLEND_MODE_OPAQUE,
        .layerCount = (uint32_t) layersCount,
        .layers = layersArray
    };
    ABORT_ON_OPENXR_ERROR(xrEndFrame(this->handle, &frameEndInfo));

    for (int i = 0; i < layersCount; i++)
    {
        if (layersArray[i]->type == XR_TYPE_COMPOSITION_LAYER_PROJECTION)
        {
            delete[] ((XrCompositionLayerProjection*) layersArray[i])->views;
        }
    }
    delete[] layersArray;
}

ViewPair Session::locateViews(XrTime time, const Space& space) const
{
    XrViewLocateInfo viewLocateInfo {
        .type = XR_TYPE_VIEW_LOCATE_INFO,
        .next = nullptr,
        .viewConfigurationType = XR_VIEW_CONFIGURATION_TYPE_PRIMARY_STEREO,
        .displayTime = time,
        .space = space.handle
    };
    XrViewState viewState {
        .type = XR_TYPE_VIEW_STATE,
        .next = nullptr
    };
    uint32_t viewsCount;
    XrView views[] {
        {
            .type = XR_TYPE_VIEW,
            .next = nullptr
        },
        {
            .type = XR_TYPE_VIEW,
            .next = nullptr
        },
    };
    ABORT_ON_OPENXR_ERROR(xrLocateViews(this->handle, &viewLocateInfo, &viewState, 2, &viewsCount, views));

    ViewPair viewPair {
        .left = View {
            .pose = views[0].pose,
            .fov = views[0].fov
        },
        .right = View {
            .pose = views[1].pose,
            .fov = views[1].fov
        }
    };
    return viewPair;
}

void Session::syncActions(const std::vector<const ActionSet*>& activeActionSets) const
{
    int count = activeActionSets.size();
    XrActiveActionSet* activeActionSetsArray = new XrActiveActionSet[count];
    for (int i = 0; i < count; i++)
    {
        activeActionSetsArray[i] = {
            .actionSet = activeActionSets[i]->handle,
            .subactionPath = XR_NULL_PATH
        };
    }
    XrActionsSyncInfo actionsSyncInfo = {
            .type = XR_TYPE_ACTIONS_SYNC_INFO,
            .next = nullptr,
            .countActiveActionSets = (uint32_t) count,
            .activeActionSets = activeActionSetsArray
    };
    ABORT_ON_OPENXR_ERROR(xrSyncActions(this->handle, &actionsSyncInfo));
    delete[] activeActionSetsArray;
}

Swapchain::Swapchain(const Session& session, int width, int height, int sampleCount, GLenum imageFormat)
{
    XrSwapchainCreateInfo swapchainCreateInfo = {
        .type = XR_TYPE_SWAPCHAIN_CREATE_INFO,
        .next = nullptr,
        .createFlags = 0,
        .usageFlags = XR_SWAPCHAIN_USAGE_COLOR_ATTACHMENT_BIT,
        .format = imageFormat,
        .sampleCount = (uint32_t) sampleCount,
        .width = (uint32_t) width,
        .height = (uint32_t) height,
        .faceCount = 1,
        .arraySize = 1,
        .mipCount = 1
    };
    ABORT_ON_OPENXR_ERROR(xrCreateSwapchain(session.handle, &swapchainCreateInfo, &this->handle));

    uint32_t swapchainImagesCount;
    ABORT_ON_OPENXR_ERROR(xrEnumerateSwapchainImages(this->handle, 0, &swapchainImagesCount, nullptr));
    XrSwapchainImageOpenGLKHR* swapchainImages = new XrSwapchainImageOpenGLKHR[swapchainImagesCount];
    for (int i = 0; i < swapchainImagesCount; i++)
    {
        swapchainImages[i].type = XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR;
        swapchainImages[i].next = nullptr;
    }
    ABORT_ON_OPENXR_ERROR(xrEnumerateSwapchainImages(this->handle, swapchainImagesCount, &swapchainImagesCount, (XrSwapchainImageBaseHeader*) swapchainImages));
    this->images = new GLuint[swapchainImagesCount];
    for (int i = 0; i < swapchainImagesCount; i++)
    {
        this->images[i] = swapchainImages[i].image;
    }
}

Swapchain::~Swapchain()
{
    ABORT_ON_OPENXR_ERROR(xrDestroySwapchain(this->handle));
    delete this->images;
}

GLuint Swapchain::acquireImage() const
{
    XrSwapchainImageAcquireInfo acquireInfo {
        .type = XR_TYPE_SWAPCHAIN_IMAGE_ACQUIRE_INFO,
        .next = nullptr
    };
    uint32_t index;
    ABORT_ON_OPENXR_ERROR(xrAcquireSwapchainImage(this->handle, &acquireInfo, &index));
    return this->images[index];
}

void Swapchain::releaseImage() const
{
    XrSwapchainImageReleaseInfo releaseInfo {
        .type = XR_TYPE_SWAPCHAIN_IMAGE_RELEASE_INFO,
        .next = nullptr
    };
    ABORT_ON_OPENXR_ERROR(xrReleaseSwapchainImage(this->handle, &releaseInfo));
}

bool Swapchain::waitSwapchain(XrDuration timeout) const
{
    XrSwapchainImageWaitInfo waitInfo {
        .type = XR_TYPE_SWAPCHAIN_IMAGE_WAIT_INFO,
        .next = nullptr,
        .timeout = timeout
    };
    XrResult result = xrWaitSwapchainImage(this->handle, &waitInfo);
    ABORT_ON_OPENXR_ERROR(result);
    return result != XR_TIMEOUT_EXPIRED;
}

Space::Space(const Session& session, XrReferenceSpaceType referenceSpaceType, const XrPosef& pose)
{
    XrReferenceSpaceCreateInfo referenceSpaceCreateInfo {
        .type = XR_TYPE_REFERENCE_SPACE_CREATE_INFO,
        .next = nullptr,
        .referenceSpaceType = referenceSpaceType,
        .poseInReferenceSpace = pose
    };
    ABORT_ON_OPENXR_ERROR(xrCreateReferenceSpace(session.handle, &referenceSpaceCreateInfo, &this->handle));
}

Space::Space(const Session& session, const Action& action, const std::string& subactionPath, const XrPosef& pose)
{
    XrActionSpaceCreateInfo actionSpaceCreateInfo {
        .type = XR_TYPE_ACTION_SPACE_CREATE_INFO,
        .next = nullptr,
        .action = action.handle,
        .subactionPath = !subactionPath.empty() ? session.instance.getPath(subactionPath) : XR_NULL_PATH,
        .poseInActionSpace = pose
    };
    ABORT_ON_OPENXR_ERROR(xrCreateActionSpace(session.handle, &actionSpaceCreateInfo, &this->handle));
}

Space::~Space()
{
    ABORT_ON_OPENXR_ERROR(xrDestroySpace(this->handle));
}

Pose Space::locate(const Space& base, XrTime time) const
{
    XrSpaceLocation location {
        .type = XR_TYPE_SPACE_LOCATION,
        .next = nullptr
    };
    ABORT_ON_OPENXR_ERROR(xrLocateSpace(this->handle, base.handle, time, &location));
    return (Pose) {
        .poseValid = ((location.locationFlags & XR_SPACE_LOCATION_POSITION_VALID_BIT) != 0) && ((location.locationFlags & XR_SPACE_LOCATION_ORIENTATION_VALID_BIT) != 0),
        .pose = location.pose
    };
}

PoseAndVelocity Space::locateWithVelocity(const Space& base, XrTime time) const
{
    XrSpaceVelocity velocity {
        .type = XR_TYPE_SPACE_VELOCITY,
        .next = nullptr
    };
    XrSpaceLocation location {
        .type = XR_TYPE_SPACE_LOCATION,
        .next = &velocity
    };
    ABORT_ON_OPENXR_ERROR(xrLocateSpace(this->handle, base.handle, time, &location));
    return (PoseAndVelocity) {
        .poseValid = ((location.locationFlags & XR_SPACE_LOCATION_POSITION_VALID_BIT) != 0) && ((location.locationFlags & XR_SPACE_LOCATION_ORIENTATION_VALID_BIT) != 0),
        .linearVelocityValid = (velocity.velocityFlags & XR_SPACE_VELOCITY_LINEAR_VALID_BIT) != 0,
        .angularVelocityValid = (velocity.velocityFlags & XR_SPACE_VELOCITY_ANGULAR_VALID_BIT) != 0,
        .pose = location.pose,
        .linearVelocity = velocity.linearVelocity,
        .angularVelocity = velocity.angularVelocity
    };
}

ActionSet::ActionSet(const Instance& instance, const std::string& name, const std::string& displayName, int priority): instance(instance)
{
    XrActionSetCreateInfo actionSetCreateInfo = {
        .type = XR_TYPE_ACTION_SET_CREATE_INFO,
        .next = nullptr,
        .priority = (uint32_t) priority
    };
    std::strcpy(actionSetCreateInfo.actionSetName, name.c_str());
    std::strcpy(actionSetCreateInfo.localizedActionSetName, displayName.c_str());
    ABORT_ON_OPENXR_ERROR(xrCreateActionSet(instance.handle, &actionSetCreateInfo, &this->handle));
}

ActionSet::~ActionSet()
{
    ABORT_ON_OPENXR_ERROR(xrDestroyActionSet(this->handle));
}

void ActionSet::suggestBindings(const std::string& interactionProfile, const std::vector<ActionBinding>& bindings) const
{
    int bindingsCount = bindings.size();
    XrActionSuggestedBinding* suggestedBindings = new XrActionSuggestedBinding[bindingsCount];
    for (int i = 0; i < bindingsCount; i++)
    {
        const ActionBinding& binding = bindings[i];
        suggestedBindings[i] = {
            .action = binding.action.handle,
            .binding = this->instance.getPath(binding.path)
        };
    }
    XrInteractionProfileSuggestedBinding interactionProfileSuggestedBinding {
        .type = XR_TYPE_INTERACTION_PROFILE_SUGGESTED_BINDING,
        .next = nullptr,
        .interactionProfile = this->instance.getPath(interactionProfile),
        .countSuggestedBindings = (uint32_t) bindingsCount,
        .suggestedBindings = suggestedBindings
    };
    ABORT_ON_OPENXR_ERROR(xrSuggestInteractionProfileBindings(this->instance.handle, &interactionProfileSuggestedBinding));
    delete[] suggestedBindings;
}

Action::Action(const ActionSet& actionSet, const std::string& name, const std::string& displayName, XrActionType type, std::vector<std::string> subactionPaths): actionSet(actionSet)
{
    int subactionPathsCount = subactionPaths.size();
    XrPath* subactionPathsArray = new XrPath[subactionPathsCount];
    for (int i = 0; i < subactionPathsCount; i++)
    {
        subactionPathsArray[i] = actionSet.instance.getPath(subactionPaths[i]);
    }
    XrActionCreateInfo actionCreateInfo = {
        .type = XR_TYPE_ACTION_CREATE_INFO,
        .next = nullptr,
        .actionType = type,
        .countSubactionPaths = (uint32_t) subactionPathsCount,
        .subactionPaths = subactionPathsArray
    };
    std::strcpy(actionCreateInfo.actionName, name.c_str());
    std::strcpy(actionCreateInfo.localizedActionName, displayName.c_str());
    ABORT_ON_OPENXR_ERROR(xrCreateAction(actionSet.handle, &actionCreateInfo, &this->handle));
    delete[] subactionPathsArray;
}

Action::~Action()
{
    ABORT_ON_OPENXR_ERROR(xrDestroyAction(this->handle));
}

bool Action::getStateBool(const Session& session, const std::string& subactionPath) const
{
    return this->getStateBool(session, subactionPath, nullptr);
}

bool Action::getStateBool(const Session& session, const std::string& subactionPath, XrTime* lastChangeTime) const
{
    XrActionStateGetInfo actionStateGetInfo {
        .type = XR_TYPE_ACTION_STATE_GET_INFO,
        .next = nullptr,
        .action = this->handle,
        .subactionPath = !subactionPath.empty() ? this->actionSet.instance.getPath(subactionPath) : XR_NULL_PATH
    };
    XrActionStateBoolean actionState {
        .type = XR_TYPE_ACTION_STATE_BOOLEAN,
        .next = nullptr
    };
    ABORT_ON_OPENXR_ERROR(xrGetActionStateBoolean(session.handle, &actionStateGetInfo, &actionState));
    if (lastChangeTime != nullptr)
    {
        *lastChangeTime = actionState.lastChangeTime;
    }
    return actionState.currentState != 0;
}

float Action::getStateFloat(const Session& session, const std::string& subactionPath) const
{
    return this->getStateFloat(session, subactionPath, nullptr);
}

float Action::getStateFloat(const Session& session, const std::string& subactionPath, XrTime* lastChangeTime) const
{
    XrActionStateGetInfo actionStateGetInfo {
        .type = XR_TYPE_ACTION_STATE_GET_INFO,
        .next = nullptr,
        .action = this->handle,
        .subactionPath = !subactionPath.empty() ? this->actionSet.instance.getPath(subactionPath) : XR_NULL_PATH
    };
    XrActionStateFloat actionState {
        .type = XR_TYPE_ACTION_STATE_FLOAT,
        .next = nullptr
    };
    ABORT_ON_OPENXR_ERROR(xrGetActionStateFloat(session.handle, &actionStateGetInfo, &actionState));
    if (lastChangeTime != nullptr)
    {
        *lastChangeTime = actionState.lastChangeTime;
    }
    return actionState.currentState;
}

XrVector2f Action::getStateVector(const Session& session, const std::string& subactionPath) const
{
    return this->getStateVector(session, subactionPath, nullptr);
}

XrVector2f Action::getStateVector(const Session& session, const std::string& subactionPath, XrTime* lastChangeTime) const
{
    XrActionStateGetInfo actionStateGetInfo {
        .type = XR_TYPE_ACTION_STATE_GET_INFO,
        .next = nullptr,
        .action = this->handle,
        .subactionPath = !subactionPath.empty() ? this->actionSet.instance.getPath(subactionPath) : XR_NULL_PATH
    };
    XrActionStateVector2f actionState {
        .type = XR_TYPE_ACTION_STATE_VECTOR2F,
        .next = nullptr
    };
    ABORT_ON_OPENXR_ERROR(xrGetActionStateVector2f(session.handle, &actionStateGetInfo, &actionState));
    if (lastChangeTime != nullptr)
    {
        *lastChangeTime = actionState.lastChangeTime;
    }
    return actionState.currentState;
}

void Action::applyHapticFeedback(const Session& session, const std::string& subactionPath, XrDuration duration, float frequency, float amplitude) const
{
    XrHapticActionInfo hapticActionInfo {
        .type = XR_TYPE_HAPTIC_ACTION_INFO,
        .next = nullptr,
        .action = this->handle,
        .subactionPath = !subactionPath.empty() ? this->actionSet.instance.getPath(subactionPath) : XR_NULL_PATH
    };
    XrHapticVibration hapticVibration {
        .type = XR_TYPE_HAPTIC_VIBRATION,
        .next = nullptr,
        .duration = duration,
        .frequency = frequency,
        .amplitude = amplitude
    };
    ABORT_ON_OPENXR_ERROR(xrApplyHapticFeedback(session.handle, &hapticActionInfo, (XrHapticBaseHeader*) &hapticVibration));
}
