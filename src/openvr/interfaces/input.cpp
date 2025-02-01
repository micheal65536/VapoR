#include "input.h"
#include "../impl/init.h"
#include "log/stub.h"

using namespace openvr;

InputError Input_003::setActionManifestPath(const char* path)
{
    return openvr::inputImpl->setActionManifestPath(path);
}

InputError Input_004::setActionManifestPath(const char* path)
{
    return openvr::inputImpl->setActionManifestPath(path);
}

InputError Input_005::setActionManifestPath(const char* path)
{
    return openvr::inputImpl->setActionManifestPath(path);
}

InputError Input_006::setActionManifestPath(const char* path)
{
    return openvr::inputImpl->setActionManifestPath(path);
}

InputError Input_007::setActionManifestPath(const char* path)
{
    return openvr::inputImpl->setActionManifestPath(path);
}

InputError Input_010::setActionManifestPath(const char* path)
{
    return openvr::inputImpl->setActionManifestPath(path);
}

InputError Input_003::getActionSetHandle(const char* actionSetName, uint64_t* handle)
{
    return openvr::inputImpl->getActionSetHandle(actionSetName, handle);
}

InputError Input_004::getActionSetHandle(const char* actionSetName, uint64_t* handle)
{
    return openvr::inputImpl->getActionSetHandle(actionSetName, handle);
}

InputError Input_005::getActionSetHandle(const char* actionSetName, uint64_t* handle)
{
    return openvr::inputImpl->getActionSetHandle(actionSetName, handle);
}

InputError Input_006::getActionSetHandle(const char* actionSetName, uint64_t* handle)
{
    return openvr::inputImpl->getActionSetHandle(actionSetName, handle);
}

InputError Input_007::getActionSetHandle(const char* actionSetName, uint64_t* handle)
{
    return openvr::inputImpl->getActionSetHandle(actionSetName, handle);
}

InputError Input_010::getActionSetHandle(const char* actionSetName, uint64_t* handle)
{
    return openvr::inputImpl->getActionSetHandle(actionSetName, handle);
}

InputError Input_003::getActionHandle(const char* actionName, uint64_t* handle)
{
    return openvr::inputImpl->getActionHandle(actionName, handle);
}

InputError Input_004::getActionHandle(const char* actionName, uint64_t* handle)
{
    return openvr::inputImpl->getActionHandle(actionName, handle);
}

InputError Input_005::getActionHandle(const char* actionName, uint64_t* handle)
{
    return openvr::inputImpl->getActionHandle(actionName, handle);
}

InputError Input_006::getActionHandle(const char* actionName, uint64_t* handle)
{
    return openvr::inputImpl->getActionHandle(actionName, handle);
}

InputError Input_007::getActionHandle(const char* actionName, uint64_t* handle)
{
    return openvr::inputImpl->getActionHandle(actionName, handle);
}

InputError Input_010::getActionHandle(const char* actionName, uint64_t* handle)
{
    return openvr::inputImpl->getActionHandle(actionName, handle);
}

InputError Input_003::getInputSourceHandle(const char* inputSourcePath, uint64_t* handle)
{
    return openvr::inputImpl->getInputSourceHandle(inputSourcePath, handle);
}

InputError Input_004::getInputSourceHandle(const char* inputSourcePath, uint64_t* handle)
{
    return openvr::inputImpl->getInputSourceHandle(inputSourcePath, handle);
}

InputError Input_005::getInputSourceHandle(const char* inputSourcePath, uint64_t* handle)
{
    return openvr::inputImpl->getInputSourceHandle(inputSourcePath, handle);
}

InputError Input_006::getInputSourceHandle(const char* inputSourcePath, uint64_t* handle)
{
    return openvr::inputImpl->getInputSourceHandle(inputSourcePath, handle);
}

InputError Input_007::getInputSourceHandle(const char* inputSourcePath, uint64_t* handle)
{
    return openvr::inputImpl->getInputSourceHandle(inputSourcePath, handle);
}

InputError Input_010::getInputSourceHandle(const char* inputSourcePath, uint64_t* handle)
{
    return openvr::inputImpl->getInputSourceHandle(inputSourcePath, handle);
}

InputError Input_003::updateActionState(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount)
{
    return openvr::inputImpl->updateActionState(actionSets, actionSetSize, actionSetsCount);
}

