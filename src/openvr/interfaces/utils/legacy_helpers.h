#pragma once

#include "openvr/types.h"

#include "log/log.h"

namespace openvr
{
    namespace utils
    {
        inline void convertToLegacyEvent(Event_0_9_0& legacyEvent, const Event_0_9_15& event)
        {
            // TODO: convert mouse event type/format
            // TODO: log event types that can't be converted
            legacyEvent.type = event.type;
            legacyEvent.trackedDeviceIndex = event.trackedDeviceIndex;
            legacyEvent.ageSeconds = event.ageSeconds;
            std::memcpy(&legacyEvent.data, &event.data, sizeof(Event_0_9_0::EventData));
        }

        inline TextureType legacyDeviceTypeToTextureType(DeviceType deviceType)
        {
            switch (deviceType)
            {
                case DeviceType::DEVICE_TYPE_OPENGL:
                    return TextureType::TEXTURE_TYPE_OPENGL;
                case DeviceType::DEVICE_TYPE_D3D9:
                case DeviceType::DEVICE_TYPE_D3D9EX:
                case DeviceType::DEVICE_TYPE_D3D10:
                case DeviceType::DEVICE_TYPE_D3D11:
                    return TextureType::TEXTURE_TYPE_DIRECTX_11;
                case DeviceType::DEVICE_TYPE_NONE:
                    TRACE_F("no device type specified");
                    return TextureType::TEXTURE_TYPE_INVALID;
                default:
                    TRACE_F("invalid device type value!");
                    return TextureType::TEXTURE_TYPE_INVALID;
            }
        }
    }
}
