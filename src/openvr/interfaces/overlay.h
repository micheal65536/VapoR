#pragma once

#include "../types.h"
#include <cstdint>

namespace openvr
{
    // TODO: other versions
    // TODO: impl class

    struct Overlay_018
    {
        static OverlayError findOverlay(const char* key, uint64_t* handle);

        static OverlayError createOverlay(const char* key, const char* name, uint64_t* handle);
        static OverlayError destroyOverlay(uint64_t handle);

        static OverlayError setHighQualityOverlay(uint64_t handle);
        static uint64_t getHighQualityOverlay();

        static uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static OverlayError setOverlayName(uint64_t handle, const char* name);

        static OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height);

        static const char* getOverlayErrorNameFromEnum(OverlayError error);

        static OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid);
        static uint32_t getOverlayRenderingPid(uint64_t handle);

        static OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled);
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flat, bool* enabled);
        static OverlayError setOverlayColor(uint64_t handle, float r, float g, float v);
        static OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b);
        static OverlayError setOverlayAlpha(uint64_t handle, float alpha);
        static OverlayError getOverlayAlpha(uint64_t handle, float* alpha);
        static OverlayError setOverlayTexelAspectRatio(uint64_t handle, float aspect);
        static OverlayError getOverlayTexelAspectRatio(uint64_t handle, float* aspect);

        static OverlayError setOverlaySortOrder(uint64_t handle, uint32_t sortOrder);
        static OverlayError getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder);
        static OverlayError setOverlayWidthInMeters(uint64_t handle, float width);
        static OverlayError getOverlayWidthInMeters(uint64_t handle, float* width);
        static OverlayError setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance);
        static OverlayError getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance);

        static OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace);
        static OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace);
        static OverlayError setOverlayTextureBounds(uint64_t handle, TextureBounds* bounds);
        static OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds);

        static uint32_t getOverlayRenderModel(uint64_t handle, char* renderModel, uint32_t bufferSize, Color* color, OverlayError* error);
        static OverlayError setOverlayRenderModel(uint64_t handle, const char* renderModel, const Color* color);

        static OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType);
        static OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix);
        static OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix);
        static OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName);
        static OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize);
        static OverlayError getOverlayTransformOverlayRelative(uint64_t handle, uint64_t* parentHandle, Matrix34* matrix);
        static OverlayError setOverlayTransformOverlayRelative(uint64_t handle, uint64_t parentHandle, const Matrix34* matrix);

        static OverlayError showOverlay(uint64_t handle);
        static OverlayError hideOverlay(uint64_t handle);
        static bool isOverlayVisible(uint64_t handle);

        static OverlayError getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix);

        static bool pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t eventSize);

        static OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod);
        static OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod);
        static OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale);
        static OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale);

        static bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results);

        static bool isHoverTargetOverlay(uint64_t handle);

        static uint64_t getGamepadFocusOverlay();
        static OverlayError setGamepadFocusOverlay(uint64_t handle);
        static OverlayError setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to);
        static OverlayError moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from);

        static OverlayError setOverlayDualAnalogTransform(uint64_t handle, DualAnalogWhich which, const Vector2& center, float radius);
        static OverlayError getOverlayDualAnalogTransform(uint64_t ulOverlay, DualAnalogWhich which, Vector2* center, float* radius);

        static OverlayError setOverlayTexture(uint64_t handle, const Texture* texture);
        static OverlayError clearOverlayTexture(uint64_t handle);

        static OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth);
        static OverlayError setOverlayFromFile(uint64_t handle, const char* filePath);

        static OverlayError getOverlayNativeTexture(uint64_t handle, void** nativeTextureHandle, void* nativeTextureRef, uint32_t* width, uint32_t* height, uint32_t* format, TextureType* type, ColorSpace* colorSpace, TextureBounds* bounds);
        static OverlayError releaseNativeOverlayTexture(uint64_t handle, void* nativeTextureHandle);

        static OverlayError getOverlayTextureSize(uint64_t handle, uint32_t* width, uint32_t* height);

        static OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle);

        static bool isDashboardVisible();
        static bool isActiveDashboardOverlay(uint64_t handle);

        static OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid);
        static OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid);

        static void showDashboard(const char* overlayToShow);

        static uint32_t getPrimaryDashboardInputTrackedDevice();

        static OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue);
        static OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue);
        static uint32_t getKeyboardText(char* text, uint32_t bufferSize);
        static void hideKeyboard();

        static void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix);
        static void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect);

        static OverlayError setOverlayIntersectionMask(uint64_t handle, OverlayIntersectionMaskPrimitive* primitives, uint32_t primitivesCount, uint32_t primitiveSize);

        static OverlayError getOverlayFlags(uint64_t handle, uint32_t* flags);

        static MessageOverlayResponse showMessageOverlay(const char* text, const char* caption, const char* button0Text, const char* button1Text, const char* button2Text, const char* button3Text);
        static void closeMessageOverlay();
    
        void* findOverlay_ = (void*) findOverlay;
        void* createOverlay_ = (void*) createOverlay;
        void* destroyOverlay_ = (void*) destroyOverlay;
        void* setHighQualityOverlay_ = (void*) setHighQualityOverlay;
        void* getHighQualityOverlay_ = (void*) getHighQualityOverlay;
        void* getOverlayKey_ = (void*) getOverlayKey;
        void* getOverlayName_ = (void*) getOverlayName;
        void* setOverlayName_ = (void*) setOverlayName;
        void* getOverlayImageData_ = (void*) getOverlayImageData;
        void* getOverlayErrorNameFromEnum_ = (void*) getOverlayErrorNameFromEnum;
        void* setOverlayRenderingPid_ = (void*) setOverlayRenderingPid;
        void* getOverlayRenderingPid_ = (void*) getOverlayRenderingPid;
        void* setOverlayFlag_ = (void*) setOverlayFlag;
        void* getOverlayFlag_ = (void*) getOverlayFlag;
        void* setOverlayColor_ = (void*) setOverlayColor;
        void* getOverlayColor_ = (void*) getOverlayColor;
        void* setOverlayAlpha_ = (void*) setOverlayAlpha;
        void* getOverlayAlpha_ = (void*) getOverlayAlpha;
        void* setOverlayTexelAspectRatio_ = (void*) setOverlayTexelAspectRatio;
        void* getOverlayTexelAspectRatio_ = (void*) getOverlayTexelAspectRatio;
        void* setOverlaySortOrder_ = (void*) setOverlaySortOrder;
        void* getOverlaySortOrder_ = (void*) getOverlaySortOrder;
        void* setOverlayWidthInMeters_ = (void*) setOverlayWidthInMeters;
        void* getOverlayWidthInMeters_ = (void*) getOverlayWidthInMeters;
        void* setOverlayAutoCurveDistanceRangeInMeters_ = (void*) setOverlayAutoCurveDistanceRangeInMeters;
        void* getOverlayAutoCurveDistanceRangeInMeters_ = (void*) getOverlayAutoCurveDistanceRangeInMeters;
        void* setOverlayTextureColorSpace_ = (void*) setOverlayTextureColorSpace;
        void* getOverlayTextureColorSpace_ = (void*) getOverlayTextureColorSpace;
        void* setOverlayTextureBounds_ = (void*) setOverlayTextureBounds;
        void* getOverlayTextureBounds_ = (void*) getOverlayTextureBounds;
        void* getOverlayRenderModel_ = (void*) getOverlayRenderModel;
        void* setOverlayRenderModel_ = (void*) setOverlayRenderModel;
        void* getOverlayTransformType_ = (void*) getOverlayTransformType;
        void* setOverlayTransformAbsolute_ = (void*) setOverlayTransformAbsolute;
        void* getOverlayTransformAbsolute_ = (void*) getOverlayTransformAbsolute;
        void* setOverlayTransformTrackedDeviceRelative_ = (void*) setOverlayTransformTrackedDeviceRelative;
        void* getOverlayTransformTrackedDeviceRelative_ = (void*) getOverlayTransformTrackedDeviceRelative;
        void* setOverlayTransformTrackedDeviceComponent_ = (void*) setOverlayTransformTrackedDeviceComponent;
        void* getOverlayTransformTrackedDeviceComponent_ = (void*) getOverlayTransformTrackedDeviceComponent;
        void* getOverlayTransformOverlayRelative_ = (void*) getOverlayTransformOverlayRelative;
        void* setOverlayTransformOverlayRelative_ = (void*) setOverlayTransformOverlayRelative;
        void* showOverlay_ = (void*) showOverlay;
        void* hideOverlay_ = (void*) hideOverlay;
        void* isOverlayVisible_ = (void*) isOverlayVisible;
        void* getTransformForOverlayCoordinates_ = (void*) getTransformForOverlayCoordinates;
        void* pollNextOverlayEvent_ = (void*) pollNextOverlayEvent;
        void* getOverlayInputMethod_ = (void*) getOverlayInputMethod;
        void* setOverlayInputMethod_ = (void*) setOverlayInputMethod;
        void* getOverlayMouseScale_ = (void*) getOverlayMouseScale;
        void* setOverlayMouseScale_ = (void*) setOverlayMouseScale;
        void* computeOverlayIntersection_ = (void*) computeOverlayIntersection;
        void* isHoverTargetOverlay_ = (void*) isHoverTargetOverlay;
        void* getGamepadFocusOverlay_ = (void*) getGamepadFocusOverlay;
        void* setGamepadFocusOverlay_ = (void*) setGamepadFocusOverlay;
        void* setOverlayNeighbor_ = (void*) setOverlayNeighbor;
        void* moveGamepadFocusToNeighbor_ = (void*) moveGamepadFocusToNeighbor;
        void* setOverlayDualAnalogTransform_ = (void*) setOverlayDualAnalogTransform;
        void* getOverlayDualAnalogTransform_ = (void*) getOverlayDualAnalogTransform;
        void* setOverlayTexture_ = (void*) setOverlayTexture;
        void* clearOverlayTexture_ = (void*) clearOverlayTexture;
        void* setOverlayRaw_ = (void*) setOverlayRaw;
        void* setOverlayFromFile_ = (void*) setOverlayFromFile;
        void* getOverlayNativeTexture_ = (void*) getOverlayNativeTexture;
        void* releaseNativeOverlayTexture_ = (void*) releaseNativeOverlayTexture;
        void* getOverlayTextureSize_ = (void*) getOverlayTextureSize;
        void* createDashboardOverlay_ = (void*) createDashboardOverlay;
        void* isDashboardVisible_ = (void*) isDashboardVisible;
        void* isActiveDashboardOverlay_ = (void*) isActiveDashboardOverlay;
        void* setDashboardOverlaySceneProcess_ = (void*) setDashboardOverlaySceneProcess;
        void* getDashboardOverlaySceneProcess_ = (void*) getDashboardOverlaySceneProcess;
        void* showDashboard_ = (void*) showDashboard;
        void* getPrimaryDashboardInputTrackedDevice_ = (void*) getPrimaryDashboardInputTrackedDevice;
        void* showKeyboard_ = (void*) showKeyboard;
        void* showKeyboardForOverlay_ = (void*) showKeyboardForOverlay;
        void* getKeyboardText_ = (void*) getKeyboardText;
        void* hideKeyboard_ = (void*) hideKeyboard;
        void* setKeyboardTransformAbsolute_ = (void*) setKeyboardTransformAbsolute;
        void* setKeyboardPositionForOverlay_ = (void*) setKeyboardPositionForOverlay;
        void* setOverlayIntersectionMask_ = (void*) setOverlayIntersectionMask;
        void* getOverlayFlags_ = (void*) getOverlayFlags;
        void* showMessageOverlay_ = (void*) showMessageOverlay;
        void* closeMessageOverlay_ = (void*) closeMessageOverlay;
    };

    class Overlay_018_v
    {
        public:
            virtual OverlayError findOverlay(const char* key, uint64_t* handle) { return Overlay_018::findOverlay(key, handle); }
            virtual OverlayError createOverlay(const char* key, const char* name, uint64_t* handle) { return Overlay_018::createOverlay(key, name, handle); }
            virtual OverlayError destroyOverlay(uint64_t handle) { return Overlay_018::destroyOverlay(handle); }
            virtual OverlayError setHighQualityOverlay(uint64_t handle) { return Overlay_018::setHighQualityOverlay(handle); }
            virtual uint64_t getHighQualityOverlay() { return Overlay_018::getHighQualityOverlay(); }
            virtual uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_018::getOverlayKey(handle, value, bufferSize, error); }
            virtual uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_018::getOverlayName(handle, value, bufferSize, error); }
            virtual OverlayError setOverlayName(uint64_t handle, const char* name) { return Overlay_018::setOverlayName(handle, name); }
            virtual OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height) { return Overlay_018::getOverlayImageData(handle, buffer, bufferSize, width, height); }
            virtual const char* getOverlayErrorNameFromEnum(OverlayError error) { return Overlay_018::getOverlayErrorNameFromEnum(error); }
            virtual OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid) { return Overlay_018::setOverlayRenderingPid(handle, pid); }
            virtual uint32_t getOverlayRenderingPid(uint64_t handle) { return Overlay_018::getOverlayRenderingPid(handle); }
            virtual OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled) { return Overlay_018::setOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flat, bool* enabled) { return Overlay_018::getOverlayFlag(handle, flat, enabled); }
            virtual OverlayError setOverlayColor(uint64_t handle, float r, float g, float v) { return Overlay_018::setOverlayColor(handle, r, g, v); }
            virtual OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b) { return Overlay_018::getOverlayColor(handle, r, g, b); }
            virtual OverlayError setOverlayAlpha(uint64_t handle, float alpha) { return Overlay_018::setOverlayAlpha(handle, alpha); }
            virtual OverlayError getOverlayAlpha(uint64_t handle, float* alpha) { return Overlay_018::getOverlayAlpha(handle, alpha); }
            virtual OverlayError setOverlayTexelAspectRatio(uint64_t handle, float aspect) { return Overlay_018::setOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError getOverlayTexelAspectRatio(uint64_t handle, float* aspect) { return Overlay_018::getOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError setOverlaySortOrder(uint64_t handle, uint32_t sortOrder) { return Overlay_018::setOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder) { return Overlay_018::getOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError setOverlayWidthInMeters(uint64_t handle, float width) { return Overlay_018::setOverlayWidthInMeters(handle, width); }
            virtual OverlayError getOverlayWidthInMeters(uint64_t handle, float* width) { return Overlay_018::getOverlayWidthInMeters(handle, width); }
            virtual OverlayError setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance) { return Overlay_018::setOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance) { return Overlay_018::getOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace) { return Overlay_018::setOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace) { return Overlay_018::getOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_018::setOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_018::getOverlayTextureBounds(handle, bounds); }
            virtual uint32_t getOverlayRenderModel(uint64_t handle, char* renderModel, uint32_t bufferSize, Color* color, OverlayError* error) { return Overlay_018::getOverlayRenderModel(handle, renderModel, bufferSize, color, error); }
            virtual OverlayError setOverlayRenderModel(uint64_t handle, const char* renderModel, const Color* color) { return Overlay_018::setOverlayRenderModel(handle, renderModel, color); }
            virtual OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType) { return Overlay_018::getOverlayTransformType(handle, transformType); }
            virtual OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_018::setOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix) { return Overlay_018::getOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix) { return Overlay_018::setOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix) { return Overlay_018::getOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName) { return Overlay_018::setOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName); }
            virtual OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize) { return Overlay_018::getOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName, bufferSize); }
            virtual OverlayError getOverlayTransformOverlayRelative(uint64_t handle, uint64_t* parentHandle, Matrix34* matrix) { return Overlay_018::getOverlayTransformOverlayRelative(handle, parentHandle, matrix); }
            virtual OverlayError setOverlayTransformOverlayRelative(uint64_t handle, uint64_t parentHandle, const Matrix34* matrix) { return Overlay_018::setOverlayTransformOverlayRelative(handle, parentHandle, matrix); }
            virtual OverlayError showOverlay(uint64_t handle) { return Overlay_018::showOverlay(handle); }
            virtual OverlayError hideOverlay(uint64_t handle) { return Overlay_018::hideOverlay(handle); }
            virtual bool isOverlayVisible(uint64_t handle) { return Overlay_018::isOverlayVisible(handle); }
            virtual OverlayError getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix) { return Overlay_018::getTransformForOverlayCoordinates(handle, origin, coordinatesInOverlay, matrix); }
            virtual bool pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t eventSize) { return Overlay_018::pollNextOverlayEvent(handle, event, eventSize); }
            virtual OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod) { return Overlay_018::getOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod) { return Overlay_018::setOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale) { return Overlay_018::getOverlayMouseScale(handle, mouseScale); }
            virtual OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale) { return Overlay_018::setOverlayMouseScale(handle, mouseScale); }
            virtual bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results) { return Overlay_018::computeOverlayIntersection(handle, params, results); }
            virtual bool isHoverTargetOverlay(uint64_t handle) { return Overlay_018::isHoverTargetOverlay(handle); }
            virtual uint64_t getGamepadFocusOverlay() { return Overlay_018::getGamepadFocusOverlay(); }
            virtual OverlayError setGamepadFocusOverlay(uint64_t handle) { return Overlay_018::setGamepadFocusOverlay(handle); }
            virtual OverlayError setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to) { return Overlay_018::setOverlayNeighbor(direction, from, to); }
            virtual OverlayError moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from) { return Overlay_018::moveGamepadFocusToNeighbor(direction, from); }
            virtual OverlayError setOverlayDualAnalogTransform(uint64_t handle, DualAnalogWhich which, const Vector2& center, float radius) { return Overlay_018::setOverlayDualAnalogTransform(handle, which, center, radius); }
            virtual OverlayError getOverlayDualAnalogTransform(uint64_t ulOverlay, DualAnalogWhich which, Vector2* center, float* radius) { return Overlay_018::getOverlayDualAnalogTransform(ulOverlay, which, center, radius); }
            virtual OverlayError setOverlayTexture(uint64_t handle, const Texture* texture) { return Overlay_018::setOverlayTexture(handle, texture); }
            virtual OverlayError clearOverlayTexture(uint64_t handle) { return Overlay_018::clearOverlayTexture(handle); }
            virtual OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth) { return Overlay_018::setOverlayRaw(handle, buffer, width, height, depth); }
            virtual OverlayError setOverlayFromFile(uint64_t handle, const char* filePath) { return Overlay_018::setOverlayFromFile(handle, filePath); }
            virtual OverlayError getOverlayNativeTexture(uint64_t handle, void** nativeTextureHandle, void* nativeTextureRef, uint32_t* width, uint32_t* height, uint32_t* format, TextureType* type, ColorSpace* colorSpace, TextureBounds* bounds) { return Overlay_018::getOverlayNativeTexture(handle, nativeTextureHandle, nativeTextureRef, width, height, format, type, colorSpace, bounds); }
            virtual OverlayError releaseNativeOverlayTexture(uint64_t handle, void* nativeTextureHandle) { return Overlay_018::releaseNativeOverlayTexture(handle, nativeTextureHandle); }
            virtual OverlayError getOverlayTextureSize(uint64_t handle, uint32_t* width, uint32_t* height) { return Overlay_018::getOverlayTextureSize(handle, width, height); }
            virtual OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle) { return Overlay_018::createDashboardOverlay(key, friendlyName, mainHandle, thumbnailHandle); }
            virtual bool isDashboardVisible() { return Overlay_018::isDashboardVisible(); }
            virtual bool isActiveDashboardOverlay(uint64_t handle) { return Overlay_018::isActiveDashboardOverlay(handle); }
            virtual OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid) { return Overlay_018::setDashboardOverlaySceneProcess(handle, pid); }
            virtual OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid) { return Overlay_018::getDashboardOverlaySceneProcess(handle, pid); }
            virtual void showDashboard(const char* overlayToShow) { return Overlay_018::showDashboard(overlayToShow); }
            virtual uint32_t getPrimaryDashboardInputTrackedDevice() { return Overlay_018::getPrimaryDashboardInputTrackedDevice(); }
            virtual OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_018::showKeyboard(textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_018::showKeyboardForOverlay(handle, textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual uint32_t getKeyboardText(char* text, uint32_t bufferSize) { return Overlay_018::getKeyboardText(text, bufferSize); }
            virtual void hideKeyboard() { return Overlay_018::hideKeyboard(); }
            virtual void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_018::setKeyboardTransformAbsolute(origin, matrix); }
            virtual void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect) { return Overlay_018::setKeyboardPositionForOverlay(handle, avoidRect); }
            virtual OverlayError setOverlayIntersectionMask(uint64_t handle, OverlayIntersectionMaskPrimitive* primitives, uint32_t primitivesCount, uint32_t primitiveSize) { return Overlay_018::setOverlayIntersectionMask(handle, primitives, primitivesCount, primitiveSize); }
            virtual OverlayError getOverlayFlags(uint64_t handle, uint32_t* flags) { return Overlay_018::getOverlayFlags(handle, flags); }
            virtual MessageOverlayResponse showMessageOverlay(const char* text, const char* caption, const char* button0Text, const char* button1Text, const char* button2Text, const char* button3Text) { return Overlay_018::showMessageOverlay(text, caption, button0Text, button1Text, button2Text, button3Text); }
            virtual void closeMessageOverlay() { return Overlay_018::closeMessageOverlay(); }
    };

    struct Overlay_019
    {
        static OverlayError findOverlay(const char* key, uint64_t* handle);

        static OverlayError createOverlay(const char* key, const char* name, uint64_t* handle);
        static OverlayError destroyOverlay(uint64_t handle);

        static OverlayError setHighQualityOverlay(uint64_t handle);
        static uint64_t getHighQualityOverlay();

        static uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static OverlayError setOverlayName(uint64_t handle, const char* name);

        static OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height);

        static const char* getOverlayErrorNameFromEnum(OverlayError error);

        static OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid);
        static uint32_t getOverlayRenderingPid(uint64_t handle);

        static OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled);
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flat, bool* enabled);
        static OverlayError setOverlayColor(uint64_t handle, float r, float g, float v);
        static OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b);
        static OverlayError setOverlayAlpha(uint64_t handle, float alpha);
        static OverlayError getOverlayAlpha(uint64_t handle, float* alpha);
        static OverlayError setOverlayTexelAspectRatio(uint64_t handle, float aspect);
        static OverlayError getOverlayTexelAspectRatio(uint64_t handle, float* aspect);

        static OverlayError setOverlaySortOrder(uint64_t handle, uint32_t sortOrder);
        static OverlayError getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder);
        static OverlayError setOverlayWidthInMeters(uint64_t handle, float width);
        static OverlayError getOverlayWidthInMeters(uint64_t handle, float* width);
        static OverlayError setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance);
        static OverlayError getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance);

        static OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace);
        static OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace);
        static OverlayError setOverlayTextureBounds(uint64_t handle, TextureBounds* bounds);
        static OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds);

        static uint32_t getOverlayRenderModel(uint64_t handle, char* renderModel, uint32_t bufferSize, Color* color, OverlayError* error);
        static OverlayError setOverlayRenderModel(uint64_t handle, const char* renderModel, const Color* color);

        static OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType);
        static OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix);
        static OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix);
        static OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName);
        static OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize);
        static OverlayError getOverlayTransformOverlayRelative(uint64_t handle, uint64_t* parentHandle, Matrix34* matrix);
        static OverlayError setOverlayTransformOverlayRelative(uint64_t handle, uint64_t parentHandle, const Matrix34* matrix);

        static OverlayError showOverlay(uint64_t handle);
        static OverlayError hideOverlay(uint64_t handle);
        static bool isOverlayVisible(uint64_t handle);

        static OverlayError getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix);

        static bool pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t eventSize);

        static OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod);
        static OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod);
        static OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale);
        static OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale);

        static bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results);

        static bool isHoverTargetOverlay(uint64_t handle);

        static uint64_t getGamepadFocusOverlay();
        static OverlayError setGamepadFocusOverlay(uint64_t handle);
        static OverlayError setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to);
        static OverlayError moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from);

        static OverlayError setOverlayDualAnalogTransform(uint64_t handle, DualAnalogWhich which, const Vector2* center, float radius);
        static OverlayError getOverlayDualAnalogTransform(uint64_t ulOverlay, DualAnalogWhich which, Vector2* center, float* radius);

        static OverlayError setOverlayTexture(uint64_t handle, const Texture* texture);
        static OverlayError clearOverlayTexture(uint64_t handle);

        static OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth);
        static OverlayError setOverlayFromFile(uint64_t handle, const char* filePath);

        static OverlayError getOverlayNativeTexture(uint64_t handle, void** nativeTextureHandle, void* nativeTextureRef, uint32_t* width, uint32_t* height, uint32_t* format, TextureType* type, ColorSpace* colorSpace, TextureBounds* bounds);
        static OverlayError releaseNativeOverlayTexture(uint64_t handle, void* nativeTextureHandle);

        static OverlayError getOverlayTextureSize(uint64_t handle, uint32_t* width, uint32_t* height);

        static OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle);

        static bool isDashboardVisible();
        static bool isActiveDashboardOverlay(uint64_t handle);

        static OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid);
        static OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid);

        static void showDashboard(const char* overlayToShow);

        static uint32_t getPrimaryDashboardInputTrackedDevice();

        static OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue);
        static OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue);
        static uint32_t getKeyboardText(char* text, uint32_t bufferSize);
        static void hideKeyboard();

        static void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix);
        static void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect);

        static OverlayError setOverlayIntersectionMask(uint64_t handle, OverlayIntersectionMaskPrimitive* primitives, uint32_t primitivesCount, uint32_t primitiveSize);

        static OverlayError getOverlayFlags(uint64_t handle, uint32_t* flags);

        static MessageOverlayResponse showMessageOverlay(const char* text, const char* caption, const char* button0Text, const char* button1Text, const char* button2Text, const char* button3Text);
        static void closeMessageOverlay();
    
        void* findOverlay_ = (void*) findOverlay;
        void* createOverlay_ = (void*) createOverlay;
        void* destroyOverlay_ = (void*) destroyOverlay;
        void* setHighQualityOverlay_ = (void*) setHighQualityOverlay;
        void* getHighQualityOverlay_ = (void*) getHighQualityOverlay;
        void* getOverlayKey_ = (void*) getOverlayKey;
        void* getOverlayName_ = (void*) getOverlayName;
        void* setOverlayName_ = (void*) setOverlayName;
        void* getOverlayImageData_ = (void*) getOverlayImageData;
        void* getOverlayErrorNameFromEnum_ = (void*) getOverlayErrorNameFromEnum;
        void* setOverlayRenderingPid_ = (void*) setOverlayRenderingPid;
        void* getOverlayRenderingPid_ = (void*) getOverlayRenderingPid;
        void* setOverlayFlag_ = (void*) setOverlayFlag;
        void* getOverlayFlag_ = (void*) getOverlayFlag;
        void* setOverlayColor_ = (void*) setOverlayColor;
        void* getOverlayColor_ = (void*) getOverlayColor;
        void* setOverlayAlpha_ = (void*) setOverlayAlpha;
        void* getOverlayAlpha_ = (void*) getOverlayAlpha;
        void* setOverlayTexelAspectRatio_ = (void*) setOverlayTexelAspectRatio;
        void* getOverlayTexelAspectRatio_ = (void*) getOverlayTexelAspectRatio;
        void* setOverlaySortOrder_ = (void*) setOverlaySortOrder;
        void* getOverlaySortOrder_ = (void*) getOverlaySortOrder;
        void* setOverlayWidthInMeters_ = (void*) setOverlayWidthInMeters;
        void* getOverlayWidthInMeters_ = (void*) getOverlayWidthInMeters;
        void* setOverlayAutoCurveDistanceRangeInMeters_ = (void*) setOverlayAutoCurveDistanceRangeInMeters;
        void* getOverlayAutoCurveDistanceRangeInMeters_ = (void*) getOverlayAutoCurveDistanceRangeInMeters;
        void* setOverlayTextureColorSpace_ = (void*) setOverlayTextureColorSpace;
        void* getOverlayTextureColorSpace_ = (void*) getOverlayTextureColorSpace;
        void* setOverlayTextureBounds_ = (void*) setOverlayTextureBounds;
        void* getOverlayTextureBounds_ = (void*) getOverlayTextureBounds;
        void* getOverlayRenderModel_ = (void*) getOverlayRenderModel;
        void* setOverlayRenderModel_ = (void*) setOverlayRenderModel;
        void* getOverlayTransformType_ = (void*) getOverlayTransformType;
        void* setOverlayTransformAbsolute_ = (void*) setOverlayTransformAbsolute;
        void* getOverlayTransformAbsolute_ = (void*) getOverlayTransformAbsolute;
        void* setOverlayTransformTrackedDeviceRelative_ = (void*) setOverlayTransformTrackedDeviceRelative;
        void* getOverlayTransformTrackedDeviceRelative_ = (void*) getOverlayTransformTrackedDeviceRelative;
        void* setOverlayTransformTrackedDeviceComponent_ = (void*) setOverlayTransformTrackedDeviceComponent;
        void* getOverlayTransformTrackedDeviceComponent_ = (void*) getOverlayTransformTrackedDeviceComponent;
        void* getOverlayTransformOverlayRelative_ = (void*) getOverlayTransformOverlayRelative;
        void* setOverlayTransformOverlayRelative_ = (void*) setOverlayTransformOverlayRelative;
        void* showOverlay_ = (void*) showOverlay;
        void* hideOverlay_ = (void*) hideOverlay;
        void* isOverlayVisible_ = (void*) isOverlayVisible;
        void* getTransformForOverlayCoordinates_ = (void*) getTransformForOverlayCoordinates;
        void* pollNextOverlayEvent_ = (void*) pollNextOverlayEvent;
        void* getOverlayInputMethod_ = (void*) getOverlayInputMethod;
        void* setOverlayInputMethod_ = (void*) setOverlayInputMethod;
        void* getOverlayMouseScale_ = (void*) getOverlayMouseScale;
        void* setOverlayMouseScale_ = (void*) setOverlayMouseScale;
        void* computeOverlayIntersection_ = (void*) computeOverlayIntersection;
        void* isHoverTargetOverlay_ = (void*) isHoverTargetOverlay;
        void* getGamepadFocusOverlay_ = (void*) getGamepadFocusOverlay;
        void* setGamepadFocusOverlay_ = (void*) setGamepadFocusOverlay;
        void* setOverlayNeighbor_ = (void*) setOverlayNeighbor;
        void* moveGamepadFocusToNeighbor_ = (void*) moveGamepadFocusToNeighbor;
        void* setOverlayDualAnalogTransform_ = (void*) setOverlayDualAnalogTransform;
        void* getOverlayDualAnalogTransform_ = (void*) getOverlayDualAnalogTransform;
        void* setOverlayTexture_ = (void*) setOverlayTexture;
        void* clearOverlayTexture_ = (void*) clearOverlayTexture;
        void* setOverlayRaw_ = (void*) setOverlayRaw;
        void* setOverlayFromFile_ = (void*) setOverlayFromFile;
        void* getOverlayNativeTexture_ = (void*) getOverlayNativeTexture;
        void* releaseNativeOverlayTexture_ = (void*) releaseNativeOverlayTexture;
        void* getOverlayTextureSize_ = (void*) getOverlayTextureSize;
        void* createDashboardOverlay_ = (void*) createDashboardOverlay;
        void* isDashboardVisible_ = (void*) isDashboardVisible;
        void* isActiveDashboardOverlay_ = (void*) isActiveDashboardOverlay;
        void* setDashboardOverlaySceneProcess_ = (void*) setDashboardOverlaySceneProcess;
        void* getDashboardOverlaySceneProcess_ = (void*) getDashboardOverlaySceneProcess;
        void* showDashboard_ = (void*) showDashboard;
        void* getPrimaryDashboardInputTrackedDevice_ = (void*) getPrimaryDashboardInputTrackedDevice;
        void* showKeyboard_ = (void*) showKeyboard;
        void* showKeyboardForOverlay_ = (void*) showKeyboardForOverlay;
        void* getKeyboardText_ = (void*) getKeyboardText;
        void* hideKeyboard_ = (void*) hideKeyboard;
        void* setKeyboardTransformAbsolute_ = (void*) setKeyboardTransformAbsolute;
        void* setKeyboardPositionForOverlay_ = (void*) setKeyboardPositionForOverlay;
        void* setOverlayIntersectionMask_ = (void*) setOverlayIntersectionMask;
        void* getOverlayFlags_ = (void*) getOverlayFlags;
        void* showMessageOverlay_ = (void*) showMessageOverlay;
        void* closeMessageOverlay_ = (void*) closeMessageOverlay;
    };

    class Overlay_019_v
    {
        public:
            virtual OverlayError findOverlay(const char* key, uint64_t* handle) { return Overlay_019::findOverlay(key, handle); }
            virtual OverlayError createOverlay(const char* key, const char* name, uint64_t* handle) { return Overlay_019::createOverlay(key, name, handle); }
            virtual OverlayError destroyOverlay(uint64_t handle) { return Overlay_019::destroyOverlay(handle); }
            virtual OverlayError setHighQualityOverlay(uint64_t handle) { return Overlay_019::setHighQualityOverlay(handle); }
            virtual uint64_t getHighQualityOverlay() { return Overlay_019::getHighQualityOverlay(); }
            virtual uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_019::getOverlayKey(handle, value, bufferSize, error); }
            virtual uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_019::getOverlayName(handle, value, bufferSize, error); }
            virtual OverlayError setOverlayName(uint64_t handle, const char* name) { return Overlay_019::setOverlayName(handle, name); }
            virtual OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height) { return Overlay_019::getOverlayImageData(handle, buffer, bufferSize, width, height); }
            virtual const char* getOverlayErrorNameFromEnum(OverlayError error) { return Overlay_019::getOverlayErrorNameFromEnum(error); }
            virtual OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid) { return Overlay_019::setOverlayRenderingPid(handle, pid); }
            virtual uint32_t getOverlayRenderingPid(uint64_t handle) { return Overlay_019::getOverlayRenderingPid(handle); }
            virtual OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled) { return Overlay_019::setOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flat, bool* enabled) { return Overlay_019::getOverlayFlag(handle, flat, enabled); }
            virtual OverlayError setOverlayColor(uint64_t handle, float r, float g, float v) { return Overlay_019::setOverlayColor(handle, r, g, v); }
            virtual OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b) { return Overlay_019::getOverlayColor(handle, r, g, b); }
            virtual OverlayError setOverlayAlpha(uint64_t handle, float alpha) { return Overlay_019::setOverlayAlpha(handle, alpha); }
            virtual OverlayError getOverlayAlpha(uint64_t handle, float* alpha) { return Overlay_019::getOverlayAlpha(handle, alpha); }
            virtual OverlayError setOverlayTexelAspectRatio(uint64_t handle, float aspect) { return Overlay_019::setOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError getOverlayTexelAspectRatio(uint64_t handle, float* aspect) { return Overlay_019::getOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError setOverlaySortOrder(uint64_t handle, uint32_t sortOrder) { return Overlay_019::setOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder) { return Overlay_019::getOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError setOverlayWidthInMeters(uint64_t handle, float width) { return Overlay_019::setOverlayWidthInMeters(handle, width); }
            virtual OverlayError getOverlayWidthInMeters(uint64_t handle, float* width) { return Overlay_019::getOverlayWidthInMeters(handle, width); }
            virtual OverlayError setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance) { return Overlay_019::setOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance) { return Overlay_019::getOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace) { return Overlay_019::setOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace) { return Overlay_019::getOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_019::setOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_019::getOverlayTextureBounds(handle, bounds); }
            virtual uint32_t getOverlayRenderModel(uint64_t handle, char* renderModel, uint32_t bufferSize, Color* color, OverlayError* error) { return Overlay_019::getOverlayRenderModel(handle, renderModel, bufferSize, color, error); }
            virtual OverlayError setOverlayRenderModel(uint64_t handle, const char* renderModel, const Color* color) { return Overlay_019::setOverlayRenderModel(handle, renderModel, color); }
            virtual OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType) { return Overlay_019::getOverlayTransformType(handle, transformType); }
            virtual OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_019::setOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix) { return Overlay_019::getOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix) { return Overlay_019::setOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix) { return Overlay_019::getOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName) { return Overlay_019::setOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName); }
            virtual OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize) { return Overlay_019::getOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName, bufferSize); }
            virtual OverlayError getOverlayTransformOverlayRelative(uint64_t handle, uint64_t* parentHandle, Matrix34* matrix) { return Overlay_019::getOverlayTransformOverlayRelative(handle, parentHandle, matrix); }
            virtual OverlayError setOverlayTransformOverlayRelative(uint64_t handle, uint64_t parentHandle, const Matrix34* matrix) { return Overlay_019::setOverlayTransformOverlayRelative(handle, parentHandle, matrix); }
            virtual OverlayError showOverlay(uint64_t handle) { return Overlay_019::showOverlay(handle); }
            virtual OverlayError hideOverlay(uint64_t handle) { return Overlay_019::hideOverlay(handle); }
            virtual bool isOverlayVisible(uint64_t handle) { return Overlay_019::isOverlayVisible(handle); }
            virtual OverlayError getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix) { return Overlay_019::getTransformForOverlayCoordinates(handle, origin, coordinatesInOverlay, matrix); }
            virtual bool pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t eventSize) { return Overlay_019::pollNextOverlayEvent(handle, event, eventSize); }
            virtual OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod) { return Overlay_019::getOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod) { return Overlay_019::setOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale) { return Overlay_019::getOverlayMouseScale(handle, mouseScale); }
            virtual OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale) { return Overlay_019::setOverlayMouseScale(handle, mouseScale); }
            virtual bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results) { return Overlay_019::computeOverlayIntersection(handle, params, results); }
            virtual bool isHoverTargetOverlay(uint64_t handle) { return Overlay_019::isHoverTargetOverlay(handle); }
            virtual uint64_t getGamepadFocusOverlay() { return Overlay_019::getGamepadFocusOverlay(); }
            virtual OverlayError setGamepadFocusOverlay(uint64_t handle) { return Overlay_019::setGamepadFocusOverlay(handle); }
            virtual OverlayError setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to) { return Overlay_019::setOverlayNeighbor(direction, from, to); }
            virtual OverlayError moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from) { return Overlay_019::moveGamepadFocusToNeighbor(direction, from); }
            virtual OverlayError setOverlayDualAnalogTransform(uint64_t handle, DualAnalogWhich which, const Vector2* center, float radius) { return Overlay_019::setOverlayDualAnalogTransform(handle, which, center, radius); }
            virtual OverlayError getOverlayDualAnalogTransform(uint64_t ulOverlay, DualAnalogWhich which, Vector2* center, float* radius) { return Overlay_019::getOverlayDualAnalogTransform(ulOverlay, which, center, radius); }
            virtual OverlayError setOverlayTexture(uint64_t handle, const Texture* texture) { return Overlay_019::setOverlayTexture(handle, texture); }
            virtual OverlayError clearOverlayTexture(uint64_t handle) { return Overlay_019::clearOverlayTexture(handle); }
            virtual OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth) { return Overlay_019::setOverlayRaw(handle, buffer, width, height, depth); }
            virtual OverlayError setOverlayFromFile(uint64_t handle, const char* filePath) { return Overlay_019::setOverlayFromFile(handle, filePath); }
            virtual OverlayError getOverlayNativeTexture(uint64_t handle, void** nativeTextureHandle, void* nativeTextureRef, uint32_t* width, uint32_t* height, uint32_t* format, TextureType* type, ColorSpace* colorSpace, TextureBounds* bounds) { return Overlay_019::getOverlayNativeTexture(handle, nativeTextureHandle, nativeTextureRef, width, height, format, type, colorSpace, bounds); }
            virtual OverlayError releaseNativeOverlayTexture(uint64_t handle, void* nativeTextureHandle) { return Overlay_019::releaseNativeOverlayTexture(handle, nativeTextureHandle); }
            virtual OverlayError getOverlayTextureSize(uint64_t handle, uint32_t* width, uint32_t* height) { return Overlay_019::getOverlayTextureSize(handle, width, height); }
            virtual OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle) { return Overlay_019::createDashboardOverlay(key, friendlyName, mainHandle, thumbnailHandle); }
            virtual bool isDashboardVisible() { return Overlay_019::isDashboardVisible(); }
            virtual bool isActiveDashboardOverlay(uint64_t handle) { return Overlay_019::isActiveDashboardOverlay(handle); }
            virtual OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid) { return Overlay_019::setDashboardOverlaySceneProcess(handle, pid); }
            virtual OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid) { return Overlay_019::getDashboardOverlaySceneProcess(handle, pid); }
            virtual void showDashboard(const char* overlayToShow) { return Overlay_019::showDashboard(overlayToShow); }
            virtual uint32_t getPrimaryDashboardInputTrackedDevice() { return Overlay_019::getPrimaryDashboardInputTrackedDevice(); }
            virtual OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_019::showKeyboard(textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_019::showKeyboardForOverlay(handle, textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual uint32_t getKeyboardText(char* text, uint32_t bufferSize) { return Overlay_019::getKeyboardText(text, bufferSize); }
            virtual void hideKeyboard() { return Overlay_019::hideKeyboard(); }
            virtual void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_019::setKeyboardTransformAbsolute(origin, matrix); }
            virtual void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect) { return Overlay_019::setKeyboardPositionForOverlay(handle, avoidRect); }
            virtual OverlayError setOverlayIntersectionMask(uint64_t handle, OverlayIntersectionMaskPrimitive* primitives, uint32_t primitivesCount, uint32_t primitiveSize) { return Overlay_019::setOverlayIntersectionMask(handle, primitives, primitivesCount, primitiveSize); }
            virtual OverlayError getOverlayFlags(uint64_t handle, uint32_t* flags) { return Overlay_019::getOverlayFlags(handle, flags); }
            virtual MessageOverlayResponse showMessageOverlay(const char* text, const char* caption, const char* button0Text, const char* button1Text, const char* button2Text, const char* button3Text) { return Overlay_019::showMessageOverlay(text, caption, button0Text, button1Text, button2Text, button3Text); }
            virtual void closeMessageOverlay() { return Overlay_019::closeMessageOverlay(); }
    };
}
