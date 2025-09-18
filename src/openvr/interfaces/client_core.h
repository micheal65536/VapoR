#pragma once

#include "../types.h"

#include "../impl/client_core.h"

namespace openvr
{
    // TODO: ClientCore_001 is known to exist but we don't have source code for it so we don't know the format

    struct ClientCore_002
    {
        static InitError init(ApplicationType applicationType);
        static void cleanup();

        static InitError isInterfaceVersionValid(const char* nameAndVersion);
        static void* getGenericInterface(const char* nameAndVersion, InitError* error);

        static bool isHmdPresent();

        static const char* getStringForInitError(InitError error);
        static const char* getIDForInitError(InitError error);

        void* init_ = (void*) init;
        void* cleanup_ = (void*) cleanup;
        void* isInterfaceVersionValid_ = (void*) isInterfaceVersionValid;
        void* getGenericInterface_ = (void*) getGenericInterface;
        void* isHmdPresent_ = (void*) isHmdPresent;
        void* getStringForInitError_ = (void*) getStringForInitError;
        void* getIDForInitError_ = (void*) getIDForInitError;
    };

    class ClientCore_002_v
    {
        public:
            virtual InitError init(ApplicationType applicationType) { return ClientCore_002::init(applicationType); }
            virtual void cleanup() { return ClientCore_002::cleanup(); }
            virtual InitError isInterfaceVersionValid(const char* nameAndVersion) { return ClientCore_002::isInterfaceVersionValid(nameAndVersion); }
            virtual void* getGenericInterface(const char* nameAndVersion, InitError* error) { return ClientCore_002::getGenericInterface(nameAndVersion, error); }
            virtual bool isHmdPresent() { return ClientCore_002::isHmdPresent(); }
            virtual const char* getStringForInitError(InitError error) { return ClientCore_002::getStringForInitError(error); }
            virtual const char* getIDForInitError(InitError error) { return ClientCore_002::getIDForInitError(error); }
    };

    //

    struct ClientCore_003
    {
        static InitError init(ApplicationType applicationType, const char* startupInfo);
        static void cleanup();

        static InitError isInterfaceVersionValid(const char* nameAndVersion);
        static void* getGenericInterface(const char* nameAndVersion, InitError* error);

        static bool isHmdPresent();

        static const char* getStringForInitError(InitError error);
        static const char* getIDForInitError(InitError error);

        void* init_ = (void*) init;
        void* cleanup_ = (void*) cleanup;
        void* isInterfaceVersionValid_ = (void*) isInterfaceVersionValid;
        void* getGenericInterface_ = (void*) getGenericInterface;
        void* isHmdPresent_ = (void*) isHmdPresent;
        void* getStringForInitError_ = (void*) getStringForInitError;
        void* getIDForInitError_ = (void*) getIDForInitError;
    };

    class ClientCore_003_v
    {
        public:
            virtual InitError init(ApplicationType applicationType, const char* startupInfo) { return ClientCore_003::init(applicationType, startupInfo); }
            virtual void cleanup() { return ClientCore_003::cleanup(); }
            virtual InitError isInterfaceVersionValid(const char* nameAndVersion) { return ClientCore_003::isInterfaceVersionValid(nameAndVersion); }
            virtual void* getGenericInterface(const char* nameAndVersion, InitError* error) { return ClientCore_003::getGenericInterface(nameAndVersion, error); }
            virtual bool isHmdPresent() { return ClientCore_003::isHmdPresent(); }
            virtual const char* getStringForInitError(InitError error) { return ClientCore_003::getStringForInitError(error); }
            virtual const char* getIDForInitError(InitError error) { return ClientCore_003::getIDForInitError(error); }
    };
}