InputError Input_004::updateActionState(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount)
{
    return openvr::inputImpl->updateActionState(actionSets, actionSetSize, actionSetsCount);
}

InputError Input_005::updateActionState(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount)
{
    return openvr::inputImpl->updateActionState(actionSets, actionSetSize, actionSetsCount);
}

InputError Input_006::updateActionState(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount)
{
    return openvr::inputImpl->updateActionState(actionSets, actionSetSize, actionSetsCount);
}

InputError Input_007::updateActionState(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount)
{
    return openvr::inputImpl->updateActionState(actionSets, actionSetSize, actionSetsCount);
}

InputError Input_010::updateActionState(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount)
{
    return openvr::inputImpl->updateActionState(actionSets, actionSetSize, actionSetsCount);
}

InputError Input_003::getDigitalActionData(uint64_t action, InputDigitalActionData* actionData, uint32_t actionDataSize)
{
    return openvr::inputImpl->getDigitalActionData(action, actionData, actionDataSize, 0);
}

InputError Input_004::getDigitalActionData(uint64_t action, InputDigitalActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    return openvr::inputImpl->getDigitalActionData(action, actionData, actionDataSize, restrictToDevice);
}

InputError Input_005::getDigitalActionData(uint64_t action, InputDigitalActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    return openvr::inputImpl->getDigitalActionData(action, actionData, actionDataSize, restrictToDevice);
}

InputError Input_006::getDigitalActionData(uint64_t action, InputDigitalActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    return openvr::inputImpl->getDigitalActionData(action, actionData, actionDataSize, restrictToDevice);
}

InputError Input_007::getDigitalActionData(uint64_t action, InputDigitalActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    return openvr::inputImpl->getDigitalActionData(action, actionData, actionDataSize, restrictToDevice);
}

InputError Input_010::getDigitalActionData(uint64_t action, InputDigitalActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    return openvr::inputImpl->getDigitalActionData(action, actionData, actionDataSize, restrictToDevice);
}

InputError Input_003::getAnalogActionData(uint64_t action, InputAnalogActionData* actionData, uint32_t actionDataSize)
{
    return openvr::inputImpl->getAnalogActionData(action, actionData, actionDataSize, 0);
}

InputError Input_004::getAnalogActionData(uint64_t action, InputAnalogActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    return openvr::inputImpl->getAnalogActionData(action, actionData, actionDataSize, restrictToDevice);
}

InputError Input_005::getAnalogActionData(uint64_t action, InputAnalogActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    return openvr::inputImpl->getAnalogActionData(action, actionData, actionDataSize, restrictToDevice);
}

InputError Input_006::getAnalogActionData(uint64_t action, InputAnalogActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    return openvr::inputImpl->getAnalogActionData(action, actionData, actionDataSize, restrictToDevice);
}

InputError Input_007::getAnalogActionData(uint64_t action, InputAnalogActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    return openvr::inputImpl->getAnalogActionData(action, actionData, actionDataSize, restrictToDevice);
}

InputError Input_010::getAnalogActionData(uint64_t action, InputAnalogActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    return openvr::inputImpl->getAnalogActionData(action, actionData, actionDataSize, restrictToDevice);
}

InputError Input_003::getPoseActionData(uint64_t action, TrackingUniverseOrigin origin, float secondsFromNow, InputPoseActionData* actionData, uint32_t actionDataSize)
{
    return openvr::inputImpl->getPoseActionDataRelativeToNow(action, origin, secondsFromNow, actionData, actionDataSize, 0);
}

InputError Input_004::getPoseActionData(uint64_t action, TrackingUniverseOrigin origin, float secondsFromNow, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    return openvr::inputImpl->getPoseActionDataRelativeToNow(action, origin, secondsFromNow, actionData, actionDataSize, restrictToDevice);
}

InputError Input_005::getPoseActionData(uint64_t action, TrackingUniverseOrigin origin, float secondsFromNow, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    return openvr::inputImpl->getPoseActionDataRelativeToNow(action, origin, secondsFromNow, actionData, actionDataSize, restrictToDevice);
}

InputError Input_006::getPoseActionDataRelativeToNow(uint64_t action, TrackingUniverseOrigin origin, float secondsFromNow, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    return openvr::inputImpl->getPoseActionDataRelativeToNow(action, origin, secondsFromNow, actionData, actionDataSize, restrictToDevice);
}

