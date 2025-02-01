#include "applications.h"
#include "../impl/init.h"
#include "log/stub.h"

using namespace openvr;

ApplicationError Applications_006::addApplicationManifest(const char* path, bool temporary)
{
    return openvr::applicationsImpl->addApplicationManifest(path, temporary);
}

ApplicationError Applications_007::addApplicationManifest(const char* path, bool temporary)
{
    return openvr::applicationsImpl->addApplicationManifest(path, temporary);
}

ApplicationError Applications_006::removeApplicationManifest(const char* path)
{
    return openvr::applicationsImpl->removeApplicationManifest(path);
}

ApplicationError Applications_007::removeApplicationManifest(const char* path)
{
    return openvr::applicationsImpl->removeApplicationManifest(path);
}

bool Applications_006::isApplicationInstalled(const char* appKey)
{
    return openvr::applicationsImpl->isApplicationInstalled(appKey);
}

bool Applications_007::isApplicationInstalled(const char* appKey)
{
    return openvr::applicationsImpl->isApplicationInstalled(appKey);
}

uint32_t Applications_006::getApplicationCount()
{
    return openvr::applicationsImpl->getApplicationCount();
}

uint32_t Applications_007::getApplicationCount()
{
    return openvr::applicationsImpl->getApplicationCount();
}

ApplicationError Applications_006::getApplicationKeyByIndex(uint32_t index, char* buffer, uint32_t bufferSize)
{
    return openvr::applicationsImpl->getApplicationKeyByIndex(index, buffer, bufferSize);
}

ApplicationError Applications_007::getApplicationKeyByIndex(uint32_t index, char* buffer, uint32_t bufferSize)
{
    return openvr::applicationsImpl->getApplicationKeyByIndex(index, buffer, bufferSize);
}

ApplicationError Applications_006::getApplicationKeyByProcessId(uint32_t pid, char* buffer, uint32_t bufferSize)
{
    return openvr::applicationsImpl->getApplicationKeyByProcessId(pid, buffer, bufferSize);
}

ApplicationError Applications_007::getApplicationKeyByProcessId(uint32_t pid, char* buffer, uint32_t bufferSize)
{
    return openvr::applicationsImpl->getApplicationKeyByProcessId(pid, buffer, bufferSize);
}

ApplicationError Applications_006::launchApplication(const char* appKey)
{
    return openvr::applicationsImpl->launchApplication(appKey);
}

ApplicationError Applications_007::launchApplication(const char* appKey)
{
    return openvr::applicationsImpl->launchApplication(appKey);
}

ApplicationError Applications_006::launchTemplateApplication(const char* templateAppKey, const char* newAppKey, const ApplicationOverrideKey* keys, uint32_t keysCount)
{
    return openvr::applicationsImpl->launchTemplateApplication(templateAppKey, newAppKey, keys, keysCount);
}

ApplicationError Applications_007::launchTemplateApplication(const char* templateAppKey, const char* newAppKey, const ApplicationOverrideKey* keys, uint32_t keysCount)
{
    return openvr::applicationsImpl->launchTemplateApplication(templateAppKey, newAppKey, keys, keysCount);
}

ApplicationError Applications_006::launchApplicationFromMimeType(const char* mimeType, const char* args)
{
    return openvr::applicationsImpl->launchApplicationFromMimeType(mimeType, args);
}

ApplicationError Applications_007::launchApplicationFromMimeType(const char* mimeType, const char* args)
{
    return openvr::applicationsImpl->launchApplicationFromMimeType(mimeType, args);
}

ApplicationError Applications_006::launchDashboardOverlay(const char* appKey)
{
    return openvr::applicationsImpl->launchDashboardOverlay(appKey);
}

ApplicationError Applications_007::launchDashboardOverlay(const char* appKey)
{
    return openvr::applicationsImpl->launchDashboardOverlay(appKey);
}

bool Applications_006::cancelApplicationLaunch(const char* appKey)
{
    return openvr::applicationsImpl->cancelApplicationLaunch(appKey);
}

