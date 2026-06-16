#pragma once

#include <string>

namespace vapor::config
{
    class StartupParams
    {
        public:
            bool parse(const std::string& startupParamsString);

            std::string actionManifestPath = "";
    };
}
