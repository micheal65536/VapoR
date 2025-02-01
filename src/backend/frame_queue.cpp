#include "frame_queue.h"

using namespace vapor;

FrameQueue::FrameQueue(int frameWidth, int frameHeight)
{
    bufferSwap = 0;
}

FrameQueue::~FrameQueue()
{
    // empty
}

int FrameQueue::getDrawBufferIndex(int eyeIndex) const
{
    return bufferSwap + eyeIndex;
}

int FrameQueue::getDisplayBufferIndex(int eyeIndex) const
{
    return (2 - bufferSwap) + eyeIndex;
}

const OpenXR::ViewPair& FrameQueue::getDisplayViews() const
{
    return displayViews;
}

bool FrameQueue::hasDisplayFrame() const
{
    return displayFrameSubmitted;
}

void FrameQueue::swapBuffers(const OpenXR::ViewPair& views)
{
    swapMutex.lock();
    displayViews = views;
    displayFrameSubmitted = true;
    bufferSwap = 2 - bufferSwap;
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
