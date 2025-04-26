#pragma once

#include <string>
#include <cstdint>
#include "openvr/types_geometry.h"
#include <map>
#include <vector>

namespace vapor
{
    class DevicePropertySet
    {
        public:
            bool populateFromJSON(const std::string& filePath);

        public:
            std::string systemName;
            std::string modelName;
            std::string serialNumber;
            std::string manufacturerName;
            std::string registeredDeviceType;
            std::string controllerType;
            std::string attachedDeviceId;
    };
}
