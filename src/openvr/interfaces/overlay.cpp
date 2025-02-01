#include "overlay.h"
#include "log/stub.h"

using namespace openvr;

OverlayError Overlay_018::findOverlay(const char* key, uint64_t* handle)
{
    STUB();
}

OverlayError Overlay_019::findOverlay(const char* key, uint64_t* handle)
{
    STUB();
}

OverlayError Overlay_018::createOverlay(const char* key, const char* name, uint64_t* handle)
{
    STUB();
}

OverlayError Overlay_019::createOverlay(const char* key, const char* name, uint64_t* handle)
{
    STUB();
}

OverlayError Overlay_018::destroyOverlay(uint64_t handle)
{
    STUB();
}

OverlayError Overlay_019::destroyOverlay(uint64_t handle)
{
    STUB();
}

OverlayError Overlay_018::setHighQualityOverlay(uint64_t handle)
{
    STUB();
}

OverlayError Overlay_019::setHighQualityOverlay(uint64_t handle)
{
    STUB();
}

uint64_t Overlay_018::getHighQualityOverlay()
{
    STUB();
}

uint64_t Overlay_019::getHighQualityOverlay()
{
    STUB();
}

uint32_t Overlay_018::getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error)
{
    STUB();
}

uint32_t Overlay_019::getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error)
{
    STUB();
}

uint32_t Overlay_018::getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error)
{
    STUB();
}

uint32_t Overlay_019::getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error)
{
    STUB();
}

OverlayError Overlay_018::setOverlayName(uint64_t handle, const char* name)
{
    STUB();
}

OverlayError Overlay_019::setOverlayName(uint64_t handle, const char* name)
{
    STUB();
}

OverlayError Overlay_018::getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height)
{
    STUB();
}

OverlayError Overlay_019::getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height)
{
    STUB();
}

const char* Overlay_018::getOverlayErrorNameFromEnum(OverlayError error)
{
    STUB();
}

const char* Overlay_019::getOverlayErrorNameFromEnum(OverlayError error)
{
    STUB();
}

OverlayError Overlay_018::setOverlayRenderingPid(uint64_t handle, uint32_t pid)
{
    STUB();
}

OverlayError Overlay_019::setOverlayRenderingPid(uint64_t handle, uint32_t pid)
{
    STUB();
}

uint32_t Overlay_018::getOverlayRenderingPid(uint64_t handle)
{
    STUB();
}

uint32_t Overlay_019::getOverlayRenderingPid(uint64_t handle)
{
    STUB();
}

OverlayError Overlay_018::setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled)
{
    STUB();
}

OverlayError Overlay_019::setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled)
{
    STUB();
}

OverlayError Overlay_018::getOverlayFlag(uint64_t handle, OverlayFlags flat, bool* enabled)
{
    STUB();
}

OverlayError Overlay_019::getOverlayFlag(uint64_t handle, OverlayFlags flat, bool* enabled)
{
    STUB();
}

OverlayError Overlay_018::setOverlayColor(uint64_t handle, float r, float g, float v)
{
    STUB();
}

OverlayError Overlay_019::setOverlayColor(uint64_t handle, float r, float g, float v)
{
    STUB();
}

OverlayError Overlay_018::getOverlayColor(uint64_t handle, float* r, float* g, float* b)
{
    STUB();
}

OverlayError Overlay_019::getOverlayColor(uint64_t handle, float* r, float* g, float* b)
{
    STUB();
}

OverlayError Overlay_018::setOverlayAlpha(uint64_t handle, float alpha)
{
    STUB();
}

OverlayError Overlay_019::setOverlayAlpha(uint64_t handle, float alpha)
{
    STUB();
}

OverlayError Overlay_018::getOverlayAlpha(uint64_t handle, float* alpha)
{
    STUB();
}

OverlayError Overlay_019::getOverlayAlpha(uint64_t handle, float* alpha)
{
    STUB();
}

OverlayError Overlay_018::setOverlayTexelAspectRatio(uint64_t handle, float aspect)
{
    STUB();
}

OverlayError Overlay_019::setOverlayTexelAspectRatio(uint64_t handle, float aspect)
{
    STUB();
}

OverlayError Overlay_018::getOverlayTexelAspectRatio(uint64_t handle, float* aspect)
{
    STUB();
}

