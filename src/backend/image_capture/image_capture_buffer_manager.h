#pragma once

#include "image_capture.h"
#include "image_capture_impl.h"
#include "openvr/types_render.h"
#include "backend/opengl.h"

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

                openvr::CompositorError captureOpenGL(GLuint srcTextureId, const openvr::TextureBounds* textureBounds)
                {
                    GLuint savedTexture;
                    glGetIntegerv(GL_TEXTURE_BINDING_2D, (GLint*) &savedTexture);
                    ABORT_ON_OPENGL_ERROR();
                    int width, height;
                    glBindTexture(GL_TEXTURE_2D, srcTextureId);
                    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width);
                    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &height);
                    ABORT_ON_OPENGL_ERROR();
                    glBindTexture(GL_TEXTURE_2D, savedTexture);
                    ABORT_ON_OPENGL_ERROR();

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

                openvr::CompositorError captureVulkan(const openvr::VulkanTextureData* textureData, const openvr::TextureBounds* textureBounds)
                {
                    int width = textureData->width;
                    int height = textureData->height;

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
