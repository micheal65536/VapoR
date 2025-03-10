#include "rendermodel.h"
#include "log/log.h"
#include "log/stub.h"

#include "input/input_source_utils.h"
#include "input/path_handle_registry.h"
#include "utils/legacy_input.h"

#include <cstring>

using namespace openvr;

RenderModelsImpl::RenderModelsImpl(ClientCoreImpl& clientCore): clientCore(clientCore)
{
    // empty
}

RenderModelError RenderModelsImpl::loadRenderModel(const char* modelName, RenderModel_0_9_12** model)
{
    TRACE_F("%s", modelName);

    // TODO: async loading

    RenderModel_0_9_12* model1 = this->clientCore.backend->renderModelLoader->loadModel(modelName);
    if (model1 == nullptr)
    {
        return RenderModelError::RENDER_MODEL_ERROR_INVALID_MODEL;
    }

    *model = model1;
    return RenderModelError::RENDER_MODEL_ERROR_NONE;
}

void RenderModelsImpl::freeRenderModel(RenderModel_0_9_12* model)
{
    TRACE();
    if (model != nullptr)
    {
        delete[] model->vertices;
        delete[] model->indices;
        delete model;
    }
}

RenderModelError RenderModelsImpl::loadTexture(int32_t textureId, RenderModelTextureMap** texture)
{
    STUB_F("%d", textureId);
    uint8_t* data = new uint8_t[4];
    data[0] = 255;
    data[1] = 0;
    data[2] = 0;
    data[3] = 255;
    *texture = new RenderModelTextureMap {
        .width = 1,
        .height = 1,
        .data = data,
        .format = RenderModelTextureFormat::RENDER_MODEL_TEXTURE_FORMAT_RGBA8_SRGB,
        .mipLevels = 1
    };
    return RenderModelError::RENDER_MODEL_ERROR_NONE;
}

void RenderModelsImpl::freeTexture(RenderModelTextureMap* texture)
{
    STUB();
    delete[] texture->data;
    delete texture;
}

uint32_t RenderModelsImpl::getRenderModelName(uint32_t index, char* name, uint32_t bufferSize)
{
    TRACE_F("%d", index);
    const vapor::RenderModel* renderModel = this->clientCore.backend->renderModelLoader->getDefinedModel(index);
    if (renderModel == nullptr)
    {
        return 0;
    }
    uint32_t requiredBufferSize = renderModel->name.length() + 1;
    if (bufferSize >= requiredBufferSize)
    {
        std::memcpy(name, renderModel->name.c_str(), requiredBufferSize);
    }
    return requiredBufferSize;
}

uint32_t RenderModelsImpl::getRenderModelCount()
{
    TRACE();
    return this->clientCore.backend->renderModelLoader->getDefinedModelsCount();
}

uint32_t RenderModelsImpl::getComponentCount(const char* modelName)
{
    TRACE_F("%s", modelName);
    const vapor::RenderModel* renderModel = this->clientCore.backend->renderModelLoader->getDefinedModel(modelName);
    if (renderModel == nullptr)
    {
        return 0;
    }
    return renderModel->getComponentsCount();
}

uint32_t RenderModelsImpl::getComponentName(const char* modelName, uint32_t componentIndex, char* componentName, uint32_t bufferSize)
{
    TRACE_F("%s %d", modelName, componentIndex);
    const vapor::RenderModel* renderModel = this->clientCore.backend->renderModelLoader->getDefinedModel(modelName);
    if (renderModel == nullptr)
    {
        return 0;
    }
    const vapor::RenderModel::Component* component = renderModel->getComponent(componentIndex);
    if (component == nullptr)
    {
        return 0;
    }
    uint32_t requiredBufferSize = component->name.length() + 1;
    if (bufferSize >= requiredBufferSize)
    {
        std::memcpy(componentName, component->name.c_str(), requiredBufferSize);
    }
    return requiredBufferSize;
}

uint64_t RenderModelsImpl::getComponentButtonMask(const char* modelName, const char* componentName)
{
    TRACE_F("%s %s", modelName, componentName);
    const vapor::RenderModel* renderModel = this->clientCore.backend->renderModelLoader->getDefinedModel(modelName);
    if (renderModel == nullptr)
    {
        return 0;
    }
    const vapor::RenderModel::Component* component = renderModel->getComponent(componentName);
    if (component == nullptr)
    {
        return 0;
    }
    return utils::makeLegacyInputButtonsBitmap(component->buttonMask);
}

uint32_t RenderModelsImpl::getComponentRenderModelName(const char* modelName, const char* componentName, char* componentRenderModelName, uint32_t bufferSize)
{
    TRACE_F("%s %s", modelName, componentName);
    const vapor::RenderModel* renderModel = this->clientCore.backend->renderModelLoader->getDefinedModel(modelName);
    if (renderModel == nullptr)
    {
        return 0;
    }
    const vapor::RenderModel::Component* component = renderModel->getComponent(componentName);
    if (component == nullptr)
    {
        return 0;
    }
    if (!component->hasModel)
    {
        return 0;
    }
    uint32_t requiredBufferSize = component->fullName.length() + 1;
    if (bufferSize >= requiredBufferSize)
    {
        std::memcpy(componentRenderModelName, component->fullName.c_str(), requiredBufferSize);
    }
    return requiredBufferSize;
}

