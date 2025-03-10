#include "path_handle_registry.h"

#include <atomic>

#include "log/log.h"

namespace openvr
{
    namespace input
    {
        PathHandleRegistry pathHandleRegistry;
    }
}

static std::atomic<uint64_t> nextHandle = 1;

using namespace openvr::input;

uint64_t PathHandleRegistry::getHandle(const std::string& path)
{
    mutex.lock();
    uint64_t handle;
    if (pathToHandleMap.contains(path))
    {
        handle = pathToHandleMap[path];
    }
    else
    {
        handle = nextHandle++;
        pathToHandleMap[path] = handle;
        handleToPathMap[handle] = path;
        TRACE_F("new handle %d %s", handle, path.c_str());
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
