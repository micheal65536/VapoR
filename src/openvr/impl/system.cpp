#include "system.h"
#include "log/log.h"
#include "log/stub.h"

#include "backend/openxr.h"

#include <cmath>
#include "utils/pose.h"
#include "utils/legacy_input.h"
#include <cstring>

using namespace openvr;

SystemImpl::SystemImpl(ClientCoreImpl& clientCore): clientCore(clientCore)
{
    // empty
}

void SystemImpl::getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height)
{
    *width = this->clientCore.backend->renderWidth;
    *height = this->clientCore.backend->renderHeight;
}

Matrix44 SystemImpl::getProjectionMatrix(Eye eye, float near, float far)
{
    float left, right, top, bottom;
    this->getProjectionRaw(eye, &left, &right, &top, &bottom);

    float idx = 1.0f / (right - left);
    float idy = 1.0f / (bottom - top);
    float idz = 1.0f / (far - near);
    float sx = right + left;
    float sy = bottom + top;

    Matrix44 mat;
    float (*m)[4] = mat.m;
    m[0][0] = 2.0f * idx; m[0][1] = 0.0f;       m[0][2] = sx * idx;   m[0][3] = 0.0f;
    m[1][0] = 0.0f;       m[1][1] = 2.0f * idy; m[1][2] = sy * idy;   m[1][3] = 0.0f;
    m[2][0] = 0.0f;       m[2][1] = 0.0f;       m[2][2] = -far * idz; m[2][3] = -far * near * idz;
    m[3][0] = 0.0f;       m[3][1] = 0.0f;       m[3][2] = -1.0f;      m[3][3] = 0.0f;

    return mat;
}

void SystemImpl::getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom)
{
    vapor::FrameState frame = this->clientCore.backend->frameStates.getFrame(0);
    OpenXR::View& view = eye == Eye::EYE_RIGHT ? frame.views.right : frame.views.left;
    *left = std::tan(view.fov.angleLeft);
    *right = std::tan(view.fov.angleRight);
    // TODO: I know this looks backwards but it seems to match ALVR?
    *top = std::tan(view.fov.angleDown);
    *bottom = std::tan(view.fov.angleUp);
}

bool SystemImpl::computeDistortion(Eye eye, float u, float v, DistortionCoordinates* distortionCoordinates)
{
    distortionCoordinates->red[0] = distortionCoordinates->green[0] = distortionCoordinates->blue[0] = u;
    distortionCoordinates->red[1] = distortionCoordinates->green[1] = distortionCoordinates->blue[1] = v;
    return true;
}

Matrix34 SystemImpl::getEyeToHeadTransform(Eye eye)
{
    // CHECK
    vapor::FrameState frame = this->clientCore.backend->frameStates.getFrame(0);
    OpenXR::View& view = eye == Eye::EYE_RIGHT ? frame.views.right : frame.views.left;
    Matrix34 matrix;
    utils::poseToMatrix(view.pose, &matrix);
    return matrix;
}

bool SystemImpl::getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter)
{
    STUB();
    return false;
}

void SystemImpl::getOutputDevice(uint64_t* device, TextureType textureType, VkInstance_T* vkInstance)
{
    STUB();
    *device = 0;
}

void SystemImpl::getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount)
{
    STUB();
}

void SystemImpl::resetSeatedZeroPose()
{
    STUB();
}

Matrix34 SystemImpl::getSeatedZeroPoseToStandingAbsoluteTrackingPose()
{
    STUB();
}

Matrix34 SystemImpl::getRawZeroPoseToStandingAbsoluteTrackingPose()
{
    STUB();
}

uint32_t SystemImpl::getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex)
{
    STUB();
}

DeviceActivityLevel SystemImpl::getTrackedDeviceActivityLevel(uint32_t index)
{
    if (index < 3)
    {
        return DeviceActivityLevel::ACTIVITY_LEVEL_ACTIVE;
    }
    else
    {
        return DeviceActivityLevel::ACTIVITY_LEVEL_UNKNOWN;
    }
}

