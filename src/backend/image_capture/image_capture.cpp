#include "image_capture.h"
#include "image_capture_impl.h"

#include "backend/opengl.h"
#include "backend/vulkan.h"
#include "log/log.h"
#include "log/abort.h"
#include "config/fixes.h"

#include <mutex>

#include <cstring>
#include <cmath>
#include <vector>

#include <GL/glx.h>
#include <GL/glext.h>

using namespace vapor::image_capture;

//

static std::recursive_mutex swapMutex;

ImageCaptureBuffer::ImageCaptureBuffer(int width, int height): width(width), height(height)
{
    // empty
}

int ImageCaptureBuffer::getCurrentDisplayBufferIndex() const
{
    return 1 - currentBuffer;
}

int ImageCaptureBuffer::getCurrentCaptureBufferIndex() const
{
    return currentBuffer;
}

void ImageCaptureBuffer::swapBuffers()
{
    lockBufferSwap();

    currentBuffer = 1 - currentBuffer;

    unlockBufferSwap();
}

void vapor::image_capture::lockBufferSwap()
{
    swapMutex.lock();
}

void vapor::image_capture::unlockBufferSwap()
{
    swapMutex.unlock();
}

std::array<OpenGL::ExternalMemory*, 2> ImageCaptureBuffer::importOpenGLMemory() const
{
    std::array<OpenGL::ExternalMemory*, 2> importedMemory;
    for (int i = 0; i < 2; i++)
    {
        importedMemory[i] = new OpenGL::ExternalMemory(bufferTextures[i].fd, bufferTextures[i].size);
    }
    return importedMemory;
}

//

