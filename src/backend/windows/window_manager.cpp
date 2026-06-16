#include "window_manager.h"

using namespace vapor::windows;

WindowManager::WindowManager()
{
    // TODO
}

WindowManager::~WindowManager()
{
    // TODO
}

void WindowManager::addWindow(Window* window)
{
    mutex.lock();
    this->windows.push_back(window);
    mutex.unlock();
}

void WindowManager::removeWindow(Window* window)
{
    mutex.lock();
    this->windows.remove(window);
    mutex.unlock();
}

const std::list<Window*>& WindowManager::getWindows()
{
    return this->windows;
}
