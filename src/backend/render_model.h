#pragma once

#include <string>
#include <vector>

#include "openvr/types_rendermodel.h"
#include "backend/legacy_input.h"

namespace vapor
{
    struct RenderModel
    {
        struct Component
        {
            std::string name;
            std::string fullName;
            bool hasModel;

            bool fixed;
            bool visible;

            LegacyInputButtonSet buttonMask;

            openvr::Matrix34 renderTransform;
            openvr::Matrix34 localSpaceTransform;
        };

        std::string name;
        std::vector<Component> components;

        int getComponentsCount() const;
        const Component* getComponent(int index) const;
        const Component* getComponent(const std::string& name) const;
    };

    class RenderModelLoader
    {
        public:
            bool addDefinitionFromJSON(const std::string& filePath);

            openvr::RenderModel_0_9_12* loadModel(const std::string& name) const;

            int getDefinedModelsCount() const;
            const RenderModel* getDefinedModel(int index) const;
            const RenderModel* getDefinedModel(const std::string& name) const;

        private:
            std::vector<RenderModel> definedModels;
    };
}
