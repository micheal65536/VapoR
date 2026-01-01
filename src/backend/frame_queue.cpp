#include "frame_queue.h"

#include "log/abort.h"
#include "image_capture/image_capture.h"

using namespace vapor;

image_capture::ImageCaptureBufferManager* FrameQueue::getCaptureBufferForEye(int eyeIndex) const
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

const OpenXR::ViewPair& FrameQueue::getDisplayViews() const
{
    return displayViews;
}

bool FrameQueue::hasDisplayFrame() const
{
    return hasDisplayFrameFlag;
}

void FrameQueue::putFrame(image_capture::ImageCaptureBufferManager* leftCaptureBuffer, image_capture::ImageCaptureBufferManager* rightCaptureBuffer, const OpenXR::ViewPair& views)
{
    this->leftCaptureBuffer = leftCaptureBuffer;
    this->rightCaptureBuffer = rightCaptureBuffer;
    this->displayViews = views;
    hasDisplayFrameFlag = true;
}

void FrameQueue::putClearFrame()
{
    leftCaptureBuffer = nullptr;
    rightCaptureBuffer = nullptr;
    displayViews = OpenXR::ViewPair();
    hasDisplayFrameFlag = false;
}