GLImageCaptureBuffer::GLImageCaptureBuffer(int width, int height): ImageCaptureBuffer(width, height)
{
    std::vector<const char*> instanceExtensions = (std::vector<const char*>) {
        VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME,
        VK_KHR_EXTERNAL_SEMAPHORE_CAPABILITIES_EXTENSION_NAME
    };
    VkApplicationInfo applicationInfo {
        .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
        .pNext = nullptr,
    };
    VkInstanceCreateInfo instanceCreateInfo {
        .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        .pNext = nullptr,
        .flags = 0,
        .pApplicationInfo = nullptr,
        .enabledLayerCount = 0,
        .ppEnabledLayerNames = nullptr,
        .enabledExtensionCount = instanceExtensions.size(),
        .ppEnabledExtensionNames = instanceExtensions.data()
    };
    VkInstance instance;
    ABORT_ON_VULKAN_ERROR(vkCreateInstance(&instanceCreateInfo, nullptr, &instance));

    uint32_t physicalDevicesCount = 1;
    VkPhysicalDevice physicalDevice;
    ABORT_ON_VULKAN_ERROR(vkEnumeratePhysicalDevices(instance, &physicalDevicesCount, &physicalDevice));
    if (physicalDevicesCount == 0)
    {
        ABORT("No Vulkan devices found");
    }

    std::vector<const char*> deviceExtensions = (std::vector<const char*>) {
        VK_KHR_EXTERNAL_MEMORY_EXTENSION_NAME,
        VK_KHR_EXTERNAL_SEMAPHORE_EXTENSION_NAME,
        VK_KHR_EXTERNAL_MEMORY_FD_EXTENSION_NAME,
        VK_KHR_EXTERNAL_SEMAPHORE_FD_EXTENSION_NAME
    };
    uint32_t queueFamilyIndex = 0; // TODO
    float queuePriority = 1.0f;
    VkDeviceQueueCreateInfo deviceQueueCreateInfo {
        .sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,
        .pNext = nullptr,
        .flags = 0,
        .queueFamilyIndex = queueFamilyIndex,
        .queueCount = 1,
        .pQueuePriorities = &queuePriority
    };
    VkDeviceCreateInfo deviceCreateInfo {
        .sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
        .pNext = nullptr,
        .flags = 0,
        .queueCreateInfoCount = 1,
        .pQueueCreateInfos = &deviceQueueCreateInfo,
        .enabledLayerCount = 0,
        .ppEnabledLayerNames = nullptr,
        .enabledExtensionCount = deviceExtensions.size(),
        .ppEnabledExtensionNames = deviceExtensions.data(),
        .pEnabledFeatures = nullptr
    };
    VkDevice device;
    ABORT_ON_VULKAN_ERROR(vkCreateDevice(physicalDevice, &deviceCreateInfo, nullptr, &device));

    VkQueue queue;
    vkGetDeviceQueue(device, queueFamilyIndex, 0, &queue);

    vulkan = new VulkanCommon(instance, physicalDevice, device, queue, queueFamilyIndex);

    //

    GLuint savedTexture;
    GLuint savedReadFramebuffer;
    GLuint savedDrawFramebuffer;
    GLuint savedRenderbuffer;
    glGetIntegerv(GL_TEXTURE_BINDING_2D, (GLint*) &savedTexture);
    glGetIntegerv(GL_READ_FRAMEBUFFER_BINDING, (GLint*) &savedReadFramebuffer);
    glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, (GLint*) &savedDrawFramebuffer);
    glGetIntegerv(GL_RENDERBUFFER_BINDING, (GLint*) &savedRenderbuffer);
    ABORT_ON_OPENGL_ERROR();

    glGenTextures(2, dstTextures);
    PFNGLCREATEMEMORYOBJECTSEXTPROC glCreateMemoryObjectsEXT = (PFNGLCREATEMEMORYOBJECTSEXTPROC) glXGetProcAddress((const GLubyte*) "glCreateMemoryObjectsEXT");
    glCreateMemoryObjectsEXT(2, dstExternalMemory);
    ABORT_ON_OPENGL_ERROR();

    PFNGLIMPORTMEMORYFDEXTPROC glImportMemoryFdEXT = (PFNGLIMPORTMEMORYFDEXTPROC) glXGetProcAddress((const GLubyte*) "glImportMemoryFdEXT");
    PFNGLTEXSTORAGEMEM2DEXTPROC glTexStorageMem2DEXT = (PFNGLTEXSTORAGEMEM2DEXTPROC) glXGetProcAddress((const GLubyte*) "glTexStorageMem2DEXT");
    for (int i = 0; i < 2; i++)
    {
        // TODO: can we do this (determine memory size etc.) without creating an image?
        VkImage image = vulkan->createImage(width, height, VK_FORMAT_R8G8B8A8_SRGB, VK_IMAGE_TILING_OPTIMAL, VK_IMAGE_USAGE_TRANSFER_DST_BIT, VK_IMAGE_LAYOUT_UNDEFINED);
        VkMemoryRequirements memoryRequirements;
        vkGetImageMemoryRequirements(vulkan->device, image, &memoryRequirements);
        uint32_t memoryTypeIndex = vulkan->selectMemoryType(0, memoryRequirements.memoryTypeBits);
        dstMemory[i] = vulkan->allocateMemory(memoryRequirements.size, memoryTypeIndex, true);
        vkDestroyImage(vulkan->device, image, nullptr);

        VkMemoryGetFdInfoKHR memoryGetFdInfo {
            .sType = VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR,
            .pNext = nullptr,
            .memory = dstMemory[i],
            .handleType = VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT_KHR
        };
        PFN_vkGetMemoryFdKHR vkGetMemoryFdKHR;
        vkGetMemoryFdKHR = (PFN_vkGetMemoryFdKHR) vkGetInstanceProcAddr(vulkan->instance, "vkGetMemoryFdKHR");
        int fd1;
        ABORT_ON_VULKAN_ERROR(vkGetMemoryFdKHR(vulkan->device, &memoryGetFdInfo, &fd1));
        bufferTextures[i] = vapor::image_capture::ImageCaptureBuffer::VulkanExportedTextureHolder {.width = width, .height = height, .vulkanMemory = dstMemory[i], .fd = fd1, .size = memoryRequirements.size};

        int fd;
        ABORT_ON_VULKAN_ERROR(vkGetMemoryFdKHR(vulkan->device, &memoryGetFdInfo, &fd));

        glImportMemoryFdEXT(dstExternalMemory[i], memoryRequirements.size, GL_HANDLE_TYPE_OPAQUE_FD_EXT, fd);
        ABORT_ON_OPENGL_ERROR();
        glBindTexture(GL_TEXTURE_2D, dstTextures[i]);
        glTexStorageMem2DEXT(GL_TEXTURE_2D, 1, GL_RGBA8, width, height, dstExternalMemory[i], 0);
        ABORT_ON_OPENGL_ERROR();
    }

    glGenFramebuffers(1, &srcFramebuffer);
    glGenRenderbuffers(2, srcRenderbuffers);
    glBindFramebuffer(GL_FRAMEBUFFER, srcFramebuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, srcRenderbuffers[0]);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_RGBA8, width, height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, srcRenderbuffers[0]);
    glBindRenderbuffer(GL_RENDERBUFFER, srcRenderbuffers[1]);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, srcRenderbuffers[1]);
    ABORT_ON_OPENGL_ERROR();

    glGenFramebuffers(1, &dstFramebuffer);
    glGenRenderbuffers(2, dstRenderbuffers);
    glBindFramebuffer(GL_FRAMEBUFFER, dstFramebuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, dstRenderbuffers[0]);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_RGBA8, width, height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, dstRenderbuffers[0]);
    glBindRenderbuffer(GL_RENDERBUFFER, dstRenderbuffers[1]);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, dstRenderbuffers[1]);
    ABORT_ON_OPENGL_ERROR();

    glBindFramebuffer(GL_READ_FRAMEBUFFER, savedReadFramebuffer);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, savedDrawFramebuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, savedRenderbuffer);
    glBindTexture(GL_TEXTURE_2D, savedTexture);
    ABORT_ON_OPENGL_ERROR();
}

