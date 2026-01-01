#pragma once

#include "openxr.h"
#include "image_capture/image_capture.h"

#include <array>

#include <vulkan/vulkan.h>

namespace vapor
{
    class FrameQueue
    {
        public:
            image_capture::ImageCaptureBufferManager* getCaptureBufferForEye(int eyeIndex) const;
            const OpenXR::ViewPair& getDisplayViews() const;
            bool hasDisplayFrame() const;

            void putFrame(image_capture::ImageCaptureBufferManager* leftCaptureBuffer, image_capture::ImageCaptureBufferManager* rightCaptureBuffer, const OpenXR::ViewPair& views);
            void putClearFrame();

        private:
            image_capture::ImageCaptureBufferManager* leftCaptureBuffer = nullptr;
            image_capture::ImageCaptureBufferManager* rightCaptureBuffer = nullptr;
            OpenXR::ViewPair displayViews;
            bool hasDisplayFrameFlag = false;
    };
}
