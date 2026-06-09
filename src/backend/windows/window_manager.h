#pragma once

#include <list>
#include <map>

#include "window.h"

#include <mutex>

namespace vapor
{
    namespace windows
    {
        class WindowManager
        {
            public:
                WindowManager();
                ~WindowManager();

                void addWindow(Window* window);
                void removeWindow(Window* window);
                const std::list<Window*>& getWindows();

                //

                inline void lock()
                {
                    mutex.lock();
                }

                inline void unlock()
                {
                    mutex.unlock();
                }

            private:
                std::list<Window*> windows;

                std::recursive_mutex mutex;
        };
    }
}
