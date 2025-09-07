#include "client_core.h"
#include "log/log.h"
#include "log/stub.h"

#include "init.h"

#include <thread>
#include <future>

using namespace openvr;

static void run(std::promise<vapor::Backend*>* promise, std::promise<bool>* finishPromise)
{
    TRACE_F("starting backend");
    vapor::Backend* backend = new vapor::Backend();
    promise->set_value(backend);
    backend->loop();
    delete backend;
    finishPromise->set_value(true);
    TRACE_F("finished backend");
}

InitError ClientCoreImpl::init(ApplicationType applicationType, const char* startupInfo)
{
    TRACE_F("%d, %s", applicationType, startupInfo);

    if (applicationType != ApplicationType::APPLICATION_TYPE_SCENE && applicationType != ApplicationType::APPLICATION_TYPE_BACKGROUND)
    {
        LOG("Unsupported application type %d", applicationType);
    }

    if (!this->initialised)
    {
        this->initialised = true;

        std::promise<vapor::Backend*> promise;
        this->backendFinishedPromise = std::promise<bool>();
        std::thread thread = std::thread(run, &promise, &this->backendFinishedPromise);
        thread.detach();
        vapor::Backend* backend = promise.get_future().get();
        backend->waitForFirstFrame();
        this->backend = backend;

        openvr::systemImpl = new SystemImpl(*openvr::clientCoreImpl);
        openvr::compositorImpl = new CompositorImpl(*openvr::clientCoreImpl);
        openvr::inputImpl = new InputImpl(*openvr::clientCoreImpl);
        openvr::chaperoneImpl = new ChaperoneImpl(*openvr::clientCoreImpl);
        //openvr::overlayImpl = new OverlayImpl(*openvr::clientCoreImpl);
        openvr::renderModelsImpl = new RenderModelsImpl(*openvr::clientCoreImpl);
        openvr::settingsImpl = new SettingsImpl(*openvr::clientCoreImpl);
        openvr::screenshotsImpl = new ScreenshotsImpl(*openvr::clientCoreImpl);
        openvr::chaperoneSetupImpl = new ChaperoneSetupImpl(*openvr::clientCoreImpl);
        openvr::applicationsImpl = new ApplicationsImpl(*openvr::clientCoreImpl);
        openvr::extendedDisplayImpl = new ExtendedDisplayImpl(*openvr::clientCoreImpl);
    }

    return InitError::INIT_ERROR_NONE;
}

void ClientCoreImpl::cleanup()
{
    TRACE();

    if (this->initialised)
    {
        this->initialised = false;

        delete openvr::systemImpl;
        delete openvr::compositorImpl;
        delete openvr::inputImpl;
        delete openvr::chaperoneImpl;
        //delete openvr::overlayImpl;
        delete openvr::renderModelsImpl;
        delete openvr::settingsImpl;
        delete openvr::screenshotsImpl;
        delete openvr::chaperoneSetupImpl;
        delete openvr::applicationsImpl;
        delete openvr::extendedDisplayImpl;
        openvr::systemImpl = nullptr;
        openvr::compositorImpl = nullptr;
        openvr::inputImpl = nullptr;
        openvr::chaperoneImpl = nullptr;
        //openvr::overlayImpl = nullptr;
        openvr::renderModelsImpl = nullptr;
        openvr::settingsImpl = nullptr;
        openvr::screenshotsImpl = nullptr;
        openvr::chaperoneSetupImpl = nullptr;
        openvr::applicationsImpl = nullptr;
        openvr::extendedDisplayImpl = nullptr;

        this->backend->requestExit();
        this->backendFinishedPromise.get_future().get();
        this->backend = nullptr;
    }
}

