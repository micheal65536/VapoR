#pragma once

#include "../types.h"
#include <cstdint>

#include "../impl/input.h"

namespace openvr
{
    struct Input_003
    {
        static InputError setActionManifestPath(const char* path);

        static InputError getActionSetHandle(const char* actionSetName, uint64_t* handle);
        static InputError getActionHandle(const char* actionName, uint64_t* handle);
        static InputError getInputSourceHandle(const char* inputSourcePath, uint64_t* handle);

        static InputError updateActionState(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount);
        static InputError getDigitalActionData(uint64_t action, InputDigitalActionData* actionData, uint32_t actionDataSize);
        static InputError getAnalogActionData(uint64_t action, InputAnalogActionData* actionData, uint32_t actionDataSize);
        static InputError getPoseActionData(uint64_t action, TrackingUniverseOrigin origin, float secondsFromNow, InputPoseActionData* actionData, uint32_t actionDataSize);
        static InputError getSkeletalActionData(uint64_t action, SkeletalTransformSpace transformSpace, float secondsFromNow, InputSkeletalActionData* actionData, uint32_t actionDataSize, BoneTransform* transforms, uint32_t transformsCount);
        static InputError getSkeletalActionDataCompressed(uint64_t action, SkeletalTransformSpace transformSpace, float secondsFromNow, void* data, uint32_t bufferSize, uint32_t* requiredBufferSize);
        static InputError decompressSkeletalActionData(const void* data, uint32_t size, SkeletalTransformSpace transformSpace, BoneTransform* transforms, uint32_t transformsCount);

        static InputError triggerHapticVibrationAction(uint64_t action, float startSecondsFromNow, float durationSeconds, float frequency, float amplitude);

        static InputError getActionOrigins(uint64_t actionSet, uint64_t action, uint64_t* originDevices, uint32_t originDevicesCount);
        static InputError getOriginLocalizedName(uint64_t originDevice, char* name, uint32_t bufferSize);
        static InputError getOriginTrackedDeviceInfo(uint64_t originDevice, InputOriginInfo* info, uint32_t infoBufferSize);
        static InputError showActionOrigins(uint64_t actionSet, uint64_t action);
        static InputError showBindingsForActionSet(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount, uint64_t originDeviceToHighlight);

        void* setActionManifestPath_ = (void*) setActionManifestPath;
        void* getActionSetHandle_ = (void*) getActionSetHandle;
        void* getActionHandle_ = (void*) getActionHandle;
        void* getInputSourceHandle_ = (void*) getInputSourceHandle;
        void* updateActionState_ = (void*) updateActionState;
        void* getDigitalActionData_ = (void*) getDigitalActionData;
        void* getAnalogActionData_ = (void*) getAnalogActionData;
        void* getPoseActionData_ = (void*) getPoseActionData;
        void* getSkeletalActionData_ = (void*) getSkeletalActionData;
        void* getSkeletalActionDataCompressed_ = (void*) getSkeletalActionDataCompressed;
        void* decompressSkeletalActionData_ = (void*) decompressSkeletalActionData;
        void* triggerHapticVibrationAction_ = (void*) triggerHapticVibrationAction;
        void* getActionOrigins_ = (void*) getActionOrigins;
        void* getOriginLocalizedName_ = (void*) getOriginLocalizedName;
        void* getOriginTrackedDeviceInfo_ = (void*) getOriginTrackedDeviceInfo;
        void* showActionOrigins_ = (void*) showActionOrigins;
        void* showBindingsForActionSet_ = (void*) showBindingsForActionSet;
    };

    class Input_003_v
    {
        public:
            virtual InputError setActionManifestPath(const char* path) { return Input_003::setActionManifestPath(path); }
            virtual InputError getActionSetHandle(const char* actionSetName, uint64_t* handle) { return Input_003::getActionSetHandle(actionSetName, handle); }
            virtual InputError getActionHandle(const char* actionName, uint64_t* handle) { return Input_003::getActionHandle(actionName, handle); }
            virtual InputError getInputSourceHandle(const char* inputSourcePath, uint64_t* handle) { return Input_003::getInputSourceHandle(inputSourcePath, handle); }
            virtual InputError updateActionState(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount) { return Input_003::updateActionState(actionSets, actionSetSize, actionSetsCount); }
            virtual InputError getDigitalActionData(uint64_t action, InputDigitalActionData* actionData, uint32_t actionDataSize) { return Input_003::getDigitalActionData(action, actionData, actionDataSize); }
            virtual InputError getAnalogActionData(uint64_t action, InputAnalogActionData* actionData, uint32_t actionDataSize) { return Input_003::getAnalogActionData(action, actionData, actionDataSize); }
            virtual InputError getPoseActionData(uint64_t action, TrackingUniverseOrigin origin, float secondsFromNow, InputPoseActionData* actionData, uint32_t actionDataSize) { return Input_003::getPoseActionData(action, origin, secondsFromNow, actionData, actionDataSize); }
            virtual InputError getSkeletalActionData(uint64_t action, SkeletalTransformSpace transformSpace, float secondsFromNow, InputSkeletalActionData* actionData, uint32_t actionDataSize, BoneTransform* transforms, uint32_t transformsCount) { return Input_003::getSkeletalActionData(action, transformSpace, secondsFromNow, actionData, actionDataSize, transforms, transformsCount); }
            virtual InputError getSkeletalActionDataCompressed(uint64_t action, SkeletalTransformSpace transformSpace, float secondsFromNow, void* data, uint32_t bufferSize, uint32_t* requiredBufferSize) { return Input_003::getSkeletalActionDataCompressed(action, transformSpace, secondsFromNow, data, bufferSize, requiredBufferSize); }
            virtual InputError decompressSkeletalActionData(const void* data, uint32_t size, SkeletalTransformSpace transformSpace, BoneTransform* transforms, uint32_t transformsCount) { return Input_003::decompressSkeletalActionData(data, size, transformSpace, transforms, transformsCount); }
            virtual InputError triggerHapticVibrationAction(uint64_t action, float startSecondsFromNow, float durationSeconds, float frequency, float amplitude) { return Input_003::triggerHapticVibrationAction(action, startSecondsFromNow, durationSeconds, frequency, amplitude); }
            virtual InputError getActionOrigins(uint64_t actionSet, uint64_t action, uint64_t* originDevices, uint32_t originDevicesCount) { return Input_003::getActionOrigins(actionSet, action, originDevices, originDevicesCount); }
            virtual InputError getOriginLocalizedName(uint64_t originDevice, char* name, uint32_t bufferSize) { return Input_003::getOriginLocalizedName(originDevice, name, bufferSize); }
            virtual InputError getOriginTrackedDeviceInfo(uint64_t originDevice, InputOriginInfo* info, uint32_t infoBufferSize) { return Input_003::getOriginTrackedDeviceInfo(originDevice, info, infoBufferSize); }
            virtual InputError showActionOrigins(uint64_t actionSet, uint64_t action) { return Input_003::showActionOrigins(actionSet, action); }
            virtual InputError showBindingsForActionSet(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount, uint64_t originDeviceToHighlight) { return Input_003::showBindingsForActionSet(actionSets, actionSetSize, actionSetsCount, originDeviceToHighlight); }
    };

    //

    struct Input_004
    {
        static InputError setActionManifestPath(const char* path);

