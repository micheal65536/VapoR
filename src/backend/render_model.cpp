#include "render_model.h"

#include <stdexcept>

#include <nlohmann/json.hpp>
#include <fstream>

#include "log/log.h"

#include "config/paths.h"

using namespace vapor;

using namespace nlohmann;

int RenderModel::getComponentsCount() const
{
    return components.size();
}

const RenderModel::Component* RenderModel::getComponent(int index) const
{
    if (index >= 0 && index < components.size())
    {
        return &components[index];
    }
    else
    {
        return nullptr;
    }
}

const RenderModel::Component* RenderModel::getComponent(const std::string& name) const
{
    for (const auto& it: components)
    {
        if (it.name == name)
        {
            return &it;
        }
    }
    return nullptr;
}

//

namespace openvr
{
    void to_json(json& j, const Matrix34& value)
    {
        j = json::array();
        for (int row = 0; row < 3; row++)
        {
            j[row] = json::array();
            for (int col = 0; col < 4; col++)
            {
                j[row][col] = value.m[row][col];
            }
        }
    }

    void from_json(const json& j, Matrix34& value)
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 4; col++)
            {
                value.m[row][col] = j.at(row).at(col).get<float>();
            }
        }
    }
}

namespace vapor
{
    void to_json(json& j, const LegacyInputButtonSet& value)
    {
        j = json::array();
        if (value.system)
        {
            j.push_back("system");
        }
        if (value.menu)
        {
            j.push_back("menu");
        }
        if (value.grip)
        {
            j.push_back("grip");
        }
        if (value.dpadLeft)
        {
            j.push_back("dpad_left");
        }
        if (value.dpadUp)
        {
            j.push_back("dpad_up");
        }
        if (value.dpadRight)
        {
            j.push_back("dpad_right");
        }
        if (value.dpadDown)
        {
            j.push_back("dpad_down");
        }
        if (value.buttonA)
        {
            j.push_back("button_a");
        }
        if (value.axis0)
        {
            j.push_back("axis0");
        }
        if (value.axis1)
        {
            j.push_back("axis1");
        }
        if (value.axis2)
        {
            j.push_back("axis2");
        }
        if (value.axis3)
        {
            j.push_back("axis3");
        }
        if (value.axis4)
        {
            j.push_back("axis4");
        }
    }

    void from_json(const json& j, LegacyInputButtonSet& value)
    {
        value = LegacyInputButtonSet();
        for (const std::string& name: j)
        {
            value.system |= name == "system";
            value.menu |= name == "menu";
            value.grip |= name == "grip";
            value.dpadLeft |= name == "dpad_left";
            value.dpadUp |= name == "dpad_up";
            value.dpadRight |= name == "dpad_right";
            value.dpadDown |= name == "dpad_down";
            value.buttonA |= name == "button_a";
            value.axis0 |= name == "axis0";
            value.axis1 |= name == "axis1";
            value.axis2 |= name == "axis2";
            value.axis3 |= name == "axis3";
            value.axis4 |= name == "axis4";
        }
    }
}

bool RenderModelLoader::addDefinitionFromJSON(const std::string& filePath)
{
    TRACE_F("Reading render model definition from %s", filePath.c_str());

    try
    {
        std::ifstream stream(filePath);
        json j = json::parse(stream);

        std::string name = j.at("name");

        std::vector<RenderModel::Component> components;
        for (auto it: j.at("components"))
        {
            static openvr::Matrix34 identityMatrix = {
                .m {
                    { 1.0f, 0.0f, 0.0f, 0.0f },
                    { 0.0f, 1.0f, 0.0f, 0.0f },
                    { 0.0f, 0.0f, 1.0f, 0.0f }
                }
            };

            std::string componentName = it.at("name");
            components.push_back((RenderModel::Component) {
                .name = componentName,
                .fullName = name + "/" + componentName,
                .hasModel = it.contains("has_model") ? it.at("has_model").get<bool>() : true,
                .fixed = it.contains("static") ? it.at("static").get<bool>() : true,
                .visible = it.contains("visible") ? it.at("visible").get<bool>() : true,
                .buttonMask = it.contains("buttons") ? it.at("buttons").get<LegacyInputButtonSet>() : LegacyInputButtonSet(),
                .renderTransform = it.contains("transform") && it.at("transform").contains("render") ? it.at("transform").at("render").get<openvr::Matrix34>() : identityMatrix,
                .localSpaceTransform = it.contains("transform") && it.at("transform").contains("local_space") ? it.at("transform").at("local_space").get<openvr::Matrix34>() : identityMatrix
            });
        }

        definedModels.push_back((RenderModel) {
            .name = name,
            .components = components
        });

        return true;
    }
    catch (const std::exception& exception)
    {
        TRACE_F("Failed to load render model definition");
        return false;
    }
}

openvr::RenderModel_0_9_12* RenderModelLoader::loadModel(const std::string& name) const
{
    TRACE_F("Loading render model %s", name.c_str());

    openvr::RenderModel_0_9_12* renderModel = new openvr::RenderModel_0_9_12();
    renderModel->vertices = nullptr;
    renderModel->indices = nullptr;

    try
    {
        std::ifstream stream(config::paths::selectDataDirForFile("render_models/" + name + ".bin"), std::ios::binary);

        stream.read((char*) &renderModel->vertexCount, sizeof(uint32_t));
        renderModel->vertices = new openvr::RenderModelVertex[renderModel->vertexCount];
        float* fbuffer = new float[renderModel->vertexCount * 8];
        stream.read((char*) fbuffer, sizeof(float) * renderModel->vertexCount * 8);
        for (int i = 0; i < renderModel->vertexCount; i++)
        {
            openvr::RenderModelVertex& vertex = renderModel->vertices[i];
            vertex.position.v[0] = fbuffer[i * 8 + 0];
            vertex.position.v[1] = fbuffer[i * 8 + 1];
            vertex.position.v[2] = fbuffer[i * 8 + 2];
            vertex.normal.v[0] = fbuffer[i * 8 + 3];
            vertex.normal.v[1] = fbuffer[i * 8 + 4];
            vertex.normal.v[2] = fbuffer[i * 8 + 5];
            vertex.uv[0] = fbuffer[i * 8 + 6];
            vertex.uv[1] = fbuffer[i * 8 + 7];
        }
        delete[] fbuffer;

        stream.read((char*) &renderModel->triangleCount, sizeof(uint32_t));
        renderModel->indices = new uint16_t[renderModel->triangleCount * 3];
        stream.read((char*) renderModel->indices, sizeof(uint16_t) * renderModel->triangleCount * 3);

        renderModel->textureId = 0; // TODO

        return renderModel;
    }
    catch (const std::exception& exception)
    {
        TRACE_F("Failed to load render model");

        if (renderModel->vertices != nullptr)
        {
            delete[] renderModel->vertices;
        }
        if (renderModel->indices != nullptr)
        {
            delete[] renderModel->indices;
        }
        delete renderModel;

        return nullptr;
    }
}

int RenderModelLoader::getDefinedModelsCount() const
{
    return definedModels.size();
}

const RenderModel* RenderModelLoader::getDefinedModel(int index) const
{
    if (index >= 0 && index < definedModels.size())
    {
        return &definedModels[index];
    }
    else
    {
        return nullptr;
    }
}

const RenderModel* RenderModelLoader::getDefinedModel(const std::string& name) const
{
    for (const auto& it: definedModels)
    {
        if (it.name == name)
        {
            return &it;
        }
    }
    return nullptr;
}
