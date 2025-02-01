#pragma once

#include <cstdint>

#include "types_geometry.h"

namespace openvr
{
    enum TrackedDeviceClass
    {
        DEVICE_CLASS_INVALID = 0,
        DEVICE_CLASS_HMD = 1,
        DEVICE_CLASS_CONTROLLER = 2,
        DEVICE_CLASS_GENERIC_TRACKER = 3
    };

    enum TrackedControllerRole
    {
        CONTROLLER_ROLE_INVALID = 0,
        CONTROLLER_ROLE_LEFT_HAND = 1,
        CONTROLLER_ROLE_RIGHT_HAND = 2
    };

    enum TrackedDeviceProperty
    {
        PROPERTY_INVALID = 0,

        PROPERTY_SYSTEM_NAME = 1000,
        PROPERTY_MODEL_NUMBER = 1001,
        PROPERTY_SERIAL_NUMBER = 1002,
        PROPERTY_RENDER_MODEL_NAME = 1003,
        PROPERTY_MANUFACTURER_NAME = 1005,
        PROPERTY_BATTERY_IS_CHARGING = 1011,
        PROPERTY_BATTERY_PERCENTAGE = 1012,
        PROPERTY_PROVIDES_BATTERY_STATUS = 1026,
        PROPERTY_DEVICE_CLASS = 1029,
        PROPERTY_DRIVER_VERSION = 1031,
        PROPERTY_PARENT_DRIVER = 1034,
        PROPERTY_REGISTERED_DEVICE_TYPE = 1036,
        PROPERTY_INPUT_PROFILE_PATH = 1037,
        PROPERTY_ACTUAL_SYSTEM_NAME = 1054,

        PROPERTY_REPORTS_TIME_SINCE_VSYNC = 2000,
        PROPERTY_SECONDS_FROM_VSYNC_TO_PHOTONS = 2001,
        PROPERTY_DISPLAY_FREQUENCY = 2002,
        PROPERTY_IPD_METERS = 2003,
        PROPERTY_CURRENT_UNIVERSE_ID = 2004,
        PROPERTY_PREVIOUS_UNIVERSE_ID = 2005,
        PROPERTY_IS_ON_DESKTOP = 2007,
        PROPERTY_HEAD_TO_EYE_DEPTH_METERS = 2026,

        PROPERTY_ATTACHED_DEVICE_ID = 3000,
        PROPERTY_SUPPORTED_BUTTONS = 3001,
        PROPERTY_AXIS0_TYPE = 3002,
        PROPERTY_AXIS1_TYPE = 3003,
        PROPERTY_AXIS2_TYPE = 3004,
        PROPERTY_AXIS3_TYPE = 3005,
        PROPERTY_AXIS4_TYPE = 3006,
        PROPERTY_CONTROLLER_ROLE = 3007
    };

    enum TrackedDevicePropertyType
    {
        PROPERTY_TYPE_FLOAT = 1,
        PROPERTY_TYPE_INT32 = 2,
        PROPERTY_TYPE_UINT64 = 3,
        PROPERTY_TYPE_BOOL = 4,
        PROPERTY_TYPE_STRING = 5,
        PROPERTY_TYPE_ERROR = 6,
        PROPERTY_TYPE_DOUBLE = 7,

        PROPERTY_TYPE_MATRIX34 = 20,
        PROPERTY_TYPE_MATRIX44 = 21,
        PROPERTY_TYPE_VECTOR3 = 22,
        PROPERTY_TYPE_VECTOR4 = 23,
        PROPERTY_TYPE_VECTOR2 = 24,
        PROPERTY_TYPE_QUAD = 25,

        PROPERTY_TYPE_HIDDEN_AREA = 30,
        PROPERTY_TYPE_PATH_HANDLE_INFO = 31,
        PROPERTY_TYPE_ACTION_PROPERTY = 32,
        PROPERTY_TYPE_INPUT_VALUE = 33,
        PROPERTY_TYPE_WILDCARD = 34,
        PROPERTY_TYPE_HAPTIC_VIBRATION = 35,
        PROPERTY_TYPE_SKELETON = 36,

