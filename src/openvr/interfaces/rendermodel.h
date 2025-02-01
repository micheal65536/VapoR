#pragma once

#include "../types.h"
#include <cstdint>

#include "../impl/rendermodel.h"

namespace openvr
{
    struct RenderModels_001
    {
        static bool loadRenderModel(const char* modelName, RenderModel_0_9_0** model);
        static void freeRenderModel(RenderModel_0_9_0* model);

        static uint32_t getRenderModelName(uint32_t index, char* name, uint32_t bufferSize);
        static uint32_t getRenderModelCount();

        static uint32_t getComponentCount(const char* modelName);
        static uint32_t getComponentName(const char* modelName, uint32_t componentIndex, char* componentName, uint32_t bufferSize);
        static uint64_t getComponentButtonMask(const char* modelName, const char* componentName);
        static uint32_t getComponentRenderModelName(const char* modelName, const char* componentName, char* componentRenderModelName, uint32_t bufferSize);
        static bool getComponentState(const char* modelName, const char* componentName, ControllerState controllerState, RenderModelComponentState* componentState);
    
        void* loadRenderModel_ = (void*) loadRenderModel;
        void* freeRenderModel_ = (void*) freeRenderModel;
        void* getRenderModelName_ = (void*) getRenderModelName;
        void* getRenderModelCount_ = (void*) getRenderModelCount;
        void* getComponentCount_ = (void*) getComponentCount;
        void* getComponentName_ = (void*) getComponentName;
        void* getComponentButtonMask_ = (void*) getComponentButtonMask;
        void* getComponentRenderModelName_ = (void*) getComponentRenderModelName;
        void* getComponentState_ = (void*) getComponentState;
    };

    class RenderModels_001_v
    {
        public:
            virtual bool loadRenderModel(const char* modelName, RenderModel_0_9_0** model) { return RenderModels_001::loadRenderModel(modelName, model); }
            virtual void freeRenderModel(RenderModel_0_9_0* model) { return RenderModels_001::freeRenderModel(model); }
            virtual uint32_t getRenderModelName(uint32_t index, char* name, uint32_t bufferSize) { return RenderModels_001::getRenderModelName(index, name, bufferSize); }
            virtual uint32_t getRenderModelCount() { return RenderModels_001::getRenderModelCount(); }
            virtual uint32_t getComponentCount(const char* modelName) { return RenderModels_001::getComponentCount(modelName); }
            virtual uint32_t getComponentName(const char* modelName, uint32_t componentIndex, char* componentName, uint32_t bufferSize) { return RenderModels_001::getComponentName(modelName, componentIndex, componentName, bufferSize); }
            virtual uint64_t getComponentButtonMask(const char* modelName, const char* componentName) { return RenderModels_001::getComponentButtonMask(modelName, componentName); }
            virtual uint32_t getComponentRenderModelName(const char* modelName, const char* componentName, char* componentRenderModelName, uint32_t bufferSize) { return RenderModels_001::getComponentRenderModelName(modelName, componentName, componentRenderModelName, bufferSize); }
            virtual bool getComponentState(const char* modelName, const char* componentName, ControllerState controllerState, RenderModelComponentState* componentState) { return RenderModels_001::getComponentState(modelName, componentName, controllerState, componentState); }
    };

    //

    struct RenderModels_002
    {
        static bool loadRenderModel(const char* modelName, RenderModel_0_9_12** model);
        static void freeRenderModel(RenderModel_0_9_12* model);
        static bool loadTexture(int32_t textureId, RenderModelTextureMap** texture);
        static void freeTexture(RenderModelTextureMap* texture);

        static uint32_t getRenderModelName(uint32_t index, char* name, uint32_t bufferSize);
        static uint32_t getRenderModelCount();

        static uint32_t getComponentCount(const char* modelName);
        static uint32_t getComponentName(const char* modelName, uint32_t componentIndex, char* componentName, uint32_t bufferSize);
        static uint64_t getComponentButtonMask(const char* modelName, const char* componentName);
        static uint32_t getComponentRenderModelName(const char* modelName, const char* componentName, char* componentRenderModelName, uint32_t bufferSize);
        static bool getComponentState(const char* modelName, const char* componentName, const ControllerState* controllerState, RenderModelComponentState* componentState);
        static bool renderModelHasComponent(const char* modelName, const char* componentName);
    
