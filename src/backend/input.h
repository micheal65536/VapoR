#pragma once

#include <string>

#include "openxr.h"

namespace vapor
{
    struct PoseSet
    {
        OpenXR::PoseAndVelocity local;
        OpenXR::PoseAndVelocity localFloor;
        OpenXR::PoseAndVelocity localNextFrame;
        OpenXR::PoseAndVelocity localFloorNextFrame;
    };

    enum InputType
    {
        // this contains a mix of types valid for OpenXR and OpenVR, but it's neater than making two separate enums
        NONE,
        BOOLEAN,
        FLOAT,
        VECTOR2,
        VECTOR3,
        POSE,
        SKELETON,
        HAPTIC
    };

    struct OpenXRInputDescription
    {
        std::string path;
        InputType type;
    };

    struct OpenVRInputDescription
    {
        std::string path;
        InputType type;
        bool click = false;
        bool touch = false;
    };

    union InputData
    {
        bool b;
        float f;
        XrVector2f vec2;
        XrVector3f vec3;
        PoseSet pose;
    };

    struct InputState
    {
        InputType type;
        InputData data;
        bool touching = false;
    };
}
