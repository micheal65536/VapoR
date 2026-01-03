#include "frame_queue.h"

#include "log/abort.h"
#include "image_capture/image_capture.h"

using namespace vapor;

image_capture::ImageCaptureBufferManager<std::tuple<OpenXR::View, openvr::TextureBounds>>* FrameQueue::getCaptureBufferForEye(int eyeIndex) const
{
    switch (eyeIndex)
    {
        case 0:
        default:
            return leftCaptureBuffer;
        case 1:
            return rightCaptureBuffer;
    }
}

bool FrameQueue::hasDisplayFrame() const
{
    return leftCaptureBuffer != nullptr && rightCaptureBuffer != nullptr;
}

void FrameQueue::setForeground(image_capture::ImageCaptureBufferManager<std::tuple<OpenXR::View, openvr::TextureBounds>>* leftCaptureBuffer, image_capture::ImageCaptureBufferManager<std::tuple<OpenXR::View, openvr::TextureBounds>>* rightCaptureBuffer)
{
    this->leftCaptureBuffer = leftCaptureBuffer;
    this->rightCaptureBuffer = rightCaptureBuffer;
}

void FrameQueue::clearForeground()
{
    leftCaptureBuffer = nullptr;
    rightCaptureBuffer = nullptr;
}
