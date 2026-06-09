#pragma once

#include <string>

#include "backend/pose_set.h"
#include "openvr/types.h"

namespace vapor
{
    namespace windows
    {
        class Backend;

        class Transform
        {
            public:
                virtual void update(const Backend& backend);
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
            // TODO
        };

        class OverlayRelativeTransform: public Transform
        {
            // TODO
        };

        // TODO: cursor transform

        // TODO: projection transform
    }
}
