#include "frame_queue.h"

#include "log/abort.h"

using namespace vapor;

bool FrameQueue::haveBuffersChanged()
{
    if (haveBuffersChangedFlag)
    {
        haveBuffersChangedFlag = false;
        return true;
    }
    return false;
}

const image_capture::ImageCaptureBuffer* FrameQueue::getCaptureBufferForEye(int eyeIndex) const
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
    return leftCaptureBuffer != nullptr && rightCaptureBuffer != nullptr;
}

void FrameQueue::putFrame(const image_capture::ImageCaptureBuffer* leftCaptureBuffer, const image_capture::ImageCaptureBuffer* rightCaptureBuffer, const OpenXR::ViewPair& views)
{
    mutex.lock();

    bool leftBufferChanged = (leftCaptureBuffer != this->leftCaptureBuffer || (leftCaptureBuffer != nullptr && *leftCaptureBuffer != *this->leftCaptureBuffer));
    bool rightBufferChanged = (rightCaptureBuffer != this->rightCaptureBuffer || (rightCaptureBuffer != nullptr && *rightCaptureBuffer != *this->rightCaptureBuffer));
    if (leftBufferChanged || rightBufferChanged)
    {
        if (!leftBufferChanged || !rightBufferChanged)
        {
            ABORT();
        }
        this->leftCaptureBuffer = leftCaptureBuffer;
        this->rightCaptureBuffer = rightCaptureBuffer;
        this->haveBuffersChangedFlag = true;
    }

    displayViews = views;

    mutex.unlock();
}

void FrameQueue::lockFrame()
{
    mutex.lock_shared();
}

void FrameQueue::unlockFrame()
{   
    mutex.unlock_shared();
}
