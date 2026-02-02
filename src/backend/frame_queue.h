#pragma once

#include "openxr.h"
#include "image_capture/image_capture_buffer_manager.h"
#include "openvr/types_render.h"
#include <tuple>

#include <vulkan/vulkan.h>

namespace vapor
{
    class FrameQueue
    {
        public:
            image_capture::ImageCaptureBufferManager<std::tuple<OpenXR::View, openvr::TextureBounds>>* getCaptureBufferForEye(int eyeIndex) const;
            bool hasDisplayFrame() const;

            void setForeground(image_capture::ImageCaptureBufferManager<std::tuple<OpenXR::View, openvr::TextureBounds>>* leftCaptureBuffer, image_capture::ImageCaptureBufferManager<std::tuple<OpenXR::View, openvr::TextureBounds>>* rightCaptureBuffer);
            void clearForeground();

        private:
            image_capture::ImageCaptureBufferManager<std::tuple<OpenXR::View, openvr::TextureBounds>>* leftCaptureBuffer = nullptr;
            image_capture::ImageCaptureBufferManager<std::tuple<OpenXR::View, openvr::TextureBounds>>* rightCaptureBuffer = nullptr;
    };
}
