#include "input.h"
#include "log/log.h"
#include "log/stub.h"

#include "backend/input/action_manager.h"
#include "backend/input/input_devices.h"
#include "backend/input_profile.h"
#include "backend/path_handle_registry.h"
#include "utils/time.h"
#include "utils/pose.h"

#include <cstring>
#include <cmath>

using namespace openvr;

InputImpl::InputImpl(ClientCoreImpl& clientCore): clientCore(clientCore)
{
    // empty
}

InputError InputImpl::setActionManifestPath(const char* path)
{
    // TODO: move impl to backend
    vapor::input::ActionManager* actionManager = new vapor::input::ActionManager();
    if (!actionManager->populateFromJSON(path))
    {
        LOG("Failed to read actions from %s", path);
        return InputError::INPUT_ERROR_IPC_ERROR;
    }
    else
    {
        LOG("Read actions from %s", path);
        if (actionManager->loadBinding("vapor_binding.json", this->clientCore.backend->inputProfile))
        {
            LOG("Loaded custom binding");
        }
        else
        {
            LOG("Failed to load custom binding, trying default binding");
            actionManager->loadDefaultBindingForControllerProfile(this->clientCore.backend->inputProfile);
        }
        this->clientCore.backend->actionManager = actionManager; //
        return InputError::INPUT_ERROR_NONE;
    }
}

InputError InputImpl::getActionSetHandle(const char* actionSetName, uint64_t* handle)
{
    TRACE_F("%s", actionSetName);
    *handle = vapor::pathHandleRegistry.getHandle(actionSetName);
    return InputError::INPUT_ERROR_NONE;
}

InputError InputImpl::getActionHandle(const char* actionName, uint64_t* handle)
{
    TRACE_F("%s", actionName);
    *handle = vapor::pathHandleRegistry.getHandle(actionName);
    return InputError::INPUT_ERROR_NONE;
}

InputError InputImpl::getInputSourceHandle(const char* inputSourcePath, uint64_t* handle)
{
    TRACE_F("%s", inputSourcePath);
    *handle = vapor::pathHandleRegistry.getHandle(inputSourcePath);
    return InputError::INPUT_ERROR_NONE;
}

InputError InputImpl::updateActionState(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount)
{
    // TODO: move impl to backend
    if (this->clientCore.backend->actionManager != nullptr)
    {
        this->clientCore.backend->actionManager->update(actionSets, actionSetSize, actionSetsCount, this->clientCore.backend->frameStates.getFrame(0).inputStates.data(), this->clientCore.backend->getCurrentXrTime());
        return InputError::INPUT_ERROR_NONE;
    }
    else
    {
        return InputError::INPUT_ERROR_NO_ACTIVE_ACTION_SET;
    }
}

InputError InputImpl::getDigitalActionData(uint64_t action, InputDigitalActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    TRACE_F("%d %d", action, restrictToDevice);

    const vapor::input::Action* action_ = this->clientCore.backend->actionManager != nullptr ? this->clientCore.backend->actionManager->findAction(vapor::pathHandleRegistry.getPath(action)) : nullptr;
    if (action_ == nullptr)
    {
        return InputError::INPUT_ERROR_INVALID_HANDLE;
    }
    if (action_->type != vapor::input::InputType::DIGITAL)
    {
        return InputError::INPUT_ERROR_WRONG_TYPE;
    }
    vapor::input::Device device = restrictToDevice != 0 ? vapor::input::getDeviceFromInputSourcePath(vapor::pathHandleRegistry.getPath(restrictToDevice), false) : vapor::input::Device::INVALID;

    const vapor::input::InputState* inputState = nullptr;
    const vapor::input::InputState* inputStatePrevious = nullptr;
    for (const vapor::input::Action::Source& source: action_->sources)
    {
        if (restrictToDevice == 0 || source.device == device)
        {
            if (source.inputState.type == vapor::input::InputType::DIGITAL)
            {
                if (inputState == nullptr || (source.inputState.data.digital && !inputState->data.digital) || (source.inputState.data.digital == inputState->data.digital && source.inputState.changeTime > inputState->changeTime))
                {
                    inputState = &source.inputState;
                }
            }
            if (source.inputStatePrevious.type == vapor::input::InputType::DIGITAL)
            {
                if (inputStatePrevious == nullptr || (source.inputStatePrevious.data.digital && !inputStatePrevious->data.digital) || (source.inputStatePrevious.data.digital == inputStatePrevious->data.digital && source.inputStatePrevious.changeTime > inputStatePrevious->changeTime))
                {
                    inputStatePrevious = &source.inputStatePrevious;
                }
            }
        }
    }

    bool state = inputState != nullptr ? inputState->data.digital : false;
    bool previousState = inputStatePrevious != nullptr ? inputStatePrevious->data.digital : false;
    *actionData = {
        .active = inputState != nullptr,
        .currentOrigin = inputState != nullptr ? inputState->inputSourceHandle : 0,
        .state = state,
        .changed = state != previousState,
        .updateTime = inputState != nullptr ? -utils::convertXrTimeToSecondsAgo(inputState->changeTime, this->clientCore.backend->getCurrentXrTime()) : 0.0f
    };
    return InputError::INPUT_ERROR_NONE;
}

