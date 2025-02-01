#pragma once

#include "../types.h"
#include <cstdint>

#include "../impl/screenshot.h"

namespace openvr
{
    struct Screenshots_001
    {
        static ScreenshotError requestScreenshot(uint32_t* screenshotHandleOut, ScreenshotType type, const char* previewFilename, const char* vrFilename);

        static ScreenshotError hookScreenshot(const ScreenshotType* types, int typesCount);

        static ScreenshotType getScreenshotPropertyType(uint32_t screenshotHandle, ScreenshotError* error);
        static uint32_t getScreenshotPropertyFilename(uint32_t screenshotHandle, ScreenshotFilenameType filenameType, char* filename, uint32_t bufferSize, ScreenshotError* error);
        static ScreenshotError updateScreenshotProgress(uint32_t screenshotHandle, float progress);

        static ScreenshotError takeStereoScreenshot(uint32_t* screenshotHandleOut, const char* previewFilename, const char* vrFilename);

        static ScreenshotError submitScreenshot(uint32_t screenshotHandle, ScreenshotType type, const char* sourcePreviewFilename, const char* sourceVrFilename);
    
        void* requestScreenshot_ = (void*) requestScreenshot;
        void* hookScreenshot_ = (void*) hookScreenshot;
        void* getScreenshotPropertyType_ = (void*) getScreenshotPropertyType;
        void* getScreenshotPropertyFilename_ = (void*) getScreenshotPropertyFilename;
        void* updateScreenshotProgress_ = (void*) updateScreenshotProgress;
        void* takeStereoScreenshot_ = (void*) takeStereoScreenshot;
        void* submitScreenshot_ = (void*) submitScreenshot;
    };

    class Screenshots_001_v
    {
        public:
            virtual ScreenshotError requestScreenshot(uint32_t* screenshotHandleOut, ScreenshotType type, const char* previewFilename, const char* vrFilename) { return Screenshots_001::requestScreenshot(screenshotHandleOut, type, previewFilename, vrFilename); }
            virtual ScreenshotError hookScreenshot(const ScreenshotType* types, int typesCount) { return Screenshots_001::hookScreenshot(types, typesCount); }
            virtual ScreenshotType getScreenshotPropertyType(uint32_t screenshotHandle, ScreenshotError* error) { return Screenshots_001::getScreenshotPropertyType(screenshotHandle, error); }
            virtual uint32_t getScreenshotPropertyFilename(uint32_t screenshotHandle, ScreenshotFilenameType filenameType, char* filename, uint32_t bufferSize, ScreenshotError* error) { return Screenshots_001::getScreenshotPropertyFilename(screenshotHandle, filenameType, filename, bufferSize, error); }
            virtual ScreenshotError updateScreenshotProgress(uint32_t screenshotHandle, float progress) { return Screenshots_001::updateScreenshotProgress(screenshotHandle, progress); }
            virtual ScreenshotError takeStereoScreenshot(uint32_t* screenshotHandleOut, const char* previewFilename, const char* vrFilename) { return Screenshots_001::takeStereoScreenshot(screenshotHandleOut, previewFilename, vrFilename); }
            virtual ScreenshotError submitScreenshot(uint32_t screenshotHandle, ScreenshotType type, const char* sourcePreviewFilename, const char* sourceVrFilename) { return Screenshots_001::submitScreenshot(screenshotHandle, type, sourcePreviewFilename, sourceVrFilename); }
    };
}