        PROPERTY_TYPE_SPATIAL_ANCHOR_POSE = 40,
        PROPERTY_TYPE_JSON = 41,
        PROPERTY_TYPE_ACTIVE_ACTION_SET = 42
    };

    enum TrackedPropertyError
    {
        PROPERTY_ERROR_SUCCESS = 0,
        PROPERTY_ERROR_WRONG_TYPE = 1,
        PROPERTY_ERROR_WRONG_CLASS = 2,
        PROPERTY_ERROR_BUFFER_TOO_SMALL = 3,
        PROPERTY_ERROR_UNKNOWN_PROPERTY = 4,
        PROPERTY_ERROR_INVALID_DEVICE = 5,
        PROPERTY_ERROR_NOT_YET_AVAILABLE = 9
    };

    enum ControllerAxisType
    {
        AXIS_NONE = 0,
        AXIS_TRACKPAD = 1,
        AXIS_JOYSTICK = 2,
        AXIS_TRIGGER = 3
    };

    enum ButtonId
    {
        BUTTON_SYSTEM = 0,
        BUTTON_MENU = 1,
        BUTTON_GRIP = 2,
        BUTTON_DPAD_LEFT = 3,
        BUTTON_DPAD_UP = 4,
        BUTTON_DPAD_RIGHT = 5,
        BUTTON_DPAD_DOWN = 6,
        BUTTON_A = 7,

        BUTTON_AXIS_0 = 32,
        BUTTON_AXIS_1 = 33,
        BUTTON_AXIS_2 = 34,
        BUTTON_AXIS_3 = 35,
        BUTTON_AXIS_4 = 36
    };

    enum MouseButton
    {
        MOUSE_BUTTON_LEFT = 1,
        MOUSE_BUTTON_RIGHT = 2,
        MOUSE_BUTTON_MIDDLE = 4
    };

    struct TrackedDevicePose
    {
        enum TrackingResult
        {
            TRACKING_UNINITIALIZED = 1,
            TRACKING_CALIBRATING_IN_PROGRESS = 100,
            TRACKING_CALIBRATING_OUT_OF_RANGE = 101,
            TRACKING_RUNNING_OK = 200,
            TRACKING_RUNNING_OUT_OF_RANGE = 201,
            TRACKING_FALLBACK_ROTATION_ONLY = 300
        };

        Matrix34 deviceToAbsolute;
        Vector3 velocity;
        Vector3 angularVelocity;
        TrackingResult trackingResult;
        bool poseIsValid;
        bool deviceIsConnected;
    };

    struct ControllerAxis
    {
        float x;
        float y;
    };

#if defined(__linux__) || defined(__APPLE__)
#pragma pack(push, 4)
#endif
    struct ControllerState
    {
        uint32_t packetNum;
        uint64_t buttonsPressed;
        uint64_t buttonsTouched;
        ControllerAxis axes[5];
    };
#if defined(__linux__) || defined(__APPLE__)
#pragma pack(pop)
#endif

    enum DeviceActivityLevel
    {
        ACTIVITY_LEVEL_UNKNOWN = -1,
        ACTIVITY_LEVEL_IDLE = 0,
        ACTIVITY_LEVEL_ACTIVE = 1,
        ACTIVITY_LEVEL_ACTIVE_TIMEOUT = 2,
        ACTIVITY_LEVEL_STANDBY = 3,
        ACTIVITY_LEVEL_IDLE_TIMEOUT = 4
    };