void SystemImpl::applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform)
{
    STUB();
}

uint32_t SystemImpl::getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole)
{
    switch (controllerRole)
    {
        case TrackedControllerRole::CONTROLLER_ROLE_LEFT_HAND:
            return 1;
        case TrackedControllerRole::CONTROLLER_ROLE_RIGHT_HAND:
            return 2;
        case TrackedControllerRole::CONTROLLER_ROLE_INVALID:
        default:
            return 0xFFFFFFFF;
    }
}

TrackedControllerRole SystemImpl::getControllerRoleForTrackedDeviceIndex(uint32_t index)
{
    switch (index)
    {
        case 1:
            return TrackedControllerRole::CONTROLLER_ROLE_LEFT_HAND;
        case 2:
            return TrackedControllerRole::CONTROLLER_ROLE_RIGHT_HAND;
        default:
            return TrackedControllerRole::CONTROLLER_ROLE_INVALID;
    }
}

TrackedDeviceClass SystemImpl::getTrackedDeviceClass(uint32_t index)
{
    if (index == 0)
    {
        return TrackedDeviceClass::DEVICE_CLASS_HMD;
    }
    else if (index < 3)
    {
        return TrackedDeviceClass::DEVICE_CLASS_CONTROLLER;
    }
    else
    {
        return TrackedDeviceClass::DEVICE_CLASS_INVALID;
    }
}

bool SystemImpl::isTrackedDeviceConnected(uint32_t index)
{
    return index < 3;
}

static inline void trackedDevicePropertyError(TrackedPropertyError* error, TrackedPropertyError error1)
{
    if (error != nullptr)
    {
        *error = error1;
    }
}

bool SystemImpl::getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    TRACE_F("%d %d", index, property);

    if (index > 2)
    {
        trackedDevicePropertyError(error, TrackedPropertyError::PROPERTY_ERROR_INVALID_DEVICE);
        return false;
    }

    trackedDevicePropertyError(error, TrackedPropertyError::PROPERTY_ERROR_SUCCESS);
    vapor::DevicePropertySet& devicePropertySet = this->clientCore.backend->devicePropertySets[index];

    switch (property)
    {
        case TrackedDeviceProperty::PROPERTY_BATTERY_IS_CHARGING:
            return false;
        case TrackedDeviceProperty::PROPERTY_PROVIDES_BATTERY_STATUS:
            return false;
    }

    if (index == 0)
    {
        switch (property)
        {
            case TrackedDeviceProperty::PROPERTY_REPORTS_TIME_SINCE_VSYNC:
                return false;
            case TrackedDeviceProperty::PROPERTY_IS_ON_DESKTOP:
                return false;
        }
    }

    if (index == 1 || index == 2)
    {
        switch (property)
        {
            // empty
        }
    }

    // TODO: properly handle PROPERTY_ERROR_WRONG_TYPE and PROPERTY_ERROR_WRONG_CLASS

    STUB_F("Unkown property %d %d", index, property);
    trackedDevicePropertyError(error, TrackedPropertyError::PROPERTY_ERROR_UNKNOWN_PROPERTY);
    return false;
}

