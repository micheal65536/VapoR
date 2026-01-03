#include "compositor.h"
#include "log/log.h"
#include "log/stub.h"

#include "utils/pose.h"

#include <cstring>

using namespace openvr;

CompositorImpl::CompositorImpl(ClientCoreImpl& clientCore): clientCore(clientCore)
{
    // empty
}

CompositorImpl::~CompositorImpl()
{
    this->loseFocus();
}

void CompositorImpl::setTrackingSpace(TrackingUniverseOrigin origin)
{
    TRACE_F("%d", origin);
    this->clientCore.trackingSpace = origin;
}

TrackingUniverseOrigin CompositorImpl::getTrackingSpace()
{
    TRACE_F("%d", this->clientCore.trackingSpace);
    return this->clientCore.trackingSpace;
}

CompositorError CompositorImpl::waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    TRACE_F("%d %d", renderPosesCount, gamePosesCount);

    this->present();

    this->clientCore.backend->frameStates.waitForNextFrame();

    TRACE_F("finished waiting");

    this->presented = false;
    for (int eye = 0; eye < 2; eye++)
    {
        framesSubmitted[eye] = false;
    }

    vapor::FrameState frame = this->clientCore.backend->frameStates.getFrame(0);
    this->lastFrameViews = frame.renderViews;
    this->lastFrameDevicePoses[0] = frame.head;
    for (int i = 0; i < 2; i++)
    {
        this->lastFrameDevicePoses[i + 1] = frame.controllerPoses[i];
    }

    if (renderPosesCount >= 1)
    {
        utils::selectTrackedDevicePose(this->lastFrameDevicePoses[0], this->clientCore.trackingSpace, false, &renderPoses[0]);
    }
    for (int i = 1; i < renderPosesCount; i++)
    {
        if (i < 3)
        {
            utils::selectTrackedDevicePose(this->lastFrameDevicePoses[i], this->clientCore.trackingSpace, false, &renderPoses[i]);
        }
    }
    if (gamePosesCount >= 1)
    {
        utils::selectTrackedDevicePose(this->lastFrameDevicePoses[0], this->clientCore.trackingSpace, true, &gamePoses[0]);
    }
    for (int i = 1; i < gamePosesCount; i++)
    {
        if (i < 3)
        {
            utils::selectTrackedDevicePose(this->lastFrameDevicePoses[i], this->clientCore.trackingSpace, true, &gamePoses[i]);
        }
    }

    return CompositorError::COMPOSITOR_ERROR_NONE;
}

CompositorError CompositorImpl::getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    TRACE_F("%d %d", renderPosesCount, gamePosesCount);

    if (renderPosesCount >= 1)
    {
        utils::selectTrackedDevicePose(this->lastFrameDevicePoses[0], this->clientCore.trackingSpace, false, &renderPoses[0]);
    }
    for (int i = 1; i < renderPosesCount; i++)
    {
        if (i < 3)
        {
            utils::selectTrackedDevicePose(this->lastFrameDevicePoses[i], this->clientCore.trackingSpace, false, &renderPoses[i]);
        }
    }
    if (gamePosesCount >= 1)
    {
        utils::selectTrackedDevicePose(this->lastFrameDevicePoses[0], this->clientCore.trackingSpace, true, &gamePoses[0]);
    }
    for (int i = 1; i < gamePosesCount; i++)
    {
        if (i < 3)
        {
            utils::selectTrackedDevicePose(this->lastFrameDevicePoses[i], this->clientCore.trackingSpace, true, &gamePoses[i]);
        }
    }

    return CompositorError::COMPOSITOR_ERROR_NONE;
}

CompositorError CompositorImpl::getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose)
{
    TRACE_F("%d", deviceIndex);

    if (deviceIndex >= 3)
    {
        return CompositorError::COMPOSITOR_ERROR_INDEX_OUT_OF_RANGE;
    }

    const vapor::PoseSet& poseSet = this->lastFrameDevicePoses[deviceIndex];
    if (outputPose != nullptr)
    {
        utils::selectTrackedDevicePose(poseSet, this->clientCore.trackingSpace, false, outputPose);
    }
    if (gamePose != nullptr)
    {
        utils::selectTrackedDevicePose(poseSet, this->clientCore.trackingSpace, true, gamePose);
    }

    return CompositorError::COMPOSITOR_ERROR_NONE;
}

