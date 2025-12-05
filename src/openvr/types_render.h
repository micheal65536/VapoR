#pragma once

#include "types_geometry.h"
#include "types_input.h"
#include <vulkan/vulkan.h>

namespace openvr
{
    enum DeviceType
    {
        DEVICE_TYPE_NONE = 0,
        DEVICE_TYPE_D3D9 = 1,
        DEVICE_TYPE_D3D9EX = 2,
        DEVICE_TYPE_D3D10 = 3,
        DEVICE_TYPE_D3D11 = 4,
        DEVICE_TYPE_OPENGL = 5
    };

    enum TextureType
    {
        TEXTURE_TYPE_INVALID = -1,
        TEXTURE_TYPE_DIRECTX_11 = 0,
        TEXTURE_TYPE_OPENGL = 1,
        TEXTURE_TYPE_VULKAN = 2,
        TEXTURE_TYPE_MACOS_IO_SURFACE = 3,
        TEXTURE_TYPE_DIRECTX_12 = 4,
        TEXTURE_TYPE_DXGI_SHARED_HANDLE = 5,
        TEXTURE_TYPE_METAL = 6
    };

    enum ColorSpace
    {
        COLOR_SPACE_AUTO = 0,
        COLOR_SPACE_GAMMA = 1,
        COLOR_SPACE_LINEAR = 2
    };

    struct Texture
    {
        void* handle;
        TextureType type;
        ColorSpace colorSpace;
    };

    struct TextureDepthInfo
    {
        void* handle;
        Matrix44 projection;
        Vector2 range;
    };

    struct TextureWithPose: public Texture
    {
        Matrix34 deviceToAbsolute;
    };

    struct TextureWithDepth: public Texture
    {
        TextureDepthInfo depth;
    };

    struct TextureWithPoseAndDepth: public TextureWithPose
    {
        TextureDepthInfo depth;
    };

    struct TextureBounds
    {
        float uMin;
        float vMin;
        float uMax;
        float vMax;
    };

    enum CompositorTextureUsage
    {
        COMPOSITOR_TEXTURE_USAGE_LEFT = 0,
        COMPOSITOR_TEXTURE_USAGE_RIGHT = 1,
        COMPOSITOR_TEXTURE_USAGE_BOTH = 2
    };

    enum CompositorError
    {
        COMPOSITOR_ERROR_NONE = 0,
        COMPOSITOR_ERROR_REQUEST_FAILED = 1,
        COMPOSITOR_ERROR_INCOMPATIBLE_VERSION = 100,
        COMPOSITOR_ERROR_DO_NOT_HAVE_FOCUS = 101,
        COMPOSITOR_ERROR_INVALID_TEXTURE = 102,
        COMPOSITOR_ERROR_IS_NOT_SCENE_APPLICATION = 103,
        COMPOSITOR_ERROR_TEXTURE_IS_ON_WRONG_DEVICE = 104,
        COMPOSITOR_ERROR_TEXTURE_USES_UNSUPPORTED_FORMAT = 105,
        COMPOSITOR_ERROR_SHARED_TEXTURES_NOT_SUPPORTED = 106,
        COMPOSITOR_ERROR_INDEX_OUT_OF_RANGE = 107,
        COMPOSITOR_ERROR_ALREADY_SUBMITTED = 108,
        COMPOSITOR_ERROR_INVALID_BOUNDS = 109,
        COMPOSITOR_ERROR_ALREADY_SET = 110
    };

    enum SubmitFlags
    {
        SUBMIT_DEFAULT = 0x0000,
        SUBMIT_LENS_DISTORTION_ALREADY_APPLIED = 0x0001,
        SUBMIT_GL_RENDER_BUFFER = 0x0002,
        SUBMIT_TEXTURE_WITH_POSE = 0x0008,
        SUBMIT_TEXTURE_WITH_DEPTH = 0x0010,
        SUBMIT_FRAME_DISCONTINUTY = 0x0020,
        SUBMIT_VULKAN_TEXTURE_WITH_ARRAY_DATA = 0x0040,
        SUBMIT_GL_ARRAY_TEXTURE = 0x0080,
        SUBMIT_IS_EGL = 0x0100
    };

    struct VulkanTextureData
    {
        VkImage_T* image;
        VkDevice_T* device;
        VkPhysicalDevice_T* physicalDevice;
        VkInstance_T* instance;
        VkQueue_T* queue;
        uint32_t queueFamilyIndex;
        uint32_t width;
        uint32_t height;
        uint32_t format;
        uint32_t sampleCount;
    };

    struct GLSharedTextureHandle
    {
        // TODO
    };

    enum FrameTimingReprojectionFlags
    {
        REASON_CPU = 0x0001,
        REASON_GPU = 0x0002,
        ASYNC_ENABLED = 0x0004,
        MOTION_SMOOTHING = 0x0008,
        PREDICTION_MASK = 0x00F0,
        THROTTLE_MASK = 0x0F00
    };

    struct FrameTiming_0_9_0
    {
        uint32_t size;

        double frameStart;
        float frameVSync;
        uint32_t numDroppedFrames;
        uint32_t frameIndex;
        TrackedDevicePose pose;