OverlayError Overlay_019::getOverlayTexelAspectRatio(uint64_t handle, float* aspect)
{
    STUB();
}

OverlayError Overlay_018::setOverlaySortOrder(uint64_t handle, uint32_t sortOrder)
{
    STUB();
}

OverlayError Overlay_019::setOverlaySortOrder(uint64_t handle, uint32_t sortOrder)
{
    STUB();
}

OverlayError Overlay_018::getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder)
{
    STUB();
}

OverlayError Overlay_019::getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder)
{
    STUB();
}

OverlayError Overlay_018::setOverlayWidthInMeters(uint64_t handle, float width)
{
    STUB();
}

OverlayError Overlay_019::setOverlayWidthInMeters(uint64_t handle, float width)
{
    STUB();
}

OverlayError Overlay_018::getOverlayWidthInMeters(uint64_t handle, float* width)
{
    STUB();
}

OverlayError Overlay_019::getOverlayWidthInMeters(uint64_t handle, float* width)
{
    STUB();
}

OverlayError Overlay_018::setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance)
{
    STUB();
}

OverlayError Overlay_019::setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance)
{
    STUB();
}

OverlayError Overlay_018::getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance)
{
    STUB();
}

OverlayError Overlay_019::getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance)
{
    STUB();
}

OverlayError Overlay_018::setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace)
{
    STUB();
}

OverlayError Overlay_019::setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace)
{
    STUB();
}

OverlayError Overlay_018::getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace)
{
    STUB();
}

OverlayError Overlay_019::getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace)
{
    STUB();
}

OverlayError Overlay_018::setOverlayTextureBounds(uint64_t handle, TextureBounds* bounds)
{
    STUB();
}

OverlayError Overlay_019::setOverlayTextureBounds(uint64_t handle, TextureBounds* bounds)
{
    STUB();
}

OverlayError Overlay_018::getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds)
{
    STUB();
}

OverlayError Overlay_019::getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds)
{
    STUB();
}

uint32_t Overlay_018::getOverlayRenderModel(uint64_t handle, char* renderModel, uint32_t bufferSize, Color* color, OverlayError* error)
{
    STUB();
}

uint32_t Overlay_019::getOverlayRenderModel(uint64_t handle, char* renderModel, uint32_t bufferSize, Color* color, OverlayError* error)
{
    STUB();
}

OverlayError Overlay_018::setOverlayRenderModel(uint64_t handle, const char* renderModel, const Color* color)
{
    STUB();
}

OverlayError Overlay_019::setOverlayRenderModel(uint64_t handle, const char* renderModel, const Color* color)
{
    STUB();
}

OverlayError Overlay_018::getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType)
{
    STUB();
}

OverlayError Overlay_019::getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType)
{
    STUB();
}

OverlayError Overlay_018::setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix)
{
    STUB();
}

OverlayError Overlay_019::setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix)
{
    STUB();
}

OverlayError Overlay_018::getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix)
{
    STUB();
}

OverlayError Overlay_019::getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix)
{
    STUB();
}

OverlayError Overlay_018::setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix)
{
    STUB();
}

OverlayError Overlay_019::setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix)
{
    STUB();
}

OverlayError Overlay_018::getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix)
{
    STUB();
}

OverlayError Overlay_019::getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix)
{
    STUB();
}

OverlayError Overlay_018::setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName)
{
    STUB();
}

OverlayError Overlay_019::setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName)
{
    STUB();
}

OverlayError Overlay_018::getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize)
{
    STUB();
}

OverlayError Overlay_019::getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize)
{
    STUB();
}

OverlayError Overlay_018::getOverlayTransformOverlayRelative(uint64_t handle, uint64_t* parentHandle, Matrix34* matrix)
{
    STUB();
}

OverlayError Overlay_019::getOverlayTransformOverlayRelative(uint64_t handle, uint64_t* parentHandle, Matrix34* matrix)
{
    STUB();
}

OverlayError Overlay_018::setOverlayTransformOverlayRelative(uint64_t handle, uint64_t parentHandle, const Matrix34* matrix)
{
    STUB();
}

OverlayError Overlay_019::setOverlayTransformOverlayRelative(uint64_t handle, uint64_t parentHandle, const Matrix34* matrix)
{
    STUB();
}

