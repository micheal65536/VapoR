#include "rendermodel.h"
#include "../impl/init.h"
#include "log/stub.h"

using namespace openvr;

bool RenderModels_001::loadRenderModel(const char* modelName, RenderModel_0_9_0** model)
{
    // TODO
    STUB();
    return false;
}

bool RenderModels_002::loadRenderModel(const char* modelName, RenderModel_0_9_12** model)
{
    return openvr::renderModelsImpl->loadRenderModel(modelName, model) == RenderModelError::RENDER_MODEL_ERROR_NONE;
}

RenderModelError RenderModels_004::loadRenderModel(const char* modelName, RenderModel_0_9_12** model)
{
    return openvr::renderModelsImpl->loadRenderModel(modelName, model);
}

RenderModelError RenderModels_005::loadRenderModel(const char* modelName, RenderModel_0_9_12** model)
{
    return openvr::renderModelsImpl->loadRenderModel(modelName, model);
}

RenderModelError RenderModels_006::loadRenderModel(const char* modelName, RenderModel_0_9_12** model)
{
    return openvr::renderModelsImpl->loadRenderModel(modelName, model);
}

void RenderModels_001::freeRenderModel(RenderModel_0_9_0* model)
{
    // TODO
    STUB();
}

void RenderModels_002::freeRenderModel(RenderModel_0_9_12* model)
{
    openvr::renderModelsImpl->freeRenderModel(model);
}

void RenderModels_004::freeRenderModel(RenderModel_0_9_12* model)
{
    openvr::renderModelsImpl->freeRenderModel(model);
}

void RenderModels_005::freeRenderModel(RenderModel_0_9_12* model)
{
    openvr::renderModelsImpl->freeRenderModel(model);
}

void RenderModels_006::freeRenderModel(RenderModel_0_9_12* model)
{
    openvr::renderModelsImpl->freeRenderModel(model);
}

bool RenderModels_002::loadTexture(int32_t textureId, RenderModelTextureMap** texture)
{
    return openvr::renderModelsImpl->loadTexture(textureId, texture) == RenderModelError::RENDER_MODEL_ERROR_NONE;
}

RenderModelError RenderModels_004::loadTexture(int32_t textureId, RenderModelTextureMap** texture)
{
    return openvr::renderModelsImpl->loadTexture(textureId, texture);
}

RenderModelError RenderModels_005::loadTexture(int32_t textureId, RenderModelTextureMap** texture)
{
    return openvr::renderModelsImpl->loadTexture(textureId, texture);
}

RenderModelError RenderModels_006::loadTexture(int32_t textureId, RenderModelTextureMap** texture)
{
    return openvr::renderModelsImpl->loadTexture(textureId, texture);
}

void RenderModels_002::freeTexture(RenderModelTextureMap* texture)
{
    openvr::renderModelsImpl->freeTexture(texture);
}

void RenderModels_004::freeTexture(RenderModelTextureMap* texture)
{
    openvr::renderModelsImpl->freeTexture(texture);
}

void RenderModels_005::freeTexture(RenderModelTextureMap* texture)
{
    openvr::renderModelsImpl->freeTexture(texture);
}

void RenderModels_006::freeTexture(RenderModelTextureMap* texture)
{
    openvr::renderModelsImpl->freeTexture(texture);
}

RenderModelError RenderModels_004::loadTextureD3D11(int32_t textureId, void* device, void** texture)
{
    STUB();
}

RenderModelError RenderModels_005::loadTextureD3D11(int32_t textureId, void* device, void** texture)
{
    STUB();
}

RenderModelError RenderModels_006::loadTextureD3D11(int32_t textureId, void* device, void** texture)
{
    STUB();
}

RenderModelError RenderModels_005::loadIntoTextureD3D11(int32_t textureId, void* texture)
{
    STUB();
}

RenderModelError RenderModels_006::loadIntoTextureD3D11(int32_t textureId, void* texture)
{
    STUB();
}

void RenderModels_004::freeTextureD3D11(void* texture)
{
    STUB();
}

void RenderModels_005::freeTextureD3D11(void* texture)
{
    STUB();
}

void RenderModels_006::freeTextureD3D11(void* texture)
{
    STUB();
}

uint32_t RenderModels_001::getRenderModelName(uint32_t index, char* name, uint32_t bufferSize)
{
    return openvr::renderModelsImpl->getRenderModelName(index, name, bufferSize);
}

uint32_t RenderModels_002::getRenderModelName(uint32_t index, char* name, uint32_t bufferSize)
{
    return openvr::renderModelsImpl->getRenderModelName(index, name, bufferSize);
}

uint32_t RenderModels_004::getRenderModelName(uint32_t index, char* name, uint32_t bufferSize)
{
    return openvr::renderModelsImpl->getRenderModelName(index, name, bufferSize);
}

