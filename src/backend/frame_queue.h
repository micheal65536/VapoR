#pragma once

#include "openxr.h"
#include "image_capture/image_capture_buffer_manager.h"

#include <array>

#include <vulkan/vulkan.h>

namespace vapor
{
    class FrameQueue
    {
        public:
            image_capture::ImageCaptureBufferManager<OpenXR::View>* getCaptureBufferForEye(int eyeIndex) const;
            bool hasDisplayFrame() const;

            void setForeground(image_capture::ImageCaptureBufferManager<OpenXR::View>* leftCaptureBuffer, image_capture::ImageCaptureBufferManager<OpenXR::View>* rightCaptureBuffer);
            void clearForeground();

        private:
            image_capture::ImageCaptureBufferManager<OpenXR::View>* leftCaptureBuffer = nullptr;
            image_capture::ImageCaptureBufferManager<OpenXR::View>* rightCaptureBuffer = nullptr;
    };
}
