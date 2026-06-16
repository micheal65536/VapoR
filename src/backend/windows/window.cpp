#include "window.h"

#include "backend/opengl.h"
#include <cstring>

using namespace vapor::windows;

Window::Window()
{
    this->transform = new AbsoluteTransform(openvr::TrackingUniverseOrigin::ORIGIN_STANDING, (openvr::Matrix34) {.m = {{1.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f, 0.0f}}});
}

Window::~Window()
{
    delete this->transform;
    this->transform = nullptr;

    std::free(cpuImageBuffer);
    cpuImageBuffer = nullptr;
    cpuImageBufferSize = 0;

    // TODO: need to queue OpenGL objects to be deleted on render thread (because destructor is typically called from client thread)
}

void Window::render(WindowRenderer* windowRenderer, const PoseSet& headPose, const OpenXR::View& view)
{
    std::unique_lock<std::recursive_mutex> lock(this->mutex);

    if (this->transform == nullptr)
    {
        return;
    }

    OpenGL::Texture* textureForRender = nullptr;
    int textureWidth, textureHeight;
    if (hasCpuImage)
    {
        if (internalTexture == nullptr)
        {
            internalTexture = new OpenGL::Texture();
        }

        if (hasCpuImageChanged)
        {
            internalTexture->image(cpuImageWidth, cpuImageHeight, GL_RGBA, GL_UNSIGNED_BYTE, GL_RGBA, cpuImageBuffer); // TODO: depth/format
            hasCpuImageChanged = false;
            ABORT_ON_OPENGL_ERROR();
        }

        textureForRender = internalTexture;
        textureWidth = cpuImageWidth;
        textureHeight = cpuImageHeight;
    }
    else if (hasGpuImage)
    {
        const image_capture::ImageCaptureBuffer* buffer = imageCaptureBuffer.getCaptureBufferForDisplay();
        if (buffer != nullptr)
        {
            if (imageCaptureBuffer.hasCaptureBufferChanged())
            {
                std::array<OpenGL::ExternalMemory*, 2> externalMemory = buffer->importOpenGLMemory();
                for (int i = 0; i < 2; i++)
                {
                    delete this->externalMemory[i];
                    delete this->externalTextures[i];
                    this->externalMemory[i] = externalMemory[i];
                    this->externalTextures[i] = new OpenGL::Texture();
                    this->externalTextures[i]->attachExternalMemory(buffer->width, buffer->height, GL_RGBA8, *externalMemory[i], 0);
                    ABORT_ON_OPENGL_ERROR();
                }
            }

            textureForRender = this->externalTextures[buffer->getCurrentDisplayBufferIndex()];
            textureWidth = buffer->width;
            textureHeight = buffer->height;
        }
        else
        {
            for (int i = 0; i < 2; i++)
            {
                delete this->externalMemory[i];
                this->externalMemory[i] = nullptr;
            }
            imageCaptureBuffer.hasCaptureBufferChanged(); // to clear flag
        }
    }
    if (textureForRender == nullptr)
    {
        return;
    }

    if (!this->transform->shouldDisplay())
    {
        return;
    }
    const float (&transformMatrix)[3][4] = this->transform->getOverlayToWorldTransformMatrix();
    float headPoseMatrix[3][4];
    this->transform->getHeadPoseToUse(headPose, &headPoseMatrix);

    // TODO: decide between flat and curved rendering (or other render styles? need to check if cursor/dashboard/etc. requires a different render style)
    float aspectRatio = ((textureHeight * (textureBounds[3] - textureBounds[1])) / (textureWidth * (textureBounds[2] - textureBounds[0]))) / this->texelAspectRatio;
    windowRenderer->renderFlat(textureForRender, textureBounds, headPoseMatrix, view, this->widthInMeters, aspectRatio, transformMatrix);
}

void Window::clearImage()
{
    mutex.lock();

    hasCpuImage = false;
    hasGpuImage = false;

    std::free(cpuImageBuffer);
    cpuImageBuffer = nullptr;
    cpuImageBufferSize = 0;

    mutex.unlock();
}

vapor::image_capture::ImageCaptureBufferManager<int>& Window::getImageCaptureBuffer()
{
    return imageCaptureBuffer;
}

void Window::activateGpuImage()
{
    mutex.lock();

    hasGpuImage = true;

    hasCpuImage = false;
    std::free(cpuImageBuffer);
    cpuImageBuffer = nullptr;
    cpuImageBufferSize = 0;

    mutex.unlock();
}

void Window::submitCpuImage(void* buffer, int width, int height, int depth)
{
    mutex.lock();

    int bufferSize = width * height * depth;
    if (cpuImageBufferSize < bufferSize)
    {
        std::free(cpuImageBuffer);
        cpuImageBuffer = std::malloc(width * height * depth);
        cpuImageBufferSize = bufferSize;
    }

    cpuImageWidth = width;
    cpuImageHeight = height;
    cpuImageDepth = depth;
    //std::memcpy(cpuImageBuffer, buffer, bufferSize);
    for (int row = 0; row < height; row++)
    {
        std::memcpy(cpuImageBuffer + (height - row - 1) * width * depth, buffer + row * width * depth, width * depth);
    }
    hasCpuImageChanged = true;

    hasCpuImage = true;
    hasGpuImage = false;

    mutex.unlock();
}