float SystemImpl::getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    TRACE_F("%d %d", index, property);

    if (index > 2)
    {
        trackedDevicePropertyError(error, TrackedPropertyError::PROPERTY_ERROR_INVALID_DEVICE);
        return 0.0f;
    }

    trackedDevicePropertyError(error, TrackedPropertyError::PROPERTY_ERROR_SUCCESS);
    vapor::DevicePropertySet& devicePropertySet = this->clientCore.backend->devicePropertySets[index];

    switch (property)
    {
        case TrackedDeviceProperty::PROPERTY_BATTERY_PERCENTAGE:
            return 0.5f;
    }

    if (index == 0)
    {
        switch (property)
        {
            case TrackedDeviceProperty::PROPERTY_SECONDS_FROM_VSYNC_TO_PHOTONS:
                return 1.0f / this->clientCore.backend->refreshRate;
            case TrackedDeviceProperty::PROPERTY_DISPLAY_FREQUENCY:
                return this->clientCore.backend->refreshRate;
            case TrackedDeviceProperty::PROPERTY_IPD_METERS:
                {
                    vapor::FrameState frame = this->clientCore.backend->frameStates.getFrame(0);
                    XrPosef& leftEye = frame.views.left.pose;
                    XrPosef& rightEye = frame.views.right.pose;
                    float dx = rightEye.position.x - leftEye.position.x;
                    float dy = rightEye.position.y - leftEye.position.y;
                    float dz = rightEye.position.z - leftEye.position.z;
                    float d = std::sqrt((dx * dx) + (dy * dy) + (dz * dz));
                    return d;
                }
            case TrackedDeviceProperty::PROPERTY_HEAD_TO_EYE_DEPTH_METERS:
                // TODO
                return 0.0f;
        }
    }

    if (index == 1 || index == 2)
    {
        switch (property)
        {
            // empty
        }
    }

    // TODO: properly handle PROPERTY_ERROR_WRONG_TYPE and PROPERTY_ERROR_WRONG_CLASS

    STUB_F("Unkown property %d %d", index, property);
    trackedDevicePropertyError(error, TrackedPropertyError::PROPERTY_ERROR_UNKNOWN_PROPERTY);
    return 0.0f;
}

int32_t SystemImpl::getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    TRACE_F("%d %d", index, property);

    if (index > 2)
    {
        trackedDevicePropertyError(error, TrackedPropertyError::PROPERTY_ERROR_INVALID_DEVICE);
        return 0;
    }

    trackedDevicePropertyError(error, TrackedPropertyError::PROPERTY_ERROR_SUCCESS);
    vapor::DevicePropertySet& devicePropertySet = this->clientCore.backend->devicePropertySets[index];

    switch (property)
    {
        case TrackedDeviceProperty::PROPERTY_DEVICE_CLASS:
            return index == 0 ? TrackedDeviceClass::DEVICE_CLASS_HMD : TrackedDeviceClass::DEVICE_CLASS_CONTROLLER;
    }

    if (index == 0)
    {
        switch (property)
        {
            // empty
        }
    }

    if (index == 1 || index == 2)
    {
        switch (property)
        {
            case TrackedDeviceProperty::PROPERTY_AXIS0_TYPE:
            case TrackedDeviceProperty::PROPERTY_AXIS1_TYPE:
            case TrackedDeviceProperty::PROPERTY_AXIS2_TYPE:
            case TrackedDeviceProperty::PROPERTY_AXIS3_TYPE:
            case TrackedDeviceProperty::PROPERTY_AXIS4_TYPE:
                switch (this->clientCore.backend->inputProfile->getOpenVRLegacyInputDescription().axisTypes[property - TrackedDeviceProperty::PROPERTY_AXIS0_TYPE])
                {
                    case vapor::LegacyInputDescription::AxisType::NONE:
                        return ControllerAxisType::AXIS_NONE;
                    case vapor::LegacyInputDescription::AxisType::TRACKPAD:
                        return ControllerAxisType::AXIS_TRACKPAD;
                    case vapor::LegacyInputDescription::AxisType::JOYSTICK:
                        return ControllerAxisType::AXIS_JOYSTICK;
                    case vapor::LegacyInputDescription::AxisType::TRIGGER:
                        return ControllerAxisType::AXIS_TRIGGER;
                }
                break;
            case TrackedDeviceProperty::PROPERTY_CONTROLLER_ROLE:
                switch (index)
                {
                    case 1:
                        return TrackedControllerRole::CONTROLLER_ROLE_LEFT_HAND;
                    case 2:
                        return TrackedControllerRole::CONTROLLER_ROLE_RIGHT_HAND;
                }
                break;
        }
    }

    // TODO: properly handle PROPERTY_ERROR_WRONG_TYPE and PROPERTY_ERROR_WRONG_CLASS

    STUB_F("Unkown property %d %d", index, property);
    trackedDevicePropertyError(error, TrackedPropertyError::PROPERTY_ERROR_UNKNOWN_PROPERTY);
    return 0;
}