uint32_t RenderModels_005::getRenderModelName(uint32_t index, char* name, uint32_t bufferSize)
{
    return openvr::renderModelsImpl->getRenderModelName(index, name, bufferSize);
}

uint32_t RenderModels_006::getRenderModelName(uint32_t index, char* name, uint32_t bufferSize)
{
    return openvr::renderModelsImpl->getRenderModelName(index, name, bufferSize);
}

uint32_t RenderModels_001::getRenderModelCount()
{
    return openvr::renderModelsImpl->getRenderModelCount();
}

uint32_t RenderModels_002::getRenderModelCount()
{
    return openvr::renderModelsImpl->getRenderModelCount();
}

uint32_t RenderModels_004::getRenderModelCount()
{
    return openvr::renderModelsImpl->getRenderModelCount();
}

uint32_t RenderModels_005::getRenderModelCount()
{
    return openvr::renderModelsImpl->getRenderModelCount();
}

uint32_t RenderModels_006::getRenderModelCount()
{
    return openvr::renderModelsImpl->getRenderModelCount();
}

uint32_t RenderModels_001::getComponentCount(const char* modelName)
{
    return openvr::renderModelsImpl->getComponentCount(modelName);
}

uint32_t RenderModels_002::getComponentCount(const char* modelName)
{
    return openvr::renderModelsImpl->getComponentCount(modelName);
}

uint32_t RenderModels_004::getComponentCount(const char* modelName)
{
    return openvr::renderModelsImpl->getComponentCount(modelName);
}

uint32_t RenderModels_005::getComponentCount(const char* modelName)
{
    return openvr::renderModelsImpl->getComponentCount(modelName);
}

uint32_t RenderModels_006::getComponentCount(const char* modelName)
{
    return openvr::renderModelsImpl->getComponentCount(modelName);
}

uint32_t RenderModels_001::getComponentName(const char* modelName, uint32_t componentIndex, char* componentName, uint32_t bufferSize)
{
    return openvr::renderModelsImpl->getComponentName(modelName, componentIndex, componentName, bufferSize);
}

uint32_t RenderModels_002::getComponentName(const char* modelName, uint32_t componentIndex, char* componentName, uint32_t bufferSize)
{
    return openvr::renderModelsImpl->getComponentName(modelName, componentIndex, componentName, bufferSize);
}

uint32_t RenderModels_004::getComponentName(const char* modelName, uint32_t componentIndex, char* componentName, uint32_t bufferSize)
{
    return openvr::renderModelsImpl->getComponentName(modelName, componentIndex, componentName, bufferSize);
}

uint32_t RenderModels_005::getComponentName(const char* modelName, uint32_t componentIndex, char* componentName, uint32_t bufferSize)
{
    return openvr::renderModelsImpl->getComponentName(modelName, componentIndex, componentName, bufferSize);
}

uint32_t RenderModels_006::getComponentName(const char* modelName, uint32_t componentIndex, char* componentName, uint32_t bufferSize)
{
    return openvr::renderModelsImpl->getComponentName(modelName, componentIndex, componentName, bufferSize);
}

uint64_t RenderModels_001::getComponentButtonMask(const char* modelName, const char* componentName)
{
    return openvr::renderModelsImpl->getComponentButtonMask(modelName, componentName);
}

uint64_t RenderModels_002::getComponentButtonMask(const char* modelName, const char* componentName)
{
    return openvr::renderModelsImpl->getComponentButtonMask(modelName, componentName);
}

uint64_t RenderModels_004::getComponentButtonMask(const char* modelName, const char* componentName)
{
    return openvr::renderModelsImpl->getComponentButtonMask(modelName, componentName);
}

uint64_t RenderModels_005::getComponentButtonMask(const char* modelName, const char* componentName)
{
    return openvr::renderModelsImpl->getComponentButtonMask(modelName, componentName);
}

uint64_t RenderModels_006::getComponentButtonMask(const char* modelName, const char* componentName)
{
    return openvr::renderModelsImpl->getComponentButtonMask(modelName, componentName);
}

uint32_t RenderModels_001::getComponentRenderModelName(const char* modelName, const char* componentName, char* componentRenderModelName, uint32_t bufferSize)
{
    return openvr::renderModelsImpl->getComponentRenderModelName(modelName, componentName, componentRenderModelName, bufferSize);
}

uint32_t RenderModels_002::getComponentRenderModelName(const char* modelName, const char* componentName, char* componentRenderModelName, uint32_t bufferSize)
{
    return openvr::renderModelsImpl->getComponentRenderModelName(modelName, componentName, componentRenderModelName, bufferSize);
}

uint32_t RenderModels_004::getComponentRenderModelName(const char* modelName, const char* componentName, char* componentRenderModelName, uint32_t bufferSize)
{
    return openvr::renderModelsImpl->getComponentRenderModelName(modelName, componentName, componentRenderModelName, bufferSize);
}

