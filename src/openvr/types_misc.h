#pragma once

#include <cstdint>

namespace openvr
{
    enum InitError
    {
        INIT_ERROR_NONE = 0,
        INIT_ERROR_UNKNOWN = 1,

        INIT_ERROR_INTERFACE_NOT_FOUND = 105,
        INIT_ERROR_INVALID_INTERFACE = 106
    };

    enum ApplicationType
    {
        APPLICATION_TYPE_OTHER = 0,
        APPLICATION_TYPE_SCENE = 1,
        APPLICATION_TYPE_OVERLAY = 2,
        APPLICATION_TYPE_BACKGROUND = 3,
        APPLICATION_TYPE_UTILITY = 4
    };

    enum Eye
    {
        EYE_LEFT = 0,
        EYE_RIGHT = 1
    };

    enum TrackingUniverseOrigin
    {
        ORIGIN_SEATED = 0,
        ORIGIN_STANDING = 1,
        ORIGIN_RAW = 2
    };

    struct HiddenAreaMesh
    {
        const Vector2* vertices;
        uint32_t triangleCount;
    };

    enum HiddenAreaMeshType
    {
        HIDDEN_AREA_MESH_TYPE_STANDARD = 0,
        HIDDEN_AREA_MESH_TYPE_INVERSE = 1,
        HIDDEN_AREA_MESH_TYPE_LINE_LOOP = 2
    };

    struct DistortionCoordinates
    {
        float red[2];
        float green[2];
        float blue[2];
    };

    enum FirmwareError
    {
        FIRMWARE_ERROR_NONE = 0,
        FIRMWARE_ERROR_SUCCESS = 1,
        FIRMWARE_ERROR_FAIL = 2
    };

    enum MatrixConvention
    {
        MATRIX_DIRECTX = 0,
        MATRIX_OPENGL = 1
    };

    enum SettingsError
    {
        SETTINGS_ERROR_NONE = 0,
        SETTINGS_ERROR_WRITE_FAILED = 2,
        SETTINGS_ERROR_READ_FAILED = 3,
        SETTINGS_ERROR_PARSE_FAILED = 4,
        SETTINGS_ERROR_UNSET_NO_DEFAULT = 5,
        SETTINGS_ERROR_ACCESS_DENIED = 6
    };

    enum ChaperoneCalibrationState
    {
        CHAPERONE_CALIBRATION_STATE_OK = 1,
        CHAPERONE_CALIBRATION_STATE_WARNING = 100,
        CHAPERONE_CALIBRATION_STATE_SEATED_BOUNDS_INVALID = 103,
        CHAPERONE_CALIBRATION_STATE_ERROR = 200,
        CHAPERONE_CALIBRATION_STATE_PLAY_AREA_INVALID = 203,
        CHAPERONE_CALIBRATION_STATE_COLLISION_BOUNDS_INVALID = 204
    };

    enum ChaperoneConfigFile
    {
        CHAPERONE_CONFIG_FILE_LIVE = 1,
        CHAPERONE_CONFIG_FILE_TEMP = 2
    };

    enum ControllerEventOutputType
    {
        CONTROLLER_EVENT_OUTPUT_TYPE_OS = 0,
        CONTROLLER_EVENT_OUTPUT_TYPE_VR = 1
    };

    enum DualAnalogWhich
    {
        DUAL_ANALOG_LEFT = 0,
        DUAL_ANALOG_RIGHT = 1
    };
}
