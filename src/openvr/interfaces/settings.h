#pragma once

#include "../types.h"
#include <cstdint>

#include "../impl/settings.h"

namespace openvr
{
    struct Settings_001
    {
        static const char* getSettingsErrorNameFromEnum(SettingsError error);

        static bool sync(bool force, SettingsError* error);

        static bool getBool(const char* section, const char* key, bool defaultValue, SettingsError* error);
        static void setBool(const char* section, const char* key, bool value, SettingsError* error);
        static int32_t getInt32(const char* section, const char* key, int32_t defaultValue, SettingsError* error);
        static void setInt32(const char* section, const char* key, int32_t value, SettingsError* error);
        static float getFloat(const char* section, const char* key, float defaultValue, SettingsError* error);
        static void setFloat(const char* section, const char* key, float value, SettingsError* error);
        static void getString(const char* section, const char* key, char* value, uint32_t bufferSize, const char* defaultValue, SettingsError* error);
        static void setString(const char* section, const char* key, const char* value, SettingsError* error);

        static void removeSection(const char* section, SettingsError* error);
        static void removeKey(const char* section, const char* key, SettingsError* error);
    
        void* getSettingsErrorNameFromEnum_ = (void*) getSettingsErrorNameFromEnum;
        void* sync_ = (void*) sync;
        void* getBool_ = (void*) getBool;
        void* setBool_ = (void*) setBool;
        void* getInt32_ = (void*) getInt32;
        void* setInt32_ = (void*) setInt32;
        void* getFloat_ = (void*) getFloat;
        void* setFloat_ = (void*) setFloat;
        void* getString_ = (void*) getString;
        void* setString_ = (void*) setString;
        void* removeSection_ = (void*) removeSection;
        void* removeKey_ = (void*) removeKey;
    };

    class Settings_001_v
    {
        public:
            virtual const char* getSettingsErrorNameFromEnum(SettingsError error) { return Settings_001::getSettingsErrorNameFromEnum(error); }
            virtual bool sync(bool force, SettingsError* error) { return Settings_001::sync(force, error); }
            virtual bool getBool(const char* section, const char* key, bool defaultValue, SettingsError* error) { return Settings_001::getBool(section, key, defaultValue, error); }
            virtual void setBool(const char* section, const char* key, bool value, SettingsError* error) { return Settings_001::setBool(section, key, value, error); }
            virtual int32_t getInt32(const char* section, const char* key, int32_t defaultValue, SettingsError* error) { return Settings_001::getInt32(section, key, defaultValue, error); }
            virtual void setInt32(const char* section, const char* key, int32_t value, SettingsError* error) { return Settings_001::setInt32(section, key, value, error); }
            virtual float getFloat(const char* section, const char* key, float defaultValue, SettingsError* error) { return Settings_001::getFloat(section, key, defaultValue, error); }
            virtual void setFloat(const char* section, const char* key, float value, SettingsError* error) { return Settings_001::setFloat(section, key, value, error); }
            virtual void getString(const char* section, const char* key, char* value, uint32_t bufferSize, const char* defaultValue, SettingsError* error) { return Settings_001::getString(section, key, value, bufferSize, defaultValue, error); }
            virtual void setString(const char* section, const char* key, const char* value, SettingsError* error) { return Settings_001::setString(section, key, value, error); }
            virtual void removeSection(const char* section, SettingsError* error) { return Settings_001::removeSection(section, error); }
            virtual void removeKey(const char* section, const char* key, SettingsError* error) { return Settings_001::removeKey(section, key, error); }
    };

    //

    struct Settings_002
    {
        static const char* getSettingsErrorNameFromEnum(SettingsError error);

        static bool sync(bool force, SettingsError* error);

        static void setBool(const char* section, const char* key, bool value, SettingsError* error);
        static void setInt32(const char* section, const char* key, int32_t value, SettingsError* error);
        static void setFloat(const char* section, const char* key, float value, SettingsError* error);
        static void setString(const char* section, const char* key, const char* value, SettingsError* error);

        static bool getBool(const char* section, const char* key, SettingsError* error);
        static int32_t getInt32(const char* section, const char* key, SettingsError* error);
        static float getFloat(const char* section, const char* key, SettingsError* error);
        static void getString(const char* section, const char* key, char* value, uint32_t bufferSize, SettingsError* error);

        static void removeSection(const char* section, SettingsError* error);
        static void removeKey(const char* section, const char* key, SettingsError* error);
    
        void* getSettingsErrorNameFromEnum_ = (void*) getSettingsErrorNameFromEnum;
        void* sync_ = (void*) sync;
        void* setBool_ = (void*) setBool;
        void* setInt32_ = (void*) setInt32;
        void* setFloat_ = (void*) setFloat;
        void* setString_ = (void*) setString;
        void* getBool_ = (void*) getBool;
        void* getInt32_ = (void*) getInt32;
        void* getFloat_ = (void*) getFloat;
        void* getString_ = (void*) getString;
        void* removeSection_ = (void*) removeSection;
        void* removeKey_ = (void*) removeKey;
    };

