#pragma once

#include "openvr/interfaces/interfaces.h"

#include <map>
#include <string>

#include "client_core.h"
#include "system.h"
#include "compositor.h"
#include "input.h"
#include "chaperone.h"
#include "overlay.h"
#include "rendermodel.h"
#include "settings.h"
#include "screenshot.h"
#include "applications.h"
#include "extended_display.h"

namespace openvr
{
    extern ClientCoreImpl* clientCoreImpl;
    extern SystemImpl* systemImpl;
    extern CompositorImpl* compositorImpl;
    extern InputImpl* inputImpl;
    extern ChaperoneImpl* chaperoneImpl;
    extern OverlayImpl* overlayImpl;
    extern RenderModelsImpl* renderModelsImpl;
    extern SettingsImpl* settingsImpl;
    extern ScreenshotsImpl* screenshotsImpl;
    extern ChaperoneSetupImpl* chaperoneSetupImpl;
    extern ApplicationsImpl* applicationsImpl;
    extern ExtendedDisplayImpl* extendedDisplayImpl;

    extern std::map<std::string, void*> createdInterfaces;
}