        void* loadRenderModel_ = (void*) loadRenderModel;
        void* freeRenderModel_ = (void*) freeRenderModel;
        void* loadTexture_ = (void*) loadTexture;
        void* freeTexture_ = (void*) freeTexture;
        void* getRenderModelName_ = (void*) getRenderModelName;
        void* getRenderModelCount_ = (void*) getRenderModelCount;
        void* getComponentCount_ = (void*) getComponentCount;
        void* getComponentName_ = (void*) getComponentName;
        void* getComponentButtonMask_ = (void*) getComponentButtonMask;
        void* getComponentRenderModelName_ = (void*) getComponentRenderModelName;
        void* getComponentState_ = (void*) getComponentState;
        void* renderModelHasComponent_ = (void*) renderModelHasComponent;
    };

    class RenderModels_002_v
    {
        public:
            virtual bool loadRenderModel(const char* modelName, RenderModel_0_9_12** model) { return RenderModels_002::loadRenderModel(modelName, model); }
            virtual void freeRenderModel(RenderModel_0_9_12* model) { return RenderModels_002::freeRenderModel(model); }
            virtual bool loadTexture(int32_t textureId, RenderModelTextureMap** texture) { return RenderModels_002::loadTexture(textureId, texture); }
            virtual void freeTexture(RenderModelTextureMap* texture) { return RenderModels_002::freeTexture(texture); }
            virtual uint32_t getRenderModelName(uint32_t index, char* name, uint32_t bufferSize) { return RenderModels_002::getRenderModelName(index, name, bufferSize); }
            virtual uint32_t getRenderModelCount() { return RenderModels_002::getRenderModelCount(); }
            virtual uint32_t getComponentCount(const char* modelName) { return RenderModels_002::getComponentCount(modelName); }
            virtual uint32_t getComponentName(const char* modelName, uint32_t componentIndex, char* componentName, uint32_t bufferSize) { return RenderModels_002::getComponentName(modelName, componentIndex, componentName, bufferSize); }
            virtual uint64_t getComponentButtonMask(const char* modelName, const char* componentName) { return RenderModels_002::getComponentButtonMask(modelName, componentName); }
            virtual uint32_t getComponentRenderModelName(const char* modelName, const char* componentName, char* componentRenderModelName, uint32_t bufferSize) { return RenderModels_002::getComponentRenderModelName(modelName, componentName, componentRenderModelName, bufferSize); }
            virtual bool getComponentState(const char* modelName, const char* componentName, const ControllerState* controllerState, RenderModelComponentState* componentState) { return RenderModels_002::getComponentState(modelName, componentName, controllerState, componentState); }
            virtual bool renderModelHasComponent(const char* modelName, const char* componentName) { return RenderModels_002::renderModelHasComponent(modelName, componentName); }
    };

    //

    struct RenderModels_004
    {
        static RenderModelError loadRenderModel(const char* modelName, RenderModel_0_9_12** model);
        static void freeRenderModel(RenderModel_0_9_12* model);
        static RenderModelError loadTexture(int32_t textureId, RenderModelTextureMap** texture);
        static void freeTexture(RenderModelTextureMap* texture);
        static RenderModelError loadTextureD3D11(int32_t textureId, void* device, void** texture);
        static void freeTextureD3D11(void* texture);

        static uint32_t getRenderModelName(uint32_t index, char* name, uint32_t bufferSize);
        static uint32_t getRenderModelCount();

        static uint32_t getComponentCount(const char* modelName);
        static uint32_t getComponentName(const char* modelName, uint32_t componentIndex, char* componentName, uint32_t bufferSize);
        static uint64_t getComponentButtonMask(const char* modelName, const char* componentName);
        static uint32_t getComponentRenderModelName(const char* modelName, const char* componentName, char* componentRenderModelName, uint32_t bufferSize);
        static bool getComponentState(const char* modelName, const char* componentName, const ControllerState* controllerState, const RenderModelControllerModeState* controllerModeState, RenderModelComponentState* componentState);
        static bool renderModelHasComponent(const char* modelName, const char* componentName);
    
