#pragma once

#include "pose_set.h"
#include "openvr/types_event.h"

#include <list>
#include <mutex>

namespace vapor
{
    class EventQueue
    {
        public:
            void putEvent(const openvr::Event_0_9_15& event);
            void putEvent(const openvr::Event_0_9_15& event, const PoseSet& poseSet);
            bool pollEvent(openvr::Event_0_9_15* eventBufferFullSize, PoseSet* poseSet);

        private:
            struct EventWithPose
            {
                openvr::Event_0_9_15 event;
                PoseSet poseSet;
            };

            std::list<EventWithPose> queue;
            std::mutex mutex;
    };
}
