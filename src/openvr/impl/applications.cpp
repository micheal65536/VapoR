#include "applications.h"
#include "log/log.h"
#include "log/stub.h"

using namespace openvr;

ApplicationsImpl::ApplicationsImpl(ClientCoreImpl& clientCore): clientCore(clientCore)
{
    // empty
}

ApplicationError ApplicationsImpl::addApplicationManifest(const char* path, bool temporary)
{
    STUB_F("%s %d", path, temporary);
    return ApplicationError::APPLICATION_ERROR_NONE;
}

ApplicationError ApplicationsImpl::removeApplicationManifest(const char* path)
{
    STUB_F("%s", path);
    return ApplicationError::APPLICATION_ERROR_NONE;
}

bool ApplicationsImpl::isApplicationInstalled(const char* appKey)
{
    TRACE_F("%s", appKey);
    return true;
}

uint32_t ApplicationsImpl::getApplicationCount()
{
    STUB();
    return 0;
}

ApplicationError ApplicationsImpl::getApplicationKeyByIndex(uint32_t index, char* buffer, uint32_t bufferSize)
{
    STUB();
}

ApplicationError ApplicationsImpl::getApplicationKeyByProcessId(uint32_t pid, char* buffer, uint32_t bufferSize)
{
    STUB();
}

ApplicationError ApplicationsImpl::launchApplication(const char* appKey)
{
    STUB();
}

ApplicationError ApplicationsImpl::launchTemplateApplication(const char* templateAppKey, const char* newAppKey, const ApplicationOverrideKey* keys, uint32_t keysCount)
{
    STUB();
}

ApplicationError ApplicationsImpl::launchApplicationFromMimeType(const char* mimeType, const char* args)
{
    STUB();
}

ApplicationError ApplicationsImpl::launchDashboardOverlay(const char* appKey)
{
    STUB();
}

bool ApplicationsImpl::cancelApplicationLaunch(const char* appKey)
{
    STUB();
}

ApplicationError ApplicationsImpl::identifyApplication(uint32_t pid, const char* appKey)
{
    TRACE_F("%u %s", pid, appKey);
    return ApplicationError::APPLICATION_ERROR_NONE;
}

uint32_t ApplicationsImpl::getApplicationProcessId(const char* appKey)
{
    STUB_F("%s", appKey);
    return 0;
}

const char* ApplicationsImpl::getApplicationsErrorNameFromEnum(ApplicationError error)
{
    STUB_F("%d", error);
    return "";
}

uint32_t ApplicationsImpl::getApplicationPropertyString(const char* appKey, ApplicationProperty property, char* buffer, uint32_t bufferSize, ApplicationError* error)
{
    STUB();
}

bool ApplicationsImpl::getApplicationPropertyBool(const char* appKey, ApplicationProperty property, ApplicationError* error)
{
    STUB();
}

uint64_t ApplicationsImpl::getApplicationPropertyUint64(const char* appKey, ApplicationProperty property, ApplicationError* error)
{
    STUB();
}

ApplicationError ApplicationsImpl::setApplicationAutoLaunch(const char* appKey, bool autoLaunch)
{
    STUB();
}

bool ApplicationsImpl::getApplicationAutoLaunch(const char* appKey)
{
    STUB();
}

ApplicationError ApplicationsImpl::setDefaultApplicationForMimeType(const char* appKey, const char* mimeType)
{
    STUB();
}

bool ApplicationsImpl::getDefaultApplicationForMimeType(const char* mimeType, char* appKeyBuffer, uint32_t bufferSize)
{
    STUB();
}

bool ApplicationsImpl::getApplicationSupportedMimeTypes(const char* appKey, char* mimeTypesBuffer, uint32_t bufferSize)
{
    STUB();
}

uint32_t ApplicationsImpl::getApplicationsThatSupportMimeType(const char* mimeType, char* appKeysBuffer, uint32_t bufferSize)
{
    STUB();
}

uint32_t ApplicationsImpl::getApplicationLaunchArguments(uint32_t handle, char* args, uint32_t bufferSize)
{
    STUB();
}

ApplicationError ApplicationsImpl::getStartingApplication(char* appKey, uint32_t bufferSize)
{
    STUB();
}

ApplicationTransitionState ApplicationsImpl::getTransitionState()
{
    STUB();
}

ApplicationState ApplicationsImpl::getApplicationState()
{
    STUB();
}

ApplicationError ApplicationsImpl::performApplicationPrelaunchCheck(const char* appKey)
{
    STUB();
}

const char* ApplicationsImpl::getApplicationTransitionStateNameFromEnum(ApplicationTransitionState state)
{
    STUB();
}

const char* ApplicationsImpl::getApplicationStateNameFromEnum(ApplicationState state)
{
    STUB();
}

bool ApplicationsImpl::isQuitUserPromptRequested()
{
    STUB();
}

ApplicationError ApplicationsImpl::launchInternalProcess(const char* binaryPath, const char* args, const char* workingDirectory)
{
    STUB();
}

uint32_t ApplicationsImpl::getCurrentSceneProcessId()
{
    STUB();
}