        static InputError getActionSetHandle(const char* actionSetName, uint64_t* handle);
        static InputError getActionHandle(const char* actionName, uint64_t* handle);
        static InputError getInputSourceHandle(const char* inputSourcePath, uint64_t* handle);

        static InputError updateActionState(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount);
        static InputError getDigitalActionData(uint64_t action, InputDigitalActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice);
        static InputError getAnalogActionData(uint64_t action, InputAnalogActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice);
        static InputError getPoseActionData(uint64_t action, TrackingUniverseOrigin origin, float secondsFromNow, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice);
        static InputError getSkeletalActionData(uint64_t action, InputSkeletalActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice);

        static InputError getSkeletalBoneData(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalMotionRange motionRange, BoneTransform* transforms, uint32_t transformsCount, uint64_t restrictToDevice);
        static InputError getSkeletalBoneDataCompressed(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalMotionRange motionRange, void* data, uint32_t bufferSize, uint32_t* requiredBufferSize, uint64_t restrictToDevice);
        static InputError decompressSkeletalBoneData(const void* data, uint32_t size, SkeletalTransformSpace transformSpace, BoneTransform* transforms, uint32_t transformsCount);

        static InputError triggerHapticVibrationAction(uint64_t action, float startSecondsFromNow, float durationSeconds, float frequency, float amplitude, uint64_t restrictToDevice);

        static InputError getActionOrigins(uint64_t actionSet, uint64_t action, uint64_t* originDevices, uint32_t originDevicesCount);
        static InputError getOriginLocalizedName(uint64_t originDevice, char* name, uint32_t bufferSize);
        static InputError getOriginTrackedDeviceInfo(uint64_t originDevice, InputOriginInfo* info, uint32_t infoBufferSize);
        static InputError showActionOrigins(uint64_t actionSet, uint64_t action);
        static InputError showBindingsForActionSet(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount, uint64_t originDeviceToHighlight);

        void* setActionManifestPath_ = (void*) setActionManifestPath;
        void* getActionSetHandle_ = (void*) getActionSetHandle;
        void* getActionHandle_ = (void*) getActionHandle;
        void* getInputSourceHandle_ = (void*) getInputSourceHandle;
        void* updateActionState_ = (void*) updateActionState;
        void* getDigitalActionData_ = (void*) getDigitalActionData;
        void* getAnalogActionData_ = (void*) getAnalogActionData;
        void* getPoseActionData_ = (void*) getPoseActionData;
        void* getSkeletalActionData_ = (void*) getSkeletalActionData;
        void* getSkeletalBoneData_ = (void*) getSkeletalBoneData;
        void* getSkeletalBoneDataCompressed_ = (void*) getSkeletalBoneDataCompressed;
        void* decompressSkeletalBoneData_ = (void*) decompressSkeletalBoneData;
        void* triggerHapticVibrationAction_ = (void*) triggerHapticVibrationAction;
        void* getActionOrigins_ = (void*) getActionOrigins;
        void* getOriginLocalizedName_ = (void*) getOriginLocalizedName;
        void* getOriginTrackedDeviceInfo_ = (void*) getOriginTrackedDeviceInfo;
        void* showActionOrigins_ = (void*) showActionOrigins;
        void* showBindingsForActionSet_ = (void*) showBindingsForActionSet;
    };

    class Input_004_v
    {
        public:
            virtual InputError setActionManifestPath(const char* path) { return Input_004::setActionManifestPath(path); }
            virtual InputError getActionSetHandle(const char* actionSetName, uint64_t* handle) { return Input_004::getActionSetHandle(actionSetName, handle); }
            virtual InputError getActionHandle(const char* actionName, uint64_t* handle) { return Input_004::getActionHandle(actionName, handle); }
            virtual InputError getInputSourceHandle(const char* inputSourcePath, uint64_t* handle) { return Input_004::getInputSourceHandle(inputSourcePath, handle); }
            virtual InputError updateActionState(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount) { return Input_004::updateActionState(actionSets, actionSetSize, actionSetsCount); }
            virtual InputError getDigitalActionData(uint64_t action, InputDigitalActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice) { return Input_004::getDigitalActionData(action, actionData, actionDataSize, restrictToDevice); }
            virtual InputError getAnalogActionData(uint64_t action, InputAnalogActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice) { return Input_004::getAnalogActionData(action, actionData, actionDataSize, restrictToDevice); }
            virtual InputError getPoseActionData(uint64_t action, TrackingUniverseOrigin origin, float secondsFromNow, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice) { return Input_004::getPoseActionData(action, origin, secondsFromNow, actionData, actionDataSize, restrictToDevice); }
            virtual InputError getSkeletalActionData(uint64_t action, InputSkeletalActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice) { return Input_004::getSkeletalActionData(action, actionData, actionDataSize, restrictToDevice); }
            virtual InputError getSkeletalBoneData(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalMotionRange motionRange, BoneTransform* transforms, uint32_t transformsCount, uint64_t restrictToDevice) { return Input_004::getSkeletalBoneData(action, transformSpace, motionRange, transforms, transformsCount, restrictToDevice); }
            virtual InputError getSkeletalBoneDataCompressed(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalMotionRange motionRange, void* data, uint32_t bufferSize, uint32_t* requiredBufferSize, uint64_t restrictToDevice) { return Input_004::getSkeletalBoneDataCompressed(action, transformSpace, motionRange, data, bufferSize, requiredBufferSize, restrictToDevice); }
            virtual InputError decompressSkeletalBoneData(const void* data, uint32_t size, SkeletalTransformSpace transformSpace, BoneTransform* transforms, uint32_t transformsCount) { return Input_004::decompressSkeletalBoneData(data, size, transformSpace, transforms, transformsCount); }
            virtual InputError triggerHapticVibrationAction(uint64_t action, float startSecondsFromNow, float durationSeconds, float frequency, float amplitude, uint64_t restrictToDevice) { return Input_004::triggerHapticVibrationAction(action, startSecondsFromNow, durationSeconds, frequency, amplitude, restrictToDevice); }
            virtual InputError getActionOrigins(uint64_t actionSet, uint64_t action, uint64_t* originDevices, uint32_t originDevicesCount) { return Input_004::getActionOrigins(actionSet, action, originDevices, originDevicesCount); }
            virtual InputError getOriginLocalizedName(uint64_t originDevice, char* name, uint32_t bufferSize) { return Input_004::getOriginLocalizedName(originDevice, name, bufferSize); }
            virtual InputError getOriginTrackedDeviceInfo(uint64_t originDevice, InputOriginInfo* info, uint32_t infoBufferSize) { return Input_004::getOriginTrackedDeviceInfo(originDevice, info, infoBufferSize); }
            virtual InputError showActionOrigins(uint64_t actionSet, uint64_t action) { return Input_004::showActionOrigins(actionSet, action); }
            virtual InputError showBindingsForActionSet(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount, uint64_t originDeviceToHighlight) { return Input_004::showBindingsForActionSet(actionSets, actionSetSize, actionSetsCount, originDeviceToHighlight); }
    };

    //

    struct Input_005
    {
        static InputError setActionManifestPath(const char* path);

        static InputError getActionSetHandle(const char* actionSetName, uint64_t* handle);
        static InputError getActionHandle(const char* actionName, uint64_t* handle);
        static InputError getInputSourceHandle(const char* inputSourcePath, uint64_t* handle);

