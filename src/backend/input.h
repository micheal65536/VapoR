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

        float offsetMatrix[3][4];
    };

    enum class OpenXRInputType
    {
        NONE,
        BOOLEAN,
        FLOAT,
        VECTOR2,
        POSE,
        HAPTIC
    };

    struct OpenXRInputDescription
    {
        std::string path;
        OpenXRInputType type;
    };

    enum class OpenVRInputType
    {
        NONE,
        BOOLEAN,
        FLOAT,
        POSE,
        SKELETON,
        HAPTIC
    };

    struct OpenVRInputDescription
    {
        std::string path;
        OpenVRInputType type;
    };

    struct OpenXRInputState
    {
        union Data
        {
            bool b;
            float f;
            XrVector2f vec2;
            PoseSet pose;
        };

        OpenXRInputType type;
        Data data;
        long changeTime;
    };

    struct OpenVRInputState
    {
        union Data
        {
            bool b;
            float f;
            PoseSet pose;
        };

        OpenVRInputType type;
        Data data;
        long changeTime;
    };

    enum class OpenVRProfileInputType
    {
        NONE,
        BUTTON,
        TRIGGER,
        JOYSTICK,
        TRACKPAD,
        POSE,
        SKELETON,
        HAPTIC
    };

    struct OpenVRProfileInputDescription
    {
        std::string path;
        OpenVRProfileInputType type;
        bool click;
        bool touch;
        bool value;
    };
}
