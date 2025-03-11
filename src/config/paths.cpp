#include "paths.h"

#include <cstdlib>
#include <filesystem>

namespace vapor::config::paths
{
    std::string systemDataDir;
    std::string userConfigDir;
    std::string userDataDir;

    static inline bool checkIfFileExists(const std::filesystem::path& path)
    {
        try
        {
            return std::filesystem::exists(path);
        }
        catch (const std::filesystem::filesystem_error& exception)
        {
            return false;
        }
    }

    std::string selectDataDirForFile(const std::string& relativePath)
    {
        std::filesystem::path path;
        path = std::filesystem::path(userDataDir) / relativePath;
        if (!systemDataDir.empty() && !checkIfFileExists(path))
        {
            path = std::filesystem::path(systemDataDir) / relativePath;
        }
        return path.string();
    }

    static inline std::string getEnv(const std::string& name)
    {
        const char* env = std::getenv(name.c_str());
        return env != nullptr ? std::string(env) : "";
    }

    void setDataDirs()
    {
        #ifdef VAPOR_SYSTEM_DATA_PATH
            systemDataDir = VAPOR_SYSTEM_DATA_PATH;
        #else
            systemDataDir = "";
        #endif

        std::filesystem::path configDirPath;
        std::filesystem::path dataDirPath;
        std::string vaporDirEnv = getEnv("VAPOR_DIR");
        if (!vaporDirEnv.empty())
        {
            configDirPath = dataDirPath = vaporDirEnv;
        }
        else
        {
            std::string homeEnv = getEnv("HOME");
            std::string xdgConfigHomeEnv = getEnv("XDG_CONFIG_HOME");
            std::string xdgDataHomeEnv = getEnv("XDG_DATA_HOME");
            configDirPath = !xdgConfigHomeEnv.empty() ? xdgConfigHomeEnv : (homeEnv + "/.config");
            dataDirPath = !xdgDataHomeEnv.empty() ? xdgDataHomeEnv : (homeEnv + "/.local/share");
            configDirPath /= "VapoR";
            dataDirPath /= "VapoR";
        }
        userConfigDir = std::filesystem::absolute(configDirPath);
        userDataDir = std::filesystem::absolute(dataDirPath);
    }
}