    enum InputError
    {
        INPUT_ERROR_NONE = 0,
        INPUT_ERROR_NAME_NOT_FOUND = 1,
        INPUT_ERROR_WRONG_TYPE = 2,
        INPUT_ERROR_INVALID_HANDLE = 3,
        INPUT_ERROR_INVALID_PARAM = 4,
        INPUT_ERROR_NO_STEAM = 5,
        INPUT_ERROR_MAX_CAPACITY_REACHED = 6,
        INPUT_ERROR_IPC_ERROR = 7,
        INPUT_ERROR_NO_ACTIVE_ACTION_SET = 8,
        INPUT_ERROR_INVALID_DEVICE = 9,
        INPUT_ERROR_INVALID_SKELETON = 10,
        INPUT_ERROR_INVALID_BONE_COUNT = 11,
        INPUT_ERROR_INVALID_COMPRESSED_DATA = 12,
        INPUT_ERROR_NO_DATA = 13,
        INPUT_ERROR_BUFFER_TOO_SMALL = 14,
        INPUT_ERROR_MISMATCHED_ACTION_MANIFEST = 15,
        INPUT_ERROR_MISSING_SKELETON_DATA = 16,
        INPUT_ERROR_INVALID_BONE_INDEX = 17,
        INPUT_ERROR_INVALID_PRIORITY = 18,
        INPUT_ERROR_PERMISSION_DENIED = 19,
        INPUT_ERROR_INVALID_RENDER_MODEL = 20
    };

    struct ActiveActionSet
    {
        uint64_t actionSet;
        uint64_t restrictToDevice;
        uint64_t secondaryActionSet;

        uint32_t padding;

        int32_t priority;
    };

    struct InputOriginInfo
    {
        uint64_t deviceHandle;
        uint32_t trackedDeviceIndex;
        char renderModelComponentName[128];
    };

    struct InputBindingInfo
    {
        char devicePath[128];
        char inputPath[128];
        char modeName[128];
        char slotName[128];
        char inputSourceType[32];
    };

    struct InputDigitalActionData
    {
        bool active;
        uint64_t currentOriginDevice;
        bool state;
        bool changed;
        float updateTime;
    };

    struct InputAnalogActionData
    {
        bool active;
        uint64_t currentOriginDevice;
        float x;
        float y;
        float z;
        float dx;
        float dy;
        float dz;
        float updateTime;        
    };

    struct InputPoseActionData
    {
        bool active;
        uint64_t currentOriginDevice;
        TrackedDevicePose pose;
    };

    struct InputSkeletalActionData
    {
        bool active;
        uint64_t currentOriginDevice;
    };

    struct BoneTransform
    {
        Vector4 position;
        Quaternionf orientation;
    };

    enum SkeletalTransformSpace
    {
        SKELETAL_TRANSFORM_SPACE_MODEL = 0,
        SKELETAL_TRANSFORM_SPACE_PARENT = 1,
        SKELETAL_TRANSFORM_SPACE_ADDITIVE = 2
    };

    enum SkeletalReferencePose
    {
        SKELETAL_REFERENCE_POSE_BIND = 0,
        SKELETAL_REFERENCE_POSE_OPEN = 1,
        SKELETAL_REFERENCE_POSE_FIST = 2,
        SKELETAL_REFERENCE_POSE_GRIP_LIMIT = 3
    };

    enum SkeletalTrackingLevel
    {
        SKELETAL_TRACKING_LEVEL_ESTIMATED = 0,
        SKELETAL_TRACKING_LEVEL_PARTIAL = 1,
        SKELETAL_TRACKING_LEVEL_FULL = 2
    };

    enum SkeletalMotionRange
    {
        SKELETAL_MOTION_RANGE_WITH_CONTROLLER = 0,
        SKELETAL_MOTION_RANGE_WITHOUT_CONTROLLER = 1
    };

    enum SkeletalSummaryType
    {
        SKELETAL_SUMMARY_TIME_FROM_ANIMATION = 0,
        SKELETAL_SUMMARY_TIME_FROM_DEVICE = 1
    };

    struct SkeletalSummaryData
    {
        float fingerCurl[5];
        float fingerSplay[4];
    };

    enum InputOriginStringSections
    {
        INPUT_ORIGIN_STRING_SECTION_HAND = 1,
        INPUT_ORIGIN_STRING_SECTION_CONTROLLER_TYPE = 2,
        INPUT_ORIGIN_STRING_SECTION_INPUT_SOURCE = 4,

        INPUT_ORIGIN_STRING_SECTIONS_ALL = 0xFFFFFFFF,
    };
}