GLImageCaptureBuffer::~GLImageCaptureBuffer()
{
    glDeleteFramebuffers(1, &srcFramebuffer);
    glDeleteRenderbuffers(2, srcRenderbuffers);
    glDeleteFramebuffers(1, &dstFramebuffer);
    glDeleteRenderbuffers(2, dstRenderbuffers);
    ABORT_ON_OPENGL_ERROR();

    glDeleteTextures(2, dstTextures);
    PFNGLDELETEMEMORYOBJECTSEXTPROC glDeleteMemoryObjectsEXT = (PFNGLDELETEMEMORYOBJECTSEXTPROC) glXGetProcAddress((const GLubyte*) "glDeleteMemoryObjectsEXT");
    glDeleteMemoryObjectsEXT(2, dstExternalMemory);
    ABORT_ON_OPENGL_ERROR();

    for (int i = 0; i < 2; i++)
    {
        vkFreeMemory(vulkan->device, dstMemory[i], nullptr);
    }

    VkDevice device = vulkan->device;
    delete vulkan;
    vkDestroyDevice(device, nullptr);
}

openvr::CompositorError GLImageCaptureBuffer::capture(GLuint srcTextureId, const openvr::TextureBounds* textureBounds)
{
    GLuint savedTexture;
    GLuint savedReadFramebuffer;
    GLuint savedDrawFramebuffer;
    glGetIntegerv(GL_TEXTURE_BINDING_2D, (GLint*) &savedTexture);
    glGetIntegerv(GL_READ_FRAMEBUFFER_BINDING, (GLint*) &savedReadFramebuffer);
    glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, (GLint*) &savedDrawFramebuffer);
    ABORT_ON_OPENGL_ERROR();

    glBindFramebuffer(GL_READ_FRAMEBUFFER, srcFramebuffer);
    glFramebufferTexture2D(GL_READ_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, srcTextureId, 0);
    ABORT_ON_OPENGL_ERROR();
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, dstFramebuffer);
    glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, dstTextures[getCurrentCaptureBufferIndex()], 0);
    ABORT_ON_OPENGL_ERROR();

    // TODO: figure out why image is sometimes flipped
    int srcWidth, srcHeight;
    glBindTexture(GL_TEXTURE_2D, srcTextureId);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &srcWidth);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &srcHeight);
    ABORT_ON_OPENGL_ERROR();
    int srcX1 = textureBounds != nullptr ? (int) std::roundf(srcWidth * textureBounds->uMin) : 0;
    int srcY1 = textureBounds != nullptr ? (int) std::roundf(srcHeight * textureBounds->vMin) : 0;
    int srcX2 = textureBounds != nullptr ? (int) std::roundf(srcWidth * textureBounds->uMax) : srcWidth;
    int srcY2 = textureBounds != nullptr ? (int) std::roundf(srcHeight * textureBounds->vMax) : srcHeight;
    glBlitFramebuffer(srcX1, vapor::config::fixes::flipImage ? srcY2 : srcY1, srcX2, vapor::config::fixes::flipImage ? srcY1 : srcY2, 0, 0, width, height, GL_COLOR_BUFFER_BIT, GL_LINEAR);
    glFinish();
    ABORT_ON_OPENGL_ERROR();

    glBindTexture(GL_TEXTURE_2D, savedTexture);
    glBindFramebuffer(GL_READ_FRAMEBUFFER, savedReadFramebuffer);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, savedDrawFramebuffer);
    ABORT_ON_OPENGL_ERROR();

    return openvr::CompositorError::COMPOSITOR_ERROR_NONE;
}

