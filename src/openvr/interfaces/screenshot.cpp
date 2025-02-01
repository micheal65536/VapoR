#include "screenshot.h"
#include "../impl/init.h"
#include "log/stub.h"

using namespace openvr;

ScreenshotError Screenshots_001::requestScreenshot(uint32_t* screenshotHandleOut, ScreenshotType type, const char* previewFilename, const char* vrFilename)
{
    return openvr::screenshotsImpl->requestScreenshot(screenshotHandleOut, type, previewFilename, vrFilename);
}

ScreenshotError Screenshots_001::hookScreenshot(const ScreenshotType* types, int typesCount)
{
    return openvr::screenshotsImpl->hookScreenshot(types, typesCount);
}

ScreenshotType Screenshots_001::getScreenshotPropertyType(uint32_t screenshotHandle, ScreenshotError* error)
{
    return openvr::screenshotsImpl->getScreenshotPropertyType(screenshotHandle, error);
}

uint32_t Screenshots_001::getScreenshotPropertyFilename(uint32_t screenshotHandle, ScreenshotFilenameType filenameType, char* filename, uint32_t bufferSize, ScreenshotError* error)
{
    return openvr::screenshotsImpl->getScreenshotPropertyFilename(screenshotHandle, filenameType, filename, bufferSize, error);
}

ScreenshotError Screenshots_001::updateScreenshotProgress(uint32_t screenshotHandle, float progress)
{
    return openvr::screenshotsImpl->updateScreenshotProgress(screenshotHandle, progress);
}

ScreenshotError Screenshots_001::takeStereoScreenshot(uint32_t* screenshotHandleOut, const char* previewFilename, const char* vrFilename)
{
    return openvr::screenshotsImpl->takeStereoScreenshot(screenshotHandleOut, previewFilename, vrFilename);
}

ScreenshotError Screenshots_001::submitScreenshot(uint32_t screenshotHandle, ScreenshotType type, const char* sourcePreviewFilename, const char* sourceVrFilename)
{
    return openvr::screenshotsImpl->submitScreenshot(screenshotHandle, type, sourcePreviewFilename, sourceVrFilename);
}