        void* loadRenderModel_ = (void*) loadRenderModel;
        void* freeRenderModel_ = (void*) freeRenderModel;
        void* loadTexture_ = (void*) loadTexture;
        void* freeTexture_ = (void*) freeTexture;
        void* loadTextureD3D11_ = (void*) loadTextureD3D11;
        void* freeTextureD3D11_ = (void*) freeTextureD3D11;
        void* getRenderModelName_ = (void*) getRenderModelName;
        void* getRenderModelCount_ = (void*) getRenderModelCount;
        void* getComponentCount_ = (void*) getComponentCount;
        void* getComponentName_ = (void*) getComponentName;
        void* getComponentButtonMask_ = (void*) getComponentButtonMask;
        void* getComponentRenderModelName_ = (void*) getComponentRenderModelName;
        void* getComponentState_ = (void*) getComponentState;
        void* renderModelHasComponent_ = (void*) renderModelHasComponent;
    };

    class RenderModels_004_v
    {
        public:
            virtual RenderModelError loadRenderModel(const char* modelName, RenderModel_0_9_12** model) { return RenderModels_004::loadRenderModel(modelName, model); }
            virtual void freeRenderModel(RenderModel_0_9_12* model) { return RenderModels_004::freeRenderModel(model); }
            virtual RenderModelError loadTexture(int32_t textureId, RenderModelTextureMap** texture) { return RenderModels_004::loadTexture(textureId, texture); }
            virtual void freeTexture(RenderModelTextureMap* texture) { return RenderModels_004::freeTexture(texture); }
            virtual RenderModelError loadTextureD3D11(int32_t textureId, void* device, void** texture) { return RenderModels_004::loadTextureD3D11(textureId, device, texture); }
            virtual void freeTextureD3D11(void* texture) { return RenderModels_004::freeTextureD3D11(texture); }
            virtual uint32_t getRenderModelName(uint32_t index, char* name, uint32_t bufferSize) { return RenderModels_004::getRenderModelName(index, name, bufferSize); }
            virtual uint32_t getRenderModelCount() { return RenderModels_004::getRenderModelCount(); }
            virtual uint32_t getComponentCount(const char* modelName) { return RenderModels_004::getComponentCount(modelName); }
            virtual uint32_t getComponentName(const char* modelName, uint32_t componentIndex, char* componentName, uint32_t bufferSize) { return RenderModels_004::getComponentName(modelName, componentIndex, componentName, bufferSize); }
            virtual uint64_t getComponentButtonMask(const char* modelName, const char* componentName) { return RenderModels_004::getComponentButtonMask(modelName, componentName); }
            virtual uint32_t getComponentRenderModelName(const char* modelName, const char* componentName, char* componentRenderModelName, uint32_t bufferSize) { return RenderModels_004::getComponentRenderModelName(modelName, componentName, componentRenderModelName, bufferSize); }
            virtual bool getComponentState(const char* modelName, const char* componentName, const ControllerState* controllerState, const RenderModelControllerModeState* controllerModeState, RenderModelComponentState* componentState) { return RenderModels_004::getComponentState(modelName, componentName, controllerState, controllerModeState, componentState); }
            virtual bool renderModelHasComponent(const char* modelName, const char* componentName) { return RenderModels_004::renderModelHasComponent(modelName, componentName); }
    };

    //

    struct RenderModels_005
    {
        static RenderModelError loadRenderModel(const char* modelName, RenderModel_0_9_12** model);
        static void freeRenderModel(RenderModel_0_9_12* model);
        static RenderModelError loadTexture(int32_t textureId, RenderModelTextureMap** texture);
        static void freeTexture(RenderModelTextureMap* texture);
        static RenderModelError loadTextureD3D11(int32_t textureId, void* device, void** texture);
        static RenderModelError loadIntoTextureD3D11(int32_t textureId, void* texture);
        static void freeTextureD3D11(void* texture);

        static uint32_t getRenderModelName(uint32_t index, char* name, uint32_t bufferSize);
        static uint32_t getRenderModelCount();