CompositorError CompositorImpl::getSubmitTexture(Texture* textureOut, bool* needsFlush, CompositorTextureUsage usage, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags)
{
    STUB_F("%d %d %d %d", usage, texture, bounds, submitFlags);
}

// TODO: implement tracking of which eyes have been submitted, handle this appropriately in present and in clearLastSubmittedFrame (e.g. when do we keep the previous eye image vs presenting a blank image, do we allow submission of only 1 eye, etc.?)

CompositorError CompositorImpl::submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags)
{
    TRACE_F("%d %d %d %d", eye, texture->type, texture->colorSpace, submitFlags);

    if (framesSubmitted[eye])
    {
        return CompositorError::COMPOSITOR_ERROR_ALREADY_SUBMITTED;
    }

    // TODO: handle different submit flags (array texture etc.)

    // TODO: handle source size
    if (texture->type == TextureType::TEXTURE_TYPE_OPENGL)
    {
        CompositorError error = imageCaptureBuffers[eye].captureOpenGL((GLuint) (uint64_t) texture->handle);
        if (error != CompositorError::COMPOSITOR_ERROR_NONE)
        {
            return error;
        }
    }
    else if (texture->type == TextureType::TEXTURE_TYPE_VULKAN)
    {
        const VulkanTextureData* textureData = (VulkanTextureData*) texture->handle;
        CompositorError error = imageCaptureBuffers[eye].captureVulkan(textureData);
        if (error != CompositorError::COMPOSITOR_ERROR_NONE)
        {
            return error;
        }
    }
    else
    {
        STUB_F("Unsupported texture type %d", texture->type);
        return CompositorError::COMPOSITOR_ERROR_REQUEST_FAILED;
    }

    const OpenXR::View* view;
    switch (eye)
    {
        case Eye::EYE_LEFT:
            view = &this->lastFrameViews.left;
            break;
        case Eye::EYE_RIGHT:
            view = &this->lastFrameViews.right;
            break;
    }
    imageCaptureBuffers[eye].submitAttachedData({*view, bounds != nullptr ? *bounds : (TextureBounds) {.uMin = 0.0f, .vMin = 0.0f, .uMax = 1.0f, .vMax = 1.0f}});

    framesSubmitted[eye] = true;
    if (framesSubmitted[Eye::EYE_LEFT] && framesSubmitted[Eye::EYE_RIGHT])
    {
        this->gainFocus();
    }

    return CompositorError::COMPOSITOR_ERROR_NONE;
}

CompositorError CompositorImpl::submitWithArrayIndex(Eye eye, const Texture* texture, uint32_t textureArrayIndex, const TextureBounds* bounds, int32_t submitFlags)
{
    STUB();
    return CompositorError::COMPOSITOR_ERROR_REQUEST_FAILED;
}

void CompositorImpl::clearLastSubmittedFrame()
{
    TRACE();

    this->loseFocus();
}

void CompositorImpl::postPresentHandoff()
{
    this->present();
}

void CompositorImpl::gainFocus()
{
    vapor::image_capture::lockBufferSwap();
    this->clientCore.backend->frameQueue->setForeground(&imageCaptureBuffers[0], &imageCaptureBuffers[1]);
    vapor::image_capture::unlockBufferSwap();
}

void CompositorImpl::loseFocus()
{
    vapor::image_capture::lockBufferSwap();
    this->clientCore.backend->frameQueue->clearForeground();
    vapor::image_capture::unlockBufferSwap();
}

void CompositorImpl::present()
{
    TRACE();

    if (!this->presented)
    {
        bool haveFrames = true;
        for (int eye = 0; eye < 2; eye++)
        {
            if (!framesSubmitted[eye])
            {
                haveFrames = false;
            }
        }

        if (haveFrames)
        {
            vapor::image_capture::lockBufferSwap();
            for (int eye = 0; eye < 2; eye++)
            {
                imageCaptureBuffers[eye].swapBuffers();
            }
            vapor::image_capture::unlockBufferSwap();

            this->presented = true;
        }
        else
        {
            TRACE_F("present with no frame");
        }
    }
}