InputError Input_007::getPoseActionDataRelativeToNow(uint64_t action, TrackingUniverseOrigin origin, float secondsFromNow, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    return openvr::inputImpl->getPoseActionDataRelativeToNow(action, origin, secondsFromNow, actionData, actionDataSize, restrictToDevice);
}

InputError Input_010::getPoseActionDataRelativeToNow(uint64_t action, TrackingUniverseOrigin origin, float secondsFromNow, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    return openvr::inputImpl->getPoseActionDataRelativeToNow(action, origin, secondsFromNow, actionData, actionDataSize, restrictToDevice);
}

InputError Input_006::getPoseActionDataForNextFrame(uint64_t action, TrackingUniverseOrigin origin, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    return openvr::inputImpl->getPoseActionDataForNextFrame(action, origin, actionData, actionDataSize, restrictToDevice);
}

InputError Input_007::getPoseActionDataForNextFrame(uint64_t action, TrackingUniverseOrigin origin, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    return openvr::inputImpl->getPoseActionDataForNextFrame(action, origin, actionData, actionDataSize, restrictToDevice);
}

InputError Input_010::getPoseActionDataForNextFrame(uint64_t action, TrackingUniverseOrigin origin, InputPoseActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    return openvr::inputImpl->getPoseActionDataForNextFrame(action, origin, actionData, actionDataSize, restrictToDevice);
}

InputError Input_003::getSkeletalActionData(uint64_t action, SkeletalTransformSpace transformSpace, float secondsFromNow, InputSkeletalActionData* actionData, uint32_t actionDataSize, BoneTransform* transforms, uint32_t transformsCount)
{
    // TODO
    STUB();
}

InputError Input_004::getSkeletalActionData(uint64_t action, InputSkeletalActionData* actionData, uint32_t actionDataSize, uint64_t restrictToDevice)
{
    return openvr::inputImpl->getSkeletalActionData(action, actionData, actionDataSize);
}

InputError Input_005::getSkeletalActionData(uint64_t action, InputSkeletalActionData* actionData, uint32_t actionDataSize)
{
    return openvr::inputImpl->getSkeletalActionData(action, actionData, actionDataSize);
}

InputError Input_006::getSkeletalActionData(uint64_t action, InputSkeletalActionData* actionData, uint32_t actionDataSize)
{
    return openvr::inputImpl->getSkeletalActionData(action, actionData, actionDataSize);
}

InputError Input_007::getSkeletalActionData(uint64_t action, InputSkeletalActionData* actionData, uint32_t actionDataSize)
{
    return openvr::inputImpl->getSkeletalActionData(action, actionData, actionDataSize);
}

InputError Input_010::getSkeletalActionData(uint64_t action, InputSkeletalActionData* actionData, uint32_t actionDataSize)
{
    return openvr::inputImpl->getSkeletalActionData(action, actionData, actionDataSize);
}

InputError Input_003::getSkeletalActionDataCompressed(uint64_t action, SkeletalTransformSpace transformSpace, float secondsFromNow, void* data, uint32_t bufferSize, uint32_t* requiredBufferSize)
{
    // TODO
    STUB();
}

InputError Input_010::getDominantHand(TrackedControllerRole* dominantHand)
{
    return openvr::inputImpl->getDominantHand(dominantHand);
}

InputError Input_010::setDominantHand(TrackedControllerRole dominantHand)
{
    return openvr::inputImpl->setDominantHand(dominantHand);
}

InputError Input_005::getBoneCount(uint64_t action, uint32_t* boneCount)
{
    return openvr::inputImpl->getBoneCount(action, boneCount);
}

InputError Input_006::getBoneCount(uint64_t action, uint32_t* boneCount)
{
    return openvr::inputImpl->getBoneCount(action, boneCount);
}

InputError Input_007::getBoneCount(uint64_t action, uint32_t* boneCount)
{
    return openvr::inputImpl->getBoneCount(action, boneCount);
}

InputError Input_010::getBoneCount(uint64_t action, uint32_t* boneCount)
{
    return openvr::inputImpl->getBoneCount(action, boneCount);
}