bool Applications_007::cancelApplicationLaunch(const char* appKey)
{
    return openvr::applicationsImpl->cancelApplicationLaunch(appKey);
}

ApplicationError Applications_006::identifyApplication(uint32_t pid, const char* appKey)
{
    return openvr::applicationsImpl->identifyApplication(pid, appKey);
}

ApplicationError Applications_007::identifyApplication(uint32_t pid, const char* appKey)
{
    return openvr::applicationsImpl->identifyApplication(pid, appKey);
}

uint32_t Applications_006::getApplicationProcessId(const char* appKey)
{
    return openvr::applicationsImpl->getApplicationProcessId(appKey);
}

uint32_t Applications_007::getApplicationProcessId(const char* appKey)
{
    return openvr::applicationsImpl->getApplicationProcessId(appKey);
}

const char* Applications_006::getApplicationsErrorNameFromEnum(ApplicationError error)
{
    return openvr::applicationsImpl->getApplicationsErrorNameFromEnum(error);
}

const char* Applications_007::getApplicationsErrorNameFromEnum(ApplicationError error)
{
    return openvr::applicationsImpl->getApplicationsErrorNameFromEnum(error);
}

uint32_t Applications_006::getApplicationPropertyString(const char* appKey, ApplicationProperty property, char* buffer, uint32_t bufferSize, ApplicationError* error)
{
    return openvr::applicationsImpl->getApplicationPropertyString(appKey, property, buffer, bufferSize, error);
}

uint32_t Applications_007::getApplicationPropertyString(const char* appKey, ApplicationProperty property, char* buffer, uint32_t bufferSize, ApplicationError* error)
{
    return openvr::applicationsImpl->getApplicationPropertyString(appKey, property, buffer, bufferSize, error);
}

bool Applications_006::getApplicationPropertyBool(const char* appKey, ApplicationProperty property, ApplicationError* error)
{
    return openvr::applicationsImpl->getApplicationPropertyBool(appKey, property, error);
}

bool Applications_007::getApplicationPropertyBool(const char* appKey, ApplicationProperty property, ApplicationError* error)
{
    return openvr::applicationsImpl->getApplicationPropertyBool(appKey, property, error);
}

uint64_t Applications_006::getApplicationPropertyUint64(const char* appKey, ApplicationProperty property, ApplicationError* error)
{
    return openvr::applicationsImpl->getApplicationPropertyUint64(appKey, property, error);
}

uint64_t Applications_007::getApplicationPropertyUint64(const char* appKey, ApplicationProperty property, ApplicationError* error)
{
    return openvr::applicationsImpl->getApplicationPropertyUint64(appKey, property, error);
}

ApplicationError Applications_006::setApplicationAutoLaunch(const char* appKey, bool autoLaunch)
{
    return openvr::applicationsImpl->setApplicationAutoLaunch(appKey, autoLaunch);
}

ApplicationError Applications_007::setApplicationAutoLaunch(const char* appKey, bool autoLaunch)
{
    return openvr::applicationsImpl->setApplicationAutoLaunch(appKey, autoLaunch);
}

bool Applications_006::getApplicationAutoLaunch(const char* appKey)
{
    return openvr::applicationsImpl->getApplicationAutoLaunch(appKey);
}

bool Applications_007::getApplicationAutoLaunch(const char* appKey)
{
    return openvr::applicationsImpl->getApplicationAutoLaunch(appKey);
}

ApplicationError Applications_006::setDefaultApplicationForMimeType(const char* appKey, const char* mimeType)
{
    return openvr::applicationsImpl->setDefaultApplicationForMimeType(appKey, mimeType);
}

ApplicationError Applications_007::setDefaultApplicationForMimeType(const char* appKey, const char* mimeType)
{
    return openvr::applicationsImpl->setDefaultApplicationForMimeType(appKey, mimeType);
}

bool Applications_006::getDefaultApplicationForMimeType(const char* mimeType, char* appKeyBuffer, uint32_t bufferSize)
{
    return openvr::applicationsImpl->getDefaultApplicationForMimeType(mimeType, appKeyBuffer, bufferSize);
}

