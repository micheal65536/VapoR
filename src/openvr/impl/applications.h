#pragma once

#include "../types.h"
#include "client_core.h"

namespace openvr
{
    class ApplicationsImpl
    {
        public:
            ClientCoreImpl& clientCore;
            ApplicationsImpl(ClientCoreImpl& clientCore);

            //

            ApplicationError addApplicationManifest(const char* path, bool temporary);
            ApplicationError removeApplicationManifest(const char* path);

            bool isApplicationInstalled(const char* appKey);

            uint32_t getApplicationCount();
            ApplicationError getApplicationKeyByIndex(uint32_t index, char* buffer, uint32_t bufferSize);
            ApplicationError getApplicationKeyByProcessId(uint32_t pid, char* buffer, uint32_t bufferSize);

            ApplicationError launchApplication(const char* appKey);
            ApplicationError launchTemplateApplication(const char* templateAppKey, const char* newAppKey, const ApplicationOverrideKey* keys, uint32_t keysCount);
            ApplicationError launchApplicationFromMimeType(const char* mimeType, const char* args);
            ApplicationError launchDashboardOverlay(const char* appKey);
            bool cancelApplicationLaunch(const char* appKey);

            ApplicationError identifyApplication(uint32_t pid, const char* appKey);
            uint32_t getApplicationProcessId(const char* appKey);

            const char* getApplicationsErrorNameFromEnum(ApplicationError error);

            uint32_t getApplicationPropertyString(const char* appKey, ApplicationProperty property, char* buffer, uint32_t bufferSize, ApplicationError* error);
            bool getApplicationPropertyBool(const char* appKey, ApplicationProperty property, ApplicationError* error);
            uint64_t getApplicationPropertyUint64(const char* appKey, ApplicationProperty property, ApplicationError* error);

            ApplicationError setApplicationAutoLaunch(const char* appKey, bool autoLaunch);
            bool getApplicationAutoLaunch(const char* appKey);

            ApplicationError setDefaultApplicationForMimeType(const char* appKey, const char* mimeType);
            bool getDefaultApplicationForMimeType(const char* mimeType, char* appKeyBuffer, uint32_t bufferSize);
            bool getApplicationSupportedMimeTypes(const char* appKey, char* mimeTypesBuffer, uint32_t bufferSize);
            uint32_t getApplicationsThatSupportMimeType(const char* mimeType, char* appKeysBuffer, uint32_t bufferSize);

            uint32_t getApplicationLaunchArguments(uint32_t handle, char* args, uint32_t bufferSize);

            ApplicationError getStartingApplication(char* appKey, uint32_t bufferSize);
            ApplicationTransitionState getTransitionState();
            ApplicationState getApplicationState();

            ApplicationError performApplicationPrelaunchCheck(const char* appKey);

            const char* getApplicationTransitionStateNameFromEnum(ApplicationTransitionState state);
            const char* getApplicationStateNameFromEnum(ApplicationState state);

            bool isQuitUserPromptRequested();

            ApplicationError launchInternalProcess(const char* binaryPath, const char* args, const char* workingDirectory);

            uint32_t getCurrentSceneProcessId();
    };
}
