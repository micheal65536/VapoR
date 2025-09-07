#include "init.h"

#include "openvr/interfaces/interfaces.h"
#include "openvr/types.h"
#include "client_core.h"

#include "log/log.h"
#include "log/stub.h"

#include <cstdint>

namespace openvr
{
    ClientCoreImpl* clientCoreImpl = new openvr::ClientCoreImpl();
    SystemImpl* systemImpl = nullptr;
    CompositorImpl* compositorImpl = nullptr;
    InputImpl* inputImpl = nullptr;
    ChaperoneImpl* chaperoneImpl = nullptr;
    //OverlayImpl* overlayImpl = nullptr;
    RenderModelsImpl* renderModelsImpl = nullptr;
    SettingsImpl* settingsImpl = nullptr;
    ScreenshotsImpl* screenshotsImpl = nullptr;
    ChaperoneSetupImpl* chaperoneSetupImpl = nullptr;
    ApplicationsImpl* applicationsImpl = nullptr;
    ExtendedDisplayImpl* extendedDisplayImpl = nullptr;

    std::map<std::string, void*> createdInterfaces;
}

extern "C"
{
    void* VRClientCoreFactory(const char* interfaceName, openvr::InitError* error)
    {
        TRACE_F("%s", interfaceName);
        return openvr::clientCoreImpl->getGenericInterface(interfaceName, error);
    }

    // required for Proton to work
    uint32_t HmdSystemFactory()
    {
        STUB();
        return 0;
    }
}
