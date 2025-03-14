#pragma once

namespace openvr
{
    enum ScreenshotError
    {
        SCREENSHOT_ERROR_NONE = 0,
        SCREENSHOT_ERROR_REQUEST_FAILED = 1,
        SCREENSHOT_ERROR_INCOMPATIBLE_VERSION = 100,
        SCREENSHOT_ERROR_NOT_FOUND = 101,
        SCREENSHOT_ERROR_BUFFER_TOO_SMALL = 102,
        SCREENSHOT_ERROR_ALREADY_IN_PROGRESS = 108
    };

    enum ScreenshotType
    {
        SCREENSHOT_TYPE_NONE = 0,
        SCREENSHOT_TYPE_MONO = 1,
        SCREENSHOT_TYPE_STEREO = 2,
        SCREENSHOT_TYPE_CUBEMAP = 3,
        SCREENSHOT_TYPE_MONO_PANORAMA = 4,
        SCREENSHOT_TYPE_STEREO_PANORAMA = 5,
    };

    enum ScreenshotFilenameType
    {
        SCREENSHOT_FILENAME_TYPE_PREVIEW = 0,
        SCREENSHOT_FILENAME_TYPE_VR = 1
    };
}
