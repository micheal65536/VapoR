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

        class ImageCaptureBuffer
        {
            public:
                int getCurrentDisplayBufferIndex() const;
                void swapBuffers();

                std::array<OpenGL::ExternalMemory*, 2> importOpenGLMemory() const;

                const int width;
                const int height;

                inline bool operator==(const ImageCaptureBuffer& rhs) const
                {
                    return rhs.uniqueId == this->uniqueId;
                }

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
                int uniqueId;

                int currentBuffer = 0;
        };
    }
}
