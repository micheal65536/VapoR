#pragma once

#include "input_devices.h"
#include "binding.h"
#include "backend/input.h"

namespace openvr
{
    namespace input
    {
        inline Device getDeviceFromInputSourcePath(const std::string& path, bool allowPrefix)
        {
            if (path == "/user/hand/left" || (allowPrefix && path.starts_with("/user/hand/left/")))
            {
                return Device::HAND_LEFT;
            }
            else if (path == "/user/hand/right" || (allowPrefix && path.starts_with("/user/hand/right/")))
            {
                return Device::HAND_RIGHT;
            }
            else if (path == "/user/elbow/left" || (allowPrefix && path.starts_with("/user/elbow/left/")))
            {
                return Device::ELBOW_LEFT;
            }
            else if (path == "/user/elbow/right" || (allowPrefix && path.starts_with("/user/elbow/right/")))
            {
                return Device::ELBOW_RIGHT;
            }
            else if (path == "/user/foot/left" || (allowPrefix && path.starts_with("/user/foot/left/")))
            {
                return Device::FOOT_LEFT;
            }
            else if (path == "/user/foot/right" || (allowPrefix && path.starts_with("/user/foot/right/")))
            {
                return Device::FOOT_RIGHT;
            }
            else if (path == "/user/knee/left" || (allowPrefix && path.starts_with("/user/knee/left/")))
            {
                return Device::KNEE_LEFT;
            }
            else if (path == "/user/knee/right" || (allowPrefix && path.starts_with("/user/knee/right/")))
            {
                return Device::KNEE_RIGHT;
            }
            else if (path == "/user/waist" || (allowPrefix && path.starts_with("/user/waist/")))
            {
                return Device::WAIST;
            }
            else if (path == "/user/camera" || (allowPrefix && path.starts_with("/user/camera/")))
            {
                return Device::CAMERA;
            }
            else
            {
                return Device::INVALID;
            }
        }

        inline std::string getDeviceInputSourcePath(Device device)
        {
            switch (device)
            {
                case Device::HAND_LEFT:
                    return "/user/hand/left";
                case Device::HAND_RIGHT:
                    return "/user/hand/right";
                case Device::ELBOW_LEFT:
                    return "/user/elbow/left";
                case Device::ELBOW_RIGHT:
                    return "/user/elbow/right";
                case Device::FOOT_LEFT:
                    return "/user/foot/left";
                case Device::FOOT_RIGHT:
                    return "/user/foot/right";
                case Device::KNEE_LEFT:
                    return "/user/knee/left";
                case Device::KNEE_RIGHT:
                    return "/user/knee/right";
                case Device::WAIST:
                    return "/user/waist/left";
                case Device::CAMERA:
                    return "/user/camera/right";
                default:
                    return "";
            }
        }

        inline std::string getSuffixedInputSourcePath(const std::string& basePath, vapor::OpenVRInputSubpath subpath)
        {
            switch (subpath)
            {
                case vapor::OpenVRInputSubpath::NONE:
                    return basePath;
                case vapor::OpenVRInputSubpath::CLICK:
                    return basePath + "/click";
                case vapor::OpenVRInputSubpath::TOUCH:
                    return basePath + "/touch";
                case vapor::OpenVRInputSubpath::VALUE:
                    return basePath + "/value";
                case vapor::OpenVRInputSubpath::X:
                    return basePath + "/x";
                case vapor::OpenVRInputSubpath::Y:
                    return basePath + "/y";
                default:
                    return "";
            }
        }
    }
}
