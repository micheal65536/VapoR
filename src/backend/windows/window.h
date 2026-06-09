#pragma once

#include <string>

#include "transform.h"
#include "window_renderer.h"
#include "backend/pose_set.h"
#include "backend/openxr.h"

#include "backend/image_capture/image_capture_buffer_manager.h"
#include "backend/opengl.h"
#include <mutex>

namespace vapor
{
    namespace windows
    {
        class WindowManager;

        class Window
        {
            friend class WindowManager;

            public:
                Window();
                ~Window();

                //

                void render(WindowRenderer* windowRenderer, const PoseSet& headPose, const OpenXR::View& view);

                //

                void clearImage();
                image_capture::ImageCaptureBufferManager<int>& getImageCaptureBuffer();
                void activateGpuImage();
                void submitCpuImage(void* buffer, int width, int height, int depth);

                //

                std::string title;

                bool visible = false;
                bool dashboard = false;

                float texelAspectRatio = 1.0f;
                float widthInMeters = 1.0f;

                // TODO: curvature properties

                float textureBounds[4] = {0.0f, 0.0f, 1.0f, 1.0f};

                Transform* transform = nullptr;

                //

                inline void lock()
                {
                    mutex.lock();
                }

                inline void unlock()
                {
                    mutex.unlock();
                }

            private:
                bool hasGpuImage = false;
                bool hasCpuImage = false;
                bool hasCpuImageChanged = false;
                image_capture::ImageCaptureBufferManager<int> imageCaptureBuffer;
                void* cpuImageBuffer = nullptr;
                int cpuImageWidth;
                int cpuImageHeight;
                int cpuImageDepth;
                int cpuImageBufferSize = 0;
                OpenGL::Texture* internalTexture = nullptr;
                OpenGL::Texture* externalTextures[2] = {nullptr, nullptr};
                OpenGL::ExternalMemory* externalMemory[2] = {nullptr, nullptr};

                std::recursive_mutex mutex;
        };
    }
}