InputError InputImpl::getAnalogActionData(uint64_t action, InputAnalogActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    TRACE_F("%d %d", action, restrictToDevice);

    const vapor::input::Action* action_ = this->clientCore.backend->actionManager != nullptr ? this->clientCore.backend->actionManager->findAction(vapor::pathHandleRegistry.getPath(action)) : nullptr;
    if (action_ == nullptr)
    {
        return InputError::INPUT_ERROR_INVALID_HANDLE;
    }
    if (action_->type != vapor::input::InputType::ANALOG)
    {
        return InputError::INPUT_ERROR_WRONG_TYPE;
    }
    vapor::input::Device device = restrictToDevice != 0 ? vapor::input::getDeviceFromInputSourcePath(vapor::pathHandleRegistry.getPath(restrictToDevice), false) : vapor::input::Device::INVALID;

    const vapor::input::InputState* inputState = nullptr;
    const vapor::input::InputState* inputStatePrevious = nullptr;
    for (const vapor::input::Action::Source& source: action_->sources)
    {
        if (restrictToDevice == 0 || source.device == device)
        {
            if (source.inputState.type == vapor::input::InputType::ANALOG)
            {
                if (inputState == nullptr || (source.inputState.data.analog > inputState->data.analog))
                {
                    inputState = &source.inputState;
                }
            }
            if (source.inputStatePrevious.type == vapor::input::InputType::ANALOG)
            {
                if (inputStatePrevious == nullptr || (source.inputStatePrevious.data.analog > inputStatePrevious->data.analog))
                {
                    inputStatePrevious = &source.inputStatePrevious;
                }
            }
        }
    }

    vapor::input::InputState::Analog value = inputState != nullptr ? inputState->data.analog : (vapor::input::InputState::Analog) {0.0f, 0.0f, 0.0f};
    vapor::input::InputState::Analog previousValue = inputStatePrevious != nullptr ? inputStatePrevious->data.analog : (vapor::input::InputState::Analog) {0.0f, 0.0f, 0.0f};
    *actionData = {
        .active = inputState != nullptr,
        .currentOrigin = inputState != nullptr ? inputState->inputSourceHandle : 0,
        .x = value.x,
        .y = value.y,
        .z = value.z,
        .dx = value.x - previousValue.x,
        .dy = value.y - previousValue.y,
        .dz = value.z - previousValue.z,
        .updateTime = inputState != nullptr ? -utils::convertXrTimeToSecondsAgo(inputState->changeTime, this->clientCore.backend->getCurrentXrTime()) : 0.0f
    };
    return InputError::INPUT_ERROR_NONE;
}

InputError InputImpl::getPoseActionDataRelativeToNow(uint64_t action, TrackingUniverseOrigin origin, float secondsFromNow, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    // TODO: support secondsFromNow

    TRACE_F("%d %d %f %d", action, restrictToDevice, secondsFromNow, actionDataSize);
    STUB_F("secondsFromNow not supported %f", secondsFromNow);

    const vapor::input::Action* action_ = this->clientCore.backend->actionManager != nullptr ? this->clientCore.backend->actionManager->findAction(vapor::pathHandleRegistry.getPath(action)) : nullptr;
    if (action_ == nullptr)
    {
        return InputError::INPUT_ERROR_INVALID_HANDLE;
    }
    if (action_->type != vapor::input::InputType::POSE)
    {
        return InputError::INPUT_ERROR_WRONG_TYPE;
    }
    vapor::input::Device device = restrictToDevice != 0 ? vapor::input::getDeviceFromInputSourcePath(vapor::pathHandleRegistry.getPath(restrictToDevice), false) : vapor::input::Device::INVALID;

    const vapor::PoseSet* poseSet = nullptr;
    uint64_t inputSourceHandle;
    for (const vapor::input::Action::PoseSource& poseSource: action_->poseSources)
    {
        if (restrictToDevice == 0 || poseSource.device == device)
        {
            if (poseSource.active)
            {
                if (poseSet == nullptr)
                {
                    poseSet = &poseSource.pose;
                    inputSourceHandle = poseSource.inputSourceHandle;
                    break;
                }
            }
        }
    }

    *actionData = {
        .active = poseSet != nullptr,
        .currentOrigin = poseSet != nullptr ? inputSourceHandle : 0
    };
    if (poseSet != nullptr)
    {
        utils::selectTrackedDevicePose(*poseSet, origin, false, &actionData->pose);
    }
    return InputError::INPUT_ERROR_NONE;
}

