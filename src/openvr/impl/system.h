#pragma once

#include "../types.h"
#include <cstdint>
#include <vulkan/vulkan.h>
#include "client_core.h"

namespace openvr
{
    class SystemImpl
    {
        public:
            ClientCoreImpl& clientCore;
            SystemImpl(ClientCoreImpl& clientCore);

            //

            void getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height);
            Matrix44 getProjectionMatrix(Eye eye, float near, float far);
            void getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom);
            bool computeDistortion(Eye eye, float u, float v, DistortionCoordinates* distortionCoordinates);
            Matrix34 getEyeToHeadTransform(Eye eye);

            bool getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter);
            void getOutputDevice(uint64_t* device, TextureType textureType, VkInstance_T* vkInstance);

            void getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount);
            void resetSeatedZeroPose();
            Matrix34 getSeatedZeroPoseToStandingAbsoluteTrackingPose();
            Matrix34 getRawZeroPoseToStandingAbsoluteTrackingPose();

            uint32_t getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex);

            DeviceActivityLevel getTrackedDeviceActivityLevel(uint32_t index);

            void applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform);

            uint32_t getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole);
            TrackedControllerRole getControllerRoleForTrackedDeviceIndex(uint32_t index);
            TrackedDeviceClass getTrackedDeviceClass(uint32_t index);
            bool isTrackedDeviceConnected(uint32_t index);
            bool getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
            float getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
            int32_t getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
            uint64_t getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
            Matrix34 getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error);
            uint32_t getArrayTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedDevicePropertyType type, void* buffer, uint32_t bufferSize, TrackedPropertyError* error);
            uint32_t getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error);
            const char* getPropErrorNameFromEnum(TrackedPropertyError error);

            bool pollNextEvent(Event_0_9_15* event, uint32_t bufferSize);
            bool pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut);
            bool pollNextEventWithPoseAndOverlays(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut, uint64_t* overlayHandle);
            const char* getEventTypeNameFromEnum(EventType type);

            HiddenAreaMesh getHiddenAreaMesh(Eye eye, HiddenAreaMeshType type);

            bool getControllerState(uint32_t index, ControllerState* state, uint32_t bufferSize);
            bool getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, uint32_t bufferSize, TrackedDevicePose* pose);
            void triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs);
            const char* getButtonIdNameFromEnum(ButtonId button);
            const char* getControllerAxisTypeNameFromEnum(ControllerAxisType axisType);

            void acknowledgeQuit();
            void acknowledgeQuitPrompt();

            uint32_t getAppContainerFilePaths(char* buffer, uint32_t bufferSize);

            const char* getRuntimeVersion();
    };
}