        float prediction;

        float frameIntervalMs;
        float sceneRenderCpuMs;
        float sceneRenderGpuMs;
        float compositorRenderGpuMs;
        float compositorRenderCpuMs;
        float presentCallCpuMs;
        float runningStartMs;
        float handoffStartMs;
        float handoffEndMs;
        float compositorUpdateCpuMs;

        uint32_t numTimesPresented;
    };

    struct FrameTiming_0_9_15
    {
        uint32_t size;

        uint32_t frameIndex;
        uint32_t numFramePresents;
        uint32_t numDroppedFrames;

        double systemTimeInSeconds;

        float sceneRenderGpuMs;
        float totalRenderGpuMs;
        float compositorRenderGpuMs;
        float compositorRenderCpuMs;
        float compositorIdleCpuMs;

        float clientFrameIntervalMs;
        float presentCallCpuMs;
        float waitForPresentCpuMs;
        float submitFrameMs;

        float waitGetPosesCalledMs;
        float newPosesReadyMs;
        float newFrameReadyMs;
        float compositorUpdateStartMs;
        float compositorUpdateEndMs;
        float compositorRenderStartMs;

        TrackedDevicePose hmdPose;

        int32_t fidelityLevel;

        uint32_t reprojectionFlags;
    };

    struct FrameTiming_1_0_2
    {
        uint32_t size;

        uint32_t frameIndex;
        uint32_t numFramePresents;
        uint32_t numDroppedFrames;
        uint32_t reprojectionFlags;

        double systemTimeInSeconds;

        float preSubmitGpuMs;
        float postSubmitGpuMs;
        float totalRenderGpuMs;
        float compositorRenderGpuMs;
        float compositorRenderCpuMs;
        float compositorIdleCpuMs;

        float clientFrameIntervalMs;
        float presentCallCpuMs;
        float waitForPresentCpuMs;
        float submitFrameMs;

        float waitGetPosesCalledMs;
        float newPosesReadyMs;
        float newFrameReadyMs;
        float compositorUpdateStartMs;
        float compositorUpdateEndMs;
        float compositorRenderStartMs;

        TrackedDevicePose hmdPose;

        uint32_t numVSyncsReadyForUse;
        uint32_t numVSyncsToFirstView;

        float transferLatencyMs;
    };

    struct FrameTiming_1_0_4
    {
        uint32_t size;

        uint32_t frameIndex;
        uint32_t numFramePresents;
        uint32_t numMisPresented;
        uint32_t numDroppedFrames;
        uint32_t reprojectionFlags;

        double systemTimeInSeconds;

        float preSubmitGpuMs;
        float postSubmitGpuMs;
        float totalRenderGpuMs;
        float compositorRenderGpuMs;
        float compositorRenderCpuMs;
        float compositorIdleCpuMs;

        float clientFrameIntervalMs;
        float presentCallCpuMs;
        float waitForPresentCpuMs;
        float submitFrameMs;

        float waitGetPosesCalledMs;
        float newPosesReadyMs;
        float newFrameReadyMs;
        float compositorUpdateStartMs;
        float compositorUpdateEndMs;
        float compositorRenderStartMs;

        TrackedDevicePose hmdPose;

        uint32_t numVSyncsReadyForUse;
        uint32_t numVSyncsToFirstView;

        float transferLatencyMs;
    };

    enum CompositorTimingMode
    {
        COMPOSITOR_TIMING_MODE_IMPLICIT = 0,
        COMPOSITOR_TIMING_MODE_EXPLICIT_RUNTIME_PERFORMS_POST_PRESENT_HANDOFF = 1,
        COMPOSITOR_TIMING_MODE_EXPLICIT_APPLICATION_PERFORMS_POST_PRESENT_HANDOFF = 2
    };

    struct StageRenderSettings
    {
        Color primaryColor;
        Color secondaryColor;
        float vignetteInnerRadius;
        float vignetteOuterRadius;
        float fresnelStrength;
        bool backfaceCulling;
        bool greyscale;
        bool wireframe;
    };

    struct CumulativeStats
    {
        uint32_t pid;

        uint32_t numFramePresents;
        uint32_t numDroppedFrames;
        uint32_t bumReprojectedFrames;

        uint32_t numFramePresentsOnStartup;
        uint32_t numDroppedFramesOnStartup;
        uint32_t numReprojectedFramesOnStartup;

        uint32_t numLoading;
        uint32_t numFramePresentsLoading;
        uint32_t numDroppedFramesLoading;
        uint32_t numReprojectedFramesLoading;

        uint32_t numTimedOut;
        uint32_t numFramePresentsTimedOut;
        uint32_t numDroppedFramesTimedOut;
        uint32_t numReprojectedFramesTimedOut;

        uint32_t numFrameSubmits;
        double sumCompositorCpuTimeMs;
        double sumCompositorGpuTimeMs;
        double sumTargetFrameTimes;
        double sumApplicationCpuTimeMs;
        double sumApplicationGpuTimeMs;

        uint32_t numFramesWithDepth;
    };

    struct BenchmarkResults
    {
        float megaPixelsPerSecond;
        float recommendedMegaPixelsPerSecond;
    };
}
