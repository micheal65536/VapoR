#include "settings.h"
#include "log/log.h"
#include "log/stub.h"

#include <cstring>

using namespace openvr;

SettingsImpl::SettingsImpl(ClientCoreImpl& clientCore): clientCore(clientCore)
{
    // empty
}

const char* SettingsImpl::getSettingsErrorNameFromEnum(SettingsError error)
{
    STUB_F("%d", error);
    return "";
}

bool SettingsImpl::sync(bool force, SettingsError* error)
{
    TRACE_F("%d", force);
    if (error != nullptr)
    {
        *error = SettingsError::SETTINGS_ERROR_NONE;
    }
    return true;
}

void SettingsImpl::setBool(const char* section, const char* key, bool value, SettingsError* error)
{
    STUB_F("%s %s %d", section, key, value);
    if (error != nullptr)
    {
        *error = SettingsError::SETTINGS_ERROR_NONE;
    }
}

void SettingsImpl::setInt32(const char* section, const char* key, int32_t value, SettingsError* error)
{
    STUB_F("%s %s %d", section, key, value);
    if (error != nullptr)
    {
        *error = SettingsError::SETTINGS_ERROR_NONE;
    }
}

void SettingsImpl::setFloat(const char* section, const char* key, float value, SettingsError* error)
{
    STUB_F("%s %s %f", section, key, value);
    if (error != nullptr)
    {
        *error = SettingsError::SETTINGS_ERROR_NONE;
    }
}

void SettingsImpl::setString(const char* section, const char* key, const char* value, SettingsError* error)
{
    STUB_F("%s %s %s", section, key, value);
    if (error != nullptr)
    {
        *error = SettingsError::SETTINGS_ERROR_NONE;
    }
}

bool SettingsImpl::getBool(const char* section, const char* key, bool defaultValue, SettingsError* error)
{
    STUB_F("%s %s", section, key);
    if (error != nullptr)
    {
        *error = SettingsError::SETTINGS_ERROR_NONE;
    }
    return defaultValue;
}

int32_t SettingsImpl::getInt32(const char* section, const char* key, int32_t defaultValue, SettingsError* error)
{
    STUB_F("%s %s", section, key);
    if (error != nullptr)
    {
        *error = SettingsError::SETTINGS_ERROR_NONE;
    }
    return defaultValue;
}

float SettingsImpl::getFloat(const char* section, const char* key, float defaultValue, SettingsError* error)
{
    STUB_F("%s %s", section, key);
    if (error != nullptr)
    {
        *error = SettingsError::SETTINGS_ERROR_NONE;
    }
    return defaultValue;
}

void SettingsImpl::getString(const char* section, const char* key, char* value, uint32_t bufferSize, const char* defaultValue, SettingsError* error)
{
    STUB_F("%s %s", section, key);
    if (error != nullptr)
    {
        *error = SettingsError::SETTINGS_ERROR_NONE;
    }
    std::strncpy(value, defaultValue, bufferSize);
}

void SettingsImpl::removeSection(const char* section, SettingsError* error)
{
    STUB_F("%s", section);
}

void SettingsImpl::removeKey(const char* section, const char* key, SettingsError* error)
{
    STUB_F("%s %s", section, key);
}
