#include "input.h"
#include "log/log.h"
#include "log/stub.h"

#include "input/action_manager.h"
#include "input/input_devices.h"

#include <cstring>

using namespace openvr;

InputImpl::InputImpl(ClientCoreImpl& clientCore): clientCore(clientCore)
{
    // empty
}

InputError InputImpl::setActionManifestPath(const char* path)
{
    input::ActionManager* actionManager = new input::ActionManager();
    if (!actionManager->populateFromJSON(path))
    {
        LOG("Failed to read actions from %s", path);
        return InputError::INPUT_ERROR_MISMATCHED_ACTION_MANIFEST; // TODO: better error code for this
    }
    else
    {
        LOG("Read actions from %s", path);
        actionManager->loadDefaultBindingForControllerProfile(this->clientCore.backend->inputProfile->getOpenVRProfileName(), this->clientCore.backend->inputProfile);
        this->clientCore.actionManager = actionManager;
        return InputError::INPUT_ERROR_NONE;
    }
}

InputError InputImpl::getActionSetHandle(const char* actionSetName, uint64_t* handle)
{
    TRACE_F("%s", actionSetName);
    if (this->clientCore.actionManager == nullptr)
    {
        return InputError::INPUT_ERROR_NAME_NOT_FOUND;
    }
    *handle = (uint64_t) this->clientCore.actionManager->findActionSet(actionSetName);
    return *handle != 0 ? InputError::INPUT_ERROR_NONE : InputError::INPUT_ERROR_NAME_NOT_FOUND;
}

InputError InputImpl::getActionHandle(const char* actionName, uint64_t* handle)
{
    TRACE_F("%s", actionName);
    if (this->clientCore.actionManager == nullptr)
    {
        return InputError::INPUT_ERROR_NAME_NOT_FOUND;
    }
    *handle = (uint64_t) this->clientCore.actionManager->findAction(actionName);
    return *handle != 0 ? InputError::INPUT_ERROR_NONE : InputError::INPUT_ERROR_NAME_NOT_FOUND;
}

InputError InputImpl::getInputSourceHandle(const char* inputSourcePath, uint64_t* handle)
{
    TRACE_F("%s", inputSourcePath);
    if (std::string(inputSourcePath) == "/user/hand/left")
    {
        *handle = input::Device::HAND_LEFT;
        return InputError::INPUT_ERROR_NONE;
    }
    else if (std::string(inputSourcePath) == "/user/hand/right")
    {
        *handle = input::Device::HAND_RIGHT;
        return InputError::INPUT_ERROR_NONE;
    }
    else if (std::string(inputSourcePath) == "/user/elbow/left")
    {
        *handle = input::Device::ELBOW_LEFT;
        return InputError::INPUT_ERROR_NONE;
    }
    else if (std::string(inputSourcePath) == "/user/elbow/right")
    {
        *handle = input::Device::ELBOW_RIGHT;
        return InputError::INPUT_ERROR_NONE;
    }
    else if (std::string(inputSourcePath) == "/user/foot/left")
    {
        *handle = input::Device::FOOT_LEFT;
        return InputError::INPUT_ERROR_NONE;
    }
    else if (std::string(inputSourcePath) == "/user/foot/right")
    {
        *handle = input::Device::FOOT_RIGHT;
        return InputError::INPUT_ERROR_NONE;
    }
    else if (std::string(inputSourcePath) == "/user/knee/left")
    {
        *handle = input::Device::KNEE_LEFT;
        return InputError::INPUT_ERROR_NONE;
    }
    else if (std::string(inputSourcePath) == "/user/knee/right")
    {
        *handle = input::Device::KNEE_RIGHT;
        return InputError::INPUT_ERROR_NONE;
    }
    else if (std::string(inputSourcePath) == "/user/waist")
    {
        *handle = input::Device::WAIST;
        return InputError::INPUT_ERROR_NONE;
    }
    else if (std::string(inputSourcePath) == "/user/camera")
    {
        *handle = input::Device::CAMERA;
        return InputError::INPUT_ERROR_NONE;
    }
    else
    {
        LOG("Unhandled input source path %s", inputSourcePath);
        *handle = 0;
        return InputError::INPUT_ERROR_NAME_NOT_FOUND;
    }
}

InputError InputImpl::updateActionState(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount)
{
    input::ActionManager::update(actionSets, actionSetSize, actionSetsCount, this->clientCore.backend->frameStates.getFrame(0).inputStates.data());
    return InputError::INPUT_ERROR_NONE;
}

InputError InputImpl::getDigitalActionData(uint64_t action, InputDigitalActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    STUB();
    return InputError::INPUT_ERROR_NONE;
}

InputError InputImpl::getAnalogActionData(uint64_t action, InputAnalogActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    STUB();
    return InputError::INPUT_ERROR_NONE;
}

InputError InputImpl::getPoseActionDataRelativeToNow(uint64_t action, TrackingUniverseOrigin origin, float secondsFromNow, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    STUB();
    return InputError::INPUT_ERROR_NONE;
}

