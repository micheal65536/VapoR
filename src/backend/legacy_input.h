#pragma once

#include "pose_set.h"
#include <cstdint>

namespace vapor
{
    class EventQueue;

    struct LegacyInputButtonSet
    {
        bool system;
        bool menu;
        bool grip;
        bool dpadLeft;
        bool dpadUp;
        bool dpadRight;
        bool dpadDown;
        bool buttonA;
        bool axis0;
        bool axis1;
        bool axis2;
        bool axis3;
        bool axis4;
    };

    struct LegacyInputState
    {
        struct Axis
        {
            float x;
            float y;
        };

        LegacyInputButtonSet touch;
        LegacyInputButtonSet click;
        Axis axes[5];

        uint32_t packetNum = 0;
    };

    struct LegacyInputDescription
    {
        enum AxisType
        {
            NONE,
            TRACKPAD,
            JOYSTICK,
            TRIGGER
        };

        LegacyInputButtonSet supportedButtons;
        AxisType axisTypes[5];
    };

    class LegacyInputHelper
    {
        public:
            static bool compareStatesAndEmitChangeEvents(EventQueue& eventQueue, const PoseSet& eventControllerPose, int eventControllerIndex, const LegacyInputState& oldState, const LegacyInputState& newState);
    };
}
