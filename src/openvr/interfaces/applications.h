#pragma once

#include "../types.h"
#include <cstdint>

#include "../impl/applications.h"

namespace openvr
{
    // TODO: other versions

    struct Applications_006
    {
        static ApplicationError addApplicationManifest(const char* path, bool temporary);
        static ApplicationError removeApplicationManifest(const char* path);

        static bool isApplicationInstalled(const char* appKey);

        static uint32_t getApplicationCount();
        static ApplicationError getApplicationKeyByIndex(uint32_t index, char* buffer, uint32_t bufferSize);
        static ApplicationError getApplicationKeyByProcessId(uint32_t pid, char* buffer, uint32_t bufferSize);

        static ApplicationError launchApplication(const char* appKey);
        static ApplicationError launchTemplateApplication(const char* templateAppKey, const char* newAppKey, const ApplicationOverrideKey* keys, uint32_t keysCount);
        static ApplicationError launchApplicationFromMimeType(const char* mimeType, const char* args);
        static ApplicationError launchDashboardOverlay(const char* appKey);
        static bool cancelApplicationLaunch(const char* appKey);

        static ApplicationError identifyApplication(uint32_t pid, const char* appKey);
        static uint32_t getApplicationProcessId(const char* appKey);

        static const char* getApplicationsErrorNameFromEnum(ApplicationError error);

        static uint32_t getApplicationPropertyString(const char* appKey, ApplicationProperty property, char* buffer, uint32_t bufferSize, ApplicationError* error);
        static bool getApplicationPropertyBool(const char* appKey, ApplicationProperty property, ApplicationError* error);
        static uint64_t getApplicationPropertyUint64(const char* appKey, ApplicationProperty property, ApplicationError* error);

        static ApplicationError setApplicationAutoLaunch(const char* appKey, bool autoLaunch);
        static bool getApplicationAutoLaunch(const char* appKey);

        static ApplicationError setDefaultApplicationForMimeType(const char* appKey, const char* mimeType);
        static bool getDefaultApplicationForMimeType(const char* mimeType, char* appKeyBuffer, uint32_t bufferSize);
        static bool getApplicationSupportedMimeTypes(const char* appKey, char* mimeTypesBuffer, uint32_t bufferSize);
        static uint32_t getApplicationsThatSupportMimeType(const char* mimeType, char* appKeysBuffer, uint32_t bufferSize);

        static uint32_t getApplicationLaunchArguments(uint32_t handle, char* args, uint32_t bufferSize);

        static ApplicationError getStartingApplication(char* appKey, uint32_t bufferSize);
        static ApplicationTransitionState getTransitionState();

        static ApplicationError performApplicationPrelaunchCheck(const char* appKey);

        static const char* getApplicationTransitionStateNameFromEnum(ApplicationTransitionState state);

        static bool isQuitUserPromptRequested();

        static ApplicationError launchInternalProcess(const char* binaryPath, const char* args, const char* workingDirectory);

        static uint32_t getCurrentSceneProcessId();