InputError Input_005::getBoneHierarchy(uint64_t action, int32_t* parentIndexes, uint32_t parentsCount)
{
    return openvr::inputImpl->getBoneHierarchy(action, parentIndexes, parentsCount);
}

InputError Input_006::getBoneHierarchy(uint64_t action, int32_t* parentIndexes, uint32_t parentsCount)
{
    return openvr::inputImpl->getBoneHierarchy(action, parentIndexes, parentsCount);
}

InputError Input_007::getBoneHierarchy(uint64_t action, int32_t* parentIndexes, uint32_t parentsCount)
{
    return openvr::inputImpl->getBoneHierarchy(action, parentIndexes, parentsCount);
}

InputError Input_010::getBoneHierarchy(uint64_t action, int32_t* parentIndexes, uint32_t parentsCount)
{
    return openvr::inputImpl->getBoneHierarchy(action, parentIndexes, parentsCount);
}

InputError Input_005::getBoneName(uint64_t action, int32_t boneIndex, char* name, uint32_t bufferSize)
{
    return openvr::inputImpl->getBoneName(action, boneIndex, name, bufferSize);
}

InputError Input_006::getBoneName(uint64_t action, int32_t boneIndex, char* name, uint32_t bufferSize)
{
    return openvr::inputImpl->getBoneName(action, boneIndex, name, bufferSize);
}

InputError Input_007::getBoneName(uint64_t action, int32_t boneIndex, char* name, uint32_t bufferSize)
{
    return openvr::inputImpl->getBoneName(action, boneIndex, name, bufferSize);
}

InputError Input_010::getBoneName(uint64_t action, int32_t boneIndex, char* name, uint32_t bufferSize)
{
    return openvr::inputImpl->getBoneName(action, boneIndex, name, bufferSize);
}

InputError Input_005::getSkeletalReferenceTransforms(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalReferencePose referencePose, BoneTransform* transforms, uint32_t transformsCount)
{
    return openvr::inputImpl->getSkeletalReferenceTransforms(action, transformSpace, referencePose, transforms, transformsCount);
}

InputError Input_006::getSkeletalReferenceTransforms(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalReferencePose referencePose, BoneTransform* transforms, uint32_t transformsCount)
{
    return openvr::inputImpl->getSkeletalReferenceTransforms(action, transformSpace, referencePose, transforms, transformsCount);
}

InputError Input_007::getSkeletalReferenceTransforms(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalReferencePose referencePose, BoneTransform* transforms, uint32_t transformsCount)
{
    return openvr::inputImpl->getSkeletalReferenceTransforms(action, transformSpace, referencePose, transforms, transformsCount);
}

InputError Input_010::getSkeletalReferenceTransforms(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalReferencePose referencePose, BoneTransform* transforms, uint32_t transformsCount)
{
    return openvr::inputImpl->getSkeletalReferenceTransforms(action, transformSpace, referencePose, transforms, transformsCount);
}

InputError Input_005::getSkeletalTrackingLevel(uint64_t action, SkeletalTrackingLevel* skeletalTrackingLevel)
{
    return openvr::inputImpl->getSkeletalTrackingLevel(action, skeletalTrackingLevel);
}

InputError Input_006::getSkeletalTrackingLevel(uint64_t action, SkeletalTrackingLevel* skeletalTrackingLevel)
{
    return openvr::inputImpl->getSkeletalTrackingLevel(action, skeletalTrackingLevel);
}

InputError Input_007::getSkeletalTrackingLevel(uint64_t action, SkeletalTrackingLevel* skeletalTrackingLevel)
{
    return openvr::inputImpl->getSkeletalTrackingLevel(action, skeletalTrackingLevel);
}

InputError Input_010::getSkeletalTrackingLevel(uint64_t action, SkeletalTrackingLevel* skeletalTrackingLevel)
{
    return openvr::inputImpl->getSkeletalTrackingLevel(action, skeletalTrackingLevel);
}

InputError Input_004::getSkeletalBoneData(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalMotionRange motionRange, BoneTransform* transforms, uint32_t transformsCount, uint64_t restrictToDevice)
{
    return openvr::inputImpl->getSkeletalBoneData(action, transformSpace, motionRange, transforms, transformsCount);
}

InputError Input_005::getSkeletalBoneData(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalMotionRange motionRange, BoneTransform* transforms, uint32_t transformsCount)
{
    return openvr::inputImpl->getSkeletalBoneData(action, transformSpace, motionRange, transforms, transformsCount);
}

