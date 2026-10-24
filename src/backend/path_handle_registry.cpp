#include "path_handle_registry.h"

#include <atomic>

#include "log/log.h"

#include "utils/string.h"

namespace vapor
{
    PathHandleRegistry pathHandleRegistry;
}

static std::atomic<uint64_t> nextHandle = 1;

using namespace vapor;

uint64_t PathHandleRegistry::getHandle(const std::string& path)
{
    std::string pathLowercase = utils::stringToLowercase(path);

    mutex.lock();
    uint64_t handle;
    if (pathToHandleMap.contains(pathLowercase))
    {
        handle = pathToHandleMap[pathLowercase];
    }
    else
    {
        handle = nextHandle++;
        pathToHandleMap[pathLowercase] = handle;
        handleToPathMap[handle] = pathLowercase;
        TRACE_F("new handle %d %s", handle, pathLowercase.c_str());
    }
    mutex.unlock();
    return handle;
}

std::string PathHandleRegistry::getPath(uint64_t handle)
{
    mutex.lock();
    std::string path;
    if (handleToPathMap.contains(handle))
    {
        path = handleToPathMap[handle];
    }
    else
    {
        path = "";
    }
    mutex.unlock();
    return path;
}
