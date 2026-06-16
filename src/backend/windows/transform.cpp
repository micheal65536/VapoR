#include "transform.h"

#include "backend/backend.h"
#include "utils/matrix.h"

using namespace vapor::windows;

inline void selectPoseFromPoseSet(const vapor::PoseSet& poseSet, openvr::TrackingUniverseOrigin trackingUniverse, float (*poseMatrixOut)[3][4])
{
    const OpenXR::PoseAndVelocity& pose = trackingUniverse == openvr::TrackingUniverseOrigin::ORIGIN_SEATED ? poseSet.local : poseSet.localFloor;
    utils::poseToMatrix(pose.pose, poseMatrixOut);
    utils::multiplyMatrix(poseSet.offsetMatrix, *poseMatrixOut);
}

//

void Transform::update(const Backend& backend)
{
    // empty
}

void Transform::getHeadPoseToUse(const PoseSet& headPoseSet, float (*pose)[3][4])
{
    selectPoseFromPoseSet(headPoseSet, openvr::TrackingUniverseOrigin::ORIGIN_STANDING, pose);
}

//

AbsoluteTransform::AbsoluteTransform(openvr::TrackingUniverseOrigin trackingUniverse, const openvr::Matrix34& offset): trackingUniverse(trackingUniverse), offset(offset)
{
    // empty
}

const float (&AbsoluteTransform::getOverlayToWorldTransformMatrix())[3][4]
{
    return this->offset.m;
}

void AbsoluteTransform::getHeadPoseToUse(const PoseSet& headPoseSet, float (*pose)[3][4])
{
    selectPoseFromPoseSet(headPoseSet, this->trackingUniverse, pose);
}

//

TrackedDeviceRelativeTransform::TrackedDeviceRelativeTransform(uint32_t deviceIndex, const openvr::Matrix34& offset): deviceIndex(deviceIndex), offset(offset)
{
    // empty
}

void TrackedDeviceRelativeTransform::update(const Backend& backend)
{
    const FrameState& frame = backend.frameStates.getFrame(0);
    if (deviceIndex >= 0 && deviceIndex <= 2)
    {
        const PoseSet& poseSet = deviceIndex == 0 ? frame.head : frame.controllerPoses[deviceIndex - 1];
        const OpenXR::PoseAndVelocity& pose = poseSet.localFloor;
        if (!pose.poseValid)
        {
            haveMatrix = false;
            return;
        }
        utils::poseToMatrix(pose.pose, &this->matrix);
        utils::multiplyMatrix(poseSet.offsetMatrix, this->matrix);
        utils::multiplyMatrix(this->offset.m, this->matrix);
        haveMatrix = true;
    }
    else
    {
        haveMatrix = false;
    }
}

void TrackedDeviceRelativeTransform::getHeadPoseToUse(const PoseSet& headPoseSet, float (*pose)[3][4])
{
    selectPoseFromPoseSet(headPoseSet, openvr::TrackingUniverseOrigin::ORIGIN_STANDING, pose);
}