uint32_t RenderModels_005::getComponentRenderModelName(const char* modelName, const char* componentName, char* componentRenderModelName, uint32_t bufferSize)
{
    return openvr::renderModelsImpl->getComponentRenderModelName(modelName, componentName, componentRenderModelName, bufferSize);
}

uint32_t RenderModels_006::getComponentRenderModelName(const char* modelName, const char* componentName, char* componentRenderModelName, uint32_t bufferSize)
{
    return openvr::renderModelsImpl->getComponentRenderModelName(modelName, componentName, componentRenderModelName, bufferSize);
}

bool RenderModels_006::getComponentStateForDevicePath(const char* modelName, const char* componentName, uint64_t inputDeviceHandle, const RenderModelControllerModeState* controllerModeState, RenderModelComponentState* componentState)
{
    return openvr::renderModelsImpl->getComponentStateForDevicePath(modelName, componentName, inputDeviceHandle, controllerModeState, componentState);
}

bool RenderModels_001::getComponentState(const char* modelName, const char* componentName, ControllerState controllerState, RenderModelComponentState* componentState)
{
    RenderModelControllerModeState controllerModeState {
        .scrollWheelVisible = false // TODO: determine correct default setting
    };
    return openvr::renderModelsImpl->getComponentState(modelName, componentName, &controllerState, &controllerModeState, componentState);
}

bool RenderModels_002::getComponentState(const char* modelName, const char* componentName, const ControllerState* controllerState, RenderModelComponentState* componentState)
{
    RenderModelControllerModeState controllerModeState {
        .scrollWheelVisible = false // TODO: determine correct default setting
    };
    return openvr::renderModelsImpl->getComponentState(modelName, componentName, controllerState, &controllerModeState, componentState);
}

bool RenderModels_004::getComponentState(const char* modelName, const char* componentName, const ControllerState* controllerState, const RenderModelControllerModeState* controllerModeState, RenderModelComponentState* componentState)
{
    return openvr::renderModelsImpl->getComponentState(modelName, componentName, controllerState, controllerModeState, componentState);
}

bool RenderModels_005::getComponentState(const char* modelName, const char* componentName, const ControllerState* controllerState, const RenderModelControllerModeState* controllerModeState, RenderModelComponentState* componentState)
{
    return openvr::renderModelsImpl->getComponentState(modelName, componentName, controllerState, controllerModeState, componentState);
}

bool RenderModels_006::getComponentState(const char* modelName, const char* componentName, const ControllerState* controllerState, const RenderModelControllerModeState* controllerModeState, RenderModelComponentState* componentState)
{
    return openvr::renderModelsImpl->getComponentState(modelName, componentName, controllerState, controllerModeState, componentState);
}

bool RenderModels_002::renderModelHasComponent(const char* modelName, const char* componentName)
{
    return openvr::renderModelsImpl->renderModelHasComponent(modelName, componentName);
}

bool RenderModels_004::renderModelHasComponent(const char* modelName, const char* componentName)
{
    return openvr::renderModelsImpl->renderModelHasComponent(modelName, componentName);
}

bool RenderModels_005::renderModelHasComponent(const char* modelName, const char* componentName)
{
    return openvr::renderModelsImpl->renderModelHasComponent(modelName, componentName);
}

bool RenderModels_006::renderModelHasComponent(const char* modelName, const char* componentName)
{
    return openvr::renderModelsImpl->renderModelHasComponent(modelName, componentName);
}

uint32_t RenderModels_005::getRenderModelThumbnailURL(const char* modelName, char* url, uint32_t bufferSize, RenderModelError* error)
{
    return openvr::renderModelsImpl->getRenderModelThumbnailURL(modelName, url, bufferSize, error);
}

uint32_t RenderModels_006::getRenderModelThumbnailURL(const char* modelName, char* url, uint32_t bufferSize, RenderModelError* error)
{
    return openvr::renderModelsImpl->getRenderModelThumbnailURL(modelName, url, bufferSize, error);
}

uint32_t RenderModels_005::getRenderModelOriginalPath(const char* modelName, char* originalPath, uint32_t bufferSize, RenderModelError* error)
{
    return openvr::renderModelsImpl->getRenderModelOriginalPath(modelName, originalPath, bufferSize, error);
}

uint32_t RenderModels_006::getRenderModelOriginalPath(const char* modelName, char* originalPath, uint32_t bufferSize, RenderModelError* error)
{
    return openvr::renderModelsImpl->getRenderModelOriginalPath(modelName, originalPath, bufferSize, error);
}

const char* RenderModels_005::getRenderModelErrorNameFromEnum(RenderModelError error)
{
    return openvr::renderModelsImpl->getRenderModelErrorNameFromEnum(error);
}

const char* RenderModels_006::getRenderModelErrorNameFromEnum(RenderModelError error)
{
    return openvr::renderModelsImpl->getRenderModelErrorNameFromEnum(error);
}