OverlayError Overlay_018::showOverlay(uint64_t handle)
{
    STUB();
}

OverlayError Overlay_019::showOverlay(uint64_t handle)
{
    STUB();
}

OverlayError Overlay_018::hideOverlay(uint64_t handle)
{
    STUB();
}

OverlayError Overlay_019::hideOverlay(uint64_t handle)
{
    STUB();
}

bool Overlay_018::isOverlayVisible(uint64_t handle)
{
    STUB();
}

bool Overlay_019::isOverlayVisible(uint64_t handle)
{
    STUB();
}

OverlayError Overlay_018::getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix)
{
    STUB();
}

OverlayError Overlay_019::getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix)
{
    STUB();
}

bool Overlay_018::pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t eventSize)
{
    STUB();
}

bool Overlay_019::pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t eventSize)
{
    STUB();
}

OverlayError Overlay_018::getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod)
{
    STUB();
}

OverlayError Overlay_019::getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod)
{
    STUB();
}

OverlayError Overlay_018::setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod)
{
    STUB();
}

OverlayError Overlay_019::setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod)
{
    STUB();
}

OverlayError Overlay_018::getOverlayMouseScale(uint64_t handle, Vector2* mouseScale)
{
    STUB();
}

OverlayError Overlay_019::getOverlayMouseScale(uint64_t handle, Vector2* mouseScale)
{
    STUB();
}

OverlayError Overlay_018::setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale)
{
    STUB();
}

OverlayError Overlay_019::setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale)
{
    STUB();
}

bool Overlay_018::computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results)
{
    STUB();
}

bool Overlay_019::computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results)
{
    STUB();
}

bool Overlay_018::isHoverTargetOverlay(uint64_t handle)
{
    STUB();
}

bool Overlay_019::isHoverTargetOverlay(uint64_t handle)
{
    STUB();
}

uint64_t Overlay_018::getGamepadFocusOverlay()
{
    STUB();
}

uint64_t Overlay_019::getGamepadFocusOverlay()
{
    STUB();
}

OverlayError Overlay_018::setGamepadFocusOverlay(uint64_t handle)
{
    STUB();
}

OverlayError Overlay_019::setGamepadFocusOverlay(uint64_t handle)
{
    STUB();
}

OverlayError Overlay_018::setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to)
{
    STUB();
}

OverlayError Overlay_019::setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to)
{
    STUB();
}

OverlayError Overlay_018::moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from)
{
    STUB();
}

OverlayError Overlay_019::moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from)
{
    STUB();
}

OverlayError Overlay_018::setOverlayDualAnalogTransform(uint64_t handle, DualAnalogWhich which, const Vector2& center, float radius)
{
    STUB();
}

OverlayError Overlay_019::setOverlayDualAnalogTransform(uint64_t handle, DualAnalogWhich which, const Vector2* center, float radius)
{
    STUB();
}

OverlayError Overlay_018::getOverlayDualAnalogTransform(uint64_t ulOverlay, DualAnalogWhich which, Vector2* center, float* radius)
{
    STUB();
}

OverlayError Overlay_019::getOverlayDualAnalogTransform(uint64_t ulOverlay, DualAnalogWhich which, Vector2* center, float* radius)
{
    STUB();
}

OverlayError Overlay_018::setOverlayTexture(uint64_t handle, const Texture* texture)
{
    STUB();
}

OverlayError Overlay_019::setOverlayTexture(uint64_t handle, const Texture* texture)
{
    STUB();
}

OverlayError Overlay_018::clearOverlayTexture(uint64_t handle)
{
    STUB();
}

OverlayError Overlay_019::clearOverlayTexture(uint64_t handle)
{
    STUB();
}

OverlayError Overlay_018::setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth)
{
    STUB();
}

OverlayError Overlay_019::setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth)
{
    STUB();
}

OverlayError Overlay_018::setOverlayFromFile(uint64_t handle, const char* filePath)
{
    STUB();
}

OverlayError Overlay_019::setOverlayFromFile(uint64_t handle, const char* filePath)
{
    STUB();
}

OverlayError Overlay_018::getOverlayNativeTexture(uint64_t handle, void** nativeTextureHandle, void* nativeTextureRef, uint32_t* width, uint32_t* height, uint32_t* format, TextureType* type, ColorSpace* colorSpace, TextureBounds* bounds)
{
    STUB();
}

