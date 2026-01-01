#pragma once

#include "image_capture.h"
#include "image_capture_impl.h"
#include "openvr/types_render.h"

namespace vapor
{
    namespace image_capture
    {
        template<typename AttachedData>
        class ImageCaptureBufferManager
        {
            public:
                ImageCaptureBufferManager()
                {
                    // empty
                }

                ~ImageCaptureBufferManager()
                {
                    if (nextFrameImageCaptureBuffer != presentedImageCaptureBuffer)
                    {
                        delete nextFrameImageCaptureBuffer;
                    }
                    delete presentedImageCaptureBuffer;
                    nextFrameImageCaptureBuffer = nullptr;
                    nextFrameImageCaptureBufferApi = Api::NONE;
                    presentedImageCaptureBuffer = nullptr;
                }

                //

                openvr::CompositorError captureOpenGL(int width, int height, GLuint srcTextureId, const openvr::TextureBounds* textureBounds)
                {
                    if (nextFrameImageCaptureBuffer == nullptr || nextFrameImageCaptureBuffer->width != width || nextFrameImageCaptureBuffer->height != height || nextFrameImageCaptureBufferApi != Api::OPENGL)
                    {
                        if (nextFrameImageCaptureBuffer != presentedImageCaptureBuffer)
                        {
                            delete nextFrameImageCaptureBuffer;
                        }
                        nextFrameImageCaptureBuffer = new GLImageCaptureBuffer(width, height);
                        nextFrameImageCaptureBufferApi = Api::OPENGL;
                    }

                    return ((GLImageCaptureBuffer*) nextFrameImageCaptureBuffer)->capture(srcTextureId, textureBounds);
                }

                openvr::CompositorError captureVulkan(int width, int height, const openvr::VulkanTextureData* textureData, const openvr::TextureBounds* textureBounds)
                {
                    // TODO: check Vulkan properties
                    if (nextFrameImageCaptureBuffer == nullptr || nextFrameImageCaptureBuffer->width != width || nextFrameImageCaptureBuffer->height != height || nextFrameImageCaptureBufferApi != Api::VULKAN)
                    {
                        if (nextFrameImageCaptureBuffer != presentedImageCaptureBuffer)
                        {
                            delete nextFrameImageCaptureBuffer;
                        }
                        nextFrameImageCaptureBuffer = new VulkanImageCaptureBuffer(width, height, textureData->instance, textureData->physicalDevice, textureData->device, textureData->queue, textureData->queueFamilyIndex);
                        nextFrameImageCaptureBufferApi = Api::VULKAN;
                    }

                    return ((VulkanImageCaptureBuffer*) nextFrameImageCaptureBuffer)->capture(textureData, textureBounds);
                }

                void submitAttachedData(const AttachedData& attachedData)
                {
                    nextFrameAttachedData = attachedData;
                }

                //

                void swapBuffers()
                {
                    lockBufferSwap();

                    if (nextFrameImageCaptureBuffer != nullptr)
                    {
                        nextFrameImageCaptureBuffer->swapBuffers();
                    }

                    if (nextFrameImageCaptureBuffer != presentedImageCaptureBuffer)
                    {
                        delete presentedImageCaptureBuffer;
                        presentedImageCaptureBuffer = nextFrameImageCaptureBuffer;
                        captureBufferChanged = true;
                    }

                    presentedAttachedData = nextFrameAttachedData;

                    unlockBufferSwap();
                }

                //

                bool hasCaptureBufferChanged()
                {
                    if (captureBufferChanged)
                    {
                        captureBufferChanged = false;
                        return true;
                    }
                    return false;
                }

                const ImageCaptureBuffer* getCaptureBufferForDisplay() const
                {
                    return presentedImageCaptureBuffer;
                }

                const AttachedData& getCurrentDisplayAttachedData() const
                {
                    return presentedAttachedData;
                }

            private:
                enum class Api
                {
                    NONE,
                    OPENGL,
                    VULKAN
                };
                ImageCaptureBuffer* nextFrameImageCaptureBuffer = nullptr;
                Api nextFrameImageCaptureBufferApi = Api::NONE;
                ImageCaptureBuffer* presentedImageCaptureBuffer = nullptr;
                bool captureBufferChanged = false;

                AttachedData nextFrameAttachedData;
                AttachedData presentedAttachedData;
        };
    }
}