        static InputError updateActionState(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount);
        static InputError getDigitalActionData(uint64_t action, InputDigitalActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice);
        static InputError getAnalogActionData(uint64_t action, InputAnalogActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice);
        static InputError getPoseActionData(uint64_t action, TrackingUniverseOrigin origin, float secondsFromNow, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice);
        static InputError getSkeletalActionData(uint64_t action, InputSkeletalActionData* actionData, uint32_t actionDataSize);

        static InputError getBoneCount(uint64_t action, uint32_t* boneCount);
        static InputError getBoneHierarchy(uint64_t action, int32_t* parentIndexes, uint32_t parentsCount);
        static InputError getBoneName(uint64_t action, int32_t boneIndex, char* name, uint32_t bufferSize);
        static InputError getSkeletalReferenceTransforms(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalReferencePose referencePose, BoneTransform* transforms, uint32_t transformsCount);
        static InputError getSkeletalTrackingLevel(uint64_t action, SkeletalTrackingLevel* skeletalTrackingLevel);

        static InputError getSkeletalBoneData(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalMotionRange motionRange, BoneTransform* transforms, uint32_t transformsCount);
        static InputError getSkeletalSummaryData(uint64_t action, SkeletalSummaryData* data);
        static InputError getSkeletalBoneDataCompressed(uint64_t action, SkeletalMotionRange motionRange, void* data, uint32_t bufferSize, uint32_t* requiredBufferSize);
        static InputError decompressSkeletalBoneData(const void* data, uint32_t size, SkeletalTransformSpace transformSpace, BoneTransform* transforms, uint32_t transformsCount);

        static InputError triggerHapticVibrationAction(uint64_t action, float startSecondsFromNow, float durationSeconds, float frequency, float amplitude, uint64_t restrictToDevice);

        static InputError getActionOrigins(uint64_t actionSet, uint64_t action, uint64_t* originDevices, uint32_t originDevicesCount);
        static InputError getOriginLocalizedName(uint64_t originDevice, char* name, uint32_t bufferSize, int32_t stringSectionsToInclude);
        static InputError getOriginTrackedDeviceInfo(uint64_t originDevice, InputOriginInfo* info, uint32_t infoBufferSize);
        static InputError showActionOrigins(uint64_t actionSet, uint64_t action);
        static InputError showBindingsForActionSet(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount, uint64_t originDeviceToHighlight);

        static bool isUsingLegacyInput();

        void* setActionManifestPath_ = (void*) setActionManifestPath;
        void* getActionSetHandle_ = (void*) getActionSetHandle;
        void* getActionHandle_ = (void*) getActionHandle;
        void* getInputSourceHandle_ = (void*) getInputSourceHandle;
        void* updateActionState_ = (void*) updateActionState;
        void* getDigitalActionData_ = (void*) getDigitalActionData;
        void* getAnalogActionData_ = (void*) getAnalogActionData;
        void* getPoseActionData_ = (void*) getPoseActionData;
        void* getSkeletalActionData_ = (void*) getSkeletalActionData;
        void* getBoneCount_ = (void*) getBoneCount;
        void* getBoneHierarchy_ = (void*) getBoneHierarchy;
        void* getBoneName_ = (void*) getBoneName;
        void* getSkeletalReferenceTransforms_ = (void*) getSkeletalReferenceTransforms;
        void* getSkeletalTrackingLevel_ = (void*) getSkeletalTrackingLevel;
        void* getSkeletalBoneData_ = (void*) getSkeletalBoneData;
        void* getSkeletalSummaryData_ = (void*) getSkeletalSummaryData;
        void* getSkeletalBoneDataCompressed_ = (void*) getSkeletalBoneDataCompressed;
        void* decompressSkeletalBoneData_ = (void*) decompressSkeletalBoneData;
        void* triggerHapticVibrationAction_ = (void*) triggerHapticVibrationAction;
        void* getActionOrigins_ = (void*) getActionOrigins;
        void* getOriginLocalizedName_ = (void*) getOriginLocalizedName;
        void* getOriginTrackedDeviceInfo_ = (void*) getOriginTrackedDeviceInfo;
        void* showActionOrigins_ = (void*) showActionOrigins;
        void* showBindingsForActionSet_ = (void*) showBindingsForActionSet;
        void* isUsingLegacyInput_ = (void*) isUsingLegacyInput;
    };

    class Input_005_v
    {
        public:
            virtual InputError setActionManifestPath(const char* path) { return Input_005::setActionManifestPath(path); }
            virtual InputError getActionSetHandle(const char* actionSetName, uint64_t* handle) { return Input_005::getActionSetHandle(actionSetName, handle); }
            virtual InputError getActionHandle(const char* actionName, uint64_t* handle) { return Input_005::getActionHandle(actionName, handle); }
            virtual InputError getInputSourceHandle(const char* inputSourcePath, uint64_t* handle) { return Input_005::getInputSourceHandle(inputSourcePath, handle); }
            virtual InputError updateActionState(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount) { return Input_005::updateActionState(actionSets, actionSetSize, actionSetsCount); }
            virtual InputError getDigitalActionData(uint64_t action, InputDigitalActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice) { return Input_005::getDigitalActionData(action, actionData, actionDataSize, restrictToDevice); }
            virtual InputError getAnalogActionData(uint64_t action, InputAnalogActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice) { return Input_005::getAnalogActionData(action, actionData, actionDataSize, restrictToDevice); }
            virtual InputError getPoseActionData(uint64_t action, TrackingUniverseOrigin origin, float secondsFromNow, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice) { return Input_005::getPoseActionData(action, origin, secondsFromNow, actionData, actionDataSize, restrictToDevice); }
            virtual InputError getSkeletalActionData(uint64_t action, InputSkeletalActionData* actionData, uint32_t actionDataSize) { return Input_005::getSkeletalActionData(action, actionData, actionDataSize); }
            virtual InputError getBoneCount(uint64_t action, uint32_t* boneCount) { return Input_005::getBoneCount(action, boneCount); }
            virtual InputError getBoneHierarchy(uint64_t action, int32_t* parentIndexes, uint32_t parentsCount) { return Input_005::getBoneHierarchy(action, parentIndexes, parentsCount); }
            virtual InputError getBoneName(uint64_t action, int32_t boneIndex, char* name, uint32_t bufferSize) { return Input_005::getBoneName(action, boneIndex, name, bufferSize); }
            virtual InputError getSkeletalReferenceTransforms(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalReferencePose referencePose, BoneTransform* transforms, uint32_t transformsCount) { return Input_005::getSkeletalReferenceTransforms(action, transformSpace, referencePose, transforms, transformsCount); }
            virtual InputError getSkeletalTrackingLevel(uint64_t action, SkeletalTrackingLevel* skeletalTrackingLevel) { return Input_005::getSkeletalTrackingLevel(action, skeletalTrackingLevel); }
            virtual InputError getSkeletalBoneData(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalMotionRange motionRange, BoneTransform* transforms, uint32_t transformsCount) { return Input_005::getSkeletalBoneData(action, transformSpace, motionRange, transforms, transformsCount); }
            virtual InputError getSkeletalSummaryData(uint64_t action, SkeletalSummaryData* data) { return Input_005::getSkeletalSummaryData(action, data); }
            virtual InputError getSkeletalBoneDataCompressed(uint64_t action, SkeletalMotionRange motionRange, void* data, uint32_t bufferSize, uint32_t* requiredBufferSize) { return Input_005::getSkeletalBoneDataCompressed(action, motionRange, data, bufferSize, requiredBufferSize); }
            virtual InputError decompressSkeletalBoneData(const void* data, uint32_t size, SkeletalTransformSpace transformSpace, BoneTransform* transforms, uint32_t transformsCount) { return Input_005::decompressSkeletalBoneData(data, size, transformSpace, transforms, transformsCount); }
            virtual InputError triggerHapticVibrationAction(uint64_t action, float startSecondsFromNow, float durationSeconds, float frequency, float amplitude, uint64_t restrictToDevice) { return Input_005::triggerHapticVibrationAction(action, startSecondsFromNow, durationSeconds, frequency, amplitude, restrictToDevice); }
            virtual InputError getActionOrigins(uint64_t actionSet, uint64_t action, uint64_t* originDevices, uint32_t originDevicesCount) { return Input_005::getActionOrigins(actionSet, action, originDevices, originDevicesCount); }
            virtual InputError getOriginLocalizedName(uint64_t originDevice, char* name, uint32_t bufferSize, int32_t stringSectionsToInclude) { return Input_005::getOriginLocalizedName(originDevice, name, bufferSize, stringSectionsToInclude); }
            virtual InputError getOriginTrackedDeviceInfo(uint64_t originDevice, InputOriginInfo* info, uint32_t infoBufferSize) { return Input_005::getOriginTrackedDeviceInfo(originDevice, info, infoBufferSize); }
            virtual InputError showActionOrigins(uint64_t actionSet, uint64_t action) { return Input_005::showActionOrigins(actionSet, action); }
            virtual InputError showBindingsForActionSet(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount, uint64_t originDeviceToHighlight) { return Input_005::showBindingsForActionSet(actionSets, actionSetSize, actionSetsCount, originDeviceToHighlight); }
            virtual bool isUsingLegacyInput() { return Input_005::isUsingLegacyInput(); }
    };