InputError Input_006::getSkeletalBoneData(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalMotionRange motionRange, BoneTransform* transforms, uint32_t transformsCount)
{
    return openvr::inputImpl->getSkeletalBoneData(action, transformSpace, motionRange, transforms, transformsCount);
}

InputError Input_007::getSkeletalBoneData(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalMotionRange motionRange, BoneTransform* transforms, uint32_t transformsCount)
{
    return openvr::inputImpl->getSkeletalBoneData(action, transformSpace, motionRange, transforms, transformsCount);
}

InputError Input_010::getSkeletalBoneData(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalMotionRange motionRange, BoneTransform* transforms, uint32_t transformsCount)
{
    return openvr::inputImpl->getSkeletalBoneData(action, transformSpace, motionRange, transforms, transformsCount);
}

InputError Input_005::getSkeletalSummaryData(uint64_t action, SkeletalSummaryData* data)
{
    return openvr::inputImpl->getSkeletalSummaryData(action, SkeletalSummaryType::SKELETAL_SUMMARY_TIME_FROM_ANIMATION, data); // TODO: confirm what SkeletalSummaryType to use
}

InputError Input_006::getSkeletalSummaryData(uint64_t action, SkeletalSummaryType summaryType, SkeletalSummaryData* data)
{
    return openvr::inputImpl->getSkeletalSummaryData(action, summaryType, data);
}

InputError Input_007::getSkeletalSummaryData(uint64_t action, SkeletalSummaryType summaryType, SkeletalSummaryData* data)
{
    return openvr::inputImpl->getSkeletalSummaryData(action, summaryType, data);
}

InputError Input_010::getSkeletalSummaryData(uint64_t action, SkeletalSummaryType summaryType, SkeletalSummaryData* data)
{
    return openvr::inputImpl->getSkeletalSummaryData(action, summaryType, data);
}

InputError Input_004::getSkeletalBoneDataCompressed(uint64_t action, SkeletalTransformSpace transformSpace, SkeletalMotionRange motionRange, void* data, uint32_t bufferSize, uint32_t* requiredBufferSize, uint64_t restrictToDevice)
{
    // TODO
    STUB();
}

InputError Input_005::getSkeletalBoneDataCompressed(uint64_t action, SkeletalMotionRange motionRange, void* data, uint32_t bufferSize, uint32_t* requiredBufferSize)
{
    return openvr::inputImpl->getSkeletalBoneDataCompressed(action, motionRange, data, bufferSize, requiredBufferSize);
}

InputError Input_006::getSkeletalBoneDataCompressed(uint64_t action, SkeletalMotionRange motionRange, void* data, uint32_t bufferSize, uint32_t* requiredBufferSize)
{
    return openvr::inputImpl->getSkeletalBoneDataCompressed(action, motionRange, data, bufferSize, requiredBufferSize);
}

InputError Input_007::getSkeletalBoneDataCompressed(uint64_t action, SkeletalMotionRange motionRange, void* data, uint32_t bufferSize, uint32_t* requiredBufferSize)
{
    return openvr::inputImpl->getSkeletalBoneDataCompressed(action, motionRange, data, bufferSize, requiredBufferSize);
}

InputError Input_010::getSkeletalBoneDataCompressed(uint64_t action, SkeletalMotionRange motionRange, void* data, uint32_t bufferSize, uint32_t* requiredBufferSize)
{
    return openvr::inputImpl->getSkeletalBoneDataCompressed(action, motionRange, data, bufferSize, requiredBufferSize);
}

InputError Input_003::decompressSkeletalActionData(const void* data, uint32_t size, SkeletalTransformSpace transformSpace, BoneTransform* transforms, uint32_t transformsCount)
{
    // TODO
    STUB();
}

InputError Input_004::decompressSkeletalBoneData(const void* data, uint32_t size, SkeletalTransformSpace transformSpace, BoneTransform* transforms, uint32_t transformsCount)
{
    return openvr::inputImpl->decompressSkeletalBoneData(data, size, transformSpace, transforms, transformsCount);
}

