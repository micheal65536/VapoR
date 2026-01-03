#pragma once

#include "backend/opengl.h"
#include "backend/vulkan.h"

#include <array>

namespace vapor
{
    namespace image_capture
    {
        void lockBufferSwap();
        void unlockBufferSwap();

        // TODO: move TextureBounds to here
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
    }
}