        void* addApplicationManifest_ = (void*) addApplicationManifest;
        void* removeApplicationManifest_ = (void*) removeApplicationManifest;
        void* isApplicationInstalled_ = (void*) isApplicationInstalled;
        void* getApplicationCount_ = (void*) getApplicationCount;
        void* getApplicationKeyByIndex_ = (void*) getApplicationKeyByIndex;
        void* getApplicationKeyByProcessId_ = (void*) getApplicationKeyByProcessId;
        void* launchApplication_ = (void*) launchApplication;
        void* launchTemplateApplication_ = (void*) launchTemplateApplication;
        void* launchApplicationFromMimeType_ = (void*) launchApplicationFromMimeType;
        void* launchDashboardOverlay_ = (void*) launchDashboardOverlay;
        void* cancelApplicationLaunch_ = (void*) cancelApplicationLaunch;
        void* identifyApplication_ = (void*) identifyApplication;
        void* getApplicationProcessId_ = (void*) getApplicationProcessId;
        void* getApplicationsErrorNameFromEnum_ = (void*) getApplicationsErrorNameFromEnum;
        void* getApplicationPropertyString_ = (void*) getApplicationPropertyString;
        void* getApplicationPropertyBool_ = (void*) getApplicationPropertyBool;
        void* getApplicationPropertyUint64_ = (void*) getApplicationPropertyUint64;
        void* setApplicationAutoLaunch_ = (void*) setApplicationAutoLaunch;
        void* getApplicationAutoLaunch_ = (void*) getApplicationAutoLaunch;
        void* setDefaultApplicationForMimeType_ = (void*) setDefaultApplicationForMimeType;
        void* getDefaultApplicationForMimeType_ = (void*) getDefaultApplicationForMimeType;
        void* getApplicationSupportedMimeTypes_ = (void*) getApplicationSupportedMimeTypes;
        void* getApplicationsThatSupportMimeType_ = (void*) getApplicationsThatSupportMimeType;
        void* getApplicationLaunchArguments_ = (void*) getApplicationLaunchArguments;
        void* getStartingApplication_ = (void*) getStartingApplication;
        void* getTransitionState_ = (void*) getTransitionState;
        void* performApplicationPrelaunchCheck_ = (void*) performApplicationPrelaunchCheck;
        void* getApplicationTransitionStateNameFromEnum_ = (void*) getApplicationTransitionStateNameFromEnum;
        void* isQuitUserPromptRequested_ = (void*) isQuitUserPromptRequested;
        void* launchInternalProcess_ = (void*) launchInternalProcess;
        void* getCurrentSceneProcessId_ = (void*) getCurrentSceneProcessId;
    };

    class Applications_006_v
    {
        public:
            virtual ApplicationError addApplicationManifest(const char* path, bool temporary) { return Applications_006::addApplicationManifest(path, temporary); }
            virtual ApplicationError removeApplicationManifest(const char* path) { return Applications_006::removeApplicationManifest(path); }
            virtual bool isApplicationInstalled(const char* appKey) { return Applications_006::isApplicationInstalled(appKey); }
            virtual uint32_t getApplicationCount() { return Applications_006::getApplicationCount(); }
            virtual ApplicationError getApplicationKeyByIndex(uint32_t index, char* buffer, uint32_t bufferSize) { return Applications_006::getApplicationKeyByIndex(index, buffer, bufferSize); }
            virtual ApplicationError getApplicationKeyByProcessId(uint32_t pid, char* buffer, uint32_t bufferSize) { return Applications_006::getApplicationKeyByProcessId(pid, buffer, bufferSize); }
            virtual ApplicationError launchApplication(const char* appKey) { return Applications_006::launchApplication(appKey); }
            virtual ApplicationError launchTemplateApplication(const char* templateAppKey, const char* newAppKey, const ApplicationOverrideKey* keys, uint32_t keysCount) { return Applications_006::launchTemplateApplication(templateAppKey, newAppKey, keys, keysCount); }
            virtual ApplicationError launchApplicationFromMimeType(const char* mimeType, const char* args) { return Applications_006::launchApplicationFromMimeType(mimeType, args); }
            virtual ApplicationError launchDashboardOverlay(const char* appKey) { return Applications_006::launchDashboardOverlay(appKey); }
            virtual bool cancelApplicationLaunch(const char* appKey) { return Applications_006::cancelApplicationLaunch(appKey); }
            virtual ApplicationError identifyApplication(uint32_t pid, const char* appKey) { return Applications_006::identifyApplication(pid, appKey); }
            virtual uint32_t getApplicationProcessId(const char* appKey) { return Applications_006::getApplicationProcessId(appKey); }
            virtual const char* getApplicationsErrorNameFromEnum(ApplicationError error) { return Applications_006::getApplicationsErrorNameFromEnum(error); }
            virtual uint32_t getApplicationPropertyString(const char* appKey, ApplicationProperty property, char* buffer, uint32_t bufferSize, ApplicationError* error) { return Applications_006::getApplicationPropertyString(appKey, property, buffer, bufferSize, error); }
            virtual bool getApplicationPropertyBool(const char* appKey, ApplicationProperty property, ApplicationError* error) { return Applications_006::getApplicationPropertyBool(appKey, property, error); }
            virtual uint64_t getApplicationPropertyUint64(const char* appKey, ApplicationProperty property, ApplicationError* error) { return Applications_006::getApplicationPropertyUint64(appKey, property, error); }
            virtual ApplicationError setApplicationAutoLaunch(const char* appKey, bool autoLaunch) { return Applications_006::setApplicationAutoLaunch(appKey, autoLaunch); }
            virtual bool getApplicationAutoLaunch(const char* appKey) { return Applications_006::getApplicationAutoLaunch(appKey); }
            virtual ApplicationError setDefaultApplicationForMimeType(const char* appKey, const char* mimeType) { return Applications_006::setDefaultApplicationForMimeType(appKey, mimeType); }
            virtual bool getDefaultApplicationForMimeType(const char* mimeType, char* appKeyBuffer, uint32_t bufferSize) { return Applications_006::getDefaultApplicationForMimeType(mimeType, appKeyBuffer, bufferSize); }
            virtual bool getApplicationSupportedMimeTypes(const char* appKey, char* mimeTypesBuffer, uint32_t bufferSize) { return Applications_006::getApplicationSupportedMimeTypes(appKey, mimeTypesBuffer, bufferSize); }
            virtual uint32_t getApplicationsThatSupportMimeType(const char* mimeType, char* appKeysBuffer, uint32_t bufferSize) { return Applications_006::getApplicationsThatSupportMimeType(mimeType, appKeysBuffer, bufferSize); }
            virtual uint32_t getApplicationLaunchArguments(uint32_t handle, char* args, uint32_t bufferSize) { return Applications_006::getApplicationLaunchArguments(handle, args, bufferSize); }
            virtual ApplicationError getStartingApplication(char* appKey, uint32_t bufferSize) { return Applications_006::getStartingApplication(appKey, bufferSize); }
            virtual ApplicationTransitionState getTransitionState() { return Applications_006::getTransitionState(); }
            virtual ApplicationError performApplicationPrelaunchCheck(const char* appKey) { return Applications_006::performApplicationPrelaunchCheck(appKey); }
            virtual const char* getApplicationTransitionStateNameFromEnum(ApplicationTransitionState state) { return Applications_006::getApplicationTransitionStateNameFromEnum(state); }
            virtual bool isQuitUserPromptRequested() { return Applications_006::isQuitUserPromptRequested(); }
            virtual ApplicationError launchInternalProcess(const char* binaryPath, const char* args, const char* workingDirectory) { return Applications_006::launchInternalProcess(binaryPath, args, workingDirectory); }
            virtual uint32_t getCurrentSceneProcessId() { return Applications_006::getCurrentSceneProcessId(); }
    };

