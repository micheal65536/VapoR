#pragma once

#include "../../types.h"

#include "backend/pose_set.h"

#include "matrix.h"

#include <cstring>

namespace openvr
{
    namespace utils
    {
        inline void poseToMatrix(const XrPosef& pose, Matrix34* matrix)
        {
            XrVector3f position = pose.position;
            XrQuaternionf orientation = pose.orientation;

	        float w = orientation.w;
	        float x = orientation.x;
	        float y = orientation.y;
	        float z = orientation.z;

	        float x2 = x + x;
	        float y2 = y + y;
	        float z2 = z + z;

	        float xx2 = x * x2;
	        float yy2 = y * y2;
	        float zz2 = z * z2;

	        float yz2 = y * z2;
	        float wx2 = w * x2;
	        float xy2 = x * y2;
	        float wz2 = w * z2;
	        float xz2 = x * z2;
	        float wy2 = w * y2;

            float (*m)[4] = matrix->m;
            m[0][0] = 1.0f - yy2 - zz2; m[0][1] = xy2 - wz2;        m[0][2] = xz2 + wy2;        m[0][3] = position.x;
            m[1][0] = xy2 + wz2;        m[1][1] = 1.0f - xx2 - zz2; m[1][2] = yz2 - wx2;        m[1][3] = position.y;
            m[2][0] = xz2 - wy2;        m[2][1] = yz2 + wx2;        m[2][2] = 1.0f - xx2 - yy2; m[2][3] = position.z;
        }

        inline void makeTrackedDevicePose(TrackedDevicePose* trackedDevicePose, const XrPosef& xrPose)
        {
            *trackedDevicePose = {
                .velocity = {0.0f, 0.0f, 0.0f},
                .angularVelocity = {0.0f, 0.0f, 0.0f},
                .trackingResult = TrackedDevicePose::TrackingResult::TRACKING_RUNNING_OK,
                .poseIsValid = true,
                .deviceIsConnected = true
            };
            poseToMatrix(xrPose, &trackedDevicePose->deviceToAbsolute);
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
            poseToMatrix(pose.pose, &trackedDevicePose->deviceToAbsolute);
        }

        inline void applyOffset(TrackedDevicePose* trackedDevicePose, const float (&offsetMatrix)[3][4])
        {
            static const float identityOffset[3][4] = {{1.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f, 0.0f}};
            if (std::memcmp(offsetMatrix, identityOffset, sizeof(identityOffset)) == 0)
            {
                return;
            }
            multiplyMatrix(offsetMatrix, trackedDevicePose->deviceToAbsolute.m);
            multiplyMatrixVector(offsetMatrix, trackedDevicePose->velocity.v, 0.0f);
            multiplyMatrixVector(offsetMatrix, trackedDevicePose->angularVelocity.v, 0.0f);
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
