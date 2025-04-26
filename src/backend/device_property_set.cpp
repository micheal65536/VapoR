#include "device_property_set.h"

#include <stdexcept>

#include <nlohmann/json.hpp>
#include <fstream>
#include <cstdlib>

#include "log/log.h"

using namespace vapor;

using namespace nlohmann;

bool DevicePropertySet::populateFromJSON(const std::string& filePath)
{
    TRACE_F("Reading device properties from %s", filePath.c_str());

    try
    {
        std::ifstream stream(filePath);
        json j = json::parse(stream);

        systemName = j.at("system_name");
        modelName = j.at("model_name");
        serialNumber = j.at("serial_number");
        manufacturerName = j.at("manufacturer_name");
        registeredDeviceType = j.at("registered_device_type");
        controllerType = j.at("controller_type");
        attachedDeviceId = j.contains("attached_device_id") && !j.at("attached_device_id").is_null() ? j.at("attached_device_id") : "";

        return true;
    }
    catch (const std::exception& exception)
    {
        TRACE_F("Failed to load device properties");
        return false;
    }
}