bool Applications_007::getDefaultApplicationForMimeType(const char* mimeType, char* appKeyBuffer, uint32_t bufferSize)
{
    return openvr::applicationsImpl->getDefaultApplicationForMimeType(mimeType, appKeyBuffer, bufferSize);
}

bool Applications_006::getApplicationSupportedMimeTypes(const char* appKey, char* mimeTypesBuffer, uint32_t bufferSize)
{
    return openvr::applicationsImpl->getApplicationSupportedMimeTypes(appKey, mimeTypesBuffer, bufferSize);
}

bool Applications_007::getApplicationSupportedMimeTypes(const char* appKey, char* mimeTypesBuffer, uint32_t bufferSize)
{
    return openvr::applicationsImpl->getApplicationSupportedMimeTypes(appKey, mimeTypesBuffer, bufferSize);
}

uint32_t Applications_006::getApplicationsThatSupportMimeType(const char* mimeType, char* appKeysBuffer, uint32_t bufferSize)
{
    return openvr::applicationsImpl->getApplicationsThatSupportMimeType(mimeType, appKeysBuffer, bufferSize);
}

uint32_t Applications_007::getApplicationsThatSupportMimeType(const char* mimeType, char* appKeysBuffer, uint32_t bufferSize)
{
    return openvr::applicationsImpl->getApplicationsThatSupportMimeType(mimeType, appKeysBuffer, bufferSize);
}

uint32_t Applications_006::getApplicationLaunchArguments(uint32_t handle, char* args, uint32_t bufferSize)
{
    return openvr::applicationsImpl->getApplicationLaunchArguments(handle, args, bufferSize);
}

uint32_t Applications_007::getApplicationLaunchArguments(uint32_t handle, char* args, uint32_t bufferSize)
{
    return openvr::applicationsImpl->getApplicationLaunchArguments(handle, args, bufferSize);
}

ApplicationError Applications_006::getStartingApplication(char* appKey, uint32_t bufferSize)
{
    return openvr::applicationsImpl->getStartingApplication(appKey, bufferSize);
}

ApplicationError Applications_007::getStartingApplication(char* appKey, uint32_t bufferSize)
{
    return openvr::applicationsImpl->getStartingApplication(appKey, bufferSize);
}

ApplicationTransitionState Applications_006::getTransitionState()
{
    return openvr::applicationsImpl->getTransitionState();
}

ApplicationState Applications_007::getApplicationState()
{
    return openvr::applicationsImpl->getApplicationState();
}

ApplicationError Applications_006::performApplicationPrelaunchCheck(const char* appKey)
{
    return openvr::applicationsImpl->performApplicationPrelaunchCheck(appKey);
}

ApplicationError Applications_007::performApplicationPrelaunchCheck(const char* appKey)
{
    return openvr::applicationsImpl->performApplicationPrelaunchCheck(appKey);
}

const char* Applications_006::getApplicationTransitionStateNameFromEnum(ApplicationTransitionState state)
{
    return openvr::applicationsImpl->getApplicationTransitionStateNameFromEnum(state);
}

const char* Applications_007::getApplicationStateNameFromEnum(ApplicationState state)
{
    return openvr::applicationsImpl->getApplicationStateNameFromEnum(state);
}

bool Applications_006::isQuitUserPromptRequested()
{
    return openvr::applicationsImpl->isQuitUserPromptRequested();
}

ApplicationError Applications_006::launchInternalProcess(const char* binaryPath, const char* args, const char* workingDirectory)
{
    return openvr::applicationsImpl->launchInternalProcess(binaryPath, args, workingDirectory);
}

ApplicationError Applications_007::launchInternalProcess(const char* binaryPath, const char* args, const char* workingDirectory)
{
    return openvr::applicationsImpl->launchInternalProcess(binaryPath, args, workingDirectory);
}

uint32_t Applications_006::getCurrentSceneProcessId()
{
    return openvr::applicationsImpl->getCurrentSceneProcessId();
}

uint32_t Applications_007::getCurrentSceneProcessId()
{
    return openvr::applicationsImpl->getCurrentSceneProcessId();
}