    //

    struct Input_006
    {
        static InputError setActionManifestPath(const char* path);

        static InputError getActionSetHandle(const char* actionSetName, uint64_t* handle);
        static InputError getActionHandle(const char* actionName, uint64_t* handle);
        static InputError getInputSourceHandle(const char* inputSourcePath, uint64_t* handle);

        static InputError updateActionState(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount);
        static InputError getDigitalActionData(uint64_t action, InputDigitalActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice);
        static InputError getAnalogActionData(uint64_t action, InputAnalogActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice);
        static InputError getPoseActionDataRelativeToNow(uint64_t action, TrackingUniverseOrigin origin, float secondsFromNow, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice);
        static InputError getPoseActionDataForNextFrame(uint64_t action, TrackingUniverseOrigin origin, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice);
        static InputError getSkeletalActionData(uint64_t action, InputSkeletalActionData* actionData, uint32_t actionDataSize);

        static InputError getBoneCount(uint64_t action, uint32_t* boneCount);
        static InputError getBoneHierarchy(uint64_t action, int32_t* parentIndexes, uint32_t parentsCount);
        static InputError getBoneName(uint64_t action, int32_t boneIndex, char* name, uint32_t bufferSize);
        static InputError getSkeletalReferenceTransforms(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalReferencePose referencePose, BoneTransform* transforms, uint32_t transformsCount);
        static InputError getSkeletalTrackingLevel(uint64_t action, SkeletalTrackingLevel* skeletalTrackingLevel);

        static InputError getSkeletalBoneData(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalMotionRange motionRange, BoneTransform* transforms, uint32_t transformsCount);
        static InputError getSkeletalSummaryData(uint64_t action, SkeletalSummaryType summaryType, SkeletalSummaryData* data);
        static InputError getSkeletalBoneDataCompressed(uint64_t action, SkeletalMotionRange motionRange, void* data, uint32_t bufferSize, uint32_t* requiredBufferSize);
        static InputError decompressSkeletalBoneData(const void* data, uint32_t size, SkeletalTransformSpace transformSpace, BoneTransform* transforms, uint32_t transformsCount);

        static InputError triggerHapticVibrationAction(uint64_t action, float startSecondsFromNow, float durationSeconds, float frequency, float amplitude, uint64_t restrictToDevice);

        static InputError getActionOrigins(uint64_t actionSet, uint64_t action, uint64_t* originDevices, uint32_t originDevicesCount);
        static InputError getOriginLocalizedName(uint64_t originDevice, char* name, uint32_t bufferSize, int32_t stringSectionsToInclude);
        static InputError getOriginTrackedDeviceInfo(uint64_t originDevice, InputOriginInfo* info, uint32_t infoBufferSize);
        static InputError showActionOrigins(uint64_t actionSet, uint64_t action);
        static InputError showBindingsForActionSet(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount, uint64_t originDeviceToHighlight);

        static bool isUsingLegacyInput();

        void* setActionManifestPath_ = (void*) setActionManifestPath;
        void* getActionSetHandle_ = (void*) getActionSetHandle;
        void* getActionHandle_ = (void*) getActionHandle;
        void* getInputSourceHandle_ = (void*) getInputSourceHandle;
        void* updateActionState_ = (void*) updateActionState;
        void* getDigitalActionData_ = (void*) getDigitalActionData;
        void* getAnalogActionData_ = (void*) getAnalogActionData;
        void* getPoseActionDataRelativeToNow_ = (void*) getPoseActionDataRelativeToNow;
        void* getPoseActionDataForNextFrame_ = (void*) getPoseActionDataForNextFrame;
        void* getSkeletalActionData_ = (void*) getSkeletalActionData;
        void* getBoneCount_ = (void*) getBoneCount;
        void* getBoneHierarchy_ = (void*) getBoneHierarchy;
        void* getBoneName_ = (void*) getBoneName;
        void* getSkeletalReferenceTransforms_ = (void*) getSkeletalReferenceTransforms;
        void* getSkeletalTrackingLevel_ = (void*) getSkeletalTrackingLevel;
        void* getSkeletalBoneData_ = (void*) getSkeletalBoneData;
        void* getSkeletalSummaryData_ = (void*) getSkeletalSummaryData;
        void* getSkeletalBoneDataCompressed_ = (void*) getSkeletalBoneDataCompressed;
        void* decompressSkeletalBoneData_ = (void*) decompressSkeletalBoneData;
        void* triggerHapticVibrationAction_ = (void*) triggerHapticVibrationAction;
        void* getActionOrigins_ = (void*) getActionOrigins;
        void* getOriginLocalizedName_ = (void*) getOriginLocalizedName;
        void* getOriginTrackedDeviceInfo_ = (void*) getOriginTrackedDeviceInfo;
        void* showActionOrigins_ = (void*) showActionOrigins;
        void* showBindingsForActionSet_ = (void*) showBindingsForActionSet;
        void* isUsingLegacyInput_ = (void*) isUsingLegacyInput;
    };