//

VulkanImageCaptureBuffer::VulkanImageCaptureBuffer(int width, int height, VkInstance instance, VkPhysicalDevice physicalDevice, VkDevice device, VkQueue queue, uint32_t queueFamilyIndex): ImageCaptureBuffer(width, height), common(instance, physicalDevice, device, queue, queueFamilyIndex)
{
    for (int i = 0; i < 2; i++)
    {
        dstImages[i] = common.createImage(width, height, vapor::config::fixes::createVulkanTargetInLinearColorspace ? VK_FORMAT_R8G8B8A8_UNORM : VK_FORMAT_R8G8B8A8_SRGB, VK_IMAGE_TILING_OPTIMAL, VK_IMAGE_USAGE_TRANSFER_DST_BIT, VK_IMAGE_LAYOUT_UNDEFINED);
        VkMemoryRequirements memoryRequirements;
        vkGetImageMemoryRequirements(common.device, dstImages[i], &memoryRequirements);
        uint32_t memoryTypeIndex = common.selectMemoryType(0, memoryRequirements.memoryTypeBits);
        dstImagesMemory[i] = common.allocateMemory(memoryRequirements.size, memoryTypeIndex, true);
        ABORT_ON_VULKAN_ERROR(vkBindImageMemory(common.device, dstImages[i], dstImagesMemory[i], 0));

        VkMemoryGetFdInfoKHR memoryGetFdInfo {
            .sType = VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR,
            .pNext = nullptr,
            .memory = dstImagesMemory[i],
            .handleType = VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT_KHR
        };
        PFN_vkGetMemoryFdKHR vkGetMemoryFdKHR;
        vkGetMemoryFdKHR = (PFN_vkGetMemoryFdKHR) vkGetInstanceProcAddr(common.instance, "vkGetMemoryFdKHR");
        int fd;
        ABORT_ON_VULKAN_ERROR(vkGetMemoryFdKHR(common.device, &memoryGetFdInfo, &fd));
        bufferTextures[i] = vapor::image_capture::ImageCaptureBuffer::VulkanExportedTextureHolder {.width = width, .height = height, .vulkanMemory = dstImagesMemory[i], .fd = fd, .size = memoryRequirements.size};
    }
}

VulkanImageCaptureBuffer::~VulkanImageCaptureBuffer()
{
    vkDestroyImage(common.device, tmpImage, nullptr);
    vkFreeMemory(common.device, tmpImageMemory, nullptr);

    for (int i = 0; i < 2; i++)
    {
        vkDestroyImage(common.device, dstImages[i], nullptr);
        vkFreeMemory(common.device, dstImagesMemory[i], nullptr);
    }
}

