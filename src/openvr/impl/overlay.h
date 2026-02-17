#pragma once

#include "../types.h"
#include <cstdint>
#include "client_core.h"

namespace openvr
{
    class OverlayImpl
    {
        public:
            ClientCoreImpl& clientCore;
            OverlayImpl(ClientCoreImpl& clientCore);
            ~OverlayImpl();

            //

            OverlayError findOverlay(const char* key, uint64_t* handle);

            OverlayError createOverlay(const char* key, const char* name, uint64_t* handle);
            OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle);
            OverlayError createSubviewOverlay(uint64_t parentHandle, const char* key, const char* name, uint64_t* handle);
            OverlayError destroyOverlay(uint64_t handle);

            uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
            uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
            OverlayError setOverlayName(uint64_t handle, const char* name);

            OverlayError setOverlayFlag(uint64_t handle, uint32_t flags, bool enabled);
            OverlayError getOverlayFlag(uint64_t handle, uint32_t flags, bool* enabled);
            OverlayError getOverlayFlags(uint64_t handle, uint32_t* flags);

            OverlayError setOverlayColor(uint64_t handle, float r, float g, float b);
            OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b);
            OverlayError setOverlayAlpha(uint64_t handle, float alpha);
            OverlayError getOverlayAlpha(uint64_t handle, float* alpha);
            OverlayError setOverlayGamma(uint64_t handle, float gamma);
            OverlayError getOverlayGamma(uint64_t handle, float* gamma);
            OverlayError setOverlayTexelAspectRatio(uint64_t handle, float aspect);
            OverlayError getOverlayTexelAspectRatio(uint64_t handle, float* aspect);
            OverlayError setOverlaySortOrder(uint64_t handle, uint32_t sortOrder);
            OverlayError getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder);
            OverlayError setOverlayWidthInMeters(uint64_t handle, float width);
            OverlayError getOverlayWidthInMeters(uint64_t handle, float* width);
            OverlayError setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance);
            OverlayError getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance);
            OverlayError setOverlayCurvature(uint64_t handle, float curvature);
            OverlayError getOverlayCurvature(uint64_t handle, float* curvature);
            OverlayError setOverlayPreCurvePitch(uint64_t handle, float radians);
            OverlayError getOverlayPreCurvePitch(uint64_t handle, float* radians);
            OverlayError getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix);

            OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType);
            OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix);
            OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix);
            OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix);
            OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix);
            OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName);
            OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize);
            OverlayError setOverlayTransformOverlayRelative(uint64_t handle, uint64_t parentHandle, const Matrix34* matrix);
            OverlayError getOverlayTransformOverlayRelative(uint64_t handle, uint64_t* parentHandle, Matrix34* matrix);
            OverlayError setOverlayTransformOverlayCursor(uint64_t handle, const Vector2* hotspot);
            OverlayError getOverlayTransformOverlayCursor(uint64_t handle, Vector2* hotspot);
            OverlayError setOverlayTransformProjection(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix, const OverlayProjection* projection, Eye eye);
            OverlayError setSubviewOverlayPosition(uint64_t handle, float x, float y);

            OverlayError showOverlay(uint64_t handle);
            OverlayError hideOverlay(uint64_t handle);
            bool isOverlayVisible(uint64_t handle);

            OverlayError legacyIsDashboardOverlay(uint64_t handle, bool* dashboard);
            OverlayError legacySetAsDashboardOverlay(uint64_t handle, bool dashboard);
            bool isDashboardVisible();
            bool isActiveDashboardOverlay(uint64_t handle);
            OverlayError showDashboard(const char* key);

            OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height);
            OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace);
            OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace);
            OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds);
            OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds);
            OverlayError setOverlayTexture(uint64_t handle, const Texture* texture);
            OverlayError clearOverlayTexture(uint64_t handle);
            OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth);
            OverlayError setOverlayFromFile(uint64_t handle, const char* filePath);
            OverlayError getOverlayNativeTexture(uint64_t handle, void** nativeTextureHandle, void* nativeTextureRef, uint32_t* width, uint32_t* height, uint32_t* format, TextureType* type, ColorSpace* colorSpace, TextureBounds* bounds);
            OverlayError releaseNativeOverlayTexture(uint64_t handle, void* nativeTextureHandle);
            OverlayError getOverlayTextureSize(uint64_t handle, uint32_t* width, uint32_t* height);

            OverlayError waitFrameSync(uint32_t timeout);
            bool pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t bufferSize);
            OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod);
            OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod);
            OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale);
            OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale);
            OverlayError setOverlayCursor(uint64_t handle, uint64_t cursorHandle);
            OverlayError setOverlayCursorPositionOverride(uint64_t handle, const Vector2* position);
            OverlayError clearOverlayCursorPositionOverride(uint64_t handle);
            OverlayError setOverlayIntersectionMask(uint64_t handle, OverlayIntersectionMaskPrimitive* primitives, uint32_t primitivesCount, uint32_t primitiveSize);
            bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results);
            bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex);
            bool isHoverTargetOverlay(uint64_t handle);
            OverlayError triggerLaserMouseHapticVibration(uint64_t handle, float durationSeconds, float frequency, float amplitude);
            uint32_t getPrimaryDashboardInputTrackedDevice();
            uint64_t getGamepadFocusOverlay();
            OverlayError setGamepadFocusOverlay(uint64_t handle);
            OverlayError setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to);
            OverlayError moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from);
            OverlayError setOverlayDualAnalogTransform(uint64_t handle, DualAnalogWhich which, const Vector2* center, float radius);
            OverlayError getOverlayDualAnalogTransform(uint64_t handle, DualAnalogWhich which, Vector2* center, float* radius);

            OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, uint32_t flags, const char* description, uint32_t maxChars, const char* existingText, uint64_t userValue);
            OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, uint32_t flags, const char* description, uint32_t maxChars, const char* existingText, uint64_t userValue);
            uint32_t getKeyboardText(char* text, uint32_t bufferSize);
            void hideKeyboard();
            void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix);
            void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect);

            MessageOverlayResponse showMessageOverlay(const char* text, const char* caption, const char* button0Text, const char* button1Text, const char* button2Text, const char* button3Text);
            void closeMessageOverlay();

            const char* getOverlayErrorNameFromEnum(OverlayError error);
    };
}
