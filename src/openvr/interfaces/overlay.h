#pragma once

#include "../types.h"
#include <cstdint>

namespace openvr
{
    struct Overlay_001
    {
        static OverlayError findOverlay(const char* key, uint64_t* handle);

        static OverlayError createOverlay(const char* key, const char* name, uint64_t* handle);
        static OverlayError destroyOverlay(uint64_t handle);

        static OverlayError setHighQualityOverlay(uint64_t handle);
        static uint64_t getHighQualityOverlay();

        static const char* getOverlayErrorNameFromEnum(OverlayError error);

        static OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled);
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled);
        static OverlayError setOverlayAlpha(uint64_t handle, float alpha);
        static OverlayError getOverlayAlpha(uint64_t handle, float* alpha);
        static OverlayError setOverlayGamma(uint64_t handle, float gamma);
        static OverlayError getOverlayGamma(uint64_t handle, float* gamma);

        static OverlayError setOverlayWidthInMeters(uint64_t handle, float width);
        static OverlayError getOverlayWidthInMeters(uint64_t handle, float* width);

        static OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds);
        static OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds);

        static OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType);
        static OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix);
        static OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix);
        static OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix);

        static OverlayError getOverlayVisibility(uint64_t handle, OverlayVisibilityLegacy* visibility);
        static OverlayError setOverlayVisibility(uint64_t handle, OverlayVisibilityLegacy visibility);
        static OverlayError showOverlay(uint64_t handle);
        static OverlayError hideOverlay(uint64_t handle);
        static bool isOverlayVisible(uint64_t handle);

        static bool pollNextOverlayEvent(uint64_t handle, Event_0_9_0* event);

        static OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod);
        static OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod);
        static OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale);
        static OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale);

        static bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results);
        static bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex);

        static OverlayError setOverlayTexture(uint64_t handle, void* texture);
        static OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth);
        static OverlayError setOverlayFromFile(uint64_t handle, const char* filePath);

        static bool isSystemOverlayVisible();
        static bool isActiveSystemOverlay(uint64_t handle);
        static OverlayError setSystemOverlaySceneProcess(uint64_t handle, uint32_t pid);
        static OverlayError getSystemOverlaySceneProcess(uint64_t handle, uint32_t* pid);

        void* findOverlay_ = (void*) findOverlay;
        void* createOverlay_ = (void*) createOverlay;
        void* destroyOverlay_ = (void*) destroyOverlay;
        void* setHighQualityOverlay_ = (void*) setHighQualityOverlay;
        void* getHighQualityOverlay_ = (void*) getHighQualityOverlay;
        void* getOverlayErrorNameFromEnum_ = (void*) getOverlayErrorNameFromEnum;
        void* setOverlayFlag_ = (void*) setOverlayFlag;
        void* getOverlayFlag_ = (void*) getOverlayFlag;
        void* setOverlayAlpha_ = (void*) setOverlayAlpha;
        void* getOverlayAlpha_ = (void*) getOverlayAlpha;
        void* setOverlayGamma_ = (void*) setOverlayGamma;
        void* getOverlayGamma_ = (void*) getOverlayGamma;
        void* setOverlayWidthInMeters_ = (void*) setOverlayWidthInMeters;
        void* getOverlayWidthInMeters_ = (void*) getOverlayWidthInMeters;
        void* setOverlayTextureBounds_ = (void*) setOverlayTextureBounds;
        void* getOverlayTextureBounds_ = (void*) getOverlayTextureBounds;
        void* getOverlayTransformType_ = (void*) getOverlayTransformType;
        void* setOverlayTransformAbsolute_ = (void*) setOverlayTransformAbsolute;
        void* getOverlayTransformAbsolute_ = (void*) getOverlayTransformAbsolute;
        void* setOverlayTransformTrackedDeviceRelative_ = (void*) setOverlayTransformTrackedDeviceRelative;
        void* getOverlayTransformTrackedDeviceRelative_ = (void*) getOverlayTransformTrackedDeviceRelative;
        void* getOverlayVisibility_ = (void*) getOverlayVisibility;
        void* setOverlayVisibility_ = (void*) setOverlayVisibility;
        void* showOverlay_ = (void*) showOverlay;
        void* hideOverlay_ = (void*) hideOverlay;
        void* isOverlayVisible_ = (void*) isOverlayVisible;
        void* pollNextOverlayEvent_ = (void*) pollNextOverlayEvent;
        void* getOverlayInputMethod_ = (void*) getOverlayInputMethod;
        void* setOverlayInputMethod_ = (void*) setOverlayInputMethod;
        void* getOverlayMouseScale_ = (void*) getOverlayMouseScale;
        void* setOverlayMouseScale_ = (void*) setOverlayMouseScale;
        void* computeOverlayIntersection_ = (void*) computeOverlayIntersection;
        void* handleControllerOverlayInteractionAsMouse_ = (void*) handleControllerOverlayInteractionAsMouse;
        void* setOverlayTexture_ = (void*) setOverlayTexture;
        void* setOverlayRaw_ = (void*) setOverlayRaw;
        void* setOverlayFromFile_ = (void*) setOverlayFromFile;
        void* isSystemOverlayVisible_ = (void*) isSystemOverlayVisible;
        void* isActiveSystemOverlay_ = (void*) isActiveSystemOverlay;
        void* setSystemOverlaySceneProcess_ = (void*) setSystemOverlaySceneProcess;
        void* getSystemOverlaySceneProcess_ = (void*) getSystemOverlaySceneProcess;
    };

    class Overlay_001_v
    {
        public:
            virtual OverlayError findOverlay(const char* key, uint64_t* handle) { return Overlay_001::findOverlay(key, handle); }
            virtual OverlayError createOverlay(const char* key, const char* name, uint64_t* handle) { return Overlay_001::createOverlay(key, name, handle); }
            virtual OverlayError destroyOverlay(uint64_t handle) { return Overlay_001::destroyOverlay(handle); }
            virtual OverlayError setHighQualityOverlay(uint64_t handle) { return Overlay_001::setHighQualityOverlay(handle); }
            virtual uint64_t getHighQualityOverlay() { return Overlay_001::getHighQualityOverlay(); }
            virtual const char* getOverlayErrorNameFromEnum(OverlayError error) { return Overlay_001::getOverlayErrorNameFromEnum(error); }
            virtual OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled) { return Overlay_001::setOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled) { return Overlay_001::getOverlayFlag(handle, flag, enabled); }
            virtual OverlayError setOverlayAlpha(uint64_t handle, float alpha) { return Overlay_001::setOverlayAlpha(handle, alpha); }
            virtual OverlayError getOverlayAlpha(uint64_t handle, float* alpha) { return Overlay_001::getOverlayAlpha(handle, alpha); }
            virtual OverlayError setOverlayGamma(uint64_t handle, float gamma) { return Overlay_001::setOverlayGamma(handle, gamma); }
            virtual OverlayError getOverlayGamma(uint64_t handle, float* gamma) { return Overlay_001::getOverlayGamma(handle, gamma); }
            virtual OverlayError setOverlayWidthInMeters(uint64_t handle, float width) { return Overlay_001::setOverlayWidthInMeters(handle, width); }
            virtual OverlayError getOverlayWidthInMeters(uint64_t handle, float* width) { return Overlay_001::getOverlayWidthInMeters(handle, width); }
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds) { return Overlay_001::setOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_001::getOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType) { return Overlay_001::getOverlayTransformType(handle, transformType); }
            virtual OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_001::setOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix) { return Overlay_001::getOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix) { return Overlay_001::setOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix) { return Overlay_001::getOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError getOverlayVisibility(uint64_t handle, OverlayVisibilityLegacy* visibility) { return Overlay_001::getOverlayVisibility(handle, visibility); }
            virtual OverlayError setOverlayVisibility(uint64_t handle, OverlayVisibilityLegacy visibility) { return Overlay_001::setOverlayVisibility(handle, visibility); }
            virtual OverlayError showOverlay(uint64_t handle) { return Overlay_001::showOverlay(handle); }
            virtual OverlayError hideOverlay(uint64_t handle) { return Overlay_001::hideOverlay(handle); }
            virtual bool isOverlayVisible(uint64_t handle) { return Overlay_001::isOverlayVisible(handle); }
            virtual bool pollNextOverlayEvent(uint64_t handle, Event_0_9_0* event) { return Overlay_001::pollNextOverlayEvent(handle, event); }
            virtual OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod) { return Overlay_001::getOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod) { return Overlay_001::setOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale) { return Overlay_001::getOverlayMouseScale(handle, mouseScale); }
            virtual OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale) { return Overlay_001::setOverlayMouseScale(handle, mouseScale); }
            virtual bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results) { return Overlay_001::computeOverlayIntersection(handle, params, results); }
            virtual bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex) { return Overlay_001::handleControllerOverlayInteractionAsMouse(handle, controllerDeviceIndex); }
            virtual OverlayError setOverlayTexture(uint64_t handle, void* texture) { return Overlay_001::setOverlayTexture(handle, texture); }
            virtual OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth) { return Overlay_001::setOverlayRaw(handle, buffer, width, height, depth); }
            virtual OverlayError setOverlayFromFile(uint64_t handle, const char* filePath) { return Overlay_001::setOverlayFromFile(handle, filePath); }
            virtual bool isSystemOverlayVisible() { return Overlay_001::isSystemOverlayVisible(); }
            virtual bool isActiveSystemOverlay(uint64_t handle) { return Overlay_001::isActiveSystemOverlay(handle); }
            virtual OverlayError setSystemOverlaySceneProcess(uint64_t handle, uint32_t pid) { return Overlay_001::setSystemOverlaySceneProcess(handle, pid); }
            virtual OverlayError getSystemOverlaySceneProcess(uint64_t handle, uint32_t* pid) { return Overlay_001::getSystemOverlaySceneProcess(handle, pid); }
    };

    //

    struct Overlay_002
    {
        static OverlayError findOverlay(const char* key, uint64_t* handle);

        static OverlayError createOverlay(const char* key, const char* name, uint64_t* handle);
        static OverlayError destroyOverlay(uint64_t handle);

        static OverlayError setHighQualityOverlay(uint64_t handle);
        static uint64_t getHighQualityOverlay();

        static const char* getOverlayErrorNameFromEnum(OverlayError error);

        static OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled);
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled);
        static OverlayError setOverlayColor(uint64_t handle, float r, float g, float b);
        static OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b);
        static OverlayError setOverlayAlpha(uint64_t handle, float alpha);
        static OverlayError getOverlayAlpha(uint64_t handle, float* alpha);
        static OverlayError setOverlayGamma(uint64_t handle, float gamma);
        static OverlayError getOverlayGamma(uint64_t handle, float* gamma);

        static OverlayError setOverlayWidthInMeters(uint64_t handle, float width);
        static OverlayError getOverlayWidthInMeters(uint64_t handle, float* width);

        static OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds);
        static OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds);

        static OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType);
        static OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix);
        static OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix);
        static OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix);

        static OverlayError showOverlay(uint64_t handle);
        static OverlayError hideOverlay(uint64_t handle);
        static bool isOverlayVisible(uint64_t handle);

        static bool pollNextOverlayEvent(uint64_t handle, Event_0_9_0* event);

        static OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod);
        static OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod);
        static OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale);
        static OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale);

        static bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results);
        static bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex);

        static OverlayError setOverlayTexture(uint64_t handle, TextureType textureType, void* texture);
        static OverlayError clearOverlayTexture(uint64_t handle);
        static OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth);
        static OverlayError setOverlayFromFile(uint64_t handle, const char* filePath);

        static OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle);
        static bool isDashboardVisible();
        static bool isActiveDashboardOverlay(uint64_t handle);
        static OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid);
        static OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid);

        void* findOverlay_ = (void*) findOverlay;
        void* createOverlay_ = (void*) createOverlay;
        void* destroyOverlay_ = (void*) destroyOverlay;
        void* setHighQualityOverlay_ = (void*) setHighQualityOverlay;
        void* getHighQualityOverlay_ = (void*) getHighQualityOverlay;
        void* getOverlayErrorNameFromEnum_ = (void*) getOverlayErrorNameFromEnum;
        void* setOverlayFlag_ = (void*) setOverlayFlag;
        void* getOverlayFlag_ = (void*) getOverlayFlag;
        void* setOverlayColor_ = (void*) setOverlayColor;
        void* getOverlayColor_ = (void*) getOverlayColor;
        void* setOverlayAlpha_ = (void*) setOverlayAlpha;
        void* getOverlayAlpha_ = (void*) getOverlayAlpha;
        void* setOverlayGamma_ = (void*) setOverlayGamma;
        void* getOverlayGamma_ = (void*) getOverlayGamma;
        void* setOverlayWidthInMeters_ = (void*) setOverlayWidthInMeters;
        void* getOverlayWidthInMeters_ = (void*) getOverlayWidthInMeters;
        void* setOverlayTextureBounds_ = (void*) setOverlayTextureBounds;
        void* getOverlayTextureBounds_ = (void*) getOverlayTextureBounds;
        void* getOverlayTransformType_ = (void*) getOverlayTransformType;
        void* setOverlayTransformAbsolute_ = (void*) setOverlayTransformAbsolute;
        void* getOverlayTransformAbsolute_ = (void*) getOverlayTransformAbsolute;
        void* setOverlayTransformTrackedDeviceRelative_ = (void*) setOverlayTransformTrackedDeviceRelative;
        void* getOverlayTransformTrackedDeviceRelative_ = (void*) getOverlayTransformTrackedDeviceRelative;
        void* showOverlay_ = (void*) showOverlay;
        void* hideOverlay_ = (void*) hideOverlay;
        void* isOverlayVisible_ = (void*) isOverlayVisible;
        void* pollNextOverlayEvent_ = (void*) pollNextOverlayEvent;
        void* getOverlayInputMethod_ = (void*) getOverlayInputMethod;
        void* setOverlayInputMethod_ = (void*) setOverlayInputMethod;
        void* getOverlayMouseScale_ = (void*) getOverlayMouseScale;
        void* setOverlayMouseScale_ = (void*) setOverlayMouseScale;
        void* computeOverlayIntersection_ = (void*) computeOverlayIntersection;
        void* handleControllerOverlayInteractionAsMouse_ = (void*) handleControllerOverlayInteractionAsMouse;
        void* setOverlayTexture_ = (void*) setOverlayTexture;
        void* clearOverlayTexture_ = (void*) clearOverlayTexture;
        void* setOverlayRaw_ = (void*) setOverlayRaw;
        void* setOverlayFromFile_ = (void*) setOverlayFromFile;
        void* createDashboardOverlay_ = (void*) createDashboardOverlay;
        void* isDashboardVisible_ = (void*) isDashboardVisible;
        void* isActiveDashboardOverlay_ = (void*) isActiveDashboardOverlay;
        void* setDashboardOverlaySceneProcess_ = (void*) setDashboardOverlaySceneProcess;
        void* getDashboardOverlaySceneProcess_ = (void*) getDashboardOverlaySceneProcess;
    };

    class Overlay_002_v
    {
        public:
            virtual OverlayError findOverlay(const char* key, uint64_t* handle) { return Overlay_002::findOverlay(key, handle); }
            virtual OverlayError createOverlay(const char* key, const char* name, uint64_t* handle) { return Overlay_002::createOverlay(key, name, handle); }
            virtual OverlayError destroyOverlay(uint64_t handle) { return Overlay_002::destroyOverlay(handle); }
            virtual OverlayError setHighQualityOverlay(uint64_t handle) { return Overlay_002::setHighQualityOverlay(handle); }
            virtual uint64_t getHighQualityOverlay() { return Overlay_002::getHighQualityOverlay(); }
            virtual const char* getOverlayErrorNameFromEnum(OverlayError error) { return Overlay_002::getOverlayErrorNameFromEnum(error); }
            virtual OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled) { return Overlay_002::setOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled) { return Overlay_002::getOverlayFlag(handle, flag, enabled); }
            virtual OverlayError setOverlayColor(uint64_t handle, float r, float g, float b) { return Overlay_002::setOverlayColor(handle, r, g, b); }
            virtual OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b) { return Overlay_002::getOverlayColor(handle, r, g, b); }
            virtual OverlayError setOverlayAlpha(uint64_t handle, float alpha) { return Overlay_002::setOverlayAlpha(handle, alpha); }
            virtual OverlayError getOverlayAlpha(uint64_t handle, float* alpha) { return Overlay_002::getOverlayAlpha(handle, alpha); }
            virtual OverlayError setOverlayGamma(uint64_t handle, float gamma) { return Overlay_002::setOverlayGamma(handle, gamma); }
            virtual OverlayError getOverlayGamma(uint64_t handle, float* gamma) { return Overlay_002::getOverlayGamma(handle, gamma); }
            virtual OverlayError setOverlayWidthInMeters(uint64_t handle, float width) { return Overlay_002::setOverlayWidthInMeters(handle, width); }
            virtual OverlayError getOverlayWidthInMeters(uint64_t handle, float* width) { return Overlay_002::getOverlayWidthInMeters(handle, width); }
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds) { return Overlay_002::setOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_002::getOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType) { return Overlay_002::getOverlayTransformType(handle, transformType); }
            virtual OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_002::setOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix) { return Overlay_002::getOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix) { return Overlay_002::setOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix) { return Overlay_002::getOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError showOverlay(uint64_t handle) { return Overlay_002::showOverlay(handle); }
            virtual OverlayError hideOverlay(uint64_t handle) { return Overlay_002::hideOverlay(handle); }
            virtual bool isOverlayVisible(uint64_t handle) { return Overlay_002::isOverlayVisible(handle); }
            virtual bool pollNextOverlayEvent(uint64_t handle, Event_0_9_0* event) { return Overlay_002::pollNextOverlayEvent(handle, event); }
            virtual OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod) { return Overlay_002::getOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod) { return Overlay_002::setOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale) { return Overlay_002::getOverlayMouseScale(handle, mouseScale); }
            virtual OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale) { return Overlay_002::setOverlayMouseScale(handle, mouseScale); }
            virtual bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results) { return Overlay_002::computeOverlayIntersection(handle, params, results); }
            virtual bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex) { return Overlay_002::handleControllerOverlayInteractionAsMouse(handle, controllerDeviceIndex); }
            virtual OverlayError setOverlayTexture(uint64_t handle, TextureType textureType, void* texture) { return Overlay_002::setOverlayTexture(handle, textureType, texture); }
            virtual OverlayError clearOverlayTexture(uint64_t handle) { return Overlay_002::clearOverlayTexture(handle); }
            virtual OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth) { return Overlay_002::setOverlayRaw(handle, buffer, width, height, depth); }
            virtual OverlayError setOverlayFromFile(uint64_t handle, const char* filePath) { return Overlay_002::setOverlayFromFile(handle, filePath); }
            virtual OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle) { return Overlay_002::createDashboardOverlay(key, friendlyName, mainHandle, thumbnailHandle); }
            virtual bool isDashboardVisible() { return Overlay_002::isDashboardVisible(); }
            virtual bool isActiveDashboardOverlay(uint64_t handle) { return Overlay_002::isActiveDashboardOverlay(handle); }
            virtual OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid) { return Overlay_002::setDashboardOverlaySceneProcess(handle, pid); }
            virtual OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid) { return Overlay_002::getDashboardOverlaySceneProcess(handle, pid); }
    };

    //

    struct Overlay_003
    {
        static OverlayError findOverlay(const char* key, uint64_t* handle);

        static OverlayError createOverlay(const char* key, const char* name, uint64_t* handle);
        static OverlayError destroyOverlay(uint64_t handle);

        static OverlayError setHighQualityOverlay(uint64_t handle);
        static uint64_t getHighQualityOverlay();

        static uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height);

        static const char* getOverlayErrorNameFromEnum(OverlayError error);

        static OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled);
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled);
        static OverlayError setOverlayColor(uint64_t handle, float r, float g, float b);
        static OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b);
        static OverlayError setOverlayAlpha(uint64_t handle, float alpha);
        static OverlayError getOverlayAlpha(uint64_t handle, float* alpha);
        static OverlayError setOverlayGamma(uint64_t handle, float gamma);
        static OverlayError getOverlayGamma(uint64_t handle, float* gamma);

        static OverlayError setOverlayWidthInMeters(uint64_t handle, float width);
        static OverlayError getOverlayWidthInMeters(uint64_t handle, float* width);

        static OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds);
        static OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds);

        static OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType);
        static OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix);
        static OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix);
        static OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix);

        static OverlayError showOverlay(uint64_t handle);
        static OverlayError hideOverlay(uint64_t handle);
        static bool isOverlayVisible(uint64_t handle);

        static bool pollNextOverlayEvent(uint64_t handle, Event_0_9_0* event);

        static OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod);
        static OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod);
        static OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale);
        static OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale);

        static bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results);
        static bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex);

        static OverlayError setOverlayTexture(uint64_t handle, TextureType textureType, void* texture);
        static OverlayError clearOverlayTexture(uint64_t handle);
        static OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth);
        static OverlayError setOverlayFromFile(uint64_t handle, const char* filePath);

        static OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle);
        static bool isDashboardVisible();
        static bool isActiveDashboardOverlay(uint64_t handle);
        static OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid);
        static OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid);
        static void showDashboard(const char* overlayToShow);

        void* findOverlay_ = (void*) findOverlay;
        void* createOverlay_ = (void*) createOverlay;
        void* destroyOverlay_ = (void*) destroyOverlay;
        void* setHighQualityOverlay_ = (void*) setHighQualityOverlay;
        void* getHighQualityOverlay_ = (void*) getHighQualityOverlay;
        void* getOverlayKey_ = (void*) getOverlayKey;
        void* getOverlayName_ = (void*) getOverlayName;
        void* getOverlayImageData_ = (void*) getOverlayImageData;
        void* getOverlayErrorNameFromEnum_ = (void*) getOverlayErrorNameFromEnum;
        void* setOverlayFlag_ = (void*) setOverlayFlag;
        void* getOverlayFlag_ = (void*) getOverlayFlag;
        void* setOverlayColor_ = (void*) setOverlayColor;
        void* getOverlayColor_ = (void*) getOverlayColor;
        void* setOverlayAlpha_ = (void*) setOverlayAlpha;
        void* getOverlayAlpha_ = (void*) getOverlayAlpha;
        void* setOverlayGamma_ = (void*) setOverlayGamma;
        void* getOverlayGamma_ = (void*) getOverlayGamma;
        void* setOverlayWidthInMeters_ = (void*) setOverlayWidthInMeters;
        void* getOverlayWidthInMeters_ = (void*) getOverlayWidthInMeters;
        void* setOverlayTextureBounds_ = (void*) setOverlayTextureBounds;
        void* getOverlayTextureBounds_ = (void*) getOverlayTextureBounds;
        void* getOverlayTransformType_ = (void*) getOverlayTransformType;
        void* setOverlayTransformAbsolute_ = (void*) setOverlayTransformAbsolute;
        void* getOverlayTransformAbsolute_ = (void*) getOverlayTransformAbsolute;
        void* setOverlayTransformTrackedDeviceRelative_ = (void*) setOverlayTransformTrackedDeviceRelative;
        void* getOverlayTransformTrackedDeviceRelative_ = (void*) getOverlayTransformTrackedDeviceRelative;
        void* showOverlay_ = (void*) showOverlay;
        void* hideOverlay_ = (void*) hideOverlay;
        void* isOverlayVisible_ = (void*) isOverlayVisible;
        void* pollNextOverlayEvent_ = (void*) pollNextOverlayEvent;
        void* getOverlayInputMethod_ = (void*) getOverlayInputMethod;
        void* setOverlayInputMethod_ = (void*) setOverlayInputMethod;
        void* getOverlayMouseScale_ = (void*) getOverlayMouseScale;
        void* setOverlayMouseScale_ = (void*) setOverlayMouseScale;
        void* computeOverlayIntersection_ = (void*) computeOverlayIntersection;
        void* handleControllerOverlayInteractionAsMouse_ = (void*) handleControllerOverlayInteractionAsMouse;
        void* setOverlayTexture_ = (void*) setOverlayTexture;
        void* clearOverlayTexture_ = (void*) clearOverlayTexture;
        void* setOverlayRaw_ = (void*) setOverlayRaw;
        void* setOverlayFromFile_ = (void*) setOverlayFromFile;
        void* createDashboardOverlay_ = (void*) createDashboardOverlay;
        void* isDashboardVisible_ = (void*) isDashboardVisible;
        void* isActiveDashboardOverlay_ = (void*) isActiveDashboardOverlay;
        void* setDashboardOverlaySceneProcess_ = (void*) setDashboardOverlaySceneProcess;
        void* getDashboardOverlaySceneProcess_ = (void*) getDashboardOverlaySceneProcess;
        void* showDashboard_ = (void*) showDashboard;
    };

    class Overlay_003_v
    {
        public:
            virtual OverlayError findOverlay(const char* key, uint64_t* handle) { return Overlay_003::findOverlay(key, handle); }
            virtual OverlayError createOverlay(const char* key, const char* name, uint64_t* handle) { return Overlay_003::createOverlay(key, name, handle); }
            virtual OverlayError destroyOverlay(uint64_t handle) { return Overlay_003::destroyOverlay(handle); }
            virtual OverlayError setHighQualityOverlay(uint64_t handle) { return Overlay_003::setHighQualityOverlay(handle); }
            virtual uint64_t getHighQualityOverlay() { return Overlay_003::getHighQualityOverlay(); }
            virtual uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_003::getOverlayKey(handle, value, bufferSize, error); }
            virtual uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_003::getOverlayName(handle, value, bufferSize, error); }
            virtual OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height) { return Overlay_003::getOverlayImageData(handle, buffer, bufferSize, width, height); }
            virtual const char* getOverlayErrorNameFromEnum(OverlayError error) { return Overlay_003::getOverlayErrorNameFromEnum(error); }
            virtual OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled) { return Overlay_003::setOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled) { return Overlay_003::getOverlayFlag(handle, flag, enabled); }
            virtual OverlayError setOverlayColor(uint64_t handle, float r, float g, float b) { return Overlay_003::setOverlayColor(handle, r, g, b); }
            virtual OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b) { return Overlay_003::getOverlayColor(handle, r, g, b); }
            virtual OverlayError setOverlayAlpha(uint64_t handle, float alpha) { return Overlay_003::setOverlayAlpha(handle, alpha); }
            virtual OverlayError getOverlayAlpha(uint64_t handle, float* alpha) { return Overlay_003::getOverlayAlpha(handle, alpha); }
            virtual OverlayError setOverlayGamma(uint64_t handle, float gamma) { return Overlay_003::setOverlayGamma(handle, gamma); }
            virtual OverlayError getOverlayGamma(uint64_t handle, float* gamma) { return Overlay_003::getOverlayGamma(handle, gamma); }
            virtual OverlayError setOverlayWidthInMeters(uint64_t handle, float width) { return Overlay_003::setOverlayWidthInMeters(handle, width); }
            virtual OverlayError getOverlayWidthInMeters(uint64_t handle, float* width) { return Overlay_003::getOverlayWidthInMeters(handle, width); }
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds) { return Overlay_003::setOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_003::getOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType) { return Overlay_003::getOverlayTransformType(handle, transformType); }
            virtual OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_003::setOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix) { return Overlay_003::getOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix) { return Overlay_003::setOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix) { return Overlay_003::getOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError showOverlay(uint64_t handle) { return Overlay_003::showOverlay(handle); }
            virtual OverlayError hideOverlay(uint64_t handle) { return Overlay_003::hideOverlay(handle); }
            virtual bool isOverlayVisible(uint64_t handle) { return Overlay_003::isOverlayVisible(handle); }
            virtual bool pollNextOverlayEvent(uint64_t handle, Event_0_9_0* event) { return Overlay_003::pollNextOverlayEvent(handle, event); }
            virtual OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod) { return Overlay_003::getOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod) { return Overlay_003::setOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale) { return Overlay_003::getOverlayMouseScale(handle, mouseScale); }
            virtual OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale) { return Overlay_003::setOverlayMouseScale(handle, mouseScale); }
            virtual bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results) { return Overlay_003::computeOverlayIntersection(handle, params, results); }
            virtual bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex) { return Overlay_003::handleControllerOverlayInteractionAsMouse(handle, controllerDeviceIndex); }
            virtual OverlayError setOverlayTexture(uint64_t handle, TextureType textureType, void* texture) { return Overlay_003::setOverlayTexture(handle, textureType, texture); }
            virtual OverlayError clearOverlayTexture(uint64_t handle) { return Overlay_003::clearOverlayTexture(handle); }
            virtual OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth) { return Overlay_003::setOverlayRaw(handle, buffer, width, height, depth); }
            virtual OverlayError setOverlayFromFile(uint64_t handle, const char* filePath) { return Overlay_003::setOverlayFromFile(handle, filePath); }
            virtual OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle) { return Overlay_003::createDashboardOverlay(key, friendlyName, mainHandle, thumbnailHandle); }
            virtual bool isDashboardVisible() { return Overlay_003::isDashboardVisible(); }
            virtual bool isActiveDashboardOverlay(uint64_t handle) { return Overlay_003::isActiveDashboardOverlay(handle); }
            virtual OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid) { return Overlay_003::setDashboardOverlaySceneProcess(handle, pid); }
            virtual OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid) { return Overlay_003::getDashboardOverlaySceneProcess(handle, pid); }
            virtual void showDashboard(const char* overlayToShow) { return Overlay_003::showDashboard(overlayToShow); }
    };

    //

    struct Overlay_004
    {
        static OverlayError findOverlay(const char* key, uint64_t* handle);

        static OverlayError createOverlay(const char* key, const char* name, uint64_t* handle);
        static OverlayError destroyOverlay(uint64_t handle);

        static OverlayError setHighQualityOverlay(uint64_t handle);
        static uint64_t getHighQualityOverlay();

        static uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height);

        static const char* getOverlayErrorNameFromEnum(OverlayError error);

        static OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled);
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled);
        static OverlayError setOverlayColor(uint64_t handle, float r, float g, float b);
        static OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b);
        static OverlayError setOverlayAlpha(uint64_t handle, float alpha);
        static OverlayError getOverlayAlpha(uint64_t handle, float* alpha);
        static OverlayError setOverlayGamma(uint64_t handle, float gamma);
        static OverlayError getOverlayGamma(uint64_t handle, float* gamma);

        static OverlayError setOverlayWidthInMeters(uint64_t handle, float width);
        static OverlayError getOverlayWidthInMeters(uint64_t handle, float* width);
        static OverlayError setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance);
        static OverlayError getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance);

        static OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds);
        static OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds);

        static OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType);
        static OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix);
        static OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix);
        static OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix);

        static OverlayError showOverlay(uint64_t handle);
        static OverlayError hideOverlay(uint64_t handle);
        static bool isOverlayVisible(uint64_t handle);

        static bool pollNextOverlayEvent(uint64_t handle, Event_0_9_0* event);

        static OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod);
        static OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod);
        static OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale);
        static OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale);

        static bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results);
        static bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex);

        static OverlayError setOverlayTexture(uint64_t handle, TextureType textureType, void* texture);
        static OverlayError clearOverlayTexture(uint64_t handle);
        static OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth);
        static OverlayError setOverlayFromFile(uint64_t handle, const char* filePath);

        static OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle);
        static bool isDashboardVisible();
        static bool isActiveDashboardOverlay(uint64_t handle);
        static OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid);
        static OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid);
        static void showDashboard(const char* overlayToShow);

        void* findOverlay_ = (void*) findOverlay;
        void* createOverlay_ = (void*) createOverlay;
        void* destroyOverlay_ = (void*) destroyOverlay;
        void* setHighQualityOverlay_ = (void*) setHighQualityOverlay;
        void* getHighQualityOverlay_ = (void*) getHighQualityOverlay;
        void* getOverlayKey_ = (void*) getOverlayKey;
        void* getOverlayName_ = (void*) getOverlayName;
        void* getOverlayImageData_ = (void*) getOverlayImageData;
        void* getOverlayErrorNameFromEnum_ = (void*) getOverlayErrorNameFromEnum;
        void* setOverlayFlag_ = (void*) setOverlayFlag;
        void* getOverlayFlag_ = (void*) getOverlayFlag;
        void* setOverlayColor_ = (void*) setOverlayColor;
        void* getOverlayColor_ = (void*) getOverlayColor;
        void* setOverlayAlpha_ = (void*) setOverlayAlpha;
        void* getOverlayAlpha_ = (void*) getOverlayAlpha;
        void* setOverlayGamma_ = (void*) setOverlayGamma;
        void* getOverlayGamma_ = (void*) getOverlayGamma;
        void* setOverlayWidthInMeters_ = (void*) setOverlayWidthInMeters;
        void* getOverlayWidthInMeters_ = (void*) getOverlayWidthInMeters;
        void* setOverlayAutoCurveDistanceRangeInMeters_ = (void*) setOverlayAutoCurveDistanceRangeInMeters;
        void* getOverlayAutoCurveDistanceRangeInMeters_ = (void*) getOverlayAutoCurveDistanceRangeInMeters;
        void* setOverlayTextureBounds_ = (void*) setOverlayTextureBounds;
        void* getOverlayTextureBounds_ = (void*) getOverlayTextureBounds;
        void* getOverlayTransformType_ = (void*) getOverlayTransformType;
        void* setOverlayTransformAbsolute_ = (void*) setOverlayTransformAbsolute;
        void* getOverlayTransformAbsolute_ = (void*) getOverlayTransformAbsolute;
        void* setOverlayTransformTrackedDeviceRelative_ = (void*) setOverlayTransformTrackedDeviceRelative;
        void* getOverlayTransformTrackedDeviceRelative_ = (void*) getOverlayTransformTrackedDeviceRelative;
        void* showOverlay_ = (void*) showOverlay;
        void* hideOverlay_ = (void*) hideOverlay;
        void* isOverlayVisible_ = (void*) isOverlayVisible;
        void* pollNextOverlayEvent_ = (void*) pollNextOverlayEvent;
        void* getOverlayInputMethod_ = (void*) getOverlayInputMethod;
        void* setOverlayInputMethod_ = (void*) setOverlayInputMethod;
        void* getOverlayMouseScale_ = (void*) getOverlayMouseScale;
        void* setOverlayMouseScale_ = (void*) setOverlayMouseScale;
        void* computeOverlayIntersection_ = (void*) computeOverlayIntersection;
        void* handleControllerOverlayInteractionAsMouse_ = (void*) handleControllerOverlayInteractionAsMouse;
        void* setOverlayTexture_ = (void*) setOverlayTexture;
        void* clearOverlayTexture_ = (void*) clearOverlayTexture;
        void* setOverlayRaw_ = (void*) setOverlayRaw;
        void* setOverlayFromFile_ = (void*) setOverlayFromFile;
        void* createDashboardOverlay_ = (void*) createDashboardOverlay;
        void* isDashboardVisible_ = (void*) isDashboardVisible;
        void* isActiveDashboardOverlay_ = (void*) isActiveDashboardOverlay;
        void* setDashboardOverlaySceneProcess_ = (void*) setDashboardOverlaySceneProcess;
        void* getDashboardOverlaySceneProcess_ = (void*) getDashboardOverlaySceneProcess;
        void* showDashboard_ = (void*) showDashboard;
    };

    class Overlay_004_v
    {
        public:
            virtual OverlayError findOverlay(const char* key, uint64_t* handle) { return Overlay_004::findOverlay(key, handle); }
            virtual OverlayError createOverlay(const char* key, const char* name, uint64_t* handle) { return Overlay_004::createOverlay(key, name, handle); }
            virtual OverlayError destroyOverlay(uint64_t handle) { return Overlay_004::destroyOverlay(handle); }
            virtual OverlayError setHighQualityOverlay(uint64_t handle) { return Overlay_004::setHighQualityOverlay(handle); }
            virtual uint64_t getHighQualityOverlay() { return Overlay_004::getHighQualityOverlay(); }
            virtual uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_004::getOverlayKey(handle, value, bufferSize, error); }
            virtual uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_004::getOverlayName(handle, value, bufferSize, error); }
            virtual OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height) { return Overlay_004::getOverlayImageData(handle, buffer, bufferSize, width, height); }
            virtual const char* getOverlayErrorNameFromEnum(OverlayError error) { return Overlay_004::getOverlayErrorNameFromEnum(error); }
            virtual OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled) { return Overlay_004::setOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled) { return Overlay_004::getOverlayFlag(handle, flag, enabled); }
            virtual OverlayError setOverlayColor(uint64_t handle, float r, float g, float b) { return Overlay_004::setOverlayColor(handle, r, g, b); }
            virtual OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b) { return Overlay_004::getOverlayColor(handle, r, g, b); }
            virtual OverlayError setOverlayAlpha(uint64_t handle, float alpha) { return Overlay_004::setOverlayAlpha(handle, alpha); }
            virtual OverlayError getOverlayAlpha(uint64_t handle, float* alpha) { return Overlay_004::getOverlayAlpha(handle, alpha); }
            virtual OverlayError setOverlayGamma(uint64_t handle, float gamma) { return Overlay_004::setOverlayGamma(handle, gamma); }
            virtual OverlayError getOverlayGamma(uint64_t handle, float* gamma) { return Overlay_004::getOverlayGamma(handle, gamma); }
            virtual OverlayError setOverlayWidthInMeters(uint64_t handle, float width) { return Overlay_004::setOverlayWidthInMeters(handle, width); }
            virtual OverlayError getOverlayWidthInMeters(uint64_t handle, float* width) { return Overlay_004::getOverlayWidthInMeters(handle, width); }
            virtual OverlayError setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance) { return Overlay_004::setOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance) { return Overlay_004::getOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds) { return Overlay_004::setOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_004::getOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType) { return Overlay_004::getOverlayTransformType(handle, transformType); }
            virtual OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_004::setOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix) { return Overlay_004::getOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix) { return Overlay_004::setOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix) { return Overlay_004::getOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError showOverlay(uint64_t handle) { return Overlay_004::showOverlay(handle); }
            virtual OverlayError hideOverlay(uint64_t handle) { return Overlay_004::hideOverlay(handle); }
            virtual bool isOverlayVisible(uint64_t handle) { return Overlay_004::isOverlayVisible(handle); }
            virtual bool pollNextOverlayEvent(uint64_t handle, Event_0_9_0* event) { return Overlay_004::pollNextOverlayEvent(handle, event); }
            virtual OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod) { return Overlay_004::getOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod) { return Overlay_004::setOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale) { return Overlay_004::getOverlayMouseScale(handle, mouseScale); }
            virtual OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale) { return Overlay_004::setOverlayMouseScale(handle, mouseScale); }
            virtual bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results) { return Overlay_004::computeOverlayIntersection(handle, params, results); }
            virtual bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex) { return Overlay_004::handleControllerOverlayInteractionAsMouse(handle, controllerDeviceIndex); }
            virtual OverlayError setOverlayTexture(uint64_t handle, TextureType textureType, void* texture) { return Overlay_004::setOverlayTexture(handle, textureType, texture); }
            virtual OverlayError clearOverlayTexture(uint64_t handle) { return Overlay_004::clearOverlayTexture(handle); }
            virtual OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth) { return Overlay_004::setOverlayRaw(handle, buffer, width, height, depth); }
            virtual OverlayError setOverlayFromFile(uint64_t handle, const char* filePath) { return Overlay_004::setOverlayFromFile(handle, filePath); }
            virtual OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle) { return Overlay_004::createDashboardOverlay(key, friendlyName, mainHandle, thumbnailHandle); }
            virtual bool isDashboardVisible() { return Overlay_004::isDashboardVisible(); }
            virtual bool isActiveDashboardOverlay(uint64_t handle) { return Overlay_004::isActiveDashboardOverlay(handle); }
            virtual OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid) { return Overlay_004::setDashboardOverlaySceneProcess(handle, pid); }
            virtual OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid) { return Overlay_004::getDashboardOverlaySceneProcess(handle, pid); }
            virtual void showDashboard(const char* overlayToShow) { return Overlay_004::showDashboard(overlayToShow); }
    };

    //

    struct Overlay_005
    {
        static OverlayError findOverlay(const char* key, uint64_t* handle);

        static OverlayError createOverlay(const char* key, const char* name, uint64_t* handle);
        static OverlayError destroyOverlay(uint64_t handle);

        static OverlayError setHighQualityOverlay(uint64_t handle);
        static uint64_t getHighQualityOverlay();

        static uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height);

        static const char* getOverlayErrorNameFromEnum(OverlayError error);

        static OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled);
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled);
        static OverlayError setOverlayColor(uint64_t handle, float r, float g, float b);
        static OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b);
        static OverlayError setOverlayAlpha(uint64_t handle, float alpha);
        static OverlayError getOverlayAlpha(uint64_t handle, float* alpha);
        static OverlayError setOverlayGamma(uint64_t handle, float gamma);
        static OverlayError getOverlayGamma(uint64_t handle, float* gamma);

        static OverlayError setOverlayWidthInMeters(uint64_t handle, float width);
        static OverlayError getOverlayWidthInMeters(uint64_t handle, float* width);
        static OverlayError setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance);
        static OverlayError getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance);

        static OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds);
        static OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds);

        static OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType);
        static OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix);
        static OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix);
        static OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix);

        static OverlayError showOverlay(uint64_t handle);
        static OverlayError hideOverlay(uint64_t handle);
        static bool isOverlayVisible(uint64_t handle);

        static bool pollNextOverlayEvent(uint64_t handle, Event_0_9_0* event);

        static OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod);
        static OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod);
        static OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale);
        static OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale);

        static bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results);
        static bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex);
        static bool isFocusOverlay(uint64_t handle);

        static OverlayError setOverlayTexture(uint64_t handle, TextureType textureType, void* texture);
        static OverlayError clearOverlayTexture(uint64_t handle);
        static OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth);
        static OverlayError setOverlayFromFile(uint64_t handle, const char* filePath);

        static OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle);
        static bool isDashboardVisible();
        static bool isActiveDashboardOverlay(uint64_t handle);
        static OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid);
        static OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid);
        static void showDashboard(const char* overlayToShow);

        static OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode);
        static uint32_t getKeyboardText(char* text, uint32_t bufferSize);
        static void hideKeyboard();

        void* findOverlay_ = (void*) findOverlay;
        void* createOverlay_ = (void*) createOverlay;
        void* destroyOverlay_ = (void*) destroyOverlay;
        void* setHighQualityOverlay_ = (void*) setHighQualityOverlay;
        void* getHighQualityOverlay_ = (void*) getHighQualityOverlay;
        void* getOverlayKey_ = (void*) getOverlayKey;
        void* getOverlayName_ = (void*) getOverlayName;
        void* getOverlayImageData_ = (void*) getOverlayImageData;
        void* getOverlayErrorNameFromEnum_ = (void*) getOverlayErrorNameFromEnum;
        void* setOverlayFlag_ = (void*) setOverlayFlag;
        void* getOverlayFlag_ = (void*) getOverlayFlag;
        void* setOverlayColor_ = (void*) setOverlayColor;
        void* getOverlayColor_ = (void*) getOverlayColor;
        void* setOverlayAlpha_ = (void*) setOverlayAlpha;
        void* getOverlayAlpha_ = (void*) getOverlayAlpha;
        void* setOverlayGamma_ = (void*) setOverlayGamma;
        void* getOverlayGamma_ = (void*) getOverlayGamma;
        void* setOverlayWidthInMeters_ = (void*) setOverlayWidthInMeters;
        void* getOverlayWidthInMeters_ = (void*) getOverlayWidthInMeters;
        void* setOverlayAutoCurveDistanceRangeInMeters_ = (void*) setOverlayAutoCurveDistanceRangeInMeters;
        void* getOverlayAutoCurveDistanceRangeInMeters_ = (void*) getOverlayAutoCurveDistanceRangeInMeters;
        void* setOverlayTextureBounds_ = (void*) setOverlayTextureBounds;
        void* getOverlayTextureBounds_ = (void*) getOverlayTextureBounds;
        void* getOverlayTransformType_ = (void*) getOverlayTransformType;
        void* setOverlayTransformAbsolute_ = (void*) setOverlayTransformAbsolute;
        void* getOverlayTransformAbsolute_ = (void*) getOverlayTransformAbsolute;
        void* setOverlayTransformTrackedDeviceRelative_ = (void*) setOverlayTransformTrackedDeviceRelative;
        void* getOverlayTransformTrackedDeviceRelative_ = (void*) getOverlayTransformTrackedDeviceRelative;
        void* showOverlay_ = (void*) showOverlay;
        void* hideOverlay_ = (void*) hideOverlay;
        void* isOverlayVisible_ = (void*) isOverlayVisible;
        void* pollNextOverlayEvent_ = (void*) pollNextOverlayEvent;
        void* getOverlayInputMethod_ = (void*) getOverlayInputMethod;
        void* setOverlayInputMethod_ = (void*) setOverlayInputMethod;
        void* getOverlayMouseScale_ = (void*) getOverlayMouseScale;
        void* setOverlayMouseScale_ = (void*) setOverlayMouseScale;
        void* computeOverlayIntersection_ = (void*) computeOverlayIntersection;
        void* handleControllerOverlayInteractionAsMouse_ = (void*) handleControllerOverlayInteractionAsMouse;
        void* isFocusOverlay_ = (void*) isFocusOverlay;
        void* setOverlayTexture_ = (void*) setOverlayTexture;
        void* clearOverlayTexture_ = (void*) clearOverlayTexture;
        void* setOverlayRaw_ = (void*) setOverlayRaw;
        void* setOverlayFromFile_ = (void*) setOverlayFromFile;
        void* createDashboardOverlay_ = (void*) createDashboardOverlay;
        void* isDashboardVisible_ = (void*) isDashboardVisible;
        void* isActiveDashboardOverlay_ = (void*) isActiveDashboardOverlay;
        void* setDashboardOverlaySceneProcess_ = (void*) setDashboardOverlaySceneProcess;
        void* getDashboardOverlaySceneProcess_ = (void*) getDashboardOverlaySceneProcess;
        void* showDashboard_ = (void*) showDashboard;
        void* showKeyboard_ = (void*) showKeyboard;
        void* getKeyboardText_ = (void*) getKeyboardText;
        void* hideKeyboard_ = (void*) hideKeyboard;
    };

    class Overlay_005_v
    {
        public:
            virtual OverlayError findOverlay(const char* key, uint64_t* handle) { return Overlay_005::findOverlay(key, handle); }
            virtual OverlayError createOverlay(const char* key, const char* name, uint64_t* handle) { return Overlay_005::createOverlay(key, name, handle); }
            virtual OverlayError destroyOverlay(uint64_t handle) { return Overlay_005::destroyOverlay(handle); }
            virtual OverlayError setHighQualityOverlay(uint64_t handle) { return Overlay_005::setHighQualityOverlay(handle); }
            virtual uint64_t getHighQualityOverlay() { return Overlay_005::getHighQualityOverlay(); }
            virtual uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_005::getOverlayKey(handle, value, bufferSize, error); }
            virtual uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_005::getOverlayName(handle, value, bufferSize, error); }
            virtual OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height) { return Overlay_005::getOverlayImageData(handle, buffer, bufferSize, width, height); }
            virtual const char* getOverlayErrorNameFromEnum(OverlayError error) { return Overlay_005::getOverlayErrorNameFromEnum(error); }
            virtual OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled) { return Overlay_005::setOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled) { return Overlay_005::getOverlayFlag(handle, flag, enabled); }
            virtual OverlayError setOverlayColor(uint64_t handle, float r, float g, float b) { return Overlay_005::setOverlayColor(handle, r, g, b); }
            virtual OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b) { return Overlay_005::getOverlayColor(handle, r, g, b); }
            virtual OverlayError setOverlayAlpha(uint64_t handle, float alpha) { return Overlay_005::setOverlayAlpha(handle, alpha); }
            virtual OverlayError getOverlayAlpha(uint64_t handle, float* alpha) { return Overlay_005::getOverlayAlpha(handle, alpha); }
            virtual OverlayError setOverlayGamma(uint64_t handle, float gamma) { return Overlay_005::setOverlayGamma(handle, gamma); }
            virtual OverlayError getOverlayGamma(uint64_t handle, float* gamma) { return Overlay_005::getOverlayGamma(handle, gamma); }
            virtual OverlayError setOverlayWidthInMeters(uint64_t handle, float width) { return Overlay_005::setOverlayWidthInMeters(handle, width); }
            virtual OverlayError getOverlayWidthInMeters(uint64_t handle, float* width) { return Overlay_005::getOverlayWidthInMeters(handle, width); }
            virtual OverlayError setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance) { return Overlay_005::setOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance) { return Overlay_005::getOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds) { return Overlay_005::setOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_005::getOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType) { return Overlay_005::getOverlayTransformType(handle, transformType); }
            virtual OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_005::setOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix) { return Overlay_005::getOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix) { return Overlay_005::setOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix) { return Overlay_005::getOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError showOverlay(uint64_t handle) { return Overlay_005::showOverlay(handle); }
            virtual OverlayError hideOverlay(uint64_t handle) { return Overlay_005::hideOverlay(handle); }
            virtual bool isOverlayVisible(uint64_t handle) { return Overlay_005::isOverlayVisible(handle); }
            virtual bool pollNextOverlayEvent(uint64_t handle, Event_0_9_0* event) { return Overlay_005::pollNextOverlayEvent(handle, event); }
            virtual OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod) { return Overlay_005::getOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod) { return Overlay_005::setOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale) { return Overlay_005::getOverlayMouseScale(handle, mouseScale); }
            virtual OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale) { return Overlay_005::setOverlayMouseScale(handle, mouseScale); }
            virtual bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results) { return Overlay_005::computeOverlayIntersection(handle, params, results); }
            virtual bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex) { return Overlay_005::handleControllerOverlayInteractionAsMouse(handle, controllerDeviceIndex); }
            virtual bool isFocusOverlay(uint64_t handle) { return Overlay_005::isFocusOverlay(handle); }
            virtual OverlayError setOverlayTexture(uint64_t handle, TextureType textureType, void* texture) { return Overlay_005::setOverlayTexture(handle, textureType, texture); }
            virtual OverlayError clearOverlayTexture(uint64_t handle) { return Overlay_005::clearOverlayTexture(handle); }
            virtual OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth) { return Overlay_005::setOverlayRaw(handle, buffer, width, height, depth); }
            virtual OverlayError setOverlayFromFile(uint64_t handle, const char* filePath) { return Overlay_005::setOverlayFromFile(handle, filePath); }
            virtual OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle) { return Overlay_005::createDashboardOverlay(key, friendlyName, mainHandle, thumbnailHandle); }
            virtual bool isDashboardVisible() { return Overlay_005::isDashboardVisible(); }
            virtual bool isActiveDashboardOverlay(uint64_t handle) { return Overlay_005::isActiveDashboardOverlay(handle); }
            virtual OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid) { return Overlay_005::setDashboardOverlaySceneProcess(handle, pid); }
            virtual OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid) { return Overlay_005::getDashboardOverlaySceneProcess(handle, pid); }
            virtual void showDashboard(const char* overlayToShow) { return Overlay_005::showDashboard(overlayToShow); }
            virtual OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode) { return Overlay_005::showKeyboard(textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode); }
            virtual uint32_t getKeyboardText(char* text, uint32_t bufferSize) { return Overlay_005::getKeyboardText(text, bufferSize); }
            virtual void hideKeyboard() { return Overlay_005::hideKeyboard(); }
    };

    //

    struct Overlay_006
    {
        static OverlayError findOverlay(const char* key, uint64_t* handle);

        static OverlayError createOverlay(const char* key, const char* name, uint64_t* handle);
        static OverlayError destroyOverlay(uint64_t handle);

        static OverlayError setHighQualityOverlay(uint64_t handle);
        static uint64_t getHighQualityOverlay();

        static uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height);

        static const char* getOverlayErrorNameFromEnum(OverlayError error);

        static OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled);
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled);
        static OverlayError setOverlayColor(uint64_t handle, float r, float g, float b);
        static OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b);
        static OverlayError setOverlayAlpha(uint64_t handle, float alpha);
        static OverlayError getOverlayAlpha(uint64_t handle, float* alpha);
        static OverlayError setOverlayGamma(uint64_t handle, float gamma);
        static OverlayError getOverlayGamma(uint64_t handle, float* gamma);

        static OverlayError setOverlayWidthInMeters(uint64_t handle, float width);
        static OverlayError getOverlayWidthInMeters(uint64_t handle, float* width);
        static OverlayError setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance);
        static OverlayError getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance);

        static OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds);
        static OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds);

        static OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType);
        static OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix);
        static OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix);
        static OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix);

        static OverlayError showOverlay(uint64_t handle);
        static OverlayError hideOverlay(uint64_t handle);
        static bool isOverlayVisible(uint64_t handle);

        static bool pollNextOverlayEvent(uint64_t handle, Event_0_9_0* event);

        static OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod);
        static OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod);
        static OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale);
        static OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale);

        static bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results);
        static bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex);
        static bool isHoverTargetOverlay(uint64_t handle);

        static uint64_t getGamepadFocusOverlay();
        static OverlayError setGamepadFocusOverlay(uint64_t handle);
        static OverlayError setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to);
        static OverlayError moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from);

        static OverlayError setOverlayTexture(uint64_t handle, TextureType textureType, void* texture);
        static OverlayError clearOverlayTexture(uint64_t handle);
        static OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth);
        static OverlayError setOverlayFromFile(uint64_t handle, const char* filePath);

        static OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle);
        static bool isDashboardVisible();
        static bool isActiveDashboardOverlay(uint64_t handle);
        static OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid);
        static OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid);
        static void showDashboard(const char* overlayToShow);

        static OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue);
        static OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue);
        static uint32_t getKeyboardText(char* text, uint32_t bufferSize);
        static void hideKeyboard();

        void* findOverlay_ = (void*) findOverlay;
        void* createOverlay_ = (void*) createOverlay;
        void* destroyOverlay_ = (void*) destroyOverlay;
        void* setHighQualityOverlay_ = (void*) setHighQualityOverlay;
        void* getHighQualityOverlay_ = (void*) getHighQualityOverlay;
        void* getOverlayKey_ = (void*) getOverlayKey;
        void* getOverlayName_ = (void*) getOverlayName;
        void* getOverlayImageData_ = (void*) getOverlayImageData;
        void* getOverlayErrorNameFromEnum_ = (void*) getOverlayErrorNameFromEnum;
        void* setOverlayFlag_ = (void*) setOverlayFlag;
        void* getOverlayFlag_ = (void*) getOverlayFlag;
        void* setOverlayColor_ = (void*) setOverlayColor;
        void* getOverlayColor_ = (void*) getOverlayColor;
        void* setOverlayAlpha_ = (void*) setOverlayAlpha;
        void* getOverlayAlpha_ = (void*) getOverlayAlpha;
        void* setOverlayGamma_ = (void*) setOverlayGamma;
        void* getOverlayGamma_ = (void*) getOverlayGamma;
        void* setOverlayWidthInMeters_ = (void*) setOverlayWidthInMeters;
        void* getOverlayWidthInMeters_ = (void*) getOverlayWidthInMeters;
        void* setOverlayAutoCurveDistanceRangeInMeters_ = (void*) setOverlayAutoCurveDistanceRangeInMeters;
        void* getOverlayAutoCurveDistanceRangeInMeters_ = (void*) getOverlayAutoCurveDistanceRangeInMeters;
        void* setOverlayTextureBounds_ = (void*) setOverlayTextureBounds;
        void* getOverlayTextureBounds_ = (void*) getOverlayTextureBounds;
        void* getOverlayTransformType_ = (void*) getOverlayTransformType;
        void* setOverlayTransformAbsolute_ = (void*) setOverlayTransformAbsolute;
        void* getOverlayTransformAbsolute_ = (void*) getOverlayTransformAbsolute;
        void* setOverlayTransformTrackedDeviceRelative_ = (void*) setOverlayTransformTrackedDeviceRelative;
        void* getOverlayTransformTrackedDeviceRelative_ = (void*) getOverlayTransformTrackedDeviceRelative;
        void* showOverlay_ = (void*) showOverlay;
        void* hideOverlay_ = (void*) hideOverlay;
        void* isOverlayVisible_ = (void*) isOverlayVisible;
        void* pollNextOverlayEvent_ = (void*) pollNextOverlayEvent;
        void* getOverlayInputMethod_ = (void*) getOverlayInputMethod;
        void* setOverlayInputMethod_ = (void*) setOverlayInputMethod;
        void* getOverlayMouseScale_ = (void*) getOverlayMouseScale;
        void* setOverlayMouseScale_ = (void*) setOverlayMouseScale;
        void* computeOverlayIntersection_ = (void*) computeOverlayIntersection;
        void* handleControllerOverlayInteractionAsMouse_ = (void*) handleControllerOverlayInteractionAsMouse;
        void* isHoverTargetOverlay_ = (void*) isHoverTargetOverlay;
        void* getGamepadFocusOverlay_ = (void*) getGamepadFocusOverlay;
        void* setGamepadFocusOverlay_ = (void*) setGamepadFocusOverlay;
        void* setOverlayNeighbor_ = (void*) setOverlayNeighbor;
        void* moveGamepadFocusToNeighbor_ = (void*) moveGamepadFocusToNeighbor;
        void* setOverlayTexture_ = (void*) setOverlayTexture;
        void* clearOverlayTexture_ = (void*) clearOverlayTexture;
        void* setOverlayRaw_ = (void*) setOverlayRaw;
        void* setOverlayFromFile_ = (void*) setOverlayFromFile;
        void* createDashboardOverlay_ = (void*) createDashboardOverlay;
        void* isDashboardVisible_ = (void*) isDashboardVisible;
        void* isActiveDashboardOverlay_ = (void*) isActiveDashboardOverlay;
        void* setDashboardOverlaySceneProcess_ = (void*) setDashboardOverlaySceneProcess;
        void* getDashboardOverlaySceneProcess_ = (void*) getDashboardOverlaySceneProcess;
        void* showDashboard_ = (void*) showDashboard;
        void* showKeyboard_ = (void*) showKeyboard;
        void* showKeyboardForOverlay_ = (void*) showKeyboardForOverlay;
        void* getKeyboardText_ = (void*) getKeyboardText;
        void* hideKeyboard_ = (void*) hideKeyboard;
    };

    class Overlay_006_v
    {
        public:
            virtual OverlayError findOverlay(const char* key, uint64_t* handle) { return Overlay_006::findOverlay(key, handle); }
            virtual OverlayError createOverlay(const char* key, const char* name, uint64_t* handle) { return Overlay_006::createOverlay(key, name, handle); }
            virtual OverlayError destroyOverlay(uint64_t handle) { return Overlay_006::destroyOverlay(handle); }
            virtual OverlayError setHighQualityOverlay(uint64_t handle) { return Overlay_006::setHighQualityOverlay(handle); }
            virtual uint64_t getHighQualityOverlay() { return Overlay_006::getHighQualityOverlay(); }
            virtual uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_006::getOverlayKey(handle, value, bufferSize, error); }
            virtual uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_006::getOverlayName(handle, value, bufferSize, error); }
            virtual OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height) { return Overlay_006::getOverlayImageData(handle, buffer, bufferSize, width, height); }
            virtual const char* getOverlayErrorNameFromEnum(OverlayError error) { return Overlay_006::getOverlayErrorNameFromEnum(error); }
            virtual OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled) { return Overlay_006::setOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled) { return Overlay_006::getOverlayFlag(handle, flag, enabled); }
            virtual OverlayError setOverlayColor(uint64_t handle, float r, float g, float b) { return Overlay_006::setOverlayColor(handle, r, g, b); }
            virtual OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b) { return Overlay_006::getOverlayColor(handle, r, g, b); }
            virtual OverlayError setOverlayAlpha(uint64_t handle, float alpha) { return Overlay_006::setOverlayAlpha(handle, alpha); }
            virtual OverlayError getOverlayAlpha(uint64_t handle, float* alpha) { return Overlay_006::getOverlayAlpha(handle, alpha); }
            virtual OverlayError setOverlayGamma(uint64_t handle, float gamma) { return Overlay_006::setOverlayGamma(handle, gamma); }
            virtual OverlayError getOverlayGamma(uint64_t handle, float* gamma) { return Overlay_006::getOverlayGamma(handle, gamma); }
            virtual OverlayError setOverlayWidthInMeters(uint64_t handle, float width) { return Overlay_006::setOverlayWidthInMeters(handle, width); }
            virtual OverlayError getOverlayWidthInMeters(uint64_t handle, float* width) { return Overlay_006::getOverlayWidthInMeters(handle, width); }
            virtual OverlayError setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance) { return Overlay_006::setOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance) { return Overlay_006::getOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds) { return Overlay_006::setOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_006::getOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType) { return Overlay_006::getOverlayTransformType(handle, transformType); }
            virtual OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_006::setOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix) { return Overlay_006::getOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix) { return Overlay_006::setOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix) { return Overlay_006::getOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError showOverlay(uint64_t handle) { return Overlay_006::showOverlay(handle); }
            virtual OverlayError hideOverlay(uint64_t handle) { return Overlay_006::hideOverlay(handle); }
            virtual bool isOverlayVisible(uint64_t handle) { return Overlay_006::isOverlayVisible(handle); }
            virtual bool pollNextOverlayEvent(uint64_t handle, Event_0_9_0* event) { return Overlay_006::pollNextOverlayEvent(handle, event); }
            virtual OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod) { return Overlay_006::getOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod) { return Overlay_006::setOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale) { return Overlay_006::getOverlayMouseScale(handle, mouseScale); }
            virtual OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale) { return Overlay_006::setOverlayMouseScale(handle, mouseScale); }
            virtual bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results) { return Overlay_006::computeOverlayIntersection(handle, params, results); }
            virtual bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex) { return Overlay_006::handleControllerOverlayInteractionAsMouse(handle, controllerDeviceIndex); }
            virtual bool isHoverTargetOverlay(uint64_t handle) { return Overlay_006::isHoverTargetOverlay(handle); }
            virtual uint64_t getGamepadFocusOverlay() { return Overlay_006::getGamepadFocusOverlay(); }
            virtual OverlayError setGamepadFocusOverlay(uint64_t handle) { return Overlay_006::setGamepadFocusOverlay(handle); }
            virtual OverlayError setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to) { return Overlay_006::setOverlayNeighbor(direction, from, to); }
            virtual OverlayError moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from) { return Overlay_006::moveGamepadFocusToNeighbor(direction, from); }
            virtual OverlayError setOverlayTexture(uint64_t handle, TextureType textureType, void* texture) { return Overlay_006::setOverlayTexture(handle, textureType, texture); }
            virtual OverlayError clearOverlayTexture(uint64_t handle) { return Overlay_006::clearOverlayTexture(handle); }
            virtual OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth) { return Overlay_006::setOverlayRaw(handle, buffer, width, height, depth); }
            virtual OverlayError setOverlayFromFile(uint64_t handle, const char* filePath) { return Overlay_006::setOverlayFromFile(handle, filePath); }
            virtual OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle) { return Overlay_006::createDashboardOverlay(key, friendlyName, mainHandle, thumbnailHandle); }
            virtual bool isDashboardVisible() { return Overlay_006::isDashboardVisible(); }
            virtual bool isActiveDashboardOverlay(uint64_t handle) { return Overlay_006::isActiveDashboardOverlay(handle); }
            virtual OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid) { return Overlay_006::setDashboardOverlaySceneProcess(handle, pid); }
            virtual OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid) { return Overlay_006::getDashboardOverlaySceneProcess(handle, pid); }
            virtual void showDashboard(const char* overlayToShow) { return Overlay_006::showDashboard(overlayToShow); }
            virtual OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_006::showKeyboard(textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_006::showKeyboardForOverlay(handle, textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual uint32_t getKeyboardText(char* text, uint32_t bufferSize) { return Overlay_006::getKeyboardText(text, bufferSize); }
            virtual void hideKeyboard() { return Overlay_006::hideKeyboard(); }
    };

    //

    struct Overlay_007
    {
        static OverlayError findOverlay(const char* key, uint64_t* handle);

        static OverlayError createOverlay(const char* key, const char* name, uint64_t* handle);
        static OverlayError destroyOverlay(uint64_t handle);

        static OverlayError setHighQualityOverlay(uint64_t handle);
        static uint64_t getHighQualityOverlay();

        static uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height);

        static const char* getOverlayErrorNameFromEnum(OverlayError error);

        static OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled);
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled);
        static OverlayError setOverlayColor(uint64_t handle, float r, float g, float b);
        static OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b);
        static OverlayError setOverlayAlpha(uint64_t handle, float alpha);
        static OverlayError getOverlayAlpha(uint64_t handle, float* alpha);

        static OverlayError setOverlayWidthInMeters(uint64_t handle, float width);
        static OverlayError getOverlayWidthInMeters(uint64_t handle, float* width);
        static OverlayError setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance);
        static OverlayError getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance);

        static OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace);
        static OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace);
        static OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds);
        static OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds);

        static OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType);
        static OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix);
        static OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix);
        static OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix);

        static OverlayError showOverlay(uint64_t handle);
        static OverlayError hideOverlay(uint64_t handle);
        static bool isOverlayVisible(uint64_t handle);

        static bool pollNextOverlayEvent(uint64_t handle, Event_0_9_0* event);

        static OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod);
        static OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod);
        static OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale);
        static OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale);

        static bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results);
        static bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex);
        static bool isHoverTargetOverlay(uint64_t handle);

        static uint64_t getGamepadFocusOverlay();
        static OverlayError setGamepadFocusOverlay(uint64_t handle);
        static OverlayError setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to);
        static OverlayError moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from);

        static OverlayError setOverlayTexture(uint64_t handle, const Texture* texture);
        static OverlayError clearOverlayTexture(uint64_t handle);
        static OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth);
        static OverlayError setOverlayFromFile(uint64_t handle, const char* filePath);

        static OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle);
        static bool isDashboardVisible();
        static bool isActiveDashboardOverlay(uint64_t handle);
        static OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid);
        static OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid);
        static void showDashboard(const char* overlayToShow);

        static OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue);
        static OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue);
        static uint32_t getKeyboardText(char* text, uint32_t bufferSize);
        static void hideKeyboard();

        void* findOverlay_ = (void*) findOverlay;
        void* createOverlay_ = (void*) createOverlay;
        void* destroyOverlay_ = (void*) destroyOverlay;
        void* setHighQualityOverlay_ = (void*) setHighQualityOverlay;
        void* getHighQualityOverlay_ = (void*) getHighQualityOverlay;
        void* getOverlayKey_ = (void*) getOverlayKey;
        void* getOverlayName_ = (void*) getOverlayName;
        void* getOverlayImageData_ = (void*) getOverlayImageData;
        void* getOverlayErrorNameFromEnum_ = (void*) getOverlayErrorNameFromEnum;
        void* setOverlayFlag_ = (void*) setOverlayFlag;
        void* getOverlayFlag_ = (void*) getOverlayFlag;
        void* setOverlayColor_ = (void*) setOverlayColor;
        void* getOverlayColor_ = (void*) getOverlayColor;
        void* setOverlayAlpha_ = (void*) setOverlayAlpha;
        void* getOverlayAlpha_ = (void*) getOverlayAlpha;
        void* setOverlayWidthInMeters_ = (void*) setOverlayWidthInMeters;
        void* getOverlayWidthInMeters_ = (void*) getOverlayWidthInMeters;
        void* setOverlayAutoCurveDistanceRangeInMeters_ = (void*) setOverlayAutoCurveDistanceRangeInMeters;
        void* getOverlayAutoCurveDistanceRangeInMeters_ = (void*) getOverlayAutoCurveDistanceRangeInMeters;
        void* setOverlayTextureColorSpace_ = (void*) setOverlayTextureColorSpace;
        void* getOverlayTextureColorSpace_ = (void*) getOverlayTextureColorSpace;
        void* setOverlayTextureBounds_ = (void*) setOverlayTextureBounds;
        void* getOverlayTextureBounds_ = (void*) getOverlayTextureBounds;
        void* getOverlayTransformType_ = (void*) getOverlayTransformType;
        void* setOverlayTransformAbsolute_ = (void*) setOverlayTransformAbsolute;
        void* getOverlayTransformAbsolute_ = (void*) getOverlayTransformAbsolute;
        void* setOverlayTransformTrackedDeviceRelative_ = (void*) setOverlayTransformTrackedDeviceRelative;
        void* getOverlayTransformTrackedDeviceRelative_ = (void*) getOverlayTransformTrackedDeviceRelative;
        void* showOverlay_ = (void*) showOverlay;
        void* hideOverlay_ = (void*) hideOverlay;
        void* isOverlayVisible_ = (void*) isOverlayVisible;
        void* pollNextOverlayEvent_ = (void*) pollNextOverlayEvent;
        void* getOverlayInputMethod_ = (void*) getOverlayInputMethod;
        void* setOverlayInputMethod_ = (void*) setOverlayInputMethod;
        void* getOverlayMouseScale_ = (void*) getOverlayMouseScale;
        void* setOverlayMouseScale_ = (void*) setOverlayMouseScale;
        void* computeOverlayIntersection_ = (void*) computeOverlayIntersection;
        void* handleControllerOverlayInteractionAsMouse_ = (void*) handleControllerOverlayInteractionAsMouse;
        void* isHoverTargetOverlay_ = (void*) isHoverTargetOverlay;
        void* getGamepadFocusOverlay_ = (void*) getGamepadFocusOverlay;
        void* setGamepadFocusOverlay_ = (void*) setGamepadFocusOverlay;
        void* setOverlayNeighbor_ = (void*) setOverlayNeighbor;
        void* moveGamepadFocusToNeighbor_ = (void*) moveGamepadFocusToNeighbor;
        void* setOverlayTexture_ = (void*) setOverlayTexture;
        void* clearOverlayTexture_ = (void*) clearOverlayTexture;
        void* setOverlayRaw_ = (void*) setOverlayRaw;
        void* setOverlayFromFile_ = (void*) setOverlayFromFile;
        void* createDashboardOverlay_ = (void*) createDashboardOverlay;
        void* isDashboardVisible_ = (void*) isDashboardVisible;
        void* isActiveDashboardOverlay_ = (void*) isActiveDashboardOverlay;
        void* setDashboardOverlaySceneProcess_ = (void*) setDashboardOverlaySceneProcess;
        void* getDashboardOverlaySceneProcess_ = (void*) getDashboardOverlaySceneProcess;
        void* showDashboard_ = (void*) showDashboard;
        void* showKeyboard_ = (void*) showKeyboard;
        void* showKeyboardForOverlay_ = (void*) showKeyboardForOverlay;
        void* getKeyboardText_ = (void*) getKeyboardText;
        void* hideKeyboard_ = (void*) hideKeyboard;
    };

    class Overlay_007_v
    {
        public:
            virtual OverlayError findOverlay(const char* key, uint64_t* handle) { return Overlay_007::findOverlay(key, handle); }
            virtual OverlayError createOverlay(const char* key, const char* name, uint64_t* handle) { return Overlay_007::createOverlay(key, name, handle); }
            virtual OverlayError destroyOverlay(uint64_t handle) { return Overlay_007::destroyOverlay(handle); }
            virtual OverlayError setHighQualityOverlay(uint64_t handle) { return Overlay_007::setHighQualityOverlay(handle); }
            virtual uint64_t getHighQualityOverlay() { return Overlay_007::getHighQualityOverlay(); }
            virtual uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_007::getOverlayKey(handle, value, bufferSize, error); }
            virtual uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_007::getOverlayName(handle, value, bufferSize, error); }
            virtual OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height) { return Overlay_007::getOverlayImageData(handle, buffer, bufferSize, width, height); }
            virtual const char* getOverlayErrorNameFromEnum(OverlayError error) { return Overlay_007::getOverlayErrorNameFromEnum(error); }
            virtual OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled) { return Overlay_007::setOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled) { return Overlay_007::getOverlayFlag(handle, flag, enabled); }
            virtual OverlayError setOverlayColor(uint64_t handle, float r, float g, float b) { return Overlay_007::setOverlayColor(handle, r, g, b); }
            virtual OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b) { return Overlay_007::getOverlayColor(handle, r, g, b); }
            virtual OverlayError setOverlayAlpha(uint64_t handle, float alpha) { return Overlay_007::setOverlayAlpha(handle, alpha); }
            virtual OverlayError getOverlayAlpha(uint64_t handle, float* alpha) { return Overlay_007::getOverlayAlpha(handle, alpha); }
            virtual OverlayError setOverlayWidthInMeters(uint64_t handle, float width) { return Overlay_007::setOverlayWidthInMeters(handle, width); }
            virtual OverlayError getOverlayWidthInMeters(uint64_t handle, float* width) { return Overlay_007::getOverlayWidthInMeters(handle, width); }
            virtual OverlayError setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance) { return Overlay_007::setOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance) { return Overlay_007::getOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace) { return Overlay_007::setOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace) { return Overlay_007::getOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds) { return Overlay_007::setOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_007::getOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType) { return Overlay_007::getOverlayTransformType(handle, transformType); }
            virtual OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_007::setOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix) { return Overlay_007::getOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix) { return Overlay_007::setOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix) { return Overlay_007::getOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError showOverlay(uint64_t handle) { return Overlay_007::showOverlay(handle); }
            virtual OverlayError hideOverlay(uint64_t handle) { return Overlay_007::hideOverlay(handle); }
            virtual bool isOverlayVisible(uint64_t handle) { return Overlay_007::isOverlayVisible(handle); }
            virtual bool pollNextOverlayEvent(uint64_t handle, Event_0_9_0* event) { return Overlay_007::pollNextOverlayEvent(handle, event); }
            virtual OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod) { return Overlay_007::getOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod) { return Overlay_007::setOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale) { return Overlay_007::getOverlayMouseScale(handle, mouseScale); }
            virtual OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale) { return Overlay_007::setOverlayMouseScale(handle, mouseScale); }
            virtual bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results) { return Overlay_007::computeOverlayIntersection(handle, params, results); }
            virtual bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex) { return Overlay_007::handleControllerOverlayInteractionAsMouse(handle, controllerDeviceIndex); }
            virtual bool isHoverTargetOverlay(uint64_t handle) { return Overlay_007::isHoverTargetOverlay(handle); }
            virtual uint64_t getGamepadFocusOverlay() { return Overlay_007::getGamepadFocusOverlay(); }
            virtual OverlayError setGamepadFocusOverlay(uint64_t handle) { return Overlay_007::setGamepadFocusOverlay(handle); }
            virtual OverlayError setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to) { return Overlay_007::setOverlayNeighbor(direction, from, to); }
            virtual OverlayError moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from) { return Overlay_007::moveGamepadFocusToNeighbor(direction, from); }
            virtual OverlayError setOverlayTexture(uint64_t handle, const Texture* texture) { return Overlay_007::setOverlayTexture(handle, texture); }
            virtual OverlayError clearOverlayTexture(uint64_t handle) { return Overlay_007::clearOverlayTexture(handle); }
            virtual OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth) { return Overlay_007::setOverlayRaw(handle, buffer, width, height, depth); }
            virtual OverlayError setOverlayFromFile(uint64_t handle, const char* filePath) { return Overlay_007::setOverlayFromFile(handle, filePath); }
            virtual OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle) { return Overlay_007::createDashboardOverlay(key, friendlyName, mainHandle, thumbnailHandle); }
            virtual bool isDashboardVisible() { return Overlay_007::isDashboardVisible(); }
            virtual bool isActiveDashboardOverlay(uint64_t handle) { return Overlay_007::isActiveDashboardOverlay(handle); }
            virtual OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid) { return Overlay_007::setDashboardOverlaySceneProcess(handle, pid); }
            virtual OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid) { return Overlay_007::getDashboardOverlaySceneProcess(handle, pid); }
            virtual void showDashboard(const char* overlayToShow) { return Overlay_007::showDashboard(overlayToShow); }
            virtual OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_007::showKeyboard(textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_007::showKeyboardForOverlay(handle, textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual uint32_t getKeyboardText(char* text, uint32_t bufferSize) { return Overlay_007::getKeyboardText(text, bufferSize); }
            virtual void hideKeyboard() { return Overlay_007::hideKeyboard(); }
    };

    //

    struct Overlay_008
    {
        static OverlayError findOverlay(const char* key, uint64_t* handle);

        static OverlayError createOverlay(const char* key, const char* name, uint64_t* handle);
        static OverlayError destroyOverlay(uint64_t handle);

        static OverlayError setHighQualityOverlay(uint64_t handle);
        static uint64_t getHighQualityOverlay();

        static uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height);

        static const char* getOverlayErrorNameFromEnum(OverlayError error);

        static OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled);
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled);
        static OverlayError setOverlayColor(uint64_t handle, float r, float g, float b);
        static OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b);
        static OverlayError setOverlayAlpha(uint64_t handle, float alpha);
        static OverlayError getOverlayAlpha(uint64_t handle, float* alpha);

        static OverlayError setOverlayWidthInMeters(uint64_t handle, float width);
        static OverlayError getOverlayWidthInMeters(uint64_t handle, float* width);
        static OverlayError setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance);
        static OverlayError getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance);

        static OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace);
        static OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace);
        static OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds);
        static OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds);

        static OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType);
        static OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix);
        static OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix);
        static OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix);

        static OverlayError showOverlay(uint64_t handle);
        static OverlayError hideOverlay(uint64_t handle);
        static bool isOverlayVisible(uint64_t handle);

        static OverlayError getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix);

        static bool pollNextOverlayEvent(uint64_t handle, Event_0_9_0* event);

        static OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod);
        static OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod);
        static OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale);
        static OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale);

        static bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results);
        static bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex);
        static bool isHoverTargetOverlay(uint64_t handle);

        static uint64_t getGamepadFocusOverlay();
        static OverlayError setGamepadFocusOverlay(uint64_t handle);
        static OverlayError setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to);
        static OverlayError moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from);

        static OverlayError setOverlayTexture(uint64_t handle, const Texture* texture);
        static OverlayError clearOverlayTexture(uint64_t handle);
        static OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth);
        static OverlayError setOverlayFromFile(uint64_t handle, const char* filePath);

        static OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle);
        static bool isDashboardVisible();
        static bool isActiveDashboardOverlay(uint64_t handle);
        static OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid);
        static OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid);
        static void showDashboard(const char* overlayToShow);

        static OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue);
        static OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue);
        static uint32_t getKeyboardText(char* text, uint32_t bufferSize);
        static void hideKeyboard();
        static void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix);
        static void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect);

        void* findOverlay_ = (void*) findOverlay;
        void* createOverlay_ = (void*) createOverlay;
        void* destroyOverlay_ = (void*) destroyOverlay;
        void* setHighQualityOverlay_ = (void*) setHighQualityOverlay;
        void* getHighQualityOverlay_ = (void*) getHighQualityOverlay;
        void* getOverlayKey_ = (void*) getOverlayKey;
        void* getOverlayName_ = (void*) getOverlayName;
        void* getOverlayImageData_ = (void*) getOverlayImageData;
        void* getOverlayErrorNameFromEnum_ = (void*) getOverlayErrorNameFromEnum;
        void* setOverlayFlag_ = (void*) setOverlayFlag;
        void* getOverlayFlag_ = (void*) getOverlayFlag;
        void* setOverlayColor_ = (void*) setOverlayColor;
        void* getOverlayColor_ = (void*) getOverlayColor;
        void* setOverlayAlpha_ = (void*) setOverlayAlpha;
        void* getOverlayAlpha_ = (void*) getOverlayAlpha;
        void* setOverlayWidthInMeters_ = (void*) setOverlayWidthInMeters;
        void* getOverlayWidthInMeters_ = (void*) getOverlayWidthInMeters;
        void* setOverlayAutoCurveDistanceRangeInMeters_ = (void*) setOverlayAutoCurveDistanceRangeInMeters;
        void* getOverlayAutoCurveDistanceRangeInMeters_ = (void*) getOverlayAutoCurveDistanceRangeInMeters;
        void* setOverlayTextureColorSpace_ = (void*) setOverlayTextureColorSpace;
        void* getOverlayTextureColorSpace_ = (void*) getOverlayTextureColorSpace;
        void* setOverlayTextureBounds_ = (void*) setOverlayTextureBounds;
        void* getOverlayTextureBounds_ = (void*) getOverlayTextureBounds;
        void* getOverlayTransformType_ = (void*) getOverlayTransformType;
        void* setOverlayTransformAbsolute_ = (void*) setOverlayTransformAbsolute;
        void* getOverlayTransformAbsolute_ = (void*) getOverlayTransformAbsolute;
        void* setOverlayTransformTrackedDeviceRelative_ = (void*) setOverlayTransformTrackedDeviceRelative;
        void* getOverlayTransformTrackedDeviceRelative_ = (void*) getOverlayTransformTrackedDeviceRelative;
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
        void* handleControllerOverlayInteractionAsMouse_ = (void*) handleControllerOverlayInteractionAsMouse;
        void* isHoverTargetOverlay_ = (void*) isHoverTargetOverlay;
        void* getGamepadFocusOverlay_ = (void*) getGamepadFocusOverlay;
        void* setGamepadFocusOverlay_ = (void*) setGamepadFocusOverlay;
        void* setOverlayNeighbor_ = (void*) setOverlayNeighbor;
        void* moveGamepadFocusToNeighbor_ = (void*) moveGamepadFocusToNeighbor;
        void* setOverlayTexture_ = (void*) setOverlayTexture;
        void* clearOverlayTexture_ = (void*) clearOverlayTexture;
        void* setOverlayRaw_ = (void*) setOverlayRaw;
        void* setOverlayFromFile_ = (void*) setOverlayFromFile;
        void* createDashboardOverlay_ = (void*) createDashboardOverlay;
        void* isDashboardVisible_ = (void*) isDashboardVisible;
        void* isActiveDashboardOverlay_ = (void*) isActiveDashboardOverlay;
        void* setDashboardOverlaySceneProcess_ = (void*) setDashboardOverlaySceneProcess;
        void* getDashboardOverlaySceneProcess_ = (void*) getDashboardOverlaySceneProcess;
        void* showDashboard_ = (void*) showDashboard;
        void* showKeyboard_ = (void*) showKeyboard;
        void* showKeyboardForOverlay_ = (void*) showKeyboardForOverlay;
        void* getKeyboardText_ = (void*) getKeyboardText;
        void* hideKeyboard_ = (void*) hideKeyboard;
        void* setKeyboardTransformAbsolute_ = (void*) setKeyboardTransformAbsolute;
        void* setKeyboardPositionForOverlay_ = (void*) setKeyboardPositionForOverlay;
    };

    class Overlay_008_v
    {
        public:
            virtual OverlayError findOverlay(const char* key, uint64_t* handle) { return Overlay_008::findOverlay(key, handle); }
            virtual OverlayError createOverlay(const char* key, const char* name, uint64_t* handle) { return Overlay_008::createOverlay(key, name, handle); }
            virtual OverlayError destroyOverlay(uint64_t handle) { return Overlay_008::destroyOverlay(handle); }
            virtual OverlayError setHighQualityOverlay(uint64_t handle) { return Overlay_008::setHighQualityOverlay(handle); }
            virtual uint64_t getHighQualityOverlay() { return Overlay_008::getHighQualityOverlay(); }
            virtual uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_008::getOverlayKey(handle, value, bufferSize, error); }
            virtual uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_008::getOverlayName(handle, value, bufferSize, error); }
            virtual OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height) { return Overlay_008::getOverlayImageData(handle, buffer, bufferSize, width, height); }
            virtual const char* getOverlayErrorNameFromEnum(OverlayError error) { return Overlay_008::getOverlayErrorNameFromEnum(error); }
            virtual OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled) { return Overlay_008::setOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled) { return Overlay_008::getOverlayFlag(handle, flag, enabled); }
            virtual OverlayError setOverlayColor(uint64_t handle, float r, float g, float b) { return Overlay_008::setOverlayColor(handle, r, g, b); }
            virtual OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b) { return Overlay_008::getOverlayColor(handle, r, g, b); }
            virtual OverlayError setOverlayAlpha(uint64_t handle, float alpha) { return Overlay_008::setOverlayAlpha(handle, alpha); }
            virtual OverlayError getOverlayAlpha(uint64_t handle, float* alpha) { return Overlay_008::getOverlayAlpha(handle, alpha); }
            virtual OverlayError setOverlayWidthInMeters(uint64_t handle, float width) { return Overlay_008::setOverlayWidthInMeters(handle, width); }
            virtual OverlayError getOverlayWidthInMeters(uint64_t handle, float* width) { return Overlay_008::getOverlayWidthInMeters(handle, width); }
            virtual OverlayError setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance) { return Overlay_008::setOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance) { return Overlay_008::getOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace) { return Overlay_008::setOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace) { return Overlay_008::getOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds) { return Overlay_008::setOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_008::getOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType) { return Overlay_008::getOverlayTransformType(handle, transformType); }
            virtual OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_008::setOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix) { return Overlay_008::getOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix) { return Overlay_008::setOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix) { return Overlay_008::getOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError showOverlay(uint64_t handle) { return Overlay_008::showOverlay(handle); }
            virtual OverlayError hideOverlay(uint64_t handle) { return Overlay_008::hideOverlay(handle); }
            virtual bool isOverlayVisible(uint64_t handle) { return Overlay_008::isOverlayVisible(handle); }
            virtual OverlayError getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix) { return Overlay_008::getTransformForOverlayCoordinates(handle, origin, coordinatesInOverlay, matrix); }
            virtual bool pollNextOverlayEvent(uint64_t handle, Event_0_9_0* event) { return Overlay_008::pollNextOverlayEvent(handle, event); }
            virtual OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod) { return Overlay_008::getOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod) { return Overlay_008::setOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale) { return Overlay_008::getOverlayMouseScale(handle, mouseScale); }
            virtual OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale) { return Overlay_008::setOverlayMouseScale(handle, mouseScale); }
            virtual bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results) { return Overlay_008::computeOverlayIntersection(handle, params, results); }
            virtual bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex) { return Overlay_008::handleControllerOverlayInteractionAsMouse(handle, controllerDeviceIndex); }
            virtual bool isHoverTargetOverlay(uint64_t handle) { return Overlay_008::isHoverTargetOverlay(handle); }
            virtual uint64_t getGamepadFocusOverlay() { return Overlay_008::getGamepadFocusOverlay(); }
            virtual OverlayError setGamepadFocusOverlay(uint64_t handle) { return Overlay_008::setGamepadFocusOverlay(handle); }
            virtual OverlayError setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to) { return Overlay_008::setOverlayNeighbor(direction, from, to); }
            virtual OverlayError moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from) { return Overlay_008::moveGamepadFocusToNeighbor(direction, from); }
            virtual OverlayError setOverlayTexture(uint64_t handle, const Texture* texture) { return Overlay_008::setOverlayTexture(handle, texture); }
            virtual OverlayError clearOverlayTexture(uint64_t handle) { return Overlay_008::clearOverlayTexture(handle); }
            virtual OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth) { return Overlay_008::setOverlayRaw(handle, buffer, width, height, depth); }
            virtual OverlayError setOverlayFromFile(uint64_t handle, const char* filePath) { return Overlay_008::setOverlayFromFile(handle, filePath); }
            virtual OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle) { return Overlay_008::createDashboardOverlay(key, friendlyName, mainHandle, thumbnailHandle); }
            virtual bool isDashboardVisible() { return Overlay_008::isDashboardVisible(); }
            virtual bool isActiveDashboardOverlay(uint64_t handle) { return Overlay_008::isActiveDashboardOverlay(handle); }
            virtual OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid) { return Overlay_008::setDashboardOverlaySceneProcess(handle, pid); }
            virtual OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid) { return Overlay_008::getDashboardOverlaySceneProcess(handle, pid); }
            virtual void showDashboard(const char* overlayToShow) { return Overlay_008::showDashboard(overlayToShow); }
            virtual OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_008::showKeyboard(textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_008::showKeyboardForOverlay(handle, textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual uint32_t getKeyboardText(char* text, uint32_t bufferSize) { return Overlay_008::getKeyboardText(text, bufferSize); }
            virtual void hideKeyboard() { return Overlay_008::hideKeyboard(); }
            virtual void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_008::setKeyboardTransformAbsolute(origin, matrix); }
            virtual void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect) { return Overlay_008::setKeyboardPositionForOverlay(handle, avoidRect); }
    };

    //

    struct Overlay_010
    {
        static OverlayError findOverlay(const char* key, uint64_t* handle);

        static OverlayError createOverlay(const char* key, const char* name, uint64_t* handle);
        static OverlayError destroyOverlay(uint64_t handle);

        static OverlayError setHighQualityOverlay(uint64_t handle);
        static uint64_t getHighQualityOverlay();

        static uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height);

        static const char* getOverlayErrorNameFromEnum(OverlayError error);

        static OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled);
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled);
        static OverlayError setOverlayColor(uint64_t handle, float r, float g, float b);
        static OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b);
        static OverlayError setOverlayAlpha(uint64_t handle, float alpha);
        static OverlayError getOverlayAlpha(uint64_t handle, float* alpha);

        static OverlayError setOverlayWidthInMeters(uint64_t handle, float width);
        static OverlayError getOverlayWidthInMeters(uint64_t handle, float* width);
        static OverlayError setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance);
        static OverlayError getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance);

        static OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace);
        static OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace);
        static OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds);
        static OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds);

        static OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType);
        static OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix);
        static OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix);
        static OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName);
        static OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize);

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
        static bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex);
        static bool isHoverTargetOverlay(uint64_t handle);

        static uint64_t getGamepadFocusOverlay();
        static OverlayError setGamepadFocusOverlay(uint64_t handle);
        static OverlayError setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to);
        static OverlayError moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from);

        static OverlayError setOverlayTexture(uint64_t handle, const Texture* texture);
        static OverlayError clearOverlayTexture(uint64_t handle);
        static OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth);
        static OverlayError setOverlayFromFile(uint64_t handle, const char* filePath);

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

        void* findOverlay_ = (void*) findOverlay;
        void* createOverlay_ = (void*) createOverlay;
        void* destroyOverlay_ = (void*) destroyOverlay;
        void* setHighQualityOverlay_ = (void*) setHighQualityOverlay;
        void* getHighQualityOverlay_ = (void*) getHighQualityOverlay;
        void* getOverlayKey_ = (void*) getOverlayKey;
        void* getOverlayName_ = (void*) getOverlayName;
        void* getOverlayImageData_ = (void*) getOverlayImageData;
        void* getOverlayErrorNameFromEnum_ = (void*) getOverlayErrorNameFromEnum;
        void* setOverlayFlag_ = (void*) setOverlayFlag;
        void* getOverlayFlag_ = (void*) getOverlayFlag;
        void* setOverlayColor_ = (void*) setOverlayColor;
        void* getOverlayColor_ = (void*) getOverlayColor;
        void* setOverlayAlpha_ = (void*) setOverlayAlpha;
        void* getOverlayAlpha_ = (void*) getOverlayAlpha;
        void* setOverlayWidthInMeters_ = (void*) setOverlayWidthInMeters;
        void* getOverlayWidthInMeters_ = (void*) getOverlayWidthInMeters;
        void* setOverlayAutoCurveDistanceRangeInMeters_ = (void*) setOverlayAutoCurveDistanceRangeInMeters;
        void* getOverlayAutoCurveDistanceRangeInMeters_ = (void*) getOverlayAutoCurveDistanceRangeInMeters;
        void* setOverlayTextureColorSpace_ = (void*) setOverlayTextureColorSpace;
        void* getOverlayTextureColorSpace_ = (void*) getOverlayTextureColorSpace;
        void* setOverlayTextureBounds_ = (void*) setOverlayTextureBounds;
        void* getOverlayTextureBounds_ = (void*) getOverlayTextureBounds;
        void* getOverlayTransformType_ = (void*) getOverlayTransformType;
        void* setOverlayTransformAbsolute_ = (void*) setOverlayTransformAbsolute;
        void* getOverlayTransformAbsolute_ = (void*) getOverlayTransformAbsolute;
        void* setOverlayTransformTrackedDeviceRelative_ = (void*) setOverlayTransformTrackedDeviceRelative;
        void* getOverlayTransformTrackedDeviceRelative_ = (void*) getOverlayTransformTrackedDeviceRelative;
        void* setOverlayTransformTrackedDeviceComponent_ = (void*) setOverlayTransformTrackedDeviceComponent;
        void* getOverlayTransformTrackedDeviceComponent_ = (void*) getOverlayTransformTrackedDeviceComponent;
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
        void* handleControllerOverlayInteractionAsMouse_ = (void*) handleControllerOverlayInteractionAsMouse;
        void* isHoverTargetOverlay_ = (void*) isHoverTargetOverlay;
        void* getGamepadFocusOverlay_ = (void*) getGamepadFocusOverlay;
        void* setGamepadFocusOverlay_ = (void*) setGamepadFocusOverlay;
        void* setOverlayNeighbor_ = (void*) setOverlayNeighbor;
        void* moveGamepadFocusToNeighbor_ = (void*) moveGamepadFocusToNeighbor;
        void* setOverlayTexture_ = (void*) setOverlayTexture;
        void* clearOverlayTexture_ = (void*) clearOverlayTexture;
        void* setOverlayRaw_ = (void*) setOverlayRaw;
        void* setOverlayFromFile_ = (void*) setOverlayFromFile;
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
    };

    class Overlay_010_v
    {
        public:
            virtual OverlayError findOverlay(const char* key, uint64_t* handle) { return Overlay_010::findOverlay(key, handle); }
            virtual OverlayError createOverlay(const char* key, const char* name, uint64_t* handle) { return Overlay_010::createOverlay(key, name, handle); }
            virtual OverlayError destroyOverlay(uint64_t handle) { return Overlay_010::destroyOverlay(handle); }
            virtual OverlayError setHighQualityOverlay(uint64_t handle) { return Overlay_010::setHighQualityOverlay(handle); }
            virtual uint64_t getHighQualityOverlay() { return Overlay_010::getHighQualityOverlay(); }
            virtual uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_010::getOverlayKey(handle, value, bufferSize, error); }
            virtual uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_010::getOverlayName(handle, value, bufferSize, error); }
            virtual OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height) { return Overlay_010::getOverlayImageData(handle, buffer, bufferSize, width, height); }
            virtual const char* getOverlayErrorNameFromEnum(OverlayError error) { return Overlay_010::getOverlayErrorNameFromEnum(error); }
            virtual OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled) { return Overlay_010::setOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled) { return Overlay_010::getOverlayFlag(handle, flag, enabled); }
            virtual OverlayError setOverlayColor(uint64_t handle, float r, float g, float b) { return Overlay_010::setOverlayColor(handle, r, g, b); }
            virtual OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b) { return Overlay_010::getOverlayColor(handle, r, g, b); }
            virtual OverlayError setOverlayAlpha(uint64_t handle, float alpha) { return Overlay_010::setOverlayAlpha(handle, alpha); }
            virtual OverlayError getOverlayAlpha(uint64_t handle, float* alpha) { return Overlay_010::getOverlayAlpha(handle, alpha); }
            virtual OverlayError setOverlayWidthInMeters(uint64_t handle, float width) { return Overlay_010::setOverlayWidthInMeters(handle, width); }
            virtual OverlayError getOverlayWidthInMeters(uint64_t handle, float* width) { return Overlay_010::getOverlayWidthInMeters(handle, width); }
            virtual OverlayError setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance) { return Overlay_010::setOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance) { return Overlay_010::getOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace) { return Overlay_010::setOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace) { return Overlay_010::getOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds) { return Overlay_010::setOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_010::getOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType) { return Overlay_010::getOverlayTransformType(handle, transformType); }
            virtual OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_010::setOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix) { return Overlay_010::getOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix) { return Overlay_010::setOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix) { return Overlay_010::getOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName) { return Overlay_010::setOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName); }
            virtual OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize) { return Overlay_010::getOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName, bufferSize); }
            virtual OverlayError showOverlay(uint64_t handle) { return Overlay_010::showOverlay(handle); }
            virtual OverlayError hideOverlay(uint64_t handle) { return Overlay_010::hideOverlay(handle); }
            virtual bool isOverlayVisible(uint64_t handle) { return Overlay_010::isOverlayVisible(handle); }
            virtual OverlayError getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix) { return Overlay_010::getTransformForOverlayCoordinates(handle, origin, coordinatesInOverlay, matrix); }
            virtual bool pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t eventSize) { return Overlay_010::pollNextOverlayEvent(handle, event, eventSize); }
            virtual OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod) { return Overlay_010::getOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod) { return Overlay_010::setOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale) { return Overlay_010::getOverlayMouseScale(handle, mouseScale); }
            virtual OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale) { return Overlay_010::setOverlayMouseScale(handle, mouseScale); }
            virtual bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results) { return Overlay_010::computeOverlayIntersection(handle, params, results); }
            virtual bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex) { return Overlay_010::handleControllerOverlayInteractionAsMouse(handle, controllerDeviceIndex); }
            virtual bool isHoverTargetOverlay(uint64_t handle) { return Overlay_010::isHoverTargetOverlay(handle); }
            virtual uint64_t getGamepadFocusOverlay() { return Overlay_010::getGamepadFocusOverlay(); }
            virtual OverlayError setGamepadFocusOverlay(uint64_t handle) { return Overlay_010::setGamepadFocusOverlay(handle); }
            virtual OverlayError setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to) { return Overlay_010::setOverlayNeighbor(direction, from, to); }
            virtual OverlayError moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from) { return Overlay_010::moveGamepadFocusToNeighbor(direction, from); }
            virtual OverlayError setOverlayTexture(uint64_t handle, const Texture* texture) { return Overlay_010::setOverlayTexture(handle, texture); }
            virtual OverlayError clearOverlayTexture(uint64_t handle) { return Overlay_010::clearOverlayTexture(handle); }
            virtual OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth) { return Overlay_010::setOverlayRaw(handle, buffer, width, height, depth); }
            virtual OverlayError setOverlayFromFile(uint64_t handle, const char* filePath) { return Overlay_010::setOverlayFromFile(handle, filePath); }
            virtual OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle) { return Overlay_010::createDashboardOverlay(key, friendlyName, mainHandle, thumbnailHandle); }
            virtual bool isDashboardVisible() { return Overlay_010::isDashboardVisible(); }
            virtual bool isActiveDashboardOverlay(uint64_t handle) { return Overlay_010::isActiveDashboardOverlay(handle); }
            virtual OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid) { return Overlay_010::setDashboardOverlaySceneProcess(handle, pid); }
            virtual OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid) { return Overlay_010::getDashboardOverlaySceneProcess(handle, pid); }
            virtual void showDashboard(const char* overlayToShow) { return Overlay_010::showDashboard(overlayToShow); }
            virtual uint32_t getPrimaryDashboardInputTrackedDevice() { return Overlay_010::getPrimaryDashboardInputTrackedDevice(); }
            virtual OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_010::showKeyboard(textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_010::showKeyboardForOverlay(handle, textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual uint32_t getKeyboardText(char* text, uint32_t bufferSize) { return Overlay_010::getKeyboardText(text, bufferSize); }
            virtual void hideKeyboard() { return Overlay_010::hideKeyboard(); }
            virtual void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_010::setKeyboardTransformAbsolute(origin, matrix); }
            virtual void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect) { return Overlay_010::setKeyboardPositionForOverlay(handle, avoidRect); }
    };

    //

    struct Overlay_011
    {
        static OverlayError findOverlay(const char* key, uint64_t* handle);

        static OverlayError createOverlay(const char* key, const char* name, uint64_t* handle);
        static OverlayError destroyOverlay(uint64_t handle);

        static OverlayError setHighQualityOverlay(uint64_t handle);
        static uint64_t getHighQualityOverlay();

        static uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height);

        static const char* getOverlayErrorNameFromEnum(OverlayError error);

        static OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid);
        static uint32_t getOverlayRenderingPid(uint64_t handle);

        static OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled);
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled);
        static OverlayError setOverlayColor(uint64_t handle, float r, float g, float b);
        static OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b);
        static OverlayError setOverlayAlpha(uint64_t handle, float alpha);
        static OverlayError getOverlayAlpha(uint64_t handle, float* alpha);

        static OverlayError setOverlayWidthInMeters(uint64_t handle, float width);
        static OverlayError getOverlayWidthInMeters(uint64_t handle, float* width);
        static OverlayError setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance);
        static OverlayError getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance);

        static OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace);
        static OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace);
        static OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds);
        static OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds);

        static OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType);
        static OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix);
        static OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix);
        static OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName);
        static OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize);

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
        static bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex);
        static bool isHoverTargetOverlay(uint64_t handle);

        static uint64_t getGamepadFocusOverlay();
        static OverlayError setGamepadFocusOverlay(uint64_t handle);
        static OverlayError setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to);
        static OverlayError moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from);

        static OverlayError setOverlayTexture(uint64_t handle, const Texture* texture);
        static OverlayError clearOverlayTexture(uint64_t handle);
        static OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth);
        static OverlayError setOverlayFromFile(uint64_t handle, const char* filePath);
        static OverlayError getOverlayNativeTexture(uint64_t handle, void** nativeTextureHandle, void* nativeTextureRef, uint32_t* width, uint32_t* height, uint32_t* format, TextureType* type, ColorSpace* colorSpace);
        static OverlayError releaseNativeOverlayTexture(uint64_t handle, void* nativeTextureHandle);

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

        void* findOverlay_ = (void*) findOverlay;
        void* createOverlay_ = (void*) createOverlay;
        void* destroyOverlay_ = (void*) destroyOverlay;
        void* setHighQualityOverlay_ = (void*) setHighQualityOverlay;
        void* getHighQualityOverlay_ = (void*) getHighQualityOverlay;
        void* getOverlayKey_ = (void*) getOverlayKey;
        void* getOverlayName_ = (void*) getOverlayName;
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
        void* setOverlayWidthInMeters_ = (void*) setOverlayWidthInMeters;
        void* getOverlayWidthInMeters_ = (void*) getOverlayWidthInMeters;
        void* setOverlayAutoCurveDistanceRangeInMeters_ = (void*) setOverlayAutoCurveDistanceRangeInMeters;
        void* getOverlayAutoCurveDistanceRangeInMeters_ = (void*) getOverlayAutoCurveDistanceRangeInMeters;
        void* setOverlayTextureColorSpace_ = (void*) setOverlayTextureColorSpace;
        void* getOverlayTextureColorSpace_ = (void*) getOverlayTextureColorSpace;
        void* setOverlayTextureBounds_ = (void*) setOverlayTextureBounds;
        void* getOverlayTextureBounds_ = (void*) getOverlayTextureBounds;
        void* getOverlayTransformType_ = (void*) getOverlayTransformType;
        void* setOverlayTransformAbsolute_ = (void*) setOverlayTransformAbsolute;
        void* getOverlayTransformAbsolute_ = (void*) getOverlayTransformAbsolute;
        void* setOverlayTransformTrackedDeviceRelative_ = (void*) setOverlayTransformTrackedDeviceRelative;
        void* getOverlayTransformTrackedDeviceRelative_ = (void*) getOverlayTransformTrackedDeviceRelative;
        void* setOverlayTransformTrackedDeviceComponent_ = (void*) setOverlayTransformTrackedDeviceComponent;
        void* getOverlayTransformTrackedDeviceComponent_ = (void*) getOverlayTransformTrackedDeviceComponent;
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
        void* handleControllerOverlayInteractionAsMouse_ = (void*) handleControllerOverlayInteractionAsMouse;
        void* isHoverTargetOverlay_ = (void*) isHoverTargetOverlay;
        void* getGamepadFocusOverlay_ = (void*) getGamepadFocusOverlay;
        void* setGamepadFocusOverlay_ = (void*) setGamepadFocusOverlay;
        void* setOverlayNeighbor_ = (void*) setOverlayNeighbor;
        void* moveGamepadFocusToNeighbor_ = (void*) moveGamepadFocusToNeighbor;
        void* setOverlayTexture_ = (void*) setOverlayTexture;
        void* clearOverlayTexture_ = (void*) clearOverlayTexture;
        void* setOverlayRaw_ = (void*) setOverlayRaw;
        void* setOverlayFromFile_ = (void*) setOverlayFromFile;
        void* getOverlayNativeTexture_ = (void*) getOverlayNativeTexture;
        void* releaseNativeOverlayTexture_ = (void*) releaseNativeOverlayTexture;
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
    };

    class Overlay_011_v
    {
        public:
            virtual OverlayError findOverlay(const char* key, uint64_t* handle) { return Overlay_011::findOverlay(key, handle); }
            virtual OverlayError createOverlay(const char* key, const char* name, uint64_t* handle) { return Overlay_011::createOverlay(key, name, handle); }
            virtual OverlayError destroyOverlay(uint64_t handle) { return Overlay_011::destroyOverlay(handle); }
            virtual OverlayError setHighQualityOverlay(uint64_t handle) { return Overlay_011::setHighQualityOverlay(handle); }
            virtual uint64_t getHighQualityOverlay() { return Overlay_011::getHighQualityOverlay(); }
            virtual uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_011::getOverlayKey(handle, value, bufferSize, error); }
            virtual uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_011::getOverlayName(handle, value, bufferSize, error); }
            virtual OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height) { return Overlay_011::getOverlayImageData(handle, buffer, bufferSize, width, height); }
            virtual const char* getOverlayErrorNameFromEnum(OverlayError error) { return Overlay_011::getOverlayErrorNameFromEnum(error); }
            virtual OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid) { return Overlay_011::setOverlayRenderingPid(handle, pid); }
            virtual uint32_t getOverlayRenderingPid(uint64_t handle) { return Overlay_011::getOverlayRenderingPid(handle); }
            virtual OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled) { return Overlay_011::setOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled) { return Overlay_011::getOverlayFlag(handle, flag, enabled); }
            virtual OverlayError setOverlayColor(uint64_t handle, float r, float g, float b) { return Overlay_011::setOverlayColor(handle, r, g, b); }
            virtual OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b) { return Overlay_011::getOverlayColor(handle, r, g, b); }
            virtual OverlayError setOverlayAlpha(uint64_t handle, float alpha) { return Overlay_011::setOverlayAlpha(handle, alpha); }
            virtual OverlayError getOverlayAlpha(uint64_t handle, float* alpha) { return Overlay_011::getOverlayAlpha(handle, alpha); }
            virtual OverlayError setOverlayWidthInMeters(uint64_t handle, float width) { return Overlay_011::setOverlayWidthInMeters(handle, width); }
            virtual OverlayError getOverlayWidthInMeters(uint64_t handle, float* width) { return Overlay_011::getOverlayWidthInMeters(handle, width); }
            virtual OverlayError setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance) { return Overlay_011::setOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance) { return Overlay_011::getOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace) { return Overlay_011::setOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace) { return Overlay_011::getOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds) { return Overlay_011::setOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_011::getOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType) { return Overlay_011::getOverlayTransformType(handle, transformType); }
            virtual OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_011::setOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix) { return Overlay_011::getOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix) { return Overlay_011::setOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix) { return Overlay_011::getOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName) { return Overlay_011::setOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName); }
            virtual OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize) { return Overlay_011::getOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName, bufferSize); }
            virtual OverlayError showOverlay(uint64_t handle) { return Overlay_011::showOverlay(handle); }
            virtual OverlayError hideOverlay(uint64_t handle) { return Overlay_011::hideOverlay(handle); }
            virtual bool isOverlayVisible(uint64_t handle) { return Overlay_011::isOverlayVisible(handle); }
            virtual OverlayError getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix) { return Overlay_011::getTransformForOverlayCoordinates(handle, origin, coordinatesInOverlay, matrix); }
            virtual bool pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t eventSize) { return Overlay_011::pollNextOverlayEvent(handle, event, eventSize); }
            virtual OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod) { return Overlay_011::getOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod) { return Overlay_011::setOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale) { return Overlay_011::getOverlayMouseScale(handle, mouseScale); }
            virtual OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale) { return Overlay_011::setOverlayMouseScale(handle, mouseScale); }
            virtual bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results) { return Overlay_011::computeOverlayIntersection(handle, params, results); }
            virtual bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex) { return Overlay_011::handleControllerOverlayInteractionAsMouse(handle, controllerDeviceIndex); }
            virtual bool isHoverTargetOverlay(uint64_t handle) { return Overlay_011::isHoverTargetOverlay(handle); }
            virtual uint64_t getGamepadFocusOverlay() { return Overlay_011::getGamepadFocusOverlay(); }
            virtual OverlayError setGamepadFocusOverlay(uint64_t handle) { return Overlay_011::setGamepadFocusOverlay(handle); }
            virtual OverlayError setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to) { return Overlay_011::setOverlayNeighbor(direction, from, to); }
            virtual OverlayError moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from) { return Overlay_011::moveGamepadFocusToNeighbor(direction, from); }
            virtual OverlayError setOverlayTexture(uint64_t handle, const Texture* texture) { return Overlay_011::setOverlayTexture(handle, texture); }
            virtual OverlayError clearOverlayTexture(uint64_t handle) { return Overlay_011::clearOverlayTexture(handle); }
            virtual OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth) { return Overlay_011::setOverlayRaw(handle, buffer, width, height, depth); }
            virtual OverlayError setOverlayFromFile(uint64_t handle, const char* filePath) { return Overlay_011::setOverlayFromFile(handle, filePath); }
            virtual OverlayError getOverlayNativeTexture(uint64_t handle, void** nativeTextureHandle, void* nativeTextureRef, uint32_t* width, uint32_t* height, uint32_t* format, TextureType* type, ColorSpace* colorSpace) { return Overlay_011::getOverlayNativeTexture(handle, nativeTextureHandle, nativeTextureRef, width, height, format, type, colorSpace); }
            virtual OverlayError releaseNativeOverlayTexture(uint64_t handle, void* nativeTextureHandle) { return Overlay_011::releaseNativeOverlayTexture(handle, nativeTextureHandle); }
            virtual OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle) { return Overlay_011::createDashboardOverlay(key, friendlyName, mainHandle, thumbnailHandle); }
            virtual bool isDashboardVisible() { return Overlay_011::isDashboardVisible(); }
            virtual bool isActiveDashboardOverlay(uint64_t handle) { return Overlay_011::isActiveDashboardOverlay(handle); }
            virtual OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid) { return Overlay_011::setDashboardOverlaySceneProcess(handle, pid); }
            virtual OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid) { return Overlay_011::getDashboardOverlaySceneProcess(handle, pid); }
            virtual void showDashboard(const char* overlayToShow) { return Overlay_011::showDashboard(overlayToShow); }
            virtual uint32_t getPrimaryDashboardInputTrackedDevice() { return Overlay_011::getPrimaryDashboardInputTrackedDevice(); }
            virtual OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_011::showKeyboard(textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_011::showKeyboardForOverlay(handle, textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual uint32_t getKeyboardText(char* text, uint32_t bufferSize) { return Overlay_011::getKeyboardText(text, bufferSize); }
            virtual void hideKeyboard() { return Overlay_011::hideKeyboard(); }
            virtual void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_011::setKeyboardTransformAbsolute(origin, matrix); }
            virtual void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect) { return Overlay_011::setKeyboardPositionForOverlay(handle, avoidRect); }
    };

    //

    struct Overlay_012
    {
        static OverlayError findOverlay(const char* key, uint64_t* handle);

        static OverlayError createOverlay(const char* key, const char* name, uint64_t* handle);
        static OverlayError destroyOverlay(uint64_t handle);

        static OverlayError setHighQualityOverlay(uint64_t handle);
        static uint64_t getHighQualityOverlay();

        static uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height);

        static const char* getOverlayErrorNameFromEnum(OverlayError error);

        static OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid);
        static uint32_t getOverlayRenderingPid(uint64_t handle);

        static OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled);
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled);
        static OverlayError setOverlayColor(uint64_t handle, float r, float g, float b);
        static OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b);
        static OverlayError setOverlayAlpha(uint64_t handle, float alpha);
        static OverlayError getOverlayAlpha(uint64_t handle, float* alpha);

        static OverlayError setOverlayWidthInMeters(uint64_t handle, float width);
        static OverlayError getOverlayWidthInMeters(uint64_t handle, float* width);
        static OverlayError setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance);
        static OverlayError getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance);

        static OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace);
        static OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace);
        static OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds);
        static OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds);

        static OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType);
        static OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix);
        static OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix);
        static OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName);
        static OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize);

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
        static bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex);
        static bool isHoverTargetOverlay(uint64_t handle);

        static uint64_t getGamepadFocusOverlay();
        static OverlayError setGamepadFocusOverlay(uint64_t handle);
        static OverlayError setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to);
        static OverlayError moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from);

        static OverlayError setOverlayTexture(uint64_t handle, const Texture* texture);
        static OverlayError clearOverlayTexture(uint64_t handle);
        static OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth);
        static OverlayError setOverlayFromFile(uint64_t handle, const char* filePath);
        static OverlayError getOverlayNativeTexture(uint64_t handle, void** nativeTextureHandle, void* nativeTextureRef, uint32_t* width, uint32_t* height, uint32_t* format, TextureType* type, ColorSpace* colorSpace);
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

        void* findOverlay_ = (void*) findOverlay;
        void* createOverlay_ = (void*) createOverlay;
        void* destroyOverlay_ = (void*) destroyOverlay;
        void* setHighQualityOverlay_ = (void*) setHighQualityOverlay;
        void* getHighQualityOverlay_ = (void*) getHighQualityOverlay;
        void* getOverlayKey_ = (void*) getOverlayKey;
        void* getOverlayName_ = (void*) getOverlayName;
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
        void* setOverlayWidthInMeters_ = (void*) setOverlayWidthInMeters;
        void* getOverlayWidthInMeters_ = (void*) getOverlayWidthInMeters;
        void* setOverlayAutoCurveDistanceRangeInMeters_ = (void*) setOverlayAutoCurveDistanceRangeInMeters;
        void* getOverlayAutoCurveDistanceRangeInMeters_ = (void*) getOverlayAutoCurveDistanceRangeInMeters;
        void* setOverlayTextureColorSpace_ = (void*) setOverlayTextureColorSpace;
        void* getOverlayTextureColorSpace_ = (void*) getOverlayTextureColorSpace;
        void* setOverlayTextureBounds_ = (void*) setOverlayTextureBounds;
        void* getOverlayTextureBounds_ = (void*) getOverlayTextureBounds;
        void* getOverlayTransformType_ = (void*) getOverlayTransformType;
        void* setOverlayTransformAbsolute_ = (void*) setOverlayTransformAbsolute;
        void* getOverlayTransformAbsolute_ = (void*) getOverlayTransformAbsolute;
        void* setOverlayTransformTrackedDeviceRelative_ = (void*) setOverlayTransformTrackedDeviceRelative;
        void* getOverlayTransformTrackedDeviceRelative_ = (void*) getOverlayTransformTrackedDeviceRelative;
        void* setOverlayTransformTrackedDeviceComponent_ = (void*) setOverlayTransformTrackedDeviceComponent;
        void* getOverlayTransformTrackedDeviceComponent_ = (void*) getOverlayTransformTrackedDeviceComponent;
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
        void* handleControllerOverlayInteractionAsMouse_ = (void*) handleControllerOverlayInteractionAsMouse;
        void* isHoverTargetOverlay_ = (void*) isHoverTargetOverlay;
        void* getGamepadFocusOverlay_ = (void*) getGamepadFocusOverlay;
        void* setGamepadFocusOverlay_ = (void*) setGamepadFocusOverlay;
        void* setOverlayNeighbor_ = (void*) setOverlayNeighbor;
        void* moveGamepadFocusToNeighbor_ = (void*) moveGamepadFocusToNeighbor;
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
    };

    class Overlay_012_v
    {
        public:
            virtual OverlayError findOverlay(const char* key, uint64_t* handle) { return Overlay_012::findOverlay(key, handle); }
            virtual OverlayError createOverlay(const char* key, const char* name, uint64_t* handle) { return Overlay_012::createOverlay(key, name, handle); }
            virtual OverlayError destroyOverlay(uint64_t handle) { return Overlay_012::destroyOverlay(handle); }
            virtual OverlayError setHighQualityOverlay(uint64_t handle) { return Overlay_012::setHighQualityOverlay(handle); }
            virtual uint64_t getHighQualityOverlay() { return Overlay_012::getHighQualityOverlay(); }
            virtual uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_012::getOverlayKey(handle, value, bufferSize, error); }
            virtual uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_012::getOverlayName(handle, value, bufferSize, error); }
            virtual OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height) { return Overlay_012::getOverlayImageData(handle, buffer, bufferSize, width, height); }
            virtual const char* getOverlayErrorNameFromEnum(OverlayError error) { return Overlay_012::getOverlayErrorNameFromEnum(error); }
            virtual OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid) { return Overlay_012::setOverlayRenderingPid(handle, pid); }
            virtual uint32_t getOverlayRenderingPid(uint64_t handle) { return Overlay_012::getOverlayRenderingPid(handle); }
            virtual OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled) { return Overlay_012::setOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled) { return Overlay_012::getOverlayFlag(handle, flag, enabled); }
            virtual OverlayError setOverlayColor(uint64_t handle, float r, float g, float b) { return Overlay_012::setOverlayColor(handle, r, g, b); }
            virtual OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b) { return Overlay_012::getOverlayColor(handle, r, g, b); }
            virtual OverlayError setOverlayAlpha(uint64_t handle, float alpha) { return Overlay_012::setOverlayAlpha(handle, alpha); }
            virtual OverlayError getOverlayAlpha(uint64_t handle, float* alpha) { return Overlay_012::getOverlayAlpha(handle, alpha); }
            virtual OverlayError setOverlayWidthInMeters(uint64_t handle, float width) { return Overlay_012::setOverlayWidthInMeters(handle, width); }
            virtual OverlayError getOverlayWidthInMeters(uint64_t handle, float* width) { return Overlay_012::getOverlayWidthInMeters(handle, width); }
            virtual OverlayError setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance) { return Overlay_012::setOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance) { return Overlay_012::getOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace) { return Overlay_012::setOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace) { return Overlay_012::getOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds) { return Overlay_012::setOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_012::getOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType) { return Overlay_012::getOverlayTransformType(handle, transformType); }
            virtual OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_012::setOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix) { return Overlay_012::getOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix) { return Overlay_012::setOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix) { return Overlay_012::getOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName) { return Overlay_012::setOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName); }
            virtual OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize) { return Overlay_012::getOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName, bufferSize); }
            virtual OverlayError showOverlay(uint64_t handle) { return Overlay_012::showOverlay(handle); }
            virtual OverlayError hideOverlay(uint64_t handle) { return Overlay_012::hideOverlay(handle); }
            virtual bool isOverlayVisible(uint64_t handle) { return Overlay_012::isOverlayVisible(handle); }
            virtual OverlayError getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix) { return Overlay_012::getTransformForOverlayCoordinates(handle, origin, coordinatesInOverlay, matrix); }
            virtual bool pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t eventSize) { return Overlay_012::pollNextOverlayEvent(handle, event, eventSize); }
            virtual OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod) { return Overlay_012::getOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod) { return Overlay_012::setOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale) { return Overlay_012::getOverlayMouseScale(handle, mouseScale); }
            virtual OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale) { return Overlay_012::setOverlayMouseScale(handle, mouseScale); }
            virtual bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results) { return Overlay_012::computeOverlayIntersection(handle, params, results); }
            virtual bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex) { return Overlay_012::handleControllerOverlayInteractionAsMouse(handle, controllerDeviceIndex); }
            virtual bool isHoverTargetOverlay(uint64_t handle) { return Overlay_012::isHoverTargetOverlay(handle); }
            virtual uint64_t getGamepadFocusOverlay() { return Overlay_012::getGamepadFocusOverlay(); }
            virtual OverlayError setGamepadFocusOverlay(uint64_t handle) { return Overlay_012::setGamepadFocusOverlay(handle); }
            virtual OverlayError setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to) { return Overlay_012::setOverlayNeighbor(direction, from, to); }
            virtual OverlayError moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from) { return Overlay_012::moveGamepadFocusToNeighbor(direction, from); }
            virtual OverlayError setOverlayTexture(uint64_t handle, const Texture* texture) { return Overlay_012::setOverlayTexture(handle, texture); }
            virtual OverlayError clearOverlayTexture(uint64_t handle) { return Overlay_012::clearOverlayTexture(handle); }
            virtual OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth) { return Overlay_012::setOverlayRaw(handle, buffer, width, height, depth); }
            virtual OverlayError setOverlayFromFile(uint64_t handle, const char* filePath) { return Overlay_012::setOverlayFromFile(handle, filePath); }
            virtual OverlayError getOverlayNativeTexture(uint64_t handle, void** nativeTextureHandle, void* nativeTextureRef, uint32_t* width, uint32_t* height, uint32_t* format, TextureType* type, ColorSpace* colorSpace) { return Overlay_012::getOverlayNativeTexture(handle, nativeTextureHandle, nativeTextureRef, width, height, format, type, colorSpace); }
            virtual OverlayError releaseNativeOverlayTexture(uint64_t handle, void* nativeTextureHandle) { return Overlay_012::releaseNativeOverlayTexture(handle, nativeTextureHandle); }
            virtual OverlayError getOverlayTextureSize(uint64_t handle, uint32_t* width, uint32_t* height) { return Overlay_012::getOverlayTextureSize(handle, width, height); }
            virtual OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle) { return Overlay_012::createDashboardOverlay(key, friendlyName, mainHandle, thumbnailHandle); }
            virtual bool isDashboardVisible() { return Overlay_012::isDashboardVisible(); }
            virtual bool isActiveDashboardOverlay(uint64_t handle) { return Overlay_012::isActiveDashboardOverlay(handle); }
            virtual OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid) { return Overlay_012::setDashboardOverlaySceneProcess(handle, pid); }
            virtual OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid) { return Overlay_012::getDashboardOverlaySceneProcess(handle, pid); }
            virtual void showDashboard(const char* overlayToShow) { return Overlay_012::showDashboard(overlayToShow); }
            virtual uint32_t getPrimaryDashboardInputTrackedDevice() { return Overlay_012::getPrimaryDashboardInputTrackedDevice(); }
            virtual OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_012::showKeyboard(textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_012::showKeyboardForOverlay(handle, textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual uint32_t getKeyboardText(char* text, uint32_t bufferSize) { return Overlay_012::getKeyboardText(text, bufferSize); }
            virtual void hideKeyboard() { return Overlay_012::hideKeyboard(); }
            virtual void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_012::setKeyboardTransformAbsolute(origin, matrix); }
            virtual void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect) { return Overlay_012::setKeyboardPositionForOverlay(handle, avoidRect); }
    };

    //

    struct Overlay_013
    {
        static OverlayError findOverlay(const char* key, uint64_t* handle);

        static OverlayError createOverlay(const char* key, const char* name, uint64_t* handle);
        static OverlayError destroyOverlay(uint64_t handle);

        static OverlayError setHighQualityOverlay(uint64_t handle);
        static uint64_t getHighQualityOverlay();

        static uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height);

        static const char* getOverlayErrorNameFromEnum(OverlayError error);

        static OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid);
        static uint32_t getOverlayRenderingPid(uint64_t handle);

        static OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled);
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled);
        static OverlayError setOverlayColor(uint64_t handle, float r, float g, float b);
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
        static OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds);
        static OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds);

        static OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType);
        static OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix);
        static OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix);
        static OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName);
        static OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize);

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
        static bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex);
        static bool isHoverTargetOverlay(uint64_t handle);

        static uint64_t getGamepadFocusOverlay();
        static OverlayError setGamepadFocusOverlay(uint64_t handle);
        static OverlayError setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to);
        static OverlayError moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from);

        static OverlayError setOverlayTexture(uint64_t handle, const Texture* texture);
        static OverlayError clearOverlayTexture(uint64_t handle);
        static OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth);
        static OverlayError setOverlayFromFile(uint64_t handle, const char* filePath);
        static OverlayError getOverlayNativeTexture(uint64_t handle, void** nativeTextureHandle, void* nativeTextureRef, uint32_t* width, uint32_t* height, uint32_t* format, TextureType* type, ColorSpace* colorSpace);
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

        void* findOverlay_ = (void*) findOverlay;
        void* createOverlay_ = (void*) createOverlay;
        void* destroyOverlay_ = (void*) destroyOverlay;
        void* setHighQualityOverlay_ = (void*) setHighQualityOverlay;
        void* getHighQualityOverlay_ = (void*) getHighQualityOverlay;
        void* getOverlayKey_ = (void*) getOverlayKey;
        void* getOverlayName_ = (void*) getOverlayName;
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
        void* getOverlayTransformType_ = (void*) getOverlayTransformType;
        void* setOverlayTransformAbsolute_ = (void*) setOverlayTransformAbsolute;
        void* getOverlayTransformAbsolute_ = (void*) getOverlayTransformAbsolute;
        void* setOverlayTransformTrackedDeviceRelative_ = (void*) setOverlayTransformTrackedDeviceRelative;
        void* getOverlayTransformTrackedDeviceRelative_ = (void*) getOverlayTransformTrackedDeviceRelative;
        void* setOverlayTransformTrackedDeviceComponent_ = (void*) setOverlayTransformTrackedDeviceComponent;
        void* getOverlayTransformTrackedDeviceComponent_ = (void*) getOverlayTransformTrackedDeviceComponent;
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
        void* handleControllerOverlayInteractionAsMouse_ = (void*) handleControllerOverlayInteractionAsMouse;
        void* isHoverTargetOverlay_ = (void*) isHoverTargetOverlay;
        void* getGamepadFocusOverlay_ = (void*) getGamepadFocusOverlay;
        void* setGamepadFocusOverlay_ = (void*) setGamepadFocusOverlay;
        void* setOverlayNeighbor_ = (void*) setOverlayNeighbor;
        void* moveGamepadFocusToNeighbor_ = (void*) moveGamepadFocusToNeighbor;
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
    };

    class Overlay_013_v
    {
        public:
            virtual OverlayError findOverlay(const char* key, uint64_t* handle) { return Overlay_013::findOverlay(key, handle); }
            virtual OverlayError createOverlay(const char* key, const char* name, uint64_t* handle) { return Overlay_013::createOverlay(key, name, handle); }
            virtual OverlayError destroyOverlay(uint64_t handle) { return Overlay_013::destroyOverlay(handle); }
            virtual OverlayError setHighQualityOverlay(uint64_t handle) { return Overlay_013::setHighQualityOverlay(handle); }
            virtual uint64_t getHighQualityOverlay() { return Overlay_013::getHighQualityOverlay(); }
            virtual uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_013::getOverlayKey(handle, value, bufferSize, error); }
            virtual uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_013::getOverlayName(handle, value, bufferSize, error); }
            virtual OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height) { return Overlay_013::getOverlayImageData(handle, buffer, bufferSize, width, height); }
            virtual const char* getOverlayErrorNameFromEnum(OverlayError error) { return Overlay_013::getOverlayErrorNameFromEnum(error); }
            virtual OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid) { return Overlay_013::setOverlayRenderingPid(handle, pid); }
            virtual uint32_t getOverlayRenderingPid(uint64_t handle) { return Overlay_013::getOverlayRenderingPid(handle); }
            virtual OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled) { return Overlay_013::setOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled) { return Overlay_013::getOverlayFlag(handle, flag, enabled); }
            virtual OverlayError setOverlayColor(uint64_t handle, float r, float g, float b) { return Overlay_013::setOverlayColor(handle, r, g, b); }
            virtual OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b) { return Overlay_013::getOverlayColor(handle, r, g, b); }
            virtual OverlayError setOverlayAlpha(uint64_t handle, float alpha) { return Overlay_013::setOverlayAlpha(handle, alpha); }
            virtual OverlayError getOverlayAlpha(uint64_t handle, float* alpha) { return Overlay_013::getOverlayAlpha(handle, alpha); }
            virtual OverlayError setOverlayTexelAspectRatio(uint64_t handle, float aspect) { return Overlay_013::setOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError getOverlayTexelAspectRatio(uint64_t handle, float* aspect) { return Overlay_013::getOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError setOverlaySortOrder(uint64_t handle, uint32_t sortOrder) { return Overlay_013::setOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder) { return Overlay_013::getOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError setOverlayWidthInMeters(uint64_t handle, float width) { return Overlay_013::setOverlayWidthInMeters(handle, width); }
            virtual OverlayError getOverlayWidthInMeters(uint64_t handle, float* width) { return Overlay_013::getOverlayWidthInMeters(handle, width); }
            virtual OverlayError setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance) { return Overlay_013::setOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance) { return Overlay_013::getOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace) { return Overlay_013::setOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace) { return Overlay_013::getOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds) { return Overlay_013::setOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_013::getOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType) { return Overlay_013::getOverlayTransformType(handle, transformType); }
            virtual OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_013::setOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix) { return Overlay_013::getOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix) { return Overlay_013::setOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix) { return Overlay_013::getOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName) { return Overlay_013::setOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName); }
            virtual OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize) { return Overlay_013::getOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName, bufferSize); }
            virtual OverlayError showOverlay(uint64_t handle) { return Overlay_013::showOverlay(handle); }
            virtual OverlayError hideOverlay(uint64_t handle) { return Overlay_013::hideOverlay(handle); }
            virtual bool isOverlayVisible(uint64_t handle) { return Overlay_013::isOverlayVisible(handle); }
            virtual OverlayError getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix) { return Overlay_013::getTransformForOverlayCoordinates(handle, origin, coordinatesInOverlay, matrix); }
            virtual bool pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t eventSize) { return Overlay_013::pollNextOverlayEvent(handle, event, eventSize); }
            virtual OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod) { return Overlay_013::getOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod) { return Overlay_013::setOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale) { return Overlay_013::getOverlayMouseScale(handle, mouseScale); }
            virtual OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale) { return Overlay_013::setOverlayMouseScale(handle, mouseScale); }
            virtual bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results) { return Overlay_013::computeOverlayIntersection(handle, params, results); }
            virtual bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex) { return Overlay_013::handleControllerOverlayInteractionAsMouse(handle, controllerDeviceIndex); }
            virtual bool isHoverTargetOverlay(uint64_t handle) { return Overlay_013::isHoverTargetOverlay(handle); }
            virtual uint64_t getGamepadFocusOverlay() { return Overlay_013::getGamepadFocusOverlay(); }
            virtual OverlayError setGamepadFocusOverlay(uint64_t handle) { return Overlay_013::setGamepadFocusOverlay(handle); }
            virtual OverlayError setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to) { return Overlay_013::setOverlayNeighbor(direction, from, to); }
            virtual OverlayError moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from) { return Overlay_013::moveGamepadFocusToNeighbor(direction, from); }
            virtual OverlayError setOverlayTexture(uint64_t handle, const Texture* texture) { return Overlay_013::setOverlayTexture(handle, texture); }
            virtual OverlayError clearOverlayTexture(uint64_t handle) { return Overlay_013::clearOverlayTexture(handle); }
            virtual OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth) { return Overlay_013::setOverlayRaw(handle, buffer, width, height, depth); }
            virtual OverlayError setOverlayFromFile(uint64_t handle, const char* filePath) { return Overlay_013::setOverlayFromFile(handle, filePath); }
            virtual OverlayError getOverlayNativeTexture(uint64_t handle, void** nativeTextureHandle, void* nativeTextureRef, uint32_t* width, uint32_t* height, uint32_t* format, TextureType* type, ColorSpace* colorSpace) { return Overlay_013::getOverlayNativeTexture(handle, nativeTextureHandle, nativeTextureRef, width, height, format, type, colorSpace); }
            virtual OverlayError releaseNativeOverlayTexture(uint64_t handle, void* nativeTextureHandle) { return Overlay_013::releaseNativeOverlayTexture(handle, nativeTextureHandle); }
            virtual OverlayError getOverlayTextureSize(uint64_t handle, uint32_t* width, uint32_t* height) { return Overlay_013::getOverlayTextureSize(handle, width, height); }
            virtual OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle) { return Overlay_013::createDashboardOverlay(key, friendlyName, mainHandle, thumbnailHandle); }
            virtual bool isDashboardVisible() { return Overlay_013::isDashboardVisible(); }
            virtual bool isActiveDashboardOverlay(uint64_t handle) { return Overlay_013::isActiveDashboardOverlay(handle); }
            virtual OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid) { return Overlay_013::setDashboardOverlaySceneProcess(handle, pid); }
            virtual OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid) { return Overlay_013::getDashboardOverlaySceneProcess(handle, pid); }
            virtual void showDashboard(const char* overlayToShow) { return Overlay_013::showDashboard(overlayToShow); }
            virtual uint32_t getPrimaryDashboardInputTrackedDevice() { return Overlay_013::getPrimaryDashboardInputTrackedDevice(); }
            virtual OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_013::showKeyboard(textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_013::showKeyboardForOverlay(handle, textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual uint32_t getKeyboardText(char* text, uint32_t bufferSize) { return Overlay_013::getKeyboardText(text, bufferSize); }
            virtual void hideKeyboard() { return Overlay_013::hideKeyboard(); }
            virtual void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_013::setKeyboardTransformAbsolute(origin, matrix); }
            virtual void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect) { return Overlay_013::setKeyboardPositionForOverlay(handle, avoidRect); }
    };

    //

    struct Overlay_014
    {
        static OverlayError findOverlay(const char* key, uint64_t* handle);

        static OverlayError createOverlay(const char* key, const char* name, uint64_t* handle);
        static OverlayError destroyOverlay(uint64_t handle);

        static OverlayError setHighQualityOverlay(uint64_t handle);
        static uint64_t getHighQualityOverlay();

        static uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height);

        static const char* getOverlayErrorNameFromEnum(OverlayError error);

        static OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid);
        static uint32_t getOverlayRenderingPid(uint64_t handle);

        static OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled);
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled);
        static OverlayError setOverlayColor(uint64_t handle, float r, float g, float b);
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
        static OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds);
        static OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds);

        static OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType);
        static OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix);
        static OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix);
        static OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName);
        static OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize);

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
        static bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex);
        static bool isHoverTargetOverlay(uint64_t handle);

        static uint64_t getGamepadFocusOverlay();
        static OverlayError setGamepadFocusOverlay(uint64_t handle);
        static OverlayError setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to);
        static OverlayError moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from);

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

        void* findOverlay_ = (void*) findOverlay;
        void* createOverlay_ = (void*) createOverlay;
        void* destroyOverlay_ = (void*) destroyOverlay;
        void* setHighQualityOverlay_ = (void*) setHighQualityOverlay;
        void* getHighQualityOverlay_ = (void*) getHighQualityOverlay;
        void* getOverlayKey_ = (void*) getOverlayKey;
        void* getOverlayName_ = (void*) getOverlayName;
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
        void* getOverlayTransformType_ = (void*) getOverlayTransformType;
        void* setOverlayTransformAbsolute_ = (void*) setOverlayTransformAbsolute;
        void* getOverlayTransformAbsolute_ = (void*) getOverlayTransformAbsolute;
        void* setOverlayTransformTrackedDeviceRelative_ = (void*) setOverlayTransformTrackedDeviceRelative;
        void* getOverlayTransformTrackedDeviceRelative_ = (void*) getOverlayTransformTrackedDeviceRelative;
        void* setOverlayTransformTrackedDeviceComponent_ = (void*) setOverlayTransformTrackedDeviceComponent;
        void* getOverlayTransformTrackedDeviceComponent_ = (void*) getOverlayTransformTrackedDeviceComponent;
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
        void* handleControllerOverlayInteractionAsMouse_ = (void*) handleControllerOverlayInteractionAsMouse;
        void* isHoverTargetOverlay_ = (void*) isHoverTargetOverlay;
        void* getGamepadFocusOverlay_ = (void*) getGamepadFocusOverlay;
        void* setGamepadFocusOverlay_ = (void*) setGamepadFocusOverlay;
        void* setOverlayNeighbor_ = (void*) setOverlayNeighbor;
        void* moveGamepadFocusToNeighbor_ = (void*) moveGamepadFocusToNeighbor;
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
    };

    class Overlay_014_v
    {
        public:
            virtual OverlayError findOverlay(const char* key, uint64_t* handle) { return Overlay_014::findOverlay(key, handle); }
            virtual OverlayError createOverlay(const char* key, const char* name, uint64_t* handle) { return Overlay_014::createOverlay(key, name, handle); }
            virtual OverlayError destroyOverlay(uint64_t handle) { return Overlay_014::destroyOverlay(handle); }
            virtual OverlayError setHighQualityOverlay(uint64_t handle) { return Overlay_014::setHighQualityOverlay(handle); }
            virtual uint64_t getHighQualityOverlay() { return Overlay_014::getHighQualityOverlay(); }
            virtual uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_014::getOverlayKey(handle, value, bufferSize, error); }
            virtual uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_014::getOverlayName(handle, value, bufferSize, error); }
            virtual OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height) { return Overlay_014::getOverlayImageData(handle, buffer, bufferSize, width, height); }
            virtual const char* getOverlayErrorNameFromEnum(OverlayError error) { return Overlay_014::getOverlayErrorNameFromEnum(error); }
            virtual OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid) { return Overlay_014::setOverlayRenderingPid(handle, pid); }
            virtual uint32_t getOverlayRenderingPid(uint64_t handle) { return Overlay_014::getOverlayRenderingPid(handle); }
            virtual OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled) { return Overlay_014::setOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled) { return Overlay_014::getOverlayFlag(handle, flag, enabled); }
            virtual OverlayError setOverlayColor(uint64_t handle, float r, float g, float b) { return Overlay_014::setOverlayColor(handle, r, g, b); }
            virtual OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b) { return Overlay_014::getOverlayColor(handle, r, g, b); }
            virtual OverlayError setOverlayAlpha(uint64_t handle, float alpha) { return Overlay_014::setOverlayAlpha(handle, alpha); }
            virtual OverlayError getOverlayAlpha(uint64_t handle, float* alpha) { return Overlay_014::getOverlayAlpha(handle, alpha); }
            virtual OverlayError setOverlayTexelAspectRatio(uint64_t handle, float aspect) { return Overlay_014::setOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError getOverlayTexelAspectRatio(uint64_t handle, float* aspect) { return Overlay_014::getOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError setOverlaySortOrder(uint64_t handle, uint32_t sortOrder) { return Overlay_014::setOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder) { return Overlay_014::getOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError setOverlayWidthInMeters(uint64_t handle, float width) { return Overlay_014::setOverlayWidthInMeters(handle, width); }
            virtual OverlayError getOverlayWidthInMeters(uint64_t handle, float* width) { return Overlay_014::getOverlayWidthInMeters(handle, width); }
            virtual OverlayError setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance) { return Overlay_014::setOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance) { return Overlay_014::getOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace) { return Overlay_014::setOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace) { return Overlay_014::getOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds) { return Overlay_014::setOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_014::getOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType) { return Overlay_014::getOverlayTransformType(handle, transformType); }
            virtual OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_014::setOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix) { return Overlay_014::getOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix) { return Overlay_014::setOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix) { return Overlay_014::getOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName) { return Overlay_014::setOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName); }
            virtual OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize) { return Overlay_014::getOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName, bufferSize); }
            virtual OverlayError showOverlay(uint64_t handle) { return Overlay_014::showOverlay(handle); }
            virtual OverlayError hideOverlay(uint64_t handle) { return Overlay_014::hideOverlay(handle); }
            virtual bool isOverlayVisible(uint64_t handle) { return Overlay_014::isOverlayVisible(handle); }
            virtual OverlayError getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix) { return Overlay_014::getTransformForOverlayCoordinates(handle, origin, coordinatesInOverlay, matrix); }
            virtual bool pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t eventSize) { return Overlay_014::pollNextOverlayEvent(handle, event, eventSize); }
            virtual OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod) { return Overlay_014::getOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod) { return Overlay_014::setOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale) { return Overlay_014::getOverlayMouseScale(handle, mouseScale); }
            virtual OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale) { return Overlay_014::setOverlayMouseScale(handle, mouseScale); }
            virtual bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results) { return Overlay_014::computeOverlayIntersection(handle, params, results); }
            virtual bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex) { return Overlay_014::handleControllerOverlayInteractionAsMouse(handle, controllerDeviceIndex); }
            virtual bool isHoverTargetOverlay(uint64_t handle) { return Overlay_014::isHoverTargetOverlay(handle); }
            virtual uint64_t getGamepadFocusOverlay() { return Overlay_014::getGamepadFocusOverlay(); }
            virtual OverlayError setGamepadFocusOverlay(uint64_t handle) { return Overlay_014::setGamepadFocusOverlay(handle); }
            virtual OverlayError setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to) { return Overlay_014::setOverlayNeighbor(direction, from, to); }
            virtual OverlayError moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from) { return Overlay_014::moveGamepadFocusToNeighbor(direction, from); }
            virtual OverlayError setOverlayTexture(uint64_t handle, const Texture* texture) { return Overlay_014::setOverlayTexture(handle, texture); }
            virtual OverlayError clearOverlayTexture(uint64_t handle) { return Overlay_014::clearOverlayTexture(handle); }
            virtual OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth) { return Overlay_014::setOverlayRaw(handle, buffer, width, height, depth); }
            virtual OverlayError setOverlayFromFile(uint64_t handle, const char* filePath) { return Overlay_014::setOverlayFromFile(handle, filePath); }
            virtual OverlayError getOverlayNativeTexture(uint64_t handle, void** nativeTextureHandle, void* nativeTextureRef, uint32_t* width, uint32_t* height, uint32_t* format, TextureType* type, ColorSpace* colorSpace, TextureBounds* bounds) { return Overlay_014::getOverlayNativeTexture(handle, nativeTextureHandle, nativeTextureRef, width, height, format, type, colorSpace, bounds); }
            virtual OverlayError releaseNativeOverlayTexture(uint64_t handle, void* nativeTextureHandle) { return Overlay_014::releaseNativeOverlayTexture(handle, nativeTextureHandle); }
            virtual OverlayError getOverlayTextureSize(uint64_t handle, uint32_t* width, uint32_t* height) { return Overlay_014::getOverlayTextureSize(handle, width, height); }
            virtual OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle) { return Overlay_014::createDashboardOverlay(key, friendlyName, mainHandle, thumbnailHandle); }
            virtual bool isDashboardVisible() { return Overlay_014::isDashboardVisible(); }
            virtual bool isActiveDashboardOverlay(uint64_t handle) { return Overlay_014::isActiveDashboardOverlay(handle); }
            virtual OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid) { return Overlay_014::setDashboardOverlaySceneProcess(handle, pid); }
            virtual OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid) { return Overlay_014::getDashboardOverlaySceneProcess(handle, pid); }
            virtual void showDashboard(const char* overlayToShow) { return Overlay_014::showDashboard(overlayToShow); }
            virtual uint32_t getPrimaryDashboardInputTrackedDevice() { return Overlay_014::getPrimaryDashboardInputTrackedDevice(); }
            virtual OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_014::showKeyboard(textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_014::showKeyboardForOverlay(handle, textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual uint32_t getKeyboardText(char* text, uint32_t bufferSize) { return Overlay_014::getKeyboardText(text, bufferSize); }
            virtual void hideKeyboard() { return Overlay_014::hideKeyboard(); }
            virtual void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_014::setKeyboardTransformAbsolute(origin, matrix); }
            virtual void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect) { return Overlay_014::setKeyboardPositionForOverlay(handle, avoidRect); }
            virtual OverlayError setOverlayIntersectionMask(uint64_t handle, OverlayIntersectionMaskPrimitive* primitives, uint32_t primitivesCount, uint32_t primitiveSize) { return Overlay_014::setOverlayIntersectionMask(handle, primitives, primitivesCount, primitiveSize); }
            virtual OverlayError getOverlayFlags(uint64_t handle, uint32_t* flags) { return Overlay_014::getOverlayFlags(handle, flags); }
            virtual MessageOverlayResponse showMessageOverlay(const char* text, const char* caption, const char* button0Text, const char* button1Text, const char* button2Text, const char* button3Text) { return Overlay_014::showMessageOverlay(text, caption, button0Text, button1Text, button2Text, button3Text); }
    };

    //

    struct Overlay_016
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
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled);
        static OverlayError setOverlayColor(uint64_t handle, float r, float g, float b);
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
        static OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds);
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
        static bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex);
        static bool isHoverTargetOverlay(uint64_t handle);

        static uint64_t getGamepadFocusOverlay();
        static OverlayError setGamepadFocusOverlay(uint64_t handle);
        static OverlayError setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to);
        static OverlayError moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from);

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
        void* handleControllerOverlayInteractionAsMouse_ = (void*) handleControllerOverlayInteractionAsMouse;
        void* isHoverTargetOverlay_ = (void*) isHoverTargetOverlay;
        void* getGamepadFocusOverlay_ = (void*) getGamepadFocusOverlay;
        void* setGamepadFocusOverlay_ = (void*) setGamepadFocusOverlay;
        void* setOverlayNeighbor_ = (void*) setOverlayNeighbor;
        void* moveGamepadFocusToNeighbor_ = (void*) moveGamepadFocusToNeighbor;
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

    class Overlay_016_v
    {
        public:
            virtual OverlayError findOverlay(const char* key, uint64_t* handle) { return Overlay_016::findOverlay(key, handle); }
            virtual OverlayError createOverlay(const char* key, const char* name, uint64_t* handle) { return Overlay_016::createOverlay(key, name, handle); }
            virtual OverlayError destroyOverlay(uint64_t handle) { return Overlay_016::destroyOverlay(handle); }
            virtual OverlayError setHighQualityOverlay(uint64_t handle) { return Overlay_016::setHighQualityOverlay(handle); }
            virtual uint64_t getHighQualityOverlay() { return Overlay_016::getHighQualityOverlay(); }
            virtual uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_016::getOverlayKey(handle, value, bufferSize, error); }
            virtual uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_016::getOverlayName(handle, value, bufferSize, error); }
            virtual OverlayError setOverlayName(uint64_t handle, const char* name) { return Overlay_016::setOverlayName(handle, name); }
            virtual OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height) { return Overlay_016::getOverlayImageData(handle, buffer, bufferSize, width, height); }
            virtual const char* getOverlayErrorNameFromEnum(OverlayError error) { return Overlay_016::getOverlayErrorNameFromEnum(error); }
            virtual OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid) { return Overlay_016::setOverlayRenderingPid(handle, pid); }
            virtual uint32_t getOverlayRenderingPid(uint64_t handle) { return Overlay_016::getOverlayRenderingPid(handle); }
            virtual OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled) { return Overlay_016::setOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled) { return Overlay_016::getOverlayFlag(handle, flag, enabled); }
            virtual OverlayError setOverlayColor(uint64_t handle, float r, float g, float b) { return Overlay_016::setOverlayColor(handle, r, g, b); }
            virtual OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b) { return Overlay_016::getOverlayColor(handle, r, g, b); }
            virtual OverlayError setOverlayAlpha(uint64_t handle, float alpha) { return Overlay_016::setOverlayAlpha(handle, alpha); }
            virtual OverlayError getOverlayAlpha(uint64_t handle, float* alpha) { return Overlay_016::getOverlayAlpha(handle, alpha); }
            virtual OverlayError setOverlayTexelAspectRatio(uint64_t handle, float aspect) { return Overlay_016::setOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError getOverlayTexelAspectRatio(uint64_t handle, float* aspect) { return Overlay_016::getOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError setOverlaySortOrder(uint64_t handle, uint32_t sortOrder) { return Overlay_016::setOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder) { return Overlay_016::getOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError setOverlayWidthInMeters(uint64_t handle, float width) { return Overlay_016::setOverlayWidthInMeters(handle, width); }
            virtual OverlayError getOverlayWidthInMeters(uint64_t handle, float* width) { return Overlay_016::getOverlayWidthInMeters(handle, width); }
            virtual OverlayError setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance) { return Overlay_016::setOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance) { return Overlay_016::getOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace) { return Overlay_016::setOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace) { return Overlay_016::getOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds) { return Overlay_016::setOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_016::getOverlayTextureBounds(handle, bounds); }
            virtual uint32_t getOverlayRenderModel(uint64_t handle, char* renderModel, uint32_t bufferSize, Color* color, OverlayError* error) { return Overlay_016::getOverlayRenderModel(handle, renderModel, bufferSize, color, error); }
            virtual OverlayError setOverlayRenderModel(uint64_t handle, const char* renderModel, const Color* color) { return Overlay_016::setOverlayRenderModel(handle, renderModel, color); }
            virtual OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType) { return Overlay_016::getOverlayTransformType(handle, transformType); }
            virtual OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_016::setOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix) { return Overlay_016::getOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix) { return Overlay_016::setOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix) { return Overlay_016::getOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName) { return Overlay_016::setOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName); }
            virtual OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize) { return Overlay_016::getOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName, bufferSize); }
            virtual OverlayError getOverlayTransformOverlayRelative(uint64_t handle, uint64_t* parentHandle, Matrix34* matrix) { return Overlay_016::getOverlayTransformOverlayRelative(handle, parentHandle, matrix); }
            virtual OverlayError setOverlayTransformOverlayRelative(uint64_t handle, uint64_t parentHandle, const Matrix34* matrix) { return Overlay_016::setOverlayTransformOverlayRelative(handle, parentHandle, matrix); }
            virtual OverlayError showOverlay(uint64_t handle) { return Overlay_016::showOverlay(handle); }
            virtual OverlayError hideOverlay(uint64_t handle) { return Overlay_016::hideOverlay(handle); }
            virtual bool isOverlayVisible(uint64_t handle) { return Overlay_016::isOverlayVisible(handle); }
            virtual OverlayError getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix) { return Overlay_016::getTransformForOverlayCoordinates(handle, origin, coordinatesInOverlay, matrix); }
            virtual bool pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t eventSize) { return Overlay_016::pollNextOverlayEvent(handle, event, eventSize); }
            virtual OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod) { return Overlay_016::getOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod) { return Overlay_016::setOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale) { return Overlay_016::getOverlayMouseScale(handle, mouseScale); }
            virtual OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale) { return Overlay_016::setOverlayMouseScale(handle, mouseScale); }
            virtual bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results) { return Overlay_016::computeOverlayIntersection(handle, params, results); }
            virtual bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex) { return Overlay_016::handleControllerOverlayInteractionAsMouse(handle, controllerDeviceIndex); }
            virtual bool isHoverTargetOverlay(uint64_t handle) { return Overlay_016::isHoverTargetOverlay(handle); }
            virtual uint64_t getGamepadFocusOverlay() { return Overlay_016::getGamepadFocusOverlay(); }
            virtual OverlayError setGamepadFocusOverlay(uint64_t handle) { return Overlay_016::setGamepadFocusOverlay(handle); }
            virtual OverlayError setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to) { return Overlay_016::setOverlayNeighbor(direction, from, to); }
            virtual OverlayError moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from) { return Overlay_016::moveGamepadFocusToNeighbor(direction, from); }
            virtual OverlayError setOverlayTexture(uint64_t handle, const Texture* texture) { return Overlay_016::setOverlayTexture(handle, texture); }
            virtual OverlayError clearOverlayTexture(uint64_t handle) { return Overlay_016::clearOverlayTexture(handle); }
            virtual OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth) { return Overlay_016::setOverlayRaw(handle, buffer, width, height, depth); }
            virtual OverlayError setOverlayFromFile(uint64_t handle, const char* filePath) { return Overlay_016::setOverlayFromFile(handle, filePath); }
            virtual OverlayError getOverlayNativeTexture(uint64_t handle, void** nativeTextureHandle, void* nativeTextureRef, uint32_t* width, uint32_t* height, uint32_t* format, TextureType* type, ColorSpace* colorSpace, TextureBounds* bounds) { return Overlay_016::getOverlayNativeTexture(handle, nativeTextureHandle, nativeTextureRef, width, height, format, type, colorSpace, bounds); }
            virtual OverlayError releaseNativeOverlayTexture(uint64_t handle, void* nativeTextureHandle) { return Overlay_016::releaseNativeOverlayTexture(handle, nativeTextureHandle); }
            virtual OverlayError getOverlayTextureSize(uint64_t handle, uint32_t* width, uint32_t* height) { return Overlay_016::getOverlayTextureSize(handle, width, height); }
            virtual OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle) { return Overlay_016::createDashboardOverlay(key, friendlyName, mainHandle, thumbnailHandle); }
            virtual bool isDashboardVisible() { return Overlay_016::isDashboardVisible(); }
            virtual bool isActiveDashboardOverlay(uint64_t handle) { return Overlay_016::isActiveDashboardOverlay(handle); }
            virtual OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid) { return Overlay_016::setDashboardOverlaySceneProcess(handle, pid); }
            virtual OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid) { return Overlay_016::getDashboardOverlaySceneProcess(handle, pid); }
            virtual void showDashboard(const char* overlayToShow) { return Overlay_016::showDashboard(overlayToShow); }
            virtual uint32_t getPrimaryDashboardInputTrackedDevice() { return Overlay_016::getPrimaryDashboardInputTrackedDevice(); }
            virtual OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_016::showKeyboard(textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_016::showKeyboardForOverlay(handle, textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual uint32_t getKeyboardText(char* text, uint32_t bufferSize) { return Overlay_016::getKeyboardText(text, bufferSize); }
            virtual void hideKeyboard() { return Overlay_016::hideKeyboard(); }
            virtual void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_016::setKeyboardTransformAbsolute(origin, matrix); }
            virtual void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect) { return Overlay_016::setKeyboardPositionForOverlay(handle, avoidRect); }
            virtual OverlayError setOverlayIntersectionMask(uint64_t handle, OverlayIntersectionMaskPrimitive* primitives, uint32_t primitivesCount, uint32_t primitiveSize) { return Overlay_016::setOverlayIntersectionMask(handle, primitives, primitivesCount, primitiveSize); }
            virtual OverlayError getOverlayFlags(uint64_t handle, uint32_t* flags) { return Overlay_016::getOverlayFlags(handle, flags); }
            virtual MessageOverlayResponse showMessageOverlay(const char* text, const char* caption, const char* button0Text, const char* button1Text, const char* button2Text, const char* button3Text) { return Overlay_016::showMessageOverlay(text, caption, button0Text, button1Text, button2Text, button3Text); }
            virtual void closeMessageOverlay() { return Overlay_016::closeMessageOverlay(); }
    };

    //

    struct Overlay_017
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
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled);
        static OverlayError setOverlayColor(uint64_t handle, float r, float g, float b);
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
        static OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds);
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
        static bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex);
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
        void* handleControllerOverlayInteractionAsMouse_ = (void*) handleControllerOverlayInteractionAsMouse;
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

    class Overlay_017_v
    {
        public:
            virtual OverlayError findOverlay(const char* key, uint64_t* handle) { return Overlay_017::findOverlay(key, handle); }
            virtual OverlayError createOverlay(const char* key, const char* name, uint64_t* handle) { return Overlay_017::createOverlay(key, name, handle); }
            virtual OverlayError destroyOverlay(uint64_t handle) { return Overlay_017::destroyOverlay(handle); }
            virtual OverlayError setHighQualityOverlay(uint64_t handle) { return Overlay_017::setHighQualityOverlay(handle); }
            virtual uint64_t getHighQualityOverlay() { return Overlay_017::getHighQualityOverlay(); }
            virtual uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_017::getOverlayKey(handle, value, bufferSize, error); }
            virtual uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_017::getOverlayName(handle, value, bufferSize, error); }
            virtual OverlayError setOverlayName(uint64_t handle, const char* name) { return Overlay_017::setOverlayName(handle, name); }
            virtual OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height) { return Overlay_017::getOverlayImageData(handle, buffer, bufferSize, width, height); }
            virtual const char* getOverlayErrorNameFromEnum(OverlayError error) { return Overlay_017::getOverlayErrorNameFromEnum(error); }
            virtual OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid) { return Overlay_017::setOverlayRenderingPid(handle, pid); }
            virtual uint32_t getOverlayRenderingPid(uint64_t handle) { return Overlay_017::getOverlayRenderingPid(handle); }
            virtual OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled) { return Overlay_017::setOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled) { return Overlay_017::getOverlayFlag(handle, flag, enabled); }
            virtual OverlayError setOverlayColor(uint64_t handle, float r, float g, float b) { return Overlay_017::setOverlayColor(handle, r, g, b); }
            virtual OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b) { return Overlay_017::getOverlayColor(handle, r, g, b); }
            virtual OverlayError setOverlayAlpha(uint64_t handle, float alpha) { return Overlay_017::setOverlayAlpha(handle, alpha); }
            virtual OverlayError getOverlayAlpha(uint64_t handle, float* alpha) { return Overlay_017::getOverlayAlpha(handle, alpha); }
            virtual OverlayError setOverlayTexelAspectRatio(uint64_t handle, float aspect) { return Overlay_017::setOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError getOverlayTexelAspectRatio(uint64_t handle, float* aspect) { return Overlay_017::getOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError setOverlaySortOrder(uint64_t handle, uint32_t sortOrder) { return Overlay_017::setOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder) { return Overlay_017::getOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError setOverlayWidthInMeters(uint64_t handle, float width) { return Overlay_017::setOverlayWidthInMeters(handle, width); }
            virtual OverlayError getOverlayWidthInMeters(uint64_t handle, float* width) { return Overlay_017::getOverlayWidthInMeters(handle, width); }
            virtual OverlayError setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance) { return Overlay_017::setOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance) { return Overlay_017::getOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace) { return Overlay_017::setOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace) { return Overlay_017::getOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds) { return Overlay_017::setOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_017::getOverlayTextureBounds(handle, bounds); }
            virtual uint32_t getOverlayRenderModel(uint64_t handle, char* renderModel, uint32_t bufferSize, Color* color, OverlayError* error) { return Overlay_017::getOverlayRenderModel(handle, renderModel, bufferSize, color, error); }
            virtual OverlayError setOverlayRenderModel(uint64_t handle, const char* renderModel, const Color* color) { return Overlay_017::setOverlayRenderModel(handle, renderModel, color); }
            virtual OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType) { return Overlay_017::getOverlayTransformType(handle, transformType); }
            virtual OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_017::setOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix) { return Overlay_017::getOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix) { return Overlay_017::setOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix) { return Overlay_017::getOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName) { return Overlay_017::setOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName); }
            virtual OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize) { return Overlay_017::getOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName, bufferSize); }
            virtual OverlayError getOverlayTransformOverlayRelative(uint64_t handle, uint64_t* parentHandle, Matrix34* matrix) { return Overlay_017::getOverlayTransformOverlayRelative(handle, parentHandle, matrix); }
            virtual OverlayError setOverlayTransformOverlayRelative(uint64_t handle, uint64_t parentHandle, const Matrix34* matrix) { return Overlay_017::setOverlayTransformOverlayRelative(handle, parentHandle, matrix); }
            virtual OverlayError showOverlay(uint64_t handle) { return Overlay_017::showOverlay(handle); }
            virtual OverlayError hideOverlay(uint64_t handle) { return Overlay_017::hideOverlay(handle); }
            virtual bool isOverlayVisible(uint64_t handle) { return Overlay_017::isOverlayVisible(handle); }
            virtual OverlayError getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix) { return Overlay_017::getTransformForOverlayCoordinates(handle, origin, coordinatesInOverlay, matrix); }
            virtual bool pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t eventSize) { return Overlay_017::pollNextOverlayEvent(handle, event, eventSize); }
            virtual OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod) { return Overlay_017::getOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod) { return Overlay_017::setOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale) { return Overlay_017::getOverlayMouseScale(handle, mouseScale); }
            virtual OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale) { return Overlay_017::setOverlayMouseScale(handle, mouseScale); }
            virtual bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results) { return Overlay_017::computeOverlayIntersection(handle, params, results); }
            virtual bool handleControllerOverlayInteractionAsMouse(uint64_t handle, uint32_t controllerDeviceIndex) { return Overlay_017::handleControllerOverlayInteractionAsMouse(handle, controllerDeviceIndex); }
            virtual bool isHoverTargetOverlay(uint64_t handle) { return Overlay_017::isHoverTargetOverlay(handle); }
            virtual uint64_t getGamepadFocusOverlay() { return Overlay_017::getGamepadFocusOverlay(); }
            virtual OverlayError setGamepadFocusOverlay(uint64_t handle) { return Overlay_017::setGamepadFocusOverlay(handle); }
            virtual OverlayError setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to) { return Overlay_017::setOverlayNeighbor(direction, from, to); }
            virtual OverlayError moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from) { return Overlay_017::moveGamepadFocusToNeighbor(direction, from); }
            virtual OverlayError setOverlayDualAnalogTransform(uint64_t handle, DualAnalogWhich which, const Vector2& center, float radius) { return Overlay_017::setOverlayDualAnalogTransform(handle, which, center, radius); }
            virtual OverlayError getOverlayDualAnalogTransform(uint64_t ulOverlay, DualAnalogWhich which, Vector2* center, float* radius) { return Overlay_017::getOverlayDualAnalogTransform(ulOverlay, which, center, radius); }
            virtual OverlayError setOverlayTexture(uint64_t handle, const Texture* texture) { return Overlay_017::setOverlayTexture(handle, texture); }
            virtual OverlayError clearOverlayTexture(uint64_t handle) { return Overlay_017::clearOverlayTexture(handle); }
            virtual OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth) { return Overlay_017::setOverlayRaw(handle, buffer, width, height, depth); }
            virtual OverlayError setOverlayFromFile(uint64_t handle, const char* filePath) { return Overlay_017::setOverlayFromFile(handle, filePath); }
            virtual OverlayError getOverlayNativeTexture(uint64_t handle, void** nativeTextureHandle, void* nativeTextureRef, uint32_t* width, uint32_t* height, uint32_t* format, TextureType* type, ColorSpace* colorSpace, TextureBounds* bounds) { return Overlay_017::getOverlayNativeTexture(handle, nativeTextureHandle, nativeTextureRef, width, height, format, type, colorSpace, bounds); }
            virtual OverlayError releaseNativeOverlayTexture(uint64_t handle, void* nativeTextureHandle) { return Overlay_017::releaseNativeOverlayTexture(handle, nativeTextureHandle); }
            virtual OverlayError getOverlayTextureSize(uint64_t handle, uint32_t* width, uint32_t* height) { return Overlay_017::getOverlayTextureSize(handle, width, height); }
            virtual OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle) { return Overlay_017::createDashboardOverlay(key, friendlyName, mainHandle, thumbnailHandle); }
            virtual bool isDashboardVisible() { return Overlay_017::isDashboardVisible(); }
            virtual bool isActiveDashboardOverlay(uint64_t handle) { return Overlay_017::isActiveDashboardOverlay(handle); }
            virtual OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid) { return Overlay_017::setDashboardOverlaySceneProcess(handle, pid); }
            virtual OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid) { return Overlay_017::getDashboardOverlaySceneProcess(handle, pid); }
            virtual void showDashboard(const char* overlayToShow) { return Overlay_017::showDashboard(overlayToShow); }
            virtual uint32_t getPrimaryDashboardInputTrackedDevice() { return Overlay_017::getPrimaryDashboardInputTrackedDevice(); }
            virtual OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_017::showKeyboard(textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_017::showKeyboardForOverlay(handle, textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual uint32_t getKeyboardText(char* text, uint32_t bufferSize) { return Overlay_017::getKeyboardText(text, bufferSize); }
            virtual void hideKeyboard() { return Overlay_017::hideKeyboard(); }
            virtual void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_017::setKeyboardTransformAbsolute(origin, matrix); }
            virtual void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect) { return Overlay_017::setKeyboardPositionForOverlay(handle, avoidRect); }
            virtual OverlayError setOverlayIntersectionMask(uint64_t handle, OverlayIntersectionMaskPrimitive* primitives, uint32_t primitivesCount, uint32_t primitiveSize) { return Overlay_017::setOverlayIntersectionMask(handle, primitives, primitivesCount, primitiveSize); }
            virtual OverlayError getOverlayFlags(uint64_t handle, uint32_t* flags) { return Overlay_017::getOverlayFlags(handle, flags); }
            virtual MessageOverlayResponse showMessageOverlay(const char* text, const char* caption, const char* button0Text, const char* button1Text, const char* button2Text, const char* button3Text) { return Overlay_017::showMessageOverlay(text, caption, button0Text, button1Text, button2Text, button3Text); }
            virtual void closeMessageOverlay() { return Overlay_017::closeMessageOverlay(); }
    };

    //

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
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled);
        static OverlayError setOverlayColor(uint64_t handle, float r, float g, float b);
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
        static OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds);
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
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled) { return Overlay_018::getOverlayFlag(handle, flag, enabled); }
            virtual OverlayError setOverlayColor(uint64_t handle, float r, float g, float b) { return Overlay_018::setOverlayColor(handle, r, g, b); }
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
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds) { return Overlay_018::setOverlayTextureBounds(handle, bounds); }
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

    //

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
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled);
        static OverlayError setOverlayColor(uint64_t handle, float r, float g, float b);
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
        static OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds);
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
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled) { return Overlay_019::getOverlayFlag(handle, flag, enabled); }
            virtual OverlayError setOverlayColor(uint64_t handle, float r, float g, float b) { return Overlay_019::setOverlayColor(handle, r, g, b); }
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
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds) { return Overlay_019::setOverlayTextureBounds(handle, bounds); }
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

    //

    struct Overlay_020
    {
        static OverlayError findOverlay(const char* key, uint64_t* handle);

        static OverlayError createOverlay(const char* key, const char* name, uint64_t* handle);
        static OverlayError destroyOverlay(uint64_t handle);

        static uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static OverlayError setOverlayName(uint64_t handle, const char* name);
        static OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height);

        static const char* getOverlayErrorNameFromEnum(OverlayError error);

        static OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid);
        static uint32_t getOverlayRenderingPid(uint64_t handle);

        static OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled);
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled);
        static OverlayError setOverlayColor(uint64_t handle, float r, float g, float b);
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
        static OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds);
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

    class Overlay_020_v
    {
        public:
            virtual OverlayError findOverlay(const char* key, uint64_t* handle) { return Overlay_020::findOverlay(key, handle); }
            virtual OverlayError createOverlay(const char* key, const char* name, uint64_t* handle) { return Overlay_020::createOverlay(key, name, handle); }
            virtual OverlayError destroyOverlay(uint64_t handle) { return Overlay_020::destroyOverlay(handle); }
            virtual uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_020::getOverlayKey(handle, value, bufferSize, error); }
            virtual uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_020::getOverlayName(handle, value, bufferSize, error); }
            virtual OverlayError setOverlayName(uint64_t handle, const char* name) { return Overlay_020::setOverlayName(handle, name); }
            virtual OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height) { return Overlay_020::getOverlayImageData(handle, buffer, bufferSize, width, height); }
            virtual const char* getOverlayErrorNameFromEnum(OverlayError error) { return Overlay_020::getOverlayErrorNameFromEnum(error); }
            virtual OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid) { return Overlay_020::setOverlayRenderingPid(handle, pid); }
            virtual uint32_t getOverlayRenderingPid(uint64_t handle) { return Overlay_020::getOverlayRenderingPid(handle); }
            virtual OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled) { return Overlay_020::setOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled) { return Overlay_020::getOverlayFlag(handle, flag, enabled); }
            virtual OverlayError setOverlayColor(uint64_t handle, float r, float g, float b) { return Overlay_020::setOverlayColor(handle, r, g, b); }
            virtual OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b) { return Overlay_020::getOverlayColor(handle, r, g, b); }
            virtual OverlayError setOverlayAlpha(uint64_t handle, float alpha) { return Overlay_020::setOverlayAlpha(handle, alpha); }
            virtual OverlayError getOverlayAlpha(uint64_t handle, float* alpha) { return Overlay_020::getOverlayAlpha(handle, alpha); }
            virtual OverlayError setOverlayTexelAspectRatio(uint64_t handle, float aspect) { return Overlay_020::setOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError getOverlayTexelAspectRatio(uint64_t handle, float* aspect) { return Overlay_020::getOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError setOverlaySortOrder(uint64_t handle, uint32_t sortOrder) { return Overlay_020::setOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder) { return Overlay_020::getOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError setOverlayWidthInMeters(uint64_t handle, float width) { return Overlay_020::setOverlayWidthInMeters(handle, width); }
            virtual OverlayError getOverlayWidthInMeters(uint64_t handle, float* width) { return Overlay_020::getOverlayWidthInMeters(handle, width); }
            virtual OverlayError setOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float minDistance, float maxDistance) { return Overlay_020::setOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError getOverlayAutoCurveDistanceRangeInMeters(uint64_t handle, float* minDistance, float* maxDistance) { return Overlay_020::getOverlayAutoCurveDistanceRangeInMeters(handle, minDistance, maxDistance); }
            virtual OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace) { return Overlay_020::setOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace) { return Overlay_020::getOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds) { return Overlay_020::setOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_020::getOverlayTextureBounds(handle, bounds); }
            virtual uint32_t getOverlayRenderModel(uint64_t handle, char* renderModel, uint32_t bufferSize, Color* color, OverlayError* error) { return Overlay_020::getOverlayRenderModel(handle, renderModel, bufferSize, color, error); }
            virtual OverlayError setOverlayRenderModel(uint64_t handle, const char* renderModel, const Color* color) { return Overlay_020::setOverlayRenderModel(handle, renderModel, color); }
            virtual OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType) { return Overlay_020::getOverlayTransformType(handle, transformType); }
            virtual OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_020::setOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix) { return Overlay_020::getOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix) { return Overlay_020::setOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix) { return Overlay_020::getOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName) { return Overlay_020::setOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName); }
            virtual OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize) { return Overlay_020::getOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName, bufferSize); }
            virtual OverlayError getOverlayTransformOverlayRelative(uint64_t handle, uint64_t* parentHandle, Matrix34* matrix) { return Overlay_020::getOverlayTransformOverlayRelative(handle, parentHandle, matrix); }
            virtual OverlayError setOverlayTransformOverlayRelative(uint64_t handle, uint64_t parentHandle, const Matrix34* matrix) { return Overlay_020::setOverlayTransformOverlayRelative(handle, parentHandle, matrix); }
            virtual OverlayError showOverlay(uint64_t handle) { return Overlay_020::showOverlay(handle); }
            virtual OverlayError hideOverlay(uint64_t handle) { return Overlay_020::hideOverlay(handle); }
            virtual bool isOverlayVisible(uint64_t handle) { return Overlay_020::isOverlayVisible(handle); }
            virtual OverlayError getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix) { return Overlay_020::getTransformForOverlayCoordinates(handle, origin, coordinatesInOverlay, matrix); }
            virtual bool pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t eventSize) { return Overlay_020::pollNextOverlayEvent(handle, event, eventSize); }
            virtual OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod) { return Overlay_020::getOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod) { return Overlay_020::setOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale) { return Overlay_020::getOverlayMouseScale(handle, mouseScale); }
            virtual OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale) { return Overlay_020::setOverlayMouseScale(handle, mouseScale); }
            virtual bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results) { return Overlay_020::computeOverlayIntersection(handle, params, results); }
            virtual bool isHoverTargetOverlay(uint64_t handle) { return Overlay_020::isHoverTargetOverlay(handle); }
            virtual uint64_t getGamepadFocusOverlay() { return Overlay_020::getGamepadFocusOverlay(); }
            virtual OverlayError setGamepadFocusOverlay(uint64_t handle) { return Overlay_020::setGamepadFocusOverlay(handle); }
            virtual OverlayError setOverlayNeighbor(OverlayNeighborDirection direction, uint64_t from, uint64_t to) { return Overlay_020::setOverlayNeighbor(direction, from, to); }
            virtual OverlayError moveGamepadFocusToNeighbor(OverlayNeighborDirection direction, uint64_t from) { return Overlay_020::moveGamepadFocusToNeighbor(direction, from); }
            virtual OverlayError setOverlayDualAnalogTransform(uint64_t handle, DualAnalogWhich which, const Vector2* center, float radius) { return Overlay_020::setOverlayDualAnalogTransform(handle, which, center, radius); }
            virtual OverlayError getOverlayDualAnalogTransform(uint64_t ulOverlay, DualAnalogWhich which, Vector2* center, float* radius) { return Overlay_020::getOverlayDualAnalogTransform(ulOverlay, which, center, radius); }
            virtual OverlayError setOverlayTexture(uint64_t handle, const Texture* texture) { return Overlay_020::setOverlayTexture(handle, texture); }
            virtual OverlayError clearOverlayTexture(uint64_t handle) { return Overlay_020::clearOverlayTexture(handle); }
            virtual OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth) { return Overlay_020::setOverlayRaw(handle, buffer, width, height, depth); }
            virtual OverlayError setOverlayFromFile(uint64_t handle, const char* filePath) { return Overlay_020::setOverlayFromFile(handle, filePath); }
            virtual OverlayError getOverlayNativeTexture(uint64_t handle, void** nativeTextureHandle, void* nativeTextureRef, uint32_t* width, uint32_t* height, uint32_t* format, TextureType* type, ColorSpace* colorSpace, TextureBounds* bounds) { return Overlay_020::getOverlayNativeTexture(handle, nativeTextureHandle, nativeTextureRef, width, height, format, type, colorSpace, bounds); }
            virtual OverlayError releaseNativeOverlayTexture(uint64_t handle, void* nativeTextureHandle) { return Overlay_020::releaseNativeOverlayTexture(handle, nativeTextureHandle); }
            virtual OverlayError getOverlayTextureSize(uint64_t handle, uint32_t* width, uint32_t* height) { return Overlay_020::getOverlayTextureSize(handle, width, height); }
            virtual OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle) { return Overlay_020::createDashboardOverlay(key, friendlyName, mainHandle, thumbnailHandle); }
            virtual bool isDashboardVisible() { return Overlay_020::isDashboardVisible(); }
            virtual bool isActiveDashboardOverlay(uint64_t handle) { return Overlay_020::isActiveDashboardOverlay(handle); }
            virtual OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid) { return Overlay_020::setDashboardOverlaySceneProcess(handle, pid); }
            virtual OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid) { return Overlay_020::getDashboardOverlaySceneProcess(handle, pid); }
            virtual void showDashboard(const char* overlayToShow) { return Overlay_020::showDashboard(overlayToShow); }
            virtual uint32_t getPrimaryDashboardInputTrackedDevice() { return Overlay_020::getPrimaryDashboardInputTrackedDevice(); }
            virtual OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_020::showKeyboard(textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_020::showKeyboardForOverlay(handle, textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual uint32_t getKeyboardText(char* text, uint32_t bufferSize) { return Overlay_020::getKeyboardText(text, bufferSize); }
            virtual void hideKeyboard() { return Overlay_020::hideKeyboard(); }
            virtual void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_020::setKeyboardTransformAbsolute(origin, matrix); }
            virtual void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect) { return Overlay_020::setKeyboardPositionForOverlay(handle, avoidRect); }
            virtual OverlayError setOverlayIntersectionMask(uint64_t handle, OverlayIntersectionMaskPrimitive* primitives, uint32_t primitivesCount, uint32_t primitiveSize) { return Overlay_020::setOverlayIntersectionMask(handle, primitives, primitivesCount, primitiveSize); }
            virtual OverlayError getOverlayFlags(uint64_t handle, uint32_t* flags) { return Overlay_020::getOverlayFlags(handle, flags); }
            virtual MessageOverlayResponse showMessageOverlay(const char* text, const char* caption, const char* button0Text, const char* button1Text, const char* button2Text, const char* button3Text) { return Overlay_020::showMessageOverlay(text, caption, button0Text, button1Text, button2Text, button3Text); }
            virtual void closeMessageOverlay() { return Overlay_020::closeMessageOverlay(); }
    };

    //

    struct Overlay_021
    {
        static OverlayError findOverlay(const char* key, uint64_t* handle);

        static OverlayError createOverlay(const char* key, const char* name, uint64_t* handle);
        static OverlayError destroyOverlay(uint64_t handle);

        static uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static OverlayError setOverlayName(uint64_t handle, const char* name);
        static OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height);

        static const char* getOverlayErrorNameFromEnum(OverlayError error);

        static OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid);
        static uint32_t getOverlayRenderingPid(uint64_t handle);

        static OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled);
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled);
        static OverlayError setOverlayColor(uint64_t handle, float r, float g, float b);
        static OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b);
        static OverlayError setOverlayAlpha(uint64_t handle, float alpha);
        static OverlayError getOverlayAlpha(uint64_t handle, float* alpha);

        static OverlayError setOverlayTexelAspectRatio(uint64_t handle, float aspect);
        static OverlayError getOverlayTexelAspectRatio(uint64_t handle, float* aspect);
        static OverlayError setOverlaySortOrder(uint64_t handle, uint32_t sortOrder);
        static OverlayError getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder);
        static OverlayError setOverlayWidthInMeters(uint64_t handle, float width);
        static OverlayError getOverlayWidthInMeters(uint64_t handle, float* width);
        static OverlayError setOverlayCurvature(uint64_t handle, float curvature);
        static OverlayError getOverlayCurvature(uint64_t handle, float* curvature);

        static OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace);
        static OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace);
        static OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds);
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
        void* setOverlayCurvature_ = (void*) setOverlayCurvature;
        void* getOverlayCurvature_ = (void*) getOverlayCurvature;
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

    class Overlay_021_v
    {
        public:
            virtual OverlayError findOverlay(const char* key, uint64_t* handle) { return Overlay_021::findOverlay(key, handle); }
            virtual OverlayError createOverlay(const char* key, const char* name, uint64_t* handle) { return Overlay_021::createOverlay(key, name, handle); }
            virtual OverlayError destroyOverlay(uint64_t handle) { return Overlay_021::destroyOverlay(handle); }
            virtual uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_021::getOverlayKey(handle, value, bufferSize, error); }
            virtual uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_021::getOverlayName(handle, value, bufferSize, error); }
            virtual OverlayError setOverlayName(uint64_t handle, const char* name) { return Overlay_021::setOverlayName(handle, name); }
            virtual OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height) { return Overlay_021::getOverlayImageData(handle, buffer, bufferSize, width, height); }
            virtual const char* getOverlayErrorNameFromEnum(OverlayError error) { return Overlay_021::getOverlayErrorNameFromEnum(error); }
            virtual OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid) { return Overlay_021::setOverlayRenderingPid(handle, pid); }
            virtual uint32_t getOverlayRenderingPid(uint64_t handle) { return Overlay_021::getOverlayRenderingPid(handle); }
            virtual OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled) { return Overlay_021::setOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled) { return Overlay_021::getOverlayFlag(handle, flag, enabled); }
            virtual OverlayError setOverlayColor(uint64_t handle, float r, float g, float b) { return Overlay_021::setOverlayColor(handle, r, g, b); }
            virtual OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b) { return Overlay_021::getOverlayColor(handle, r, g, b); }
            virtual OverlayError setOverlayAlpha(uint64_t handle, float alpha) { return Overlay_021::setOverlayAlpha(handle, alpha); }
            virtual OverlayError getOverlayAlpha(uint64_t handle, float* alpha) { return Overlay_021::getOverlayAlpha(handle, alpha); }
            virtual OverlayError setOverlayTexelAspectRatio(uint64_t handle, float aspect) { return Overlay_021::setOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError getOverlayTexelAspectRatio(uint64_t handle, float* aspect) { return Overlay_021::getOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError setOverlaySortOrder(uint64_t handle, uint32_t sortOrder) { return Overlay_021::setOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder) { return Overlay_021::getOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError setOverlayWidthInMeters(uint64_t handle, float width) { return Overlay_021::setOverlayWidthInMeters(handle, width); }
            virtual OverlayError getOverlayWidthInMeters(uint64_t handle, float* width) { return Overlay_021::getOverlayWidthInMeters(handle, width); }
            virtual OverlayError setOverlayCurvature(uint64_t handle, float curvature) { return Overlay_021::setOverlayCurvature(handle, curvature); }
            virtual OverlayError getOverlayCurvature(uint64_t handle, float* curvature) { return Overlay_021::getOverlayCurvature(handle, curvature); }
            virtual OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace) { return Overlay_021::setOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace) { return Overlay_021::getOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds) { return Overlay_021::setOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_021::getOverlayTextureBounds(handle, bounds); }
            virtual uint32_t getOverlayRenderModel(uint64_t handle, char* renderModel, uint32_t bufferSize, Color* color, OverlayError* error) { return Overlay_021::getOverlayRenderModel(handle, renderModel, bufferSize, color, error); }
            virtual OverlayError setOverlayRenderModel(uint64_t handle, const char* renderModel, const Color* color) { return Overlay_021::setOverlayRenderModel(handle, renderModel, color); }
            virtual OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType) { return Overlay_021::getOverlayTransformType(handle, transformType); }
            virtual OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_021::setOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix) { return Overlay_021::getOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix) { return Overlay_021::setOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix) { return Overlay_021::getOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName) { return Overlay_021::setOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName); }
            virtual OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize) { return Overlay_021::getOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName, bufferSize); }
            virtual OverlayError getOverlayTransformOverlayRelative(uint64_t handle, uint64_t* parentHandle, Matrix34* matrix) { return Overlay_021::getOverlayTransformOverlayRelative(handle, parentHandle, matrix); }
            virtual OverlayError setOverlayTransformOverlayRelative(uint64_t handle, uint64_t parentHandle, const Matrix34* matrix) { return Overlay_021::setOverlayTransformOverlayRelative(handle, parentHandle, matrix); }
            virtual OverlayError showOverlay(uint64_t handle) { return Overlay_021::showOverlay(handle); }
            virtual OverlayError hideOverlay(uint64_t handle) { return Overlay_021::hideOverlay(handle); }
            virtual bool isOverlayVisible(uint64_t handle) { return Overlay_021::isOverlayVisible(handle); }
            virtual OverlayError getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix) { return Overlay_021::getTransformForOverlayCoordinates(handle, origin, coordinatesInOverlay, matrix); }
            virtual bool pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t eventSize) { return Overlay_021::pollNextOverlayEvent(handle, event, eventSize); }
            virtual OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod) { return Overlay_021::getOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod) { return Overlay_021::setOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale) { return Overlay_021::getOverlayMouseScale(handle, mouseScale); }
            virtual OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale) { return Overlay_021::setOverlayMouseScale(handle, mouseScale); }
            virtual bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results) { return Overlay_021::computeOverlayIntersection(handle, params, results); }
            virtual bool isHoverTargetOverlay(uint64_t handle) { return Overlay_021::isHoverTargetOverlay(handle); }
            virtual OverlayError setOverlayDualAnalogTransform(uint64_t handle, DualAnalogWhich which, const Vector2* center, float radius) { return Overlay_021::setOverlayDualAnalogTransform(handle, which, center, radius); }
            virtual OverlayError getOverlayDualAnalogTransform(uint64_t ulOverlay, DualAnalogWhich which, Vector2* center, float* radius) { return Overlay_021::getOverlayDualAnalogTransform(ulOverlay, which, center, radius); }
            virtual OverlayError setOverlayTexture(uint64_t handle, const Texture* texture) { return Overlay_021::setOverlayTexture(handle, texture); }
            virtual OverlayError clearOverlayTexture(uint64_t handle) { return Overlay_021::clearOverlayTexture(handle); }
            virtual OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth) { return Overlay_021::setOverlayRaw(handle, buffer, width, height, depth); }
            virtual OverlayError setOverlayFromFile(uint64_t handle, const char* filePath) { return Overlay_021::setOverlayFromFile(handle, filePath); }
            virtual OverlayError getOverlayNativeTexture(uint64_t handle, void** nativeTextureHandle, void* nativeTextureRef, uint32_t* width, uint32_t* height, uint32_t* format, TextureType* type, ColorSpace* colorSpace, TextureBounds* bounds) { return Overlay_021::getOverlayNativeTexture(handle, nativeTextureHandle, nativeTextureRef, width, height, format, type, colorSpace, bounds); }
            virtual OverlayError releaseNativeOverlayTexture(uint64_t handle, void* nativeTextureHandle) { return Overlay_021::releaseNativeOverlayTexture(handle, nativeTextureHandle); }
            virtual OverlayError getOverlayTextureSize(uint64_t handle, uint32_t* width, uint32_t* height) { return Overlay_021::getOverlayTextureSize(handle, width, height); }
            virtual OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle) { return Overlay_021::createDashboardOverlay(key, friendlyName, mainHandle, thumbnailHandle); }
            virtual bool isDashboardVisible() { return Overlay_021::isDashboardVisible(); }
            virtual bool isActiveDashboardOverlay(uint64_t handle) { return Overlay_021::isActiveDashboardOverlay(handle); }
            virtual OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid) { return Overlay_021::setDashboardOverlaySceneProcess(handle, pid); }
            virtual OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid) { return Overlay_021::getDashboardOverlaySceneProcess(handle, pid); }
            virtual void showDashboard(const char* overlayToShow) { return Overlay_021::showDashboard(overlayToShow); }
            virtual uint32_t getPrimaryDashboardInputTrackedDevice() { return Overlay_021::getPrimaryDashboardInputTrackedDevice(); }
            virtual OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_021::showKeyboard(textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_021::showKeyboardForOverlay(handle, textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual uint32_t getKeyboardText(char* text, uint32_t bufferSize) { return Overlay_021::getKeyboardText(text, bufferSize); }
            virtual void hideKeyboard() { return Overlay_021::hideKeyboard(); }
            virtual void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_021::setKeyboardTransformAbsolute(origin, matrix); }
            virtual void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect) { return Overlay_021::setKeyboardPositionForOverlay(handle, avoidRect); }
            virtual OverlayError setOverlayIntersectionMask(uint64_t handle, OverlayIntersectionMaskPrimitive* primitives, uint32_t primitivesCount, uint32_t primitiveSize) { return Overlay_021::setOverlayIntersectionMask(handle, primitives, primitivesCount, primitiveSize); }
            virtual OverlayError getOverlayFlags(uint64_t handle, uint32_t* flags) { return Overlay_021::getOverlayFlags(handle, flags); }
            virtual MessageOverlayResponse showMessageOverlay(const char* text, const char* caption, const char* button0Text, const char* button1Text, const char* button2Text, const char* button3Text) { return Overlay_021::showMessageOverlay(text, caption, button0Text, button1Text, button2Text, button3Text); }
            virtual void closeMessageOverlay() { return Overlay_021::closeMessageOverlay(); }
    };

    //

    struct Overlay_022
    {
        static OverlayError findOverlay(const char* key, uint64_t* handle);

        static OverlayError createOverlay(const char* key, const char* name, uint64_t* handle);
        static OverlayError destroyOverlay(uint64_t handle);

        static uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static OverlayError setOverlayName(uint64_t handle, const char* name);
        static OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height);

        static const char* getOverlayErrorNameFromEnum(OverlayError error);

        static OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid);
        static uint32_t getOverlayRenderingPid(uint64_t handle);

        static OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled);
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled);
        static OverlayError getOverlayFlags(uint64_t handle, uint32_t* flags);

        static OverlayError setOverlayColor(uint64_t handle, float r, float g, float b);
        static OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b);
        static OverlayError setOverlayAlpha(uint64_t handle, float alpha);
        static OverlayError getOverlayAlpha(uint64_t handle, float* alpha);

        static OverlayError setOverlayTexelAspectRatio(uint64_t handle, float aspect);
        static OverlayError getOverlayTexelAspectRatio(uint64_t handle, float* aspect);
        static OverlayError setOverlaySortOrder(uint64_t handle, uint32_t sortOrder);
        static OverlayError getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder);
        static OverlayError setOverlayWidthInMeters(uint64_t handle, float width);
        static OverlayError getOverlayWidthInMeters(uint64_t handle, float* width);
        static OverlayError setOverlayCurvature(uint64_t handle, float curvature);
        static OverlayError getOverlayCurvature(uint64_t handle, float* curvature);

        static OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace);
        static OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace);
        static OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds);
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
        static OverlayError setOverlayTransformOverlayCursor(uint64_t handle, const Vector2* hotspot);
        static OverlayError getOverlayTransformOverlayCursor(uint64_t handle, Vector2* hotspot);

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

        static OverlayError setOverlayDualAnalogTransform(uint64_t handle, DualAnalogWhich which, const Vector2* center, float radius);
        static OverlayError getOverlayDualAnalogTransform(uint64_t ulOverlay, DualAnalogWhich which, Vector2* center, float* radius);

        static OverlayError setOverlayIntersectionMask(uint64_t handle, OverlayIntersectionMaskPrimitive* primitives, uint32_t primitivesCount, uint32_t primitiveSize);
        static OverlayError triggerLaserMouseHapticVibration(uint64_t handle, float durationSeconds, float frequency, float amplitude);
        static OverlayError setOverlayCursor(uint64_t handle, uint64_t cursorHandle);
        static OverlayError setOverlayCursorPositionOverride(uint64_t handle, const Vector2* position);
        static OverlayError clearOverlayCursorPositionOverride(uint64_t handle);

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

        static MessageOverlayResponse showMessageOverlay(const char* text, const char* caption, const char* button0Text, const char* button1Text, const char* button2Text, const char* button3Text);
        static void closeMessageOverlay();

        void* findOverlay_ = (void*) findOverlay;
        void* createOverlay_ = (void*) createOverlay;
        void* destroyOverlay_ = (void*) destroyOverlay;
        void* getOverlayKey_ = (void*) getOverlayKey;
        void* getOverlayName_ = (void*) getOverlayName;
        void* setOverlayName_ = (void*) setOverlayName;
        void* getOverlayImageData_ = (void*) getOverlayImageData;
        void* getOverlayErrorNameFromEnum_ = (void*) getOverlayErrorNameFromEnum;
        void* setOverlayRenderingPid_ = (void*) setOverlayRenderingPid;
        void* getOverlayRenderingPid_ = (void*) getOverlayRenderingPid;
        void* setOverlayFlag_ = (void*) setOverlayFlag;
        void* getOverlayFlag_ = (void*) getOverlayFlag;
        void* getOverlayFlags_ = (void*) getOverlayFlags;
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
        void* setOverlayCurvature_ = (void*) setOverlayCurvature;
        void* getOverlayCurvature_ = (void*) getOverlayCurvature;
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
        void* setOverlayTransformOverlayCursor_ = (void*) setOverlayTransformOverlayCursor;
        void* getOverlayTransformOverlayCursor_ = (void*) getOverlayTransformOverlayCursor;
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
        void* setOverlayDualAnalogTransform_ = (void*) setOverlayDualAnalogTransform;
        void* getOverlayDualAnalogTransform_ = (void*) getOverlayDualAnalogTransform;
        void* setOverlayIntersectionMask_ = (void*) setOverlayIntersectionMask;
        void* triggerLaserMouseHapticVibration_ = (void*) triggerLaserMouseHapticVibration;
        void* setOverlayCursor_ = (void*) setOverlayCursor;
        void* setOverlayCursorPositionOverride_ = (void*) setOverlayCursorPositionOverride;
        void* clearOverlayCursorPositionOverride_ = (void*) clearOverlayCursorPositionOverride;
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
        void* showMessageOverlay_ = (void*) showMessageOverlay;
        void* closeMessageOverlay_ = (void*) closeMessageOverlay;
    };

    class Overlay_022_v
    {
        public:
            virtual OverlayError findOverlay(const char* key, uint64_t* handle) { return Overlay_022::findOverlay(key, handle); }
            virtual OverlayError createOverlay(const char* key, const char* name, uint64_t* handle) { return Overlay_022::createOverlay(key, name, handle); }
            virtual OverlayError destroyOverlay(uint64_t handle) { return Overlay_022::destroyOverlay(handle); }
            virtual uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_022::getOverlayKey(handle, value, bufferSize, error); }
            virtual uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_022::getOverlayName(handle, value, bufferSize, error); }
            virtual OverlayError setOverlayName(uint64_t handle, const char* name) { return Overlay_022::setOverlayName(handle, name); }
            virtual OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height) { return Overlay_022::getOverlayImageData(handle, buffer, bufferSize, width, height); }
            virtual const char* getOverlayErrorNameFromEnum(OverlayError error) { return Overlay_022::getOverlayErrorNameFromEnum(error); }
            virtual OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid) { return Overlay_022::setOverlayRenderingPid(handle, pid); }
            virtual uint32_t getOverlayRenderingPid(uint64_t handle) { return Overlay_022::getOverlayRenderingPid(handle); }
            virtual OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled) { return Overlay_022::setOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled) { return Overlay_022::getOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlags(uint64_t handle, uint32_t* flags) { return Overlay_022::getOverlayFlags(handle, flags); }
            virtual OverlayError setOverlayColor(uint64_t handle, float r, float g, float b) { return Overlay_022::setOverlayColor(handle, r, g, b); }
            virtual OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b) { return Overlay_022::getOverlayColor(handle, r, g, b); }
            virtual OverlayError setOverlayAlpha(uint64_t handle, float alpha) { return Overlay_022::setOverlayAlpha(handle, alpha); }
            virtual OverlayError getOverlayAlpha(uint64_t handle, float* alpha) { return Overlay_022::getOverlayAlpha(handle, alpha); }
            virtual OverlayError setOverlayTexelAspectRatio(uint64_t handle, float aspect) { return Overlay_022::setOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError getOverlayTexelAspectRatio(uint64_t handle, float* aspect) { return Overlay_022::getOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError setOverlaySortOrder(uint64_t handle, uint32_t sortOrder) { return Overlay_022::setOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder) { return Overlay_022::getOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError setOverlayWidthInMeters(uint64_t handle, float width) { return Overlay_022::setOverlayWidthInMeters(handle, width); }
            virtual OverlayError getOverlayWidthInMeters(uint64_t handle, float* width) { return Overlay_022::getOverlayWidthInMeters(handle, width); }
            virtual OverlayError setOverlayCurvature(uint64_t handle, float curvature) { return Overlay_022::setOverlayCurvature(handle, curvature); }
            virtual OverlayError getOverlayCurvature(uint64_t handle, float* curvature) { return Overlay_022::getOverlayCurvature(handle, curvature); }
            virtual OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace) { return Overlay_022::setOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace) { return Overlay_022::getOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds) { return Overlay_022::setOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_022::getOverlayTextureBounds(handle, bounds); }
            virtual uint32_t getOverlayRenderModel(uint64_t handle, char* renderModel, uint32_t bufferSize, Color* color, OverlayError* error) { return Overlay_022::getOverlayRenderModel(handle, renderModel, bufferSize, color, error); }
            virtual OverlayError setOverlayRenderModel(uint64_t handle, const char* renderModel, const Color* color) { return Overlay_022::setOverlayRenderModel(handle, renderModel, color); }
            virtual OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType) { return Overlay_022::getOverlayTransformType(handle, transformType); }
            virtual OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_022::setOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix) { return Overlay_022::getOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix) { return Overlay_022::setOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix) { return Overlay_022::getOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName) { return Overlay_022::setOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName); }
            virtual OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize) { return Overlay_022::getOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName, bufferSize); }
            virtual OverlayError getOverlayTransformOverlayRelative(uint64_t handle, uint64_t* parentHandle, Matrix34* matrix) { return Overlay_022::getOverlayTransformOverlayRelative(handle, parentHandle, matrix); }
            virtual OverlayError setOverlayTransformOverlayRelative(uint64_t handle, uint64_t parentHandle, const Matrix34* matrix) { return Overlay_022::setOverlayTransformOverlayRelative(handle, parentHandle, matrix); }
            virtual OverlayError setOverlayTransformOverlayCursor(uint64_t handle, const Vector2* hotspot) { return Overlay_022::setOverlayTransformOverlayCursor(handle, hotspot); }
            virtual OverlayError getOverlayTransformOverlayCursor(uint64_t handle, Vector2* hotspot) { return Overlay_022::getOverlayTransformOverlayCursor(handle, hotspot); }
            virtual OverlayError showOverlay(uint64_t handle) { return Overlay_022::showOverlay(handle); }
            virtual OverlayError hideOverlay(uint64_t handle) { return Overlay_022::hideOverlay(handle); }
            virtual bool isOverlayVisible(uint64_t handle) { return Overlay_022::isOverlayVisible(handle); }
            virtual OverlayError getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix) { return Overlay_022::getTransformForOverlayCoordinates(handle, origin, coordinatesInOverlay, matrix); }
            virtual bool pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t eventSize) { return Overlay_022::pollNextOverlayEvent(handle, event, eventSize); }
            virtual OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod) { return Overlay_022::getOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod) { return Overlay_022::setOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale) { return Overlay_022::getOverlayMouseScale(handle, mouseScale); }
            virtual OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale) { return Overlay_022::setOverlayMouseScale(handle, mouseScale); }
            virtual bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results) { return Overlay_022::computeOverlayIntersection(handle, params, results); }
            virtual bool isHoverTargetOverlay(uint64_t handle) { return Overlay_022::isHoverTargetOverlay(handle); }
            virtual OverlayError setOverlayDualAnalogTransform(uint64_t handle, DualAnalogWhich which, const Vector2* center, float radius) { return Overlay_022::setOverlayDualAnalogTransform(handle, which, center, radius); }
            virtual OverlayError getOverlayDualAnalogTransform(uint64_t ulOverlay, DualAnalogWhich which, Vector2* center, float* radius) { return Overlay_022::getOverlayDualAnalogTransform(ulOverlay, which, center, radius); }
            virtual OverlayError setOverlayIntersectionMask(uint64_t handle, OverlayIntersectionMaskPrimitive* primitives, uint32_t primitivesCount, uint32_t primitiveSize) { return Overlay_022::setOverlayIntersectionMask(handle, primitives, primitivesCount, primitiveSize); }
            virtual OverlayError triggerLaserMouseHapticVibration(uint64_t handle, float durationSeconds, float frequency, float amplitude) { return Overlay_022::triggerLaserMouseHapticVibration(handle, durationSeconds, frequency, amplitude); }
            virtual OverlayError setOverlayCursor(uint64_t handle, uint64_t cursorHandle) { return Overlay_022::setOverlayCursor(handle, cursorHandle); }
            virtual OverlayError setOverlayCursorPositionOverride(uint64_t handle, const Vector2* position) { return Overlay_022::setOverlayCursorPositionOverride(handle, position); }
            virtual OverlayError clearOverlayCursorPositionOverride(uint64_t handle) { return Overlay_022::clearOverlayCursorPositionOverride(handle); }
            virtual OverlayError setOverlayTexture(uint64_t handle, const Texture* texture) { return Overlay_022::setOverlayTexture(handle, texture); }
            virtual OverlayError clearOverlayTexture(uint64_t handle) { return Overlay_022::clearOverlayTexture(handle); }
            virtual OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth) { return Overlay_022::setOverlayRaw(handle, buffer, width, height, depth); }
            virtual OverlayError setOverlayFromFile(uint64_t handle, const char* filePath) { return Overlay_022::setOverlayFromFile(handle, filePath); }
            virtual OverlayError getOverlayNativeTexture(uint64_t handle, void** nativeTextureHandle, void* nativeTextureRef, uint32_t* width, uint32_t* height, uint32_t* format, TextureType* type, ColorSpace* colorSpace, TextureBounds* bounds) { return Overlay_022::getOverlayNativeTexture(handle, nativeTextureHandle, nativeTextureRef, width, height, format, type, colorSpace, bounds); }
            virtual OverlayError releaseNativeOverlayTexture(uint64_t handle, void* nativeTextureHandle) { return Overlay_022::releaseNativeOverlayTexture(handle, nativeTextureHandle); }
            virtual OverlayError getOverlayTextureSize(uint64_t handle, uint32_t* width, uint32_t* height) { return Overlay_022::getOverlayTextureSize(handle, width, height); }
            virtual OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle) { return Overlay_022::createDashboardOverlay(key, friendlyName, mainHandle, thumbnailHandle); }
            virtual bool isDashboardVisible() { return Overlay_022::isDashboardVisible(); }
            virtual bool isActiveDashboardOverlay(uint64_t handle) { return Overlay_022::isActiveDashboardOverlay(handle); }
            virtual OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid) { return Overlay_022::setDashboardOverlaySceneProcess(handle, pid); }
            virtual OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid) { return Overlay_022::getDashboardOverlaySceneProcess(handle, pid); }
            virtual void showDashboard(const char* overlayToShow) { return Overlay_022::showDashboard(overlayToShow); }
            virtual uint32_t getPrimaryDashboardInputTrackedDevice() { return Overlay_022::getPrimaryDashboardInputTrackedDevice(); }
            virtual OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_022::showKeyboard(textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, const char* description, uint32_t maxChars, const char* existingText, bool useMinimalMode, uint64_t userValue) { return Overlay_022::showKeyboardForOverlay(handle, textInputMode, textInputLineMode, description, maxChars, existingText, useMinimalMode, userValue); }
            virtual uint32_t getKeyboardText(char* text, uint32_t bufferSize) { return Overlay_022::getKeyboardText(text, bufferSize); }
            virtual void hideKeyboard() { return Overlay_022::hideKeyboard(); }
            virtual void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_022::setKeyboardTransformAbsolute(origin, matrix); }
            virtual void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect) { return Overlay_022::setKeyboardPositionForOverlay(handle, avoidRect); }
            virtual MessageOverlayResponse showMessageOverlay(const char* text, const char* caption, const char* button0Text, const char* button1Text, const char* button2Text, const char* button3Text) { return Overlay_022::showMessageOverlay(text, caption, button0Text, button1Text, button2Text, button3Text); }
            virtual void closeMessageOverlay() { return Overlay_022::closeMessageOverlay(); }
    };

    //

    struct Overlay_024
    {
        static OverlayError findOverlay(const char* key, uint64_t* handle);

        static OverlayError createOverlay(const char* key, const char* name, uint64_t* handle);
        static OverlayError destroyOverlay(uint64_t handle);

        static uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static OverlayError setOverlayName(uint64_t handle, const char* name);
        static OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height);

        static const char* getOverlayErrorNameFromEnum(OverlayError error);

        static OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid);
        static uint32_t getOverlayRenderingPid(uint64_t handle);

        static OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled);
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled);
        static OverlayError getOverlayFlags(uint64_t handle, uint32_t* flags);

        static OverlayError setOverlayColor(uint64_t handle, float r, float g, float b);
        static OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b);
        static OverlayError setOverlayAlpha(uint64_t handle, float alpha);
        static OverlayError getOverlayAlpha(uint64_t handle, float* alpha);

        static OverlayError setOverlayTexelAspectRatio(uint64_t handle, float aspect);
        static OverlayError getOverlayTexelAspectRatio(uint64_t handle, float* aspect);
        static OverlayError setOverlaySortOrder(uint64_t handle, uint32_t sortOrder);
        static OverlayError getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder);
        static OverlayError setOverlayWidthInMeters(uint64_t handle, float width);
        static OverlayError getOverlayWidthInMeters(uint64_t handle, float* width);
        static OverlayError setOverlayCurvature(uint64_t handle, float curvature);
        static OverlayError getOverlayCurvature(uint64_t handle, float* curvature);

        static OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace);
        static OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace);
        static OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds);
        static OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds);

        static OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType);
        static OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix);
        static OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix);
        static OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName);
        static OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize);
        static OverlayError getOverlayTransformOverlayRelative(uint64_t handle, uint64_t* parentHandle, Matrix34* matrix);
        static OverlayError setOverlayTransformOverlayRelative(uint64_t handle, uint64_t parentHandle, const Matrix34* matrix);
        static OverlayError setOverlayTransformOverlayCursor(uint64_t handle, const Vector2* hotspot);
        static OverlayError getOverlayTransformOverlayCursor(uint64_t handle, Vector2* hotspot);

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

        static OverlayError setOverlayIntersectionMask(uint64_t handle, OverlayIntersectionMaskPrimitive* primitives, uint32_t primitivesCount, uint32_t primitiveSize);
        static OverlayError triggerLaserMouseHapticVibration(uint64_t handle, float durationSeconds, float frequency, float amplitude);
        static OverlayError setOverlayCursor(uint64_t handle, uint64_t cursorHandle);
        static OverlayError setOverlayCursorPositionOverride(uint64_t handle, const Vector2* position);
        static OverlayError clearOverlayCursorPositionOverride(uint64_t handle);

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

        static OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, uint32_t flags, const char* description, uint32_t maxChars, const char* existingText, uint64_t userValue);
        static OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, uint32_t flags, const char* description, uint32_t maxChars, const char* existingText, uint64_t userValue);
        static uint32_t getKeyboardText(char* text, uint32_t bufferSize);
        static void hideKeyboard();
        static void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix);
        static void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect);

        static MessageOverlayResponse showMessageOverlay(const char* text, const char* caption, const char* button0Text, const char* button1Text, const char* button2Text, const char* button3Text);
        static void closeMessageOverlay();

        void* findOverlay_ = (void*) findOverlay;
        void* createOverlay_ = (void*) createOverlay;
        void* destroyOverlay_ = (void*) destroyOverlay;
        void* getOverlayKey_ = (void*) getOverlayKey;
        void* getOverlayName_ = (void*) getOverlayName;
        void* setOverlayName_ = (void*) setOverlayName;
        void* getOverlayImageData_ = (void*) getOverlayImageData;
        void* getOverlayErrorNameFromEnum_ = (void*) getOverlayErrorNameFromEnum;
        void* setOverlayRenderingPid_ = (void*) setOverlayRenderingPid;
        void* getOverlayRenderingPid_ = (void*) getOverlayRenderingPid;
        void* setOverlayFlag_ = (void*) setOverlayFlag;
        void* getOverlayFlag_ = (void*) getOverlayFlag;
        void* getOverlayFlags_ = (void*) getOverlayFlags;
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
        void* setOverlayCurvature_ = (void*) setOverlayCurvature;
        void* getOverlayCurvature_ = (void*) getOverlayCurvature;
        void* setOverlayTextureColorSpace_ = (void*) setOverlayTextureColorSpace;
        void* getOverlayTextureColorSpace_ = (void*) getOverlayTextureColorSpace;
        void* setOverlayTextureBounds_ = (void*) setOverlayTextureBounds;
        void* getOverlayTextureBounds_ = (void*) getOverlayTextureBounds;
        void* getOverlayTransformType_ = (void*) getOverlayTransformType;
        void* setOverlayTransformAbsolute_ = (void*) setOverlayTransformAbsolute;
        void* getOverlayTransformAbsolute_ = (void*) getOverlayTransformAbsolute;
        void* setOverlayTransformTrackedDeviceRelative_ = (void*) setOverlayTransformTrackedDeviceRelative;
        void* getOverlayTransformTrackedDeviceRelative_ = (void*) getOverlayTransformTrackedDeviceRelative;
        void* setOverlayTransformTrackedDeviceComponent_ = (void*) setOverlayTransformTrackedDeviceComponent;
        void* getOverlayTransformTrackedDeviceComponent_ = (void*) getOverlayTransformTrackedDeviceComponent;
        void* getOverlayTransformOverlayRelative_ = (void*) getOverlayTransformOverlayRelative;
        void* setOverlayTransformOverlayRelative_ = (void*) setOverlayTransformOverlayRelative;
        void* setOverlayTransformOverlayCursor_ = (void*) setOverlayTransformOverlayCursor;
        void* getOverlayTransformOverlayCursor_ = (void*) getOverlayTransformOverlayCursor;
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
        void* setOverlayIntersectionMask_ = (void*) setOverlayIntersectionMask;
        void* triggerLaserMouseHapticVibration_ = (void*) triggerLaserMouseHapticVibration;
        void* setOverlayCursor_ = (void*) setOverlayCursor;
        void* setOverlayCursorPositionOverride_ = (void*) setOverlayCursorPositionOverride;
        void* clearOverlayCursorPositionOverride_ = (void*) clearOverlayCursorPositionOverride;
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
        void* showMessageOverlay_ = (void*) showMessageOverlay;
        void* closeMessageOverlay_ = (void*) closeMessageOverlay;
    };

    class Overlay_024_v
    {
        public:
            virtual OverlayError findOverlay(const char* key, uint64_t* handle) { return Overlay_024::findOverlay(key, handle); }
            virtual OverlayError createOverlay(const char* key, const char* name, uint64_t* handle) { return Overlay_024::createOverlay(key, name, handle); }
            virtual OverlayError destroyOverlay(uint64_t handle) { return Overlay_024::destroyOverlay(handle); }
            virtual uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_024::getOverlayKey(handle, value, bufferSize, error); }
            virtual uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_024::getOverlayName(handle, value, bufferSize, error); }
            virtual OverlayError setOverlayName(uint64_t handle, const char* name) { return Overlay_024::setOverlayName(handle, name); }
            virtual OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height) { return Overlay_024::getOverlayImageData(handle, buffer, bufferSize, width, height); }
            virtual const char* getOverlayErrorNameFromEnum(OverlayError error) { return Overlay_024::getOverlayErrorNameFromEnum(error); }
            virtual OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid) { return Overlay_024::setOverlayRenderingPid(handle, pid); }
            virtual uint32_t getOverlayRenderingPid(uint64_t handle) { return Overlay_024::getOverlayRenderingPid(handle); }
            virtual OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled) { return Overlay_024::setOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled) { return Overlay_024::getOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlags(uint64_t handle, uint32_t* flags) { return Overlay_024::getOverlayFlags(handle, flags); }
            virtual OverlayError setOverlayColor(uint64_t handle, float r, float g, float b) { return Overlay_024::setOverlayColor(handle, r, g, b); }
            virtual OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b) { return Overlay_024::getOverlayColor(handle, r, g, b); }
            virtual OverlayError setOverlayAlpha(uint64_t handle, float alpha) { return Overlay_024::setOverlayAlpha(handle, alpha); }
            virtual OverlayError getOverlayAlpha(uint64_t handle, float* alpha) { return Overlay_024::getOverlayAlpha(handle, alpha); }
            virtual OverlayError setOverlayTexelAspectRatio(uint64_t handle, float aspect) { return Overlay_024::setOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError getOverlayTexelAspectRatio(uint64_t handle, float* aspect) { return Overlay_024::getOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError setOverlaySortOrder(uint64_t handle, uint32_t sortOrder) { return Overlay_024::setOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder) { return Overlay_024::getOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError setOverlayWidthInMeters(uint64_t handle, float width) { return Overlay_024::setOverlayWidthInMeters(handle, width); }
            virtual OverlayError getOverlayWidthInMeters(uint64_t handle, float* width) { return Overlay_024::getOverlayWidthInMeters(handle, width); }
            virtual OverlayError setOverlayCurvature(uint64_t handle, float curvature) { return Overlay_024::setOverlayCurvature(handle, curvature); }
            virtual OverlayError getOverlayCurvature(uint64_t handle, float* curvature) { return Overlay_024::getOverlayCurvature(handle, curvature); }
            virtual OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace) { return Overlay_024::setOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace) { return Overlay_024::getOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds) { return Overlay_024::setOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_024::getOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType) { return Overlay_024::getOverlayTransformType(handle, transformType); }
            virtual OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_024::setOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix) { return Overlay_024::getOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix) { return Overlay_024::setOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix) { return Overlay_024::getOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName) { return Overlay_024::setOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName); }
            virtual OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize) { return Overlay_024::getOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName, bufferSize); }
            virtual OverlayError getOverlayTransformOverlayRelative(uint64_t handle, uint64_t* parentHandle, Matrix34* matrix) { return Overlay_024::getOverlayTransformOverlayRelative(handle, parentHandle, matrix); }
            virtual OverlayError setOverlayTransformOverlayRelative(uint64_t handle, uint64_t parentHandle, const Matrix34* matrix) { return Overlay_024::setOverlayTransformOverlayRelative(handle, parentHandle, matrix); }
            virtual OverlayError setOverlayTransformOverlayCursor(uint64_t handle, const Vector2* hotspot) { return Overlay_024::setOverlayTransformOverlayCursor(handle, hotspot); }
            virtual OverlayError getOverlayTransformOverlayCursor(uint64_t handle, Vector2* hotspot) { return Overlay_024::getOverlayTransformOverlayCursor(handle, hotspot); }
            virtual OverlayError showOverlay(uint64_t handle) { return Overlay_024::showOverlay(handle); }
            virtual OverlayError hideOverlay(uint64_t handle) { return Overlay_024::hideOverlay(handle); }
            virtual bool isOverlayVisible(uint64_t handle) { return Overlay_024::isOverlayVisible(handle); }
            virtual OverlayError getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix) { return Overlay_024::getTransformForOverlayCoordinates(handle, origin, coordinatesInOverlay, matrix); }
            virtual bool pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t eventSize) { return Overlay_024::pollNextOverlayEvent(handle, event, eventSize); }
            virtual OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod) { return Overlay_024::getOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod) { return Overlay_024::setOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale) { return Overlay_024::getOverlayMouseScale(handle, mouseScale); }
            virtual OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale) { return Overlay_024::setOverlayMouseScale(handle, mouseScale); }
            virtual bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results) { return Overlay_024::computeOverlayIntersection(handle, params, results); }
            virtual bool isHoverTargetOverlay(uint64_t handle) { return Overlay_024::isHoverTargetOverlay(handle); }
            virtual OverlayError setOverlayIntersectionMask(uint64_t handle, OverlayIntersectionMaskPrimitive* primitives, uint32_t primitivesCount, uint32_t primitiveSize) { return Overlay_024::setOverlayIntersectionMask(handle, primitives, primitivesCount, primitiveSize); }
            virtual OverlayError triggerLaserMouseHapticVibration(uint64_t handle, float durationSeconds, float frequency, float amplitude) { return Overlay_024::triggerLaserMouseHapticVibration(handle, durationSeconds, frequency, amplitude); }
            virtual OverlayError setOverlayCursor(uint64_t handle, uint64_t cursorHandle) { return Overlay_024::setOverlayCursor(handle, cursorHandle); }
            virtual OverlayError setOverlayCursorPositionOverride(uint64_t handle, const Vector2* position) { return Overlay_024::setOverlayCursorPositionOverride(handle, position); }
            virtual OverlayError clearOverlayCursorPositionOverride(uint64_t handle) { return Overlay_024::clearOverlayCursorPositionOverride(handle); }
            virtual OverlayError setOverlayTexture(uint64_t handle, const Texture* texture) { return Overlay_024::setOverlayTexture(handle, texture); }
            virtual OverlayError clearOverlayTexture(uint64_t handle) { return Overlay_024::clearOverlayTexture(handle); }
            virtual OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth) { return Overlay_024::setOverlayRaw(handle, buffer, width, height, depth); }
            virtual OverlayError setOverlayFromFile(uint64_t handle, const char* filePath) { return Overlay_024::setOverlayFromFile(handle, filePath); }
            virtual OverlayError getOverlayNativeTexture(uint64_t handle, void** nativeTextureHandle, void* nativeTextureRef, uint32_t* width, uint32_t* height, uint32_t* format, TextureType* type, ColorSpace* colorSpace, TextureBounds* bounds) { return Overlay_024::getOverlayNativeTexture(handle, nativeTextureHandle, nativeTextureRef, width, height, format, type, colorSpace, bounds); }
            virtual OverlayError releaseNativeOverlayTexture(uint64_t handle, void* nativeTextureHandle) { return Overlay_024::releaseNativeOverlayTexture(handle, nativeTextureHandle); }
            virtual OverlayError getOverlayTextureSize(uint64_t handle, uint32_t* width, uint32_t* height) { return Overlay_024::getOverlayTextureSize(handle, width, height); }
            virtual OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle) { return Overlay_024::createDashboardOverlay(key, friendlyName, mainHandle, thumbnailHandle); }
            virtual bool isDashboardVisible() { return Overlay_024::isDashboardVisible(); }
            virtual bool isActiveDashboardOverlay(uint64_t handle) { return Overlay_024::isActiveDashboardOverlay(handle); }
            virtual OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid) { return Overlay_024::setDashboardOverlaySceneProcess(handle, pid); }
            virtual OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid) { return Overlay_024::getDashboardOverlaySceneProcess(handle, pid); }
            virtual void showDashboard(const char* overlayToShow) { return Overlay_024::showDashboard(overlayToShow); }
            virtual uint32_t getPrimaryDashboardInputTrackedDevice() { return Overlay_024::getPrimaryDashboardInputTrackedDevice(); }
            virtual OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, uint32_t flags, const char* description, uint32_t maxChars, const char* existingText, uint64_t userValue) { return Overlay_024::showKeyboard(textInputMode, textInputLineMode, flags, description, maxChars, existingText, userValue); }
            virtual OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, uint32_t flags, const char* description, uint32_t maxChars, const char* existingText, uint64_t userValue) { return Overlay_024::showKeyboardForOverlay(handle, textInputMode, textInputLineMode, flags, description, maxChars, existingText, userValue); }
            virtual uint32_t getKeyboardText(char* text, uint32_t bufferSize) { return Overlay_024::getKeyboardText(text, bufferSize); }
            virtual void hideKeyboard() { return Overlay_024::hideKeyboard(); }
            virtual void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_024::setKeyboardTransformAbsolute(origin, matrix); }
            virtual void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect) { return Overlay_024::setKeyboardPositionForOverlay(handle, avoidRect); }
            virtual MessageOverlayResponse showMessageOverlay(const char* text, const char* caption, const char* button0Text, const char* button1Text, const char* button2Text, const char* button3Text) { return Overlay_024::showMessageOverlay(text, caption, button0Text, button1Text, button2Text, button3Text); }
            virtual void closeMessageOverlay() { return Overlay_024::closeMessageOverlay(); }
    };

    //

    struct Overlay_025
    {
        static OverlayError findOverlay(const char* key, uint64_t* handle);

        static OverlayError createOverlay(const char* key, const char* name, uint64_t* handle);
        static OverlayError destroyOverlay(uint64_t handle);

        static uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static OverlayError setOverlayName(uint64_t handle, const char* name);
        static OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height);

        static const char* getOverlayErrorNameFromEnum(OverlayError error);

        static OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid);
        static uint32_t getOverlayRenderingPid(uint64_t handle);

        static OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled);
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled);
        static OverlayError getOverlayFlags(uint64_t handle, uint32_t* flags);

        static OverlayError setOverlayColor(uint64_t handle, float r, float g, float b);
        static OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b);
        static OverlayError setOverlayAlpha(uint64_t handle, float alpha);
        static OverlayError getOverlayAlpha(uint64_t handle, float* alpha);

        static OverlayError setOverlayTexelAspectRatio(uint64_t handle, float aspect);
        static OverlayError getOverlayTexelAspectRatio(uint64_t handle, float* aspect);
        static OverlayError setOverlaySortOrder(uint64_t handle, uint32_t sortOrder);
        static OverlayError getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder);
        static OverlayError setOverlayWidthInMeters(uint64_t handle, float width);
        static OverlayError getOverlayWidthInMeters(uint64_t handle, float* width);
        static OverlayError setOverlayCurvature(uint64_t handle, float curvature);
        static OverlayError getOverlayCurvature(uint64_t handle, float* curvature);

        static OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace);
        static OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace);
        static OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds);
        static OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds);

        static OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType);
        static OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix);
        static OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix);
        static OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName);
        static OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize);
        static OverlayError getOverlayTransformOverlayRelative(uint64_t handle, uint64_t* parentHandle, Matrix34* matrix);
        static OverlayError setOverlayTransformOverlayRelative(uint64_t handle, uint64_t parentHandle, const Matrix34* matrix);
        static OverlayError setOverlayTransformOverlayCursor(uint64_t handle, const Vector2* hotspot);
        static OverlayError getOverlayTransformOverlayCursor(uint64_t handle, Vector2* hotspot);
        static OverlayError setOverlayTransformProjection(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix, const OverlayProjection* projection, Eye eye);

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

        static OverlayError setOverlayIntersectionMask(uint64_t handle, OverlayIntersectionMaskPrimitive* primitives, uint32_t primitivesCount, uint32_t primitiveSize);
        static OverlayError triggerLaserMouseHapticVibration(uint64_t handle, float durationSeconds, float frequency, float amplitude);
        static OverlayError setOverlayCursor(uint64_t handle, uint64_t cursorHandle);
        static OverlayError setOverlayCursorPositionOverride(uint64_t handle, const Vector2* position);
        static OverlayError clearOverlayCursorPositionOverride(uint64_t handle);

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

        static OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, uint32_t flags, const char* description, uint32_t maxChars, const char* existingText, uint64_t userValue);
        static OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, uint32_t flags, const char* description, uint32_t maxChars, const char* existingText, uint64_t userValue);
        static uint32_t getKeyboardText(char* text, uint32_t bufferSize);
        static void hideKeyboard();
        static void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix);
        static void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect);

        static MessageOverlayResponse showMessageOverlay(const char* text, const char* caption, const char* button0Text, const char* button1Text, const char* button2Text, const char* button3Text);
        static void closeMessageOverlay();

        void* findOverlay_ = (void*) findOverlay;
        void* createOverlay_ = (void*) createOverlay;
        void* destroyOverlay_ = (void*) destroyOverlay;
        void* getOverlayKey_ = (void*) getOverlayKey;
        void* getOverlayName_ = (void*) getOverlayName;
        void* setOverlayName_ = (void*) setOverlayName;
        void* getOverlayImageData_ = (void*) getOverlayImageData;
        void* getOverlayErrorNameFromEnum_ = (void*) getOverlayErrorNameFromEnum;
        void* setOverlayRenderingPid_ = (void*) setOverlayRenderingPid;
        void* getOverlayRenderingPid_ = (void*) getOverlayRenderingPid;
        void* setOverlayFlag_ = (void*) setOverlayFlag;
        void* getOverlayFlag_ = (void*) getOverlayFlag;
        void* getOverlayFlags_ = (void*) getOverlayFlags;
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
        void* setOverlayCurvature_ = (void*) setOverlayCurvature;
        void* getOverlayCurvature_ = (void*) getOverlayCurvature;
        void* setOverlayTextureColorSpace_ = (void*) setOverlayTextureColorSpace;
        void* getOverlayTextureColorSpace_ = (void*) getOverlayTextureColorSpace;
        void* setOverlayTextureBounds_ = (void*) setOverlayTextureBounds;
        void* getOverlayTextureBounds_ = (void*) getOverlayTextureBounds;
        void* getOverlayTransformType_ = (void*) getOverlayTransformType;
        void* setOverlayTransformAbsolute_ = (void*) setOverlayTransformAbsolute;
        void* getOverlayTransformAbsolute_ = (void*) getOverlayTransformAbsolute;
        void* setOverlayTransformTrackedDeviceRelative_ = (void*) setOverlayTransformTrackedDeviceRelative;
        void* getOverlayTransformTrackedDeviceRelative_ = (void*) getOverlayTransformTrackedDeviceRelative;
        void* setOverlayTransformTrackedDeviceComponent_ = (void*) setOverlayTransformTrackedDeviceComponent;
        void* getOverlayTransformTrackedDeviceComponent_ = (void*) getOverlayTransformTrackedDeviceComponent;
        void* getOverlayTransformOverlayRelative_ = (void*) getOverlayTransformOverlayRelative;
        void* setOverlayTransformOverlayRelative_ = (void*) setOverlayTransformOverlayRelative;
        void* setOverlayTransformOverlayCursor_ = (void*) setOverlayTransformOverlayCursor;
        void* getOverlayTransformOverlayCursor_ = (void*) getOverlayTransformOverlayCursor;
        void* setOverlayTransformProjection_ = (void*) setOverlayTransformProjection;
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
        void* setOverlayIntersectionMask_ = (void*) setOverlayIntersectionMask;
        void* triggerLaserMouseHapticVibration_ = (void*) triggerLaserMouseHapticVibration;
        void* setOverlayCursor_ = (void*) setOverlayCursor;
        void* setOverlayCursorPositionOverride_ = (void*) setOverlayCursorPositionOverride;
        void* clearOverlayCursorPositionOverride_ = (void*) clearOverlayCursorPositionOverride;
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
        void* showMessageOverlay_ = (void*) showMessageOverlay;
        void* closeMessageOverlay_ = (void*) closeMessageOverlay;
    };

    class Overlay_025_v
    {
        public:
            virtual OverlayError findOverlay(const char* key, uint64_t* handle) { return Overlay_025::findOverlay(key, handle); }
            virtual OverlayError createOverlay(const char* key, const char* name, uint64_t* handle) { return Overlay_025::createOverlay(key, name, handle); }
            virtual OverlayError destroyOverlay(uint64_t handle) { return Overlay_025::destroyOverlay(handle); }
            virtual uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_025::getOverlayKey(handle, value, bufferSize, error); }
            virtual uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_025::getOverlayName(handle, value, bufferSize, error); }
            virtual OverlayError setOverlayName(uint64_t handle, const char* name) { return Overlay_025::setOverlayName(handle, name); }
            virtual OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height) { return Overlay_025::getOverlayImageData(handle, buffer, bufferSize, width, height); }
            virtual const char* getOverlayErrorNameFromEnum(OverlayError error) { return Overlay_025::getOverlayErrorNameFromEnum(error); }
            virtual OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid) { return Overlay_025::setOverlayRenderingPid(handle, pid); }
            virtual uint32_t getOverlayRenderingPid(uint64_t handle) { return Overlay_025::getOverlayRenderingPid(handle); }
            virtual OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled) { return Overlay_025::setOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled) { return Overlay_025::getOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlags(uint64_t handle, uint32_t* flags) { return Overlay_025::getOverlayFlags(handle, flags); }
            virtual OverlayError setOverlayColor(uint64_t handle, float r, float g, float b) { return Overlay_025::setOverlayColor(handle, r, g, b); }
            virtual OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b) { return Overlay_025::getOverlayColor(handle, r, g, b); }
            virtual OverlayError setOverlayAlpha(uint64_t handle, float alpha) { return Overlay_025::setOverlayAlpha(handle, alpha); }
            virtual OverlayError getOverlayAlpha(uint64_t handle, float* alpha) { return Overlay_025::getOverlayAlpha(handle, alpha); }
            virtual OverlayError setOverlayTexelAspectRatio(uint64_t handle, float aspect) { return Overlay_025::setOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError getOverlayTexelAspectRatio(uint64_t handle, float* aspect) { return Overlay_025::getOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError setOverlaySortOrder(uint64_t handle, uint32_t sortOrder) { return Overlay_025::setOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder) { return Overlay_025::getOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError setOverlayWidthInMeters(uint64_t handle, float width) { return Overlay_025::setOverlayWidthInMeters(handle, width); }
            virtual OverlayError getOverlayWidthInMeters(uint64_t handle, float* width) { return Overlay_025::getOverlayWidthInMeters(handle, width); }
            virtual OverlayError setOverlayCurvature(uint64_t handle, float curvature) { return Overlay_025::setOverlayCurvature(handle, curvature); }
            virtual OverlayError getOverlayCurvature(uint64_t handle, float* curvature) { return Overlay_025::getOverlayCurvature(handle, curvature); }
            virtual OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace) { return Overlay_025::setOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace) { return Overlay_025::getOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds) { return Overlay_025::setOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_025::getOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType) { return Overlay_025::getOverlayTransformType(handle, transformType); }
            virtual OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_025::setOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix) { return Overlay_025::getOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix) { return Overlay_025::setOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix) { return Overlay_025::getOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName) { return Overlay_025::setOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName); }
            virtual OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize) { return Overlay_025::getOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName, bufferSize); }
            virtual OverlayError getOverlayTransformOverlayRelative(uint64_t handle, uint64_t* parentHandle, Matrix34* matrix) { return Overlay_025::getOverlayTransformOverlayRelative(handle, parentHandle, matrix); }
            virtual OverlayError setOverlayTransformOverlayRelative(uint64_t handle, uint64_t parentHandle, const Matrix34* matrix) { return Overlay_025::setOverlayTransformOverlayRelative(handle, parentHandle, matrix); }
            virtual OverlayError setOverlayTransformOverlayCursor(uint64_t handle, const Vector2* hotspot) { return Overlay_025::setOverlayTransformOverlayCursor(handle, hotspot); }
            virtual OverlayError getOverlayTransformOverlayCursor(uint64_t handle, Vector2* hotspot) { return Overlay_025::getOverlayTransformOverlayCursor(handle, hotspot); }
            virtual OverlayError setOverlayTransformProjection(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix, const OverlayProjection* projection, Eye eye) { return Overlay_025::setOverlayTransformProjection(handle, origin, matrix, projection, eye); }
            virtual OverlayError showOverlay(uint64_t handle) { return Overlay_025::showOverlay(handle); }
            virtual OverlayError hideOverlay(uint64_t handle) { return Overlay_025::hideOverlay(handle); }
            virtual bool isOverlayVisible(uint64_t handle) { return Overlay_025::isOverlayVisible(handle); }
            virtual OverlayError getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix) { return Overlay_025::getTransformForOverlayCoordinates(handle, origin, coordinatesInOverlay, matrix); }
            virtual bool pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t eventSize) { return Overlay_025::pollNextOverlayEvent(handle, event, eventSize); }
            virtual OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod) { return Overlay_025::getOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod) { return Overlay_025::setOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale) { return Overlay_025::getOverlayMouseScale(handle, mouseScale); }
            virtual OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale) { return Overlay_025::setOverlayMouseScale(handle, mouseScale); }
            virtual bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results) { return Overlay_025::computeOverlayIntersection(handle, params, results); }
            virtual bool isHoverTargetOverlay(uint64_t handle) { return Overlay_025::isHoverTargetOverlay(handle); }
            virtual OverlayError setOverlayIntersectionMask(uint64_t handle, OverlayIntersectionMaskPrimitive* primitives, uint32_t primitivesCount, uint32_t primitiveSize) { return Overlay_025::setOverlayIntersectionMask(handle, primitives, primitivesCount, primitiveSize); }
            virtual OverlayError triggerLaserMouseHapticVibration(uint64_t handle, float durationSeconds, float frequency, float amplitude) { return Overlay_025::triggerLaserMouseHapticVibration(handle, durationSeconds, frequency, amplitude); }
            virtual OverlayError setOverlayCursor(uint64_t handle, uint64_t cursorHandle) { return Overlay_025::setOverlayCursor(handle, cursorHandle); }
            virtual OverlayError setOverlayCursorPositionOverride(uint64_t handle, const Vector2* position) { return Overlay_025::setOverlayCursorPositionOverride(handle, position); }
            virtual OverlayError clearOverlayCursorPositionOverride(uint64_t handle) { return Overlay_025::clearOverlayCursorPositionOverride(handle); }
            virtual OverlayError setOverlayTexture(uint64_t handle, const Texture* texture) { return Overlay_025::setOverlayTexture(handle, texture); }
            virtual OverlayError clearOverlayTexture(uint64_t handle) { return Overlay_025::clearOverlayTexture(handle); }
            virtual OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth) { return Overlay_025::setOverlayRaw(handle, buffer, width, height, depth); }
            virtual OverlayError setOverlayFromFile(uint64_t handle, const char* filePath) { return Overlay_025::setOverlayFromFile(handle, filePath); }
            virtual OverlayError getOverlayNativeTexture(uint64_t handle, void** nativeTextureHandle, void* nativeTextureRef, uint32_t* width, uint32_t* height, uint32_t* format, TextureType* type, ColorSpace* colorSpace, TextureBounds* bounds) { return Overlay_025::getOverlayNativeTexture(handle, nativeTextureHandle, nativeTextureRef, width, height, format, type, colorSpace, bounds); }
            virtual OverlayError releaseNativeOverlayTexture(uint64_t handle, void* nativeTextureHandle) { return Overlay_025::releaseNativeOverlayTexture(handle, nativeTextureHandle); }
            virtual OverlayError getOverlayTextureSize(uint64_t handle, uint32_t* width, uint32_t* height) { return Overlay_025::getOverlayTextureSize(handle, width, height); }
            virtual OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle) { return Overlay_025::createDashboardOverlay(key, friendlyName, mainHandle, thumbnailHandle); }
            virtual bool isDashboardVisible() { return Overlay_025::isDashboardVisible(); }
            virtual bool isActiveDashboardOverlay(uint64_t handle) { return Overlay_025::isActiveDashboardOverlay(handle); }
            virtual OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid) { return Overlay_025::setDashboardOverlaySceneProcess(handle, pid); }
            virtual OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid) { return Overlay_025::getDashboardOverlaySceneProcess(handle, pid); }
            virtual void showDashboard(const char* overlayToShow) { return Overlay_025::showDashboard(overlayToShow); }
            virtual uint32_t getPrimaryDashboardInputTrackedDevice() { return Overlay_025::getPrimaryDashboardInputTrackedDevice(); }
            virtual OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, uint32_t flags, const char* description, uint32_t maxChars, const char* existingText, uint64_t userValue) { return Overlay_025::showKeyboard(textInputMode, textInputLineMode, flags, description, maxChars, existingText, userValue); }
            virtual OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, uint32_t flags, const char* description, uint32_t maxChars, const char* existingText, uint64_t userValue) { return Overlay_025::showKeyboardForOverlay(handle, textInputMode, textInputLineMode, flags, description, maxChars, existingText, userValue); }
            virtual uint32_t getKeyboardText(char* text, uint32_t bufferSize) { return Overlay_025::getKeyboardText(text, bufferSize); }
            virtual void hideKeyboard() { return Overlay_025::hideKeyboard(); }
            virtual void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_025::setKeyboardTransformAbsolute(origin, matrix); }
            virtual void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect) { return Overlay_025::setKeyboardPositionForOverlay(handle, avoidRect); }
            virtual MessageOverlayResponse showMessageOverlay(const char* text, const char* caption, const char* button0Text, const char* button1Text, const char* button2Text, const char* button3Text) { return Overlay_025::showMessageOverlay(text, caption, button0Text, button1Text, button2Text, button3Text); }
            virtual void closeMessageOverlay() { return Overlay_025::closeMessageOverlay(); }
    };

    //

    struct Overlay_026
    {
        static OverlayError findOverlay(const char* key, uint64_t* handle);

        static OverlayError createOverlay(const char* key, const char* name, uint64_t* handle);
        static OverlayError destroyOverlay(uint64_t handle);

        static uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static OverlayError setOverlayName(uint64_t handle, const char* name);
        static OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height);

        static const char* getOverlayErrorNameFromEnum(OverlayError error);

        static OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid);
        static uint32_t getOverlayRenderingPid(uint64_t handle);

        static OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled);
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled);
        static OverlayError getOverlayFlags(uint64_t handle, uint32_t* flags);

        static OverlayError setOverlayColor(uint64_t handle, float r, float g, float b);
        static OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b);
        static OverlayError setOverlayAlpha(uint64_t handle, float alpha);
        static OverlayError getOverlayAlpha(uint64_t handle, float* alpha);

        static OverlayError setOverlayTexelAspectRatio(uint64_t handle, float aspect);
        static OverlayError getOverlayTexelAspectRatio(uint64_t handle, float* aspect);
        static OverlayError setOverlaySortOrder(uint64_t handle, uint32_t sortOrder);
        static OverlayError getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder);
        static OverlayError setOverlayWidthInMeters(uint64_t handle, float width);
        static OverlayError getOverlayWidthInMeters(uint64_t handle, float* width);
        static OverlayError setOverlayCurvature(uint64_t handle, float curvature);
        static OverlayError getOverlayCurvature(uint64_t handle, float* curvature);
        static OverlayError setOverlayPreCurvePitch(uint64_t handle, float radians);
        static OverlayError getOverlayPreCurvePitch(uint64_t handle, float* radians);

        static OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace);
        static OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace);
        static OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds);
        static OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds);

        static OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType);
        static OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix);
        static OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix);
        static OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName);
        static OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize);
        static OverlayError getOverlayTransformOverlayRelative(uint64_t handle, uint64_t* parentHandle, Matrix34* matrix);
        static OverlayError setOverlayTransformOverlayRelative(uint64_t handle, uint64_t parentHandle, const Matrix34* matrix);
        static OverlayError setOverlayTransformOverlayCursor(uint64_t handle, const Vector2* hotspot);
        static OverlayError getOverlayTransformOverlayCursor(uint64_t handle, Vector2* hotspot);
        static OverlayError setOverlayTransformProjection(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix, const OverlayProjection* projection, Eye eye);

        static OverlayError showOverlay(uint64_t handle);
        static OverlayError hideOverlay(uint64_t handle);
        static bool isOverlayVisible(uint64_t handle);

        static OverlayError getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix);

        static OverlayError waitFrameSync(uint32_t timeout);
        static bool pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t eventSize);

        static OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod);
        static OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod);
        static OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale);
        static OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale);

        static bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results);
        static bool isHoverTargetOverlay(uint64_t handle);

        static OverlayError setOverlayIntersectionMask(uint64_t handle, OverlayIntersectionMaskPrimitive* primitives, uint32_t primitivesCount, uint32_t primitiveSize);
        static OverlayError triggerLaserMouseHapticVibration(uint64_t handle, float durationSeconds, float frequency, float amplitude);
        static OverlayError setOverlayCursor(uint64_t handle, uint64_t cursorHandle);
        static OverlayError setOverlayCursorPositionOverride(uint64_t handle, const Vector2* position);
        static OverlayError clearOverlayCursorPositionOverride(uint64_t handle);

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

        static OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, uint32_t flags, const char* description, uint32_t maxChars, const char* existingText, uint64_t userValue);
        static OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, uint32_t flags, const char* description, uint32_t maxChars, const char* existingText, uint64_t userValue);
        static uint32_t getKeyboardText(char* text, uint32_t bufferSize);
        static void hideKeyboard();
        static void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix);
        static void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect);

        static MessageOverlayResponse showMessageOverlay(const char* text, const char* caption, const char* button0Text, const char* button1Text, const char* button2Text, const char* button3Text);
        static void closeMessageOverlay();

        void* findOverlay_ = (void*) findOverlay;
        void* createOverlay_ = (void*) createOverlay;
        void* destroyOverlay_ = (void*) destroyOverlay;
        void* getOverlayKey_ = (void*) getOverlayKey;
        void* getOverlayName_ = (void*) getOverlayName;
        void* setOverlayName_ = (void*) setOverlayName;
        void* getOverlayImageData_ = (void*) getOverlayImageData;
        void* getOverlayErrorNameFromEnum_ = (void*) getOverlayErrorNameFromEnum;
        void* setOverlayRenderingPid_ = (void*) setOverlayRenderingPid;
        void* getOverlayRenderingPid_ = (void*) getOverlayRenderingPid;
        void* setOverlayFlag_ = (void*) setOverlayFlag;
        void* getOverlayFlag_ = (void*) getOverlayFlag;
        void* getOverlayFlags_ = (void*) getOverlayFlags;
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
        void* setOverlayCurvature_ = (void*) setOverlayCurvature;
        void* getOverlayCurvature_ = (void*) getOverlayCurvature;
        void* setOverlayPreCurvePitch_ = (void*) setOverlayPreCurvePitch;
        void* getOverlayPreCurvePitch_ = (void*) getOverlayPreCurvePitch;
        void* setOverlayTextureColorSpace_ = (void*) setOverlayTextureColorSpace;
        void* getOverlayTextureColorSpace_ = (void*) getOverlayTextureColorSpace;
        void* setOverlayTextureBounds_ = (void*) setOverlayTextureBounds;
        void* getOverlayTextureBounds_ = (void*) getOverlayTextureBounds;
        void* getOverlayTransformType_ = (void*) getOverlayTransformType;
        void* setOverlayTransformAbsolute_ = (void*) setOverlayTransformAbsolute;
        void* getOverlayTransformAbsolute_ = (void*) getOverlayTransformAbsolute;
        void* setOverlayTransformTrackedDeviceRelative_ = (void*) setOverlayTransformTrackedDeviceRelative;
        void* getOverlayTransformTrackedDeviceRelative_ = (void*) getOverlayTransformTrackedDeviceRelative;
        void* setOverlayTransformTrackedDeviceComponent_ = (void*) setOverlayTransformTrackedDeviceComponent;
        void* getOverlayTransformTrackedDeviceComponent_ = (void*) getOverlayTransformTrackedDeviceComponent;
        void* getOverlayTransformOverlayRelative_ = (void*) getOverlayTransformOverlayRelative;
        void* setOverlayTransformOverlayRelative_ = (void*) setOverlayTransformOverlayRelative;
        void* setOverlayTransformOverlayCursor_ = (void*) setOverlayTransformOverlayCursor;
        void* getOverlayTransformOverlayCursor_ = (void*) getOverlayTransformOverlayCursor;
        void* setOverlayTransformProjection_ = (void*) setOverlayTransformProjection;
        void* showOverlay_ = (void*) showOverlay;
        void* hideOverlay_ = (void*) hideOverlay;
        void* isOverlayVisible_ = (void*) isOverlayVisible;
        void* getTransformForOverlayCoordinates_ = (void*) getTransformForOverlayCoordinates;
        void* waitFrameSync_ = (void*) waitFrameSync;
        void* pollNextOverlayEvent_ = (void*) pollNextOverlayEvent;
        void* getOverlayInputMethod_ = (void*) getOverlayInputMethod;
        void* setOverlayInputMethod_ = (void*) setOverlayInputMethod;
        void* getOverlayMouseScale_ = (void*) getOverlayMouseScale;
        void* setOverlayMouseScale_ = (void*) setOverlayMouseScale;
        void* computeOverlayIntersection_ = (void*) computeOverlayIntersection;
        void* isHoverTargetOverlay_ = (void*) isHoverTargetOverlay;
        void* setOverlayIntersectionMask_ = (void*) setOverlayIntersectionMask;
        void* triggerLaserMouseHapticVibration_ = (void*) triggerLaserMouseHapticVibration;
        void* setOverlayCursor_ = (void*) setOverlayCursor;
        void* setOverlayCursorPositionOverride_ = (void*) setOverlayCursorPositionOverride;
        void* clearOverlayCursorPositionOverride_ = (void*) clearOverlayCursorPositionOverride;
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
        void* showMessageOverlay_ = (void*) showMessageOverlay;
        void* closeMessageOverlay_ = (void*) closeMessageOverlay;
    };

    class Overlay_026_v
    {
        public:
            virtual OverlayError findOverlay(const char* key, uint64_t* handle) { return Overlay_026::findOverlay(key, handle); }
            virtual OverlayError createOverlay(const char* key, const char* name, uint64_t* handle) { return Overlay_026::createOverlay(key, name, handle); }
            virtual OverlayError destroyOverlay(uint64_t handle) { return Overlay_026::destroyOverlay(handle); }
            virtual uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_026::getOverlayKey(handle, value, bufferSize, error); }
            virtual uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_026::getOverlayName(handle, value, bufferSize, error); }
            virtual OverlayError setOverlayName(uint64_t handle, const char* name) { return Overlay_026::setOverlayName(handle, name); }
            virtual OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height) { return Overlay_026::getOverlayImageData(handle, buffer, bufferSize, width, height); }
            virtual const char* getOverlayErrorNameFromEnum(OverlayError error) { return Overlay_026::getOverlayErrorNameFromEnum(error); }
            virtual OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid) { return Overlay_026::setOverlayRenderingPid(handle, pid); }
            virtual uint32_t getOverlayRenderingPid(uint64_t handle) { return Overlay_026::getOverlayRenderingPid(handle); }
            virtual OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled) { return Overlay_026::setOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled) { return Overlay_026::getOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlags(uint64_t handle, uint32_t* flags) { return Overlay_026::getOverlayFlags(handle, flags); }
            virtual OverlayError setOverlayColor(uint64_t handle, float r, float g, float b) { return Overlay_026::setOverlayColor(handle, r, g, b); }
            virtual OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b) { return Overlay_026::getOverlayColor(handle, r, g, b); }
            virtual OverlayError setOverlayAlpha(uint64_t handle, float alpha) { return Overlay_026::setOverlayAlpha(handle, alpha); }
            virtual OverlayError getOverlayAlpha(uint64_t handle, float* alpha) { return Overlay_026::getOverlayAlpha(handle, alpha); }
            virtual OverlayError setOverlayTexelAspectRatio(uint64_t handle, float aspect) { return Overlay_026::setOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError getOverlayTexelAspectRatio(uint64_t handle, float* aspect) { return Overlay_026::getOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError setOverlaySortOrder(uint64_t handle, uint32_t sortOrder) { return Overlay_026::setOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder) { return Overlay_026::getOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError setOverlayWidthInMeters(uint64_t handle, float width) { return Overlay_026::setOverlayWidthInMeters(handle, width); }
            virtual OverlayError getOverlayWidthInMeters(uint64_t handle, float* width) { return Overlay_026::getOverlayWidthInMeters(handle, width); }
            virtual OverlayError setOverlayCurvature(uint64_t handle, float curvature) { return Overlay_026::setOverlayCurvature(handle, curvature); }
            virtual OverlayError getOverlayCurvature(uint64_t handle, float* curvature) { return Overlay_026::getOverlayCurvature(handle, curvature); }
            virtual OverlayError setOverlayPreCurvePitch(uint64_t handle, float radians) { return Overlay_026::setOverlayPreCurvePitch(handle, radians); }
            virtual OverlayError getOverlayPreCurvePitch(uint64_t handle, float* radians) { return Overlay_026::getOverlayPreCurvePitch(handle, radians); }
            virtual OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace) { return Overlay_026::setOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace) { return Overlay_026::getOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds) { return Overlay_026::setOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_026::getOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType) { return Overlay_026::getOverlayTransformType(handle, transformType); }
            virtual OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_026::setOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix) { return Overlay_026::getOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix) { return Overlay_026::setOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix) { return Overlay_026::getOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName) { return Overlay_026::setOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName); }
            virtual OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize) { return Overlay_026::getOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName, bufferSize); }
            virtual OverlayError getOverlayTransformOverlayRelative(uint64_t handle, uint64_t* parentHandle, Matrix34* matrix) { return Overlay_026::getOverlayTransformOverlayRelative(handle, parentHandle, matrix); }
            virtual OverlayError setOverlayTransformOverlayRelative(uint64_t handle, uint64_t parentHandle, const Matrix34* matrix) { return Overlay_026::setOverlayTransformOverlayRelative(handle, parentHandle, matrix); }
            virtual OverlayError setOverlayTransformOverlayCursor(uint64_t handle, const Vector2* hotspot) { return Overlay_026::setOverlayTransformOverlayCursor(handle, hotspot); }
            virtual OverlayError getOverlayTransformOverlayCursor(uint64_t handle, Vector2* hotspot) { return Overlay_026::getOverlayTransformOverlayCursor(handle, hotspot); }
            virtual OverlayError setOverlayTransformProjection(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix, const OverlayProjection* projection, Eye eye) { return Overlay_026::setOverlayTransformProjection(handle, origin, matrix, projection, eye); }
            virtual OverlayError showOverlay(uint64_t handle) { return Overlay_026::showOverlay(handle); }
            virtual OverlayError hideOverlay(uint64_t handle) { return Overlay_026::hideOverlay(handle); }
            virtual bool isOverlayVisible(uint64_t handle) { return Overlay_026::isOverlayVisible(handle); }
            virtual OverlayError getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix) { return Overlay_026::getTransformForOverlayCoordinates(handle, origin, coordinatesInOverlay, matrix); }
            virtual OverlayError waitFrameSync(uint32_t timeout) { return Overlay_026::waitFrameSync(timeout); }
            virtual bool pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t eventSize) { return Overlay_026::pollNextOverlayEvent(handle, event, eventSize); }
            virtual OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod) { return Overlay_026::getOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod) { return Overlay_026::setOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale) { return Overlay_026::getOverlayMouseScale(handle, mouseScale); }
            virtual OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale) { return Overlay_026::setOverlayMouseScale(handle, mouseScale); }
            virtual bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results) { return Overlay_026::computeOverlayIntersection(handle, params, results); }
            virtual bool isHoverTargetOverlay(uint64_t handle) { return Overlay_026::isHoverTargetOverlay(handle); }
            virtual OverlayError setOverlayIntersectionMask(uint64_t handle, OverlayIntersectionMaskPrimitive* primitives, uint32_t primitivesCount, uint32_t primitiveSize) { return Overlay_026::setOverlayIntersectionMask(handle, primitives, primitivesCount, primitiveSize); }
            virtual OverlayError triggerLaserMouseHapticVibration(uint64_t handle, float durationSeconds, float frequency, float amplitude) { return Overlay_026::triggerLaserMouseHapticVibration(handle, durationSeconds, frequency, amplitude); }
            virtual OverlayError setOverlayCursor(uint64_t handle, uint64_t cursorHandle) { return Overlay_026::setOverlayCursor(handle, cursorHandle); }
            virtual OverlayError setOverlayCursorPositionOverride(uint64_t handle, const Vector2* position) { return Overlay_026::setOverlayCursorPositionOverride(handle, position); }
            virtual OverlayError clearOverlayCursorPositionOverride(uint64_t handle) { return Overlay_026::clearOverlayCursorPositionOverride(handle); }
            virtual OverlayError setOverlayTexture(uint64_t handle, const Texture* texture) { return Overlay_026::setOverlayTexture(handle, texture); }
            virtual OverlayError clearOverlayTexture(uint64_t handle) { return Overlay_026::clearOverlayTexture(handle); }
            virtual OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth) { return Overlay_026::setOverlayRaw(handle, buffer, width, height, depth); }
            virtual OverlayError setOverlayFromFile(uint64_t handle, const char* filePath) { return Overlay_026::setOverlayFromFile(handle, filePath); }
            virtual OverlayError getOverlayNativeTexture(uint64_t handle, void** nativeTextureHandle, void* nativeTextureRef, uint32_t* width, uint32_t* height, uint32_t* format, TextureType* type, ColorSpace* colorSpace, TextureBounds* bounds) { return Overlay_026::getOverlayNativeTexture(handle, nativeTextureHandle, nativeTextureRef, width, height, format, type, colorSpace, bounds); }
            virtual OverlayError releaseNativeOverlayTexture(uint64_t handle, void* nativeTextureHandle) { return Overlay_026::releaseNativeOverlayTexture(handle, nativeTextureHandle); }
            virtual OverlayError getOverlayTextureSize(uint64_t handle, uint32_t* width, uint32_t* height) { return Overlay_026::getOverlayTextureSize(handle, width, height); }
            virtual OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle) { return Overlay_026::createDashboardOverlay(key, friendlyName, mainHandle, thumbnailHandle); }
            virtual bool isDashboardVisible() { return Overlay_026::isDashboardVisible(); }
            virtual bool isActiveDashboardOverlay(uint64_t handle) { return Overlay_026::isActiveDashboardOverlay(handle); }
            virtual OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid) { return Overlay_026::setDashboardOverlaySceneProcess(handle, pid); }
            virtual OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid) { return Overlay_026::getDashboardOverlaySceneProcess(handle, pid); }
            virtual void showDashboard(const char* overlayToShow) { return Overlay_026::showDashboard(overlayToShow); }
            virtual uint32_t getPrimaryDashboardInputTrackedDevice() { return Overlay_026::getPrimaryDashboardInputTrackedDevice(); }
            virtual OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, uint32_t flags, const char* description, uint32_t maxChars, const char* existingText, uint64_t userValue) { return Overlay_026::showKeyboard(textInputMode, textInputLineMode, flags, description, maxChars, existingText, userValue); }
            virtual OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, uint32_t flags, const char* description, uint32_t maxChars, const char* existingText, uint64_t userValue) { return Overlay_026::showKeyboardForOverlay(handle, textInputMode, textInputLineMode, flags, description, maxChars, existingText, userValue); }
            virtual uint32_t getKeyboardText(char* text, uint32_t bufferSize) { return Overlay_026::getKeyboardText(text, bufferSize); }
            virtual void hideKeyboard() { return Overlay_026::hideKeyboard(); }
            virtual void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_026::setKeyboardTransformAbsolute(origin, matrix); }
            virtual void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect) { return Overlay_026::setKeyboardPositionForOverlay(handle, avoidRect); }
            virtual MessageOverlayResponse showMessageOverlay(const char* text, const char* caption, const char* button0Text, const char* button1Text, const char* button2Text, const char* button3Text) { return Overlay_026::showMessageOverlay(text, caption, button0Text, button1Text, button2Text, button3Text); }
            virtual void closeMessageOverlay() { return Overlay_026::closeMessageOverlay(); }
    };

    //

    struct Overlay_027
    {
        static OverlayError findOverlay(const char* key, uint64_t* handle);

        static OverlayError createOverlay(const char* key, const char* name, uint64_t* handle);
        static OverlayError destroyOverlay(uint64_t handle);

        static uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static OverlayError setOverlayName(uint64_t handle, const char* name);
        static OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height);

        static const char* getOverlayErrorNameFromEnum(OverlayError error);

        static OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid);
        static uint32_t getOverlayRenderingPid(uint64_t handle);

        static OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled);
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled);
        static OverlayError getOverlayFlags(uint64_t handle, uint32_t* flags);

        static OverlayError setOverlayColor(uint64_t handle, float r, float g, float b);
        static OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b);
        static OverlayError setOverlayAlpha(uint64_t handle, float alpha);
        static OverlayError getOverlayAlpha(uint64_t handle, float* alpha);

        static OverlayError setOverlayTexelAspectRatio(uint64_t handle, float aspect);
        static OverlayError getOverlayTexelAspectRatio(uint64_t handle, float* aspect);
        static OverlayError setOverlaySortOrder(uint64_t handle, uint32_t sortOrder);
        static OverlayError getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder);
        static OverlayError setOverlayWidthInMeters(uint64_t handle, float width);
        static OverlayError getOverlayWidthInMeters(uint64_t handle, float* width);
        static OverlayError setOverlayCurvature(uint64_t handle, float curvature);
        static OverlayError getOverlayCurvature(uint64_t handle, float* curvature);
        static OverlayError setOverlayPreCurvePitch(uint64_t handle, float radians);
        static OverlayError getOverlayPreCurvePitch(uint64_t handle, float* radians);

        static OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace);
        static OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace);
        static OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds);
        static OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds);

        static OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType);
        static OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix);
        static OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix);
        static OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName);
        static OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize);
        static OverlayError setOverlayTransformOverlayCursor(uint64_t handle, const Vector2* hotspot);
        static OverlayError getOverlayTransformOverlayCursor(uint64_t handle, Vector2* hotspot);
        static OverlayError setOverlayTransformProjection(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix, const OverlayProjection* projection, Eye eye);

        static OverlayError showOverlay(uint64_t handle);
        static OverlayError hideOverlay(uint64_t handle);
        static bool isOverlayVisible(uint64_t handle);

        static OverlayError getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix);

        static OverlayError waitFrameSync(uint32_t timeout);
        static bool pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t eventSize);

        static OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod);
        static OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod);
        static OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale);
        static OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale);

        static bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results);
        static bool isHoverTargetOverlay(uint64_t handle);

        static OverlayError setOverlayIntersectionMask(uint64_t handle, OverlayIntersectionMaskPrimitive* primitives, uint32_t primitivesCount, uint32_t primitiveSize);
        static OverlayError triggerLaserMouseHapticVibration(uint64_t handle, float durationSeconds, float frequency, float amplitude);
        static OverlayError setOverlayCursor(uint64_t handle, uint64_t cursorHandle);
        static OverlayError setOverlayCursorPositionOverride(uint64_t handle, const Vector2* position);
        static OverlayError clearOverlayCursorPositionOverride(uint64_t handle);

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

        static OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, uint32_t flags, const char* description, uint32_t maxChars, const char* existingText, uint64_t userValue);
        static OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, uint32_t flags, const char* description, uint32_t maxChars, const char* existingText, uint64_t userValue);
        static uint32_t getKeyboardText(char* text, uint32_t bufferSize);
        static void hideKeyboard();
        static void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix);
        static void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect);

        static MessageOverlayResponse showMessageOverlay(const char* text, const char* caption, const char* button0Text, const char* button1Text, const char* button2Text, const char* button3Text);
        static void closeMessageOverlay();

        void* findOverlay_ = (void*) findOverlay;
        void* createOverlay_ = (void*) createOverlay;
        void* destroyOverlay_ = (void*) destroyOverlay;
        void* getOverlayKey_ = (void*) getOverlayKey;
        void* getOverlayName_ = (void*) getOverlayName;
        void* setOverlayName_ = (void*) setOverlayName;
        void* getOverlayImageData_ = (void*) getOverlayImageData;
        void* getOverlayErrorNameFromEnum_ = (void*) getOverlayErrorNameFromEnum;
        void* setOverlayRenderingPid_ = (void*) setOverlayRenderingPid;
        void* getOverlayRenderingPid_ = (void*) getOverlayRenderingPid;
        void* setOverlayFlag_ = (void*) setOverlayFlag;
        void* getOverlayFlag_ = (void*) getOverlayFlag;
        void* getOverlayFlags_ = (void*) getOverlayFlags;
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
        void* setOverlayCurvature_ = (void*) setOverlayCurvature;
        void* getOverlayCurvature_ = (void*) getOverlayCurvature;
        void* setOverlayPreCurvePitch_ = (void*) setOverlayPreCurvePitch;
        void* getOverlayPreCurvePitch_ = (void*) getOverlayPreCurvePitch;
        void* setOverlayTextureColorSpace_ = (void*) setOverlayTextureColorSpace;
        void* getOverlayTextureColorSpace_ = (void*) getOverlayTextureColorSpace;
        void* setOverlayTextureBounds_ = (void*) setOverlayTextureBounds;
        void* getOverlayTextureBounds_ = (void*) getOverlayTextureBounds;
        void* getOverlayTransformType_ = (void*) getOverlayTransformType;
        void* setOverlayTransformAbsolute_ = (void*) setOverlayTransformAbsolute;
        void* getOverlayTransformAbsolute_ = (void*) getOverlayTransformAbsolute;
        void* setOverlayTransformTrackedDeviceRelative_ = (void*) setOverlayTransformTrackedDeviceRelative;
        void* getOverlayTransformTrackedDeviceRelative_ = (void*) getOverlayTransformTrackedDeviceRelative;
        void* setOverlayTransformTrackedDeviceComponent_ = (void*) setOverlayTransformTrackedDeviceComponent;
        void* getOverlayTransformTrackedDeviceComponent_ = (void*) getOverlayTransformTrackedDeviceComponent;
        void* setOverlayTransformOverlayCursor_ = (void*) setOverlayTransformOverlayCursor;
        void* getOverlayTransformOverlayCursor_ = (void*) getOverlayTransformOverlayCursor;
        void* setOverlayTransformProjection_ = (void*) setOverlayTransformProjection;
        void* showOverlay_ = (void*) showOverlay;
        void* hideOverlay_ = (void*) hideOverlay;
        void* isOverlayVisible_ = (void*) isOverlayVisible;
        void* getTransformForOverlayCoordinates_ = (void*) getTransformForOverlayCoordinates;
        void* waitFrameSync_ = (void*) waitFrameSync;
        void* pollNextOverlayEvent_ = (void*) pollNextOverlayEvent;
        void* getOverlayInputMethod_ = (void*) getOverlayInputMethod;
        void* setOverlayInputMethod_ = (void*) setOverlayInputMethod;
        void* getOverlayMouseScale_ = (void*) getOverlayMouseScale;
        void* setOverlayMouseScale_ = (void*) setOverlayMouseScale;
        void* computeOverlayIntersection_ = (void*) computeOverlayIntersection;
        void* isHoverTargetOverlay_ = (void*) isHoverTargetOverlay;
        void* setOverlayIntersectionMask_ = (void*) setOverlayIntersectionMask;
        void* triggerLaserMouseHapticVibration_ = (void*) triggerLaserMouseHapticVibration;
        void* setOverlayCursor_ = (void*) setOverlayCursor;
        void* setOverlayCursorPositionOverride_ = (void*) setOverlayCursorPositionOverride;
        void* clearOverlayCursorPositionOverride_ = (void*) clearOverlayCursorPositionOverride;
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
        void* showMessageOverlay_ = (void*) showMessageOverlay;
        void* closeMessageOverlay_ = (void*) closeMessageOverlay;
    };

    class Overlay_027_v
    {
        public:
            virtual OverlayError findOverlay(const char* key, uint64_t* handle) { return Overlay_027::findOverlay(key, handle); }
            virtual OverlayError createOverlay(const char* key, const char* name, uint64_t* handle) { return Overlay_027::createOverlay(key, name, handle); }
            virtual OverlayError destroyOverlay(uint64_t handle) { return Overlay_027::destroyOverlay(handle); }
            virtual uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_027::getOverlayKey(handle, value, bufferSize, error); }
            virtual uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_027::getOverlayName(handle, value, bufferSize, error); }
            virtual OverlayError setOverlayName(uint64_t handle, const char* name) { return Overlay_027::setOverlayName(handle, name); }
            virtual OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height) { return Overlay_027::getOverlayImageData(handle, buffer, bufferSize, width, height); }
            virtual const char* getOverlayErrorNameFromEnum(OverlayError error) { return Overlay_027::getOverlayErrorNameFromEnum(error); }
            virtual OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid) { return Overlay_027::setOverlayRenderingPid(handle, pid); }
            virtual uint32_t getOverlayRenderingPid(uint64_t handle) { return Overlay_027::getOverlayRenderingPid(handle); }
            virtual OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled) { return Overlay_027::setOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled) { return Overlay_027::getOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlags(uint64_t handle, uint32_t* flags) { return Overlay_027::getOverlayFlags(handle, flags); }
            virtual OverlayError setOverlayColor(uint64_t handle, float r, float g, float b) { return Overlay_027::setOverlayColor(handle, r, g, b); }
            virtual OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b) { return Overlay_027::getOverlayColor(handle, r, g, b); }
            virtual OverlayError setOverlayAlpha(uint64_t handle, float alpha) { return Overlay_027::setOverlayAlpha(handle, alpha); }
            virtual OverlayError getOverlayAlpha(uint64_t handle, float* alpha) { return Overlay_027::getOverlayAlpha(handle, alpha); }
            virtual OverlayError setOverlayTexelAspectRatio(uint64_t handle, float aspect) { return Overlay_027::setOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError getOverlayTexelAspectRatio(uint64_t handle, float* aspect) { return Overlay_027::getOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError setOverlaySortOrder(uint64_t handle, uint32_t sortOrder) { return Overlay_027::setOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder) { return Overlay_027::getOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError setOverlayWidthInMeters(uint64_t handle, float width) { return Overlay_027::setOverlayWidthInMeters(handle, width); }
            virtual OverlayError getOverlayWidthInMeters(uint64_t handle, float* width) { return Overlay_027::getOverlayWidthInMeters(handle, width); }
            virtual OverlayError setOverlayCurvature(uint64_t handle, float curvature) { return Overlay_027::setOverlayCurvature(handle, curvature); }
            virtual OverlayError getOverlayCurvature(uint64_t handle, float* curvature) { return Overlay_027::getOverlayCurvature(handle, curvature); }
            virtual OverlayError setOverlayPreCurvePitch(uint64_t handle, float radians) { return Overlay_027::setOverlayPreCurvePitch(handle, radians); }
            virtual OverlayError getOverlayPreCurvePitch(uint64_t handle, float* radians) { return Overlay_027::getOverlayPreCurvePitch(handle, radians); }
            virtual OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace) { return Overlay_027::setOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace) { return Overlay_027::getOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds) { return Overlay_027::setOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_027::getOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType) { return Overlay_027::getOverlayTransformType(handle, transformType); }
            virtual OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_027::setOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix) { return Overlay_027::getOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix) { return Overlay_027::setOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix) { return Overlay_027::getOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName) { return Overlay_027::setOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName); }
            virtual OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize) { return Overlay_027::getOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName, bufferSize); }
            virtual OverlayError setOverlayTransformOverlayCursor(uint64_t handle, const Vector2* hotspot) { return Overlay_027::setOverlayTransformOverlayCursor(handle, hotspot); }
            virtual OverlayError getOverlayTransformOverlayCursor(uint64_t handle, Vector2* hotspot) { return Overlay_027::getOverlayTransformOverlayCursor(handle, hotspot); }
            virtual OverlayError setOverlayTransformProjection(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix, const OverlayProjection* projection, Eye eye) { return Overlay_027::setOverlayTransformProjection(handle, origin, matrix, projection, eye); }
            virtual OverlayError showOverlay(uint64_t handle) { return Overlay_027::showOverlay(handle); }
            virtual OverlayError hideOverlay(uint64_t handle) { return Overlay_027::hideOverlay(handle); }
            virtual bool isOverlayVisible(uint64_t handle) { return Overlay_027::isOverlayVisible(handle); }
            virtual OverlayError getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix) { return Overlay_027::getTransformForOverlayCoordinates(handle, origin, coordinatesInOverlay, matrix); }
            virtual OverlayError waitFrameSync(uint32_t timeout) { return Overlay_027::waitFrameSync(timeout); }
            virtual bool pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t eventSize) { return Overlay_027::pollNextOverlayEvent(handle, event, eventSize); }
            virtual OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod) { return Overlay_027::getOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod) { return Overlay_027::setOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale) { return Overlay_027::getOverlayMouseScale(handle, mouseScale); }
            virtual OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale) { return Overlay_027::setOverlayMouseScale(handle, mouseScale); }
            virtual bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results) { return Overlay_027::computeOverlayIntersection(handle, params, results); }
            virtual bool isHoverTargetOverlay(uint64_t handle) { return Overlay_027::isHoverTargetOverlay(handle); }
            virtual OverlayError setOverlayIntersectionMask(uint64_t handle, OverlayIntersectionMaskPrimitive* primitives, uint32_t primitivesCount, uint32_t primitiveSize) { return Overlay_027::setOverlayIntersectionMask(handle, primitives, primitivesCount, primitiveSize); }
            virtual OverlayError triggerLaserMouseHapticVibration(uint64_t handle, float durationSeconds, float frequency, float amplitude) { return Overlay_027::triggerLaserMouseHapticVibration(handle, durationSeconds, frequency, amplitude); }
            virtual OverlayError setOverlayCursor(uint64_t handle, uint64_t cursorHandle) { return Overlay_027::setOverlayCursor(handle, cursorHandle); }
            virtual OverlayError setOverlayCursorPositionOverride(uint64_t handle, const Vector2* position) { return Overlay_027::setOverlayCursorPositionOverride(handle, position); }
            virtual OverlayError clearOverlayCursorPositionOverride(uint64_t handle) { return Overlay_027::clearOverlayCursorPositionOverride(handle); }
            virtual OverlayError setOverlayTexture(uint64_t handle, const Texture* texture) { return Overlay_027::setOverlayTexture(handle, texture); }
            virtual OverlayError clearOverlayTexture(uint64_t handle) { return Overlay_027::clearOverlayTexture(handle); }
            virtual OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth) { return Overlay_027::setOverlayRaw(handle, buffer, width, height, depth); }
            virtual OverlayError setOverlayFromFile(uint64_t handle, const char* filePath) { return Overlay_027::setOverlayFromFile(handle, filePath); }
            virtual OverlayError getOverlayNativeTexture(uint64_t handle, void** nativeTextureHandle, void* nativeTextureRef, uint32_t* width, uint32_t* height, uint32_t* format, TextureType* type, ColorSpace* colorSpace, TextureBounds* bounds) { return Overlay_027::getOverlayNativeTexture(handle, nativeTextureHandle, nativeTextureRef, width, height, format, type, colorSpace, bounds); }
            virtual OverlayError releaseNativeOverlayTexture(uint64_t handle, void* nativeTextureHandle) { return Overlay_027::releaseNativeOverlayTexture(handle, nativeTextureHandle); }
            virtual OverlayError getOverlayTextureSize(uint64_t handle, uint32_t* width, uint32_t* height) { return Overlay_027::getOverlayTextureSize(handle, width, height); }
            virtual OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle) { return Overlay_027::createDashboardOverlay(key, friendlyName, mainHandle, thumbnailHandle); }
            virtual bool isDashboardVisible() { return Overlay_027::isDashboardVisible(); }
            virtual bool isActiveDashboardOverlay(uint64_t handle) { return Overlay_027::isActiveDashboardOverlay(handle); }
            virtual OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid) { return Overlay_027::setDashboardOverlaySceneProcess(handle, pid); }
            virtual OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid) { return Overlay_027::getDashboardOverlaySceneProcess(handle, pid); }
            virtual void showDashboard(const char* overlayToShow) { return Overlay_027::showDashboard(overlayToShow); }
            virtual uint32_t getPrimaryDashboardInputTrackedDevice() { return Overlay_027::getPrimaryDashboardInputTrackedDevice(); }
            virtual OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, uint32_t flags, const char* description, uint32_t maxChars, const char* existingText, uint64_t userValue) { return Overlay_027::showKeyboard(textInputMode, textInputLineMode, flags, description, maxChars, existingText, userValue); }
            virtual OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, uint32_t flags, const char* description, uint32_t maxChars, const char* existingText, uint64_t userValue) { return Overlay_027::showKeyboardForOverlay(handle, textInputMode, textInputLineMode, flags, description, maxChars, existingText, userValue); }
            virtual uint32_t getKeyboardText(char* text, uint32_t bufferSize) { return Overlay_027::getKeyboardText(text, bufferSize); }
            virtual void hideKeyboard() { return Overlay_027::hideKeyboard(); }
            virtual void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_027::setKeyboardTransformAbsolute(origin, matrix); }
            virtual void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect) { return Overlay_027::setKeyboardPositionForOverlay(handle, avoidRect); }
            virtual MessageOverlayResponse showMessageOverlay(const char* text, const char* caption, const char* button0Text, const char* button1Text, const char* button2Text, const char* button3Text) { return Overlay_027::showMessageOverlay(text, caption, button0Text, button1Text, button2Text, button3Text); }
            virtual void closeMessageOverlay() { return Overlay_027::closeMessageOverlay(); }
    };

    //

    struct Overlay_028
    {
        static OverlayError findOverlay(const char* key, uint64_t* handle);

        static OverlayError createOverlay(const char* key, const char* name, uint64_t* handle);
        static OverlayError createSubviewOverlay(uint64_t parentHandle, const char* key, const char* name, uint64_t* handle);
        static OverlayError destroyOverlay(uint64_t handle);

        static uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error);
        static OverlayError setOverlayName(uint64_t handle, const char* name);
        static OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height);

        static const char* getOverlayErrorNameFromEnum(OverlayError error);

        static OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid);
        static uint32_t getOverlayRenderingPid(uint64_t handle);

        static OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled);
        static OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled);
        static OverlayError getOverlayFlags(uint64_t handle, uint32_t* flags);

        static OverlayError setOverlayColor(uint64_t handle, float r, float g, float b);
        static OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b);
        static OverlayError setOverlayAlpha(uint64_t handle, float alpha);
        static OverlayError getOverlayAlpha(uint64_t handle, float* alpha);

        static OverlayError setOverlayTexelAspectRatio(uint64_t handle, float aspect);
        static OverlayError getOverlayTexelAspectRatio(uint64_t handle, float* aspect);
        static OverlayError setOverlaySortOrder(uint64_t handle, uint32_t sortOrder);
        static OverlayError getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder);
        static OverlayError setOverlayWidthInMeters(uint64_t handle, float width);
        static OverlayError getOverlayWidthInMeters(uint64_t handle, float* width);
        static OverlayError setOverlayCurvature(uint64_t handle, float curvature);
        static OverlayError getOverlayCurvature(uint64_t handle, float* curvature);
        static OverlayError setOverlayPreCurvePitch(uint64_t handle, float radians);
        static OverlayError getOverlayPreCurvePitch(uint64_t handle, float* radians);

        static OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace);
        static OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace);
        static OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds);
        static OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds);

        static OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType);
        static OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix);
        static OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix);
        static OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix);
        static OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName);
        static OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize);
        static OverlayError setOverlayTransformOverlayCursor(uint64_t handle, const Vector2* hotspot);
        static OverlayError getOverlayTransformOverlayCursor(uint64_t handle, Vector2* hotspot);
        static OverlayError setOverlayTransformProjection(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix, const OverlayProjection* projection, Eye eye);
        static OverlayError setSubviewOverlayPosition(uint64_t handle, float x, float y);

        static OverlayError showOverlay(uint64_t handle);
        static OverlayError hideOverlay(uint64_t handle);
        static bool isOverlayVisible(uint64_t handle);

        static OverlayError getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix);

        static OverlayError waitFrameSync(uint32_t timeout);
        static bool pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t eventSize);

        static OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod);
        static OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod);
        static OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale);
        static OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale);

        static bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results);
        static bool isHoverTargetOverlay(uint64_t handle);

        static OverlayError setOverlayIntersectionMask(uint64_t handle, OverlayIntersectionMaskPrimitive* primitives, uint32_t primitivesCount, uint32_t primitiveSize);
        static OverlayError triggerLaserMouseHapticVibration(uint64_t handle, float durationSeconds, float frequency, float amplitude);
        static OverlayError setOverlayCursor(uint64_t handle, uint64_t cursorHandle);
        static OverlayError setOverlayCursorPositionOverride(uint64_t handle, const Vector2* position);
        static OverlayError clearOverlayCursorPositionOverride(uint64_t handle);

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

        static OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, uint32_t flags, const char* description, uint32_t maxChars, const char* existingText, uint64_t userValue);
        static OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, uint32_t flags, const char* description, uint32_t maxChars, const char* existingText, uint64_t userValue);
        static uint32_t getKeyboardText(char* text, uint32_t bufferSize);
        static void hideKeyboard();
        static void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix);
        static void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect);

        static MessageOverlayResponse showMessageOverlay(const char* text, const char* caption, const char* button0Text, const char* button1Text, const char* button2Text, const char* button3Text);
        static void closeMessageOverlay();

        void* findOverlay_ = (void*) findOverlay;
        void* createOverlay_ = (void*) createOverlay;
        void* createSubviewOverlay_ = (void*) createSubviewOverlay;
        void* destroyOverlay_ = (void*) destroyOverlay;
        void* getOverlayKey_ = (void*) getOverlayKey;
        void* getOverlayName_ = (void*) getOverlayName;
        void* setOverlayName_ = (void*) setOverlayName;
        void* getOverlayImageData_ = (void*) getOverlayImageData;
        void* getOverlayErrorNameFromEnum_ = (void*) getOverlayErrorNameFromEnum;
        void* setOverlayRenderingPid_ = (void*) setOverlayRenderingPid;
        void* getOverlayRenderingPid_ = (void*) getOverlayRenderingPid;
        void* setOverlayFlag_ = (void*) setOverlayFlag;
        void* getOverlayFlag_ = (void*) getOverlayFlag;
        void* getOverlayFlags_ = (void*) getOverlayFlags;
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
        void* setOverlayCurvature_ = (void*) setOverlayCurvature;
        void* getOverlayCurvature_ = (void*) getOverlayCurvature;
        void* setOverlayPreCurvePitch_ = (void*) setOverlayPreCurvePitch;
        void* getOverlayPreCurvePitch_ = (void*) getOverlayPreCurvePitch;
        void* setOverlayTextureColorSpace_ = (void*) setOverlayTextureColorSpace;
        void* getOverlayTextureColorSpace_ = (void*) getOverlayTextureColorSpace;
        void* setOverlayTextureBounds_ = (void*) setOverlayTextureBounds;
        void* getOverlayTextureBounds_ = (void*) getOverlayTextureBounds;
        void* getOverlayTransformType_ = (void*) getOverlayTransformType;
        void* setOverlayTransformAbsolute_ = (void*) setOverlayTransformAbsolute;
        void* getOverlayTransformAbsolute_ = (void*) getOverlayTransformAbsolute;
        void* setOverlayTransformTrackedDeviceRelative_ = (void*) setOverlayTransformTrackedDeviceRelative;
        void* getOverlayTransformTrackedDeviceRelative_ = (void*) getOverlayTransformTrackedDeviceRelative;
        void* setOverlayTransformTrackedDeviceComponent_ = (void*) setOverlayTransformTrackedDeviceComponent;
        void* getOverlayTransformTrackedDeviceComponent_ = (void*) getOverlayTransformTrackedDeviceComponent;
        void* setOverlayTransformOverlayCursor_ = (void*) setOverlayTransformOverlayCursor;
        void* getOverlayTransformOverlayCursor_ = (void*) getOverlayTransformOverlayCursor;
        void* setOverlayTransformProjection_ = (void*) setOverlayTransformProjection;
        void* setSubviewOverlayPosition_ = (void*) setSubviewOverlayPosition;
        void* showOverlay_ = (void*) showOverlay;
        void* hideOverlay_ = (void*) hideOverlay;
        void* isOverlayVisible_ = (void*) isOverlayVisible;
        void* getTransformForOverlayCoordinates_ = (void*) getTransformForOverlayCoordinates;
        void* waitFrameSync_ = (void*) waitFrameSync;
        void* pollNextOverlayEvent_ = (void*) pollNextOverlayEvent;
        void* getOverlayInputMethod_ = (void*) getOverlayInputMethod;
        void* setOverlayInputMethod_ = (void*) setOverlayInputMethod;
        void* getOverlayMouseScale_ = (void*) getOverlayMouseScale;
        void* setOverlayMouseScale_ = (void*) setOverlayMouseScale;
        void* computeOverlayIntersection_ = (void*) computeOverlayIntersection;
        void* isHoverTargetOverlay_ = (void*) isHoverTargetOverlay;
        void* setOverlayIntersectionMask_ = (void*) setOverlayIntersectionMask;
        void* triggerLaserMouseHapticVibration_ = (void*) triggerLaserMouseHapticVibration;
        void* setOverlayCursor_ = (void*) setOverlayCursor;
        void* setOverlayCursorPositionOverride_ = (void*) setOverlayCursorPositionOverride;
        void* clearOverlayCursorPositionOverride_ = (void*) clearOverlayCursorPositionOverride;
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
        void* showMessageOverlay_ = (void*) showMessageOverlay;
        void* closeMessageOverlay_ = (void*) closeMessageOverlay;
    };

    class Overlay_028_v
    {
        public:
            virtual OverlayError findOverlay(const char* key, uint64_t* handle) { return Overlay_028::findOverlay(key, handle); }
            virtual OverlayError createOverlay(const char* key, const char* name, uint64_t* handle) { return Overlay_028::createOverlay(key, name, handle); }
            virtual OverlayError createSubviewOverlay(uint64_t parentHandle, const char* key, const char* name, uint64_t* handle) { return Overlay_028::createSubviewOverlay(parentHandle, key, name, handle); }
            virtual OverlayError destroyOverlay(uint64_t handle) { return Overlay_028::destroyOverlay(handle); }
            virtual uint32_t getOverlayKey(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_028::getOverlayKey(handle, value, bufferSize, error); }
            virtual uint32_t getOverlayName(uint64_t handle, char* value, uint32_t bufferSize, OverlayError* error) { return Overlay_028::getOverlayName(handle, value, bufferSize, error); }
            virtual OverlayError setOverlayName(uint64_t handle, const char* name) { return Overlay_028::setOverlayName(handle, name); }
            virtual OverlayError getOverlayImageData(uint64_t handle, void* buffer, uint32_t bufferSize, uint32_t* width, uint32_t* height) { return Overlay_028::getOverlayImageData(handle, buffer, bufferSize, width, height); }
            virtual const char* getOverlayErrorNameFromEnum(OverlayError error) { return Overlay_028::getOverlayErrorNameFromEnum(error); }
            virtual OverlayError setOverlayRenderingPid(uint64_t handle, uint32_t pid) { return Overlay_028::setOverlayRenderingPid(handle, pid); }
            virtual uint32_t getOverlayRenderingPid(uint64_t handle) { return Overlay_028::getOverlayRenderingPid(handle); }
            virtual OverlayError setOverlayFlag(uint64_t handle, OverlayFlags flag, bool enabled) { return Overlay_028::setOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlag(uint64_t handle, OverlayFlags flag, bool* enabled) { return Overlay_028::getOverlayFlag(handle, flag, enabled); }
            virtual OverlayError getOverlayFlags(uint64_t handle, uint32_t* flags) { return Overlay_028::getOverlayFlags(handle, flags); }
            virtual OverlayError setOverlayColor(uint64_t handle, float r, float g, float b) { return Overlay_028::setOverlayColor(handle, r, g, b); }
            virtual OverlayError getOverlayColor(uint64_t handle, float* r, float* g, float* b) { return Overlay_028::getOverlayColor(handle, r, g, b); }
            virtual OverlayError setOverlayAlpha(uint64_t handle, float alpha) { return Overlay_028::setOverlayAlpha(handle, alpha); }
            virtual OverlayError getOverlayAlpha(uint64_t handle, float* alpha) { return Overlay_028::getOverlayAlpha(handle, alpha); }
            virtual OverlayError setOverlayTexelAspectRatio(uint64_t handle, float aspect) { return Overlay_028::setOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError getOverlayTexelAspectRatio(uint64_t handle, float* aspect) { return Overlay_028::getOverlayTexelAspectRatio(handle, aspect); }
            virtual OverlayError setOverlaySortOrder(uint64_t handle, uint32_t sortOrder) { return Overlay_028::setOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError getOverlaySortOrder(uint64_t handle, uint32_t* sortOrder) { return Overlay_028::getOverlaySortOrder(handle, sortOrder); }
            virtual OverlayError setOverlayWidthInMeters(uint64_t handle, float width) { return Overlay_028::setOverlayWidthInMeters(handle, width); }
            virtual OverlayError getOverlayWidthInMeters(uint64_t handle, float* width) { return Overlay_028::getOverlayWidthInMeters(handle, width); }
            virtual OverlayError setOverlayCurvature(uint64_t handle, float curvature) { return Overlay_028::setOverlayCurvature(handle, curvature); }
            virtual OverlayError getOverlayCurvature(uint64_t handle, float* curvature) { return Overlay_028::getOverlayCurvature(handle, curvature); }
            virtual OverlayError setOverlayPreCurvePitch(uint64_t handle, float radians) { return Overlay_028::setOverlayPreCurvePitch(handle, radians); }
            virtual OverlayError getOverlayPreCurvePitch(uint64_t handle, float* radians) { return Overlay_028::getOverlayPreCurvePitch(handle, radians); }
            virtual OverlayError setOverlayTextureColorSpace(uint64_t handle, ColorSpace colorSpace) { return Overlay_028::setOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError getOverlayTextureColorSpace(uint64_t handle, ColorSpace* colorSpace) { return Overlay_028::getOverlayTextureColorSpace(handle, colorSpace); }
            virtual OverlayError setOverlayTextureBounds(uint64_t handle, const TextureBounds* bounds) { return Overlay_028::setOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTextureBounds(uint64_t handle, TextureBounds* bounds) { return Overlay_028::getOverlayTextureBounds(handle, bounds); }
            virtual OverlayError getOverlayTransformType(uint64_t handle, OverlayTransformType* transformType) { return Overlay_028::getOverlayTransformType(handle, transformType); }
            virtual OverlayError setOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_028::setOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError getOverlayTransformAbsolute(uint64_t handle, TrackingUniverseOrigin* origin, Matrix34* matrix) { return Overlay_028::getOverlayTransformAbsolute(handle, origin, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t trackedDeviceIndex, const Matrix34* matrix) { return Overlay_028::setOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError getOverlayTransformTrackedDeviceRelative(uint64_t handle, uint32_t* trackedDeviceIndex, Matrix34* matrix) { return Overlay_028::getOverlayTransformTrackedDeviceRelative(handle, trackedDeviceIndex, matrix); }
            virtual OverlayError setOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t trackedDeviceIndex, const char* componentName) { return Overlay_028::setOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName); }
            virtual OverlayError getOverlayTransformTrackedDeviceComponent(uint64_t handle, uint32_t* trackedDeviceIndex, char* componentName, uint32_t bufferSize) { return Overlay_028::getOverlayTransformTrackedDeviceComponent(handle, trackedDeviceIndex, componentName, bufferSize); }
            virtual OverlayError setOverlayTransformOverlayCursor(uint64_t handle, const Vector2* hotspot) { return Overlay_028::setOverlayTransformOverlayCursor(handle, hotspot); }
            virtual OverlayError getOverlayTransformOverlayCursor(uint64_t handle, Vector2* hotspot) { return Overlay_028::getOverlayTransformOverlayCursor(handle, hotspot); }
            virtual OverlayError setOverlayTransformProjection(uint64_t handle, TrackingUniverseOrigin origin, const Matrix34* matrix, const OverlayProjection* projection, Eye eye) { return Overlay_028::setOverlayTransformProjection(handle, origin, matrix, projection, eye); }
            virtual OverlayError setSubviewOverlayPosition(uint64_t handle, float x, float y) { return Overlay_028::setSubviewOverlayPosition(handle, x, y); }
            virtual OverlayError showOverlay(uint64_t handle) { return Overlay_028::showOverlay(handle); }
            virtual OverlayError hideOverlay(uint64_t handle) { return Overlay_028::hideOverlay(handle); }
            virtual bool isOverlayVisible(uint64_t handle) { return Overlay_028::isOverlayVisible(handle); }
            virtual OverlayError getTransformForOverlayCoordinates(uint64_t handle, TrackingUniverseOrigin origin, Vector2 coordinatesInOverlay, Matrix34* matrix) { return Overlay_028::getTransformForOverlayCoordinates(handle, origin, coordinatesInOverlay, matrix); }
            virtual OverlayError waitFrameSync(uint32_t timeout) { return Overlay_028::waitFrameSync(timeout); }
            virtual bool pollNextOverlayEvent(uint64_t handle, Event_0_9_15* event, uint32_t eventSize) { return Overlay_028::pollNextOverlayEvent(handle, event, eventSize); }
            virtual OverlayError getOverlayInputMethod(uint64_t handle, OverlayInputMethod* inputMethod) { return Overlay_028::getOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError setOverlayInputMethod(uint64_t handle, OverlayInputMethod inputMethod) { return Overlay_028::setOverlayInputMethod(handle, inputMethod); }
            virtual OverlayError getOverlayMouseScale(uint64_t handle, Vector2* mouseScale) { return Overlay_028::getOverlayMouseScale(handle, mouseScale); }
            virtual OverlayError setOverlayMouseScale(uint64_t handle, const Vector2* mouseScale) { return Overlay_028::setOverlayMouseScale(handle, mouseScale); }
            virtual bool computeOverlayIntersection(uint64_t handle, const OverlayIntersectionParams* params, OverlayIntersectionResults* results) { return Overlay_028::computeOverlayIntersection(handle, params, results); }
            virtual bool isHoverTargetOverlay(uint64_t handle) { return Overlay_028::isHoverTargetOverlay(handle); }
            virtual OverlayError setOverlayIntersectionMask(uint64_t handle, OverlayIntersectionMaskPrimitive* primitives, uint32_t primitivesCount, uint32_t primitiveSize) { return Overlay_028::setOverlayIntersectionMask(handle, primitives, primitivesCount, primitiveSize); }
            virtual OverlayError triggerLaserMouseHapticVibration(uint64_t handle, float durationSeconds, float frequency, float amplitude) { return Overlay_028::triggerLaserMouseHapticVibration(handle, durationSeconds, frequency, amplitude); }
            virtual OverlayError setOverlayCursor(uint64_t handle, uint64_t cursorHandle) { return Overlay_028::setOverlayCursor(handle, cursorHandle); }
            virtual OverlayError setOverlayCursorPositionOverride(uint64_t handle, const Vector2* position) { return Overlay_028::setOverlayCursorPositionOverride(handle, position); }
            virtual OverlayError clearOverlayCursorPositionOverride(uint64_t handle) { return Overlay_028::clearOverlayCursorPositionOverride(handle); }
            virtual OverlayError setOverlayTexture(uint64_t handle, const Texture* texture) { return Overlay_028::setOverlayTexture(handle, texture); }
            virtual OverlayError clearOverlayTexture(uint64_t handle) { return Overlay_028::clearOverlayTexture(handle); }
            virtual OverlayError setOverlayRaw(uint64_t handle, void* buffer, uint32_t width, uint32_t height, uint32_t depth) { return Overlay_028::setOverlayRaw(handle, buffer, width, height, depth); }
            virtual OverlayError setOverlayFromFile(uint64_t handle, const char* filePath) { return Overlay_028::setOverlayFromFile(handle, filePath); }
            virtual OverlayError getOverlayNativeTexture(uint64_t handle, void** nativeTextureHandle, void* nativeTextureRef, uint32_t* width, uint32_t* height, uint32_t* format, TextureType* type, ColorSpace* colorSpace, TextureBounds* bounds) { return Overlay_028::getOverlayNativeTexture(handle, nativeTextureHandle, nativeTextureRef, width, height, format, type, colorSpace, bounds); }
            virtual OverlayError releaseNativeOverlayTexture(uint64_t handle, void* nativeTextureHandle) { return Overlay_028::releaseNativeOverlayTexture(handle, nativeTextureHandle); }
            virtual OverlayError getOverlayTextureSize(uint64_t handle, uint32_t* width, uint32_t* height) { return Overlay_028::getOverlayTextureSize(handle, width, height); }
            virtual OverlayError createDashboardOverlay(const char* key, const char* friendlyName, uint64_t* mainHandle, uint64_t* thumbnailHandle) { return Overlay_028::createDashboardOverlay(key, friendlyName, mainHandle, thumbnailHandle); }
            virtual bool isDashboardVisible() { return Overlay_028::isDashboardVisible(); }
            virtual bool isActiveDashboardOverlay(uint64_t handle) { return Overlay_028::isActiveDashboardOverlay(handle); }
            virtual OverlayError setDashboardOverlaySceneProcess(uint64_t handle, uint32_t pid) { return Overlay_028::setDashboardOverlaySceneProcess(handle, pid); }
            virtual OverlayError getDashboardOverlaySceneProcess(uint64_t handle, uint32_t* pid) { return Overlay_028::getDashboardOverlaySceneProcess(handle, pid); }
            virtual void showDashboard(const char* overlayToShow) { return Overlay_028::showDashboard(overlayToShow); }
            virtual uint32_t getPrimaryDashboardInputTrackedDevice() { return Overlay_028::getPrimaryDashboardInputTrackedDevice(); }
            virtual OverlayError showKeyboard(GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, uint32_t flags, const char* description, uint32_t maxChars, const char* existingText, uint64_t userValue) { return Overlay_028::showKeyboard(textInputMode, textInputLineMode, flags, description, maxChars, existingText, userValue); }
            virtual OverlayError showKeyboardForOverlay(uint64_t handle, GamepadTextInputMode textInputMode, GamepadTextInputLineMode textInputLineMode, uint32_t flags, const char* description, uint32_t maxChars, const char* existingText, uint64_t userValue) { return Overlay_028::showKeyboardForOverlay(handle, textInputMode, textInputLineMode, flags, description, maxChars, existingText, userValue); }
            virtual uint32_t getKeyboardText(char* text, uint32_t bufferSize) { return Overlay_028::getKeyboardText(text, bufferSize); }
            virtual void hideKeyboard() { return Overlay_028::hideKeyboard(); }
            virtual void setKeyboardTransformAbsolute(TrackingUniverseOrigin origin, const Matrix34* matrix) { return Overlay_028::setKeyboardTransformAbsolute(origin, matrix); }
            virtual void setKeyboardPositionForOverlay(uint64_t handle, Rect avoidRect) { return Overlay_028::setKeyboardPositionForOverlay(handle, avoidRect); }
            virtual MessageOverlayResponse showMessageOverlay(const char* text, const char* caption, const char* button0Text, const char* button1Text, const char* button2Text, const char* button3Text) { return Overlay_028::showMessageOverlay(text, caption, button0Text, button1Text, button2Text, button3Text); }
            virtual void closeMessageOverlay() { return Overlay_028::closeMessageOverlay(); }
    };
}
