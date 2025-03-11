#include "config.h"

#include "paths.h"
#include "fixes.h"

#include <nlohmann/json.hpp>
#include <fstream>

#include "log/log.h"

using namespace vapor::config;

using namespace nlohmann;

namespace vapor::config::config
{
    std::string deviceProfileName = "generic";
}

static bool loadConfigFromFile(const std::string& filePath)
{
    LOG("Attempting to load config from %s", filePath.c_str());

    try
    {
        std::ifstream stream(filePath);
        json j = json::parse(stream);

        if (j.contains("device_profile"))
        {
            config::deviceProfileName = j.at("device_profile");
        }

        if (j.contains("fixes"))
        {
            json& fixes = j.at("fixes");
            if (fixes.contains("flip"))
            {
                fixes::flipImage = fixes.at("flip");
            }
            if (fixes.contains("linear_colorspace"))
            {
                fixes::createVulkanTargetInLinearColorspace = fixes.at("linear_colorspace");
            }
        }

        LOG("Loaded config");

        return true;
    }
    catch (const std::exception& exception)
    {
        return false;
    }
}

void vapor::config::config::loadConfig()
{
    if (!paths::systemDataDir.empty())
    {
        loadConfigFromFile(paths::systemDataDir + "/config.json");
    }
    loadConfigFromFile(paths::userConfigDir + "/config.json");
    loadConfigFromFile("vapor_config.json");
}