    class Input_006_v
    {
        public:
            virtual InputError setActionManifestPath(const char* path) { return Input_006::setActionManifestPath(path); }
            virtual InputError getActionSetHandle(const char* actionSetName, uint64_t* handle) { return Input_006::getActionSetHandle(actionSetName, handle); }
            virtual InputError getActionHandle(const char* actionName, uint64_t* handle) { return Input_006::getActionHandle(actionName, handle); }
            virtual InputError getInputSourceHandle(const char* inputSourcePath, uint64_t* handle) { return Input_006::getInputSourceHandle(inputSourcePath, handle); }
            virtual InputError updateActionState(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount) { return Input_006::updateActionState(actionSets, actionSetSize, actionSetsCount); }
            virtual InputError getDigitalActionData(uint64_t action, InputDigitalActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice) { return Input_006::getDigitalActionData(action, actionData, actionDataSize, restrictToDevice); }
            virtual InputError getAnalogActionData(uint64_t action, InputAnalogActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice) { return Input_006::getAnalogActionData(action, actionData, actionDataSize, restrictToDevice); }
            virtual InputError getPoseActionDataRelativeToNow(uint64_t action, TrackingUniverseOrigin origin, float secondsFromNow, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice) { return Input_006::getPoseActionDataRelativeToNow(action, origin, secondsFromNow, actionData, actionDataSize, restrictToDevice); }
            virtual InputError getPoseActionDataForNextFrame(uint64_t action, TrackingUniverseOrigin origin, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice) { return Input_006::getPoseActionDataForNextFrame(action, origin, actionData, actionDataSize, restrictToDevice); }
            virtual InputError getSkeletalActionData(uint64_t action, InputSkeletalActionData* actionData, uint32_t actionDataSize) { return Input_006::getSkeletalActionData(action, actionData, actionDataSize); }
            virtual InputError getBoneCount(uint64_t action, uint32_t* boneCount) { return Input_006::getBoneCount(action, boneCount); }
            virtual InputError getBoneHierarchy(uint64_t action, int32_t* parentIndexes, uint32_t parentsCount) { return Input_006::getBoneHierarchy(action, parentIndexes, parentsCount); }
            virtual InputError getBoneName(uint64_t action, int32_t boneIndex, char* name, uint32_t bufferSize) { return Input_006::getBoneName(action, boneIndex, name, bufferSize); }
            virtual InputError getSkeletalReferenceTransforms(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalReferencePose referencePose, BoneTransform* transforms, uint32_t transformsCount) { return Input_006::getSkeletalReferenceTransforms(action, transformSpace, referencePose, transforms, transformsCount); }
            virtual InputError getSkeletalTrackingLevel(uint64_t action, SkeletalTrackingLevel* skeletalTrackingLevel) { return Input_006::getSkeletalTrackingLevel(action, skeletalTrackingLevel); }
            virtual InputError getSkeletalBoneData(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalMotionRange motionRange, BoneTransform* transforms, uint32_t transformsCount) { return Input_006::getSkeletalBoneData(action, transformSpace, motionRange, transforms, transformsCount); }
            virtual InputError getSkeletalSummaryData(uint64_t action, SkeletalSummaryType summaryType, SkeletalSummaryData* data) { return Input_006::getSkeletalSummaryData(action, summaryType, data); }
            virtual InputError getSkeletalBoneDataCompressed(uint64_t action, SkeletalMotionRange motionRange, void* data, uint32_t bufferSize, uint32_t* requiredBufferSize) { return Input_006::getSkeletalBoneDataCompressed(action, motionRange, data, bufferSize, requiredBufferSize); }
            virtual InputError decompressSkeletalBoneData(const void* data, uint32_t size, SkeletalTransformSpace transformSpace, BoneTransform* transforms, uint32_t transformsCount) { return Input_006::decompressSkeletalBoneData(data, size, transformSpace, transforms, transformsCount); }
            virtual InputError triggerHapticVibrationAction(uint64_t action, float startSecondsFromNow, float durationSeconds, float frequency, float amplitude, uint64_t restrictToDevice) { return Input_006::triggerHapticVibrationAction(action, startSecondsFromNow, durationSeconds, frequency, amplitude, restrictToDevice); }
            virtual InputError getActionOrigins(uint64_t actionSet, uint64_t action, uint64_t* originDevices, uint32_t originDevicesCount) { return Input_006::getActionOrigins(actionSet, action, originDevices, originDevicesCount); }
            virtual InputError getOriginLocalizedName(uint64_t originDevice, char* name, uint32_t bufferSize, int32_t stringSectionsToInclude) { return Input_006::getOriginLocalizedName(originDevice, name, bufferSize, stringSectionsToInclude); }
            virtual InputError getOriginTrackedDeviceInfo(uint64_t originDevice, InputOriginInfo* info, uint32_t infoBufferSize) { return Input_006::getOriginTrackedDeviceInfo(originDevice, info, infoBufferSize); }
            virtual InputError showActionOrigins(uint64_t actionSet, uint64_t action) { return Input_006::showActionOrigins(actionSet, action); }
            virtual InputError showBindingsForActionSet(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount, uint64_t originDeviceToHighlight) { return Input_006::showBindingsForActionSet(actionSets, actionSetSize, actionSetsCount, originDeviceToHighlight); }
            virtual bool isUsingLegacyInput() { return Input_006::isUsingLegacyInput(); }
    };

    //

    struct Input_007
    {
        static InputError setActionManifestPath(const char* path);

        static InputError getActionSetHandle(const char* actionSetName, uint64_t* handle);
        static InputError getActionHandle(const char* actionName, uint64_t* handle);
        static InputError getInputSourceHandle(const char* inputSourcePath, uint64_t* handle);

        static InputError updateActionState(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount);
        static InputError getDigitalActionData(uint64_t action, InputDigitalActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice);
        static InputError getAnalogActionData(uint64_t action, InputAnalogActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice);
        static InputError getPoseActionDataRelativeToNow(uint64_t action, TrackingUniverseOrigin origin, float secondsFromNow, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice);
        static InputError getPoseActionDataForNextFrame(uint64_t action, TrackingUniverseOrigin origin, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice);
        static InputError getSkeletalActionData(uint64_t action, InputSkeletalActionData* actionData, uint32_t actionDataSize);

        static InputError getBoneCount(uint64_t action, uint32_t* boneCount);
        static InputError getBoneHierarchy(uint64_t action, int32_t* parentIndexes, uint32_t parentsCount);
        static InputError getBoneName(uint64_t action, int32_t boneIndex, char* name, uint32_t bufferSize);
        static InputError getSkeletalReferenceTransforms(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalReferencePose referencePose, BoneTransform* transforms, uint32_t transformsCount);
        static InputError getSkeletalTrackingLevel(uint64_t action, SkeletalTrackingLevel* skeletalTrackingLevel);

        static InputError getSkeletalBoneData(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalMotionRange motionRange, BoneTransform* transforms, uint32_t transformsCount);
        static InputError getSkeletalSummaryData(uint64_t action, SkeletalSummaryType summaryType, SkeletalSummaryData* data);
        static InputError getSkeletalBoneDataCompressed(uint64_t action, SkeletalMotionRange motionRange, void* data, uint32_t bufferSize, uint32_t* requiredBufferSize);
        static InputError decompressSkeletalBoneData(const void* data, uint32_t size, SkeletalTransformSpace transformSpace, BoneTransform* transforms, uint32_t transformsCount);

        static InputError triggerHapticVibrationAction(uint64_t action, float startSecondsFromNow, float durationSeconds, float frequency, float amplitude, uint64_t restrictToDevice);

