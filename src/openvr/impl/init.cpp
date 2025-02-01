#include "init.h"

#include "openvr/interfaces/interfaces.h"
#include "openvr/types.h"
#include "client_core.h"

#include "log/log.h"
#include "log/stub.h"

#include <cstdint>

namespace openvr
{
    ClientCoreImpl* clientCoreImpl;
    SystemImpl* systemImpl;
    CompositorImpl* compositorImpl;
    InputImpl* inputImpl;
    ChaperoneImpl* chaperoneImpl;
    //OverlayImpl* overlayImpl;
    RenderModelsImpl* renderModelsImpl;
    SettingsImpl* settingsImpl;
    ScreenshotsImpl* screenshotsImpl;
    ChaperoneSetupImpl* chaperoneSetupImpl;
    ApplicationsImpl* applicationsImpl;
    ExtendedDisplayImpl* extendedDisplayImpl;

    std::map<std::string, void*> createdInterfaces;
}

extern "C"
{
    void* VRClientCoreFactory(const char* interfaceName, int* returnCode)
    {
        TRACE_F("%s", interfaceName);
        *returnCode = 0;
        openvr::clientCoreImpl = new openvr::ClientCoreImpl();
        return new openvr::ClientCore_003_v(); // TODO: do we need to support FnTable style here?
    }

    /*uint32_t VR_InitInternal(openvr::InitError* error, openvr::ApplicationType applicationType)
    {
        STUB();
    }

    uint32_t VR_InitInternal2(openvr::InitError* error, openvr::ApplicationType applicationType, const char* startupInfo)
    {
        STUB();
    }

    uint32_t VR_GetInitToken()
    {
        STUB();
    }

    void VR_ShutdownInternal()
    {
        STUB();
    }

    bool VR_IsInterfaceVersionValid(const char* nameAndVersion)
    {
        STUB_F("%s", nameAndVersion);
        return true;
    }

    void* VR_GetGenericInterface(const char* nameAndVersion, openvr::InitError* error)
    {
        STUB_F("%s", nameAndVersion);
    }

    bool VR_IsHmdPresent()
    {
        TRACE();
        return true;
    }

    bool VR_IsRuntimeInstalled()
    {
        TRACE();
        return true;
    }

    const char* VR_RuntimePath()
    {
        STUB();
    }

    char* VR_GetStringForHmdError(int error)
    {
        STUB();
    }

    const char* VR_GetVRInitErrorAsEnglishDescription(openvr::InitError error)
    {
        STUB();
    }

    const char* VR_GetVRInitErrorAsSymbol(openvr::InitError error)
    {
        STUB();
    }*/

    // required for Proton to work
    uint32_t HmdSystemFactory()
    {
        STUB();
        return 0;
    }
}