OverlayError Overlay_019::getOverlayNativeTexture(uint64_t handle, void** nativeTextureHandle, void* nativeTextureRef, uint32_t* width, uint32_t* height, uint32_t* format, TextureType* type, ColorSpace* colorSpace, TextureBounds* bounds)
{
    STUB();
}

OverlayError Overlay_018::releaseNativeOverlayTexture(uint64_t handle, void* nativeTextureHandle)
{
    STUB();
}

OverlayError Overlay_019::releaseNativeOverlayTexture(uint64_t handle, void* nativeTextureHandle)
{
    STUB();
}

OverlayError Overlay_018::getOverlayTextureSize(uint64_t handle, uint32_t* width, uint32_t* height)
{
    STUB();
}

OverlayError Overlay_019::getOverlayTextureSize(uint64_t handle, uint32_t* width, uint32_t* height)
{
    STUB();
}

OverlayError Overlay_018::createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle)
{
    STUB();
}

OverlayError Overlay_019::createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle)
{
    STUB();
}

bool Overlay_018::isDashboardVisible()
{
    STUB();
}

bool Overlay_019::isDashboardVisible()
{
    STUB();
}

bool Overlay_018::isActiveDashboardOverlay(uint64_t handle)
{
    STUB();
}

bool Overlay_019::isActiveDashboardOverlay(uint64_t handle)
{
    STUB();
}

OverlayError Overlay_018::setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid)
{
    STUB();
}

OverlayError Overlay_019::setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid)
{
    STUB();
}

OverlayError Overlay_018::getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid)
{
    STUB();
}

OverlayError Overlay_019::getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid)
{
    STUB();
}

void Overlay_018::showDashboard(const char* overlayToShow)
{
    STUB();
}

void Overlay_019::showDashboard(const char* overlayToShow)
{
    STUB();
}

uint32_t Overlay_018::getPrimaryDashboardInputTrackedDevice()
{
    STUB();
}

uint32_t Overlay_019::getPrimaryDashboardInputTrackedDevice()
{
    STUB();
}

OverlayError Overlay_018::showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue)
{
    STUB();
}

OverlayError Overlay_019::showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue)
{
    STUB();
}

OverlayError Overlay_018::showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue)
{
    STUB();
}

OverlayError Overlay_019::showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue)
{
    STUB();
}

uint32_t Overlay_018::getKeyboardText(char* text, uint32_t bufferSize)
{
    STUB();
}

uint32_t Overlay_019::getKeyboardText(char* text, uint32_t bufferSize)
{
    STUB();
}

void Overlay_018::hideKeyboard()
{
    STUB();
}

void Overlay_019::hideKeyboard()
{
    STUB();
}

void Overlay_018::setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix)
{
    STUB();
}

void Overlay_019::setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix)
{
    STUB();
}

void Overlay_018::setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect)
{
    STUB();
}

void Overlay_019::setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect)
{
    STUB();
}

OverlayError Overlay_018::setOverlayIntersectionMask(uint64_t handle, OverlayIntersectionMaskPrimitive* primitives, uint32_t primitivesCount, uint32_t primitiveSize)
{
    STUB();
}

OverlayError Overlay_019::setOverlayIntersectionMask(uint64_t handle, OverlayIntersectionMaskPrimitive* primitives, uint32_t primitivesCount, uint32_t primitiveSize)
{
    STUB();
}

OverlayError Overlay_018::getOverlayFlags(uint64_t handle, uint32_t* flags)
{
    STUB();
}

OverlayError Overlay_019::getOverlayFlags(uint64_t handle, uint32_t* flags)
{
    STUB();
}

MessageOverlayResponse Overlay_018::showMessageOverlay(const char* text, const char* caption, const char* button0Text, const char* button1Text, const char* button2Text, const char* button3Text)
{
    STUB();
}

MessageOverlayResponse Overlay_019::showMessageOverlay(const char* text, const char* caption, const char* button0Text, const char* button1Text, const char* button2Text, const char* button3Text)
{
    STUB();
}

void Overlay_018::closeMessageOverlay()
{
    STUB();
}

void Overlay_019::closeMessageOverlay()
{
    STUB();
}