    //

    struct Applications_007
    {
        static ApplicationError addApplicationManifest(const char* path, bool temporary);
        static ApplicationError removeApplicationManifest(const char* path);

        static bool isApplicationInstalled(const char* appKey);

        static uint32_t getApplicationCount();
        static ApplicationError getApplicationKeyByIndex(uint32_t index, char* buffer, uint32_t bufferSize);
        static ApplicationError getApplicationKeyByProcessId(uint32_t pid, char* buffer, uint32_t bufferSize);

        static ApplicationError launchApplication(const char* appKey);
        static ApplicationError launchTemplateApplication(const char* templateAppKey, const char* newAppKey, const ApplicationOverrideKey* keys, uint32_t keysCount);
        static ApplicationError launchApplicationFromMimeType(const char* mimeType, const char* args);
        static ApplicationError launchDashboardOverlay(const char* appKey);
        static bool cancelApplicationLaunch(const char* appKey);

        static ApplicationError identifyApplication(uint32_t pid, const char* appKey);
        static uint32_t getApplicationProcessId(const char* appKey);

        static const char* getApplicationsErrorNameFromEnum(ApplicationError error);

        static uint32_t getApplicationPropertyString(const char* appKey, ApplicationProperty property, char* buffer, uint32_t bufferSize, ApplicationError* error);
        static bool getApplicationPropertyBool(const char* appKey, ApplicationProperty property, ApplicationError* error);
        static uint64_t getApplicationPropertyUint64(const char* appKey, ApplicationProperty property, ApplicationError* error);

        static ApplicationError setApplicationAutoLaunch(const char* appKey, bool autoLaunch);
        static bool getApplicationAutoLaunch(const char* appKey);