uint64_t SystemImpl::getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    TRACE_F("%d %d", index, property);

    if (index > 2)
    {
        trackedDevicePropertyError(error, TrackedPropertyError::PROPERTY_ERROR_INVALID_DEVICE);
        return 0;
    }

    trackedDevicePropertyError(error, TrackedPropertyError::PROPERTY_ERROR_SUCCESS);
    vapor::DevicePropertySet& devicePropertySet = this->clientCore.backend->devicePropertySets[index];

    switch (property)
    {
        // empty
    }

    if (index == 0)
    {
        switch (property)
        {
            case TrackedDeviceProperty::PROPERTY_CURRENT_UNIVERSE_ID:
                return 2; // comment in ALVR code assures that this is supposed to be hardcoded at 2
            case TrackedDeviceProperty::PROPERTY_PREVIOUS_UNIVERSE_ID:
                // TODO
                break;
        }
    }

    if (index == 1 || index == 2)
    {
        switch (property)
        {
            case TrackedDeviceProperty::PROPERTY_SUPPORTED_BUTTONS:
                return utils::makeLegacyInputButtonsBitmap(this->clientCore.backend->inputProfile->getOpenVRLegacyInputDescription().supportedButtons);
        }
    }

    // TODO: properly handle PROPERTY_ERROR_WRONG_TYPE and PROPERTY_ERROR_WRONG_CLASS

    STUB_F("Unkown property %d %d", index, property);
    trackedDevicePropertyError(error, TrackedPropertyError::PROPERTY_ERROR_UNKNOWN_PROPERTY);
    return 0;
}

Matrix34 SystemImpl::getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    TRACE_F("%d %d", index, property);

    if (index > 2)
    {
        trackedDevicePropertyError(error, TrackedPropertyError::PROPERTY_ERROR_INVALID_DEVICE);
        return Matrix34();
    }

    // we don't actually implement any matrix34 properties

    STUB_F("Unkown property %d %d", index, property);
    trackedDevicePropertyError(error, TrackedPropertyError::PROPERTY_ERROR_UNKNOWN_PROPERTY);
    return Matrix34();
}

uint32_t SystemImpl::getArrayTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedDevicePropertyType type, void* buffer, uint32_t bufferSize, TrackedPropertyError* error)
{
    TRACE_F("%d %d", index, property);

    if (index > 2)
    {
        trackedDevicePropertyError(error, TrackedPropertyError::PROPERTY_ERROR_INVALID_DEVICE);
        return 0;
    }

    // we don't actually implement any array properties

    STUB_F("Unkown property %d %d", index, property);
    trackedDevicePropertyError(error, TrackedPropertyError::PROPERTY_ERROR_UNKNOWN_PROPERTY);
    return 0;
}

static inline uint32_t returnStringTrackedDeviceProperty(const std::string& value, char* buffer, uint32_t bufferSize, TrackedPropertyError* error)
{
    if (value.empty())
    {
        trackedDevicePropertyError(error, TrackedPropertyError::PROPERTY_ERROR_UNKNOWN_PROPERTY);
        return 0;
    }
    uint32_t requiredBufferSize = value.length() + 1;
    if (bufferSize >= requiredBufferSize)
    {
        std::memcpy(buffer, value.c_str(), requiredBufferSize);
    }
    else
    {
        trackedDevicePropertyError(error, TrackedPropertyError::PROPERTY_ERROR_BUFFER_TOO_SMALL);
    }
    return requiredBufferSize;
}

