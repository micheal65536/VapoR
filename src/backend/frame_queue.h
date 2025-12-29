#pragma once

#include "vulkan_exported_texture_holder.h"
#include "openxr.h"

#include <array>
#include <shared_mutex>

#include <vulkan/vulkan.h>

namespace vapor
{
    class FrameQueue
    {
        public:
            bool hasBufferTextureSetChanged();
            const std::array<VulkanExportedTextureHolder, 4>* getBufferTextureSet() const;
            int getDisplayBufferIndex(int eyeIndex) const;
            const OpenXR::ViewPair& getDisplayViews() const;
            bool hasDisplayFrame() const;

            void swapBuffers(const std::array<VulkanExportedTextureHolder, 4>* bufferTextureSet, int leftEyeBufferIndex, int rightEyeBufferIndex, const OpenXR::ViewPair& views);
            void lockBufferSwap();
            void unlockBufferSwap();

        private:
            const std::array<VulkanExportedTextureHolder, 4>* bufferTextureSet = nullptr;
            bool hasBufferTextureSetChangedFlag = false;
            int leftEyeDisplayBufferIndex;
            int rightEyeDisplayBufferIndex;
            OpenXR::ViewPair displayViews;

            std::shared_mutex swapMutex;
    };
}