static void* getInterface(const std::string& nameAndVersion, bool create, bool* exists)
{
    bool fnTable = false;
    std::string str = std::string(nameAndVersion);
    if (str.find(":") != std::string::npos)
    {
        fnTable = true;
        str = str.substr(str.find(":") + 1);
    }

    if (str.find("_") == std::string::npos)
    {
        *exists = false;
        return nullptr;
    }
    std::string name = str.substr(0, str.find("_"));
    std::string version = str.substr(str.find("_") + 1);
    if (name.empty() || version.empty())
    {
        *exists = false;
        return nullptr;
    }

    *exists = true;
    if (name == "IVRClientCore")
    {
        // TODO: support IVRClientCore_001 and IVRClientCore_002 (confirmed to exist in SteamVR)
        if (version == "003")
        {
            return create ? (fnTable ? (void*) new ClientCore_003() : (void*) new ClientCore_003_v()) : nullptr;
        }
    }
    else if (name == "IVRSystem")
    {
        if (version == "003")
        {
            return create ? (fnTable ? (void*) new System_003() : (void*) new System_003_v()) : nullptr;
        }
        else if (version == "004")
        {
            return create ? (fnTable ? (void*) new System_004() : (void*) new System_004_v()) : nullptr;
        }
        else if (version == "005")
        {
            return create ? (fnTable ? (void*) new System_005() : (void*) new System_005_v()) : nullptr;
        }
        else if (version == "006")
        {
            return create ? (fnTable ? (void*) new System_006() : (void*) new System_006_v()) : nullptr;
        }
        else if (version == "007")
        {
            return create ? (fnTable ? (void*) new System_007() : (void*) new System_007_v()) : nullptr;
        }
        else if (version == "009")
        {
            return create ? (fnTable ? (void*) new System_009() : (void*) new System_009_v()) : nullptr;
        }
        else if (version == "010")
        {
            return create ? (fnTable ? (void*) new System_010() : (void*) new System_010_v()) : nullptr;
        }
        else if (version == "011")
        {
            return create ? (fnTable ? (void*) new System_011() : (void*) new System_011_v()) : nullptr;
        }
        else if (version == "012")
        {
            return create ? (fnTable ? (void*) new System_012() : (void*) new System_012_v()) : nullptr;
        }
        else if (version == "014")
        {
            return create ? (fnTable ? (void*) new System_014() : (void*) new System_014_v()) : nullptr;
        }
        else if (version == "015")
        {
            return create ? (fnTable ? (void*) new System_015() : (void*) new System_015_v()) : nullptr;
        }
        else if (version == "016")
        {
            return create ? (fnTable ? (void*) new System_016() : (void*) new System_016_v()) : nullptr;
        }
        else if (version == "017")
        {
            return create ? (fnTable ? (void*) new System_017() : (void*) new System_017_v()) : nullptr;
        }
        else if (version == "019")
        {
            return create ? (fnTable ? (void*) new System_019() : (void*) new System_019_v()) : nullptr;
        }
        else if (version == "020")
        {
            return create ? (fnTable ? (void*) new System_020() : (void*) new System_020_v()) : nullptr;
        }
        else if (version == "021")
        {
            return create ? (fnTable ? (void*) new System_021() : (void*) new System_021_v()) : nullptr;
        }
        else if (version == "022")
        {
            return create ? (fnTable ? (void*) new System_022() : (void*) new System_022_v()) : nullptr;
        }
    }
    else if (name == "IVRCompositor")
    {
        if (version == "005")
        {
            return create ? (fnTable ? (void*) new Compositor_005() : (void*) new Compositor_005_v()) : nullptr;
        }
        else if (version == "006")
        {
            return create ? (fnTable ? (void*) new Compositor_006() : (void*) new Compositor_006_v()) : nullptr;
        }
        else if (version == "007")
        {
            return create ? (fnTable ? (void*) new Compositor_007() : (void*) new Compositor_007_v()) : nullptr;
        }
        else if (version == "008")
        {
            return create ? (fnTable ? (void*) new Compositor_008() : (void*) new Compositor_008_v()) : nullptr;
        }
        else if (version == "009" || version == "010")
        {
            return create ? (fnTable ? (void*) new Compositor_009() : (void*) new Compositor_009_v()) : nullptr;
        }
        else if (version == "011")
        {
            return create ? (fnTable ? (void*) new Compositor_011() : (void*) new Compositor_011_v()) : nullptr;
        }
        else if (version == "012")
        {
            return create ? (fnTable ? (void*) new Compositor_012() : (void*) new Compositor_012_v()) : nullptr;
        }
        else if (version == "013")
        {
            return create ? (fnTable ? (void*) new Compositor_013() : (void*) new Compositor_013_v()) : nullptr;
        }
        else if (version == "014")
        {
            return create ? (fnTable ? (void*) new Compositor_014() : (void*) new Compositor_014_v()) : nullptr;
        }
        else if (version == "015")
        {
            return create ? (fnTable ? (void*) new Compositor_015() : (void*) new Compositor_015_v()) : nullptr;
        }
        else if (version == "016")
        {
            return create ? (fnTable ? (void*) new Compositor_016() : (void*) new Compositor_016_v()) : nullptr;
        }
        else if (version == "018")
        {
            return create ? (fnTable ? (void*) new Compositor_018() : (void*) new Compositor_018_v()) : nullptr;
        }
        else if (version == "019")
        {
            return create ? (fnTable ? (void*) new Compositor_019() : (void*) new Compositor_019_v()) : nullptr;
        }
        else if (version == "020")
        {
            return create ? (fnTable ? (void*) new Compositor_020() : (void*) new Compositor_020_v()) : nullptr;
        }
        else if (version == "021")
        {
            return create ? (fnTable ? (void*) new Compositor_021() : (void*) new Compositor_021_v()) : nullptr;
        }
        else if (version == "022")
        {
            return create ? (fnTable ? (void*) new Compositor_022() : (void*) new Compositor_022_v()) : nullptr;
        }
        else if (version == "024")
        {
            return create ? (fnTable ? (void*) new Compositor_024() : (void*) new Compositor_024_v()) : nullptr;
        }
        else if (version == "026" || version == "027")
        {
            return create ? (fnTable ? (void*) new Compositor_026() : (void*) new Compositor_026_v()) : nullptr;
        }
        else if (version == "028")
        {
            return create ? (fnTable ? (void*) new Compositor_028() : (void*) new Compositor_028_v()) : nullptr;
        }
    }
    else if (name == "IVRInput")
    {
        if (version == "003")
        {
            return create ? (fnTable ? (void*) new Input_003() : (void*) new Input_003_v()) : nullptr;
        }
        else if (version == "004")
        {
            return create ? (fnTable ? (void*) new Input_004() : (void*) new Input_004_v()) : nullptr;
        }
        else if (version == "005")
        {
            return create ? (fnTable ? (void*) new Input_005() : (void*) new Input_005_v()) : nullptr;
        }
        else if (version == "006")
        {
            return create ? (fnTable ? (void*) new Input_006() : (void*) new Input_006_v()) : nullptr;
        }
        else if (version == "007")
        {
            return create ? (fnTable ? (void*) new Input_007() : (void*) new Input_007_v()) : nullptr;
        }
        else if (version == "010")
        {
            return create ? (fnTable ? (void*) new Input_010() : (void*) new Input_010_v()) : nullptr;
        }
    }
    else if (name == "IVRChaperone")
    {
        if (version == "002")
        {
            return create ? (fnTable ? (void*) new Chaperone_002() : (void*) new Chaperone_002_v()) : nullptr;
        }
        else if (version == "003")
        {
            return create ? (fnTable ? (void*) new Chaperone_003() : (void*) new Chaperone_003_v()) : nullptr;
        }
        else if (version == "004")
        {
            return create ? (fnTable ? (void*) new Chaperone_004() : (void*) new Chaperone_004_v()) : nullptr;
        }
    }
    else if (name == "IVROverlay")
    {
        // TODO
        if (version == "018")
        {
            return create ? (fnTable ? (void*) new Overlay_018() : (void*) new Overlay_018_v()) : nullptr;
        }
        else if (version == "019")
        {
            return create ? (fnTable ? (void*) new Overlay_019() : (void*) new Overlay_019_v()) : nullptr;
        }
    }
    else if (name == "IVRRenderModels")
    {
        if (version == "001")
        {
            return create ? (fnTable ? (void*) new RenderModels_001() : (void*) new RenderModels_001_v()) : nullptr;
        }
        else if (version == "002")
        {
            return create ? (fnTable ? (void*) new RenderModels_002() : (void*) new RenderModels_002_v()) : nullptr;
        }
        else if (version == "004")
        {
            return create ? (fnTable ? (void*) new RenderModels_004() : (void*) new RenderModels_004_v()) : nullptr;
        }
        else if (version == "005")
        {
            return create ? (fnTable ? (void*) new RenderModels_005() : (void*) new RenderModels_005_v()) : nullptr;
        }
        else if (version == "006")
        {
            return create ? (fnTable ? (void*) new RenderModels_006() : (void*) new RenderModels_006_v()) : nullptr;
        }
    }
    else if (name == "IVRSettings")
    {
        if (version == "001")
        {
            return create ? (fnTable ? (void*) new Settings_001() : (void*) new Settings_001_v()) : nullptr;
        }
        else if (version == "002")
        {
            return create ? (fnTable ? (void*) new Settings_002() : (void*) new Settings_002_v()) : nullptr;
        }
        else if (version == "003")
        {
            return create ? (fnTable ? (void*) new Settings_003() : (void*) new Settings_003_v()) : nullptr;
        }
    }
    else if (name == "IVRScreenshots")
    {
        if (version == "001")
        {
            return create ? (fnTable ? (void*) new Screenshots_001() : (void*) new Screenshots_001_v()) : nullptr;
        }
    }
    else if (name == "IVRChaperoneSetup")
    {
        if (version == "004")
        {
            return create ? (fnTable ? (void*) new ChaperoneSetup_004() : (void*) new ChaperoneSetup_004_v()) : nullptr;
        }
        else if (version == "005")
        {
            return create ? (fnTable ? (void*) new ChaperoneSetup_005() : (void*) new ChaperoneSetup_005_v()) : nullptr;
        }
        else if (version == "006")
        {
            return create ? (fnTable ? (void*) new ChaperoneSetup_006() : (void*) new ChaperoneSetup_006_v()) : nullptr;
        }
    }
    else if (name == "IVRApplications")
    {
        // TODO
        if (version == "006")
        {
            return create ? (fnTable ? (void*) new Applications_006() : (void*) new Applications_006_v()) : nullptr;
        }
        else if (version == "007")
        {
            return create ? (fnTable ? (void*) new Applications_007() : (void*) new Applications_007_v()) : nullptr;
        }
    }
    else if (name  == "IVRExtendedDisplay")
    {
        if (version == "001")
        {
            return create ? (fnTable ? (void*) new ExtendedDisplay_001() : (void*) new ExtendedDisplay_001_v()) : nullptr;
        }
    }

    *exists = false;
    return nullptr;
}

