#pragma once

#include <cstdint>

#include "types_geometry.h"
#include "types_misc.h"

namespace openvr
{
    enum OverlayError
    {
        OVERLAY_ERROR_NONE = 0,
        OVERLAY_ERROR_UNKNOWN_OVERLAY = 10,
        OVERLAY_ERROR_INVALID_HANDLE = 11,
        OVERLAY_ERROR_PERMISSION_DENIED = 12,
        OVERLAY_ERROR_WRONG_VISIBLITY_TYPE = 14,
        OVERLAY_ERROR_KEY_TOO_LONG = 15,
        OVERLAY_ERROR_NAME_TOO_LONG = 16,
        OVERLAY_ERROR_KEY_IN_USE = 17,
        OVERLAY_ERROR_WRONG_TRANSFORM_TYPE = 18,
        OVERLAY_ERROR_INVALID_TRACKED_DEVICE = 19,
        OVERLAY_ERROR_INVALID_PARAMETER = 20,
        OVERLAY_ERROR_THUMBNAIL_CANT_BE_DESTROYED = 21,
        OVERLAY_ERROR_ARRAY_TOO_SMALL = 22,
        OVERLAY_ERROR_REQUEST_FAILED = 23,
        OVERLAY_ERROR_INVALID_TEXTURE = 24,
        OVERLAY_ERROR_UNABLE_TO_LOAD_FILE = 25,
        OVERLAY_ERROR_KEYBOARD_ALREADY_IN_USE = 26,
        OVERLAY_ERROR_NO_NEIGHBOR = 27,
        OVERLAY_ERROR_BAD_MASK_PRIMITIVE = 30,
        OVERLAY_ERROR_TEXTURE_ALREADY_LOCKED = 31,
        OVERLAY_ERROR_TEXTURE_NOT_LOCKED = 33
    };

    enum OverlayTransformType
    {
        OVERLAY_TRANSFORM_TYPE_INVALID = -1,
        OVERLAY_TRANSFORM_TYPE_ABSOLUTE = 0,
        OVERLAY_TRANSFORM_TYPE_TRACKED_DEVICE_RELATIVE = 1,
        OVERLAY_TRANSFORM_TYPE_SYSTEM_OVERLAY = 2,
        OVERLAY_TRANSFORM_TYPE_TRACKED_COMPONENT = 3,
        OVERLAY_TRANSFORM_TYPE_CURSOR = 4,
        OVERLAY_TRANSFORM_TYPE_DASHBOARD_TAB = 5,
        OVERLAY_TRANSFORM_TYPE_DASHBOARD_THUMB = 6,
        OVERLAY_TRANSFORM_TYPE_MOUNTABLE = 7,
        OVERLAY_TRANSFORM_TYPE_PROJECTION = 8,
        OVERLAY_TRANSFORM_TYPE_SUBVIEW = 9
    };

    enum OverlayFlags
    {
        OVERLAY_FLAG_NO_DASHBOARD_TAB = 0x00000008,
        OVERLAY_FLAG_DISCRETE_SCROLL_EVENTS = 0x00000040,
        OVERLAY_FLAG_TOUCHPAD_EVENTS = 0x00000080,
        OVERLAY_FLAG_SHOW_TOUCHPAD_SCROLL_WHEEL = 0x00000100,
        OVERLAY_FLAG_TRANSFER_OWNERSHIP_TO_INTERNAL_PROCESS = 0x00000200,
        OVERLAY_FLAG_SBS_PARALLEL = 0x00000400,
        OVERLAY_FLAG_SBS_CROSSED = 0x00000800,
        OVERLAY_FLAG_PANORAMA = 0x00001000,
        OVERLAY_FLAG_STEREO_PANORAMA = 0x00002000,
        OVERLAY_FLAG_SORT_WITH_NON_SCENE_OVERLAYS = 0x00004000,
        OVERLAY_FLAG_VISIBLE_IN_DASHBOARD = 0x00008000,
        OVERLAY_FLAG_MAKE_INTERACTIVE_IF_VISIBLE = 0x00010000,
        OVERLAY_FLAG_SMOOTH_SCROLL_EVENTS = 0x00020000,
        OVERLAY_FLAG_PROTECTED_CONTENT = 0x00040000,
        OVERLAY_FLAG_HIDE_LASER_INTERSECTION = 0x00080000,
        OVERLAY_FLAG_MODAL = 0x00100000,
        OVERLAY_FLAG_PREMULTIPLIED = 0x00200000,
        OVERLAY_FLAG_IGNORE_TEXTURE_ALPHA = 0x00400000,
        OVERLAY_FLAG_CONTROL_BAR = 0x00800000,
        OVERLAY_FLAG_CONTROL_BAR_KEYBOARD = 0x01000000,
        OVERLAY_FLAG_CONTROL_BAR_CLOSE = 0x02000000,
        OVERLAY_FLAG_CLICK_STABILISATION = 0x08000000,
        OVERLAY_FLAG_MULTI_CURSOR = 0x10000000
    };

    struct OverlaySettings
    {
        uint32_t size;
        bool curved;
        bool antialias;
        float scale;
        float distance;
        float alpha;
        float uOffset;
        float vOffset;
        float uScale;
        float vScale;
        float gridDivs;
        float gridWidth;
        float gridScale;
        Matrix44 transform;
    };

    struct OverlayIntersectionParams
    {
        Vector3 source;
        Vector3 direction;
        TrackingUniverseOrigin origin;
    };

    struct OverlayIntersectionResults
    {
        Vector3 point;
        Vector3 normal;
        Vector2 uv;
        float distance;
    };

    struct OverlayIntersectionMaskPrimitive
    {
        enum Type
        {
            RECTANGLE = 0,
            CIRCLE = 1
        };

        struct RectangleData
        {
            float x;
            float y;
            float width;
            float height;
        };

        struct CircleData
        {
            float x;
            float y;
            float radius;
        };

        union Data
        {
            RectangleData rectangle;
            CircleData circle;
        };

        Type type;
        Data data;
    };

    enum OverlayInputMethod
    {
        OVERLAY_INPUT_METHOD_NONE = 0,
        OVERLAY_INPUT_METHOD_MOUSE = 1,
        OVERLAY_INPUT_METHOD_DUAL_ANALOG = 2
    };

    enum OverlayNeighborDirection
    {
        OVERLAY_NEIGHBOR_DIRECTION_UP = 0,
        OVERLAY_NEIGHBOR_DIRECTION_DOWN = 1,
        OVERLAY_NEIGHBOR_DIRECTION_LEFT = 2,
        OVERLAY_NEIGHBOR_DIRECTION_RIGHT = 3
    };

    enum MessageOverlayResponse
    {
        MESSAGE_OVERLAY_RESPONSE_BUTTON0 = 0,
        MESSAGE_OVERLAY_RESPONSE_BUTTON1 = 1,
        MESSAGE_OVERLAY_RESPONSE_BUTTON2 = 2,
        MESSAGE_OVERLAY_RESPONSE_BUTTON3 = 3,
        MESSAGE_OVERLAY_RESPONSE_APPLICATION_QUIT = 6
    };

    enum GamepadTextInputMode
    {
        TEXT_INPUT_MODE_NORMAL = 0,
        TEXT_INPUT_MODE_PASSWORD = 1,
        TEXT_INPUT_MODE_SUBMIT = 2
    };

    enum GamepadTextInputLineMode
    {
        TEXT_LINE_INPUT_MODE_SINGLE_LINE = 0,
        TEXT_LINE_INPUT_MODE_MULTI_LINE = 1
    };
}
