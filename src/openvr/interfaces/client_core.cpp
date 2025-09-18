#include "client_core.h"
#include "../impl/init.h"
#include "log/stub.h"

using namespace openvr;

InitError ClientCore_002::init(ApplicationType applicationType)
{
    return openvr::clientCoreImpl->init(applicationType, "");
}

InitError ClientCore_003::init(ApplicationType applicationType, const char* startupInfo)
{
    return openvr::clientCoreImpl->init(applicationType, startupInfo);
}

void ClientCore_002::cleanup()
{
    openvr::clientCoreImpl->cleanup();
}

void ClientCore_003::cleanup()
{
    openvr::clientCoreImpl->cleanup();
}

InitError ClientCore_002::isInterfaceVersionValid(const char* nameAndVersion)
{
    return openvr::clientCoreImpl->isInterfaceVersionValid(nameAndVersion);
}

InitError ClientCore_003::isInterfaceVersionValid(const char* nameAndVersion)
{
    return openvr::clientCoreImpl->isInterfaceVersionValid(nameAndVersion);
}

void* ClientCore_002::getGenericInterface(const char* nameAndVersion, InitError* error)
{
    return openvr::clientCoreImpl->getGenericInterface(nameAndVersion, error);
}

void* ClientCore_003::getGenericInterface(const char* nameAndVersion, InitError* error)
{
    return openvr::clientCoreImpl->getGenericInterface(nameAndVersion, error);
}

bool ClientCore_002::isHmdPresent()
{
    return openvr::clientCoreImpl->isHmdPresent();
}

bool ClientCore_003::isHmdPresent()
{
    return openvr::clientCoreImpl->isHmdPresent();
}

const char* ClientCore_002::getStringForInitError(InitError error)
{
    return openvr::clientCoreImpl->getStringForInitError(error);
}

const char* ClientCore_003::getStringForInitError(InitError error)
{
    return openvr::clientCoreImpl->getStringForInitError(error);
}

const char* ClientCore_002::getIDForInitError(InitError error)
{
    return openvr::clientCoreImpl->getIDForInitError(error);
}

const char* ClientCore_003::getIDForInitError(InitError error)
{
    return openvr::clientCoreImpl->getIDForInitError(error);
}