InputError Input_005::decompressSkeletalBoneData(const void* data, uint32_t size, SkeletalTransformSpace transformSpace, BoneTransform* transforms, uint32_t transformsCount)
{
    return openvr::inputImpl->decompressSkeletalBoneData(data, size, transformSpace, transforms, transformsCount);
}

InputError Input_006::decompressSkeletalBoneData(const void* data, uint32_t size, SkeletalTransformSpace transformSpace, BoneTransform* transforms, uint32_t transformsCount)
{
    return openvr::inputImpl->decompressSkeletalBoneData(data, size, transformSpace, transforms, transformsCount);
}

InputError Input_007::decompressSkeletalBoneData(const void* data, uint32_t size, SkeletalTransformSpace transformSpace, BoneTransform* transforms, uint32_t transformsCount)
{
    return openvr::inputImpl->decompressSkeletalBoneData(data, size, transformSpace, transforms, transformsCount);
}

InputError Input_010::decompressSkeletalBoneData(const void* data, uint32_t size, SkeletalTransformSpace transformSpace, BoneTransform* transforms, uint32_t transformsCount)
{
    return openvr::inputImpl->decompressSkeletalBoneData(data, size, transformSpace, transforms, transformsCount);
}

InputError Input_003::triggerHapticVibrationAction(uint64_t action, float startSecondsFromNow, float durationSeconds, float frequency, float amplitude)
{
    return openvr::inputImpl->triggerHapticVibrationAction(action, startSecondsFromNow, durationSeconds, frequency, amplitude, 0);
}

InputError Input_004::triggerHapticVibrationAction(uint64_t action, float startSecondsFromNow, float durationSeconds, float frequency, float amplitude, uint64_t restrictToDevice)
{
    return openvr::inputImpl->triggerHapticVibrationAction(action, startSecondsFromNow, durationSeconds, frequency, amplitude, restrictToDevice);
}

InputError Input_005::triggerHapticVibrationAction(uint64_t action, float startSecondsFromNow, float durationSeconds, float frequency, float amplitude, uint64_t restrictToDevice)
{
    return openvr::inputImpl->triggerHapticVibrationAction(action, startSecondsFromNow, durationSeconds, frequency, amplitude, restrictToDevice);
}

InputError Input_006::triggerHapticVibrationAction(uint64_t action, float startSecondsFromNow, float durationSeconds, float frequency, float amplitude, uint64_t restrictToDevice)
{
    return openvr::inputImpl->triggerHapticVibrationAction(action, startSecondsFromNow, durationSeconds, frequency, amplitude, restrictToDevice);
}

InputError Input_007::triggerHapticVibrationAction(uint64_t action, float startSecondsFromNow, float durationSeconds, float frequency, float amplitude, uint64_t restrictToDevice)
{
    return openvr::inputImpl->triggerHapticVibrationAction(action, startSecondsFromNow, durationSeconds, frequency, amplitude, restrictToDevice);
}

InputError Input_010::triggerHapticVibrationAction(uint64_t action, float startSecondsFromNow, float durationSeconds, float frequency, float amplitude, uint64_t restrictToDevice)
{
    return openvr::inputImpl->triggerHapticVibrationAction(action, startSecondsFromNow, durationSeconds, frequency, amplitude, restrictToDevice);
}

InputError Input_003::getActionOrigins(uint64_t actionSet, uint64_t action, uint64_t* originDevices, uint32_t originDevicesCount)
{
    return openvr::inputImpl->getActionOrigins(actionSet, action, originDevices, originDevicesCount);
}

InputError Input_004::getActionOrigins(uint64_t actionSet, uint64_t action, uint64_t* originDevices, uint32_t originDevicesCount)
{
    return openvr::inputImpl->getActionOrigins(actionSet, action, originDevices, originDevicesCount);
}

InputError Input_005::getActionOrigins(uint64_t actionSet, uint64_t action, uint64_t* originDevices, uint32_t originDevicesCount)
{
    return openvr::inputImpl->getActionOrigins(actionSet, action, originDevices, originDevicesCount);
}

InputError Input_006::getActionOrigins(uint64_t actionSet, uint64_t action, uint64_t* originDevices, uint32_t originDevicesCount)
{
    return openvr::inputImpl->getActionOrigins(actionSet, action, originDevices, originDevicesCount);
}

