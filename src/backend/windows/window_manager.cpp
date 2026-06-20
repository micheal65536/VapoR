#include "window_manager.h"

#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>

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

std::list<Window*> WindowManager::getWindowsForRender(const PoseSet& head, bool dashboardIsOpen)
{
    // TODO: properly handle dashboard visibility (I think there's a flag that causes a non-dashboard overlay to be hidden when the dashboard is open?)
    // TODO: group subview overlays with parent
    // TODO: how are we supposed to handle OverlayRelativeTransform?

    std::vector<std::tuple<int, float, Window*>> windowsSorted;
    mutex.lock();
    for (auto& it: windows)
    {
        windows::Window* window = it;
        window->lock();
        if ((!window->dashboard && !window->visible) || (window->dashboard && !dashboardIsOpen))
        {
            window->unlock();
            continue;
        }
        if (window->transform == nullptr)
        {
            window->unlock();
            continue;
        }
        float headPose[3][4];
        window->transform->getHeadPoseToUse(head, &headPose);
        const float (&windowPose)[3][4] = window->transform->getOverlayToWorldTransformMatrix();
        float dx = windowPose[0][3] - headPose[0][3];
        float dy = windowPose[1][3] - headPose[1][3];
        float dz = windowPose[2][3] - headPose[2][3];
        float distance = std::sqrt(dx * dx + dy * dy + dz * dz);
        windowsSorted.push_back(std::tuple<int, float, Window*>(-window->sortOrder, distance, window));
        window->unlock();
    }
    mutex.unlock();

    std::sort(windowsSorted.begin(), windowsSorted.end());
    std::reverse(windowsSorted.begin(), windowsSorted.end());

    std::list<Window*> renderWindows;
    for (auto& it: windowsSorted)
    {
        renderWindows.push_back(std::get<2>(it));
    }
    return renderWindows;
}