        static ApplicationError setDefaultApplicationForMimeType(const char* appKey, const char* mimeType);
        static bool getDefaultApplicationForMimeType(const char* mimeType, char* appKeyBuffer, uint32_t bufferSize);
        static bool getApplicationSupportedMimeTypes(const char* appKey, char* mimeTypesBuffer, uint32_t bufferSize);
        static uint32_t getApplicationsThatSupportMimeType(const char* mimeType, char* appKeysBuffer, uint32_t bufferSize);

        static uint32_t getApplicationLaunchArguments(uint32_t handle, char* args, uint32_t bufferSize);

        static ApplicationError getStartingApplication(char* appKey, uint32_t bufferSize);
        static ApplicationState getApplicationState();

        static ApplicationError performApplicationPrelaunchCheck(const char* appKey);

        static const char* getApplicationStateNameFromEnum(ApplicationState state);

        static ApplicationError launchInternalProcess(const char* binaryPath, const char* args, const char* workingDirectory);

        static uint32_t getCurrentSceneProcessId();

        void* addApplicationManifest_ = (void*) addApplicationManifest;
        void* removeApplicationManifest_ = (void*) removeApplicationManifest;
        void* isApplicationInstalled_ = (void*) isApplicationInstalled;
        void* getApplicationCount_ = (void*) getApplicationCount;
        void* getApplicationKeyByIndex_ = (void*) getApplicationKeyByIndex;
        void* getApplicationKeyByProcessId_ = (void*) getApplicationKeyByProcessId;
        void* launchApplication_ = (void*) launchApplication;
        void* launchTemplateApplication_ = (void*) launchTemplateApplication;
        void* launchApplicationFromMimeType_ = (void*) launchApplicationFromMimeType;
        void* launchDashboardOverlay_ = (void*) launchDashboardOverlay;
        void* cancelApplicationLaunch_ = (void*) cancelApplicationLaunch;
        void* identifyApplication_ = (void*) identifyApplication;
        void* getApplicationProcessId_ = (void*) getApplicationProcessId;
        void* getApplicationsErrorNameFromEnum_ = (void*) getApplicationsErrorNameFromEnum;
        void* getApplicationPropertyString_ = (void*) getApplicationPropertyString;
        void* getApplicationPropertyBool_ = (void*) getApplicationPropertyBool;
        void* getApplicationPropertyUint64_ = (void*) getApplicationPropertyUint64;
        void* setApplicationAutoLaunch_ = (void*) setApplicationAutoLaunch;
        void* getApplicationAutoLaunch_ = (void*) getApplicationAutoLaunch;
        void* setDefaultApplicationForMimeType_ = (void*) setDefaultApplicationForMimeType;
        void* getDefaultApplicationForMimeType_ = (void*) getDefaultApplicationForMimeType;
        void* getApplicationSupportedMimeTypes_ = (void*) getApplicationSupportedMimeTypes;
        void* getApplicationsThatSupportMimeType_ = (void*) getApplicationsThatSupportMimeType;
        void* getApplicationLaunchArguments_ = (void*) getApplicationLaunchArguments;
        void* getStartingApplication_ = (void*) getStartingApplication;
        void* getApplicationState_ = (void*) getApplicationState;
        void* performApplicationPrelaunchCheck_ = (void*) performApplicationPrelaunchCheck;
        void* getApplicationStateNameFromEnum_ = (void*) getApplicationStateNameFromEnum;
        void* launchInternalProcess_ = (void*) launchInternalProcess;
        void* getCurrentSceneProcessId_ = (void*) getCurrentSceneProcessId;
    };

