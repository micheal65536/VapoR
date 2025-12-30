#pragma once

#include "openxr.h"
#include "image_capture/image_capture.h"

#include <array>
#include <shared_mutex>

#include <vulkan/vulkan.h>

namespace vapor
{
    class FrameQueue
    {
        public:
            bool haveBuffersChanged();
            const image_capture::ImageCaptureBuffer* getCaptureBufferForEye(int eyeIndex) const;
            const OpenXR::ViewPair& getDisplayViews() const;
            bool hasDisplayFrame() const;

            void putFrame(const image_capture::ImageCaptureBuffer* leftCaptureBuffer, const image_capture::ImageCaptureBuffer* rightCaptureBuffer, const OpenXR::ViewPair& views);
            void lockFrame();
            void unlockFrame();

        private:
            const image_capture::ImageCaptureBuffer* leftCaptureBuffer = nullptr;
            const image_capture::ImageCaptureBuffer* rightCaptureBuffer = nullptr;
            bool haveBuffersChangedFlag = false;
            OpenXR::ViewPair displayViews;

            std::shared_mutex mutex;
    };
}