    class Settings_002_v
    {
        public:
            virtual const char* getSettingsErrorNameFromEnum(SettingsError error) { return Settings_002::getSettingsErrorNameFromEnum(error); }
            virtual bool sync(bool force, SettingsError* error) { return Settings_002::sync(force, error); }
            virtual void setBool(const char* section, const char* key, bool value, SettingsError* error) { return Settings_002::setBool(section, key, value, error); }
            virtual void setInt32(const char* section, const char* key, int32_t value, SettingsError* error) { return Settings_002::setInt32(section, key, value, error); }
            virtual void setFloat(const char* section, const char* key, float value, SettingsError* error) { return Settings_002::setFloat(section, key, value, error); }
            virtual void setString(const char* section, const char* key, const char* value, SettingsError* error) { return Settings_002::setString(section, key, value, error); }
            virtual bool getBool(const char* section, const char* key, SettingsError* error) { return Settings_002::getBool(section, key, error); }
            virtual int32_t getInt32(const char* section, const char* key, SettingsError* error) { return Settings_002::getInt32(section, key, error); }
            virtual float getFloat(const char* section, const char* key, SettingsError* error) { return Settings_002::getFloat(section, key, error); }
            virtual void getString(const char* section, const char* key, char* value, uint32_t bufferSize, SettingsError* error) { return Settings_002::getString(section, key, value, bufferSize, error); }
            virtual void removeSection(const char* section, SettingsError* error) { return Settings_002::removeSection(section, error); }
            virtual void removeKey(const char* section, const char* key, SettingsError* error) { return Settings_002::removeKey(section, key, error); }
    };

    //

    struct Settings_003
    {
        static const char* getSettingsErrorNameFromEnum(SettingsError error);

        static void setBool(const char* section, const char* key, bool value, SettingsError* error);
        static void setInt32(const char* section, const char* key, int32_t value, SettingsError* error);
        static void setFloat(const char* section, const char* key, float value, SettingsError* error);
        static void setString(const char* section, const char* key, const char* value, SettingsError* error);

        static bool getBool(const char* section, const char* key, SettingsError* error);
        static int32_t getInt32(const char* section, const char* key, SettingsError* error);
        static float getFloat(const char* section, const char* key, SettingsError* error);
        static void getString(const char* section, const char* key, char* value, uint32_t bufferSize, SettingsError* error);

        static void removeSection(const char* section, SettingsError* error);
        static void removeKey(const char* section, const char* key, SettingsError* error);
    
        void* getSettingsErrorNameFromEnum_ = (void*) getSettingsErrorNameFromEnum;
        void* setBool_ = (void*) setBool;
        void* setInt32_ = (void*) setInt32;
        void* setFloat_ = (void*) setFloat;
        void* setString_ = (void*) setString;
        void* getBool_ = (void*) getBool;
        void* getInt32_ = (void*) getInt32;
        void* getFloat_ = (void*) getFloat;
        void* getString_ = (void*) getString;
        void* removeSection_ = (void*) removeSection;
        void* removeKey_ = (void*) removeKey;
    };

    class Settings_003_v
    {
        public:
            virtual const char* getSettingsErrorNameFromEnum(SettingsError error) { return Settings_003::getSettingsErrorNameFromEnum(error); }
            virtual void setBool(const char* section, const char* key, bool value, SettingsError* error) { return Settings_003::setBool(section, key, value, error); }
            virtual void setInt32(const char* section, const char* key, int32_t value, SettingsError* error) { return Settings_003::setInt32(section, key, value, error); }
            virtual void setFloat(const char* section, const char* key, float value, SettingsError* error) { return Settings_003::setFloat(section, key, value, error); }
            virtual void setString(const char* section, const char* key, const char* value, SettingsError* error) { return Settings_003::setString(section, key, value, error); }
            virtual bool getBool(const char* section, const char* key, SettingsError* error) { return Settings_003::getBool(section, key, error); }
            virtual int32_t getInt32(const char* section, const char* key, SettingsError* error) { return Settings_003::getInt32(section, key, error); }
            virtual float getFloat(const char* section, const char* key, SettingsError* error) { return Settings_003::getFloat(section, key, error); }
            virtual void getString(const char* section, const char* key, char* value, uint32_t bufferSize, SettingsError* error) { return Settings_003::getString(section, key, value, bufferSize, error); }
            virtual void removeSection(const char* section, SettingsError* error) { return Settings_003::removeSection(section, error); }
            virtual void removeKey(const char* section, const char* key, SettingsError* error) { return Settings_003::removeKey(section, key, error); }
    };
}