        static uint32_t getComponentCount(const char* modelName);
        static uint32_t getComponentName(const char* modelName, uint32_t componentIndex, char* componentName, uint32_t bufferSize);
        static uint64_t getComponentButtonMask(const char* modelName, const char* componentName);
        static uint32_t getComponentRenderModelName(const char* modelName, const char* componentName, char* componentRenderModelName, uint32_t bufferSize);
        static bool getComponentState(const char* modelName, const char* componentName, const ControllerState* controllerState, const RenderModelControllerModeState* controllerModeState, RenderModelComponentState* componentState);
        static bool renderModelHasComponent(const char* modelName, const char* componentName);

        static uint32_t getRenderModelThumbnailURL(const char* modelName, char* url, uint32_t bufferSize, RenderModelError* error);

        static uint32_t getRenderModelOriginalPath(const char* modelName, char* originalPath, uint32_t bufferSize, RenderModelError* error);

        static const char* getRenderModelErrorNameFromEnum(RenderModelError error);
    
        void* loadRenderModel_ = (void*) loadRenderModel;
        void* freeRenderModel_ = (void*) freeRenderModel;
        void* loadTexture_ = (void*) loadTexture;
        void* freeTexture_ = (void*) freeTexture;
        void* loadTextureD3D11_ = (void*) loadTextureD3D11;
        void* loadIntoTextureD3D11_ = (void*) loadIntoTextureD3D11;
        void* freeTextureD3D11_ = (void*) freeTextureD3D11;
        void* getRenderModelName_ = (void*) getRenderModelName;
        void* getRenderModelCount_ = (void*) getRenderModelCount;
        void* getComponentCount_ = (void*) getComponentCount;
        void* getComponentName_ = (void*) getComponentName;
        void* getComponentButtonMask_ = (void*) getComponentButtonMask;
        void* getComponentRenderModelName_ = (void*) getComponentRenderModelName;
        void* getComponentState_ = (void*) getComponentState;
        void* renderModelHasComponent_ = (void*) renderModelHasComponent;
        void* getRenderModelThumbnailURL_ = (void*) getRenderModelThumbnailURL;
        void* getRenderModelOriginalPath_ = (void*) getRenderModelOriginalPath;
        void* getRenderModelErrorNameFromEnum_ = (void*) getRenderModelErrorNameFromEnum;
    };

    class RenderModels_005_v
    {
        public:
            virtual RenderModelError loadRenderModel(const char* modelName, RenderModel_0_9_12** model) { return RenderModels_005::loadRenderModel(modelName, model); }
            virtual void freeRenderModel(RenderModel_0_9_12* model) { return RenderModels_005::freeRenderModel(model); }
            virtual RenderModelError loadTexture(int32_t textureId, RenderModelTextureMap** texture) { return RenderModels_005::loadTexture(textureId, texture); }
            virtual void freeTexture(RenderModelTextureMap* texture) { return RenderModels_005::freeTexture(texture); }
            virtual RenderModelError loadTextureD3D11(int32_t textureId, void* device, void** texture) { return RenderModels_005::loadTextureD3D11(textureId, device, texture); }
            virtual RenderModelError loadIntoTextureD3D11(int32_t textureId, void* texture) { return RenderModels_005::loadIntoTextureD3D11(textureId, texture); }
            virtual void freeTextureD3D11(void* texture) { return RenderModels_005::freeTextureD3D11(texture); }
            virtual uint32_t getRenderModelName(uint32_t index, char* name, uint32_t bufferSize) { return RenderModels_005::getRenderModelName(index, name, bufferSize); }
            virtual uint32_t getRenderModelCount() { return RenderModels_005::getRenderModelCount(); }
            virtual uint32_t getComponentCount(const char* modelName) { return RenderModels_005::getComponentCount(modelName); }
            virtual uint32_t getComponentName(const char* modelName, uint32_t componentIndex, char* componentName, uint32_t bufferSize) { return RenderModels_005::getComponentName(modelName, componentIndex, componentName, bufferSize); }
            virtual uint64_t getComponentButtonMask(const char* modelName, const char* componentName) { return RenderModels_005::getComponentButtonMask(modelName, componentName); }
            virtual uint32_t getComponentRenderModelName(const char* modelName, const char* componentName, char* componentRenderModelName, uint32_t bufferSize) { return RenderModels_005::getComponentRenderModelName(modelName, componentName, componentRenderModelName, bufferSize); }
            virtual bool getComponentState(const char* modelName, const char* componentName, const ControllerState* controllerState, const RenderModelControllerModeState* controllerModeState, RenderModelComponentState* componentState) { return RenderModels_005::getComponentState(modelName, componentName, controllerState, controllerModeState, componentState); }
            virtual bool renderModelHasComponent(const char* modelName, const char* componentName) { return RenderModels_005::renderModelHasComponent(modelName, componentName); }
            virtual uint32_t getRenderModelThumbnailURL(const char* modelName, char* url, uint32_t bufferSize, RenderModelError* error) { return RenderModels_005::getRenderModelThumbnailURL(modelName, url, bufferSize, error); }
            virtual uint32_t getRenderModelOriginalPath(const char* modelName, char* originalPath, uint32_t bufferSize, RenderModelError* error) { return RenderModels_005::getRenderModelOriginalPath(modelName, originalPath, bufferSize, error); }
            virtual const char* getRenderModelErrorNameFromEnum(RenderModelError error) { return RenderModels_005::getRenderModelErrorNameFromEnum(error); }
    };

