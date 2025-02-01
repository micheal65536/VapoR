#include "paths.h"

#include <cstdlib>
#include <filesystem>

namespace vapor::config::paths
{
    std::string dataDir;

    void setDataDir()
    {
        const char* vaporDirEnv = std::getenv("VAPOR_DIR");
        const char* homeEnv = std::getenv("HOME");
        std::filesystem::path path;
        if (vaporDirEnv != nullptr)
        {
            path = std::string(vaporDirEnv);
        }
        else if (homeEnv != nullptr)
        {
            path = std::string(homeEnv);
            path /= ".VapoR";
        }
        else
        {
            path = "/";
        }

        dataDir = std::filesystem::absolute(path);
    }
}