openvr::CompositorError VulkanImageCaptureBuffer::capture(const openvr::VulkanTextureData* textureData, const openvr::TextureBounds* textureBounds)
{
    if (textureData->instance != common.instance || textureData->physicalDevice != common.physicalDevice || textureData->device != common.device || textureData->queue != common.queue || textureData->queueFamilyIndex != common.queueFamilyIndex)
    {
        LOG("Texture submitted with mismatched Vulkan context");
        return openvr::CompositorError::COMPOSITOR_ERROR_TEXTURE_IS_ON_WRONG_DEVICE;
    }

    common.beginCommandBuffer();

    VkImage srcImage;
    if (textureData->sampleCount != 1)
    {
        if (textureData->width != tmpImageWidth || textureData->height != tmpImageHeight || (VkFormat) textureData->format != tmpImageFormat)
        {
            vkFreeMemory(common.device, tmpImageMemory, nullptr);
            vkDestroyImage(common.device, tmpImage, nullptr);

            tmpImageWidth = textureData->width;
            tmpImageHeight = textureData->height;
            tmpImageFormat = (VkFormat) textureData->format;
            tmpImage = common.createImage(tmpImageWidth, tmpImageHeight, tmpImageFormat, VK_IMAGE_TILING_OPTIMAL, VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT, VK_IMAGE_LAYOUT_UNDEFINED);
            tmpImageMemory = common.allocateAndBindImage(tmpImage, 0, false);
        }

        common.transitionImageLayout(tmpImage, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 0, VK_ACCESS_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT);

        VkImageResolve imageResolve {
            .srcSubresource = {
                .aspectMask = VK_IMAGE_ASPECT_COLOR_BIT,
                .mipLevel = 0,
                .baseArrayLayer = 0,
                .layerCount = 1
            },
            .srcOffset = { .x = 0, .y = 0, .z = 0},
            .dstSubresource = {
                .aspectMask = VK_IMAGE_ASPECT_COLOR_BIT,
                .mipLevel = 0,
                .baseArrayLayer = 0,
                .layerCount = 1
            },
            .dstOffset = { .x = 0, .y = 0, .z = 0 },
            .extent = { .width = textureData->width, .height = textureData->height, .depth = 1 }
        };
        vkCmdResolveImage(common.commandBuffer, textureData->image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, tmpImage, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &imageResolve);

        common.transitionImageLayout(tmpImage, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_ACCESS_TRANSFER_WRITE_BIT, VK_ACCESS_TRANSFER_READ_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT);

        srcImage = tmpImage;
    }
    else
    {
        srcImage = textureData->image;
    }

    VkImage dstImage = dstImages[getCurrentCaptureBufferIndex()];

    common.transitionImageLayout(dstImage, VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 0, VK_ACCESS_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT);

    // TODO: figure out why image is sometimes flipped
    int srcX1 = textureBounds != nullptr ? (int) std::roundf(textureData->width * textureBounds->uMin) : 0;
    int srcY1 = textureBounds != nullptr ? (int) std::roundf(textureData->height * textureBounds->vMin) : 0;
    int srcX2 = textureBounds != nullptr ? (int) std::roundf(textureData->width * textureBounds->uMax) : textureData->width;
    int srcY2 = textureBounds != nullptr ? (int) std::roundf(textureData->height * textureBounds->vMax) : textureData->height;
    VkImageBlit imageBlit {
        .srcSubresource = {
            .aspectMask = VK_IMAGE_ASPECT_COLOR_BIT,
            .mipLevel = 0,
            .baseArrayLayer = 0,
            .layerCount = 1
        },
        .srcOffsets = {
            { .x = srcX1, .y = vapor::config::fixes::flipImage ? srcY2 : srcY1, .z = 0 },
            { .x = srcX2, .y = vapor::config::fixes::flipImage ? srcY1 : srcY2, .z = 1 }
        },
        .dstSubresource = {
            .aspectMask = VK_IMAGE_ASPECT_COLOR_BIT,
            .mipLevel = 0,
            .baseArrayLayer = 0,
            .layerCount = 1
        },
        .dstOffsets = {
            { .x = 0, .y = 0, .z = 0 },
            { .x = this->width, .y = this->height, .z = 1 }
        }
    };
    vkCmdBlitImage(common.commandBuffer, srcImage, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, dstImage, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &imageBlit, VK_FILTER_LINEAR);

    common.transitionImageLayout(dstImage, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, VK_IMAGE_LAYOUT_GENERAL, VK_ACCESS_TRANSFER_WRITE_BIT, VK_ACCESS_MEMORY_READ_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_PIPELINE_STAGE_TRANSFER_BIT);

    common.endAndSubmitCommandBuffer();

    return openvr::CompositorError::COMPOSITOR_ERROR_NONE;
}

//

VulkanCommon::VulkanCommon(VkInstance instance, VkPhysicalDevice physicalDevice, VkDevice device, VkQueue queue, uint32_t queueFamilyIndex)
{
    this->instance = instance;
    this->physicalDevice = physicalDevice;
    this->device = device;
    this->queue = queue;
    this->queueFamilyIndex = queueFamilyIndex;

    vkGetPhysicalDeviceMemoryProperties(physicalDevice, &physicalDeviceMemoryProperties);

    VkCommandPoolCreateInfo commandPoolCreateInfo {
        .sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,
        .pNext = nullptr,
        .flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT,
        .queueFamilyIndex = queueFamilyIndex
    };
    ABORT_ON_VULKAN_ERROR(vkCreateCommandPool(device, &commandPoolCreateInfo, nullptr, &commandPool));
    VkCommandBufferAllocateInfo commandBufferAllocateInfo {
        .sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
        .pNext = nullptr,
        .commandPool = this->commandPool,
        .level = VK_COMMAND_BUFFER_LEVEL_PRIMARY,
        .commandBufferCount = 1
    };
    ABORT_ON_VULKAN_ERROR(vkAllocateCommandBuffers(device, &commandBufferAllocateInfo, &commandBuffer));

    VkFenceCreateInfo fenceCreateInfo {
        .sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO,
        .pNext = nullptr,
        .flags = 0
    };
    ABORT_ON_VULKAN_ERROR(vkCreateFence(device, &fenceCreateInfo, nullptr, &fence));
}