        static InputError getActionOrigins(uint64_t actionSet, uint64_t action, uint64_t* originDevices, uint32_t originDevicesCount);
        static InputError getOriginLocalizedName(uint64_t originDevice, char* name, uint32_t bufferSize, int32_t stringSectionsToInclude);
        static InputError getOriginTrackedDeviceInfo(uint64_t originDevice, InputOriginInfo* info, uint32_t infoBufferSize);
        static InputError getActionBindingInfo(uint64_t action, InputBindingInfo* bindings, uint32_t bindingInfoSize, uint32_t bindingsBufferCount, uint32_t* returnedBindingsCount);
        static InputError showActionOrigins(uint64_t actionSet, uint64_t action);
        static InputError showBindingsForActionSet(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount, uint64_t originDeviceToHighlight);

        static bool isUsingLegacyInput();

        static InputError openBindingUI(const char* appKey, uint64_t actionSet, uint64_t device, bool showOnDesktop);

        void* setActionManifestPath_ = (void*) setActionManifestPath;
        void* getActionSetHandle_ = (void*) getActionSetHandle;
        void* getActionHandle_ = (void*) getActionHandle;
        void* getInputSourceHandle_ = (void*) getInputSourceHandle;
        void* updateActionState_ = (void*) updateActionState;
        void* getDigitalActionData_ = (void*) getDigitalActionData;
        void* getAnalogActionData_ = (void*) getAnalogActionData;
        void* getPoseActionDataRelativeToNow_ = (void*) getPoseActionDataRelativeToNow;
        void* getPoseActionDataForNextFrame_ = (void*) getPoseActionDataForNextFrame;
        void* getSkeletalActionData_ = (void*) getSkeletalActionData;
        void* getBoneCount_ = (void*) getBoneCount;
        void* getBoneHierarchy_ = (void*) getBoneHierarchy;
        void* getBoneName_ = (void*) getBoneName;
        void* getSkeletalReferenceTransforms_ = (void*) getSkeletalReferenceTransforms;
        void* getSkeletalTrackingLevel_ = (void*) getSkeletalTrackingLevel;
        void* getSkeletalBoneData_ = (void*) getSkeletalBoneData;
        void* getSkeletalSummaryData_ = (void*) getSkeletalSummaryData;
        void* getSkeletalBoneDataCompressed_ = (void*) getSkeletalBoneDataCompressed;
        void* decompressSkeletalBoneData_ = (void*) decompressSkeletalBoneData;
        void* triggerHapticVibrationAction_ = (void*) triggerHapticVibrationAction;
        void* getActionOrigins_ = (void*) getActionOrigins;
        void* getOriginLocalizedName_ = (void*) getOriginLocalizedName;
        void* getOriginTrackedDeviceInfo_ = (void*) getOriginTrackedDeviceInfo;
        void* getActionBindingInfo_ = (void*) getActionBindingInfo;
        void* showActionOrigins_ = (void*) showActionOrigins;
        void* showBindingsForActionSet_ = (void*) showBindingsForActionSet;
        void* isUsingLegacyInput_ = (void*) isUsingLegacyInput;
        void* openBindingUI_ = (void*) openBindingUI;
    };

    class Input_007_v
    {
        public:
            virtual InputError setActionManifestPath(const char* path) { return Input_007::setActionManifestPath(path); }
            virtual InputError getActionSetHandle(const char* actionSetName, uint64_t* handle) { return Input_007::getActionSetHandle(actionSetName, handle); }
            virtual InputError getActionHandle(const char* actionName, uint64_t* handle) { return Input_007::getActionHandle(actionName, handle); }
            virtual InputError getInputSourceHandle(const char* inputSourcePath, uint64_t* handle) { return Input_007::getInputSourceHandle(inputSourcePath, handle); }
            virtual InputError updateActionState(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount) { return Input_007::updateActionState(actionSets, actionSetSize, actionSetsCount); }
            virtual InputError getDigitalActionData(uint64_t action, InputDigitalActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice) { return Input_007::getDigitalActionData(action, actionData, actionDataSize, restrictToDevice); }
            virtual InputError getAnalogActionData(uint64_t action, InputAnalogActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice) { return Input_007::getAnalogActionData(action, actionData, actionDataSize, restrictToDevice); }
            virtual InputError getPoseActionDataRelativeToNow(uint64_t action, TrackingUniverseOrigin origin, float secondsFromNow, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice) { return Input_007::getPoseActionDataRelativeToNow(action, origin, secondsFromNow, actionData, actionDataSize, restrictToDevice); }
            virtual InputError getPoseActionDataForNextFrame(uint64_t action, TrackingUniverseOrigin origin, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice) { return Input_007::getPoseActionDataForNextFrame(action, origin, actionData, actionDataSize, restrictToDevice); }
            virtual InputError getSkeletalActionData(uint64_t action, InputSkeletalActionData* actionData, uint32_t actionDataSize) { return Input_007::getSkeletalActionData(action, actionData, actionDataSize); }
            virtual InputError getBoneCount(uint64_t action, uint32_t* boneCount) { return Input_007::getBoneCount(action, boneCount); }
            virtual InputError getBoneHierarchy(uint64_t action, int32_t* parentIndexes, uint32_t parentsCount) { return Input_007::getBoneHierarchy(action, parentIndexes, parentsCount); }
            virtual InputError getBoneName(uint64_t action, int32_t boneIndex, char* name, uint32_t bufferSize) { return Input_007::getBoneName(action, boneIndex, name, bufferSize); }
            virtual InputError getSkeletalReferenceTransforms(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalReferencePose referencePose, BoneTransform* transforms, uint32_t transformsCount) { return Input_007::getSkeletalReferenceTransforms(action, transformSpace, referencePose, transforms, transformsCount); }
            virtual InputError getSkeletalTrackingLevel(uint64_t action, SkeletalTrackingLevel* skeletalTrackingLevel) { return Input_007::getSkeletalTrackingLevel(action, skeletalTrackingLevel); }
            virtual InputError getSkeletalBoneData(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalMotionRange motionRange, BoneTransform* transforms, uint32_t transformsCount) { return Input_007::getSkeletalBoneData(action, transformSpace, motionRange, transforms, transformsCount); }
            virtual InputError getSkeletalSummaryData(uint64_t action, SkeletalSummaryType summaryType, SkeletalSummaryData* data) { return Input_007::getSkeletalSummaryData(action, summaryType, data); }
            virtual InputError getSkeletalBoneDataCompressed(uint64_t action, SkeletalMotionRange motionRange, void* data, uint32_t bufferSize, uint32_t* requiredBufferSize) { return Input_007::getSkeletalBoneDataCompressed(action, motionRange, data, bufferSize, requiredBufferSize); }
            virtual InputError decompressSkeletalBoneData(const void* data, uint32_t size, SkeletalTransformSpace transformSpace, BoneTransform* transforms, uint32_t transformsCount) { return Input_007::decompressSkeletalBoneData(data, size, transformSpace, transforms, transformsCount); }
            virtual InputError triggerHapticVibrationAction(uint64_t action, float startSecondsFromNow, float durationSeconds, float frequency, float amplitude, uint64_t restrictToDevice) { return Input_007::triggerHapticVibrationAction(action, startSecondsFromNow, durationSeconds, frequency, amplitude, restrictToDevice); }
            virtual InputError getActionOrigins(uint64_t actionSet, uint64_t action, uint64_t* originDevices, uint32_t originDevicesCount) { return Input_007::getActionOrigins(actionSet, action, originDevices, originDevicesCount); }
            virtual InputError getOriginLocalizedName(uint64_t originDevice, char* name, uint32_t bufferSize, int32_t stringSectionsToInclude) { return Input_007::getOriginLocalizedName(originDevice, name, bufferSize, stringSectionsToInclude); }
            virtual InputError getOriginTrackedDeviceInfo(uint64_t originDevice, InputOriginInfo* info, uint32_t infoBufferSize) { return Input_007::getOriginTrackedDeviceInfo(originDevice, info, infoBufferSize); }
            virtual InputError getActionBindingInfo(uint64_t action, InputBindingInfo* bindings, uint32_t bindingInfoSize, uint32_t bindingsBufferCount, uint32_t* returnedBindingsCount) { return Input_007::getActionBindingInfo(action, bindings, bindingInfoSize, bindingsBufferCount, returnedBindingsCount); }
            virtual InputError showActionOrigins(uint64_t actionSet, uint64_t action) { return Input_007::showActionOrigins(actionSet, action); }
            virtual InputError showBindingsForActionSet(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount, uint64_t originDeviceToHighlight) { return Input_007::showBindingsForActionSet(actionSets, actionSetSize, actionSetsCount, originDeviceToHighlight); }
            virtual bool isUsingLegacyInput() { return Input_007::isUsingLegacyInput(); }
            virtual InputError openBindingUI(const char* appKey, uint64_t actionSet, uint64_t device, bool showOnDesktop) { return Input_007::openBindingUI(appKey, actionSet, device, showOnDesktop); }
    };

