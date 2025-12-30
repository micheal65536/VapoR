#pragma once

#include "image_capture.h"

#include "backend/opengl.h"
#include "backend/vulkan.h"
#include "openvr/types_render.h"

namespace vapor
{
    namespace image_capture
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

        class GLImageCaptureBuffer: public ImageCaptureBuffer
        {
            public:
                GLImageCaptureBuffer(int width, int height);
                ~GLImageCaptureBuffer();

                openvr::CompositorError capture(GLuint srcTextureId, const openvr::TextureBounds* textureBounds);

            private:
                VulkanCommon* vulkan;
                VkDeviceMemory dstMemory[2];

                GLuint srcFramebuffer;
                GLuint srcRenderbuffers[2];
                GLuint dstTextures[2];
                GLuint dstExternalMemory[2];
                GLuint dstFramebuffer;
                GLuint dstRenderbuffers[2];
        };

        class VulkanImageCaptureBuffer: public ImageCaptureBuffer
        {
            public:
                VulkanImageCaptureBuffer(int width, int height, VkInstance instance, VkPhysicalDevice physicalDevice, VkDevice device, VkQueue queue, uint32_t queueFamilyIndex);
                ~VulkanImageCaptureBuffer();
 
                openvr::CompositorError capture(const openvr::VulkanTextureData* textureData, const openvr::TextureBounds* textureBounds);

            private:
                VulkanCommon common;

                VkImage dstImages[2];
                VkDeviceMemory dstImagesMemory[2];

                VkImage tmpImage = VK_NULL_HANDLE;
                VkDeviceMemory tmpImageMemory = VK_NULL_HANDLE;
                uint32_t tmpImageWidth = 0;
                uint32_t tmpImageHeight = 0;
                VkFormat tmpImageFormat;
        };
    }
}
