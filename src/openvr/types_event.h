#pragma once

#include <cstdint>

#include "types_input.h"

namespace openvr
{
    enum EventType
    {
        EVENT_NONE = 0,

        EVENT_TRACKED_DEVICE_ACTIVATED = 100,
        EVENT_TRACKED_DEVICE_DEACTIVATED = 101,
        EVENT_TRACKED_DEVICE_UPDATED = 102,
        EVENT_TRACKED_DEVICE_USER_INTERACTION_STARTED = 103,
        EVENT_TRACKED_DEVICE_USER_INTERACTION_ENDED = 104,
        EVENT_PROPERTY_CHANGED = 111,

        EVENT_BUTTON_PRESS = 200,
        EVENT_BUTTON_RELEASE = 201,
        EVENT_BUTTON_TOUCH = 202,
        EVENT_BUTTON_UNTOUCH = 203,

        HIDE_RENDER_MODELS = 410,
        SHOW_RENDER_MODELS = 411,

        REQUEST_SCREENSHOT = 520,
        SCREENSHOT_TAKEN = 521,
        SCREENSHOT_FAILED = 522,

        SEATED_ZERO_POSE_RESET = 804,
        STANDING_ZERO_POSE_RESET = 808,

        STAGE_OVERRIDE_READY = 1419
    };

    struct EventDataButton
    {
        ButtonId button;
    };

    struct EventDataMouse_0_9_0
    {
        float x;
        float y;
        MouseButton button;
    };

    struct EventDataMouse_0_9_15
    {
        float x;
        float y;
        uint32_t button;
        uint32_t cursorIndex;
    };

    struct EventDataScroll
    {
        float dx;
        float dy;
        uint32_t unused;
        float viewportScale;
        uint32_t cursorIndex;
    };

    struct EventDataScreenshot
    {
        uint32_t handle;
        uint32_t type;
    };

    struct EventDataZeroPoseReset
    {
        bool resetBySystemMenu;
    };

    struct Event_0_9_0
    {
        struct EventDataReservedSpace
        {
            uint64_t reserved0;
            uint64_t reserved1;
        };

        union EventData
        {
            EventDataReservedSpace reservedSpace;
            EventDataButton button;
            EventDataMouse_0_9_0 mouse; // TODO: mouse events are not converted in legacy event interface implementation
        };

        EventType type;
        uint32_t trackedDeviceIndex;
        EventData data;
        float ageSeconds;
    };

    struct Event_0_9_15
    {
        union EventData
        {
            EventDataButton button;
            EventDataMouse_0_9_15 mouse;
            EventDataScroll scroll;
            EventDataScreenshot screenshot;
            EventDataZeroPoseReset zeroPoseReset;
        };

        EventType type;
        uint32_t trackedDeviceIndex;
        float ageSeconds;
        EventData data;
    };
}