InputError InputImpl::getPoseActionDataForNextFrame(uint64_t action, TrackingUniverseOrigin origin, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    TRACE_F("%d %d %d", action, restrictToDevice, actionDataSize);

    const vapor::input::Action* action_ = this->clientCore.backend->actionManager != nullptr ? this->clientCore.backend->actionManager->findAction(vapor::pathHandleRegistry.getPath(action)) : nullptr;
    if (action_ == nullptr)
    {
        return InputError::INPUT_ERROR_INVALID_HANDLE;
    }
    if (action_->type != vapor::input::InputType::POSE)
    {
        return InputError::INPUT_ERROR_WRONG_TYPE;
    }
    vapor::input::Device device = restrictToDevice != 0 ? vapor::input::getDeviceFromInputSourcePath(vapor::pathHandleRegistry.getPath(restrictToDevice), false) : vapor::input::Device::INVALID;

    const vapor::PoseSet* poseSet = nullptr;
    uint64_t inputSourceHandle;
    for (const vapor::input::Action::PoseSource& poseSource: action_->poseSources)
    {
        if (restrictToDevice == 0 || poseSource.device == device)
        {
            if (poseSource.active)
            {
                if (poseSet == nullptr)
                {
                    poseSet = &poseSource.pose;
                    inputSourceHandle = poseSource.inputSourceHandle;
                    break;
                }
            }
        }
    }

    *actionData = {
        .active = poseSet != nullptr,
        .currentOrigin = poseSet != nullptr ? inputSourceHandle : 0
    };
    if (poseSet != nullptr)
    {
        utils::selectTrackedDevicePose(*poseSet, origin, false, &actionData->pose);
    }
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
    *dominantHand = TrackedControllerRole::CONTROLLER_ROLE_RIGHT_HAND;
    return InputError::INPUT_ERROR_NONE;
}

InputError InputImpl::setDominantHand(TrackedControllerRole dominantHand)
{
    STUB_F("%d", dominantHand);
    return InputError::INPUT_ERROR_NONE;
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
    TRACE_F("%d %d %f %f %f %f", action, restrictToDevice, startSecondsFromNow, durationSeconds, frequency, amplitude);
    if (startSecondsFromNow != 0.0f)
    {
        STUB_F("startSecondsFromNow %f not supported", startSecondsFromNow);
    }

    const vapor::input::Action* action_ = this->clientCore.backend->actionManager != nullptr ? this->clientCore.backend->actionManager->findAction(vapor::pathHandleRegistry.getPath(action)) : nullptr;
    if (action_ == nullptr)
    {
        return InputError::INPUT_ERROR_INVALID_HANDLE;
    }
    if (action_->type != vapor::input::InputType::HAPTIC)
    {
        return InputError::INPUT_ERROR_WRONG_TYPE;
    }
    vapor::input::Device device = restrictToDevice != 0 ? vapor::input::getDeviceFromInputSourcePath(vapor::pathHandleRegistry.getPath(restrictToDevice), false) : vapor::input::Device::INVALID;

    for (const vapor::input::Action::HapticOutput& hapticOutput: action_->hapticOutputs)
    {
        if (restrictToDevice == 0 || hapticOutput.device == device)
        {
            int durationUs = (int) std::lround((double) durationSeconds * 1000000.0);
            this->clientCore.backend->hapticQueue->queueHapticEvent(hapticOutput.openVRInputIndex, durationSeconds, frequency, amplitude);
        }
    }

    return InputError::INPUT_ERROR_NONE;
}

InputError InputImpl::getActionOrigins(uint64_t actionSet, uint64_t action, uint64_t* origins, uint32_t originsCount)
{
    TRACE_F("%d %d %d", actionSet, action, originsCount);

    // CHECK: actionSet parameter seems to be ignored/unused?

    const vapor::input::Action* action_ = this->clientCore.backend->actionManager != nullptr ? this->clientCore.backend->actionManager->findAction(vapor::pathHandleRegistry.getPath(action)) : nullptr;
    if (action_ == nullptr)
    {
        return InputError::INPUT_ERROR_INVALID_HANDLE;
    }

    int activeSourcesCount = 0;
    for (const vapor::input::Action::Source& source: action_->sources)
    {
        if (source.inputState.type != vapor::input::InputType::EMPTY)
        {
            activeSourcesCount++;
        }
    }
    for (const vapor::input::Action::PoseSource& poseSource: action_->poseSources)
    {
        if (poseSource.active)
        {
            activeSourcesCount++;
        }
    }

    if (originsCount < activeSourcesCount)
    {
        return InputError::INPUT_ERROR_BUFFER_TOO_SMALL;
    }
    int index = 0;
    for (const vapor::input::Action::Source& source: action_->sources)
    {
        if (source.inputState.type != vapor::input::InputType::EMPTY)
        {
            origins[index++] = source.inputState.inputSourceHandle;
        }
    }
    for (const vapor::input::Action::PoseSource& poseSource: action_->poseSources)
    {
        if (poseSource.active)
        {
            origins[index++] = poseSource.inputSourceHandle;
        }
    }
    while (index < activeSourcesCount)
    {
        origins[index++] = 0;
    }
    return InputError::INPUT_ERROR_NONE;
}

