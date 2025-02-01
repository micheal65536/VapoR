#pragma once

#include <vulkan/vulkan.h>

#include "log/abort.h"

#define ABORT_ON_VULKAN_ERROR(x) \
    { \
        VkResult _r = x; \
        if (_r < 0) \
        { \
            ABORT("Vulkan call failed (%d)", _r); \
        } \
    }
