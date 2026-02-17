#include "overlay.h"
#include "log/log.h"
#include "log/stub.h"

using namespace openvr;

OverlayImpl::OverlayImpl(ClientCoreImpl& clientCore): clientCore(clientCore)
{
    // empty
}

OverlayImpl::~OverlayImpl()
{
    // TODO
}

OverlayError OverlayImpl::findOverlay(const char* key, uint64_t* handle)
{
    // TODO
    STUB_F("%s", key);
    *handle = 0;
    return OverlayError::OVERLAY_ERROR_UNKNOWN_OVERLAY;
}

OverlayError OverlayImpl::createOverlay(const char* key, const char* name, uint64_t* handle)
{
    // TODO
    STUB_F("%s %s", key, name);
    *handle = 0;
    return OverlayError::OVERLAY_ERROR_REQUEST_FAILED;
}

OverlayError OverlayImpl::createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle)
{
    // TODO
    STUB_F("%s %s", key, friendlyName);
    *mainHandle = *thumbnailHandle = 0;
    return OverlayError::OVERLAY_ERROR_REQUEST_FAILED;
}

OverlayError OverlayImpl::createSubviewOverlay(uint64_t parentHandle, const char* key, const char* name, uint64_t* handle)
{
    // TODO
    STUB_F("%lu %s %s", parentHandle, key, name);
    *handle = 0;
    return OverlayError::OVERLAY_ERROR_REQUEST_FAILED;
}

OverlayError OverlayImpl::destroyOverlay(uint64_t handle)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

uint32_t OverlayImpl::getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error)
{
    // TODO
    STUB_F("%lu", handle);
    return 0;
}

uint32_t OverlayImpl::getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error)
{
    // TODO
    STUB_F("%lu", handle);
    return 0;
}

OverlayError OverlayImpl::setOverlayName(uint64_t handle, const char* name)
{
    // TODO
    STUB_F("%lu %s", handle, name);
}