    //

    struct RenderModels_006
    {
        static RenderModelError loadRenderModel(const char* modelName, RenderModel_0_9_12** model);
        static void freeRenderModel(RenderModel_0_9_12* model);
        static RenderModelError loadTexture(int32_t textureId, RenderModelTextureMap** texture);
        static void freeTexture(RenderModelTextureMap* texture);
        static RenderModelError loadTextureD3D11(int32_t textureId, void* device, void** texture);
        static RenderModelError loadIntoTextureD3D11(int32_t textureId, void* texture);
        static void freeTextureD3D11(void* texture);

        static uint32_t getRenderModelName(uint32_t index, char* name, uint32_t bufferSize);
        static uint32_t getRenderModelCount();

        static uint32_t getComponentCount(const char* modelName);
        static uint32_t getComponentName(const char* modelName, uint32_t componentIndex, char* componentName, uint32_t bufferSize);
        static uint64_t getComponentButtonMask(const char* modelName, const char* componentName);
        static uint32_t getComponentRenderModelName(const char* modelName, const char* componentName, char* componentRenderModelName, uint32_t bufferSize);
        static bool getComponentStateForDevicePath(const char* modelName, const char* componentName, uint64_t inputDeviceHandle, const RenderModelControllerModeState* controllerModeState, RenderModelComponentState* componentState);
        static bool getComponentState(const char* modelName, const char* componentName, const ControllerState* controllerState, const RenderModelControllerModeState* controllerModeState, RenderModelComponentState* componentState);
        static bool renderModelHasComponent(const char* modelName, const char* componentName);

        static uint32_t getRenderModelThumbnailURL(const char* modelName, char* url, uint32_t bufferSize, RenderModelError* error);

        static uint32_t getRenderModelOriginalPath(const char* modelName, char* originalPath, uint32_t bufferSize, RenderModelError* error);

        static const char* getRenderModelErrorNameFromEnum(RenderModelError error);
    
        void* loadRenderModel_ = (void*) loadRenderModel;
        void* freeRenderModel_ = (void*) freeRenderModel;
        void* loadTexture_ = (void*) loadTexture;
        void* freeTexture_ = (void*) freeTexture;
        void* loadTextureD3D11_ = (void*) loadTextureD3D11;
        void* loadIntoTextureD3D11_ = (void*) loadIntoTextureD3D11;
        void* freeTextureD3D11_ = (void*) freeTextureD3D11;
        void* getRenderModelName_ = (void*) getRenderModelName;
        void* getRenderModelCount_ = (void*) getRenderModelCount;
        void* getComponentCount_ = (void*) getComponentCount;
        void* getComponentName_ = (void*) getComponentName;
        void* getComponentButtonMask_ = (void*) getComponentButtonMask;
        void* getComponentRenderModelName_ = (void*) getComponentRenderModelName;
        void* getComponentStateForDevicePath_ = (void*) getComponentStateForDevicePath;
        void* getComponentState_ = (void*) getComponentState;
        void* renderModelHasComponent_ = (void*) renderModelHasComponent;
        void* getRenderModelThumbnailURL_ = (void*) getRenderModelThumbnailURL;
        void* getRenderModelOriginalPath_ = (void*) getRenderModelOriginalPath;
        void* getRenderModelErrorNameFromEnum_ = (void*) getRenderModelErrorNameFromEnum;
    };

