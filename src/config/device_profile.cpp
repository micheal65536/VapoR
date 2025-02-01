#include "device_profile.h"

#include <nlohmann/json.hpp>
#include <fstream>

#include "log/log.h"

using namespace vapor::config;

using namespace nlohmann;

bool DeviceProfile::populateFromJSON(const std::string& filePath)
{
    TRACE_F("Reading device profile from %s", filePath.c_str());

    try
    {
        std::ifstream stream(filePath);
        json j = json::parse(stream);

        inputProfileName = j.at("input_profile");

        hmdPropertySetName = j.at("hmd").at("properties");
        hmdRenderModelName = j.at("hmd").contains("render_model") ? j.at("hmd").at("render_model") : "generic_hmd";
        controllerPropertySetNames[0] = j.at("controller_left").at("properties");
        controllerRenderModelNames[0] = j.at("controller_left").contains("render_model") ? j.at("controller_left").at("render_model") : "generic_controller";
        controllerPropertySetNames[1] = j.at("controller_right").at("properties");
        controllerRenderModelNames[1] = j.at("controller_right").contains("render_model") ? j.at("controller_right").at("render_model") : "generic_controller";

        return true;
    }
    catch (const std::exception& exception)
    {
        TRACE_F("Failed to load device profile");
        return false;
    }
}
