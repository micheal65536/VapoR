#pragma once

#include "../types.h"
#include <cstdint>
#include "client_core.h"

namespace openvr
{
    class InputImpl
    {
        public:
            ClientCoreImpl& clientCore;
            InputImpl(ClientCoreImpl& clientCore);

            //

            InputError setActionManifestPath(const char* path);

            InputError getActionSetHandle(const char* actionSetName, uint64_t* handle);
            InputError getActionHandle(const char* actionName, uint64_t* handle);
            InputError getInputSourceHandle(const char* inputSourcePath, uint64_t* handle);

            InputError updateActionState(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount);
            InputError getDigitalActionData(uint64_t action, InputDigitalActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice);
            InputError getAnalogActionData(uint64_t action, InputAnalogActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice);
            InputError getPoseActionDataRelativeToNow(uint64_t action, TrackingUniverseOrigin origin, float secondsFromNow, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice);
            InputError getPoseActionDataForNextFrame(uint64_t action, TrackingUniverseOrigin origin, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice);
            InputError getSkeletalActionData(uint64_t action, InputSkeletalActionData* actionData, uint32_t actionDataSize);

            InputError getDominantHand(TrackedControllerRole* dominantHand);
            InputError setDominantHand(TrackedControllerRole dominantHand);

            InputError getBoneCount(uint64_t action, uint32_t* boneCount);
            InputError getBoneHierarchy(uint64_t action, int32_t* parentIndexes, uint32_t parentsCount);
            InputError getBoneName(uint64_t action, int32_t boneIndex, char* name, uint32_t bufferSize);
            InputError getSkeletalReferenceTransforms(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalReferencePose referencePose, BoneTransform* transforms, uint32_t transformsCount);
            InputError getSkeletalTrackingLevel(uint64_t action, SkeletalTrackingLevel* skeletalTrackingLevel);

            InputError getSkeletalBoneData(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalMotionRange motionRange, BoneTransform* transforms, uint32_t transformsCount);
            InputError getSkeletalSummaryData(uint64_t action, SkeletalSummaryType summaryType, SkeletalSummaryData* data);
            InputError getSkeletalBoneDataCompressed(uint64_t action, SkeletalMotionRange motionRange, void* data, uint32_t bufferSize, uint32_t* requiredBufferSize);
            InputError decompressSkeletalBoneData(const void* data, uint32_t size, SkeletalTransformSpace transformSpace, BoneTransform* transforms, uint32_t transformsCount);

            InputError triggerHapticVibrationAction(uint64_t action, float startSecondsFromNow, float durationSeconds, float frequency, float amplitude, uint64_t restrictToDevice);

            InputError getActionOrigins(uint64_t actionSet, uint64_t action, uint64_t* originDevices, uint32_t originDevicesCount);
            InputError getOriginLocalizedName(uint64_t originDevice, char* name, uint32_t bufferSize, int32_t stringSectionsToInclude);
            InputError getOriginTrackedDeviceInfo(uint64_t originDevice, InputOriginInfo* info, uint32_t infoBufferSize);
            InputError getActionBindingInfo(uint64_t action, InputBindingInfo* bindings, uint32_t bindingInfoSize, uint32_t bindingsBufferCount, uint32_t* returnedBindingsCount);
            InputError showActionOrigins(uint64_t actionSet, uint64_t action);
            InputError showBindingsForActionSet(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount, uint64_t originDeviceToHighlight);
            InputError getComponentStateForBinding(const char* renderModelName, const char* componentName, const InputBindingInfo* bindings, uint32_t bindingInfoSize, uint32_t bindingsCount, RenderModelComponentState* componentState);

            bool isUsingLegacyInput();

            InputError openBindingUI(const char* appKey, uint64_t actionSet, uint64_t device, bool showOnDesktop);

            InputError getBindingVariant(uint64_t device, char* variant, uint32_t bufferSize);
    };
}