    //

    struct Input_010
    {
        static InputError setActionManifestPath(const char* path);

        static InputError getActionSetHandle(const char* actionSetName, uint64_t* handle);
        static InputError getActionHandle(const char* actionName, uint64_t* handle);
        static InputError getInputSourceHandle(const char* inputSourcePath, uint64_t* handle);

        static InputError updateActionState(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount);
        static InputError getDigitalActionData(uint64_t action, InputDigitalActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice);
        static InputError getAnalogActionData(uint64_t action, InputAnalogActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice);
        static InputError getPoseActionDataRelativeToNow(uint64_t action, TrackingUniverseOrigin origin, float secondsFromNow, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice);
        static InputError getPoseActionDataForNextFrame(uint64_t action, TrackingUniverseOrigin origin, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice);
        static InputError getSkeletalActionData(uint64_t action, InputSkeletalActionData* actionData, uint32_t actionDataSize);

        static InputError getDominantHand(TrackedControllerRole* dominantHand);
        static InputError setDominantHand(TrackedControllerRole dominantHand);

        static InputError getBoneCount(uint64_t action, uint32_t* boneCount);
        static InputError getBoneHierarchy(uint64_t action, int32_t* parentIndexes, uint32_t parentsCount);
        static InputError getBoneName(uint64_t action, int32_t boneIndex, char* name, uint32_t bufferSize);
        static InputError getSkeletalReferenceTransforms(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalReferencePose referencePose, BoneTransform* transforms, uint32_t transformsCount);
        static InputError getSkeletalTrackingLevel(uint64_t action, SkeletalTrackingLevel* skeletalTrackingLevel);

        static InputError getSkeletalBoneData(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalMotionRange motionRange, BoneTransform* transforms, uint32_t transformsCount);
        static InputError getSkeletalSummaryData(uint64_t action, SkeletalSummaryType summaryType, SkeletalSummaryData* data);
        static InputError getSkeletalBoneDataCompressed(uint64_t action, SkeletalMotionRange motionRange, void* data, uint32_t bufferSize, uint32_t* requiredBufferSize);
        static InputError decompressSkeletalBoneData(const void* data, uint32_t size, SkeletalTransformSpace transformSpace, BoneTransform* transforms, uint32_t transformsCount);

        static InputError triggerHapticVibrationAction(uint64_t action, float startSecondsFromNow, float durationSeconds, float frequency, float amplitude, uint64_t restrictToDevice);

        static InputError getActionOrigins(uint64_t actionSet, uint64_t action, uint64_t* originDevices, uint32_t originDevicesCount);
        static InputError getOriginLocalizedName(uint64_t originDevice, char* name, uint32_t bufferSize, int32_t stringSectionsToInclude);
        static InputError getOriginTrackedDeviceInfo(uint64_t originDevice, InputOriginInfo* info, uint32_t infoBufferSize);
        static InputError getActionBindingInfo(uint64_t action, InputBindingInfo* bindings, uint32_t bindingInfoSize, uint32_t bindingsBufferCount, uint32_t* returnedBindingsCount);
        static InputError showActionOrigins(uint64_t actionSet, uint64_t action);
        static InputError showBindingsForActionSet(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount, uint64_t originDeviceToHighlight);
        static InputError getComponentStateForBinding(const char* renderModelName, const char* componentName, const InputBindingInfo* bindings, uint32_t bindingInfoSize, uint32_t bindingsCount, RenderModelComponentState* componentState);

        static bool isUsingLegacyInput();

        static InputError openBindingUI(const char* appKey, uint64_t actionSet, uint64_t device, bool showOnDesktop);

        static InputError getBindingVariant(uint64_t device, char* variant, uint32_t bufferSize);

        void* setActionManifestPath_ = (void*) setActionManifestPath;
        void* getActionSetHandle_ = (void*) getActionSetHandle;
        void* getActionHandle_ = (void*) getActionHandle;
        void* getInputSourceHandle_ = (void*) getInputSourceHandle;
        void* updateActionState_ = (void*) updateActionState;
        void* getDigitalActionData_ = (void*) getDigitalActionData;
        void* getAnalogActionData_ = (void*) getAnalogActionData;
        void* getPoseActionDataRelativeToNow_ = (void*) getPoseActionDataRelativeToNow;
        void* getPoseActionDataForNextFrame_ = (void*) getPoseActionDataForNextFrame;
        void* getSkeletalActionData_ = (void*) getSkeletalActionData;
        void* getDominantHand_ = (void*) getDominantHand;
        void* setDominantHand_ = (void*) setDominantHand;
        void* getBoneCount_ = (void*) getBoneCount;
        void* getBoneHierarchy_ = (void*) getBoneHierarchy;
        void* getBoneName_ = (void*) getBoneName;
        void* getSkeletalReferenceTransforms_ = (void*) getSkeletalReferenceTransforms;
        void* getSkeletalTrackingLevel_ = (void*) getSkeletalTrackingLevel;
        void* getSkeletalBoneData_ = (void*) getSkeletalBoneData;
        void* getSkeletalSummaryData_ = (void*) getSkeletalSummaryData;
        void* getSkeletalBoneDataCompressed_ = (void*) getSkeletalBoneDataCompressed;
        void* decompressSkeletalBoneData_ = (void*) decompressSkeletalBoneData;
        void* triggerHapticVibrationAction_ = (void*) triggerHapticVibrationAction;
        void* getActionOrigins_ = (void*) getActionOrigins;
        void* getOriginLocalizedName_ = (void*) getOriginLocalizedName;
        void* getOriginTrackedDeviceInfo_ = (void*) getOriginTrackedDeviceInfo;
        void* getActionBindingInfo_ = (void*) getActionBindingInfo;
        void* showActionOrigins_ = (void*) showActionOrigins;
        void* showBindingsForActionSet_ = (void*) showBindingsForActionSet;
        void* getComponentStateForBinding_ = (void*) getComponentStateForBinding;
        void* isUsingLegacyInput_ = (void*) isUsingLegacyInput;
        void* openBindingUI_ = (void*) openBindingUI;
        void* getBindingVariant_ = (void*) getBindingVariant;
    };

