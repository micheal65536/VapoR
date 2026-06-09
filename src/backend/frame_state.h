#pragma once

#include <vector>
#include <mutex>
#include <condition_variable>

#include "openxr.h"
#include "pose_set.h"

namespace vapor
{
    struct FrameState
    {
        long index;

        long displayTime;

        OpenXR::ViewPair views;

        OpenXR::ViewPair renderViews;

        PoseSet head;
        PoseSet controllerPoses[2];
    };

    class FrameStateStore
    {
        public:
            FrameStateStore(int size);
            ~FrameStateStore();

            void postFrame(FrameState frame);

            FrameState getFrame(int indexAgo) const;

            long getFrameCounter() const;
            void waitForNextFrame() const;

            // these are provided in case we want to retrieve multiple frames without the risk of a new frame being posted in-between, or we want to post a frame and do additional work such as queuing events atomically before allowing the new frame to become visible to the OpenVR client
            // it is not required to call lock/unlock merely to retrieve a single frame
            void lock() const;
            void unlock() const;

        private:
            int size;
            int filled = 0;
            long counter = 0;
            FrameState* frames;
            mutable std::recursive_mutex mutex;
            mutable std::condition_variable_any frameConditionVariable;
    };
}
