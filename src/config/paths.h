#pragma once

#include <string>

namespace vapor::config::paths
{
    extern std::string systemDataDir;
    extern std::string userConfigDir;
    extern std::string userDataDir;

    std::string selectDataDirForFile(const std::string& relativePath);

    void setDataDirs();
}
