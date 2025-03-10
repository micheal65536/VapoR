#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>
#include <mutex>

namespace openvr
{
    namespace input
    {
        class PathHandleRegistry
        {
            public:
                uint64_t getHandle(const std::string& path);
                std::string getPath(uint64_t handle);

            private:
                std::unordered_map<std::string, uint64_t> pathToHandleMap;
                std::unordered_map<uint64_t, std::string> handleToPathMap;
                std::mutex mutex;
        };

        extern PathHandleRegistry pathHandleRegistry;
    }
}
