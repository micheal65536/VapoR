#pragma once

#include "openvr/interfaces/interfaces.h"

#include <map>
#include <string>

namespace openvr
{
    extern ClientCoreImpl* clientCoreImpl;
    extern SystemImpl* systemImpl;
    extern CompositorImpl* compositorImpl;
    extern InputImpl* inputImpl;
    extern ChaperoneImpl* chaperoneImpl;
    //extern OverlayImpl* overlayImpl;
    extern RenderModelsImpl* renderModelsImpl;
    extern SettingsImpl* settingsImpl;
    extern ScreenshotsImpl* screenshotsImpl;
    extern ChaperoneSetupImpl* chaperoneSetupImpl;
    extern ApplicationsImpl* applicationsImpl;
    extern ExtendedDisplayImpl* extendedDisplayImpl;

    extern std::map<std::string, void*> createdInterfaces;
}
