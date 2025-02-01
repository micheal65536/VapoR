#include "screenshot.h"
#include "log/log.h"
#include "log/stub.h"

using namespace openvr;

ScreenshotsImpl::ScreenshotsImpl(ClientCoreImpl& clientCore): clientCore(clientCore)
{
    // empty
}

ScreenshotError ScreenshotsImpl::requestScreenshot(uint32_t* screenshotHandleOut, ScreenshotType type, const char* previewFilename, const char* vrFilename)
{
    STUB();
    if (screenshotHandleOut != nullptr)
    {
        *screenshotHandleOut = 0;
    }
    return ScreenshotError::SCREENSHOT_ERROR_REQUEST_FAILED;
}

ScreenshotError ScreenshotsImpl::hookScreenshot(const ScreenshotType* types, int typesCount)
{
    STUB();
    return ScreenshotError::SCREENSHOT_ERROR_REQUEST_FAILED;
}

ScreenshotType ScreenshotsImpl::getScreenshotPropertyType(uint32_t screenshotHandle, ScreenshotError* error)
{
    STUB();
    if (error != nullptr)
    {
        *error = ScreenshotError::SCREENSHOT_ERROR_REQUEST_FAILED;
    }
    return SCREENSHOT_TYPE_NONE;
}

uint32_t ScreenshotsImpl::getScreenshotPropertyFilename(uint32_t screenshotHandle, ScreenshotFilenameType filenameType, char* filename, uint32_t bufferSize, ScreenshotError* error)
{
    STUB();
    if (error != nullptr)
    {
        *error = ScreenshotError::SCREENSHOT_ERROR_REQUEST_FAILED;
    }
    return 0;
}

ScreenshotError ScreenshotsImpl::updateScreenshotProgress(uint32_t screenshotHandle, float progress)
{
    STUB();
    return ScreenshotError::SCREENSHOT_ERROR_REQUEST_FAILED;
}

ScreenshotError ScreenshotsImpl::takeStereoScreenshot(uint32_t* screenshotHandleOut, const char* previewFilename, const char* vrFilename)
{
    STUB();
    if (screenshotHandleOut != nullptr)
    {
        *screenshotHandleOut = 0;
    }
    return ScreenshotError::SCREENSHOT_ERROR_REQUEST_FAILED;
}

ScreenshotError ScreenshotsImpl::submitScreenshot(uint32_t screenshotHandle, ScreenshotType type, const char* sourcePreviewFilename, const char* sourceVrFilename)
{
    STUB();
    return ScreenshotError::SCREENSHOT_ERROR_NONE;
}
