#pragma once

namespace vapor
{
    class FrameStateStore;
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
            static bool emitChangeEvents(FrameStateStore& frameStates, EventQueue& eventQueue);
    };
}
