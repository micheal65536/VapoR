#pragma once

#include "input/action_manager.h"
#include "openvr/types.h"
#include "backend/backend.h"

#include <future>

namespace openvr
{
    class ClientCoreImpl
    {
        public:
            vapor::Backend* backend;
            std::promise<bool> backendFinishedPromise;

            TrackingUniverseOrigin trackingSpace = TrackingUniverseOrigin::ORIGIN_STANDING;
            input::ActionManager* actionManager = nullptr;

            //

            InitError init(ApplicationType applicationType, const char* startupInfo);
            void cleanup();

            InitError isInterfaceVersionValid(const char* nameAndVersion);
            void* getGenericInterface(const char* nameAndVersion, InitError* error);

            bool isHmdPresent();

            const char* getStringForInitError(InitError error);
            const char* getIDForInitError(InitError error);
    };
}