    class Input_010_v
    {
        public:
            virtual InputError setActionManifestPath(const char* path) { return Input_010::setActionManifestPath(path); }
            virtual InputError getActionSetHandle(const char* actionSetName, uint64_t* handle) { return Input_010::getActionSetHandle(actionSetName, handle); }
            virtual InputError getActionHandle(const char* actionName, uint64_t* handle) { return Input_010::getActionHandle(actionName, handle); }
            virtual InputError getInputSourceHandle(const char* inputSourcePath, uint64_t* handle) { return Input_010::getInputSourceHandle(inputSourcePath, handle); }
            virtual InputError updateActionState(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount) { return Input_010::updateActionState(actionSets, actionSetSize, actionSetsCount); }
            virtual InputError getDigitalActionData(uint64_t action, InputDigitalActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice) { return Input_010::getDigitalActionData(action, actionData, actionDataSize, restrictToDevice); }
            virtual InputError getAnalogActionData(uint64_t action, InputAnalogActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice) { return Input_010::getAnalogActionData(action, actionData, actionDataSize, restrictToDevice); }
            virtual InputError getPoseActionDataRelativeToNow(uint64_t action, TrackingUniverseOrigin origin, float secondsFromNow, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice) { return Input_010::getPoseActionDataRelativeToNow(action, origin, secondsFromNow, actionData, actionDataSize, restrictToDevice); }
            virtual InputError getPoseActionDataForNextFrame(uint64_t action, TrackingUniverseOrigin origin, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice) { return Input_010::getPoseActionDataForNextFrame(action, origin, actionData, actionDataSize, restrictToDevice); }
            virtual InputError getSkeletalActionData(uint64_t action, InputSkeletalActionData* actionData, uint32_t actionDataSize) { return Input_010::getSkeletalActionData(action, actionData, actionDataSize); }
            virtual InputError getDominantHand(TrackedControllerRole* dominantHand) { return Input_010::getDominantHand(dominantHand); }
            virtual InputError setDominantHand(TrackedControllerRole dominantHand) { return Input_010::setDominantHand(dominantHand); }
            virtual InputError getBoneCount(uint64_t action, uint32_t* boneCount) { return Input_010::getBoneCount(action, boneCount); }
            virtual InputError getBoneHierarchy(uint64_t action, int32_t* parentIndexes, uint32_t parentsCount) { return Input_010::getBoneHierarchy(action, parentIndexes, parentsCount); }
            virtual InputError getBoneName(uint64_t action, int32_t boneIndex, char* name, uint32_t bufferSize) { return Input_010::getBoneName(action, boneIndex, name, bufferSize); }
            virtual InputError getSkeletalReferenceTransforms(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalReferencePose referencePose, BoneTransform* transforms, uint32_t transformsCount) { return Input_010::getSkeletalReferenceTransforms(action, transformSpace, referencePose, transforms, transformsCount); }
            virtual InputError getSkeletalTrackingLevel(uint64_t action, SkeletalTrackingLevel* skeletalTrackingLevel) { return Input_010::getSkeletalTrackingLevel(action, skeletalTrackingLevel); }
            virtual InputError getSkeletalBoneData(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalMotionRange motionRange, BoneTransform* transforms, uint32_t transformsCount) { return Input_010::getSkeletalBoneData(action, transformSpace, motionRange, transforms, transformsCount); }
            virtual InputError getSkeletalSummaryData(uint64_t action, SkeletalSummaryType summaryType, SkeletalSummaryData* data) { return Input_010::getSkeletalSummaryData(action, summaryType, data); }
            virtual InputError getSkeletalBoneDataCompressed(uint64_t action, SkeletalMotionRange motionRange, void* data, uint32_t bufferSize, uint32_t* requiredBufferSize) { return Input_010::getSkeletalBoneDataCompressed(action, motionRange, data, bufferSize, requiredBufferSize); }
            virtual InputError decompressSkeletalBoneData(const void* data, uint32_t size, SkeletalTransformSpace transformSpace, BoneTransform* transforms, uint32_t transformsCount) { return Input_010::decompressSkeletalBoneData(data, size, transformSpace, transforms, transformsCount); }
            virtual InputError triggerHapticVibrationAction(uint64_t action, float startSecondsFromNow, float durationSeconds, float frequency, float amplitude, uint64_t restrictToDevice) { return Input_010::triggerHapticVibrationAction(action, startSecondsFromNow, durationSeconds, frequency, amplitude, restrictToDevice); }
            virtual InputError getActionOrigins(uint64_t actionSet, uint64_t action, uint64_t* originDevices, uint32_t originDevicesCount) { return Input_010::getActionOrigins(actionSet, action, originDevices, originDevicesCount); }
            virtual InputError getOriginLocalizedName(uint64_t originDevice, char* name, uint32_t bufferSize, int32_t stringSectionsToInclude) { return Input_010::getOriginLocalizedName(originDevice, name, bufferSize, stringSectionsToInclude); }
            virtual InputError getOriginTrackedDeviceInfo(uint64_t originDevice, InputOriginInfo* info, uint32_t infoBufferSize) { return Input_010::getOriginTrackedDeviceInfo(originDevice, info, infoBufferSize); }
            virtual InputError getActionBindingInfo(uint64_t action, InputBindingInfo* bindings, uint32_t bindingInfoSize, uint32_t bindingsBufferCount, uint32_t* returnedBindingsCount) { return Input_010::getActionBindingInfo(action, bindings, bindingInfoSize, bindingsBufferCount, returnedBindingsCount); }
            virtual InputError showActionOrigins(uint64_t actionSet, uint64_t action) { return Input_010::showActionOrigins(actionSet, action); }
            virtual InputError showBindingsForActionSet(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount, uint64_t originDeviceToHighlight) { return Input_010::showBindingsForActionSet(actionSets, actionSetSize, actionSetsCount, originDeviceToHighlight); }
            virtual InputError getComponentStateForBinding(const char* renderModelName, const char* componentName, const InputBindingInfo* bindings, uint32_t bindingInfoSize, uint32_t bindingsCount, RenderModelComponentState* componentState) { return Input_010::getComponentStateForBinding(renderModelName, componentName, bindings, bindingInfoSize, bindingsCount, componentState); }
            virtual bool isUsingLegacyInput() { return Input_010::isUsingLegacyInput(); }
            virtual InputError openBindingUI(const char* appKey, uint64_t actionSet, uint64_t device, bool showOnDesktop) { return Input_010::openBindingUI(appKey, actionSet, device, showOnDesktop); }
            virtual InputError getBindingVariant(uint64_t device, char* variant, uint32_t bufferSize) { return Input_010::getBindingVariant(device, variant, bufferSize); }
    };
}
