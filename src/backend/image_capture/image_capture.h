#pragma once

#include "backend/opengl.h"
#include "backend/vulkan.h"
#include "openvr/types_render.h"

#include <array>

namespace vapor
{
    namespace image_capture
    {
        void lockBufferSwap();
        void unlockBufferSwap();

        class ImageCaptureBuffer
        {
            public:
                int getCurrentDisplayBufferIndex() const;
                void swapBuffers();

                std::array<OpenGL::ExternalMemory*, 2> importOpenGLMemory() const;

                const int width;
                const int height;

            protected:
                ImageCaptureBuffer(int width, int height);

                int getCurrentCaptureBufferIndex() const;

                struct VulkanExportedTextureHolder
                {
                    int width;
                    int height;

                    VkDeviceMemory vulkanMemory;
                    int fd;
                    int size;
                };
                std::array<VulkanExportedTextureHolder, 2> bufferTextures;

            private:
                int currentBuffer = 0;
        };

        class ImageCaptureBufferManager
        {
            public:
                ImageCaptureBufferManager();
                ~ImageCaptureBufferManager();

                openvr::CompositorError captureOpenGL(int width, int height, GLuint srcTextureId, const openvr::TextureBounds* textureBounds);
                openvr::CompositorError captureVulkan(int width, int height, const openvr::VulkanTextureData* textureData, const openvr::TextureBounds* textureBounds);
                void deleteCaptureBuffer();

                void swapBuffers();

                bool hasCaptureBufferChanged();
                const ImageCaptureBuffer* getCaptureBufferForDisplay() const;

            private:
                void cleanupOldCaptureBuffer();

                enum class Api
                {
                    NONE,
                    OPENGL,
                    VULKAN
                };
                ImageCaptureBuffer* nextFrameImageCaptureBuffer = nullptr;
                Api nextFrameImageCaptureBufferApi = Api::NONE;
                ImageCaptureBuffer* presentedImageCaptureBuffer = nullptr;
                ImageCaptureBuffer* oldImageCaptureBuffer = nullptr;
                bool captureBufferChanged = false;
        };
    }
}