OverlayError OverlayImpl::setOverlayFlag(uint64_t handle, uint32_t flags, bool enabled)
{
    // TODO: perform bitwise OR of new flags (or inverse of new flags, if enabled is false) with current flags
    STUB_F("%lu %u %d", handle, flags, enabled);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayFlag(uint64_t handle, uint32_t flags, bool* enabled)
{
    // TODO: perform bitwise AND of provided flags with current flags and return true if non-zero
    STUB_F("%lu %u", handle, flags);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayFlags(uint64_t handle, uint32_t* flags)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayColor(uint64_t handle, float r, float g, float b)
{
    // TODO
    STUB_F("%lu %f %f %f", handle, r, g, b);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayColor(uint64_t handle, float* r, float* g, float* b)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayAlpha(uint64_t handle, float alpha)
{
    // TODO
    STUB_F("%lu %f", handle, alpha);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayAlpha(uint64_t handle, float* alpha)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayGamma(uint64_t handle, float gamma)
{
    // TODO
    STUB_F("%lu %f", handle, gamma);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayGamma(uint64_t handle, float* gamma)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayTexelAspectRatio(uint64_t handle, float aspect)
{
    // TODO
    STUB_F("%lu %f", handle, aspect);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayTexelAspectRatio(uint64_t handle, float* aspect)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlaySortOrder(uint64_t handle, uint32_t sortOrder)
{
    // TODO
    STUB_F("%lu %u", handle, sortOrder);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayWidthInMeters(uint64_t handle, float width)
{
    // TODO
    STUB_F("%lu %f", handle, width);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayWidthInMeters(uint64_t handle, float* width)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance)
{
    // TODO
    STUB_F("%lu %f %f", handle, minDistance, maxDistance);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayCurvature(uint64_t handle, float curvature)
{
    // TODO
    STUB_F("%lu %f", handle, curvature);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayCurvature(uint64_t handle, float* curvature)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayPreCurvePitch(uint64_t handle, float radians)
{
    // TODO
    STUB_F("%lu %f", handle, radians);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayPreCurvePitch(uint64_t handle, float* radians)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayTransformOverlayRelative(uint64_t handle, uint64_t parentHandle, const Matrix34* matrix)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayTransformOverlayRelative(uint64_t handle, uint64_t* parentHandle, Matrix34* matrix)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayTransformOverlayCursor(uint64_t handle, const Vector2* hotspot)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayTransformOverlayCursor(uint64_t handle, Vector2* hotspot)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayTransformProjection(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix, const OverlayProjection* projection, Eye eye)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setSubviewOverlayPosition(uint64_t handle, float x, float y)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::showOverlay(uint64_t handle)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::hideOverlay(uint64_t handle)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

bool OverlayImpl::isOverlayVisible(uint64_t handle)
{
    // TODO
    STUB_F("%lu", handle);
    return false;
}

OverlayError OverlayImpl::legacyIsDashboardOverlay(uint64_t handle, bool* dashboard)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::legacySetAsDashboardOverlay(uint64_t handle, bool dashboard)
{
    // TODO
    STUB_F("%lu %d", handle, dashboard);
    return OverlayError::OVERLAY_ERROR_NONE;
}

bool OverlayImpl::isDashboardVisible()
{
    // TODO
    STUB();
    return false;
}

bool OverlayImpl::isActiveDashboardOverlay(uint64_t handle)
{
    // TODO
    STUB_F("%lu", handle);
    return false;
}

OverlayError OverlayImpl::showDashboard(const char* key)
{
    // TODO
    STUB_F("%s", key);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace)
{
    // TODO
    STUB_F("%lu %d", handle, colorSpace);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayTexture(uint64_t handle, const Texture* texture)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::clearOverlayTexture(uint64_t handle)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayFromFile(uint64_t handle, const char* filePath)
{
    // TODO
    STUB_F("%lu %s", handle, filePath);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayNativeTexture(uint64_t handle, void** nativeTextureHandle, void* nativeTextureRef, uint32_t* width, uint32_t* height, uint32_t* format, TextureType* type, ColorSpace* colorSpace, TextureBounds* bounds)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::releaseNativeOverlayTexture(uint64_t handle, void* nativeTextureHandle)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayTextureSize(uint64_t handle, uint32_t* width, uint32_t* height)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::waitFrameSync(uint32_t timeout)
{
    // TODO
    STUB_F("%u", timeout);
    return OverlayError::OVERLAY_ERROR_NONE;
}

bool OverlayImpl::pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t bufferSize)
{
    // TODO
    STUB_F("%lu", handle);
    return false;
}

OverlayError OverlayImpl::setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod)
{
    // TODO
    STUB_F("%lu %d", handle, inputMethod);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayMouseScale(uint64_t handle, Vector2* mouseScale)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayCursor(uint64_t handle, uint64_t cursorHandle)
{
    // TODO
    STUB_F("%lu %lu", handle, cursorHandle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayCursorPositionOverride(uint64_t handle, const Vector2* position)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::clearOverlayCursorPositionOverride(uint64_t handle)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayIntersectionMask(uint64_t handle, OverlayIntersectionMaskPrimitive* primitives, uint32_t primitivesCount, uint32_t primitiveSize)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

bool OverlayImpl::computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results)
{
    // TODO
    STUB_F("%lu", handle);
    return false;
}

bool OverlayImpl::handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex)
{
    // TODO
    STUB_F("%lu %u", handle, controllerDeviceIndex);
    return false;
}

bool OverlayImpl::isHoverTargetOverlay(uint64_t handle)
{
    // TODO
    STUB_F("%lu", handle);
    return false;
}

OverlayError OverlayImpl::triggerLaserMouseHapticVibration(uint64_t handle, float durationSeconds, float frequency, float amplitude)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

uint32_t OverlayImpl::getPrimaryDashboardInputTrackedDevice()
{
    // TODO
    STUB();
    return 0;
}

uint64_t OverlayImpl::getGamepadFocusOverlay()
{
    // TODO
    STUB();
    return 0;
}

OverlayError OverlayImpl::setGamepadFocusOverlay(uint64_t handle)
{
    // TODO
    STUB_F("%lu", handle);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to)
{
    // TODO
    STUB_F("%d %lu %lu", from, to);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from)
{
    // TODO
    STUB_F("%d %lu", direction, from);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::setOverlayDualAnalogTransform(uint64_t handle, DualAnalogWhich which, const Vector2* center, float radius)
{
    // TODO
    STUB_F("%lu %d", handle, which);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::getOverlayDualAnalogTransform(uint64_t handle, DualAnalogWhich which, Vector2* center, float* radius)
{
    // TODO
    STUB_F("%lu %d", handle, which);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, uint32_t flags, const char* description, uint32_t maxChars, const char* existingText, uint64_t userValue)
{
    // TODO
    STUB_F("%d %d %u %s %u %s %lu", textInputMode, textInputLineMode, flags, description, maxChars, existingText, userValue);
    return OverlayError::OVERLAY_ERROR_NONE;
}

OverlayError OverlayImpl::showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, uint32_t flags, const char* description, uint32_t maxChars, const char* existingText, uint64_t userValue)
{
    // TODO
    STUB_F("%lu %d %d %u %s %u %s %lu", handle, textInputMode, textInputLineMode, flags, description, maxChars, existingText, userValue);
    return OverlayError::OVERLAY_ERROR_NONE;
}

uint32_t OverlayImpl::getKeyboardText(char* text, uint32_t bufferSize)
{
    // TODO
    STUB();
    return 0;
}

void OverlayImpl::hideKeyboard()
{
    // TODO
    STUB();
}

void OverlayImpl::setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix)
{
    // TODO
    STUB();
}

void OverlayImpl::setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect)
{
    // TODO
    STUB_F("%lu", handle);
}

MessageOverlayResponse OverlayImpl::showMessageOverlay(const char* text, const char* caption, const char* button0Text, const char* button1Text, const char* button2Text, const char* button3Text)
{
    // TODO
    STUB_F("%s %s %s %s %s %s", text, caption, button0Text, button1Text, button2Text, button3Text);
    return MessageOverlayResponse::MESSAGE_OVERLAY_RESPONSE_COULDNT_FIND_SYSTEM_OVERLAY;
}

void OverlayImpl::closeMessageOverlay()
{
    // TODO
    STUB();
}

const char* OverlayImpl::getOverlayErrorNameFromEnum(OverlayError error)
{
    // TODO
    STUB_F("%d", error);
    return "";
}
