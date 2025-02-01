#include "frame_state.h"

using namespace vapor;

FrameStateStore::FrameStateStore(int size)
{
    this->size = size;
    this->frames = new FrameState[size];
    for (int i = 0; i < size; i++)
    {
        this->frames[i].time = 0;
        this->frames[i].index = -1;
    }
}

FrameStateStore::~FrameStateStore()
{
    delete[] this->frames;
}

void FrameStateStore::postFrame(FrameState frame)
{
    this->mutex.lock();
    for (int i = 1; i < this->size; i++)
    {
        this->frames[i - 1] = this->frames[i];
    }
    this->frames[this->size - 1] = frame;
    this->frames[this->size - 1].index = this->counter++;
    if (this->filled < this->size)
    {
        this->filled++;
    }
    this->mutex.unlock();
    this->frameConditionVariable.notify_all();
}

FrameState FrameStateStore::getFrame(int indexAgo)
{
    this->mutex.lock();
    int index = this->size - indexAgo - 1;
    FrameState frame = this->frames[index < 0 ? 0 : index];
    this->mutex.unlock();
    return frame;
}

long FrameStateStore::getFrameCounter()
{
    this->mutex.lock();
    long counter = this->counter;
    this->mutex.unlock();
    return counter;
}

void FrameStateStore::waitForNextFrame()
{
    std::unique_lock<std::recursive_mutex> lock(this->mutex);
    long start = this->counter;
    for (;;)
    {
        this->frameConditionVariable.wait(lock);
        if (this->counter > start)
        {
            break;
        }
    }
}

void FrameStateStore::lock()
{
    this->mutex.lock();
}

void FrameStateStore::unlock()
{
    this->mutex.unlock();
}
