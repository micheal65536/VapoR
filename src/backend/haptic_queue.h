#pragma once

#include <cstdint>

#include <list>
#include <mutex>

namespace vapor
{
    class HapticQueue
    {
        public:
            struct HapticEvent
            {
                int durationUs;
                float frequency;
                float amplitude;

                int inputOrControllerIndex;
                bool fromLegacyInput;
            };

            void queueHapticEvent(int openVRinputIndex, int durationUs, float frequency, float amplitude);
            void queueLegacyHapticEvent(int controllerIndex, int durationUs);

            bool pollHapticEvent(HapticEvent* event);

        private:
            std::list<HapticEvent> queue;
            std::mutex mutex;
    };
}