static inline bool getComponentStateFromLegacyInputState(const vapor::RenderModelLoader& renderModelLoader, const char* modelName, const char* componentName, const vapor::LegacyInputState& inputState, const RenderModelControllerModeState* controllerModeState, RenderModelComponentState* componentState)
{
    const vapor::RenderModel* renderModel = renderModelLoader.getDefinedModel(modelName);
    if (renderModel == nullptr)
    {
        return false;
    }
    const vapor::RenderModel::Component* component = renderModel->getComponent(componentName);
    if (component == nullptr)
    {
        return false;
    }

    // TODO: transform change when inputs are pressed/moved
    componentState->renderTransform = component->renderTransform;
    componentState->localSpaceTransform = component->localSpaceTransform;

    // TODO: extra properties (SCROLLED/HIGHLIGHTED) (and property change (VISIBLE) based on press state?)
    componentState->properties = 0;
    if (component->fixed)
    {
        componentState->properties |= RenderModelComponentState::ComponentProperty::STATIC;
    }
    if (component->visible)
    {
        componentState->properties |= RenderModelComponentState::ComponentProperty::VISIBLE;
    }
    if ((utils::makeLegacyInputButtonsBitmap(inputState.touch) & utils::makeLegacyInputButtonsBitmap(component->buttonMask)) != 0)
    {
        componentState->properties |= RenderModelComponentState::ComponentProperty::TOUCHED;
    }
    if ((utils::makeLegacyInputButtonsBitmap(inputState.click) & utils::makeLegacyInputButtonsBitmap(component->buttonMask)) != 0)
    {
        componentState->properties |= RenderModelComponentState::ComponentProperty::PRESSED;
    }

    return true;
}

bool RenderModelsImpl::getComponentStateForDevicePath(const char* modelName, const char* componentName, uint64_t inputDeviceHandle, const RenderModelControllerModeState* controllerModeState, RenderModelComponentState* componentState)
{
    TRACE_F("%s %s %d", modelName, componentName, inputDeviceHandle);

    int controllerIndex;
    switch (input::getDeviceFromInputSourcePath(input::pathHandleRegistry.getPath(inputDeviceHandle), false))
    {
        case input::Device::HAND_LEFT:
            controllerIndex = 0;
            break;
        case input::Device::HAND_RIGHT:
            controllerIndex = 1;
            break;
        default:
            return false;
    }

    vapor::FrameState frame = this->clientCore.backend->frameStates.getFrame(0);
    const vapor::LegacyInputState& legacyInputState = frame.legacyInputStates[controllerIndex];
    return getComponentStateFromLegacyInputState(*this->clientCore.backend->renderModelLoader, modelName, componentName, legacyInputState, controllerModeState, componentState);
}

bool RenderModelsImpl::getComponentState(const char* modelName, const char* componentName, const ControllerState* controllerState, const RenderModelControllerModeState* controllerModeState, RenderModelComponentState* componentState)
{
    TRACE_F("%s %s", modelName, componentName);

    vapor::LegacyInputState legacyInputState;
    utils::decodeLegacyInputButtonsBitmap(controllerState->buttonsTouched, legacyInputState.touch);
    utils::decodeLegacyInputButtonsBitmap(controllerState->buttonsPressed, legacyInputState.click);
    for (int i = 0; i < 5; i++)
    {
        legacyInputState.axes[i] = {.x = controllerState->axes[i].x, .y = controllerState->axes[i].y};
    }

    return getComponentStateFromLegacyInputState(*this->clientCore.backend->renderModelLoader, modelName, componentName, legacyInputState, controllerModeState, componentState);
}

bool RenderModelsImpl::renderModelHasComponent(const char* modelName, const char* componentName)
{
    TRACE_F("%s %s", modelName, componentName);
    const vapor::RenderModel* renderModel = this->clientCore.backend->renderModelLoader->getDefinedModel(modelName);
    if (renderModel == nullptr)
    {
        return false;
    }
    const vapor::RenderModel::Component* component = renderModel->getComponent(componentName);
    return component != nullptr;
}

uint32_t RenderModelsImpl::getRenderModelThumbnailURL(const char* modelName, char* url, uint32_t bufferSize, RenderModelError* error)
{
    STUB();
    return 0;
}

uint32_t RenderModelsImpl::getRenderModelOriginalPath(const char* modelName, char* originalPath, uint32_t bufferSize, RenderModelError* error)
{
    TRACE_F("%s", modelName);
    uint32_t requiredBufferSize = std::strlen(modelName) + 1;
    if (bufferSize >= requiredBufferSize)
    {
        std::memcpy(originalPath, modelName, requiredBufferSize);
        if (error != nullptr)
        {
            *error = RenderModelError::RENDER_MODEL_ERROR_NONE;
        }
    }
    else
    {
        if (error != nullptr)
        {
            *error = RenderModelError::RENDER_MODEL_ERROR_BUFFER_TOO_SMALL;
        }
    }
    return requiredBufferSize;
}

const char* RenderModelsImpl::getRenderModelErrorNameFromEnum(RenderModelError error)
{
    STUB_F("%d", error);
    return "";
}
