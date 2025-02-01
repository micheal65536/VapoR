#include "event_queue.h"

using namespace vapor;

void EventQueue::putEvent(const openvr::Event_0_9_15& event)
{
    this->mutex.lock();
    this->queue.push_back(EventWithPose {.event = event});
    this->mutex.unlock();
}

void EventQueue::putEvent(const openvr::Event_0_9_15& event, const PoseSet& poseSet)
{
    this->mutex.lock();
    this->queue.push_back(EventWithPose {.event = event, .poseSet = poseSet});
    this->mutex.unlock();
}

bool EventQueue::pollEvent(openvr::Event_0_9_15* eventBufferFullSize, PoseSet* poseSet)
{
    bool haveEvent;
    this->mutex.lock();
    haveEvent = !this->queue.empty();
    if (haveEvent)
    {
        *eventBufferFullSize = this->queue.front().event;
        if (poseSet != nullptr)
        {
            *poseSet = this->queue.front().poseSet;
        }
        this->queue.pop_front();
    }
    this->mutex.unlock();
    return haveEvent;
}
