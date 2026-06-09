#pragma once

#include <string>

#include "backend/pose_set.h"
#include "openvr/types.h"

namespace vapor
{
    class Backend;

    namespace windows
    {
        class Transform
        {
            public:
                virtual void update(const Backend& backend);
                virtual bool shouldDisplay() { return true; };
                virtual const float (&getOverlayToWorldTransformMatrix())[3][4] = 0;
                virtual void getHeadPoseToUse(const PoseSet& headPoseSet, float (*pose)[3][4]);
                virtual openvr::OverlayTransformType getTransformType() const { return openvr::OverlayTransformType::OVERLAY_TRANSFORM_TYPE_INVALID; };
        };

        class AbsoluteTransform: public Transform
        {
            public:
                AbsoluteTransform(openvr::TrackingUniverseOrigin trackingUniverse, const openvr::Matrix34& offset);
                virtual const float (&getOverlayToWorldTransformMatrix())[3][4];
                virtual void getHeadPoseToUse(const PoseSet& headPoseSet, float (*pose)[3][4]);
                virtual openvr::OverlayTransformType getTransformType() const { return openvr::OverlayTransformType::OVERLAY_TRANSFORM_TYPE_ABSOLUTE; };

                const openvr::TrackingUniverseOrigin trackingUniverse;
                const openvr::Matrix34 offset;
        };

        class TrackedDeviceRelativeTransform: public Transform
        {
            public:
                TrackedDeviceRelativeTransform(uint32_t deviceIndex, const openvr::Matrix34& offset);
                virtual void update(const Backend& backend);
                virtual bool shouldDisplay() { return haveMatrix; };
                virtual const float (&getOverlayToWorldTransformMatrix())[3][4] { return matrix; };
                virtual void getHeadPoseToUse(const PoseSet& headPoseSet, float (*pose)[3][4]);
                virtual openvr::OverlayTransformType getTransformType() const { return openvr::OverlayTransformType::OVERLAY_TRANSFORM_TYPE_TRACKED_DEVICE_RELATIVE; };

                const uint32_t deviceIndex;
                const openvr::Matrix34 offset;

            private:
                bool haveMatrix = false;
                float matrix[3][4];
        };

        class OverlayRelativeTransform: public Transform
        {
            // TODO
        };

        // TODO: cursor transform

        // TODO: projection transform
    }
}