InitError ClientCoreImpl::isInterfaceVersionValid(const char* nameAndVersion)
{
    TRACE_F("Testing for interface %s", nameAndVersion);
    bool exists;
    getInterface(nameAndVersion, false, &exists);
    if (!exists)
    {
        return InitError::INIT_ERROR_INTERFACE_NOT_FOUND;
    }
    else
    {
        return InitError::INIT_ERROR_NONE;
    }
}

void* ClientCoreImpl::getGenericInterface(const char* nameAndVersion, InitError* error)
{
    if (openvr::createdInterfaces.contains(nameAndVersion))
    {
        *error = InitError::INIT_ERROR_NONE;
        return openvr::createdInterfaces[nameAndVersion];
    }
    else
    {
        bool exists;
        void* interface = getInterface(nameAndVersion, true, &exists);
        if (interface == nullptr)
        {
            LOG("Unimplemented interface %s", nameAndVersion);
            *error = InitError::INIT_ERROR_INTERFACE_NOT_FOUND;
            return nullptr;
        }
        else
        {
            TRACE_F("Returning interface %s", nameAndVersion);
            *error = InitError::INIT_ERROR_NONE;
            openvr::createdInterfaces[nameAndVersion] = interface;
            return interface;
        }
    }
}

bool ClientCoreImpl::isHmdPresent()
{
    return true;
}

const char* ClientCoreImpl::getStringForInitError(InitError error)
{
    STUB_F("%d", error);
    return "";
}

const char* ClientCoreImpl::getIDForInitError(InitError error)
{
    STUB_F("%d", error);
    return "";
}
