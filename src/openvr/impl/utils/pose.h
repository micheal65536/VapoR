#pragma once

#include "openvr/types.h"
#include "backend/pose_set.h"

#include "utils/matrix.h"
#include <cstring>

namespace openvr
{
    namespace utils
    {
        inline void makeTrackedDevicePose(TrackedDevicePose* trackedDevicePose, const XrPosef& xrPose)
        {
            *trackedDevicePose = {
                .velocity = {0.0f, 0.0f, 0.0f},
                .angularVelocity = {0.0f, 0.0f, 0.0f},
                .trackingResult = TrackedDevicePose::TrackingResult::TRACKING_RUNNING_OK,
                .poseIsValid = true,
                .deviceIsConnected = true
            };
            ::utils::poseToMatrix(xrPose, &trackedDevicePose->deviceToAbsolute.m);
        }

        inline void makeTrackedDevicePose(TrackedDevicePose* trackedDevicePose, const OpenXR::PoseAndVelocity& pose)
        {
            // CHECK: compare poses with SteamVR for headset and controllers, make sure that they're sane (same co-ordinate system, orientation, etc.)
            // CHECK: test that sign of velocity is the same between OpenXR and OpenVR
            *trackedDevicePose = {
                .velocity = pose.linearVelocityValid ? (Vector3) {pose.linearVelocity.x, pose.linearVelocity.y, pose.linearVelocity.z} : (Vector3) {0.0f, 0.0f, 0.0f},
                .angularVelocity = pose.angularVelocityValid ? (Vector3) {pose.angularVelocity.x, pose.angularVelocity.y, pose.angularVelocity.z} : (Vector3) {0.0f, 0.0f, 0.0f},
                .trackingResult = TrackedDevicePose::TrackingResult::TRACKING_RUNNING_OK,
                .poseIsValid = pose.poseValid,
                .deviceIsConnected = true
            };
            ::utils::poseToMatrix(pose.pose, &trackedDevicePose->deviceToAbsolute.m);
        }

        inline void applyOffset(TrackedDevicePose* trackedDevicePose, const float (&offsetMatrix)[3][4])
        {
            static const float identityOffset[3][4] = {{1.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f, 0.0f}};
            if (std::memcmp(offsetMatrix, identityOffset, sizeof(identityOffset)) == 0)
            {
                return;
            }
            ::utils::multiplyMatrix(offsetMatrix, trackedDevicePose->deviceToAbsolute.m);
            ::utils::multiplyMatrixVector(offsetMatrix, trackedDevicePose->velocity.v, 0.0f);
            ::utils::multiplyMatrixVector(offsetMatrix, trackedDevicePose->angularVelocity.v, 0.0f);
        }

        inline void selectTrackedDevicePose(const vapor::PoseSet& poseSet, TrackingUniverseOrigin origin, bool nextFrame, TrackedDevicePose* trackedDevicePoseOut)
        {
            const OpenXR::PoseAndVelocity* pose;
            if (nextFrame)
            {
                pose = origin == TrackingUniverseOrigin::ORIGIN_SEATED ? &poseSet.localNextFrame : &poseSet.localFloorNextFrame;
            }
            else
            {
                pose = origin == TrackingUniverseOrigin::ORIGIN_SEATED ? &poseSet.local : &poseSet.localFloor;
            }
            makeTrackedDevicePose(trackedDevicePoseOut, *pose);
            applyOffset(trackedDevicePoseOut, poseSet.offsetMatrix);
        }
    }
}
