#include "frame_queue.h"

using namespace vapor;

bool FrameQueue::hasBufferTextureSetChanged()
{
    if (hasBufferTextureSetChangedFlag)
    {
        hasBufferTextureSetChangedFlag = false;
        return true;
    }
    return false;
}

const std::array<VulkanExportedTextureHolder, 4>* FrameQueue::getBufferTextureSet() const
{
    return bufferTextureSet;
}

int FrameQueue::getDisplayBufferIndex(int eyeIndex) const
{
    switch (eyeIndex)
    {
        case 0:
            return leftEyeDisplayBufferIndex;
        case 1:
            return rightEyeDisplayBufferIndex;
        default:
            return 0;
    }
}

const OpenXR::ViewPair& FrameQueue::getDisplayViews() const
{
    return displayViews;
}

bool FrameQueue::hasDisplayFrame() const
{
    return bufferTextureSet != nullptr;
}

void FrameQueue::swapBuffers(const std::array<VulkanExportedTextureHolder, 4>* bufferTextureSet, int leftEyeBufferIndex, int rightEyeBufferIndex, const OpenXR::ViewPair& views)
{
    swapMutex.lock();

    if (bufferTextureSet != this->bufferTextureSet) // TODO: need more rigorous way to determine if buffer set has changed
    {
        this->bufferTextureSet = bufferTextureSet;
        hasBufferTextureSetChangedFlag = true;
    }

    leftEyeDisplayBufferIndex = leftEyeBufferIndex;
    rightEyeDisplayBufferIndex = rightEyeBufferIndex;

    displayViews = views;

    swapMutex.unlock();
}

void FrameQueue::lockBufferSwap()
{
    swapMutex.lock_shared();
}

void FrameQueue::unlockBufferSwap()
{   
    swapMutex.unlock_shared();
}