VulkanCommon::~VulkanCommon()
{
    vkFreeCommandBuffers(device, commandPool, 1, &commandBuffer);
    vkDestroyCommandPool(device, commandPool, nullptr);

    vkDestroyFence(device, fence, nullptr);
}

uint32_t VulkanCommon::selectMemoryType(VkMemoryPropertyFlags propertyFlags, uint32_t imageMemoryTypeBits)
{
    for (uint32_t i = 0; i < physicalDeviceMemoryProperties.memoryTypeCount; i++)
    {
        VkMemoryType& memoryType = physicalDeviceMemoryProperties.memoryTypes[i];
        if (imageMemoryTypeBits != 0 && !(imageMemoryTypeBits & (1 << i)))
        {
            continue;
        }
        if ((memoryType.propertyFlags & propertyFlags) != propertyFlags)
        {
            continue;
        }
        return i;
    }
    ABORT("Cannot find suitable memory type");
}

VkDeviceMemory VulkanCommon::allocateMemory(VkDeviceSize size, uint32_t memoryTypeIndex, bool exported)
{
    VkMemoryAllocateInfo memoryAllocateInfo {
        .sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
        .pNext = nullptr,
        .allocationSize = size,
        .memoryTypeIndex = memoryTypeIndex
    };
    VkExportMemoryAllocateInfo exportMemoryAllocateInfo;
    if (exported)
    {
        exportMemoryAllocateInfo = {
            .sType = VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO,
            .pNext = nullptr,
            .handleTypes = VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT
        };
        memoryAllocateInfo.pNext = &exportMemoryAllocateInfo;
    }
    VkDeviceMemory memory;
    ABORT_ON_VULKAN_ERROR(vkAllocateMemory(device, &memoryAllocateInfo, nullptr, &memory));
    return memory;
}

void VulkanCommon::beginCommandBuffer()
{
    ABORT_ON_VULKAN_ERROR(vkResetCommandBuffer(commandBuffer, 0));
    VkCommandBufferBeginInfo commandBufferBeginInfo {
        .sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO,
        .pNext = nullptr,
        .flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT,
        .pInheritanceInfo = nullptr
    };
    ABORT_ON_VULKAN_ERROR(vkBeginCommandBuffer(commandBuffer, &commandBufferBeginInfo));
}

void VulkanCommon::endAndSubmitCommandBuffer()
{
    ABORT_ON_VULKAN_ERROR(vkEndCommandBuffer(commandBuffer));

    ABORT_ON_VULKAN_ERROR(vkResetFences(device, 1, &fence));
    VkSubmitInfo submitInfo {
        .sType = VK_STRUCTURE_TYPE_SUBMIT_INFO,
        .pNext = nullptr,
        .waitSemaphoreCount = 0,
        .pWaitSemaphores = nullptr,
        .commandBufferCount = 1,
        .pCommandBuffers = &commandBuffer,
        .signalSemaphoreCount = 0,
        .pSignalSemaphores = nullptr
    };
    ABORT_ON_VULKAN_ERROR(vkQueueSubmit(queue, 1, &submitInfo, fence));
    VkResult result = vkWaitForFences(device, 1, &fence, VK_TRUE, 1000000000l);
    ABORT_ON_VULKAN_ERROR(result);
    if (result == VK_TIMEOUT)
    {
        ABORT("Timeout waiting for Vulkan commands to finish");
    }
}