bool CompositorImpl::getFrameTiming(FrameTiming_0_9_0* timing, uint32_t framesAgo)
{
    STUB();
    return false;
}

bool CompositorImpl::getFrameTiming(FrameTiming_0_9_15* timing, uint32_t framesAgo)
{
    STUB();
    return false;
}

bool CompositorImpl::getFrameTiming(FrameTiming_1_0_2* timing, uint32_t framesAgo)
{
    STUB();
    return false;
}

bool CompositorImpl::getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo)
{
    STUB();
    return false;
}

uint32_t CompositorImpl::getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames)
{
    STUB();
    return 0;
}

float CompositorImpl::getFrameTimeRemaining()
{
    STUB();
    return 0.0f;
}

void CompositorImpl::getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize)
{
    STUB();
}

void CompositorImpl::fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background)
{
    STUB();
}

Color CompositorImpl::getCurrentFadeColor(bool background)
{
    STUB();
}

void CompositorImpl::fadeGrid(float seconds, bool fadeGridIn)
{
    STUB();
}

float CompositorImpl::getCurrentGridAlpha()
{
    STUB();
}

CompositorError CompositorImpl::setSkyboxOverride(const Texture* textures, uint32_t texturesCount)
{
    STUB();
}

void CompositorImpl::clearSkyboxOverride()
{
    STUB();
}

uint32_t CompositorImpl::getCurrentSceneFocusProcess()
{
    STUB();
}

uint32_t CompositorImpl::getLastFrameRenderer()
{
    STUB();
}

void CompositorImpl::showMirrorWindow()
{
    TRACE();
}

void CompositorImpl::hideMirrorWindow()
{
    TRACE();
}

bool CompositorImpl::isMirrorWindowVisible()
{
    TRACE();
    return false;
}

void CompositorImpl::compositorDumpImages()
{
    STUB();
}

void CompositorImpl::suspendRendering(bool suspend)
{
    STUB();
}

CompositorError CompositorImpl::getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle)
{
    STUB();
}

bool CompositorImpl::releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle)
{
    STUB();
}

void CompositorImpl::lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle)
{
    STUB();
}

void CompositorImpl::unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle)
{
    STUB();
}

uint32_t CompositorImpl::getVulkanInstanceExtensionsRequired(char* value, uint32_t bufferSize)
{
    static const char* extensions = VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME " " VK_KHR_EXTERNAL_SEMAPHORE_CAPABILITIES_EXTENSION_NAME;
    std::strncpy(value, extensions, bufferSize);
    return std::strlen(extensions) + 1;
}

uint32_t CompositorImpl::getVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* device, char* value, uint32_t bufferSize)
{
    static const char* extensions = VK_KHR_EXTERNAL_MEMORY_EXTENSION_NAME " " VK_KHR_EXTERNAL_SEMAPHORE_EXTENSION_NAME " " VK_KHR_EXTERNAL_MEMORY_FD_EXTENSION_NAME " " VK_KHR_EXTERNAL_SEMAPHORE_FD_EXTENSION_NAME;
    std::strncpy(value, extensions, bufferSize);
    return std::strlen(extensions) + 1;
}

void CompositorImpl::setExplicitTimingMode(CompositorTimingMode timingMode)
{
    TRACE_F("%d", timingMode);
}

CompositorError CompositorImpl::submitExplicitTimingData()
{
    TRACE();
    return CompositorError::COMPOSITOR_ERROR_NONE;
}

bool CompositorImpl::isCurrentSceneFocusAppLoading()
{
    STUB();
}

CompositorError CompositorImpl::setStageOverride(const char* modelPath, const Matrix34* transform, const StageRenderSettings* renderSettings, uint32_t renderSettingsSize)
{
    STUB();
}

void CompositorImpl::clearStageOverride()
{
    STUB();
}

CompositorError CompositorImpl::getLastPosePredictionIDs(uint32_t* renderPosePredictionId, uint32_t* gamePosePredictionId)
{
    STUB();
}

CompositorError CompositorImpl::getPosesForFrame(uint32_t posePredictionId, TrackedDevicePose* poses, uint32_t posesCount)
{
    STUB();
}