InputError Input_007::getActionOrigins(uint64_t actionSet, uint64_t action, uint64_t* originDevices, uint32_t originDevicesCount)
{
    return openvr::inputImpl->getActionOrigins(actionSet, action, originDevices, originDevicesCount);
}

InputError Input_010::getActionOrigins(uint64_t actionSet, uint64_t action, uint64_t* originDevices, uint32_t originDevicesCount)
{
    return openvr::inputImpl->getActionOrigins(actionSet, action, originDevices, originDevicesCount);
}

InputError Input_003::getOriginLocalizedName(uint64_t originDevice, char* name, uint32_t bufferSize)
{
    return openvr::inputImpl->getOriginLocalizedName(originDevice, name, bufferSize, InputOriginStringSections::INPUT_ORIGIN_STRING_SECTIONS_ALL);
}

InputError Input_004::getOriginLocalizedName(uint64_t originDevice, char* name, uint32_t bufferSize)
{
    return openvr::inputImpl->getOriginLocalizedName(originDevice, name, bufferSize, InputOriginStringSections::INPUT_ORIGIN_STRING_SECTIONS_ALL);
}

InputError  Input_005::getOriginLocalizedName(uint64_t originDevice, char* name, uint32_t bufferSize, int32_t stringSectionsToInclude)
{
    return openvr::inputImpl->getOriginLocalizedName(originDevice, name, bufferSize, stringSectionsToInclude);
}

InputError Input_006::getOriginLocalizedName(uint64_t originDevice, char* name, uint32_t bufferSize, int32_t stringSectionsToInclude)
{
    return openvr::inputImpl->getOriginLocalizedName(originDevice, name, bufferSize, stringSectionsToInclude);
}

InputError Input_007::getOriginLocalizedName(uint64_t originDevice, char* name, uint32_t bufferSize, int32_t stringSectionsToInclude)
{
    return openvr::inputImpl->getOriginLocalizedName(originDevice, name, bufferSize, stringSectionsToInclude);
}

InputError Input_010::getOriginLocalizedName(uint64_t originDevice, char* name, uint32_t bufferSize, int32_t stringSectionsToInclude)
{
    return openvr::inputImpl->getOriginLocalizedName(originDevice, name, bufferSize, stringSectionsToInclude);
}

InputError Input_003::getOriginTrackedDeviceInfo(uint64_t originDevice, InputOriginInfo* info, uint32_t infoBufferSize)
{
    return openvr::inputImpl->getOriginTrackedDeviceInfo(originDevice, info, infoBufferSize);
}

InputError Input_004::getOriginTrackedDeviceInfo(uint64_t originDevice, InputOriginInfo* info, uint32_t infoBufferSize)
{
    return openvr::inputImpl->getOriginTrackedDeviceInfo(originDevice, info, infoBufferSize);
}

InputError Input_005::getOriginTrackedDeviceInfo(uint64_t originDevice, InputOriginInfo* info, uint32_t infoBufferSize)
{
    return openvr::inputImpl->getOriginTrackedDeviceInfo(originDevice, info, infoBufferSize);
}

InputError Input_006::getOriginTrackedDeviceInfo(uint64_t originDevice, InputOriginInfo* info, uint32_t infoBufferSize)
{
    return openvr::inputImpl->getOriginTrackedDeviceInfo(originDevice, info, infoBufferSize);
}

InputError Input_007::getOriginTrackedDeviceInfo(uint64_t originDevice, InputOriginInfo* info, uint32_t infoBufferSize)
{
    return openvr::inputImpl->getOriginTrackedDeviceInfo(originDevice, info, infoBufferSize);
}

InputError Input_010::getOriginTrackedDeviceInfo(uint64_t originDevice, InputOriginInfo* info, uint32_t infoBufferSize)
{
    return openvr::inputImpl->getOriginTrackedDeviceInfo(originDevice, info, infoBufferSize);
}

InputError Input_007::getActionBindingInfo(uint64_t action, InputBindingInfo* bindings, uint32_t bindingInfoSize, uint32_t bindingsBufferCount, uint32_t* returnedBindingsCount)
{
    return openvr::inputImpl->getActionBindingInfo(action, bindings, bindingInfoSize, bindingsBufferCount, returnedBindingsCount);
}

