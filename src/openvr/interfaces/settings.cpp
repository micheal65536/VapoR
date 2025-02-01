#include "settings.h"
#include "../impl/init.h"
#include "log/stub.h"

using namespace openvr;

const char* Settings_001::getSettingsErrorNameFromEnum(SettingsError error)
{
    return openvr::settingsImpl->getSettingsErrorNameFromEnum(error);
}

const char* Settings_002::getSettingsErrorNameFromEnum(SettingsError error)
{
    return openvr::settingsImpl->getSettingsErrorNameFromEnum(error);
}

const char* Settings_003::getSettingsErrorNameFromEnum(SettingsError error)
{
    return openvr::settingsImpl->getSettingsErrorNameFromEnum(error);
}

bool Settings_001::sync(bool force, SettingsError* error)
{
    return openvr::settingsImpl->sync(force, error);
}

bool Settings_002::sync(bool force, SettingsError* error)
{
    return openvr::settingsImpl->sync(force, error);
}

void Settings_001::setBool(const char* section, const char* key, bool value, SettingsError* error)
{
    openvr::settingsImpl->setBool(section, key, value, error);
}

void Settings_002::setBool(const char* section, const char* key, bool value, SettingsError* error)
{
    openvr::settingsImpl->setBool(section, key, value, error);
}

void Settings_003::setBool(const char* section, const char* key, bool value, SettingsError* error)
{
    openvr::settingsImpl->setBool(section, key, value, error);
}

void Settings_001::setInt32(const char* section, const char* key, int32_t value, SettingsError* error)
{
    openvr::settingsImpl->setInt32(section, key, value, error);
}

void Settings_002::setInt32(const char* section, const char* key, int32_t value, SettingsError* error)
{
    openvr::settingsImpl->setInt32(section, key, value, error);
}

void Settings_003::setInt32(const char* section, const char* key, int32_t value, SettingsError* error)
{
    openvr::settingsImpl->setInt32(section, key, value, error);
}

void Settings_001::setFloat(const char* section, const char* key, float value, SettingsError* error)
{
    openvr::settingsImpl->setFloat(section, key, value, error);
}

void Settings_002::setFloat(const char* section, const char* key, float value, SettingsError* error)
{
    openvr::settingsImpl->setFloat(section, key, value, error);
}

void Settings_003::setFloat(const char* section, const char* key, float value, SettingsError* error)
{
    openvr::settingsImpl->setFloat(section, key, value, error);
}

void Settings_001::setString(const char* section, const char* key, const char* value, SettingsError* error)
{
    openvr::settingsImpl->setString(section, key, value, error);
}

void Settings_002::setString(const char* section, const char* key, const char* value, SettingsError* error)
{
    openvr::settingsImpl->setString(section, key, value, error);
}

void Settings_003::setString(const char* section, const char* key, const char* value, SettingsError* error)
{
    openvr::settingsImpl->setString(section, key, value, error);
}

bool Settings_001::getBool(const char* section, const char* key, bool defaultValue, SettingsError* error)
{
    return openvr::settingsImpl->getBool(section, key, defaultValue, error);
}

bool Settings_002::getBool(const char* section, const char* key, SettingsError* error)
{
    return openvr::settingsImpl->getBool(section, key, false, error);
}

bool Settings_003::getBool(const char* section, const char* key, SettingsError* error)
{
    return openvr::settingsImpl->getBool(section, key, false, error);
}

int32_t Settings_001::getInt32(const char* section, const char* key, int32_t defaultValue, SettingsError* error)
{
    return openvr::settingsImpl->getInt32(section, key, defaultValue, error);
}

int32_t Settings_002::getInt32(const char* section, const char* key, SettingsError* error)
{
    return openvr::settingsImpl->getInt32(section, key, 0, error);
}

int32_t Settings_003::getInt32(const char* section, const char* key, SettingsError* error)
{
    return openvr::settingsImpl->getInt32(section, key, 0, error);
}

float Settings_001::getFloat(const char* section, const char* key, float defaultValue, SettingsError* error)
{
    return openvr::settingsImpl->getFloat(section, key, defaultValue, error);
}

float Settings_002::getFloat(const char* section, const char* key, SettingsError* error)
{
    return openvr::settingsImpl->getFloat(section, key, 0.0f, error);
}

float Settings_003::getFloat(const char* section, const char* key, SettingsError* error)
{
    return openvr::settingsImpl->getFloat(section, key, 0.0f, error);
}

void Settings_001::getString(const char* section, const char* key, char* value, uint32_t bufferSize, const char* defaultValue, SettingsError* error)
{
    openvr::settingsImpl->getString(section, key, value, bufferSize, defaultValue, error);
}

void Settings_002::getString(const char* section, const char* key, char* value, uint32_t bufferSize, SettingsError* error)
{
    openvr::settingsImpl->getString(section, key, value, bufferSize, "", error);
}

void Settings_003::getString(const char* section, const char* key, char* value, uint32_t bufferSize, SettingsError* error)
{
    openvr::settingsImpl->getString(section, key, value, bufferSize, "", error);
}

void Settings_001::removeSection(const char* section, SettingsError* error)
{
    openvr::settingsImpl->removeSection(section, error);
}

void Settings_002::removeSection(const char* section, SettingsError* error)
{
    openvr::settingsImpl->removeSection(section, error);
}

void Settings_003::removeSection(const char* section, SettingsError* error)
{
    openvr::settingsImpl->removeSection(section, error);
}

void Settings_001::removeKey(const char* section, const char* key, SettingsError* error)
{
    openvr::settingsImpl->removeKey(section, key, error);
}

void Settings_002::removeKey(const char* section, const char* key, SettingsError* error)
{
    openvr::settingsImpl->removeKey(section, key, error);
}

void Settings_003::removeKey(const char* section, const char* key, SettingsError* error)
{
    openvr::settingsImpl->removeKey(section, key, error);
}
