#include "haptic_queue.h"

using namespace vapor;

void HapticQueue::queueHapticEvent(int openVRinputIndex, int durationUs, float frequency, float amplitude)
{
    this->mutex.lock();
    this->queue.push_back(HapticEvent {.durationUs = durationUs, .frequency = frequency, .amplitude = amplitude, .inputOrControllerIndex = openVRinputIndex, .fromLegacyInput = false});
    this->mutex.unlock();
}

void HapticQueue::queueLegacyHapticEvent(int controllerIndex, int durationUs)
{
    this->mutex.lock();
    this->queue.push_back(HapticEvent {.durationUs = durationUs, .frequency = 0.0f, .amplitude = 0.0f, .inputOrControllerIndex = controllerIndex, .fromLegacyInput = true});
    this->mutex.unlock();
}

bool HapticQueue::pollHapticEvent(HapticEvent* event)
{
    bool haveEvent;
    this->mutex.lock();
    haveEvent = !this->queue.empty();
    if (haveEvent)
    {
        *event = this->queue.front();
        this->queue.pop_front();
    }
    this->mutex.unlock();
    return haveEvent;
}
