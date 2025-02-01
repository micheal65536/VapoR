#pragma once

#include "../types.h"
#include <cstdint>
#include <vulkan/vulkan.h>

#include "../impl/system.h"

namespace openvr
{
    struct System_003
    {
        static void getWindowBounds(int32_t* x, int32_t* y, uint32_t* width, uint32_t* height);
        static void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height);
        static void getEyeOutputViewport(Eye eye, uint32_t* x, uint32_t* y, uint32_t* width, uint32_t* height);
        static Matrix44 getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention);
        static void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom);
        static DistortionCoordinates computeDistortion(Eye eye, float u, float v);
        static Matrix34 getEyeToHeadTransform(Eye eye);

        static bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter);
        static int32_t getD3D9AdapterIndex();
        static void getDXGIOutputInfo(int32_t* adapterIndex, int32_t* outputIndex);
        static bool AttachToWindow(void* hwnd);

        static void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount);
        static void resetSeatedZeroPose();
        static Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose();

        static bool loadRenderModel(const char* modelName, RenderModel_0_9_0* renderModel);
        static void freeRenderModel(RenderModel_0_9_0* renderModel);

        static TrackedDeviceClass getTrackedDeviceClass(uint32_t index);
        static bool isTrackedDeviceConnected(uint32_t index);
        static bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error);
        static const char* getPropErrorNameFromEnum(TrackedPropertyError error);

        static bool pollNextEvent(Event_0_9_0* event);
        static bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_0* event, TrackedDevicePose* trackedDevicePoseOut);
        static const char* getEventTypeNameFromEnum(EventType type);

        static HiddenAreaMesh getHiddenAreaMesh(Eye eye);

        static bool getControllerState(uint32_t index, ControllerState* state);
        static bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose);
        static void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs);
        static const char* getButtonIdNameFromEnum(ButtonId button);
        static const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType);

        static bool handleControllerOverlayInteractionAsMouse(const OverlaySettings& overlaySettings, Vector2 windowClientPositionOnScreen, Vector2 windowClientSize, uint32_t controllerDeviceIndex, ControllerEventOutputType outputType);

        static bool captureInputFocus();
        static void releaseInputFocus();
        static bool isInputFocusCapturedByAnotherProcess();

        static uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize);

        void* getWindowBounds_ = (void*) getWindowBounds;
        void* getRecommendedRenderTargetSize_ = (void*) getRecommendedRenderTargetSize;
        void* getEyeOutputViewport_ = (void*) getEyeOutputViewport;
        void* getProjectionMatrix_ = (void*) getProjectionMatrix;
        void* getProjectionRaw_ = (void*) getProjectionRaw;
        void* computeDistortion_ = (void*) computeDistortion;
        void* getEyeToHeadTransform_ = (void*) getEyeToHeadTransform;
        void* getTimeSinceLastVsync_ = (void*) getTimeSinceLastVsync;
        void* getD3D9AdapterIndex_ = (void*) getD3D9AdapterIndex;
        void* getDXGIOutputInfo_ = (void*) getDXGIOutputInfo;
        void* AttachToWindow_ = (void*) AttachToWindow;
        void* getDeviceToAbsoluteTrackingPose_ = (void*) getDeviceToAbsoluteTrackingPose;
        void* resetSeatedZeroPose_ = (void*) resetSeatedZeroPose;
        void* getSeatedZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getSeatedZeroPoseToStandingAbsoluteTrackingPose;
        void* loadRenderModel_ = (void*) loadRenderModel;
        void* freeRenderModel_ = (void*) freeRenderModel;
        void* getTrackedDeviceClass_ = (void*) getTrackedDeviceClass;
        void* isTrackedDeviceConnected_ = (void*) isTrackedDeviceConnected;
        void* getBoolTrackedDeviceProperty_ = (void*) getBoolTrackedDeviceProperty;
        void* getFloatTrackedDeviceProperty_ = (void*) getFloatTrackedDeviceProperty;
        void* getInt32TrackedDeviceProperty_ = (void*) getInt32TrackedDeviceProperty;
        void* getUint64TrackedDeviceProperty_ = (void*) getUint64TrackedDeviceProperty;
        void* getMatrix34TrackedDeviceProperty_ = (void*) getMatrix34TrackedDeviceProperty;
        void* getStringTrackedDeviceProperty_ = (void*) getStringTrackedDeviceProperty;
        void* getPropErrorNameFromEnum_ = (void*) getPropErrorNameFromEnum;
        void* pollNextEvent_ = (void*) pollNextEvent;
        void* pollNextEventWithPose_ = (void*) pollNextEventWithPose;
        void* getEventTypeNameFromEnum_ = (void*) getEventTypeNameFromEnum;
        void* getHiddenAreaMesh_ = (void*) getHiddenAreaMesh;
        void* getControllerState_ = (void*) getControllerState;
        void* getControllerStateWithPose_ = (void*) getControllerStateWithPose;
        void* triggerHapticPulse_ = (void*) triggerHapticPulse;
        void* getButtonIdNameFromEnum_ = (void*) getButtonIdNameFromEnum;
        void* getControllerAxisTypeNameFromEnum_ = (void*) getControllerAxisTypeNameFromEnum;
        void* handleControllerOverlayInteractionAsMouse_ = (void*) handleControllerOverlayInteractionAsMouse;
        void* captureInputFocus_ = (void*) captureInputFocus;
        void* releaseInputFocus_ = (void*) releaseInputFocus;
        void* isInputFocusCapturedByAnotherProcess_ = (void*) isInputFocusCapturedByAnotherProcess;
        void* driverDebugRequest_ = (void*) driverDebugRequest;
    };

    class System_003_v
    {
        public:
            virtual void getWindowBounds(int32_t* x, int32_t* y, uint32_t* width, uint32_t* height) { return System_003::getWindowBounds(x, y, width, height); }
            virtual void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height) { return System_003::getRecommendedRenderTargetSize(width, height); }
            virtual void getEyeOutputViewport(Eye eye, uint32_t* x, uint32_t* y, uint32_t* width, uint32_t* height) { return System_003::getEyeOutputViewport(eye, x, y, width, height); }
            virtual Matrix44 getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention) { return System_003::getProjectionMatrix(eye, near, far, convention); }
            virtual void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom) { return System_003::getProjectionRaw(eye, left, right, top, bottom); }
            virtual DistortionCoordinates computeDistortion(Eye eye, float u, float v) { return System_003::computeDistortion(eye, u, v); }
            virtual Matrix34 getEyeToHeadTransform(Eye eye) { return System_003::getEyeToHeadTransform(eye); }
            virtual bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter) { return System_003::getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter); }
            virtual int32_t getD3D9AdapterIndex() { return System_003::getD3D9AdapterIndex(); }
            virtual void getDXGIOutputInfo(int32_t* adapterIndex, int32_t* outputIndex) { return System_003::getDXGIOutputInfo(adapterIndex, outputIndex); }
            virtual bool AttachToWindow(void* hwnd) { return System_003::AttachToWindow(hwnd); }
            virtual void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount) { return System_003::getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount); }
            virtual void resetSeatedZeroPose() { return System_003::resetSeatedZeroPose(); }
            virtual Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose() { return System_003::getSeatedZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual bool loadRenderModel(const char* modelName, RenderModel_0_9_0* renderModel) { return System_003::loadRenderModel(modelName, renderModel); }
            virtual void freeRenderModel(RenderModel_0_9_0* renderModel) { return System_003::freeRenderModel(renderModel); }
            virtual TrackedDeviceClass getTrackedDeviceClass(uint32_t index) { return System_003::getTrackedDeviceClass(index); }
            virtual bool isTrackedDeviceConnected(uint32_t index) { return System_003::isTrackedDeviceConnected(index); }
            virtual bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_003::getBoolTrackedDeviceProperty(index, property, error); }
            virtual float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_003::getFloatTrackedDeviceProperty(index, property, error); }
            virtual int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_003::getInt32TrackedDeviceProperty(index, property, error); }
            virtual uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_003::getUint64TrackedDeviceProperty(index, property, error); }
            virtual Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_003::getMatrix34TrackedDeviceProperty(index, property, error); }
            virtual uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error) { return System_003::getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error); }
            virtual const char* getPropErrorNameFromEnum(TrackedPropertyError error) { return System_003::getPropErrorNameFromEnum(error); }
            virtual bool pollNextEvent(Event_0_9_0* event) { return System_003::pollNextEvent(event); }
            virtual bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_0* event, TrackedDevicePose* trackedDevicePoseOut) { return System_003::pollNextEventWithPose(origin, event, trackedDevicePoseOut); }
            virtual const char* getEventTypeNameFromEnum(EventType type) { return System_003::getEventTypeNameFromEnum(type); }
            virtual HiddenAreaMesh getHiddenAreaMesh(Eye eye) { return System_003::getHiddenAreaMesh(eye); }
            virtual bool getControllerState(uint32_t index, ControllerState* state) { return System_003::getControllerState(index, state); }
            virtual bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose) { return System_003::getControllerStateWithPose(origin, index, state, pose); }
            virtual void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs) { return System_003::triggerHapticPulse(index, axisId, durationUs); }
            virtual const char* getButtonIdNameFromEnum(ButtonId button) { return System_003::getButtonIdNameFromEnum(button); }
            virtual const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType) { return System_003::getControllerAxisTypeNameFromEnum(axisType); }
            virtual bool handleControllerOverlayInteractionAsMouse(const OverlaySettings& overlaySettings, Vector2 windowClientPositionOnScreen, Vector2 windowClientSize, uint32_t controllerDeviceIndex, ControllerEventOutputType outputType) { return System_003::handleControllerOverlayInteractionAsMouse(overlaySettings, windowClientPositionOnScreen, windowClientSize, controllerDeviceIndex, outputType); }
            virtual bool captureInputFocus() { return System_003::captureInputFocus(); }
            virtual void releaseInputFocus() { return System_003::releaseInputFocus(); }
            virtual bool isInputFocusCapturedByAnotherProcess() { return System_003::isInputFocusCapturedByAnotherProcess(); }
            virtual uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize) { return System_003::driverDebugRequest(deviceIndex, request, response, responseBufferSize); }
    };

    //

    struct System_004
    {
        static void getWindowBounds(int32_t* x, int32_t* y, uint32_t* width, uint32_t* height);
        static void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height);
        static void getEyeOutputViewport(Eye eye, uint32_t* x, uint32_t* y, uint32_t* width, uint32_t* height);
        static Matrix44 getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention);
        static void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom);
        static DistortionCoordinates computeDistortion(Eye eye, float u, float v);
        static Matrix34 getEyeToHeadTransform(Eye eye);

        static bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter);
        static int32_t getD3D9AdapterIndex();
        static void getDXGIOutputInfo(int32_t* adapterIndex, int32_t* outputIndex);
        static bool AttachToWindow(void* hwnd);

        static void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount);
        static void resetSeatedZeroPose();
        static Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose();

        static TrackedDeviceClass getTrackedDeviceClass(uint32_t index);
        static bool isTrackedDeviceConnected(uint32_t index);
        static bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error);
        static const char* getPropErrorNameFromEnum(TrackedPropertyError error);

        static bool pollNextEvent(Event_0_9_0* event);
        static bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_0* event, TrackedDevicePose* trackedDevicePoseOut);
        static const char* getEventTypeNameFromEnum(EventType type);

        static HiddenAreaMesh getHiddenAreaMesh(Eye eye);

        static bool getControllerState(uint32_t index, ControllerState* state);
        static bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose);
        static void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs);
        static const char* getButtonIdNameFromEnum(ButtonId button);
        static const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType);

        static bool captureInputFocus();
        static void releaseInputFocus();
        static bool isInputFocusCapturedByAnotherProcess();

        static uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize);

        void* getWindowBounds_ = (void*) getWindowBounds;
        void* getRecommendedRenderTargetSize_ = (void*) getRecommendedRenderTargetSize;
        void* getEyeOutputViewport_ = (void*) getEyeOutputViewport;
        void* getProjectionMatrix_ = (void*) getProjectionMatrix;
        void* getProjectionRaw_ = (void*) getProjectionRaw;
        void* computeDistortion_ = (void*) computeDistortion;
        void* getEyeToHeadTransform_ = (void*) getEyeToHeadTransform;
        void* getTimeSinceLastVsync_ = (void*) getTimeSinceLastVsync;
        void* getD3D9AdapterIndex_ = (void*) getD3D9AdapterIndex;
        void* getDXGIOutputInfo_ = (void*) getDXGIOutputInfo;
        void* AttachToWindow_ = (void*) AttachToWindow;
        void* getDeviceToAbsoluteTrackingPose_ = (void*) getDeviceToAbsoluteTrackingPose;
        void* resetSeatedZeroPose_ = (void*) resetSeatedZeroPose;
        void* getSeatedZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getSeatedZeroPoseToStandingAbsoluteTrackingPose;
        void* getTrackedDeviceClass_ = (void*) getTrackedDeviceClass;
        void* isTrackedDeviceConnected_ = (void*) isTrackedDeviceConnected;
        void* getBoolTrackedDeviceProperty_ = (void*) getBoolTrackedDeviceProperty;
        void* getFloatTrackedDeviceProperty_ = (void*) getFloatTrackedDeviceProperty;
        void* getInt32TrackedDeviceProperty_ = (void*) getInt32TrackedDeviceProperty;
        void* getUint64TrackedDeviceProperty_ = (void*) getUint64TrackedDeviceProperty;
        void* getMatrix34TrackedDeviceProperty_ = (void*) getMatrix34TrackedDeviceProperty;
        void* getStringTrackedDeviceProperty_ = (void*) getStringTrackedDeviceProperty;
        void* getPropErrorNameFromEnum_ = (void*) getPropErrorNameFromEnum;
        void* pollNextEvent_ = (void*) pollNextEvent;
        void* pollNextEventWithPose_ = (void*) pollNextEventWithPose;
        void* getEventTypeNameFromEnum_ = (void*) getEventTypeNameFromEnum;
        void* getHiddenAreaMesh_ = (void*) getHiddenAreaMesh;
        void* getControllerState_ = (void*) getControllerState;
        void* getControllerStateWithPose_ = (void*) getControllerStateWithPose;
        void* triggerHapticPulse_ = (void*) triggerHapticPulse;
        void* getButtonIdNameFromEnum_ = (void*) getButtonIdNameFromEnum;
        void* getControllerAxisTypeNameFromEnum_ = (void*) getControllerAxisTypeNameFromEnum;
        void* captureInputFocus_ = (void*) captureInputFocus;
        void* releaseInputFocus_ = (void*) releaseInputFocus;
        void* isInputFocusCapturedByAnotherProcess_ = (void*) isInputFocusCapturedByAnotherProcess;
        void* driverDebugRequest_ = (void*) driverDebugRequest;
    };

    class System_004_v
    {
        public:
            virtual void getWindowBounds(int32_t* x, int32_t* y, uint32_t* width, uint32_t* height) { return System_004::getWindowBounds(x, y, width, height); }
            virtual void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height) { return System_004::getRecommendedRenderTargetSize(width, height); }
            virtual void getEyeOutputViewport(Eye eye, uint32_t* x, uint32_t* y, uint32_t* width, uint32_t* height) { return System_004::getEyeOutputViewport(eye, x, y, width, height); }
            virtual Matrix44 getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention) { return System_004::getProjectionMatrix(eye, near, far, convention); }
            virtual void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom) { return System_004::getProjectionRaw(eye, left, right, top, bottom); }
            virtual DistortionCoordinates computeDistortion(Eye eye, float u, float v) { return System_004::computeDistortion(eye, u, v); }
            virtual Matrix34 getEyeToHeadTransform(Eye eye) { return System_004::getEyeToHeadTransform(eye); }
            virtual bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter) { return System_004::getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter); }
            virtual int32_t getD3D9AdapterIndex() { return System_004::getD3D9AdapterIndex(); }
            virtual void getDXGIOutputInfo(int32_t* adapterIndex, int32_t* outputIndex) { return System_004::getDXGIOutputInfo(adapterIndex, outputIndex); }
            virtual bool AttachToWindow(void* hwnd) { return System_004::AttachToWindow(hwnd); }
            virtual void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount) { return System_004::getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount); }
            virtual void resetSeatedZeroPose() { return System_004::resetSeatedZeroPose(); }
            virtual Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose() { return System_004::getSeatedZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual TrackedDeviceClass getTrackedDeviceClass(uint32_t index) { return System_004::getTrackedDeviceClass(index); }
            virtual bool isTrackedDeviceConnected(uint32_t index) { return System_004::isTrackedDeviceConnected(index); }
            virtual bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_004::getBoolTrackedDeviceProperty(index, property, error); }
            virtual float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_004::getFloatTrackedDeviceProperty(index, property, error); }
            virtual int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_004::getInt32TrackedDeviceProperty(index, property, error); }
            virtual uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_004::getUint64TrackedDeviceProperty(index, property, error); }
            virtual Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_004::getMatrix34TrackedDeviceProperty(index, property, error); }
            virtual uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error) { return System_004::getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error); }
            virtual const char* getPropErrorNameFromEnum(TrackedPropertyError error) { return System_004::getPropErrorNameFromEnum(error); }
            virtual bool pollNextEvent(Event_0_9_0* event) { return System_004::pollNextEvent(event); }
            virtual bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_0* event, TrackedDevicePose* trackedDevicePoseOut) { return System_004::pollNextEventWithPose(origin, event, trackedDevicePoseOut); }
            virtual const char* getEventTypeNameFromEnum(EventType type) { return System_004::getEventTypeNameFromEnum(type); }
            virtual HiddenAreaMesh getHiddenAreaMesh(Eye eye) { return System_004::getHiddenAreaMesh(eye); }
            virtual bool getControllerState(uint32_t index, ControllerState* state) { return System_004::getControllerState(index, state); }
            virtual bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose) { return System_004::getControllerStateWithPose(origin, index, state, pose); }
            virtual void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs) { return System_004::triggerHapticPulse(index, axisId, durationUs); }
            virtual const char* getButtonIdNameFromEnum(ButtonId button) { return System_004::getButtonIdNameFromEnum(button); }
            virtual const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType) { return System_004::getControllerAxisTypeNameFromEnum(axisType); }
            virtual bool captureInputFocus() { return System_004::captureInputFocus(); }
            virtual void releaseInputFocus() { return System_004::releaseInputFocus(); }
            virtual bool isInputFocusCapturedByAnotherProcess() { return System_004::isInputFocusCapturedByAnotherProcess(); }
            virtual uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize) { return System_004::driverDebugRequest(deviceIndex, request, response, responseBufferSize); }
    };

    //

    struct System_005
    {
        static void getWindowBounds(int32_t* x, int32_t* y, uint32_t* width, uint32_t* height);
        static void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height);
        static void getEyeOutputViewport(Eye eye, uint32_t* x, uint32_t* y, uint32_t* width, uint32_t* height);
        static Matrix44 getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention);
        static void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom);
        static DistortionCoordinates computeDistortion(Eye eye, float u, float v);
        static Matrix34 getEyeToHeadTransform(Eye eye);

        static bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter);
        static int32_t getD3D9AdapterIndex();
        static void getDXGIOutputInfo(int32_t* adapterIndex, int32_t* outputIndex);
        static bool AttachToWindow(void* hwnd);

        static void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount);
        static void resetSeatedZeroPose();
        static Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose();

        static uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex);

        static TrackedDeviceClass getTrackedDeviceClass(uint32_t index);
        static bool isTrackedDeviceConnected(uint32_t index);
        static bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error);
        static const char* getPropErrorNameFromEnum(TrackedPropertyError error);

        static bool pollNextEvent(Event_0_9_0* event);
        static bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_0* event, TrackedDevicePose* trackedDevicePoseOut);
        static const char* getEventTypeNameFromEnum(EventType type);

        static HiddenAreaMesh getHiddenAreaMesh(Eye eye);

        static bool getControllerState(uint32_t index, ControllerState* state);
        static bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose);
        static void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs);
        static const char* getButtonIdNameFromEnum(ButtonId button);
        static const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType);

        static bool captureInputFocus();
        static void releaseInputFocus();
        static bool isInputFocusCapturedByAnotherProcess();

        static uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize);

        void* getWindowBounds_ = (void*) getWindowBounds;
        void* getRecommendedRenderTargetSize_ = (void*) getRecommendedRenderTargetSize;
        void* getEyeOutputViewport_ = (void*) getEyeOutputViewport;
        void* getProjectionMatrix_ = (void*) getProjectionMatrix;
        void* getProjectionRaw_ = (void*) getProjectionRaw;
        void* computeDistortion_ = (void*) computeDistortion;
        void* getEyeToHeadTransform_ = (void*) getEyeToHeadTransform;
        void* getTimeSinceLastVsync_ = (void*) getTimeSinceLastVsync;
        void* getD3D9AdapterIndex_ = (void*) getD3D9AdapterIndex;
        void* getDXGIOutputInfo_ = (void*) getDXGIOutputInfo;
        void* AttachToWindow_ = (void*) AttachToWindow;
        void* getDeviceToAbsoluteTrackingPose_ = (void*) getDeviceToAbsoluteTrackingPose;
        void* resetSeatedZeroPose_ = (void*) resetSeatedZeroPose;
        void* getSeatedZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getSeatedZeroPoseToStandingAbsoluteTrackingPose;
        void* getSortedTrackedDeviceIndicesOfClass_ = (void*) getSortedTrackedDeviceIndicesOfClass;
        void* getTrackedDeviceClass_ = (void*) getTrackedDeviceClass;
        void* isTrackedDeviceConnected_ = (void*) isTrackedDeviceConnected;
        void* getBoolTrackedDeviceProperty_ = (void*) getBoolTrackedDeviceProperty;
        void* getFloatTrackedDeviceProperty_ = (void*) getFloatTrackedDeviceProperty;
        void* getInt32TrackedDeviceProperty_ = (void*) getInt32TrackedDeviceProperty;
        void* getUint64TrackedDeviceProperty_ = (void*) getUint64TrackedDeviceProperty;
        void* getMatrix34TrackedDeviceProperty_ = (void*) getMatrix34TrackedDeviceProperty;
        void* getStringTrackedDeviceProperty_ = (void*) getStringTrackedDeviceProperty;
        void* getPropErrorNameFromEnum_ = (void*) getPropErrorNameFromEnum;
        void* pollNextEvent_ = (void*) pollNextEvent;
        void* pollNextEventWithPose_ = (void*) pollNextEventWithPose;
        void* getEventTypeNameFromEnum_ = (void*) getEventTypeNameFromEnum;
        void* getHiddenAreaMesh_ = (void*) getHiddenAreaMesh;
        void* getControllerState_ = (void*) getControllerState;
        void* getControllerStateWithPose_ = (void*) getControllerStateWithPose;
        void* triggerHapticPulse_ = (void*) triggerHapticPulse;
        void* getButtonIdNameFromEnum_ = (void*) getButtonIdNameFromEnum;
        void* getControllerAxisTypeNameFromEnum_ = (void*) getControllerAxisTypeNameFromEnum;
        void* captureInputFocus_ = (void*) captureInputFocus;
        void* releaseInputFocus_ = (void*) releaseInputFocus;
        void* isInputFocusCapturedByAnotherProcess_ = (void*) isInputFocusCapturedByAnotherProcess;
        void* driverDebugRequest_ = (void*) driverDebugRequest;
    };

    class System_005_v
    {
        public:
            virtual void getWindowBounds(int32_t* x, int32_t* y, uint32_t* width, uint32_t* height) { return System_005::getWindowBounds(x, y, width, height); }
            virtual void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height) { return System_005::getRecommendedRenderTargetSize(width, height); }
            virtual void getEyeOutputViewport(Eye eye, uint32_t* x, uint32_t* y, uint32_t* width, uint32_t* height) { return System_005::getEyeOutputViewport(eye, x, y, width, height); }
            virtual Matrix44 getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention) { return System_005::getProjectionMatrix(eye, near, far, convention); }
            virtual void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom) { return System_005::getProjectionRaw(eye, left, right, top, bottom); }
            virtual DistortionCoordinates computeDistortion(Eye eye, float u, float v) { return System_005::computeDistortion(eye, u, v); }
            virtual Matrix34 getEyeToHeadTransform(Eye eye) { return System_005::getEyeToHeadTransform(eye); }
            virtual bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter) { return System_005::getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter); }
            virtual int32_t getD3D9AdapterIndex() { return System_005::getD3D9AdapterIndex(); }
            virtual void getDXGIOutputInfo(int32_t* adapterIndex, int32_t* outputIndex) { return System_005::getDXGIOutputInfo(adapterIndex, outputIndex); }
            virtual bool AttachToWindow(void* hwnd) { return System_005::AttachToWindow(hwnd); }
            virtual void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount) { return System_005::getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount); }
            virtual void resetSeatedZeroPose() { return System_005::resetSeatedZeroPose(); }
            virtual Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose() { return System_005::getSeatedZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex) { return System_005::getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex); }
            virtual TrackedDeviceClass getTrackedDeviceClass(uint32_t index) { return System_005::getTrackedDeviceClass(index); }
            virtual bool isTrackedDeviceConnected(uint32_t index) { return System_005::isTrackedDeviceConnected(index); }
            virtual bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_005::getBoolTrackedDeviceProperty(index, property, error); }
            virtual float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_005::getFloatTrackedDeviceProperty(index, property, error); }
            virtual int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_005::getInt32TrackedDeviceProperty(index, property, error); }
            virtual uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_005::getUint64TrackedDeviceProperty(index, property, error); }
            virtual Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_005::getMatrix34TrackedDeviceProperty(index, property, error); }
            virtual uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error) { return System_005::getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error); }
            virtual const char* getPropErrorNameFromEnum(TrackedPropertyError error) { return System_005::getPropErrorNameFromEnum(error); }
            virtual bool pollNextEvent(Event_0_9_0* event) { return System_005::pollNextEvent(event); }
            virtual bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_0* event, TrackedDevicePose* trackedDevicePoseOut) { return System_005::pollNextEventWithPose(origin, event, trackedDevicePoseOut); }
            virtual const char* getEventTypeNameFromEnum(EventType type) { return System_005::getEventTypeNameFromEnum(type); }
            virtual HiddenAreaMesh getHiddenAreaMesh(Eye eye) { return System_005::getHiddenAreaMesh(eye); }
            virtual bool getControllerState(uint32_t index, ControllerState* state) { return System_005::getControllerState(index, state); }
            virtual bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose) { return System_005::getControllerStateWithPose(origin, index, state, pose); }
            virtual void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs) { return System_005::triggerHapticPulse(index, axisId, durationUs); }
            virtual const char* getButtonIdNameFromEnum(ButtonId button) { return System_005::getButtonIdNameFromEnum(button); }
            virtual const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType) { return System_005::getControllerAxisTypeNameFromEnum(axisType); }
            virtual bool captureInputFocus() { return System_005::captureInputFocus(); }
            virtual void releaseInputFocus() { return System_005::releaseInputFocus(); }
            virtual bool isInputFocusCapturedByAnotherProcess() { return System_005::isInputFocusCapturedByAnotherProcess(); }
            virtual uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize) { return System_005::driverDebugRequest(deviceIndex, request, response, responseBufferSize); }
    };

    //

    struct System_006
    {
        static void getWindowBounds(int32_t* x, int32_t* y, uint32_t* width, uint32_t* height);
        static void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height);
        static void getEyeOutputViewport(Eye eye, uint32_t* x, uint32_t* y, uint32_t* width, uint32_t* height);
        static Matrix44 getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention);
        static void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom);
        static DistortionCoordinates computeDistortion(Eye eye, float u, float v);
        static Matrix34 getEyeToHeadTransform(Eye eye);

        static bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter);
        static int32_t getD3D9AdapterIndex();
        static void getDXGIOutputInfo(int32_t* adapterIndex, int32_t* outputIndex);
        static bool AttachToWindow(void* hwnd);

        static void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount);
        static void resetSeatedZeroPose();
        static Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose();
        static Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose();

        static uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex);

        static DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index);

        static TrackedDeviceClass getTrackedDeviceClass(uint32_t index);
        static bool isTrackedDeviceConnected(uint32_t index);
        static bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error);
        static const char* getPropErrorNameFromEnum(TrackedPropertyError error);

        static bool pollNextEvent(Event_0_9_0* event);
        static bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_0* event, TrackedDevicePose* trackedDevicePoseOut);
        static const char* getEventTypeNameFromEnum(EventType type);

        static HiddenAreaMesh getHiddenAreaMesh(Eye eye);

        static bool getControllerState(uint32_t index, ControllerState* state);
        static bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose);
        static void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs);
        static const char* getButtonIdNameFromEnum(ButtonId button);
        static const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType);

        static bool captureInputFocus();
        static void releaseInputFocus();
        static bool isInputFocusCapturedByAnotherProcess();

        static uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize);
        static FirmwareError performFirmwareUpdate(uint32_t deviceIndex);

        static bool isDisplayOnDesktop();
        static bool setDisplayVisibility(bool visibleOnDesktop);

        void* getWindowBounds_ = (void*) getWindowBounds;
        void* getRecommendedRenderTargetSize_ = (void*) getRecommendedRenderTargetSize;
        void* getEyeOutputViewport_ = (void*) getEyeOutputViewport;
        void* getProjectionMatrix_ = (void*) getProjectionMatrix;
        void* getProjectionRaw_ = (void*) getProjectionRaw;
        void* computeDistortion_ = (void*) computeDistortion;
        void* getEyeToHeadTransform_ = (void*) getEyeToHeadTransform;
        void* getTimeSinceLastVsync_ = (void*) getTimeSinceLastVsync;
        void* getD3D9AdapterIndex_ = (void*) getD3D9AdapterIndex;
        void* getDXGIOutputInfo_ = (void*) getDXGIOutputInfo;
        void* AttachToWindow_ = (void*) AttachToWindow;
        void* getDeviceToAbsoluteTrackingPose_ = (void*) getDeviceToAbsoluteTrackingPose;
        void* resetSeatedZeroPose_ = (void*) resetSeatedZeroPose;
        void* getSeatedZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getSeatedZeroPoseToStandingAbsoluteTrackingPose;
        void* getRawZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getRawZeroPoseToStandingAbsoluteTrackingPose;
        void* getSortedTrackedDeviceIndicesOfClass_ = (void*) getSortedTrackedDeviceIndicesOfClass;
        void* getTrackedDeviceActivityLevel_ = (void*) getTrackedDeviceActivityLevel;
        void* getTrackedDeviceClass_ = (void*) getTrackedDeviceClass;
        void* isTrackedDeviceConnected_ = (void*) isTrackedDeviceConnected;
        void* getBoolTrackedDeviceProperty_ = (void*) getBoolTrackedDeviceProperty;
        void* getFloatTrackedDeviceProperty_ = (void*) getFloatTrackedDeviceProperty;
        void* getInt32TrackedDeviceProperty_ = (void*) getInt32TrackedDeviceProperty;
        void* getUint64TrackedDeviceProperty_ = (void*) getUint64TrackedDeviceProperty;
        void* getMatrix34TrackedDeviceProperty_ = (void*) getMatrix34TrackedDeviceProperty;
        void* getStringTrackedDeviceProperty_ = (void*) getStringTrackedDeviceProperty;
        void* getPropErrorNameFromEnum_ = (void*) getPropErrorNameFromEnum;
        void* pollNextEvent_ = (void*) pollNextEvent;
        void* pollNextEventWithPose_ = (void*) pollNextEventWithPose;
        void* getEventTypeNameFromEnum_ = (void*) getEventTypeNameFromEnum;
        void* getHiddenAreaMesh_ = (void*) getHiddenAreaMesh;
        void* getControllerState_ = (void*) getControllerState;
        void* getControllerStateWithPose_ = (void*) getControllerStateWithPose;
        void* triggerHapticPulse_ = (void*) triggerHapticPulse;
        void* getButtonIdNameFromEnum_ = (void*) getButtonIdNameFromEnum;
        void* getControllerAxisTypeNameFromEnum_ = (void*) getControllerAxisTypeNameFromEnum;
        void* captureInputFocus_ = (void*) captureInputFocus;
        void* releaseInputFocus_ = (void*) releaseInputFocus;
        void* isInputFocusCapturedByAnotherProcess_ = (void*) isInputFocusCapturedByAnotherProcess;
        void* driverDebugRequest_ = (void*) driverDebugRequest;
        void* performFirmwareUpdate_ = (void*) performFirmwareUpdate;
        void* isDisplayOnDesktop_ = (void*) isDisplayOnDesktop;
        void* setDisplayVisibility_ = (void*) setDisplayVisibility;
    };

    class System_006_v
    {
        public:
            virtual void getWindowBounds(int32_t* x, int32_t* y, uint32_t* width, uint32_t* height) { return System_006::getWindowBounds(x, y, width, height); }
            virtual void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height) { return System_006::getRecommendedRenderTargetSize(width, height); }
            virtual void getEyeOutputViewport(Eye eye, uint32_t* x, uint32_t* y, uint32_t* width, uint32_t* height) { return System_006::getEyeOutputViewport(eye, x, y, width, height); }
            virtual Matrix44 getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention) { return System_006::getProjectionMatrix(eye, near, far, convention); }
            virtual void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom) { return System_006::getProjectionRaw(eye, left, right, top, bottom); }
            virtual DistortionCoordinates computeDistortion(Eye eye, float u, float v) { return System_006::computeDistortion(eye, u, v); }
            virtual Matrix34 getEyeToHeadTransform(Eye eye) { return System_006::getEyeToHeadTransform(eye); }
            virtual bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter) { return System_006::getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter); }
            virtual int32_t getD3D9AdapterIndex() { return System_006::getD3D9AdapterIndex(); }
            virtual void getDXGIOutputInfo(int32_t* adapterIndex, int32_t* outputIndex) { return System_006::getDXGIOutputInfo(adapterIndex, outputIndex); }
            virtual bool AttachToWindow(void* hwnd) { return System_006::AttachToWindow(hwnd); }
            virtual void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount) { return System_006::getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount); }
            virtual void resetSeatedZeroPose() { return System_006::resetSeatedZeroPose(); }
            virtual Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose() { return System_006::getSeatedZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose() { return System_006::getRawZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex) { return System_006::getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex); }
            virtual DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index) { return System_006::getTrackedDeviceActivityLevel(index); }
            virtual TrackedDeviceClass getTrackedDeviceClass(uint32_t index) { return System_006::getTrackedDeviceClass(index); }
            virtual bool isTrackedDeviceConnected(uint32_t index) { return System_006::isTrackedDeviceConnected(index); }
            virtual bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_006::getBoolTrackedDeviceProperty(index, property, error); }
            virtual float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_006::getFloatTrackedDeviceProperty(index, property, error); }
            virtual int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_006::getInt32TrackedDeviceProperty(index, property, error); }
            virtual uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_006::getUint64TrackedDeviceProperty(index, property, error); }
            virtual Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_006::getMatrix34TrackedDeviceProperty(index, property, error); }
            virtual uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error) { return System_006::getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error); }
            virtual const char* getPropErrorNameFromEnum(TrackedPropertyError error) { return System_006::getPropErrorNameFromEnum(error); }
            virtual bool pollNextEvent(Event_0_9_0* event) { return System_006::pollNextEvent(event); }
            virtual bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_0* event, TrackedDevicePose* trackedDevicePoseOut) { return System_006::pollNextEventWithPose(origin, event, trackedDevicePoseOut); }
            virtual const char* getEventTypeNameFromEnum(EventType type) { return System_006::getEventTypeNameFromEnum(type); }
            virtual HiddenAreaMesh getHiddenAreaMesh(Eye eye) { return System_006::getHiddenAreaMesh(eye); }
            virtual bool getControllerState(uint32_t index, ControllerState* state) { return System_006::getControllerState(index, state); }
            virtual bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose) { return System_006::getControllerStateWithPose(origin, index, state, pose); }
            virtual void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs) { return System_006::triggerHapticPulse(index, axisId, durationUs); }
            virtual const char* getButtonIdNameFromEnum(ButtonId button) { return System_006::getButtonIdNameFromEnum(button); }
            virtual const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType) { return System_006::getControllerAxisTypeNameFromEnum(axisType); }
            virtual bool captureInputFocus() { return System_006::captureInputFocus(); }
            virtual void releaseInputFocus() { return System_006::releaseInputFocus(); }
            virtual bool isInputFocusCapturedByAnotherProcess() { return System_006::isInputFocusCapturedByAnotherProcess(); }
            virtual uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize) { return System_006::driverDebugRequest(deviceIndex, request, response, responseBufferSize); }
            virtual FirmwareError performFirmwareUpdate(uint32_t deviceIndex) { return System_006::performFirmwareUpdate(deviceIndex); }
            virtual bool isDisplayOnDesktop() { return System_006::isDisplayOnDesktop(); }
            virtual bool setDisplayVisibility(bool visibleOnDesktop) { return System_006::setDisplayVisibility(visibleOnDesktop); }
    };

    //

    struct System_007
    {
        static void getWindowBounds(int32_t* x, int32_t* y, uint32_t* width, uint32_t* height);
        static void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height);
        static void getEyeOutputViewport(Eye eye, uint32_t* x, uint32_t* y, uint32_t* width, uint32_t* height);
        static Matrix44 getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention);
        static void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom);
        static DistortionCoordinates computeDistortion(Eye eye, float u, float v);
        static Matrix34 getEyeToHeadTransform(Eye eye);

        static bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter);
        static int32_t getD3D9AdapterIndex();
        static void getDXGIOutputInfo(int32_t* adapterIndex, int32_t* outputIndex);
        static bool AttachToWindow(void* hwnd);

        static void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount);
        static void resetSeatedZeroPose();
        static Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose();
        static Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose();

        static uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex);

        static DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index);

        static void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose& trackedDevicePose, const Matrix34& transform);

        static TrackedDeviceClass getTrackedDeviceClass(uint32_t index);
        static bool isTrackedDeviceConnected(uint32_t index);
        static bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error);
        static const char* getPropErrorNameFromEnum(TrackedPropertyError error);

        static bool pollNextEvent(Event_0_9_0* event);
        static bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_0* event, TrackedDevicePose* trackedDevicePoseOut);
        static const char* getEventTypeNameFromEnum(EventType type);

        static HiddenAreaMesh getHiddenAreaMesh(Eye eye);

        static bool getControllerState(uint32_t index, ControllerState* state);
        static bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose);
        static void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs);
        static const char* getButtonIdNameFromEnum(ButtonId button);
        static const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType);

        static bool captureInputFocus();
        static void releaseInputFocus();
        static bool isInputFocusCapturedByAnotherProcess();

        static uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize);
        static FirmwareError performFirmwareUpdate(uint32_t deviceIndex);

        static bool isDisplayOnDesktop();
        static bool setDisplayVisibility(bool visibleOnDesktop);

        void* getWindowBounds_ = (void*) getWindowBounds;
        void* getRecommendedRenderTargetSize_ = (void*) getRecommendedRenderTargetSize;
        void* getEyeOutputViewport_ = (void*) getEyeOutputViewport;
        void* getProjectionMatrix_ = (void*) getProjectionMatrix;
        void* getProjectionRaw_ = (void*) getProjectionRaw;
        void* computeDistortion_ = (void*) computeDistortion;
        void* getEyeToHeadTransform_ = (void*) getEyeToHeadTransform;
        void* getTimeSinceLastVsync_ = (void*) getTimeSinceLastVsync;
        void* getD3D9AdapterIndex_ = (void*) getD3D9AdapterIndex;
        void* getDXGIOutputInfo_ = (void*) getDXGIOutputInfo;
        void* AttachToWindow_ = (void*) AttachToWindow;
        void* getDeviceToAbsoluteTrackingPose_ = (void*) getDeviceToAbsoluteTrackingPose;
        void* resetSeatedZeroPose_ = (void*) resetSeatedZeroPose;
        void* getSeatedZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getSeatedZeroPoseToStandingAbsoluteTrackingPose;
        void* getRawZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getRawZeroPoseToStandingAbsoluteTrackingPose;
        void* getSortedTrackedDeviceIndicesOfClass_ = (void*) getSortedTrackedDeviceIndicesOfClass;
        void* getTrackedDeviceActivityLevel_ = (void*) getTrackedDeviceActivityLevel;
        void* applyTransform_ = (void*) applyTransform;
        void* getTrackedDeviceClass_ = (void*) getTrackedDeviceClass;
        void* isTrackedDeviceConnected_ = (void*) isTrackedDeviceConnected;
        void* getBoolTrackedDeviceProperty_ = (void*) getBoolTrackedDeviceProperty;
        void* getFloatTrackedDeviceProperty_ = (void*) getFloatTrackedDeviceProperty;
        void* getInt32TrackedDeviceProperty_ = (void*) getInt32TrackedDeviceProperty;
        void* getUint64TrackedDeviceProperty_ = (void*) getUint64TrackedDeviceProperty;
        void* getMatrix34TrackedDeviceProperty_ = (void*) getMatrix34TrackedDeviceProperty;
        void* getStringTrackedDeviceProperty_ = (void*) getStringTrackedDeviceProperty;
        void* getPropErrorNameFromEnum_ = (void*) getPropErrorNameFromEnum;
        void* pollNextEvent_ = (void*) pollNextEvent;
        void* pollNextEventWithPose_ = (void*) pollNextEventWithPose;
        void* getEventTypeNameFromEnum_ = (void*) getEventTypeNameFromEnum;
        void* getHiddenAreaMesh_ = (void*) getHiddenAreaMesh;
        void* getControllerState_ = (void*) getControllerState;
        void* getControllerStateWithPose_ = (void*) getControllerStateWithPose;
        void* triggerHapticPulse_ = (void*) triggerHapticPulse;
        void* getButtonIdNameFromEnum_ = (void*) getButtonIdNameFromEnum;
        void* getControllerAxisTypeNameFromEnum_ = (void*) getControllerAxisTypeNameFromEnum;
        void* captureInputFocus_ = (void*) captureInputFocus;
        void* releaseInputFocus_ = (void*) releaseInputFocus;
        void* isInputFocusCapturedByAnotherProcess_ = (void*) isInputFocusCapturedByAnotherProcess;
        void* driverDebugRequest_ = (void*) driverDebugRequest;
        void* performFirmwareUpdate_ = (void*) performFirmwareUpdate;
        void* isDisplayOnDesktop_ = (void*) isDisplayOnDesktop;
        void* setDisplayVisibility_ = (void*) setDisplayVisibility;
    };

    class System_007_v
    {
        public:
            virtual void getWindowBounds(int32_t* x, int32_t* y, uint32_t* width, uint32_t* height) { return System_007::getWindowBounds(x, y, width, height); }
            virtual void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height) { return System_007::getRecommendedRenderTargetSize(width, height); }
            virtual void getEyeOutputViewport(Eye eye, uint32_t* x, uint32_t* y, uint32_t* width, uint32_t* height) { return System_007::getEyeOutputViewport(eye, x, y, width, height); }
            virtual Matrix44 getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention) { return System_007::getProjectionMatrix(eye, near, far, convention); }
            virtual void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom) { return System_007::getProjectionRaw(eye, left, right, top, bottom); }
            virtual DistortionCoordinates computeDistortion(Eye eye, float u, float v) { return System_007::computeDistortion(eye, u, v); }
            virtual Matrix34 getEyeToHeadTransform(Eye eye) { return System_007::getEyeToHeadTransform(eye); }
            virtual bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter) { return System_007::getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter); }
            virtual int32_t getD3D9AdapterIndex() { return System_007::getD3D9AdapterIndex(); }
            virtual void getDXGIOutputInfo(int32_t* adapterIndex, int32_t* outputIndex) { return System_007::getDXGIOutputInfo(adapterIndex, outputIndex); }
            virtual bool AttachToWindow(void* hwnd) { return System_007::AttachToWindow(hwnd); }
            virtual void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount) { return System_007::getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount); }
            virtual void resetSeatedZeroPose() { return System_007::resetSeatedZeroPose(); }
            virtual Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose() { return System_007::getSeatedZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose() { return System_007::getRawZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex) { return System_007::getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex); }
            virtual DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index) { return System_007::getTrackedDeviceActivityLevel(index); }
            virtual void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose& trackedDevicePose, const Matrix34& transform) { return System_007::applyTransform(outputPose, trackedDevicePose, transform); }
            virtual TrackedDeviceClass getTrackedDeviceClass(uint32_t index) { return System_007::getTrackedDeviceClass(index); }
            virtual bool isTrackedDeviceConnected(uint32_t index) { return System_007::isTrackedDeviceConnected(index); }
            virtual bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_007::getBoolTrackedDeviceProperty(index, property, error); }
            virtual float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_007::getFloatTrackedDeviceProperty(index, property, error); }
            virtual int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_007::getInt32TrackedDeviceProperty(index, property, error); }
            virtual uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_007::getUint64TrackedDeviceProperty(index, property, error); }
            virtual Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_007::getMatrix34TrackedDeviceProperty(index, property, error); }
            virtual uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error) { return System_007::getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error); }
            virtual const char* getPropErrorNameFromEnum(TrackedPropertyError error) { return System_007::getPropErrorNameFromEnum(error); }
            virtual bool pollNextEvent(Event_0_9_0* event) { return System_007::pollNextEvent(event); }
            virtual bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_0* event, TrackedDevicePose* trackedDevicePoseOut) { return System_007::pollNextEventWithPose(origin, event, trackedDevicePoseOut); }
            virtual const char* getEventTypeNameFromEnum(EventType type) { return System_007::getEventTypeNameFromEnum(type); }
            virtual HiddenAreaMesh getHiddenAreaMesh(Eye eye) { return System_007::getHiddenAreaMesh(eye); }
            virtual bool getControllerState(uint32_t index, ControllerState* state) { return System_007::getControllerState(index, state); }
            virtual bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose) { return System_007::getControllerStateWithPose(origin, index, state, pose); }
            virtual void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs) { return System_007::triggerHapticPulse(index, axisId, durationUs); }
            virtual const char* getButtonIdNameFromEnum(ButtonId button) { return System_007::getButtonIdNameFromEnum(button); }
            virtual const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType) { return System_007::getControllerAxisTypeNameFromEnum(axisType); }
            virtual bool captureInputFocus() { return System_007::captureInputFocus(); }
            virtual void releaseInputFocus() { return System_007::releaseInputFocus(); }
            virtual bool isInputFocusCapturedByAnotherProcess() { return System_007::isInputFocusCapturedByAnotherProcess(); }
            virtual uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize) { return System_007::driverDebugRequest(deviceIndex, request, response, responseBufferSize); }
            virtual FirmwareError performFirmwareUpdate(uint32_t deviceIndex) { return System_007::performFirmwareUpdate(deviceIndex); }
            virtual bool isDisplayOnDesktop() { return System_007::isDisplayOnDesktop(); }
            virtual bool setDisplayVisibility(bool visibleOnDesktop) { return System_007::setDisplayVisibility(visibleOnDesktop); }
    };

    //

    struct System_009
    {
        static void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height);
        static Matrix44 getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention);
        static void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom);
        static DistortionCoordinates computeDistortion(Eye eye, float u, float v);
        static Matrix34 getEyeToHeadTransform(Eye eye);

        static bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter);
        static int32_t getD3D9AdapterIndex();
        static void getDXGIOutputInfo(int32_t* adapterIndex);

        static bool isDisplayOnDesktop();
        static bool setDisplayVisibility(bool visibleOnDesktop);

        static void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount);
        static void resetSeatedZeroPose();
        static Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose();
        static Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose();

        static uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex);

        static DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index);

        static void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform);

        static TrackedDeviceClass getTrackedDeviceClass(uint32_t index);
        static bool isTrackedDeviceConnected(uint32_t index);
        static bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error);
        static const char* getPropErrorNameFromEnum(TrackedPropertyError error);

        static bool pollNextEvent(Event_0_9_0* event);
        static bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_0* event, TrackedDevicePose* trackedDevicePoseOut);
        static const char* getEventTypeNameFromEnum(EventType type);

        static HiddenAreaMesh getHiddenAreaMesh(Eye eye);

        static bool getControllerState(uint32_t index, ControllerState* state);
        static bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose);
        static void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs);
        static const char* getButtonIdNameFromEnum(ButtonId button);
        static const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType);

        static bool captureInputFocus();
        static void releaseInputFocus();
        static bool isInputFocusCapturedByAnotherProcess();

        static uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize);
        static FirmwareError performFirmwareUpdate(uint32_t deviceIndex);

        static void acknowledgeQuit();
        static void acknowledgeQuitPrompt();

        void* getRecommendedRenderTargetSize_ = (void*) getRecommendedRenderTargetSize;
        void* getProjectionMatrix_ = (void*) getProjectionMatrix;
        void* getProjectionRaw_ = (void*) getProjectionRaw;
        void* computeDistortion_ = (void*) computeDistortion;
        void* getEyeToHeadTransform_ = (void*) getEyeToHeadTransform;
        void* getTimeSinceLastVsync_ = (void*) getTimeSinceLastVsync;
        void* getD3D9AdapterIndex_ = (void*) getD3D9AdapterIndex;
        void* getDXGIOutputInfo_ = (void*) getDXGIOutputInfo;
        void* isDisplayOnDesktop_ = (void*) isDisplayOnDesktop;
        void* setDisplayVisibility_ = (void*) setDisplayVisibility;
        void* getDeviceToAbsoluteTrackingPose_ = (void*) getDeviceToAbsoluteTrackingPose;
        void* resetSeatedZeroPose_ = (void*) resetSeatedZeroPose;
        void* getSeatedZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getSeatedZeroPoseToStandingAbsoluteTrackingPose;
        void* getRawZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getRawZeroPoseToStandingAbsoluteTrackingPose;
        void* getSortedTrackedDeviceIndicesOfClass_ = (void*) getSortedTrackedDeviceIndicesOfClass;
        void* getTrackedDeviceActivityLevel_ = (void*) getTrackedDeviceActivityLevel;
        void* applyTransform_ = (void*) applyTransform;
        void* getTrackedDeviceClass_ = (void*) getTrackedDeviceClass;
        void* isTrackedDeviceConnected_ = (void*) isTrackedDeviceConnected;
        void* getBoolTrackedDeviceProperty_ = (void*) getBoolTrackedDeviceProperty;
        void* getFloatTrackedDeviceProperty_ = (void*) getFloatTrackedDeviceProperty;
        void* getInt32TrackedDeviceProperty_ = (void*) getInt32TrackedDeviceProperty;
        void* getUint64TrackedDeviceProperty_ = (void*) getUint64TrackedDeviceProperty;
        void* getMatrix34TrackedDeviceProperty_ = (void*) getMatrix34TrackedDeviceProperty;
        void* getStringTrackedDeviceProperty_ = (void*) getStringTrackedDeviceProperty;
        void* getPropErrorNameFromEnum_ = (void*) getPropErrorNameFromEnum;
        void* pollNextEvent_ = (void*) pollNextEvent;
        void* pollNextEventWithPose_ = (void*) pollNextEventWithPose;
        void* getEventTypeNameFromEnum_ = (void*) getEventTypeNameFromEnum;
        void* getHiddenAreaMesh_ = (void*) getHiddenAreaMesh;
        void* getControllerState_ = (void*) getControllerState;
        void* getControllerStateWithPose_ = (void*) getControllerStateWithPose;
        void* triggerHapticPulse_ = (void*) triggerHapticPulse;
        void* getButtonIdNameFromEnum_ = (void*) getButtonIdNameFromEnum;
        void* getControllerAxisTypeNameFromEnum_ = (void*) getControllerAxisTypeNameFromEnum;
        void* captureInputFocus_ = (void*) captureInputFocus;
        void* releaseInputFocus_ = (void*) releaseInputFocus;
        void* isInputFocusCapturedByAnotherProcess_ = (void*) isInputFocusCapturedByAnotherProcess;
        void* driverDebugRequest_ = (void*) driverDebugRequest;
        void* performFirmwareUpdate_ = (void*) performFirmwareUpdate;
        void* acknowledgeQuit_ = (void*) acknowledgeQuit;
        void* acknowledgeQuitPrompt_ = (void*) acknowledgeQuitPrompt;
    };

    class System_009_v
    {
        public:
            virtual void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height) { return System_009::getRecommendedRenderTargetSize(width, height); }
            virtual Matrix44 getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention) { return System_009::getProjectionMatrix(eye, near, far, convention); }
            virtual void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom) { return System_009::getProjectionRaw(eye, left, right, top, bottom); }
            virtual DistortionCoordinates computeDistortion(Eye eye, float u, float v) { return System_009::computeDistortion(eye, u, v); }
            virtual Matrix34 getEyeToHeadTransform(Eye eye) { return System_009::getEyeToHeadTransform(eye); }
            virtual bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter) { return System_009::getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter); }
            virtual int32_t getD3D9AdapterIndex() { return System_009::getD3D9AdapterIndex(); }
            virtual void getDXGIOutputInfo(int32_t* adapterIndex) { return System_009::getDXGIOutputInfo(adapterIndex); }
            virtual bool isDisplayOnDesktop() { return System_009::isDisplayOnDesktop(); }
            virtual bool setDisplayVisibility(bool visibleOnDesktop) { return System_009::setDisplayVisibility(visibleOnDesktop); }
            virtual void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount) { return System_009::getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount); }
            virtual void resetSeatedZeroPose() { return System_009::resetSeatedZeroPose(); }
            virtual Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose() { return System_009::getSeatedZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose() { return System_009::getRawZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex) { return System_009::getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex); }
            virtual DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index) { return System_009::getTrackedDeviceActivityLevel(index); }
            virtual void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform) { return System_009::applyTransform(outputPose, trackedDevicePose, transform); }
            virtual TrackedDeviceClass getTrackedDeviceClass(uint32_t index) { return System_009::getTrackedDeviceClass(index); }
            virtual bool isTrackedDeviceConnected(uint32_t index) { return System_009::isTrackedDeviceConnected(index); }
            virtual bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_009::getBoolTrackedDeviceProperty(index, property, error); }
            virtual float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_009::getFloatTrackedDeviceProperty(index, property, error); }
            virtual int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_009::getInt32TrackedDeviceProperty(index, property, error); }
            virtual uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_009::getUint64TrackedDeviceProperty(index, property, error); }
            virtual Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_009::getMatrix34TrackedDeviceProperty(index, property, error); }
            virtual uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error) { return System_009::getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error); }
            virtual const char* getPropErrorNameFromEnum(TrackedPropertyError error) { return System_009::getPropErrorNameFromEnum(error); }
            virtual bool pollNextEvent(Event_0_9_0* event) { return System_009::pollNextEvent(event); }
            virtual bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_0* event, TrackedDevicePose* trackedDevicePoseOut) { return System_009::pollNextEventWithPose(origin, event, trackedDevicePoseOut); }
            virtual const char* getEventTypeNameFromEnum(EventType type) { return System_009::getEventTypeNameFromEnum(type); }
            virtual HiddenAreaMesh getHiddenAreaMesh(Eye eye) { return System_009::getHiddenAreaMesh(eye); }
            virtual bool getControllerState(uint32_t index, ControllerState* state) { return System_009::getControllerState(index, state); }
            virtual bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose) { return System_009::getControllerStateWithPose(origin, index, state, pose); }
            virtual void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs) { return System_009::triggerHapticPulse(index, axisId, durationUs); }
            virtual const char* getButtonIdNameFromEnum(ButtonId button) { return System_009::getButtonIdNameFromEnum(button); }
            virtual const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType) { return System_009::getControllerAxisTypeNameFromEnum(axisType); }
            virtual bool captureInputFocus() { return System_009::captureInputFocus(); }
            virtual void releaseInputFocus() { return System_009::releaseInputFocus(); }
            virtual bool isInputFocusCapturedByAnotherProcess() { return System_009::isInputFocusCapturedByAnotherProcess(); }
            virtual uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize) { return System_009::driverDebugRequest(deviceIndex, request, response, responseBufferSize); }
            virtual FirmwareError performFirmwareUpdate(uint32_t deviceIndex) { return System_009::performFirmwareUpdate(deviceIndex); }
            virtual void acknowledgeQuit() { return System_009::acknowledgeQuit(); }
            virtual void acknowledgeQuitPrompt() { return System_009::acknowledgeQuitPrompt(); }
    };

    //

    struct System_010
    {
        static void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height);
        static Matrix44 getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention);
        static void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom);
        static DistortionCoordinates computeDistortion(Eye eye, float u, float v);
        static Matrix34 getEyeToHeadTransform(Eye eye);

        static bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter);
        static int32_t getD3D9AdapterIndex();
        static void getDXGIOutputInfo(int32_t* adapterIndex);

        static bool isDisplayOnDesktop();
        static bool setDisplayVisibility(bool visibleOnDesktop);

        static void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount);
        static void resetSeatedZeroPose();
        static Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose();
        static Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose();

        static uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex);

        static DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index);

        static void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform);

        static uint32_t getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole);
        static TrackedControllerRole getControllerRoleForTrackedDeviceIndex(uint32_t index);
        static TrackedDeviceClass getTrackedDeviceClass(uint32_t index);
        static bool isTrackedDeviceConnected(uint32_t index);
        static bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error);
        static const char* getPropErrorNameFromEnum(TrackedPropertyError error);

        static bool pollNextEvent(Event_0_9_0* event);
        static bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_0* event, TrackedDevicePose* trackedDevicePoseOut);
        static const char* getEventTypeNameFromEnum(EventType type);

        static HiddenAreaMesh getHiddenAreaMesh(Eye eye);

        static bool getControllerState(uint32_t index, ControllerState* state);
        static bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose);
        static void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs);
        static const char* getButtonIdNameFromEnum(ButtonId button);
        static const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType);

        static bool captureInputFocus();
        static void releaseInputFocus();
        static bool isInputFocusCapturedByAnotherProcess();

        static uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize);
        static FirmwareError performFirmwareUpdate(uint32_t deviceIndex);

        static void acknowledgeQuit();
        static void acknowledgeQuitPrompt();

        static void performanceTestEnableCapture(bool enable);
        static void performanceTestReportFidelityLevelChange(int level);

        void* getRecommendedRenderTargetSize_ = (void*) getRecommendedRenderTargetSize;
        void* getProjectionMatrix_ = (void*) getProjectionMatrix;
        void* getProjectionRaw_ = (void*) getProjectionRaw;
        void* computeDistortion_ = (void*) computeDistortion;
        void* getEyeToHeadTransform_ = (void*) getEyeToHeadTransform;
        void* getTimeSinceLastVsync_ = (void*) getTimeSinceLastVsync;
        void* getD3D9AdapterIndex_ = (void*) getD3D9AdapterIndex;
        void* getDXGIOutputInfo_ = (void*) getDXGIOutputInfo;
        void* isDisplayOnDesktop_ = (void*) isDisplayOnDesktop;
        void* setDisplayVisibility_ = (void*) setDisplayVisibility;
        void* getDeviceToAbsoluteTrackingPose_ = (void*) getDeviceToAbsoluteTrackingPose;
        void* resetSeatedZeroPose_ = (void*) resetSeatedZeroPose;
        void* getSeatedZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getSeatedZeroPoseToStandingAbsoluteTrackingPose;
        void* getRawZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getRawZeroPoseToStandingAbsoluteTrackingPose;
        void* getSortedTrackedDeviceIndicesOfClass_ = (void*) getSortedTrackedDeviceIndicesOfClass;
        void* getTrackedDeviceActivityLevel_ = (void*) getTrackedDeviceActivityLevel;
        void* applyTransform_ = (void*) applyTransform;
        void* getTrackedDeviceIndexForControllerRole_ = (void*) getTrackedDeviceIndexForControllerRole;
        void* getControllerRoleForTrackedDeviceIndex_ = (void*) getControllerRoleForTrackedDeviceIndex;
        void* getTrackedDeviceClass_ = (void*) getTrackedDeviceClass;
        void* isTrackedDeviceConnected_ = (void*) isTrackedDeviceConnected;
        void* getBoolTrackedDeviceProperty_ = (void*) getBoolTrackedDeviceProperty;
        void* getFloatTrackedDeviceProperty_ = (void*) getFloatTrackedDeviceProperty;
        void* getInt32TrackedDeviceProperty_ = (void*) getInt32TrackedDeviceProperty;
        void* getUint64TrackedDeviceProperty_ = (void*) getUint64TrackedDeviceProperty;
        void* getMatrix34TrackedDeviceProperty_ = (void*) getMatrix34TrackedDeviceProperty;
        void* getStringTrackedDeviceProperty_ = (void*) getStringTrackedDeviceProperty;
        void* getPropErrorNameFromEnum_ = (void*) getPropErrorNameFromEnum;
        void* pollNextEvent_ = (void*) pollNextEvent;
        void* pollNextEventWithPose_ = (void*) pollNextEventWithPose;
        void* getEventTypeNameFromEnum_ = (void*) getEventTypeNameFromEnum;
        void* getHiddenAreaMesh_ = (void*) getHiddenAreaMesh;
        void* getControllerState_ = (void*) getControllerState;
        void* getControllerStateWithPose_ = (void*) getControllerStateWithPose;
        void* triggerHapticPulse_ = (void*) triggerHapticPulse;
        void* getButtonIdNameFromEnum_ = (void*) getButtonIdNameFromEnum;
        void* getControllerAxisTypeNameFromEnum_ = (void*) getControllerAxisTypeNameFromEnum;
        void* captureInputFocus_ = (void*) captureInputFocus;
        void* releaseInputFocus_ = (void*) releaseInputFocus;
        void* isInputFocusCapturedByAnotherProcess_ = (void*) isInputFocusCapturedByAnotherProcess;
        void* driverDebugRequest_ = (void*) driverDebugRequest;
        void* performFirmwareUpdate_ = (void*) performFirmwareUpdate;
        void* acknowledgeQuit_ = (void*) acknowledgeQuit;
        void* acknowledgeQuitPrompt_ = (void*) acknowledgeQuitPrompt;
        void* performanceTestEnableCapture_ = (void*) performanceTestEnableCapture;
        void* performanceTestReportFidelityLevelChange_ = (void*) performanceTestReportFidelityLevelChange;
    };

    class System_010_v
    {
        public:
            virtual void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height) { return System_010::getRecommendedRenderTargetSize(width, height); }
            virtual Matrix44 getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention) { return System_010::getProjectionMatrix(eye, near, far, convention); }
            virtual void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom) { return System_010::getProjectionRaw(eye, left, right, top, bottom); }
            virtual DistortionCoordinates computeDistortion(Eye eye, float u, float v) { return System_010::computeDistortion(eye, u, v); }
            virtual Matrix34 getEyeToHeadTransform(Eye eye) { return System_010::getEyeToHeadTransform(eye); }
            virtual bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter) { return System_010::getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter); }
            virtual int32_t getD3D9AdapterIndex() { return System_010::getD3D9AdapterIndex(); }
            virtual void getDXGIOutputInfo(int32_t* adapterIndex) { return System_010::getDXGIOutputInfo(adapterIndex); }
            virtual bool isDisplayOnDesktop() { return System_010::isDisplayOnDesktop(); }
            virtual bool setDisplayVisibility(bool visibleOnDesktop) { return System_010::setDisplayVisibility(visibleOnDesktop); }
            virtual void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount) { return System_010::getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount); }
            virtual void resetSeatedZeroPose() { return System_010::resetSeatedZeroPose(); }
            virtual Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose() { return System_010::getSeatedZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose() { return System_010::getRawZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex) { return System_010::getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex); }
            virtual DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index) { return System_010::getTrackedDeviceActivityLevel(index); }
            virtual void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform) { return System_010::applyTransform(outputPose, trackedDevicePose, transform); }
            virtual uint32_t getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole) { return System_010::getTrackedDeviceIndexForControllerRole(controllerRole); }
            virtual TrackedControllerRole getControllerRoleForTrackedDeviceIndex(uint32_t index) { return System_010::getControllerRoleForTrackedDeviceIndex(index); }
            virtual TrackedDeviceClass getTrackedDeviceClass(uint32_t index) { return System_010::getTrackedDeviceClass(index); }
            virtual bool isTrackedDeviceConnected(uint32_t index) { return System_010::isTrackedDeviceConnected(index); }
            virtual bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_010::getBoolTrackedDeviceProperty(index, property, error); }
            virtual float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_010::getFloatTrackedDeviceProperty(index, property, error); }
            virtual int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_010::getInt32TrackedDeviceProperty(index, property, error); }
            virtual uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_010::getUint64TrackedDeviceProperty(index, property, error); }
            virtual Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_010::getMatrix34TrackedDeviceProperty(index, property, error); }
            virtual uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error) { return System_010::getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error); }
            virtual const char* getPropErrorNameFromEnum(TrackedPropertyError error) { return System_010::getPropErrorNameFromEnum(error); }
            virtual bool pollNextEvent(Event_0_9_0* event) { return System_010::pollNextEvent(event); }
            virtual bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_0* event, TrackedDevicePose* trackedDevicePoseOut) { return System_010::pollNextEventWithPose(origin, event, trackedDevicePoseOut); }
            virtual const char* getEventTypeNameFromEnum(EventType type) { return System_010::getEventTypeNameFromEnum(type); }
            virtual HiddenAreaMesh getHiddenAreaMesh(Eye eye) { return System_010::getHiddenAreaMesh(eye); }
            virtual bool getControllerState(uint32_t index, ControllerState* state) { return System_010::getControllerState(index, state); }
            virtual bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose) { return System_010::getControllerStateWithPose(origin, index, state, pose); }
            virtual void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs) { return System_010::triggerHapticPulse(index, axisId, durationUs); }
            virtual const char* getButtonIdNameFromEnum(ButtonId button) { return System_010::getButtonIdNameFromEnum(button); }
            virtual const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType) { return System_010::getControllerAxisTypeNameFromEnum(axisType); }
            virtual bool captureInputFocus() { return System_010::captureInputFocus(); }
            virtual void releaseInputFocus() { return System_010::releaseInputFocus(); }
            virtual bool isInputFocusCapturedByAnotherProcess() { return System_010::isInputFocusCapturedByAnotherProcess(); }
            virtual uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize) { return System_010::driverDebugRequest(deviceIndex, request, response, responseBufferSize); }
            virtual FirmwareError performFirmwareUpdate(uint32_t deviceIndex) { return System_010::performFirmwareUpdate(deviceIndex); }
            virtual void acknowledgeQuit() { return System_010::acknowledgeQuit(); }
            virtual void acknowledgeQuitPrompt() { return System_010::acknowledgeQuitPrompt(); }
            virtual void performanceTestEnableCapture(bool enable) { return System_010::performanceTestEnableCapture(enable); }
            virtual void performanceTestReportFidelityLevelChange(int level) { return System_010::performanceTestReportFidelityLevelChange(level); }
    };

    //

    struct System_011
    {
        static void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height);
        static Matrix44 getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention);
        static void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom);
        static DistortionCoordinates computeDistortion(Eye eye, float u, float v);
        static Matrix34 getEyeToHeadTransform(Eye eye);

        static bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter);
        static int32_t getD3D9AdapterIndex();
        static void getDXGIOutputInfo(int32_t* adapterIndex);

        static bool isDisplayOnDesktop();
        static bool setDisplayVisibility(bool visibleOnDesktop);

        static void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount);
        static void resetSeatedZeroPose();
        static Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose();
        static Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose();

        static uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex);

        static DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index);

        static void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform);

        static uint32_t getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole);
        static TrackedControllerRole getControllerRoleForTrackedDeviceIndex(uint32_t index);
        static TrackedDeviceClass getTrackedDeviceClass(uint32_t index);
        static bool isTrackedDeviceConnected(uint32_t index);
        static bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error);
        static const char* getPropErrorNameFromEnum(TrackedPropertyError error);

        static bool pollNextEvent(Event_0_9_15* event, uint32_t bufferSize);
        static bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut);
        static const char* getEventTypeNameFromEnum(EventType type);

        static HiddenAreaMesh getHiddenAreaMesh(Eye eye);

        static bool getControllerState(uint32_t index, ControllerState* state);
        static bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose);
        static void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs);
        static const char* getButtonIdNameFromEnum(ButtonId button);
        static const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType);

        static bool captureInputFocus();
        static void releaseInputFocus();
        static bool isInputFocusCapturedByAnotherProcess();

        static uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize);
        static FirmwareError performFirmwareUpdate(uint32_t deviceIndex);

        static void acknowledgeQuit();
        static void acknowledgeQuitPrompt();

        static void performanceTestEnableCapture(bool enable);
        static void performanceTestReportFidelityLevelChange(int level);

        void* getRecommendedRenderTargetSize_ = (void*) getRecommendedRenderTargetSize;
        void* getProjectionMatrix_ = (void*) getProjectionMatrix;
        void* getProjectionRaw_ = (void*) getProjectionRaw;
        void* computeDistortion_ = (void*) computeDistortion;
        void* getEyeToHeadTransform_ = (void*) getEyeToHeadTransform;
        void* getTimeSinceLastVsync_ = (void*) getTimeSinceLastVsync;
        void* getD3D9AdapterIndex_ = (void*) getD3D9AdapterIndex;
        void* getDXGIOutputInfo_ = (void*) getDXGIOutputInfo;
        void* isDisplayOnDesktop_ = (void*) isDisplayOnDesktop;
        void* setDisplayVisibility_ = (void*) setDisplayVisibility;
        void* getDeviceToAbsoluteTrackingPose_ = (void*) getDeviceToAbsoluteTrackingPose;
        void* resetSeatedZeroPose_ = (void*) resetSeatedZeroPose;
        void* getSeatedZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getSeatedZeroPoseToStandingAbsoluteTrackingPose;
        void* getRawZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getRawZeroPoseToStandingAbsoluteTrackingPose;
        void* getSortedTrackedDeviceIndicesOfClass_ = (void*) getSortedTrackedDeviceIndicesOfClass;
        void* getTrackedDeviceActivityLevel_ = (void*) getTrackedDeviceActivityLevel;
        void* applyTransform_ = (void*) applyTransform;
        void* getTrackedDeviceIndexForControllerRole_ = (void*) getTrackedDeviceIndexForControllerRole;
        void* getControllerRoleForTrackedDeviceIndex_ = (void*) getControllerRoleForTrackedDeviceIndex;
        void* getTrackedDeviceClass_ = (void*) getTrackedDeviceClass;
        void* isTrackedDeviceConnected_ = (void*) isTrackedDeviceConnected;
        void* getBoolTrackedDeviceProperty_ = (void*) getBoolTrackedDeviceProperty;
        void* getFloatTrackedDeviceProperty_ = (void*) getFloatTrackedDeviceProperty;
        void* getInt32TrackedDeviceProperty_ = (void*) getInt32TrackedDeviceProperty;
        void* getUint64TrackedDeviceProperty_ = (void*) getUint64TrackedDeviceProperty;
        void* getMatrix34TrackedDeviceProperty_ = (void*) getMatrix34TrackedDeviceProperty;
        void* getStringTrackedDeviceProperty_ = (void*) getStringTrackedDeviceProperty;
        void* getPropErrorNameFromEnum_ = (void*) getPropErrorNameFromEnum;
        void* pollNextEvent_ = (void*) pollNextEvent;
        void* pollNextEventWithPose_ = (void*) pollNextEventWithPose;
        void* getEventTypeNameFromEnum_ = (void*) getEventTypeNameFromEnum;
        void* getHiddenAreaMesh_ = (void*) getHiddenAreaMesh;
        void* getControllerState_ = (void*) getControllerState;
        void* getControllerStateWithPose_ = (void*) getControllerStateWithPose;
        void* triggerHapticPulse_ = (void*) triggerHapticPulse;
        void* getButtonIdNameFromEnum_ = (void*) getButtonIdNameFromEnum;
        void* getControllerAxisTypeNameFromEnum_ = (void*) getControllerAxisTypeNameFromEnum;
        void* captureInputFocus_ = (void*) captureInputFocus;
        void* releaseInputFocus_ = (void*) releaseInputFocus;
        void* isInputFocusCapturedByAnotherProcess_ = (void*) isInputFocusCapturedByAnotherProcess;
        void* driverDebugRequest_ = (void*) driverDebugRequest;
        void* performFirmwareUpdate_ = (void*) performFirmwareUpdate;
        void* acknowledgeQuit_ = (void*) acknowledgeQuit;
        void* acknowledgeQuitPrompt_ = (void*) acknowledgeQuitPrompt;
        void* performanceTestEnableCapture_ = (void*) performanceTestEnableCapture;
        void* performanceTestReportFidelityLevelChange_ = (void*) performanceTestReportFidelityLevelChange;
    };

    class System_011_v
    {
        public:
            virtual void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height) { return System_011::getRecommendedRenderTargetSize(width, height); }
            virtual Matrix44 getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention) { return System_011::getProjectionMatrix(eye, near, far, convention); }
            virtual void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom) { return System_011::getProjectionRaw(eye, left, right, top, bottom); }
            virtual DistortionCoordinates computeDistortion(Eye eye, float u, float v) { return System_011::computeDistortion(eye, u, v); }
            virtual Matrix34 getEyeToHeadTransform(Eye eye) { return System_011::getEyeToHeadTransform(eye); }
            virtual bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter) { return System_011::getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter); }
            virtual int32_t getD3D9AdapterIndex() { return System_011::getD3D9AdapterIndex(); }
            virtual void getDXGIOutputInfo(int32_t* adapterIndex) { return System_011::getDXGIOutputInfo(adapterIndex); }
            virtual bool isDisplayOnDesktop() { return System_011::isDisplayOnDesktop(); }
            virtual bool setDisplayVisibility(bool visibleOnDesktop) { return System_011::setDisplayVisibility(visibleOnDesktop); }
            virtual void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount) { return System_011::getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount); }
            virtual void resetSeatedZeroPose() { return System_011::resetSeatedZeroPose(); }
            virtual Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose() { return System_011::getSeatedZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose() { return System_011::getRawZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex) { return System_011::getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex); }
            virtual DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index) { return System_011::getTrackedDeviceActivityLevel(index); }
            virtual void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform) { return System_011::applyTransform(outputPose, trackedDevicePose, transform); }
            virtual uint32_t getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole) { return System_011::getTrackedDeviceIndexForControllerRole(controllerRole); }
            virtual TrackedControllerRole getControllerRoleForTrackedDeviceIndex(uint32_t index) { return System_011::getControllerRoleForTrackedDeviceIndex(index); }
            virtual TrackedDeviceClass getTrackedDeviceClass(uint32_t index) { return System_011::getTrackedDeviceClass(index); }
            virtual bool isTrackedDeviceConnected(uint32_t index) { return System_011::isTrackedDeviceConnected(index); }
            virtual bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_011::getBoolTrackedDeviceProperty(index, property, error); }
            virtual float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_011::getFloatTrackedDeviceProperty(index, property, error); }
            virtual int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_011::getInt32TrackedDeviceProperty(index, property, error); }
            virtual uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_011::getUint64TrackedDeviceProperty(index, property, error); }
            virtual Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_011::getMatrix34TrackedDeviceProperty(index, property, error); }
            virtual uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error) { return System_011::getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error); }
            virtual const char* getPropErrorNameFromEnum(TrackedPropertyError error) { return System_011::getPropErrorNameFromEnum(error); }
            virtual bool pollNextEvent(Event_0_9_15* event, uint32_t bufferSize) { return System_011::pollNextEvent(event, bufferSize); }
            virtual bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut) { return System_011::pollNextEventWithPose(origin, event, bufferSize, trackedDevicePoseOut); }
            virtual const char* getEventTypeNameFromEnum(EventType type) { return System_011::getEventTypeNameFromEnum(type); }
            virtual HiddenAreaMesh getHiddenAreaMesh(Eye eye) { return System_011::getHiddenAreaMesh(eye); }
            virtual bool getControllerState(uint32_t index, ControllerState* state) { return System_011::getControllerState(index, state); }
            virtual bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose) { return System_011::getControllerStateWithPose(origin, index, state, pose); }
            virtual void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs) { return System_011::triggerHapticPulse(index, axisId, durationUs); }
            virtual const char* getButtonIdNameFromEnum(ButtonId button) { return System_011::getButtonIdNameFromEnum(button); }
            virtual const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType) { return System_011::getControllerAxisTypeNameFromEnum(axisType); }
            virtual bool captureInputFocus() { return System_011::captureInputFocus(); }
            virtual void releaseInputFocus() { return System_011::releaseInputFocus(); }
            virtual bool isInputFocusCapturedByAnotherProcess() { return System_011::isInputFocusCapturedByAnotherProcess(); }
            virtual uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize) { return System_011::driverDebugRequest(deviceIndex, request, response, responseBufferSize); }
            virtual FirmwareError performFirmwareUpdate(uint32_t deviceIndex) { return System_011::performFirmwareUpdate(deviceIndex); }
            virtual void acknowledgeQuit() { return System_011::acknowledgeQuit(); }
            virtual void acknowledgeQuitPrompt() { return System_011::acknowledgeQuitPrompt(); }
            virtual void performanceTestEnableCapture(bool enable) { return System_011::performanceTestEnableCapture(enable); }
            virtual void performanceTestReportFidelityLevelChange(int level) { return System_011::performanceTestReportFidelityLevelChange(level); }
    };

    //

    struct System_012
    {
        static void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height);
        static Matrix44 getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention);
        static void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom);
        static DistortionCoordinates computeDistortion(Eye eye, float u, float v);
        static Matrix34 getEyeToHeadTransform(Eye eye);

        static bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter);
        static int32_t getD3D9AdapterIndex();
        static void getDXGIOutputInfo(int32_t* adapterIndex);

        static bool isDisplayOnDesktop();
        static bool setDisplayVisibility(bool visibleOnDesktop);

        static void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount);
        static void resetSeatedZeroPose();
        static Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose();
        static Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose();

        static uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex);

        static DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index);

        static void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform);

        static uint32_t getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole);
        static TrackedControllerRole getControllerRoleForTrackedDeviceIndex(uint32_t index);
        static TrackedDeviceClass getTrackedDeviceClass(uint32_t index);
        static bool isTrackedDeviceConnected(uint32_t index);
        static bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error);
        static const char* getPropErrorNameFromEnum(TrackedPropertyError error);

        static bool pollNextEvent(Event_0_9_15* event, uint32_t bufferSize);
        static bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut);
        static const char* getEventTypeNameFromEnum(EventType type);

        static HiddenAreaMesh getHiddenAreaMesh(Eye eye);

        static bool getControllerState(uint32_t index, ControllerState* state);
        static bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose);
        static void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs);
        static const char* getButtonIdNameFromEnum(ButtonId button);
        static const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType);

        static bool captureInputFocus();
        static void releaseInputFocus();
        static bool isInputFocusCapturedByAnotherProcess();

        static uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize);
        static FirmwareError performFirmwareUpdate(uint32_t deviceIndex);

        static void acknowledgeQuit();
        static void acknowledgeQuitPrompt();

        void* getRecommendedRenderTargetSize_ = (void*) getRecommendedRenderTargetSize;
        void* getProjectionMatrix_ = (void*) getProjectionMatrix;
        void* getProjectionRaw_ = (void*) getProjectionRaw;
        void* computeDistortion_ = (void*) computeDistortion;
        void* getEyeToHeadTransform_ = (void*) getEyeToHeadTransform;
        void* getTimeSinceLastVsync_ = (void*) getTimeSinceLastVsync;
        void* getD3D9AdapterIndex_ = (void*) getD3D9AdapterIndex;
        void* getDXGIOutputInfo_ = (void*) getDXGIOutputInfo;
        void* isDisplayOnDesktop_ = (void*) isDisplayOnDesktop;
        void* setDisplayVisibility_ = (void*) setDisplayVisibility;
        void* getDeviceToAbsoluteTrackingPose_ = (void*) getDeviceToAbsoluteTrackingPose;
        void* resetSeatedZeroPose_ = (void*) resetSeatedZeroPose;
        void* getSeatedZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getSeatedZeroPoseToStandingAbsoluteTrackingPose;
        void* getRawZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getRawZeroPoseToStandingAbsoluteTrackingPose;
        void* getSortedTrackedDeviceIndicesOfClass_ = (void*) getSortedTrackedDeviceIndicesOfClass;
        void* getTrackedDeviceActivityLevel_ = (void*) getTrackedDeviceActivityLevel;
        void* applyTransform_ = (void*) applyTransform;
        void* getTrackedDeviceIndexForControllerRole_ = (void*) getTrackedDeviceIndexForControllerRole;
        void* getControllerRoleForTrackedDeviceIndex_ = (void*) getControllerRoleForTrackedDeviceIndex;
        void* getTrackedDeviceClass_ = (void*) getTrackedDeviceClass;
        void* isTrackedDeviceConnected_ = (void*) isTrackedDeviceConnected;
        void* getBoolTrackedDeviceProperty_ = (void*) getBoolTrackedDeviceProperty;
        void* getFloatTrackedDeviceProperty_ = (void*) getFloatTrackedDeviceProperty;
        void* getInt32TrackedDeviceProperty_ = (void*) getInt32TrackedDeviceProperty;
        void* getUint64TrackedDeviceProperty_ = (void*) getUint64TrackedDeviceProperty;
        void* getMatrix34TrackedDeviceProperty_ = (void*) getMatrix34TrackedDeviceProperty;
        void* getStringTrackedDeviceProperty_ = (void*) getStringTrackedDeviceProperty;
        void* getPropErrorNameFromEnum_ = (void*) getPropErrorNameFromEnum;
        void* pollNextEvent_ = (void*) pollNextEvent;
        void* pollNextEventWithPose_ = (void*) pollNextEventWithPose;
        void* getEventTypeNameFromEnum_ = (void*) getEventTypeNameFromEnum;
        void* getHiddenAreaMesh_ = (void*) getHiddenAreaMesh;
        void* getControllerState_ = (void*) getControllerState;
        void* getControllerStateWithPose_ = (void*) getControllerStateWithPose;
        void* triggerHapticPulse_ = (void*) triggerHapticPulse;
        void* getButtonIdNameFromEnum_ = (void*) getButtonIdNameFromEnum;
        void* getControllerAxisTypeNameFromEnum_ = (void*) getControllerAxisTypeNameFromEnum;
        void* captureInputFocus_ = (void*) captureInputFocus;
        void* releaseInputFocus_ = (void*) releaseInputFocus;
        void* isInputFocusCapturedByAnotherProcess_ = (void*) isInputFocusCapturedByAnotherProcess;
        void* driverDebugRequest_ = (void*) driverDebugRequest;
        void* performFirmwareUpdate_ = (void*) performFirmwareUpdate;
        void* acknowledgeQuit_ = (void*) acknowledgeQuit;
        void* acknowledgeQuitPrompt_ = (void*) acknowledgeQuitPrompt;
    };

    class System_012_v
    {
        public:
            virtual void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height) { return System_012::getRecommendedRenderTargetSize(width, height); }
            virtual Matrix44 getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention) { return System_012::getProjectionMatrix(eye, near, far, convention); }
            virtual void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom) { return System_012::getProjectionRaw(eye, left, right, top, bottom); }
            virtual DistortionCoordinates computeDistortion(Eye eye, float u, float v) { return System_012::computeDistortion(eye, u, v); }
            virtual Matrix34 getEyeToHeadTransform(Eye eye) { return System_012::getEyeToHeadTransform(eye); }
            virtual bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter) { return System_012::getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter); }
            virtual int32_t getD3D9AdapterIndex() { return System_012::getD3D9AdapterIndex(); }
            virtual void getDXGIOutputInfo(int32_t* adapterIndex) { return System_012::getDXGIOutputInfo(adapterIndex); }
            virtual bool isDisplayOnDesktop() { return System_012::isDisplayOnDesktop(); }
            virtual bool setDisplayVisibility(bool visibleOnDesktop) { return System_012::setDisplayVisibility(visibleOnDesktop); }
            virtual void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount) { return System_012::getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount); }
            virtual void resetSeatedZeroPose() { return System_012::resetSeatedZeroPose(); }
            virtual Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose() { return System_012::getSeatedZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose() { return System_012::getRawZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex) { return System_012::getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex); }
            virtual DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index) { return System_012::getTrackedDeviceActivityLevel(index); }
            virtual void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform) { return System_012::applyTransform(outputPose, trackedDevicePose, transform); }
            virtual uint32_t getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole) { return System_012::getTrackedDeviceIndexForControllerRole(controllerRole); }
            virtual TrackedControllerRole getControllerRoleForTrackedDeviceIndex(uint32_t index) { return System_012::getControllerRoleForTrackedDeviceIndex(index); }
            virtual TrackedDeviceClass getTrackedDeviceClass(uint32_t index) { return System_012::getTrackedDeviceClass(index); }
            virtual bool isTrackedDeviceConnected(uint32_t index) { return System_012::isTrackedDeviceConnected(index); }
            virtual bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_012::getBoolTrackedDeviceProperty(index, property, error); }
            virtual float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_012::getFloatTrackedDeviceProperty(index, property, error); }
            virtual int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_012::getInt32TrackedDeviceProperty(index, property, error); }
            virtual uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_012::getUint64TrackedDeviceProperty(index, property, error); }
            virtual Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_012::getMatrix34TrackedDeviceProperty(index, property, error); }
            virtual uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error) { return System_012::getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error); }
            virtual const char* getPropErrorNameFromEnum(TrackedPropertyError error) { return System_012::getPropErrorNameFromEnum(error); }
            virtual bool pollNextEvent(Event_0_9_15* event, uint32_t bufferSize) { return System_012::pollNextEvent(event, bufferSize); }
            virtual bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut) { return System_012::pollNextEventWithPose(origin, event, bufferSize, trackedDevicePoseOut); }
            virtual const char* getEventTypeNameFromEnum(EventType type) { return System_012::getEventTypeNameFromEnum(type); }
            virtual HiddenAreaMesh getHiddenAreaMesh(Eye eye) { return System_012::getHiddenAreaMesh(eye); }
            virtual bool getControllerState(uint32_t index, ControllerState* state) { return System_012::getControllerState(index, state); }
            virtual bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose) { return System_012::getControllerStateWithPose(origin, index, state, pose); }
            virtual void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs) { return System_012::triggerHapticPulse(index, axisId, durationUs); }
            virtual const char* getButtonIdNameFromEnum(ButtonId button) { return System_012::getButtonIdNameFromEnum(button); }
            virtual const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType) { return System_012::getControllerAxisTypeNameFromEnum(axisType); }
            virtual bool captureInputFocus() { return System_012::captureInputFocus(); }
            virtual void releaseInputFocus() { return System_012::releaseInputFocus(); }
            virtual bool isInputFocusCapturedByAnotherProcess() { return System_012::isInputFocusCapturedByAnotherProcess(); }
            virtual uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize) { return System_012::driverDebugRequest(deviceIndex, request, response, responseBufferSize); }
            virtual FirmwareError performFirmwareUpdate(uint32_t deviceIndex) { return System_012::performFirmwareUpdate(deviceIndex); }
            virtual void acknowledgeQuit() { return System_012::acknowledgeQuit(); }
            virtual void acknowledgeQuitPrompt() { return System_012::acknowledgeQuitPrompt(); }
    };

    //

    struct System_014
    {
        static void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height);
        static Matrix44 getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention);
        static void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom);
        static bool computeDistortion(Eye eye, float u, float v, DistortionCoordinates* distortionCoordinates);
        static Matrix34 getEyeToHeadTransform(Eye eye);

        static bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter);
        static int32_t getD3D9AdapterIndex();
        static void getDXGIOutputInfo(int32_t* adapterIndex);

        static bool isDisplayOnDesktop();
        static bool setDisplayVisibility(bool visibleOnDesktop);

        static void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount);
        static void resetSeatedZeroPose();
        static Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose();
        static Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose();

        static uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex);

        static DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index);

        static void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform);

        static uint32_t getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole);
        static TrackedControllerRole getControllerRoleForTrackedDeviceIndex(uint32_t index);
        static TrackedDeviceClass getTrackedDeviceClass(uint32_t index);
        static bool isTrackedDeviceConnected(uint32_t index);
        static bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error);
        static const char* getPropErrorNameFromEnum(TrackedPropertyError error);

        static bool pollNextEvent(Event_0_9_15* event, uint32_t bufferSize);
        static bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut);
        static const char* getEventTypeNameFromEnum(EventType type);

        static HiddenAreaMesh getHiddenAreaMesh(Eye eye, HiddenAreaMeshType type);

        static bool getControllerState(uint32_t index, ControllerState* state, uint32_t bufferSize);
        static bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, uint32_t bufferSize, TrackedDevicePose* pose);
        static void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs);
        static const char* getButtonIdNameFromEnum(ButtonId button);
        static const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType);

        static bool captureInputFocus();
        static void releaseInputFocus();
        static bool isInputFocusCapturedByAnotherProcess();

        static uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize);
        static FirmwareError performFirmwareUpdate(uint32_t deviceIndex);

        static void acknowledgeQuit();
        static void acknowledgeQuitPrompt();

        void* getRecommendedRenderTargetSize_ = (void*) getRecommendedRenderTargetSize;
        void* getProjectionMatrix_ = (void*) getProjectionMatrix;
        void* getProjectionRaw_ = (void*) getProjectionRaw;
        void* computeDistortion_ = (void*) computeDistortion;
        void* getEyeToHeadTransform_ = (void*) getEyeToHeadTransform;
        void* getTimeSinceLastVsync_ = (void*) getTimeSinceLastVsync;
        void* getD3D9AdapterIndex_ = (void*) getD3D9AdapterIndex;
        void* getDXGIOutputInfo_ = (void*) getDXGIOutputInfo;
        void* isDisplayOnDesktop_ = (void*) isDisplayOnDesktop;
        void* setDisplayVisibility_ = (void*) setDisplayVisibility;
        void* getDeviceToAbsoluteTrackingPose_ = (void*) getDeviceToAbsoluteTrackingPose;
        void* resetSeatedZeroPose_ = (void*) resetSeatedZeroPose;
        void* getSeatedZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getSeatedZeroPoseToStandingAbsoluteTrackingPose;
        void* getRawZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getRawZeroPoseToStandingAbsoluteTrackingPose;
        void* getSortedTrackedDeviceIndicesOfClass_ = (void*) getSortedTrackedDeviceIndicesOfClass;
        void* getTrackedDeviceActivityLevel_ = (void*) getTrackedDeviceActivityLevel;
        void* applyTransform_ = (void*) applyTransform;
        void* getTrackedDeviceIndexForControllerRole_ = (void*) getTrackedDeviceIndexForControllerRole;
        void* getControllerRoleForTrackedDeviceIndex_ = (void*) getControllerRoleForTrackedDeviceIndex;
        void* getTrackedDeviceClass_ = (void*) getTrackedDeviceClass;
        void* isTrackedDeviceConnected_ = (void*) isTrackedDeviceConnected;
        void* getBoolTrackedDeviceProperty_ = (void*) getBoolTrackedDeviceProperty;
        void* getFloatTrackedDeviceProperty_ = (void*) getFloatTrackedDeviceProperty;
        void* getInt32TrackedDeviceProperty_ = (void*) getInt32TrackedDeviceProperty;
        void* getUint64TrackedDeviceProperty_ = (void*) getUint64TrackedDeviceProperty;
        void* getMatrix34TrackedDeviceProperty_ = (void*) getMatrix34TrackedDeviceProperty;
        void* getStringTrackedDeviceProperty_ = (void*) getStringTrackedDeviceProperty;
        void* getPropErrorNameFromEnum_ = (void*) getPropErrorNameFromEnum;
        void* pollNextEvent_ = (void*) pollNextEvent;
        void* pollNextEventWithPose_ = (void*) pollNextEventWithPose;
        void* getEventTypeNameFromEnum_ = (void*) getEventTypeNameFromEnum;
        void* getHiddenAreaMesh_ = (void*) getHiddenAreaMesh;
        void* getControllerState_ = (void*) getControllerState;
        void* getControllerStateWithPose_ = (void*) getControllerStateWithPose;
        void* triggerHapticPulse_ = (void*) triggerHapticPulse;
        void* getButtonIdNameFromEnum_ = (void*) getButtonIdNameFromEnum;
        void* getControllerAxisTypeNameFromEnum_ = (void*) getControllerAxisTypeNameFromEnum;
        void* captureInputFocus_ = (void*) captureInputFocus;
        void* releaseInputFocus_ = (void*) releaseInputFocus;
        void* isInputFocusCapturedByAnotherProcess_ = (void*) isInputFocusCapturedByAnotherProcess;
        void* driverDebugRequest_ = (void*) driverDebugRequest;
        void* performFirmwareUpdate_ = (void*) performFirmwareUpdate;
        void* acknowledgeQuit_ = (void*) acknowledgeQuit;
        void* acknowledgeQuitPrompt_ = (void*) acknowledgeQuitPrompt;
    };

    class System_014_v
    {
        public:
            virtual void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height) { return System_014::getRecommendedRenderTargetSize(width, height); }
            virtual Matrix44 getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention) { return System_014::getProjectionMatrix(eye, near, far, convention); }
            virtual void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom) { return System_014::getProjectionRaw(eye, left, right, top, bottom); }
            virtual bool computeDistortion(Eye eye, float u, float v, DistortionCoordinates* distortionCoordinates) { return System_014::computeDistortion(eye, u, v, distortionCoordinates); }
            virtual Matrix34 getEyeToHeadTransform(Eye eye) { return System_014::getEyeToHeadTransform(eye); }
            virtual bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter) { return System_014::getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter); }
            virtual int32_t getD3D9AdapterIndex() { return System_014::getD3D9AdapterIndex(); }
            virtual void getDXGIOutputInfo(int32_t* adapterIndex) { return System_014::getDXGIOutputInfo(adapterIndex); }
            virtual bool isDisplayOnDesktop() { return System_014::isDisplayOnDesktop(); }
            virtual bool setDisplayVisibility(bool visibleOnDesktop) { return System_014::setDisplayVisibility(visibleOnDesktop); }
            virtual void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount) { return System_014::getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount); }
            virtual void resetSeatedZeroPose() { return System_014::resetSeatedZeroPose(); }
            virtual Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose() { return System_014::getSeatedZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose() { return System_014::getRawZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex) { return System_014::getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex); }
            virtual DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index) { return System_014::getTrackedDeviceActivityLevel(index); }
            virtual void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform) { return System_014::applyTransform(outputPose, trackedDevicePose, transform); }
            virtual uint32_t getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole) { return System_014::getTrackedDeviceIndexForControllerRole(controllerRole); }
            virtual TrackedControllerRole getControllerRoleForTrackedDeviceIndex(uint32_t index) { return System_014::getControllerRoleForTrackedDeviceIndex(index); }
            virtual TrackedDeviceClass getTrackedDeviceClass(uint32_t index) { return System_014::getTrackedDeviceClass(index); }
            virtual bool isTrackedDeviceConnected(uint32_t index) { return System_014::isTrackedDeviceConnected(index); }
            virtual bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_014::getBoolTrackedDeviceProperty(index, property, error); }
            virtual float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_014::getFloatTrackedDeviceProperty(index, property, error); }
            virtual int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_014::getInt32TrackedDeviceProperty(index, property, error); }
            virtual uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_014::getUint64TrackedDeviceProperty(index, property, error); }
            virtual Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_014::getMatrix34TrackedDeviceProperty(index, property, error); }
            virtual uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error) { return System_014::getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error); }
            virtual const char* getPropErrorNameFromEnum(TrackedPropertyError error) { return System_014::getPropErrorNameFromEnum(error); }
            virtual bool pollNextEvent(Event_0_9_15* event, uint32_t bufferSize) { return System_014::pollNextEvent(event, bufferSize); }
            virtual bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut) { return System_014::pollNextEventWithPose(origin, event, bufferSize, trackedDevicePoseOut); }
            virtual const char* getEventTypeNameFromEnum(EventType type) { return System_014::getEventTypeNameFromEnum(type); }
            virtual HiddenAreaMesh getHiddenAreaMesh(Eye eye, HiddenAreaMeshType type) { return System_014::getHiddenAreaMesh(eye, type); }
            virtual bool getControllerState(uint32_t index, ControllerState* state, uint32_t bufferSize) { return System_014::getControllerState(index, state, bufferSize); }
            virtual bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, uint32_t bufferSize, TrackedDevicePose* pose) { return System_014::getControllerStateWithPose(origin, index, state, bufferSize, pose); }
            virtual void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs) { return System_014::triggerHapticPulse(index, axisId, durationUs); }
            virtual const char* getButtonIdNameFromEnum(ButtonId button) { return System_014::getButtonIdNameFromEnum(button); }
            virtual const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType) { return System_014::getControllerAxisTypeNameFromEnum(axisType); }
            virtual bool captureInputFocus() { return System_014::captureInputFocus(); }
            virtual void releaseInputFocus() { return System_014::releaseInputFocus(); }
            virtual bool isInputFocusCapturedByAnotherProcess() { return System_014::isInputFocusCapturedByAnotherProcess(); }
            virtual uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize) { return System_014::driverDebugRequest(deviceIndex, request, response, responseBufferSize); }
            virtual FirmwareError performFirmwareUpdate(uint32_t deviceIndex) { return System_014::performFirmwareUpdate(deviceIndex); }
            virtual void acknowledgeQuit() { return System_014::acknowledgeQuit(); }
            virtual void acknowledgeQuitPrompt() { return System_014::acknowledgeQuitPrompt(); }
    };

    //

    struct System_015
    {
        static void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height);
        static Matrix44 getProjectionMatrix(Eye eye, float near, float far);
        static void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom);
        static bool computeDistortion(Eye eye, float u, float v, DistortionCoordinates* distortionCoordinates);
        static Matrix34 getEyeToHeadTransform(Eye eye);

        static bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter);
        static int32_t getD3D9AdapterIndex();
        static void getDXGIOutputInfo(int32_t* adapterIndex);

        static bool isDisplayOnDesktop();
        static bool setDisplayVisibility(bool visibleOnDesktop);

        static void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount);
        static void resetSeatedZeroPose();
        static Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose();
        static Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose();

        static uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex);

        static DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index);

        static void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform);

        static uint32_t getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole);
        static TrackedControllerRole getControllerRoleForTrackedDeviceIndex(uint32_t index);
        static TrackedDeviceClass getTrackedDeviceClass(uint32_t index);
        static bool isTrackedDeviceConnected(uint32_t index);
        static bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error);
        static const char* getPropErrorNameFromEnum(TrackedPropertyError error);

        static bool pollNextEvent(Event_0_9_15* event, uint32_t bufferSize);
        static bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut);
        static const char* getEventTypeNameFromEnum(EventType type);

        static HiddenAreaMesh getHiddenAreaMesh(Eye eye, HiddenAreaMeshType type);

        static bool getControllerState(uint32_t index, ControllerState* state, uint32_t bufferSize);
        static bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, uint32_t bufferSize, TrackedDevicePose* pose);
        static void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs);
        static const char* getButtonIdNameFromEnum(ButtonId button);
        static const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType);

        static bool captureInputFocus();
        static void releaseInputFocus();
        static bool isInputFocusCapturedByAnotherProcess();

        static uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize);
        static FirmwareError performFirmwareUpdate(uint32_t deviceIndex);

        static void acknowledgeQuit();
        static void acknowledgeQuitPrompt();

        void* getRecommendedRenderTargetSize_ = (void*) getRecommendedRenderTargetSize;
        void* getProjectionMatrix_ = (void*) getProjectionMatrix;
        void* getProjectionRaw_ = (void*) getProjectionRaw;
        void* computeDistortion_ = (void*) computeDistortion;
        void* getEyeToHeadTransform_ = (void*) getEyeToHeadTransform;
        void* getTimeSinceLastVsync_ = (void*) getTimeSinceLastVsync;
        void* getD3D9AdapterIndex_ = (void*) getD3D9AdapterIndex;
        void* getDXGIOutputInfo_ = (void*) getDXGIOutputInfo;
        void* isDisplayOnDesktop_ = (void*) isDisplayOnDesktop;
        void* setDisplayVisibility_ = (void*) setDisplayVisibility;
        void* getDeviceToAbsoluteTrackingPose_ = (void*) getDeviceToAbsoluteTrackingPose;
        void* resetSeatedZeroPose_ = (void*) resetSeatedZeroPose;
        void* getSeatedZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getSeatedZeroPoseToStandingAbsoluteTrackingPose;
        void* getRawZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getRawZeroPoseToStandingAbsoluteTrackingPose;
        void* getSortedTrackedDeviceIndicesOfClass_ = (void*) getSortedTrackedDeviceIndicesOfClass;
        void* getTrackedDeviceActivityLevel_ = (void*) getTrackedDeviceActivityLevel;
        void* applyTransform_ = (void*) applyTransform;
        void* getTrackedDeviceIndexForControllerRole_ = (void*) getTrackedDeviceIndexForControllerRole;
        void* getControllerRoleForTrackedDeviceIndex_ = (void*) getControllerRoleForTrackedDeviceIndex;
        void* getTrackedDeviceClass_ = (void*) getTrackedDeviceClass;
        void* isTrackedDeviceConnected_ = (void*) isTrackedDeviceConnected;
        void* getBoolTrackedDeviceProperty_ = (void*) getBoolTrackedDeviceProperty;
        void* getFloatTrackedDeviceProperty_ = (void*) getFloatTrackedDeviceProperty;
        void* getInt32TrackedDeviceProperty_ = (void*) getInt32TrackedDeviceProperty;
        void* getUint64TrackedDeviceProperty_ = (void*) getUint64TrackedDeviceProperty;
        void* getMatrix34TrackedDeviceProperty_ = (void*) getMatrix34TrackedDeviceProperty;
        void* getStringTrackedDeviceProperty_ = (void*) getStringTrackedDeviceProperty;
        void* getPropErrorNameFromEnum_ = (void*) getPropErrorNameFromEnum;
        void* pollNextEvent_ = (void*) pollNextEvent;
        void* pollNextEventWithPose_ = (void*) pollNextEventWithPose;
        void* getEventTypeNameFromEnum_ = (void*) getEventTypeNameFromEnum;
        void* getHiddenAreaMesh_ = (void*) getHiddenAreaMesh;
        void* getControllerState_ = (void*) getControllerState;
        void* getControllerStateWithPose_ = (void*) getControllerStateWithPose;
        void* triggerHapticPulse_ = (void*) triggerHapticPulse;
        void* getButtonIdNameFromEnum_ = (void*) getButtonIdNameFromEnum;
        void* getControllerAxisTypeNameFromEnum_ = (void*) getControllerAxisTypeNameFromEnum;
        void* captureInputFocus_ = (void*) captureInputFocus;
        void* releaseInputFocus_ = (void*) releaseInputFocus;
        void* isInputFocusCapturedByAnotherProcess_ = (void*) isInputFocusCapturedByAnotherProcess;
        void* driverDebugRequest_ = (void*) driverDebugRequest;
        void* performFirmwareUpdate_ = (void*) performFirmwareUpdate;
        void* acknowledgeQuit_ = (void*) acknowledgeQuit;
        void* acknowledgeQuitPrompt_ = (void*) acknowledgeQuitPrompt;
    };

    class System_015_v
    {
        public:
            virtual void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height) { return System_015::getRecommendedRenderTargetSize(width, height); }
            virtual Matrix44 getProjectionMatrix(Eye eye, float near, float far) { return System_015::getProjectionMatrix(eye, near, far); }
            virtual void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom) { return System_015::getProjectionRaw(eye, left, right, top, bottom); }
            virtual bool computeDistortion(Eye eye, float u, float v, DistortionCoordinates* distortionCoordinates) { return System_015::computeDistortion(eye, u, v, distortionCoordinates); }
            virtual Matrix34 getEyeToHeadTransform(Eye eye) { return System_015::getEyeToHeadTransform(eye); }
            virtual bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter) { return System_015::getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter); }
            virtual int32_t getD3D9AdapterIndex() { return System_015::getD3D9AdapterIndex(); }
            virtual void getDXGIOutputInfo(int32_t* adapterIndex) { return System_015::getDXGIOutputInfo(adapterIndex); }
            virtual bool isDisplayOnDesktop() { return System_015::isDisplayOnDesktop(); }
            virtual bool setDisplayVisibility(bool visibleOnDesktop) { return System_015::setDisplayVisibility(visibleOnDesktop); }
            virtual void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount) { return System_015::getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount); }
            virtual void resetSeatedZeroPose() { return System_015::resetSeatedZeroPose(); }
            virtual Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose() { return System_015::getSeatedZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose() { return System_015::getRawZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex) { return System_015::getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex); }
            virtual DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index) { return System_015::getTrackedDeviceActivityLevel(index); }
            virtual void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform) { return System_015::applyTransform(outputPose, trackedDevicePose, transform); }
            virtual uint32_t getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole) { return System_015::getTrackedDeviceIndexForControllerRole(controllerRole); }
            virtual TrackedControllerRole getControllerRoleForTrackedDeviceIndex(uint32_t index) { return System_015::getControllerRoleForTrackedDeviceIndex(index); }
            virtual TrackedDeviceClass getTrackedDeviceClass(uint32_t index) { return System_015::getTrackedDeviceClass(index); }
            virtual bool isTrackedDeviceConnected(uint32_t index) { return System_015::isTrackedDeviceConnected(index); }
            virtual bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_015::getBoolTrackedDeviceProperty(index, property, error); }
            virtual float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_015::getFloatTrackedDeviceProperty(index, property, error); }
            virtual int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_015::getInt32TrackedDeviceProperty(index, property, error); }
            virtual uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_015::getUint64TrackedDeviceProperty(index, property, error); }
            virtual Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_015::getMatrix34TrackedDeviceProperty(index, property, error); }
            virtual uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error) { return System_015::getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error); }
            virtual const char* getPropErrorNameFromEnum(TrackedPropertyError error) { return System_015::getPropErrorNameFromEnum(error); }
            virtual bool pollNextEvent(Event_0_9_15* event, uint32_t bufferSize) { return System_015::pollNextEvent(event, bufferSize); }
            virtual bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut) { return System_015::pollNextEventWithPose(origin, event, bufferSize, trackedDevicePoseOut); }
            virtual const char* getEventTypeNameFromEnum(EventType type) { return System_015::getEventTypeNameFromEnum(type); }
            virtual HiddenAreaMesh getHiddenAreaMesh(Eye eye, HiddenAreaMeshType type) { return System_015::getHiddenAreaMesh(eye, type); }
            virtual bool getControllerState(uint32_t index, ControllerState* state, uint32_t bufferSize) { return System_015::getControllerState(index, state, bufferSize); }
            virtual bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, uint32_t bufferSize, TrackedDevicePose* pose) { return System_015::getControllerStateWithPose(origin, index, state, bufferSize, pose); }
            virtual void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs) { return System_015::triggerHapticPulse(index, axisId, durationUs); }
            virtual const char* getButtonIdNameFromEnum(ButtonId button) { return System_015::getButtonIdNameFromEnum(button); }
            virtual const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType) { return System_015::getControllerAxisTypeNameFromEnum(axisType); }
            virtual bool captureInputFocus() { return System_015::captureInputFocus(); }
            virtual void releaseInputFocus() { return System_015::releaseInputFocus(); }
            virtual bool isInputFocusCapturedByAnotherProcess() { return System_015::isInputFocusCapturedByAnotherProcess(); }
            virtual uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize) { return System_015::driverDebugRequest(deviceIndex, request, response, responseBufferSize); }
            virtual FirmwareError performFirmwareUpdate(uint32_t deviceIndex) { return System_015::performFirmwareUpdate(deviceIndex); }
            virtual void acknowledgeQuit() { return System_015::acknowledgeQuit(); }
            virtual void acknowledgeQuitPrompt() { return System_015::acknowledgeQuitPrompt(); }
    };

    //

    struct System_016
    {
        static void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height);
        static Matrix44 getProjectionMatrix(Eye eye, float near, float far);
        static void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom);
        static bool computeDistortion(Eye eye, float u, float v, DistortionCoordinates* distortionCoordinates);
        static Matrix34 getEyeToHeadTransform(Eye eye);

        static bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter);
        static int32_t getD3D9AdapterIndex();
        static void getDXGIOutputInfo(int32_t* adapterIndex);
        static void getOutputDevice(uint64_t* device, TextureType textureType);

        static bool isDisplayOnDesktop();
        static bool setDisplayVisibility(bool visibleOnDesktop);

        static void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount);
        static void resetSeatedZeroPose();
        static Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose();
        static Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose();

        static uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex);

        static DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index);

        static void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform);

        static uint32_t getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole);
        static TrackedControllerRole getControllerRoleForTrackedDeviceIndex(uint32_t index);
        static TrackedDeviceClass getTrackedDeviceClass(uint32_t index);
        static bool isTrackedDeviceConnected(uint32_t index);
        static bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error);
        static const char* getPropErrorNameFromEnum(TrackedPropertyError error);

        static bool pollNextEvent(Event_0_9_15* event, uint32_t bufferSize);
        static bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut);
        static const char* getEventTypeNameFromEnum(EventType type);

        static HiddenAreaMesh getHiddenAreaMesh(Eye eye, HiddenAreaMeshType type);

        static bool getControllerState(uint32_t index, ControllerState* state, uint32_t bufferSize);
        static bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, uint32_t bufferSize, TrackedDevicePose* pose);
        static void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs);
        static const char* getButtonIdNameFromEnum(ButtonId button);
        static const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType);

        static bool captureInputFocus();
        static void releaseInputFocus();
        static bool isInputFocusCapturedByAnotherProcess();

        static uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize);
        static FirmwareError performFirmwareUpdate(uint32_t deviceIndex);

        static void acknowledgeQuit();
        static void acknowledgeQuitPrompt();

        void* getRecommendedRenderTargetSize_ = (void*) getRecommendedRenderTargetSize;
        void* getProjectionMatrix_ = (void*) getProjectionMatrix;
        void* getProjectionRaw_ = (void*) getProjectionRaw;
        void* computeDistortion_ = (void*) computeDistortion;
        void* getEyeToHeadTransform_ = (void*) getEyeToHeadTransform;
        void* getTimeSinceLastVsync_ = (void*) getTimeSinceLastVsync;
        void* getD3D9AdapterIndex_ = (void*) getD3D9AdapterIndex;
        void* getDXGIOutputInfo_ = (void*) getDXGIOutputInfo;
        void* getOutputDevice_ = (void*) getOutputDevice;
        void* isDisplayOnDesktop_ = (void*) isDisplayOnDesktop;
        void* setDisplayVisibility_ = (void*) setDisplayVisibility;
        void* getDeviceToAbsoluteTrackingPose_ = (void*) getDeviceToAbsoluteTrackingPose;
        void* resetSeatedZeroPose_ = (void*) resetSeatedZeroPose;
        void* getSeatedZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getSeatedZeroPoseToStandingAbsoluteTrackingPose;
        void* getRawZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getRawZeroPoseToStandingAbsoluteTrackingPose;
        void* getSortedTrackedDeviceIndicesOfClass_ = (void*) getSortedTrackedDeviceIndicesOfClass;
        void* getTrackedDeviceActivityLevel_ = (void*) getTrackedDeviceActivityLevel;
        void* applyTransform_ = (void*) applyTransform;
        void* getTrackedDeviceIndexForControllerRole_ = (void*) getTrackedDeviceIndexForControllerRole;
        void* getControllerRoleForTrackedDeviceIndex_ = (void*) getControllerRoleForTrackedDeviceIndex;
        void* getTrackedDeviceClass_ = (void*) getTrackedDeviceClass;
        void* isTrackedDeviceConnected_ = (void*) isTrackedDeviceConnected;
        void* getBoolTrackedDeviceProperty_ = (void*) getBoolTrackedDeviceProperty;
        void* getFloatTrackedDeviceProperty_ = (void*) getFloatTrackedDeviceProperty;
        void* getInt32TrackedDeviceProperty_ = (void*) getInt32TrackedDeviceProperty;
        void* getUint64TrackedDeviceProperty_ = (void*) getUint64TrackedDeviceProperty;
        void* getMatrix34TrackedDeviceProperty_ = (void*) getMatrix34TrackedDeviceProperty;
        void* getStringTrackedDeviceProperty_ = (void*) getStringTrackedDeviceProperty;
        void* getPropErrorNameFromEnum_ = (void*) getPropErrorNameFromEnum;
        void* pollNextEvent_ = (void*) pollNextEvent;
        void* pollNextEventWithPose_ = (void*) pollNextEventWithPose;
        void* getEventTypeNameFromEnum_ = (void*) getEventTypeNameFromEnum;
        void* getHiddenAreaMesh_ = (void*) getHiddenAreaMesh;
        void* getControllerState_ = (void*) getControllerState;
        void* getControllerStateWithPose_ = (void*) getControllerStateWithPose;
        void* triggerHapticPulse_ = (void*) triggerHapticPulse;
        void* getButtonIdNameFromEnum_ = (void*) getButtonIdNameFromEnum;
        void* getControllerAxisTypeNameFromEnum_ = (void*) getControllerAxisTypeNameFromEnum;
        void* captureInputFocus_ = (void*) captureInputFocus;
        void* releaseInputFocus_ = (void*) releaseInputFocus;
        void* isInputFocusCapturedByAnotherProcess_ = (void*) isInputFocusCapturedByAnotherProcess;
        void* driverDebugRequest_ = (void*) driverDebugRequest;
        void* performFirmwareUpdate_ = (void*) performFirmwareUpdate;
        void* acknowledgeQuit_ = (void*) acknowledgeQuit;
        void* acknowledgeQuitPrompt_ = (void*) acknowledgeQuitPrompt;
    };

    class System_016_v
    {
        public:
            virtual void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height) { return System_016::getRecommendedRenderTargetSize(width, height); }
            virtual Matrix44 getProjectionMatrix(Eye eye, float near, float far) { return System_016::getProjectionMatrix(eye, near, far); }
            virtual void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom) { return System_016::getProjectionRaw(eye, left, right, top, bottom); }
            virtual bool computeDistortion(Eye eye, float u, float v, DistortionCoordinates* distortionCoordinates) { return System_016::computeDistortion(eye, u, v, distortionCoordinates); }
            virtual Matrix34 getEyeToHeadTransform(Eye eye) { return System_016::getEyeToHeadTransform(eye); }
            virtual bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter) { return System_016::getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter); }
            virtual int32_t getD3D9AdapterIndex() { return System_016::getD3D9AdapterIndex(); }
            virtual void getDXGIOutputInfo(int32_t* adapterIndex) { return System_016::getDXGIOutputInfo(adapterIndex); }
            virtual void getOutputDevice(uint64_t* device, TextureType textureType) { return System_016::getOutputDevice(device, textureType); }
            virtual bool isDisplayOnDesktop() { return System_016::isDisplayOnDesktop(); }
            virtual bool setDisplayVisibility(bool visibleOnDesktop) { return System_016::setDisplayVisibility(visibleOnDesktop); }
            virtual void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount) { return System_016::getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount); }
            virtual void resetSeatedZeroPose() { return System_016::resetSeatedZeroPose(); }
            virtual Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose() { return System_016::getSeatedZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose() { return System_016::getRawZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex) { return System_016::getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex); }
            virtual DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index) { return System_016::getTrackedDeviceActivityLevel(index); }
            virtual void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform) { return System_016::applyTransform(outputPose, trackedDevicePose, transform); }
            virtual uint32_t getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole) { return System_016::getTrackedDeviceIndexForControllerRole(controllerRole); }
            virtual TrackedControllerRole getControllerRoleForTrackedDeviceIndex(uint32_t index) { return System_016::getControllerRoleForTrackedDeviceIndex(index); }
            virtual TrackedDeviceClass getTrackedDeviceClass(uint32_t index) { return System_016::getTrackedDeviceClass(index); }
            virtual bool isTrackedDeviceConnected(uint32_t index) { return System_016::isTrackedDeviceConnected(index); }
            virtual bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_016::getBoolTrackedDeviceProperty(index, property, error); }
            virtual float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_016::getFloatTrackedDeviceProperty(index, property, error); }
            virtual int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_016::getInt32TrackedDeviceProperty(index, property, error); }
            virtual uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_016::getUint64TrackedDeviceProperty(index, property, error); }
            virtual Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_016::getMatrix34TrackedDeviceProperty(index, property, error); }
            virtual uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error) { return System_016::getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error); }
            virtual const char* getPropErrorNameFromEnum(TrackedPropertyError error) { return System_016::getPropErrorNameFromEnum(error); }
            virtual bool pollNextEvent(Event_0_9_15* event, uint32_t bufferSize) { return System_016::pollNextEvent(event, bufferSize); }
            virtual bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut) { return System_016::pollNextEventWithPose(origin, event, bufferSize, trackedDevicePoseOut); }
            virtual const char* getEventTypeNameFromEnum(EventType type) { return System_016::getEventTypeNameFromEnum(type); }
            virtual HiddenAreaMesh getHiddenAreaMesh(Eye eye, HiddenAreaMeshType type) { return System_016::getHiddenAreaMesh(eye, type); }
            virtual bool getControllerState(uint32_t index, ControllerState* state, uint32_t bufferSize) { return System_016::getControllerState(index, state, bufferSize); }
            virtual bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, uint32_t bufferSize, TrackedDevicePose* pose) { return System_016::getControllerStateWithPose(origin, index, state, bufferSize, pose); }
            virtual void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs) { return System_016::triggerHapticPulse(index, axisId, durationUs); }
            virtual const char* getButtonIdNameFromEnum(ButtonId button) { return System_016::getButtonIdNameFromEnum(button); }
            virtual const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType) { return System_016::getControllerAxisTypeNameFromEnum(axisType); }
            virtual bool captureInputFocus() { return System_016::captureInputFocus(); }
            virtual void releaseInputFocus() { return System_016::releaseInputFocus(); }
            virtual bool isInputFocusCapturedByAnotherProcess() { return System_016::isInputFocusCapturedByAnotherProcess(); }
            virtual uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize) { return System_016::driverDebugRequest(deviceIndex, request, response, responseBufferSize); }
            virtual FirmwareError performFirmwareUpdate(uint32_t deviceIndex) { return System_016::performFirmwareUpdate(deviceIndex); }
            virtual void acknowledgeQuit() { return System_016::acknowledgeQuit(); }
            virtual void acknowledgeQuitPrompt() { return System_016::acknowledgeQuitPrompt(); }
    };

    //

    struct System_017
    {
        static void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height);
        static Matrix44 getProjectionMatrix(Eye eye, float near, float far);
        static void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom);
        static bool computeDistortion(Eye eye, float u, float v, DistortionCoordinates* distortionCoordinates);
        static Matrix34 getEyeToHeadTransform(Eye eye);

        static bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter);
        static int32_t getD3D9AdapterIndex();
        static void getDXGIOutputInfo(int32_t* adapterIndex);
        static void getOutputDevice(uint64_t* device, TextureType textureType, VkInstance_T* vkInstance);

        static bool isDisplayOnDesktop();
        static bool setDisplayVisibility(bool visibleOnDesktop);

        static void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount);
        static void resetSeatedZeroPose();
        static Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose();
        static Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose();

        static uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex);

        static DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index);

        static void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform);

        static uint32_t getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole);
        static TrackedControllerRole getControllerRoleForTrackedDeviceIndex(uint32_t index);
        static TrackedDeviceClass getTrackedDeviceClass(uint32_t index);
        static bool isTrackedDeviceConnected(uint32_t index);
        static bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error);
        static const char* getPropErrorNameFromEnum(TrackedPropertyError error);

        static bool pollNextEvent(Event_0_9_15* event, uint32_t bufferSize);
        static bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut);
        static const char* getEventTypeNameFromEnum(EventType type);

        static HiddenAreaMesh getHiddenAreaMesh(Eye eye, HiddenAreaMeshType type);

        static bool getControllerState(uint32_t index, ControllerState* state, uint32_t bufferSize);
        static bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, uint32_t bufferSize, TrackedDevicePose* pose);
        static void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs);
        static const char* getButtonIdNameFromEnum(ButtonId button);
        static const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType);

        static bool captureInputFocus();
        static void releaseInputFocus();
        static bool isInputFocusCapturedByAnotherProcess();

        static uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize);
        static FirmwareError performFirmwareUpdate(uint32_t deviceIndex);

        static void acknowledgeQuit();
        static void acknowledgeQuitPrompt();

        void* getRecommendedRenderTargetSize_ = (void*) getRecommendedRenderTargetSize;
        void* getProjectionMatrix_ = (void*) getProjectionMatrix;
        void* getProjectionRaw_ = (void*) getProjectionRaw;
        void* computeDistortion_ = (void*) computeDistortion;
        void* getEyeToHeadTransform_ = (void*) getEyeToHeadTransform;
        void* getTimeSinceLastVsync_ = (void*) getTimeSinceLastVsync;
        void* getD3D9AdapterIndex_ = (void*) getD3D9AdapterIndex;
        void* getDXGIOutputInfo_ = (void*) getDXGIOutputInfo;
        void* getOutputDevice_ = (void*) getOutputDevice;
        void* isDisplayOnDesktop_ = (void*) isDisplayOnDesktop;
        void* setDisplayVisibility_ = (void*) setDisplayVisibility;
        void* getDeviceToAbsoluteTrackingPose_ = (void*) getDeviceToAbsoluteTrackingPose;
        void* resetSeatedZeroPose_ = (void*) resetSeatedZeroPose;
        void* getSeatedZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getSeatedZeroPoseToStandingAbsoluteTrackingPose;
        void* getRawZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getRawZeroPoseToStandingAbsoluteTrackingPose;
        void* getSortedTrackedDeviceIndicesOfClass_ = (void*) getSortedTrackedDeviceIndicesOfClass;
        void* getTrackedDeviceActivityLevel_ = (void*) getTrackedDeviceActivityLevel;
        void* applyTransform_ = (void*) applyTransform;
        void* getTrackedDeviceIndexForControllerRole_ = (void*) getTrackedDeviceIndexForControllerRole;
        void* getControllerRoleForTrackedDeviceIndex_ = (void*) getControllerRoleForTrackedDeviceIndex;
        void* getTrackedDeviceClass_ = (void*) getTrackedDeviceClass;
        void* isTrackedDeviceConnected_ = (void*) isTrackedDeviceConnected;
        void* getBoolTrackedDeviceProperty_ = (void*) getBoolTrackedDeviceProperty;
        void* getFloatTrackedDeviceProperty_ = (void*) getFloatTrackedDeviceProperty;
        void* getInt32TrackedDeviceProperty_ = (void*) getInt32TrackedDeviceProperty;
        void* getUint64TrackedDeviceProperty_ = (void*) getUint64TrackedDeviceProperty;
        void* getMatrix34TrackedDeviceProperty_ = (void*) getMatrix34TrackedDeviceProperty;
        void* getStringTrackedDeviceProperty_ = (void*) getStringTrackedDeviceProperty;
        void* getPropErrorNameFromEnum_ = (void*) getPropErrorNameFromEnum;
        void* pollNextEvent_ = (void*) pollNextEvent;
        void* pollNextEventWithPose_ = (void*) pollNextEventWithPose;
        void* getEventTypeNameFromEnum_ = (void*) getEventTypeNameFromEnum;
        void* getHiddenAreaMesh_ = (void*) getHiddenAreaMesh;
        void* getControllerState_ = (void*) getControllerState;
        void* getControllerStateWithPose_ = (void*) getControllerStateWithPose;
        void* triggerHapticPulse_ = (void*) triggerHapticPulse;
        void* getButtonIdNameFromEnum_ = (void*) getButtonIdNameFromEnum;
        void* getControllerAxisTypeNameFromEnum_ = (void*) getControllerAxisTypeNameFromEnum;
        void* captureInputFocus_ = (void*) captureInputFocus;
        void* releaseInputFocus_ = (void*) releaseInputFocus;
        void* isInputFocusCapturedByAnotherProcess_ = (void*) isInputFocusCapturedByAnotherProcess;
        void* driverDebugRequest_ = (void*) driverDebugRequest;
        void* performFirmwareUpdate_ = (void*) performFirmwareUpdate;
        void* acknowledgeQuit_ = (void*) acknowledgeQuit;
        void* acknowledgeQuitPrompt_ = (void*) acknowledgeQuitPrompt;
    };

    class System_017_v
    {
        public:
            virtual void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height) { return System_017::getRecommendedRenderTargetSize(width, height); }
            virtual Matrix44 getProjectionMatrix(Eye eye, float near, float far) { return System_017::getProjectionMatrix(eye, near, far); }
            virtual void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom) { return System_017::getProjectionRaw(eye, left, right, top, bottom); }
            virtual bool computeDistortion(Eye eye, float u, float v, DistortionCoordinates* distortionCoordinates) { return System_017::computeDistortion(eye, u, v, distortionCoordinates); }
            virtual Matrix34 getEyeToHeadTransform(Eye eye) { return System_017::getEyeToHeadTransform(eye); }
            virtual bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter) { return System_017::getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter); }
            virtual int32_t getD3D9AdapterIndex() { return System_017::getD3D9AdapterIndex(); }
            virtual void getDXGIOutputInfo(int32_t* adapterIndex) { return System_017::getDXGIOutputInfo(adapterIndex); }
            virtual void getOutputDevice(uint64_t* device, TextureType textureType, VkInstance_T* vkInstance) { return System_017::getOutputDevice(device, textureType, vkInstance); }
            virtual bool isDisplayOnDesktop() { return System_017::isDisplayOnDesktop(); }
            virtual bool setDisplayVisibility(bool visibleOnDesktop) { return System_017::setDisplayVisibility(visibleOnDesktop); }
            virtual void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount) { return System_017::getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount); }
            virtual void resetSeatedZeroPose() { return System_017::resetSeatedZeroPose(); }
            virtual Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose() { return System_017::getSeatedZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose() { return System_017::getRawZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex) { return System_017::getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex); }
            virtual DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index) { return System_017::getTrackedDeviceActivityLevel(index); }
            virtual void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform) { return System_017::applyTransform(outputPose, trackedDevicePose, transform); }
            virtual uint32_t getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole) { return System_017::getTrackedDeviceIndexForControllerRole(controllerRole); }
            virtual TrackedControllerRole getControllerRoleForTrackedDeviceIndex(uint32_t index) { return System_017::getControllerRoleForTrackedDeviceIndex(index); }
            virtual TrackedDeviceClass getTrackedDeviceClass(uint32_t index) { return System_017::getTrackedDeviceClass(index); }
            virtual bool isTrackedDeviceConnected(uint32_t index) { return System_017::isTrackedDeviceConnected(index); }
            virtual bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_017::getBoolTrackedDeviceProperty(index, property, error); }
            virtual float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_017::getFloatTrackedDeviceProperty(index, property, error); }
            virtual int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_017::getInt32TrackedDeviceProperty(index, property, error); }
            virtual uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_017::getUint64TrackedDeviceProperty(index, property, error); }
            virtual Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_017::getMatrix34TrackedDeviceProperty(index, property, error); }
            virtual uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error) { return System_017::getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error); }
            virtual const char* getPropErrorNameFromEnum(TrackedPropertyError error) { return System_017::getPropErrorNameFromEnum(error); }
            virtual bool pollNextEvent(Event_0_9_15* event, uint32_t bufferSize) { return System_017::pollNextEvent(event, bufferSize); }
            virtual bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut) { return System_017::pollNextEventWithPose(origin, event, bufferSize, trackedDevicePoseOut); }
            virtual const char* getEventTypeNameFromEnum(EventType type) { return System_017::getEventTypeNameFromEnum(type); }
            virtual HiddenAreaMesh getHiddenAreaMesh(Eye eye, HiddenAreaMeshType type) { return System_017::getHiddenAreaMesh(eye, type); }
            virtual bool getControllerState(uint32_t index, ControllerState* state, uint32_t bufferSize) { return System_017::getControllerState(index, state, bufferSize); }
            virtual bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, uint32_t bufferSize, TrackedDevicePose* pose) { return System_017::getControllerStateWithPose(origin, index, state, bufferSize, pose); }
            virtual void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs) { return System_017::triggerHapticPulse(index, axisId, durationUs); }
            virtual const char* getButtonIdNameFromEnum(ButtonId button) { return System_017::getButtonIdNameFromEnum(button); }
            virtual const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType) { return System_017::getControllerAxisTypeNameFromEnum(axisType); }
            virtual bool captureInputFocus() { return System_017::captureInputFocus(); }
            virtual void releaseInputFocus() { return System_017::releaseInputFocus(); }
            virtual bool isInputFocusCapturedByAnotherProcess() { return System_017::isInputFocusCapturedByAnotherProcess(); }
            virtual uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize) { return System_017::driverDebugRequest(deviceIndex, request, response, responseBufferSize); }
            virtual FirmwareError performFirmwareUpdate(uint32_t deviceIndex) { return System_017::performFirmwareUpdate(deviceIndex); }
            virtual void acknowledgeQuit() { return System_017::acknowledgeQuit(); }
            virtual void acknowledgeQuitPrompt() { return System_017::acknowledgeQuitPrompt(); }
    };

    //

    struct System_019
    {
        static void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height);
        static Matrix44 getProjectionMatrix(Eye eye, float near, float far);
        static void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom);
        static bool computeDistortion(Eye eye, float u, float v, DistortionCoordinates* distortionCoordinates);
        static Matrix34 getEyeToHeadTransform(Eye eye);

        static bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter);
        static int32_t getD3D9AdapterIndex();
        static void getDXGIOutputInfo(int32_t* adapterIndex);
        static void getOutputDevice(uint64_t* device, TextureType textureType, VkInstance_T* vkInstance);

        static bool isDisplayOnDesktop();
        static bool setDisplayVisibility(bool visibleOnDesktop);

        static void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount);
        static void resetSeatedZeroPose();
        static Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose();
        static Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose();

        static uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex);

        static DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index);

        static void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform);

        static uint32_t getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole);
        static TrackedControllerRole getControllerRoleForTrackedDeviceIndex(uint32_t index);
        static TrackedDeviceClass getTrackedDeviceClass(uint32_t index);
        static bool isTrackedDeviceConnected(uint32_t index);
        static bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint32_t getArrayTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedDevicePropertyType type, void* buffer, uint32_t bufferSize, TrackedPropertyError* error);
        static uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error);
        static const char* getPropErrorNameFromEnum(TrackedPropertyError error);

        static bool pollNextEvent(Event_0_9_15* event, uint32_t bufferSize);
        static bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut);
        static const char* getEventTypeNameFromEnum(EventType type);

        static HiddenAreaMesh getHiddenAreaMesh(Eye eye, HiddenAreaMeshType type);

        static bool getControllerState(uint32_t index, ControllerState* state, uint32_t bufferSize);
        static bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, uint32_t bufferSize, TrackedDevicePose* pose);
        static void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs);
        static const char* getButtonIdNameFromEnum(ButtonId button);
        static const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType);

        static bool isInputAvailable();
        static bool isSteamVRDrawingControllers();
        static bool shouldApplicationPause();
        static bool shouldApplicationReduceRenderingWork();

        static uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize);
        static FirmwareError performFirmwareUpdate(uint32_t deviceIndex);

        static void acknowledgeQuit();
        static void acknowledgeQuitPrompt();

        void* getRecommendedRenderTargetSize_ = (void*) getRecommendedRenderTargetSize;
        void* getProjectionMatrix_ = (void*) getProjectionMatrix;
        void* getProjectionRaw_ = (void*) getProjectionRaw;
        void* computeDistortion_ = (void*) computeDistortion;
        void* getEyeToHeadTransform_ = (void*) getEyeToHeadTransform;
        void* getTimeSinceLastVsync_ = (void*) getTimeSinceLastVsync;
        void* getD3D9AdapterIndex_ = (void*) getD3D9AdapterIndex;
        void* getDXGIOutputInfo_ = (void*) getDXGIOutputInfo;
        void* getOutputDevice_ = (void*) getOutputDevice;
        void* isDisplayOnDesktop_ = (void*) isDisplayOnDesktop;
        void* setDisplayVisibility_ = (void*) setDisplayVisibility;
        void* getDeviceToAbsoluteTrackingPose_ = (void*) getDeviceToAbsoluteTrackingPose;
        void* resetSeatedZeroPose_ = (void*) resetSeatedZeroPose;
        void* getSeatedZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getSeatedZeroPoseToStandingAbsoluteTrackingPose;
        void* getRawZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getRawZeroPoseToStandingAbsoluteTrackingPose;
        void* getSortedTrackedDeviceIndicesOfClass_ = (void*) getSortedTrackedDeviceIndicesOfClass;
        void* getTrackedDeviceActivityLevel_ = (void*) getTrackedDeviceActivityLevel;
        void* applyTransform_ = (void*) applyTransform;
        void* getTrackedDeviceIndexForControllerRole_ = (void*) getTrackedDeviceIndexForControllerRole;
        void* getControllerRoleForTrackedDeviceIndex_ = (void*) getControllerRoleForTrackedDeviceIndex;
        void* getTrackedDeviceClass_ = (void*) getTrackedDeviceClass;
        void* isTrackedDeviceConnected_ = (void*) isTrackedDeviceConnected;
        void* getBoolTrackedDeviceProperty_ = (void*) getBoolTrackedDeviceProperty;
        void* getFloatTrackedDeviceProperty_ = (void*) getFloatTrackedDeviceProperty;
        void* getInt32TrackedDeviceProperty_ = (void*) getInt32TrackedDeviceProperty;
        void* getUint64TrackedDeviceProperty_ = (void*) getUint64TrackedDeviceProperty;
        void* getMatrix34TrackedDeviceProperty_ = (void*) getMatrix34TrackedDeviceProperty;
        void* getArrayTrackedDeviceProperty_ = (void*) getArrayTrackedDeviceProperty;
        void* getStringTrackedDeviceProperty_ = (void*) getStringTrackedDeviceProperty;
        void* getPropErrorNameFromEnum_ = (void*) getPropErrorNameFromEnum;
        void* pollNextEvent_ = (void*) pollNextEvent;
        void* pollNextEventWithPose_ = (void*) pollNextEventWithPose;
        void* getEventTypeNameFromEnum_ = (void*) getEventTypeNameFromEnum;
        void* getHiddenAreaMesh_ = (void*) getHiddenAreaMesh;
        void* getControllerState_ = (void*) getControllerState;
        void* getControllerStateWithPose_ = (void*) getControllerStateWithPose;
        void* triggerHapticPulse_ = (void*) triggerHapticPulse;
        void* getButtonIdNameFromEnum_ = (void*) getButtonIdNameFromEnum;
        void* getControllerAxisTypeNameFromEnum_ = (void*) getControllerAxisTypeNameFromEnum;
        void* isInputAvailable_ = (void*) isInputAvailable;
        void* isSteamVRDrawingControllers_ = (void*) isSteamVRDrawingControllers;
        void* shouldApplicationPause_ = (void*) shouldApplicationPause;
        void* shouldApplicationReduceRenderingWork_ = (void*) shouldApplicationReduceRenderingWork;
        void* driverDebugRequest_ = (void*) driverDebugRequest;
        void* performFirmwareUpdate_ = (void*) performFirmwareUpdate;
        void* acknowledgeQuit_ = (void*) acknowledgeQuit;
        void* acknowledgeQuitPrompt_ = (void*) acknowledgeQuitPrompt;
    };

    class System_019_v
    {
        public:
            virtual void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height) { return System_019::getRecommendedRenderTargetSize(width, height); }
            virtual Matrix44 getProjectionMatrix(Eye eye, float near, float far) { return System_019::getProjectionMatrix(eye, near, far); }
            virtual void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom) { return System_019::getProjectionRaw(eye, left, right, top, bottom); }
            virtual bool computeDistortion(Eye eye, float u, float v, DistortionCoordinates* distortionCoordinates) { return System_019::computeDistortion(eye, u, v, distortionCoordinates); }
            virtual Matrix34 getEyeToHeadTransform(Eye eye) { return System_019::getEyeToHeadTransform(eye); }
            virtual bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter) { return System_019::getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter); }
            virtual int32_t getD3D9AdapterIndex() { return System_019::getD3D9AdapterIndex(); }
            virtual void getDXGIOutputInfo(int32_t* adapterIndex) { return System_019::getDXGIOutputInfo(adapterIndex); }
            virtual void getOutputDevice(uint64_t* device, TextureType textureType, VkInstance_T* vkInstance) { return System_019::getOutputDevice(device, textureType, vkInstance); }
            virtual bool isDisplayOnDesktop() { return System_019::isDisplayOnDesktop(); }
            virtual bool setDisplayVisibility(bool visibleOnDesktop) { return System_019::setDisplayVisibility(visibleOnDesktop); }
            virtual void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount) { return System_019::getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount); }
            virtual void resetSeatedZeroPose() { return System_019::resetSeatedZeroPose(); }
            virtual Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose() { return System_019::getSeatedZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose() { return System_019::getRawZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex) { return System_019::getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex); }
            virtual DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index) { return System_019::getTrackedDeviceActivityLevel(index); }
            virtual void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform) { return System_019::applyTransform(outputPose, trackedDevicePose, transform); }
            virtual uint32_t getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole) { return System_019::getTrackedDeviceIndexForControllerRole(controllerRole); }
            virtual TrackedControllerRole getControllerRoleForTrackedDeviceIndex(uint32_t index) { return System_019::getControllerRoleForTrackedDeviceIndex(index); }
            virtual TrackedDeviceClass getTrackedDeviceClass(uint32_t index) { return System_019::getTrackedDeviceClass(index); }
            virtual bool isTrackedDeviceConnected(uint32_t index) { return System_019::isTrackedDeviceConnected(index); }
            virtual bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_019::getBoolTrackedDeviceProperty(index, property, error); }
            virtual float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_019::getFloatTrackedDeviceProperty(index, property, error); }
            virtual int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_019::getInt32TrackedDeviceProperty(index, property, error); }
            virtual uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_019::getUint64TrackedDeviceProperty(index, property, error); }
            virtual Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_019::getMatrix34TrackedDeviceProperty(index, property, error); }
            virtual uint32_t getArrayTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedDevicePropertyType type, void* buffer, uint32_t bufferSize, TrackedPropertyError* error) { return System_019::getArrayTrackedDeviceProperty(index, property, type, buffer, bufferSize, error); }
            virtual uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error) { return System_019::getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error); }
            virtual const char* getPropErrorNameFromEnum(TrackedPropertyError error) { return System_019::getPropErrorNameFromEnum(error); }
            virtual bool pollNextEvent(Event_0_9_15* event, uint32_t bufferSize) { return System_019::pollNextEvent(event, bufferSize); }
            virtual bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut) { return System_019::pollNextEventWithPose(origin, event, bufferSize, trackedDevicePoseOut); }
            virtual const char* getEventTypeNameFromEnum(EventType type) { return System_019::getEventTypeNameFromEnum(type); }
            virtual HiddenAreaMesh getHiddenAreaMesh(Eye eye, HiddenAreaMeshType type) { return System_019::getHiddenAreaMesh(eye, type); }
            virtual bool getControllerState(uint32_t index, ControllerState* state, uint32_t bufferSize) { return System_019::getControllerState(index, state, bufferSize); }
            virtual bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, uint32_t bufferSize, TrackedDevicePose* pose) { return System_019::getControllerStateWithPose(origin, index, state, bufferSize, pose); }
            virtual void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs) { return System_019::triggerHapticPulse(index, axisId, durationUs); }
            virtual const char* getButtonIdNameFromEnum(ButtonId button) { return System_019::getButtonIdNameFromEnum(button); }
            virtual const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType) { return System_019::getControllerAxisTypeNameFromEnum(axisType); }
            virtual bool isInputAvailable() { return System_019::isInputAvailable(); }
            virtual bool isSteamVRDrawingControllers() { return System_019::isSteamVRDrawingControllers(); }
            virtual bool shouldApplicationPause() { return System_019::shouldApplicationPause(); }
            virtual bool shouldApplicationReduceRenderingWork() { return System_019::shouldApplicationReduceRenderingWork(); }
            virtual uint32_t driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize) { return System_019::driverDebugRequest(deviceIndex, request, response, responseBufferSize); }
            virtual FirmwareError performFirmwareUpdate(uint32_t deviceIndex) { return System_019::performFirmwareUpdate(deviceIndex); }
            virtual void acknowledgeQuit() { return System_019::acknowledgeQuit(); }
            virtual void acknowledgeQuitPrompt() { return System_019::acknowledgeQuitPrompt(); }
    };

    //

    struct System_020
    {
        static void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height);
        static Matrix44 getProjectionMatrix(Eye eye, float near, float far);
        static void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom);
        static bool computeDistortion(Eye eye, float u, float v, DistortionCoordinates* distortionCoordinates);
        static Matrix34 getEyeToHeadTransform(Eye eye);

        static bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter);
        static int32_t getD3D9AdapterIndex();
        static void getDXGIOutputInfo(int32_t* adapterIndex);
        static void getOutputDevice(uint64_t* device, TextureType textureType, VkInstance_T* vkInstance);

        static bool isDisplayOnDesktop();
        static bool setDisplayVisibility(bool visibleOnDesktop);

        static void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount);
        static void resetSeatedZeroPose();
        static Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose();
        static Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose();

        static uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex);

        static DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index);

        static void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform);

        static uint32_t getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole);
        static TrackedControllerRole getControllerRoleForTrackedDeviceIndex(uint32_t index);
        static TrackedDeviceClass getTrackedDeviceClass(uint32_t index);
        static bool isTrackedDeviceConnected(uint32_t index);
        static bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint32_t getArrayTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedDevicePropertyType type, void* buffer, uint32_t bufferSize, TrackedPropertyError* error);
        static uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error);
        static const char* getPropErrorNameFromEnum(TrackedPropertyError error);

        static bool pollNextEvent(Event_0_9_15* event, uint32_t bufferSize);
        static bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut);
        static const char* getEventTypeNameFromEnum(EventType type);

        static HiddenAreaMesh getHiddenAreaMesh(Eye eye, HiddenAreaMeshType type);

        static bool getControllerState(uint32_t index, ControllerState* state, uint32_t bufferSize);
        static bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, uint32_t bufferSize, TrackedDevicePose* pose);
        static void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs);
        static const char* getButtonIdNameFromEnum(ButtonId button);
        static const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType);

        static bool isInputAvailable();
        static bool isSteamVRDrawingControllers();
        static bool shouldApplicationPause();
        static bool shouldApplicationReduceRenderingWork();

        static FirmwareError performFirmwareUpdate(uint32_t deviceIndex);

        static void acknowledgeQuit();
        static void acknowledgeQuitPrompt();

        static uint32_t getAppContainerFilePaths(char* buffer, uint32_t bufferSize);

        static const char* getRuntimeVersion();

        void* getRecommendedRenderTargetSize_ = (void*) getRecommendedRenderTargetSize;
        void* getProjectionMatrix_ = (void*) getProjectionMatrix;
        void* getProjectionRaw_ = (void*) getProjectionRaw;
        void* computeDistortion_ = (void*) computeDistortion;
        void* getEyeToHeadTransform_ = (void*) getEyeToHeadTransform;
        void* getTimeSinceLastVsync_ = (void*) getTimeSinceLastVsync;
        void* getD3D9AdapterIndex_ = (void*) getD3D9AdapterIndex;
        void* getDXGIOutputInfo_ = (void*) getDXGIOutputInfo;
        void* getOutputDevice_ = (void*) getOutputDevice;
        void* isDisplayOnDesktop_ = (void*) isDisplayOnDesktop;
        void* setDisplayVisibility_ = (void*) setDisplayVisibility;
        void* getDeviceToAbsoluteTrackingPose_ = (void*) getDeviceToAbsoluteTrackingPose;
        void* resetSeatedZeroPose_ = (void*) resetSeatedZeroPose;
        void* getSeatedZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getSeatedZeroPoseToStandingAbsoluteTrackingPose;
        void* getRawZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getRawZeroPoseToStandingAbsoluteTrackingPose;
        void* getSortedTrackedDeviceIndicesOfClass_ = (void*) getSortedTrackedDeviceIndicesOfClass;
        void* getTrackedDeviceActivityLevel_ = (void*) getTrackedDeviceActivityLevel;
        void* applyTransform_ = (void*) applyTransform;
        void* getTrackedDeviceIndexForControllerRole_ = (void*) getTrackedDeviceIndexForControllerRole;
        void* getControllerRoleForTrackedDeviceIndex_ = (void*) getControllerRoleForTrackedDeviceIndex;
        void* getTrackedDeviceClass_ = (void*) getTrackedDeviceClass;
        void* isTrackedDeviceConnected_ = (void*) isTrackedDeviceConnected;
        void* getBoolTrackedDeviceProperty_ = (void*) getBoolTrackedDeviceProperty;
        void* getFloatTrackedDeviceProperty_ = (void*) getFloatTrackedDeviceProperty;
        void* getInt32TrackedDeviceProperty_ = (void*) getInt32TrackedDeviceProperty;
        void* getUint64TrackedDeviceProperty_ = (void*) getUint64TrackedDeviceProperty;
        void* getMatrix34TrackedDeviceProperty_ = (void*) getMatrix34TrackedDeviceProperty;
        void* getArrayTrackedDeviceProperty_ = (void*) getArrayTrackedDeviceProperty;
        void* getStringTrackedDeviceProperty_ = (void*) getStringTrackedDeviceProperty;
        void* getPropErrorNameFromEnum_ = (void*) getPropErrorNameFromEnum;
        void* pollNextEvent_ = (void*) pollNextEvent;
        void* pollNextEventWithPose_ = (void*) pollNextEventWithPose;
        void* getEventTypeNameFromEnum_ = (void*) getEventTypeNameFromEnum;
        void* getHiddenAreaMesh_ = (void*) getHiddenAreaMesh;
        void* getControllerState_ = (void*) getControllerState;
        void* getControllerStateWithPose_ = (void*) getControllerStateWithPose;
        void* triggerHapticPulse_ = (void*) triggerHapticPulse;
        void* getButtonIdNameFromEnum_ = (void*) getButtonIdNameFromEnum;
        void* getControllerAxisTypeNameFromEnum_ = (void*) getControllerAxisTypeNameFromEnum;
        void* isInputAvailable_ = (void*) isInputAvailable;
        void* isSteamVRDrawingControllers_ = (void*) isSteamVRDrawingControllers;
        void* shouldApplicationPause_ = (void*) shouldApplicationPause;
        void* shouldApplicationReduceRenderingWork_ = (void*) shouldApplicationReduceRenderingWork;
        void* performFirmwareUpdate_ = (void*) performFirmwareUpdate;
        void* acknowledgeQuit_ = (void*) acknowledgeQuit;
        void* acknowledgeQuitPrompt_ = (void*) acknowledgeQuitPrompt;
        void* getAppContainerFilePaths_ = (void*) getAppContainerFilePaths;
        void* getRuntimeVersion_ = (void*) getRuntimeVersion;
    };

    class System_020_v
    {
        public:
            virtual void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height) { return System_020::getRecommendedRenderTargetSize(width, height); }
            virtual Matrix44 getProjectionMatrix(Eye eye, float near, float far) { return System_020::getProjectionMatrix(eye, near, far); }
            virtual void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom) { return System_020::getProjectionRaw(eye, left, right, top, bottom); }
            virtual bool computeDistortion(Eye eye, float u, float v, DistortionCoordinates* distortionCoordinates) { return System_020::computeDistortion(eye, u, v, distortionCoordinates); }
            virtual Matrix34 getEyeToHeadTransform(Eye eye) { return System_020::getEyeToHeadTransform(eye); }
            virtual bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter) { return System_020::getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter); }
            virtual int32_t getD3D9AdapterIndex() { return System_020::getD3D9AdapterIndex(); }
            virtual void getDXGIOutputInfo(int32_t* adapterIndex) { return System_020::getDXGIOutputInfo(adapterIndex); }
            virtual void getOutputDevice(uint64_t* device, TextureType textureType, VkInstance_T* vkInstance) { return System_020::getOutputDevice(device, textureType, vkInstance); }
            virtual bool isDisplayOnDesktop() { return System_020::isDisplayOnDesktop(); }
            virtual bool setDisplayVisibility(bool visibleOnDesktop) { return System_020::setDisplayVisibility(visibleOnDesktop); }
            virtual void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount) { return System_020::getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount); }
            virtual void resetSeatedZeroPose() { return System_020::resetSeatedZeroPose(); }
            virtual Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose() { return System_020::getSeatedZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose() { return System_020::getRawZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex) { return System_020::getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex); }
            virtual DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index) { return System_020::getTrackedDeviceActivityLevel(index); }
            virtual void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform) { return System_020::applyTransform(outputPose, trackedDevicePose, transform); }
            virtual uint32_t getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole) { return System_020::getTrackedDeviceIndexForControllerRole(controllerRole); }
            virtual TrackedControllerRole getControllerRoleForTrackedDeviceIndex(uint32_t index) { return System_020::getControllerRoleForTrackedDeviceIndex(index); }
            virtual TrackedDeviceClass getTrackedDeviceClass(uint32_t index) { return System_020::getTrackedDeviceClass(index); }
            virtual bool isTrackedDeviceConnected(uint32_t index) { return System_020::isTrackedDeviceConnected(index); }
            virtual bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_020::getBoolTrackedDeviceProperty(index, property, error); }
            virtual float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_020::getFloatTrackedDeviceProperty(index, property, error); }
            virtual int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_020::getInt32TrackedDeviceProperty(index, property, error); }
            virtual uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_020::getUint64TrackedDeviceProperty(index, property, error); }
            virtual Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_020::getMatrix34TrackedDeviceProperty(index, property, error); }
            virtual uint32_t getArrayTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedDevicePropertyType type, void* buffer, uint32_t bufferSize, TrackedPropertyError* error) { return System_020::getArrayTrackedDeviceProperty(index, property, type, buffer, bufferSize, error); }
            virtual uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error) { return System_020::getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error); }
            virtual const char* getPropErrorNameFromEnum(TrackedPropertyError error) { return System_020::getPropErrorNameFromEnum(error); }
            virtual bool pollNextEvent(Event_0_9_15* event, uint32_t bufferSize) { return System_020::pollNextEvent(event, bufferSize); }
            virtual bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut) { return System_020::pollNextEventWithPose(origin, event, bufferSize, trackedDevicePoseOut); }
            virtual const char* getEventTypeNameFromEnum(EventType type) { return System_020::getEventTypeNameFromEnum(type); }
            virtual HiddenAreaMesh getHiddenAreaMesh(Eye eye, HiddenAreaMeshType type) { return System_020::getHiddenAreaMesh(eye, type); }
            virtual bool getControllerState(uint32_t index, ControllerState* state, uint32_t bufferSize) { return System_020::getControllerState(index, state, bufferSize); }
            virtual bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, uint32_t bufferSize, TrackedDevicePose* pose) { return System_020::getControllerStateWithPose(origin, index, state, bufferSize, pose); }
            virtual void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs) { return System_020::triggerHapticPulse(index, axisId, durationUs); }
            virtual const char* getButtonIdNameFromEnum(ButtonId button) { return System_020::getButtonIdNameFromEnum(button); }
            virtual const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType) { return System_020::getControllerAxisTypeNameFromEnum(axisType); }
            virtual bool isInputAvailable() { return System_020::isInputAvailable(); }
            virtual bool isSteamVRDrawingControllers() { return System_020::isSteamVRDrawingControllers(); }
            virtual bool shouldApplicationPause() { return System_020::shouldApplicationPause(); }
            virtual bool shouldApplicationReduceRenderingWork() { return System_020::shouldApplicationReduceRenderingWork(); }
            virtual FirmwareError performFirmwareUpdate(uint32_t deviceIndex) { return System_020::performFirmwareUpdate(deviceIndex); }
            virtual void acknowledgeQuit() { return System_020::acknowledgeQuit(); }
            virtual void acknowledgeQuitPrompt() { return System_020::acknowledgeQuitPrompt(); }
            virtual uint32_t getAppContainerFilePaths(char* buffer, uint32_t bufferSize) { return System_020::getAppContainerFilePaths(buffer, bufferSize); }
            virtual const char* getRuntimeVersion() { return System_020::getRuntimeVersion(); }
    };

    //

    struct System_021
    {
        static void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height);
        static Matrix44 getProjectionMatrix(Eye eye, float near, float far);
        static void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom);
        static bool computeDistortion(Eye eye, float u, float v, DistortionCoordinates* distortionCoordinates);
        static Matrix34 getEyeToHeadTransform(Eye eye);

        static bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter);
        static int32_t getD3D9AdapterIndex();
        static void getDXGIOutputInfo(int32_t* adapterIndex);
        static void getOutputDevice(uint64_t* device, TextureType textureType, VkInstance_T* vkInstance);

        static bool isDisplayOnDesktop();
        static bool setDisplayVisibility(bool visibleOnDesktop);

        static void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount);
        static void resetSeatedZeroPose();
        static Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose();
        static Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose();

        static uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex);

        static DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index);

        static void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform);

        static uint32_t getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole);
        static TrackedControllerRole getControllerRoleForTrackedDeviceIndex(uint32_t index);
        static TrackedDeviceClass getTrackedDeviceClass(uint32_t index);
        static bool isTrackedDeviceConnected(uint32_t index);
        static bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint32_t getArrayTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedDevicePropertyType type, void* buffer, uint32_t bufferSize, TrackedPropertyError* error);
        static uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error);
        static const char* getPropErrorNameFromEnum(TrackedPropertyError error);

        static bool pollNextEvent(Event_0_9_15* event, uint32_t bufferSize);
        static bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut);
        static const char* getEventTypeNameFromEnum(EventType type);

        static HiddenAreaMesh getHiddenAreaMesh(Eye eye, HiddenAreaMeshType type);

        static bool getControllerState(uint32_t index, ControllerState* state, uint32_t bufferSize);
        static bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, uint32_t bufferSize, TrackedDevicePose* pose);
        static void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs);
        static const char* getButtonIdNameFromEnum(ButtonId button);
        static const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType);

        static bool isInputAvailable();
        static bool isSteamVRDrawingControllers();
        static bool shouldApplicationPause();
        static bool shouldApplicationReduceRenderingWork();

        static FirmwareError performFirmwareUpdate(uint32_t deviceIndex);

        static void acknowledgeQuit();

        static uint32_t getAppContainerFilePaths(char* buffer, uint32_t bufferSize);

        static const char* getRuntimeVersion();

        void* getRecommendedRenderTargetSize_ = (void*) getRecommendedRenderTargetSize;
        void* getProjectionMatrix_ = (void*) getProjectionMatrix;
        void* getProjectionRaw_ = (void*) getProjectionRaw;
        void* computeDistortion_ = (void*) computeDistortion;
        void* getEyeToHeadTransform_ = (void*) getEyeToHeadTransform;
        void* getTimeSinceLastVsync_ = (void*) getTimeSinceLastVsync;
        void* getD3D9AdapterIndex_ = (void*) getD3D9AdapterIndex;
        void* getDXGIOutputInfo_ = (void*) getDXGIOutputInfo;
        void* getOutputDevice_ = (void*) getOutputDevice;
        void* isDisplayOnDesktop_ = (void*) isDisplayOnDesktop;
        void* setDisplayVisibility_ = (void*) setDisplayVisibility;
        void* getDeviceToAbsoluteTrackingPose_ = (void*) getDeviceToAbsoluteTrackingPose;
        void* resetSeatedZeroPose_ = (void*) resetSeatedZeroPose;
        void* getSeatedZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getSeatedZeroPoseToStandingAbsoluteTrackingPose;
        void* getRawZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getRawZeroPoseToStandingAbsoluteTrackingPose;
        void* getSortedTrackedDeviceIndicesOfClass_ = (void*) getSortedTrackedDeviceIndicesOfClass;
        void* getTrackedDeviceActivityLevel_ = (void*) getTrackedDeviceActivityLevel;
        void* applyTransform_ = (void*) applyTransform;
        void* getTrackedDeviceIndexForControllerRole_ = (void*) getTrackedDeviceIndexForControllerRole;
        void* getControllerRoleForTrackedDeviceIndex_ = (void*) getControllerRoleForTrackedDeviceIndex;
        void* getTrackedDeviceClass_ = (void*) getTrackedDeviceClass;
        void* isTrackedDeviceConnected_ = (void*) isTrackedDeviceConnected;
        void* getBoolTrackedDeviceProperty_ = (void*) getBoolTrackedDeviceProperty;
        void* getFloatTrackedDeviceProperty_ = (void*) getFloatTrackedDeviceProperty;
        void* getInt32TrackedDeviceProperty_ = (void*) getInt32TrackedDeviceProperty;
        void* getUint64TrackedDeviceProperty_ = (void*) getUint64TrackedDeviceProperty;
        void* getMatrix34TrackedDeviceProperty_ = (void*) getMatrix34TrackedDeviceProperty;
        void* getArrayTrackedDeviceProperty_ = (void*) getArrayTrackedDeviceProperty;
        void* getStringTrackedDeviceProperty_ = (void*) getStringTrackedDeviceProperty;
        void* getPropErrorNameFromEnum_ = (void*) getPropErrorNameFromEnum;
        void* pollNextEvent_ = (void*) pollNextEvent;
        void* pollNextEventWithPose_ = (void*) pollNextEventWithPose;
        void* getEventTypeNameFromEnum_ = (void*) getEventTypeNameFromEnum;
        void* getHiddenAreaMesh_ = (void*) getHiddenAreaMesh;
        void* getControllerState_ = (void*) getControllerState;
        void* getControllerStateWithPose_ = (void*) getControllerStateWithPose;
        void* triggerHapticPulse_ = (void*) triggerHapticPulse;
        void* getButtonIdNameFromEnum_ = (void*) getButtonIdNameFromEnum;
        void* getControllerAxisTypeNameFromEnum_ = (void*) getControllerAxisTypeNameFromEnum;
        void* isInputAvailable_ = (void*) isInputAvailable;
        void* isSteamVRDrawingControllers_ = (void*) isSteamVRDrawingControllers;
        void* shouldApplicationPause_ = (void*) shouldApplicationPause;
        void* shouldApplicationReduceRenderingWork_ = (void*) shouldApplicationReduceRenderingWork;
        void* performFirmwareUpdate_ = (void*) performFirmwareUpdate;
        void* acknowledgeQuit_ = (void*) acknowledgeQuit;
        void* getAppContainerFilePaths_ = (void*) getAppContainerFilePaths;
        void* getRuntimeVersion_ = (void*) getRuntimeVersion;
    };

    class System_021_v
    {
        public:
            virtual void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height) { return System_021::getRecommendedRenderTargetSize(width, height); }
            virtual Matrix44 getProjectionMatrix(Eye eye, float near, float far) { return System_021::getProjectionMatrix(eye, near, far); }
            virtual void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom) { return System_021::getProjectionRaw(eye, left, right, top, bottom); }
            virtual bool computeDistortion(Eye eye, float u, float v, DistortionCoordinates* distortionCoordinates) { return System_021::computeDistortion(eye, u, v, distortionCoordinates); }
            virtual Matrix34 getEyeToHeadTransform(Eye eye) { return System_021::getEyeToHeadTransform(eye); }
            virtual bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter) { return System_021::getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter); }
            virtual int32_t getD3D9AdapterIndex() { return System_021::getD3D9AdapterIndex(); }
            virtual void getDXGIOutputInfo(int32_t* adapterIndex) { return System_021::getDXGIOutputInfo(adapterIndex); }
            virtual void getOutputDevice(uint64_t* device, TextureType textureType, VkInstance_T* vkInstance) { return System_021::getOutputDevice(device, textureType, vkInstance); }
            virtual bool isDisplayOnDesktop() { return System_021::isDisplayOnDesktop(); }
            virtual bool setDisplayVisibility(bool visibleOnDesktop) { return System_021::setDisplayVisibility(visibleOnDesktop); }
            virtual void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount) { return System_021::getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount); }
            virtual void resetSeatedZeroPose() { return System_021::resetSeatedZeroPose(); }
            virtual Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose() { return System_021::getSeatedZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose() { return System_021::getRawZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex) { return System_021::getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex); }
            virtual DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index) { return System_021::getTrackedDeviceActivityLevel(index); }
            virtual void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform) { return System_021::applyTransform(outputPose, trackedDevicePose, transform); }
            virtual uint32_t getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole) { return System_021::getTrackedDeviceIndexForControllerRole(controllerRole); }
            virtual TrackedControllerRole getControllerRoleForTrackedDeviceIndex(uint32_t index) { return System_021::getControllerRoleForTrackedDeviceIndex(index); }
            virtual TrackedDeviceClass getTrackedDeviceClass(uint32_t index) { return System_021::getTrackedDeviceClass(index); }
            virtual bool isTrackedDeviceConnected(uint32_t index) { return System_021::isTrackedDeviceConnected(index); }
            virtual bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_021::getBoolTrackedDeviceProperty(index, property, error); }
            virtual float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_021::getFloatTrackedDeviceProperty(index, property, error); }
            virtual int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_021::getInt32TrackedDeviceProperty(index, property, error); }
            virtual uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_021::getUint64TrackedDeviceProperty(index, property, error); }
            virtual Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_021::getMatrix34TrackedDeviceProperty(index, property, error); }
            virtual uint32_t getArrayTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedDevicePropertyType type, void* buffer, uint32_t bufferSize, TrackedPropertyError* error) { return System_021::getArrayTrackedDeviceProperty(index, property, type, buffer, bufferSize, error); }
            virtual uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error) { return System_021::getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error); }
            virtual const char* getPropErrorNameFromEnum(TrackedPropertyError error) { return System_021::getPropErrorNameFromEnum(error); }
            virtual bool pollNextEvent(Event_0_9_15* event, uint32_t bufferSize) { return System_021::pollNextEvent(event, bufferSize); }
            virtual bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut) { return System_021::pollNextEventWithPose(origin, event, bufferSize, trackedDevicePoseOut); }
            virtual const char* getEventTypeNameFromEnum(EventType type) { return System_021::getEventTypeNameFromEnum(type); }
            virtual HiddenAreaMesh getHiddenAreaMesh(Eye eye, HiddenAreaMeshType type) { return System_021::getHiddenAreaMesh(eye, type); }
            virtual bool getControllerState(uint32_t index, ControllerState* state, uint32_t bufferSize) { return System_021::getControllerState(index, state, bufferSize); }
            virtual bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, uint32_t bufferSize, TrackedDevicePose* pose) { return System_021::getControllerStateWithPose(origin, index, state, bufferSize, pose); }
            virtual void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs) { return System_021::triggerHapticPulse(index, axisId, durationUs); }
            virtual const char* getButtonIdNameFromEnum(ButtonId button) { return System_021::getButtonIdNameFromEnum(button); }
            virtual const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType) { return System_021::getControllerAxisTypeNameFromEnum(axisType); }
            virtual bool isInputAvailable() { return System_021::isInputAvailable(); }
            virtual bool isSteamVRDrawingControllers() { return System_021::isSteamVRDrawingControllers(); }
            virtual bool shouldApplicationPause() { return System_021::shouldApplicationPause(); }
            virtual bool shouldApplicationReduceRenderingWork() { return System_021::shouldApplicationReduceRenderingWork(); }
            virtual FirmwareError performFirmwareUpdate(uint32_t deviceIndex) { return System_021::performFirmwareUpdate(deviceIndex); }
            virtual void acknowledgeQuit() { return System_021::acknowledgeQuit(); }
            virtual uint32_t getAppContainerFilePaths(char* buffer, uint32_t bufferSize) { return System_021::getAppContainerFilePaths(buffer, bufferSize); }
            virtual const char* getRuntimeVersion() { return System_021::getRuntimeVersion(); }
    };

    //

    struct System_022
    {
        static void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height);
        static Matrix44 getProjectionMatrix(Eye eye, float near, float far);
        static void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom);
        static bool computeDistortion(Eye eye, float u, float v, DistortionCoordinates* distortionCoordinates);
        static Matrix34 getEyeToHeadTransform(Eye eye);

        static bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter);
        static int32_t getD3D9AdapterIndex();
        static void getDXGIOutputInfo(int32_t* adapterIndex);
        static void getOutputDevice(uint64_t* device, TextureType textureType, VkInstance_T* vkInstance);

        static bool isDisplayOnDesktop();
        static bool setDisplayVisibility(bool visibleOnDesktop);

        static void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount);
        static Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose();
        static Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose();

        static uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex);

        static DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index);

        static void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform);

        static uint32_t getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole);
        static TrackedControllerRole getControllerRoleForTrackedDeviceIndex(uint32_t index);
        static TrackedDeviceClass getTrackedDeviceClass(uint32_t index);
        static bool isTrackedDeviceConnected(uint32_t index);
        static bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
        static uint32_t getArrayTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedDevicePropertyType type, void* buffer, uint32_t bufferSize, TrackedPropertyError* error);
        static uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error);
        static const char* getPropErrorNameFromEnum(TrackedPropertyError error);

        static bool pollNextEvent(Event_0_9_15* event, uint32_t bufferSize);
        static bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut);
        static const char* getEventTypeNameFromEnum(EventType type);

        static HiddenAreaMesh getHiddenAreaMesh(Eye eye, HiddenAreaMeshType type);

        static bool getControllerState(uint32_t index, ControllerState* state, uint32_t bufferSize);
        static bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, uint32_t bufferSize, TrackedDevicePose* pose);
        static void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs);
        static const char* getButtonIdNameFromEnum(ButtonId button);
        static const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType);

        static bool isInputAvailable();
        static bool isSteamVRDrawingControllers();
        static bool shouldApplicationPause();
        static bool shouldApplicationReduceRenderingWork();

        static FirmwareError performFirmwareUpdate(uint32_t deviceIndex);

        static void acknowledgeQuit();

        static uint32_t getAppContainerFilePaths(char* buffer, uint32_t bufferSize);

        static const char* getRuntimeVersion();

        void* getRecommendedRenderTargetSize_ = (void*) getRecommendedRenderTargetSize;
        void* getProjectionMatrix_ = (void*) getProjectionMatrix;
        void* getProjectionRaw_ = (void*) getProjectionRaw;
        void* computeDistortion_ = (void*) computeDistortion;
        void* getEyeToHeadTransform_ = (void*) getEyeToHeadTransform;
        void* getTimeSinceLastVsync_ = (void*) getTimeSinceLastVsync;
        void* getD3D9AdapterIndex_ = (void*) getD3D9AdapterIndex;
        void* getDXGIOutputInfo_ = (void*) getDXGIOutputInfo;
        void* getOutputDevice_ = (void*) getOutputDevice;
        void* isDisplayOnDesktop_ = (void*) isDisplayOnDesktop;
        void* setDisplayVisibility_ = (void*) setDisplayVisibility;
        void* getDeviceToAbsoluteTrackingPose_ = (void*) getDeviceToAbsoluteTrackingPose;
        void* getSeatedZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getSeatedZeroPoseToStandingAbsoluteTrackingPose;
        void* getRawZeroPoseToStandingAbsoluteTrackingPose_ = (void*) getRawZeroPoseToStandingAbsoluteTrackingPose;
        void* getSortedTrackedDeviceIndicesOfClass_ = (void*) getSortedTrackedDeviceIndicesOfClass;
        void* getTrackedDeviceActivityLevel_ = (void*) getTrackedDeviceActivityLevel;
        void* applyTransform_ = (void*) applyTransform;
        void* getTrackedDeviceIndexForControllerRole_ = (void*) getTrackedDeviceIndexForControllerRole;
        void* getControllerRoleForTrackedDeviceIndex_ = (void*) getControllerRoleForTrackedDeviceIndex;
        void* getTrackedDeviceClass_ = (void*) getTrackedDeviceClass;
        void* isTrackedDeviceConnected_ = (void*) isTrackedDeviceConnected;
        void* getBoolTrackedDeviceProperty_ = (void*) getBoolTrackedDeviceProperty;
        void* getFloatTrackedDeviceProperty_ = (void*) getFloatTrackedDeviceProperty;
        void* getInt32TrackedDeviceProperty_ = (void*) getInt32TrackedDeviceProperty;
        void* getUint64TrackedDeviceProperty_ = (void*) getUint64TrackedDeviceProperty;
        void* getMatrix34TrackedDeviceProperty_ = (void*) getMatrix34TrackedDeviceProperty;
        void* getArrayTrackedDeviceProperty_ = (void*) getArrayTrackedDeviceProperty;
        void* getStringTrackedDeviceProperty_ = (void*) getStringTrackedDeviceProperty;
        void* getPropErrorNameFromEnum_ = (void*) getPropErrorNameFromEnum;
        void* pollNextEvent_ = (void*) pollNextEvent;
        void* pollNextEventWithPose_ = (void*) pollNextEventWithPose;
        void* getEventTypeNameFromEnum_ = (void*) getEventTypeNameFromEnum;
        void* getHiddenAreaMesh_ = (void*) getHiddenAreaMesh;
        void* getControllerState_ = (void*) getControllerState;
        void* getControllerStateWithPose_ = (void*) getControllerStateWithPose;
        void* triggerHapticPulse_ = (void*) triggerHapticPulse;
        void* getButtonIdNameFromEnum_ = (void*) getButtonIdNameFromEnum;
        void* getControllerAxisTypeNameFromEnum_ = (void*) getControllerAxisTypeNameFromEnum;
        void* isInputAvailable_ = (void*) isInputAvailable;
        void* isSteamVRDrawingControllers_ = (void*) isSteamVRDrawingControllers;
        void* shouldApplicationPause_ = (void*) shouldApplicationPause;
        void* shouldApplicationReduceRenderingWork_ = (void*) shouldApplicationReduceRenderingWork;
        void* performFirmwareUpdate_ = (void*) performFirmwareUpdate;
        void* acknowledgeQuit_ = (void*) acknowledgeQuit;
        void* getAppContainerFilePaths_ = (void*) getAppContainerFilePaths;
        void* getRuntimeVersion_ = (void*) getRuntimeVersion;
    };

    class System_022_v
    {
        public:
            virtual void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height) { return System_022::getRecommendedRenderTargetSize(width, height); }
            virtual Matrix44 getProjectionMatrix(Eye eye, float near, float far) { return System_022::getProjectionMatrix(eye, near, far); }
            virtual void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom) { return System_022::getProjectionRaw(eye, left, right, top, bottom); }
            virtual bool computeDistortion(Eye eye, float u, float v, DistortionCoordinates* distortionCoordinates) { return System_022::computeDistortion(eye, u, v, distortionCoordinates); }
            virtual Matrix34 getEyeToHeadTransform(Eye eye) { return System_022::getEyeToHeadTransform(eye); }
            virtual bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter) { return System_022::getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter); }
            virtual int32_t getD3D9AdapterIndex() { return System_022::getD3D9AdapterIndex(); }
            virtual void getDXGIOutputInfo(int32_t* adapterIndex) { return System_022::getDXGIOutputInfo(adapterIndex); }
            virtual void getOutputDevice(uint64_t* device, TextureType textureType, VkInstance_T* vkInstance) { return System_022::getOutputDevice(device, textureType, vkInstance); }
            virtual bool isDisplayOnDesktop() { return System_022::isDisplayOnDesktop(); }
            virtual bool setDisplayVisibility(bool visibleOnDesktop) { return System_022::setDisplayVisibility(visibleOnDesktop); }
            virtual void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount) { return System_022::getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount); }
            virtual Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose() { return System_022::getSeatedZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose() { return System_022::getRawZeroPoseToStandingAbsoluteTrackingPose(); }
            virtual uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex) { return System_022::getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex); }
            virtual DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index) { return System_022::getTrackedDeviceActivityLevel(index); }
            virtual void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform) { return System_022::applyTransform(outputPose, trackedDevicePose, transform); }
            virtual uint32_t getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole) { return System_022::getTrackedDeviceIndexForControllerRole(controllerRole); }
            virtual TrackedControllerRole getControllerRoleForTrackedDeviceIndex(uint32_t index) { return System_022::getControllerRoleForTrackedDeviceIndex(index); }
            virtual TrackedDeviceClass getTrackedDeviceClass(uint32_t index) { return System_022::getTrackedDeviceClass(index); }
            virtual bool isTrackedDeviceConnected(uint32_t index) { return System_022::isTrackedDeviceConnected(index); }
            virtual bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_022::getBoolTrackedDeviceProperty(index, property, error); }
            virtual float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_022::getFloatTrackedDeviceProperty(index, property, error); }
            virtual int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_022::getInt32TrackedDeviceProperty(index, property, error); }
            virtual uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_022::getUint64TrackedDeviceProperty(index, property, error); }
            virtual Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error) { return System_022::getMatrix34TrackedDeviceProperty(index, property, error); }
            virtual uint32_t getArrayTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedDevicePropertyType type, void* buffer, uint32_t bufferSize, TrackedPropertyError* error) { return System_022::getArrayTrackedDeviceProperty(index, property, type, buffer, bufferSize, error); }
            virtual uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error) { return System_022::getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error); }
            virtual const char* getPropErrorNameFromEnum(TrackedPropertyError error) { return System_022::getPropErrorNameFromEnum(error); }
            virtual bool pollNextEvent(Event_0_9_15* event, uint32_t bufferSize) { return System_022::pollNextEvent(event, bufferSize); }
            virtual bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut) { return System_022::pollNextEventWithPose(origin, event, bufferSize, trackedDevicePoseOut); }
            virtual const char* getEventTypeNameFromEnum(EventType type) { return System_022::getEventTypeNameFromEnum(type); }
            virtual HiddenAreaMesh getHiddenAreaMesh(Eye eye, HiddenAreaMeshType type) { return System_022::getHiddenAreaMesh(eye, type); }
            virtual bool getControllerState(uint32_t index, ControllerState* state, uint32_t bufferSize) { return System_022::getControllerState(index, state, bufferSize); }
            virtual bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, uint32_t bufferSize, TrackedDevicePose* pose) { return System_022::getControllerStateWithPose(origin, index, state, bufferSize, pose); }
            virtual void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs) { return System_022::triggerHapticPulse(index, axisId, durationUs); }
            virtual const char* getButtonIdNameFromEnum(ButtonId button) { return System_022::getButtonIdNameFromEnum(button); }
            virtual const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType) { return System_022::getControllerAxisTypeNameFromEnum(axisType); }
            virtual bool isInputAvailable() { return System_022::isInputAvailable(); }
            virtual bool isSteamVRDrawingControllers() { return System_022::isSteamVRDrawingControllers(); }
            virtual bool shouldApplicationPause() { return System_022::shouldApplicationPause(); }
            virtual bool shouldApplicationReduceRenderingWork() { return System_022::shouldApplicationReduceRenderingWork(); }
            virtual FirmwareError performFirmwareUpdate(uint32_t deviceIndex) { return System_022::performFirmwareUpdate(deviceIndex); }
            virtual void acknowledgeQuit() { return System_022::acknowledgeQuit(); }
            virtual uint32_t getAppContainerFilePaths(char* buffer, uint32_t bufferSize) { return System_022::getAppContainerFilePaths(buffer, bufferSize); }
            virtual const char* getRuntimeVersion() { return System_022::getRuntimeVersion(); }
    };
}