    class Applications_007_v
    {
        public:
            virtual ApplicationError addApplicationManifest(const char* path, bool temporary) { return Applications_007::addApplicationManifest(path, temporary); }
            virtual ApplicationError removeApplicationManifest(const char* path) { return Applications_007::removeApplicationManifest(path); }
            virtual bool isApplicationInstalled(const char* appKey) { return Applications_007::isApplicationInstalled(appKey); }
            virtual uint32_t getApplicationCount() { return Applications_007::getApplicationCount(); }
            virtual ApplicationError getApplicationKeyByIndex(uint32_t index, char* buffer, uint32_t bufferSize) { return Applications_007::getApplicationKeyByIndex(index, buffer, bufferSize); }
            virtual ApplicationError getApplicationKeyByProcessId(uint32_t pid, char* buffer, uint32_t bufferSize) { return Applications_007::getApplicationKeyByProcessId(pid, buffer, bufferSize); }
            virtual ApplicationError launchApplication(const char* appKey) { return Applications_007::launchApplication(appKey); }
            virtual ApplicationError launchTemplateApplication(const char* templateAppKey, const char* newAppKey, const ApplicationOverrideKey* keys, uint32_t keysCount) { return Applications_007::launchTemplateApplication(templateAppKey, newAppKey, keys, keysCount); }
            virtual ApplicationError launchApplicationFromMimeType(const char* mimeType, const char* args) { return Applications_007::launchApplicationFromMimeType(mimeType, args); }
            virtual ApplicationError launchDashboardOverlay(const char* appKey) { return Applications_007::launchDashboardOverlay(appKey); }
            virtual bool cancelApplicationLaunch(const char* appKey) { return Applications_007::cancelApplicationLaunch(appKey); }
            virtual ApplicationError identifyApplication(uint32_t pid, const char* appKey) { return Applications_007::identifyApplication(pid, appKey); }
            virtual uint32_t getApplicationProcessId(const char* appKey) { return Applications_007::getApplicationProcessId(appKey); }
            virtual const char* getApplicationsErrorNameFromEnum(ApplicationError error) { return Applications_007::getApplicationsErrorNameFromEnum(error); }
            virtual uint32_t getApplicationPropertyString(const char* appKey, ApplicationProperty property, char* buffer, uint32_t bufferSize, ApplicationError* error) { return Applications_007::getApplicationPropertyString(appKey, property, buffer, bufferSize, error); }
            virtual bool getApplicationPropertyBool(const char* appKey, ApplicationProperty property, ApplicationError* error) { return Applications_007::getApplicationPropertyBool(appKey, property, error); }
            virtual uint64_t getApplicationPropertyUint64(const char* appKey, ApplicationProperty property, ApplicationError* error) { return Applications_007::getApplicationPropertyUint64(appKey, property, error); }
            virtual ApplicationError setApplicationAutoLaunch(const char* appKey, bool autoLaunch) { return Applications_007::setApplicationAutoLaunch(appKey, autoLaunch); }
            virtual bool getApplicationAutoLaunch(const char* appKey) { return Applications_007::getApplicationAutoLaunch(appKey); }
            virtual ApplicationError setDefaultApplicationForMimeType(const char* appKey, const char* mimeType) { return Applications_007::setDefaultApplicationForMimeType(appKey, mimeType); }
            virtual bool getDefaultApplicationForMimeType(const char* mimeType, char* appKeyBuffer, uint32_t bufferSize) { return Applications_007::getDefaultApplicationForMimeType(mimeType, appKeyBuffer, bufferSize); }
            virtual bool getApplicationSupportedMimeTypes(const char* appKey, char* mimeTypesBuffer, uint32_t bufferSize) { return Applications_007::getApplicationSupportedMimeTypes(appKey, mimeTypesBuffer, bufferSize); }
            virtual uint32_t getApplicationsThatSupportMimeType(const char* mimeType, char* appKeysBuffer, uint32_t bufferSize) { return Applications_007::getApplicationsThatSupportMimeType(mimeType, appKeysBuffer, bufferSize); }
            virtual uint32_t getApplicationLaunchArguments(uint32_t handle, char* args, uint32_t bufferSize) { return Applications_007::getApplicationLaunchArguments(handle, args, bufferSize); }
            virtual ApplicationError getStartingApplication(char* appKey, uint32_t bufferSize) { return Applications_007::getStartingApplication(appKey, bufferSize); }
            virtual ApplicationState getApplicationState() { return Applications_007::getApplicationState(); }
            virtual ApplicationError performApplicationPrelaunchCheck(const char* appKey) { return Applications_007::performApplicationPrelaunchCheck(appKey); }
            virtual const char* getApplicationStateNameFromEnum(ApplicationState state) { return Applications_007::getApplicationStateNameFromEnum(state); }
            virtual ApplicationError launchInternalProcess(const char* binaryPath, const char* args, const char* workingDirectory) { return Applications_007::launchInternalProcess(binaryPath, args, workingDirectory); }
            virtual uint32_t getCurrentSceneProcessId() { return Applications_007::getCurrentSceneProcessId(); }
    };
}