    class RenderModels_006_v
    {
        public:
            virtual RenderModelError loadRenderModel(const char* modelName, RenderModel_0_9_12** model) { return RenderModels_006::loadRenderModel(modelName, model); }
            virtual void freeRenderModel(RenderModel_0_9_12* model) { return RenderModels_006::freeRenderModel(model); }
            virtual RenderModelError loadTexture(int32_t textureId, RenderModelTextureMap** texture) { return RenderModels_006::loadTexture(textureId, texture); }
            virtual void freeTexture(RenderModelTextureMap* texture) { return RenderModels_006::freeTexture(texture); }
            virtual RenderModelError loadTextureD3D11(int32_t textureId, void* device, void** texture) { return RenderModels_006::loadTextureD3D11(textureId, device, texture); }
            virtual RenderModelError loadIntoTextureD3D11(int32_t textureId, void* texture) { return RenderModels_006::loadIntoTextureD3D11(textureId, texture); }
            virtual void freeTextureD3D11(void* texture) { return RenderModels_006::freeTextureD3D11(texture); }
            virtual uint32_t getRenderModelName(uint32_t index, char* name, uint32_t bufferSize) { return RenderModels_006::getRenderModelName(index, name, bufferSize); }
            virtual uint32_t getRenderModelCount() { return RenderModels_006::getRenderModelCount(); }
            virtual uint32_t getComponentCount(const char* modelName) { return RenderModels_006::getComponentCount(modelName); }
            virtual uint32_t getComponentName(const char* modelName, uint32_t componentIndex, char* componentName, uint32_t bufferSize) { return RenderModels_006::getComponentName(modelName, componentIndex, componentName, bufferSize); }
            virtual uint64_t getComponentButtonMask(const char* modelName, const char* componentName) { return RenderModels_006::getComponentButtonMask(modelName, componentName); }
            virtual uint32_t getComponentRenderModelName(const char* modelName, const char* componentName, char* componentRenderModelName, uint32_t bufferSize) { return RenderModels_006::getComponentRenderModelName(modelName, componentName, componentRenderModelName, bufferSize); }
            virtual bool getComponentStateForDevicePath(const char* modelName, const char* componentName, uint64_t inputDeviceHandle, const RenderModelControllerModeState* controllerModeState, RenderModelComponentState* componentState) { return RenderModels_006::getComponentStateForDevicePath(modelName, componentName, inputDeviceHandle, controllerModeState, componentState); }
            virtual bool getComponentState(const char* modelName, const char* componentName, const ControllerState* controllerState, const RenderModelControllerModeState* controllerModeState, RenderModelComponentState* componentState) { return RenderModels_006::getComponentState(modelName, componentName, controllerState, controllerModeState, componentState); }
            virtual bool renderModelHasComponent(const char* modelName, const char* componentName) { return RenderModels_006::renderModelHasComponent(modelName, componentName); }
            virtual uint32_t getRenderModelThumbnailURL(const char* modelName, char* url, uint32_t bufferSize, RenderModelError* error) { return RenderModels_006::getRenderModelThumbnailURL(modelName, url, bufferSize, error); }
            virtual uint32_t getRenderModelOriginalPath(const char* modelName, char* originalPath, uint32_t bufferSize, RenderModelError* error) { return RenderModels_006::getRenderModelOriginalPath(modelName, originalPath, bufferSize, error); }
            virtual const char* getRenderModelErrorNameFromEnum(RenderModelError error) { return RenderModels_006::getRenderModelErrorNameFromEnum(error); }
    };
}
