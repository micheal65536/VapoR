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
