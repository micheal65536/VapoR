#pragma once

#include <string>

namespace vapor::config
{
    class DeviceProfile
    {
        public:
            bool populateFromJSON(const std::string& filePath);

            std::string inputProfileName;

            std::string hmdPropertySetName;
            std::string hmdRenderModelName;
            std::string controllerPropertySetNames[2];
            std::string controllerRenderModelNames[2];
    };
}