uint32_t SystemImpl::getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error)
{
    TRACE_F("%d %d", index, property);

    if (index > 2)
    {
        trackedDevicePropertyError(error, TrackedPropertyError::PROPERTY_ERROR_INVALID_DEVICE);
        return 0;
    }

    trackedDevicePropertyError(error, TrackedPropertyError::PROPERTY_ERROR_SUCCESS);
    vapor::DevicePropertySet& devicePropertySet = this->clientCore.backend->devicePropertySets[index];

    switch (property)
    {
        case TrackedDeviceProperty::PROPERTY_SYSTEM_NAME:
            return returnStringTrackedDeviceProperty(devicePropertySet.systemName, buffer, bufferSize, error);
        case TrackedDeviceProperty::PROPERTY_MODEL_NUMBER:
            return returnStringTrackedDeviceProperty(devicePropertySet.modelName, buffer, bufferSize, error);
        case TrackedDeviceProperty::PROPERTY_SERIAL_NUMBER:
            return returnStringTrackedDeviceProperty(devicePropertySet.serialNumber, buffer, bufferSize, error);
        case TrackedDeviceProperty::PROPERTY_RENDER_MODEL_NAME:
            return returnStringTrackedDeviceProperty(this->clientCore.backend->deviceRenderModelNames[index], buffer, bufferSize, error);
        case TrackedDeviceProperty::PROPERTY_MANUFACTURER_NAME:
            return returnStringTrackedDeviceProperty(devicePropertySet.manufacturerName, buffer, bufferSize, error);
        case TrackedDeviceProperty::PROPERTY_REGISTERED_DEVICE_TYPE:
            return returnStringTrackedDeviceProperty(devicePropertySet.registeredDeviceType, buffer, bufferSize, error);
        case TrackedDeviceProperty::PROPERTY_ACTUAL_SYSTEM_NAME:
            return returnStringTrackedDeviceProperty("VapoR", buffer, bufferSize, error);
    }

    if (index == 0)
    {
        switch (property)
        {
            // empty
        }
    }

    if (index == 1 || index == 2)
    {
        switch (property)
        {
            case TrackedDeviceProperty::PROPERTY_ATTACHED_DEVICE_ID:
                return returnStringTrackedDeviceProperty(devicePropertySet.attachedDeviceId, buffer, bufferSize, error);
        }
    }

    // TODO: properly handle PROPERTY_ERROR_WRONG_TYPE and PROPERTY_ERROR_WRONG_CLASS

    STUB_F("Unkown property %d %d", index, property);
    trackedDevicePropertyError(error, TrackedPropertyError::PROPERTY_ERROR_UNKNOWN_PROPERTY);
    return 0;
}

const char* SystemImpl::getPropErrorNameFromEnum(TrackedPropertyError error)
{
    STUB_F("%d", error);
    return "";
}

bool SystemImpl::pollNextEvent(Event_0_9_15* event, uint32_t bufferSize)
{
    TRACE();
    if (bufferSize >= sizeof(Event_0_9_15))
    {
        return this->clientCore.backend->eventQueue.pollEvent(event, nullptr);
    }
    else
    {
        Event_0_9_15 eventFullSize;
        bool haveEvent = this->clientCore.backend->eventQueue.pollEvent(&eventFullSize, nullptr);
        if (haveEvent)
        {
            std::memcpy(event, &eventFullSize, bufferSize);
        }
        return haveEvent;
    }
}

bool SystemImpl::pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut)
{
    TRACE();
    bool haveEvent;
    vapor::PoseSet poseSet;
    if (bufferSize >= sizeof(Event_0_9_15))
    {
        haveEvent = this->clientCore.backend->eventQueue.pollEvent(event, &poseSet);
    }
    else
    {
        Event_0_9_15 eventFullSize;
        haveEvent = this->clientCore.backend->eventQueue.pollEvent(&eventFullSize, nullptr);
        if (haveEvent)
        {
            std::memcpy(event, &eventFullSize, bufferSize);
        }
    }
    if (haveEvent && trackedDevicePoseOut != nullptr)
    {
        utils::selectTrackedDevicePose(poseSet, origin, false, trackedDevicePoseOut);
    }
    return haveEvent;
}

const char* SystemImpl::getEventTypeNameFromEnum(EventType type)
{
    STUB_F("%d", type);
    return "";
}

HiddenAreaMesh SystemImpl::getHiddenAreaMesh(Eye eye, HiddenAreaMeshType type)
{
    TRACE();
    return HiddenAreaMesh {
        .vertices = nullptr,
        .triangleCount = 0
    };
}

