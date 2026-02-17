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
        OVERLAY_ERROR_LIMIT_EXCEEDED = 13,
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
        OVERLAY_ERROR_TOO_MANY_PRIMITIVES = 29,
        OVERLAY_ERROR_BAD_MASK_PRIMITIVE = 30,
        OVERLAY_ERROR_TEXTURE_ALREADY_LOCKED = 31,
        OVERLAY_ERROR_TEXTURE_LOCK_CAPACITY_REACHED = 32,
        OVERLAY_ERROR_TEXTURE_NOT_LOCKED = 33,
        OVERLAY_ERROR_TIMED_OUT = 34
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

    struct OverlayProjection
    {
        float left;
        float right;
        float top;
        float bottom;
    };

    enum OverlayFlags
    {
        OVERLAY_FLAG_NO_DASHBOARD_TAB = 1 << 3,
        OVERLAY_FLAG_SEND_DISCRETE_SCROLL_EVENTS = 1 << 6,
        OVERLAY_FLAG_SEND_TOUCHPAD_EVENTS = 1 << 7,
        OVERLAY_FLAG_SHOW_TOUCHPAD_SCROLL_WHEEL = 1 << 8,
        OVERLAY_FLAG_TRANSFER_OWNERSHIP_TO_INTERNAL_PROCESS = 1 << 9,
        OVERLAY_FLAG_SBS_PARALLEL = 1 << 10,
        OVERLAY_FLAG_SBS_CROSSED = 1 << 11,
        OVERLAY_FLAG_PANORAMA = 1 << 12,
        OVERLAY_FLAG_STEREO_PANORAMA = 1 << 13,
        OVERLAY_FLAG_SORT_WITH_NON_SCENE_OVERLAYS = 1 << 14,
        OVERLAY_FLAG_VISIBLE_IN_DASHBOARD = 1 << 15,
        OVERLAY_FLAG_MAKE_INTERACTIVE_IF_VISIBLE = 1 << 16,
        OVERLAY_FLAG_SEND_SMOOTH_SCROLL_EVENTS = 1 << 17,
        OVERLAY_FLAG_PROTECTED_CONTENT = 1 << 18,
        OVERLAY_FLAG_HIDE_LASER_INTERSECTION = 1 << 19,
        OVERLAY_FLAG_MODAL = 1 << 20,
        OVERLAY_FLAG_PREMULTIPLIED = 1 << 21,
        OVERLAY_FLAG_IGNORE_TEXTURE_ALPHA = 1 << 22,
        OVERLAY_FLAG_CONTROL_BAR = 1 << 23,
        OVERLAY_FLAG_CONTROL_BAR_KEYBOARD = 1 << 24,
        OVERLAY_FLAG_CONTROL_BAR_CLOSE = 1 << 25,
        OVERLAY_FLAG_CLICK_STABILISATION = 1 << 27,
        OVERLAY_FLAG_MULTI_CURSOR = 1 << 28
    };

    enum OverlayFlagsLegacy
    {
        OVERLAY_FLAG_LEGACY_NONE = 0,
        OVERLAY_FLAG_LEGACY_CURVED = 1,
        OVERLAY_FLAG_LEGACY_RGSS4X = 2,
        OVERLAY_FLAG_LEGACY_NO_DASHBOARD_TAB = 3,
        OVERLAY_FLAG_LEGACY_ACCEPTS_GAMEPAD_EVENTS = 4,
        OVERLAY_FLAG_LEGACY_SHOW_GAMEPAD_FOCUS = 5,
        OVERLAY_FLAG_LEGACY_SEND_DISCRETE_SCROLL_EVENTS = 6,
        OVERLAY_FLAG_LEGACY_SEND_TOUCHPAD_EVENTS = 7,
        OVERLAY_FLAG_LEGACY_SHOW_TOUCHPAD_SCROLL_WHEEL = 8,
        OVERLAY_FLAG_LEGACY_TRANSFER_OWNERSHIP_TO_INTERNAL_PROCESS = 9,
        OVERLAY_FLAG_LEGACY_SBS_PARALLEL = 10,
        OVERLAY_FLAG_LEGACY_SBS_CROSSED = 11,
        OVERLAY_FLAG_LEGACY_PANORAMA = 12,
        OVERLAY_FLAG_LEGACY_STEREO_PANORAMA = 13,
        OVERLAY_FLAG_LEGACY_SORT_WITH_NON_SCENE_OVERLAYS = 14,
        OVERLAY_FLAG_LEGACY_VISIBLE_IN_DASHBOARD = 15,
        OVERLAY_FLAG_LEGACY_MAKE_INTERACTIVE_IF_VISIBLE = 16,
        OVERLAY_FLAG_LEGACY_SEND_SMOOTH_SCROLL_EVENTS = 17,
        OVERLAY_FLAG_LEGACY_PROTECTED_CONTENT = 18
    };

    enum OverlayVisibilityLegacy
    {
        OVERLAY_VISIBILITY_LEGACY_MANUAL = 0,
        OVERLAY_VISIBILITY_LEGACY_SYSTEM_OVERLAY = 1
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
        MESSAGE_OVERLAY_RESPONSE_COULDNT_FIND_SYSTEM_OVERLAY = 4,
        MESSAGE_OVERLAY_RESPONSE_COULDNT_FIND_OR_CREATE_CLIENT_OVERLAY = 5,
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

    enum KeyboardFlags
    {
        KEYBOARD_FLAG_MINIMAL = 1,
        KEYBOARD_FLAG_MODAL = 2
    };
}
