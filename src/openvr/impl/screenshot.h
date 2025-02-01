#pragma once

#include "../types.h"
#include <cstdint>
#include "client_core.h"

namespace openvr
{
    class ScreenshotsImpl
    {
        public:
            ClientCoreImpl& clientCore;
            ScreenshotsImpl(ClientCoreImpl& clientCore);

            //

            ScreenshotError requestScreenshot(uint32_t* screenshotHandleOut, ScreenshotType type, const char* previewFilename, const char* vrFilename);

            ScreenshotError hookScreenshot(const ScreenshotType* types, int typesCount);

            ScreenshotType getScreenshotPropertyType(uint32_t screenshotHandle, ScreenshotError* error);
            uint32_t getScreenshotPropertyFilename(uint32_t screenshotHandle, ScreenshotFilenameType filenameType, char* filename, uint32_t bufferSize, ScreenshotError* error);
            ScreenshotError updateScreenshotProgress(uint32_t screenshotHandle, float progress);

            ScreenshotError takeStereoScreenshot(uint32_t* screenshotHandleOut, const char* previewFilename, const char* vrFilename);

            ScreenshotError submitScreenshot(uint32_t screenshotHandle, ScreenshotType type, const char* sourcePreviewFilename, const char* sourceVrFilename);
    };
}