InputError Input_010::getActionBindingInfo(uint64_t action, InputBindingInfo* bindings, uint32_t bindingInfoSize, uint32_t bindingsBufferCount, uint32_t* returnedBindingsCount)
{
    return openvr::inputImpl->getActionBindingInfo(action, bindings, bindingInfoSize, bindingsBufferCount, returnedBindingsCount);
}

InputError Input_003::showActionOrigins(uint64_t actionSet, uint64_t action)
{
    return openvr::inputImpl->showActionOrigins(actionSet, action);
}

InputError Input_004::showActionOrigins(uint64_t actionSet, uint64_t action)
{
    return openvr::inputImpl->showActionOrigins(actionSet, action);
}

InputError Input_005::showActionOrigins(uint64_t actionSet, uint64_t action)
{
    return openvr::inputImpl->showActionOrigins(actionSet, action);
}

InputError Input_006::showActionOrigins(uint64_t actionSet, uint64_t action)
{
    return openvr::inputImpl->showActionOrigins(actionSet, action);
}

InputError Input_007::showActionOrigins(uint64_t actionSet, uint64_t action)
{
    return openvr::inputImpl->showActionOrigins(actionSet, action);
}

InputError Input_010::showActionOrigins(uint64_t actionSet, uint64_t action)
{
    return openvr::inputImpl->showActionOrigins(actionSet, action);
}

InputError Input_003::showBindingsForActionSet(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount, uint64_t originDeviceToHighlight)
{
    return openvr::inputImpl->showBindingsForActionSet(actionSets, actionSetSize, actionSetsCount, originDeviceToHighlight);
}

InputError Input_004::showBindingsForActionSet(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount, uint64_t originDeviceToHighlight)
{
    return openvr::inputImpl->showBindingsForActionSet(actionSets, actionSetSize, actionSetsCount, originDeviceToHighlight);
}

InputError Input_005::showBindingsForActionSet(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount, uint64_t originDeviceToHighlight)
{
    return openvr::inputImpl->showBindingsForActionSet(actionSets, actionSetSize, actionSetsCount, originDeviceToHighlight);
}

InputError Input_006::showBindingsForActionSet(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount, uint64_t originDeviceToHighlight)
{
    return openvr::inputImpl->showBindingsForActionSet(actionSets, actionSetSize, actionSetsCount, originDeviceToHighlight);
}

InputError Input_007::showBindingsForActionSet(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount, uint64_t originDeviceToHighlight)
{
    return openvr::inputImpl->showBindingsForActionSet(actionSets, actionSetSize, actionSetsCount, originDeviceToHighlight);
}

InputError Input_010::showBindingsForActionSet(ActiveActionSet* actionSets, uint32_t actionSetSize, uint32_t actionSetsCount, uint64_t originDeviceToHighlight)
{
    return openvr::inputImpl->showBindingsForActionSet(actionSets, actionSetSize, actionSetsCount, originDeviceToHighlight);
}

InputError Input_010::getComponentStateForBinding(const char* renderModelName, const char* componentName, const InputBindingInfo* bindings, uint32_t bindingInfoSize, uint32_t bindingsCount, RenderModelComponentState* componentState)
{
    return openvr::inputImpl->getComponentStateForBinding(renderModelName, componentName, bindings, bindingInfoSize, bindingsCount, componentState);
}

bool Input_005::isUsingLegacyInput()
{
    return openvr::inputImpl->isUsingLegacyInput();
}

bool Input_006::isUsingLegacyInput()
{
    return openvr::inputImpl->isUsingLegacyInput();
}

bool Input_007::isUsingLegacyInput()
{
    return openvr::inputImpl->isUsingLegacyInput();
}

bool Input_010::isUsingLegacyInput()
{
    return openvr::inputImpl->isUsingLegacyInput();
}

InputError Input_007::openBindingUI(const char* appKey, uint64_t actionSet, uint64_t device, bool showOnDesktop)
{
    return openvr::inputImpl->openBindingUI(appKey, actionSet, device, showOnDesktop);
}

InputError Input_010::openBindingUI(const char* appKey, uint64_t actionSet, uint64_t device, bool showOnDesktop)
{
    return openvr::inputImpl->openBindingUI(appKey, actionSet, device, showOnDesktop);
}

InputError Input_010::getBindingVariant(uint64_t device, char* variant, uint32_t bufferSize)
{
    return openvr::inputImpl->getBindingVariant(device, variant, bufferSize);
}