InputError InputImpl::getOriginLocalizedName(uint64_t origin, char* name, uint32_t bufferSize, int32_t stringSectionsToInclude)
{
    STUB();
    if (name != nullptr)
    {
        name[0] = '\0';
    }
    return InputError::INPUT_ERROR_NONE;
}

InputError InputImpl::getOriginTrackedDeviceInfo(uint64_t origin, InputOriginInfo* info, uint32_t infoBufferSize)
{
    std::string fullPath = vapor::pathHandleRegistry.getPath(origin);
    if (fullPath == "")
    {
        return InputError::INPUT_ERROR_INVALID_HANDLE;
    }

    InputOriginInfo infoLocal;
    STUB_F("renderModelComponentName missing");
    infoLocal.renderModelComponentName[0] = '\0'; // TODO

    vapor::input::Device device = vapor::input::getDeviceFromInputSourcePath(fullPath, false);
    if (device != vapor::input::Device::INVALID)
    {
        infoLocal.deviceHandle = origin;
        switch (device)
        {
            case vapor::input::Device::HAND_LEFT:
                infoLocal.trackedDeviceIndex = 1;
                break;
            case vapor::input::Device::HAND_RIGHT:
                infoLocal.trackedDeviceIndex = 2;
                break;
            default:
                infoLocal.trackedDeviceIndex = 0xFFFFFFFF;
                break;
        }
    }
    else
    {
        device = vapor::input::getDeviceFromInputSourcePath(fullPath, true);
        if (device == vapor::input::Device::INVALID)
        {
            return InputError::INPUT_ERROR_INVALID_HANDLE;
        }
        infoLocal.deviceHandle = vapor::pathHandleRegistry.getHandle(vapor::input::getDeviceInputSourcePath(device));
        switch (device)
        {
            case vapor::input::Device::HAND_LEFT:
                infoLocal.trackedDeviceIndex = 1;
                break;
            case vapor::input::Device::HAND_RIGHT:
                infoLocal.trackedDeviceIndex = 2;
                break;
            default:
                infoLocal.trackedDeviceIndex = 0xFFFFFFFF;
                break;
        }

        bool valid = false;
        vapor::input_profile::InputProfile* inputProfile = this->clientCore.backend->inputProfile;
        for (int i = 0; i < inputProfile->getOpenVRInputsCount(); i++)
        {
            const vapor::input_profile::OpenVRInputDescription& inputDescription = inputProfile->getOpenVRInputs()[i];
            if (fullPath == inputDescription.path)
            {
                valid = true;
                break;
            }
        }
        for (int i = 0; i < inputProfile->getOpenVRProfileInputsCount(); i++)
        {
            const vapor::input_profile::OpenVRProfileInputDescription& profileInputDescription = inputProfile->getOpenVRProfileInputs()[i];
            if (fullPath == profileInputDescription.path)
            {
                valid = true;
                break;
            }
        }
        if (!valid)
        {
            return InputError::INPUT_ERROR_INVALID_HANDLE;
        }
    }

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

InputError InputImpl::showBindingsForActionSet(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount, uint64_t originToHighlight)
{
    STUB();
}

InputError InputImpl::getComponentStateForBinding(const char* renderModelName, const char* componentName, const InputBindingInfo* bindings, uint32_t bindingInfoSize, uint32_t bindingsCount, RenderModelComponentState* componentState)
{
    STUB();
}

bool InputImpl::isUsingLegacyInput()
{
    // CHECK: are we supposed to disable legacy input state and events after action set input has been configured?
    return this->clientCore.backend->actionManager == nullptr;
}

InputError InputImpl::openBindingUI(const char* appKey, uint64_t actionSet, uint64_t device, bool showOnDesktop)
{
    STUB();
}

InputError InputImpl::getBindingVariant(uint64_t device, char* variant, uint32_t bufferSize)
{
    STUB();
}
