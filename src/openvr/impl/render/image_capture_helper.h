#pragma once

#include <cstdint>
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <vulkan/vulkan.h>
#include "openvr/types_render.h"
#include "openvr/types_misc.h"
#include "backend/vulkan_exported_texture_holder.h"

#include <array>

namespace openvr
{
    namespace render
    {
        class VulkanCommon
        {
            public:
                VulkanCommon(VkInstance instance, VkPhysicalDevice physicalDevice, VkDevice device, VkQueue queue, uint32_t queueFamilyIndex);
                ~VulkanCommon();

                VkInstance instance;
                VkPhysicalDevice physicalDevice;
                VkDevice device;
                VkQueue queue;
                uint32_t queueFamilyIndex;

                VkPhysicalDeviceMemoryProperties physicalDeviceMemoryProperties;
                uint32_t selectMemoryType(VkMemoryPropertyFlags propertyFlags, uint32_t imageMemoryTypeBits);
                VkDeviceMemory allocateMemory(VkDeviceSize size, uint32_t memoryTypeIndex, bool exported);

                VkCommandPool commandPool;
                VkCommandBuffer commandBuffer;
                VkFence fence;
                void beginCommandBuffer();
                void endAndSubmitCommandBuffer();

                VkImage createImage(uint32_t width, uint32_t height, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkImageLayout initialLayout);
                VkDeviceMemory allocateAndBindImage(VkImage image, VkMemoryPropertyFlags memoryPropertyFlags, bool exported);

                void transitionImageLayout(VkImage image, VkImageLayout oldLayout, VkImageLayout newLayout, VkAccessFlags srcAccessMask, VkAccessFlags dstAccessMask, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask);
        };

        class GLImageCaptureHelper
        {
            public:
                GLImageCaptureHelper(int width, int height);
                ~GLImageCaptureHelper();

                CompositorError capture(GLuint srcTextureId, const TextureBounds* textureBounds, Eye eye);
                int getCurrentBufferIndexForEye(Eye eye);
                void swapBuffers();

                std::array<vapor::VulkanExportedTextureHolder, 4> exportedBufferTextures;

            private:
                int width;
                int height;

                VulkanCommon* vulkan;
                VkDeviceMemory dstMemory[4];
                int currentBufferSwap = 0;

                GLuint srcFramebuffer;
                GLuint srcRenderbuffers[2];
                GLuint dstTextures[4];
                GLuint dstExternalMemory[4];
                GLuint dstFramebuffer;
                GLuint dstRenderbuffers[2];
        };

        class VulkanImageCaptureHelper
        {
            public:
                VulkanImageCaptureHelper(int width, int height, VkInstance instance, VkPhysicalDevice physicalDevice, VkDevice device, VkQueue queue, uint32_t queueFamilyIndex);
                ~VulkanImageCaptureHelper();
 
                CompositorError capture(const VulkanTextureData* textureData, const TextureBounds* textureBounds, Eye eye);
                int getCurrentBufferIndexForEye(Eye eye);
                void swapBuffers();

                std::array<vapor::VulkanExportedTextureHolder, 4> exportedBufferTextures;

            private:
                int width;
                int height;

                VulkanCommon common;

                VkImage dstImages[4];
                VkDeviceMemory dstImagesMemory[4];
                int currentBufferSwap = 0;

                VkImage tmpImage = VK_NULL_HANDLE;
                VkDeviceMemory tmpImageMemory = VK_NULL_HANDLE;
                uint32_t tmpImageWidth = 0;
                uint32_t tmpImageHeight = 0;
                VkFormat tmpImageFormat;
        };
    }
}
