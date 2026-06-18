#include "startup_params.h"

#include <nlohmann/json.hpp>
#include <fstream>

#include "log/log.h"

using namespace vapor::config;

using namespace nlohmann;

bool StartupParams::parse(const std::string& startupParamsString)
{
    if (startupParamsString == "")
    {
        return true;
    }

    // NOTE: there is no official documentation on the format of the startup parameters and supposedly this is "reserved for future use", but it appears to be a JSON object

    TRACE_F("Parsing startup params %s", startupParamsString.c_str());

    try
    {
        json j = json::parse(startupParamsString);

        if (j.contains("action_manifest_path"))
        {
            actionManifestPath = j.at("action_manifest_path");
        }

        return true;
    }
    catch (const std::exception& exception)
    {
        TRACE_F("Failed to parse startup params");
        return false;
    }
}
