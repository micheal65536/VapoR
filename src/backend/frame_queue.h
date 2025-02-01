#pragma once

#include "openxr.h"

#include <cstdint>
#include <shared_mutex>

#include <vulkan/vulkan.h>

namespace vapor
{
    class FrameQueue
    {
        public:
            struct Memory
            {
                VkDeviceMemory vulkanMemory;
                int fd;
                int size;
            };

            FrameQueue(int frameWidth, int frameHeight);
            ~FrameQueue();

            int getDrawBufferIndex(int eyeIndex) const;
            int getDisplayBufferIndex(int eyeIndex) const;
            const OpenXR::ViewPair& getDisplayViews() const;
            bool hasDisplayFrame() const;

            void swapBuffers(const OpenXR::ViewPair& views);
            void lockBufferSwap();
            void unlockBufferSwap();

            Memory memory[4];

        private:
            OpenXR::ViewPair displayViews;
            bool displayFrameSubmitted = false;
            int bufferSwap;
            std::shared_mutex swapMutex;
    };
}