InputError InputImpl::getPoseActionDataForNextFrame(uint64_t action, TrackingUniverseOrigin origin, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    STUB();
    return InputError::INPUT_ERROR_NONE;
}

InputError InputImpl::getSkeletalActionData(uint64_t action, InputSkeletalActionData* actionData, uint32_t actionDataSize)
{
    STUB();
    return InputError::INPUT_ERROR_NONE;
}

InputError InputImpl::getDominantHand(TrackedControllerRole* dominantHand)
{
    STUB();
}

InputError InputImpl::setDominantHand(TrackedControllerRole dominantHand)
{
    STUB();
}

InputError InputImpl::getBoneCount(uint64_t action, uint32_t* boneCount)
{
    STUB();
}

InputError InputImpl::getBoneHierarchy(uint64_t action, int32_t* parentIndexes, uint32_t parentsCount)
{
    STUB();
}

InputError InputImpl::getBoneName(uint64_t action, int32_t boneIndex, char* name, uint32_t bufferSize)
{
    STUB();
}

InputError InputImpl::getSkeletalReferenceTransforms(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalReferencePose referencePose, BoneTransform* transforms, uint32_t transformsCount)
{
    STUB();
}

InputError InputImpl::getSkeletalTrackingLevel(uint64_t action, SkeletalTrackingLevel* skeletalTrackingLevel)
{
    STUB();
}

InputError InputImpl::getSkeletalBoneData(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalMotionRange motionRange, BoneTransform* transforms, uint32_t transformsCount)
{
    STUB();
}

InputError InputImpl::getSkeletalSummaryData(uint64_t action, SkeletalSummaryType summaryType, SkeletalSummaryData* data)
{
    STUB();
}

InputError InputImpl::getSkeletalBoneDataCompressed(uint64_t action, SkeletalMotionRange motionRange, void* data, uint32_t bufferSize, uint32_t* requiredBufferSize)
{
    STUB();
}

InputError InputImpl::decompressSkeletalBoneData(const void* data, uint32_t size, SkeletalTransformSpace transformSpace, BoneTransform* transforms, uint32_t transformsCount)
{
    STUB();
}

InputError InputImpl::triggerHapticVibrationAction(uint64_t action, float startSecondsFromNow, float durationSeconds, float frequency, float amplitude, uint64_t restrictToDevice)
{
    STUB();
}

InputError InputImpl::getActionOrigins(uint64_t actionSet, uint64_t action, uint64_t* originDevices, uint32_t originDevicesCount)
{
    STUB();
}

InputError InputImpl::getOriginLocalizedName(uint64_t originDevice, char* name, uint32_t bufferSize, int32_t stringSectionsToInclude)
{
    STUB();
}

InputError InputImpl::getOriginTrackedDeviceInfo(uint64_t originDevice, InputOriginInfo* info, uint32_t infoBufferSize)
{
    InputOriginInfo infoLocal;
    infoLocal.deviceHandle = originDevice;
    switch (originDevice)
    {
        case input::Device::HAND_LEFT:
            infoLocal.trackedDeviceIndex = 1;
            break;
        case input::Device::HAND_RIGHT:
            infoLocal.trackedDeviceIndex = 2;
            break;
        default:
            infoLocal.trackedDeviceIndex = 0xFFFFFFFF;
            break;
    }
    STUB_F("renderModelComponentName missing");
    infoLocal.renderModelComponentName[0] = '\0'; // TODO
    std::memcpy(info, &infoLocal, infoBufferSize < sizeof(InputOriginInfo) ? infoBufferSize : sizeof(InputOriginInfo));
    return InputError::INPUT_ERROR_NONE;
}

InputError InputImpl::getActionBindingInfo(uint64_t action, InputBindingInfo* bindings, uint32_t bindingInfoSize, uint32_t bindingsBufferCount, uint32_t* returnedBindingsCount)
{
    STUB();
    *returnedBindingsCount = 0;
    return InputError::INPUT_ERROR_NONE;
}

InputError InputImpl::showActionOrigins(uint64_t actionSet, uint64_t action)
{
    STUB();
}

InputError InputImpl::showBindingsForActionSet(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount, uint64_t originDeviceToHighlight)
{
    STUB();
}

InputError InputImpl::getComponentStateForBinding(const char* renderModelName, const char* componentName, const InputBindingInfo* bindings, uint32_t bindingInfoSize, uint32_t bindingsCount, RenderModelComponentState* componentState)
{
    STUB();
}

bool InputImpl::isUsingLegacyInput()
{
    return this->clientCore.actionManager == nullptr;
}

InputError InputImpl::openBindingUI(const char* appKey, uint64_t actionSet, uint64_t device, bool showOnDesktop)
{
    STUB();
}

InputError InputImpl::getBindingVariant(uint64_t device, char* variant, uint32_t bufferSize)
{
    STUB();
}