bool SystemImpl::getControllerState(uint32_t index, ControllerState* state, uint32_t bufferSize)
{
    TRACE_F("%d", index);

    if (index == 0 || index > 2)
    {
        // CHECK: no state for HMD? (maybe we still return pose?)
        return false;
    }

    ControllerState state1;
    ControllerState& stateToUse = bufferSize < sizeof(ControllerState) ? state1 : *state;

    vapor::FrameState frame = this->clientCore.backend->frameStates.getFrame(0);
    vapor::LegacyInputState& legacyInputState = frame.legacyInputStates[index - 1];
    stateToUse.packetNum = (uint32_t) frame.index; // TODO: packet num should only be updated when the state actually changes (this will require work from LegacyInputHelper and probably an extra field in FrameState)
    stateToUse.buttonsPressed = utils::makeLegacyInputButtonsBitmap(legacyInputState.click);
    stateToUse.buttonsTouched = utils::makeLegacyInputButtonsBitmap(legacyInputState.touch);
    for (int i = 0; i < 5; i++)
    {
        stateToUse.axes[i] = {
            .x = legacyInputState.axes[i].x,
            .y = legacyInputState.axes[i].y
        };
    }

    if (bufferSize < sizeof(ControllerState))
    {
        std::memcpy(state, &state1, bufferSize);
    }
    return true;
}

bool SystemImpl::getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, uint32_t bufferSize, TrackedDevicePose* pose)
{
    TRACE_F("%d", index);

    if (index == 0 || index > 2)
    {
        // CHECK: no state for HMD? (maybe we still return pose?)
        // CHECK: should we empty out the provided pose buffer if the device index is invalid?
        return false;
    }

    ControllerState state1;
    ControllerState& stateToUse = bufferSize < sizeof(ControllerState) ? state1 : *state;

    vapor::FrameState frame = this->clientCore.backend->frameStates.getFrame(0);
    vapor::LegacyInputState& legacyInputState = frame.legacyInputStates[index - 1];
    stateToUse.packetNum = (uint32_t) frame.index; // TODO: packet num should only be updated when the state actually changes (this will require work from LegacyInputHelper and probably an extra field in FrameState)
    stateToUse.buttonsPressed = utils::makeLegacyInputButtonsBitmap(legacyInputState.click);
    stateToUse.buttonsTouched = utils::makeLegacyInputButtonsBitmap(legacyInputState.touch);
    for (int i = 0; i < 5; i++)
    {
        stateToUse.axes[i] = {
            .x = legacyInputState.axes[i].x,
            .y = legacyInputState.axes[i].y
        };
    }

    if (pose != nullptr)
    {
        utils::selectTrackedDevicePose(frame.controllerPoses[index - 1], origin, false, pose);
    }

    if (bufferSize < sizeof(ControllerState))
    {
        std::memcpy(state, &state1, bufferSize);
    }
    return true;
}

void SystemImpl::triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs)
{
    TRACE_F("%d %d %d", index, axisId, durationUs);
    // TODO: what is axisId supposed to do?
    if (index >= 1 && index <= 2)
    {
        this->clientCore.backend->hapticQueue->queueLegacyHapticEvent(index - 1, durationUs);
    }
}

const char* SystemImpl::getButtonIdNameFromEnum(ButtonId button)
{
    STUB_F("%d", button);
    return "";
}

const char* SystemImpl::getControllerAxisTypeNameFromEnum(ControllerAxisType axisType)
{
    STUB_F("%d", axisType);
    return "";
}

void SystemImpl::acknowledgeQuit()
{
    STUB();
}

void SystemImpl::acknowledgeQuitPrompt()
{
    STUB();
}

uint32_t SystemImpl::getAppContainerFilePaths(char* buffer, uint32_t bufferSize)
{
    STUB();
    return 0;
}

const char* SystemImpl::getRuntimeVersion()
{
    STUB();
    return "";
}
