#pragma once

#include "../types.h"
#include <cstdint>
#include "client_core.h"

namespace openvr
{
    class SettingsImpl
    {
        public:
            ClientCoreImpl& clientCore;
            SettingsImpl(ClientCoreImpl& clientCore);

            //

            const char* getSettingsErrorNameFromEnum(SettingsError error);

            bool sync(bool force, SettingsError* error);

            void setBool(const char* section, const char* key, bool value, SettingsError* error);
            void setInt32(const char* section, const char* key, int32_t value, SettingsError* error);
            void setFloat(const char* section, const char* key, float value, SettingsError* error);
            void setString(const char* section, const char* key, const char* value, SettingsError* error);

            bool getBool(const char* section, const char* key, bool defaultValue, SettingsError* error);
            int32_t getInt32(const char* section, const char* key, int32_t defaultValue, SettingsError* error);
            float getFloat(const char* section, const char* key, float defaultValue, SettingsError* error);
            void getString(const char* section, const char* key, char* value, uint32_t bufferSize, const char* defaultValue, SettingsError* error);

            void removeSection(const char* section, SettingsError* error);
            void removeKey(const char* section, const char* key, SettingsError* error);
    };
}
