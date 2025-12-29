#pragma once

#include "opengl.h"

#include <vulkan/vulkan.h>

namespace vapor
{
    struct VulkanExportedTextureHolder
    {
        int width;
        int height;

        VkDeviceMemory vulkanMemory;
        int fd;
        int size;
    };
}
