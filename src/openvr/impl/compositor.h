#pragma once

#include "../types.h"
#include <cstdint>
#include <GL/gl.h>
#include <vulkan/vulkan.h>
#include "client_core.h"

#include "backend/pose_set.h"
#include "render/image_capture_helper.h"

namespace openvr
{
    class CompositorImpl
    {
        public:
            ClientCoreImpl& clientCore;
            CompositorImpl(ClientCoreImpl& clientCore);
            ~CompositorImpl();

            //

            void setTrackingSpace(TrackingUniverseOrigin origin);
            TrackingUniverseOrigin getTrackingSpace();

            CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
            CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
            CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose);
            CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags);
            CompositorError submitWithArrayIndex(Eye eye, const Texture* texture, uint32_t textureArrayIndex, const TextureBounds* bounds, int32_t submitFlags);
            void clearLastSubmittedFrame();
            void postPresentHandoff();

            bool getFrameTiming(FrameTiming_0_9_0* timing, uint32_t framesAgo);
            bool getFrameTiming(FrameTiming_0_9_15* timing, uint32_t framesAgo);
            bool getFrameTiming(FrameTiming_1_0_2* timing, uint32_t framesAgo);
            bool getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo);
            uint32_t getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames);
            float getFrameTimeRemaining();
            void getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize);

            void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background);
            Color getCurrentFadeColor(bool background);
            void fadeGrid(float seconds, bool fadeGridIn);
            float getCurrentGridAlpha();

            CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount);
            void clearSkyboxOverride();

            uint32_t getCurrentSceneFocusProcess();
            uint32_t getLastFrameRenderer();

            void showMirrorWindow();
            void hideMirrorWindow();
            bool isMirrorWindowVisible();

            void compositorDumpImages();

            void suspendRendering(bool suspend);

            CompositorError getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle);
            bool releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle);
            void lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle);
            void unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle);

            uint32_t getVulkanInstanceExtensionsRequired(char* value, uint32_t bufferSize);
            uint32_t getVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* device, char* value, uint32_t bufferSize);

            void setExplicitTimingMode(CompositorTimingMode timingMode);
            CompositorError submitExplicitTimingData();

            bool isCurrentSceneFocusAppLoading();

            CompositorError setStageOverride(const char* modelPath, const Matrix34* transform, const StageRenderSettings* renderSettings, uint32_t renderSettingsSize);
            void clearStageOverride();

            CompositorError getLastPosePredictionIDs(uint32_t* renderPosePredictionId, uint32_t* gamePosePredictionId);
            CompositorError getPosesForFrame(uint32_t posePredictionId, TrackedDevicePose* poses, uint32_t posesCount);

        private:
            OpenXR::ViewPair lastFrameViews;
            vapor::PoseSet lastFrameDevicePoses[3];

            render::GLImageCaptureHelper* glImageCaptureHelper = nullptr;
            render::VulkanImageCaptureHelper* vulkanImageCaptureHelper = nullptr;

            void present();
            bool presented = true;
    };
}