VkImage VulkanCommon::createImage(uint32_t width, uint32_t height, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkImageLayout initialLayout)
{
    VkImageCreateInfo imageCreateInfo {
        .sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
        .pNext = nullptr,
        .flags = 0,
        .imageType = VK_IMAGE_TYPE_2D,
        .format = format,
        .extent = {
            .width = width,
            .height = height,
            .depth = 1
        },
        .mipLevels = 1,
        .arrayLayers = 1,
        .samples = VK_SAMPLE_COUNT_1_BIT,
        .tiling = tiling,
        .usage = usage,
        .sharingMode = VK_SHARING_MODE_EXCLUSIVE,
        .queueFamilyIndexCount = 0,
        .pQueueFamilyIndices = nullptr,
        .initialLayout = initialLayout
    };
    VkImage image;
    ABORT_ON_VULKAN_ERROR(vkCreateImage(device, &imageCreateInfo, nullptr, &image));
    return image;
}

VkDeviceMemory VulkanCommon::allocateAndBindImage(VkImage image, VkMemoryPropertyFlags memoryPropertyFlags, bool exported)
{
    VkMemoryRequirements memoryRequirements;
    vkGetImageMemoryRequirements(device, image, &memoryRequirements);
    uint32_t memoryTypeIndex = selectMemoryType(memoryPropertyFlags, memoryRequirements.memoryTypeBits);
    VkDeviceMemory memory = allocateMemory(memoryRequirements.size, memoryTypeIndex, exported);
    ABORT_ON_VULKAN_ERROR(vkBindImageMemory(device, image, memory, 0));
    return memory;
}

void VulkanCommon::transitionImageLayout(VkImage image, VkImageLayout oldLayout, VkImageLayout newLayout, VkAccessFlags srcAccessMask, VkAccessFlags dstAccessMask, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask)
{
    VkImageMemoryBarrier imageMemoryBarrier {
        .sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
        .pNext = nullptr,
        .srcAccessMask = srcAccessMask,
        .dstAccessMask = dstAccessMask,
        .oldLayout = oldLayout,
        .newLayout = newLayout,
        .srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
        .dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
        .image = image,
        .subresourceRange = {
            .aspectMask = VK_IMAGE_ASPECT_COLOR_BIT,
            .baseMipLevel = 0,
            .levelCount = 1,
            .baseArrayLayer = 0,
            .layerCount = 1
        }
    };
    vkCmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, 0, 0, nullptr, 0, nullptr, 1, &imageMemoryBarrier);
}

//

ImageCaptureBufferManager::ImageCaptureBufferManager()
{
    // empty
}

ImageCaptureBufferManager::~ImageCaptureBufferManager()
{
    if (nextFrameImageCaptureBuffer != presentedImageCaptureBuffer)
    {
        delete nextFrameImageCaptureBuffer;
    }
    delete presentedImageCaptureBuffer;
    delete oldImageCaptureBuffer;
    nextFrameImageCaptureBuffer = nullptr;
    nextFrameImageCaptureBufferApi = Api::NONE;
    presentedImageCaptureBuffer = nullptr;
    oldImageCaptureBuffer = nullptr;
}

openvr::CompositorError ImageCaptureBufferManager::captureOpenGL(int width, int height, GLuint srcTextureId, const openvr::TextureBounds* textureBounds)
{
    cleanupOldCaptureBuffer();

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

openvr::CompositorError ImageCaptureBufferManager::captureVulkan(int width, int height, const openvr::VulkanTextureData* textureData, const openvr::TextureBounds* textureBounds)
{
    cleanupOldCaptureBuffer();

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

void ImageCaptureBufferManager::deleteCaptureBuffer()
{
    if (nextFrameImageCaptureBuffer != nullptr)
    {
        if (nextFrameImageCaptureBuffer != presentedImageCaptureBuffer)
        {
            delete nextFrameImageCaptureBuffer;
        }
        nextFrameImageCaptureBuffer = nullptr;
        nextFrameImageCaptureBufferApi = Api::NONE;
    }
}

void ImageCaptureBufferManager::swapBuffers()
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

    unlockBufferSwap();
}

bool ImageCaptureBufferManager::hasCaptureBufferChanged()
{
    if (captureBufferChanged)
    {
        captureBufferChanged = false;
        return true;
    }
    return false;
}

const ImageCaptureBuffer* ImageCaptureBufferManager::getCaptureBufferForDisplay() const
{
    return presentedImageCaptureBuffer;
}

void ImageCaptureBufferManager::cleanupOldCaptureBuffer()
{
    if (oldImageCaptureBuffer != nullptr)
    {
        delete oldImageCaptureBuffer;
        oldImageCaptureBuffer = nullptr;
    }
}
