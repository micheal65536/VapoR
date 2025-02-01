#pragma once

#include "../types.h"
#include <cstdint>
#include <vulkan/vulkan.h>
#include "client_core.h"

namespace openvr
{
    class RenderModelsImpl
    {
        public:
            ClientCoreImpl& clientCore;
            RenderModelsImpl(ClientCoreImpl& clientCore);

            //

            RenderModelError loadRenderModel(const char* modelName, RenderModel_0_9_12** model);
            void freeRenderModel(RenderModel_0_9_12* model);
            RenderModelError loadTexture(int32_t textureId, RenderModelTextureMap** texture);
            void freeTexture(RenderModelTextureMap* texture);

            uint32_t getRenderModelName(uint32_t index, char* name, uint32_t bufferSize);
            uint32_t getRenderModelCount();

            uint32_t getComponentCount(const char* modelName);
            uint32_t getComponentName(const char* modelName, uint32_t componentIndex, char* componentName, uint32_t bufferSize);
            uint64_t getComponentButtonMask(const char* modelName, const char* componentName);
            uint32_t getComponentRenderModelName(const char* modelName, const char* componentName, char* componentRenderModelName, uint32_t bufferSize);
            bool getComponentStateForDevicePath(const char* modelName, const char* componentName, uint64_t inputDeviceHandle, const RenderModelControllerModeState* controllerModeState, RenderModelComponentState* componentState);
            bool getComponentState(const char* modelName, const char* componentName, const ControllerState* controllerState, const RenderModelControllerModeState* controllerModeState, RenderModelComponentState* componentState);
            bool renderModelHasComponent(const char* modelName, const char* componentName);

            uint32_t getRenderModelThumbnailURL(const char* modelName, char* url, uint32_t bufferSize, RenderModelError* error);

            uint32_t getRenderModelOriginalPath(const char* modelName, char* originalPath, uint32_t bufferSize, RenderModelError* error);

            const char* getRenderModelErrorNameFromEnum(RenderModelError error);
    };
}
