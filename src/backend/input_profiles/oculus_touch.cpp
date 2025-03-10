#include "oculus_touch.h"

#include <vector>

#include <cmath>
#include <numbers>

using namespace vapor;
using namespace vapor::input_profiles;

static const std::vector<OpenXRInputDescription> openXRInputs = (std::vector<OpenXRInputDescription>) {
    {.path = "/user/hand/left/input/aim/pose", .type = OpenXRInputType::POSE},
    {.path = "/user/hand/right/input/aim/pose", .type = OpenXRInputType::POSE},
    {.path = "/user/hand/left/input/grip/pose", .type = OpenXRInputType::POSE},
    {.path = "/user/hand/right/input/grip/pose", .type = OpenXRInputType::POSE},
    {.path = "/user/hand/left/input/trigger/value", .type = OpenXRInputType::FLOAT},
    {.path = "/user/hand/left/input/trigger/touch", .type = OpenXRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/trigger/value", .type = OpenXRInputType::FLOAT},
    {.path = "/user/hand/right/input/trigger/touch", .type = OpenXRInputType::BOOLEAN},
    {.path = "/user/hand/left/input/squeeze/value", .type = OpenXRInputType::FLOAT},
    {.path = "/user/hand/right/input/squeeze/value", .type = OpenXRInputType::FLOAT},
    {.path = "/user/hand/left/input/thumbstick", .type = OpenXRInputType::VECTOR2},
    {.path = "/user/hand/left/input/thumbstick/click", .type = OpenXRInputType::BOOLEAN},
    {.path = "/user/hand/left/input/thumbstick/touch", .type = OpenXRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/thumbstick", .type = OpenXRInputType::VECTOR2},
    {.path = "/user/hand/right/input/thumbstick/click", .type = OpenXRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/thumbstick/touch", .type = OpenXRInputType::BOOLEAN},
    {.path = "/user/hand/left/input/x/click", .type = OpenXRInputType::BOOLEAN},
    {.path = "/user/hand/left/input/x/touch", .type = OpenXRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/a/click", .type = OpenXRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/a/touch", .type = OpenXRInputType::BOOLEAN},
    {.path = "/user/hand/left/input/y/click", .type = OpenXRInputType::BOOLEAN},
    {.path = "/user/hand/left/input/y/touch", .type = OpenXRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/b/click", .type = OpenXRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/b/touch", .type = OpenXRInputType::BOOLEAN},
    {.path = "/user/hand/left/input/menu/click", .type = OpenXRInputType::BOOLEAN},
    {.path = "/user/hand/left/output/haptic", .type = OpenXRInputType::HAPTIC},
    {.path = "/user/hand/right/output/haptic", .type = OpenXRInputType::HAPTIC}
};

static const std::vector<OpenVRInputDescription> openVRInputs = (std::vector<OpenVRInputDescription>) {
    {.path = "/user/hand/left/pose/raw", .type = OpenVRInputType::POSE, .subpath = OpenVRInputSubpath::NONE},
    {.path = "/user/hand/right/pose/raw", .type = OpenVRInputType::POSE, .subpath = OpenVRInputSubpath::NONE},
    {.path = "/user/hand/left/pose/base", .type = OpenVRInputType::POSE, .subpath = OpenVRInputSubpath::NONE},
    {.path = "/user/hand/right/pose/base", .type = OpenVRInputType::POSE, .subpath = OpenVRInputSubpath::NONE},
    {.path = "/user/hand/left/pose/handgrip", .type = OpenVRInputType::POSE, .subpath = OpenVRInputSubpath::NONE},
    {.path = "/user/hand/right/pose/handgrip", .type = OpenVRInputType::POSE, .subpath = OpenVRInputSubpath::NONE},
    {.path = "/user/hand/left/pose/tip", .type = OpenVRInputType::POSE, .subpath = OpenVRInputSubpath::NONE},
    {.path = "/user/hand/right/pose/tip", .type = OpenVRInputType::POSE, .subpath = OpenVRInputSubpath::NONE},
    {.path = "/user/hand/left/pose/openxr_aim", .type = OpenVRInputType::POSE, .subpath = OpenVRInputSubpath::NONE},
    {.path = "/user/hand/right/pose/openxr_aim", .type = OpenVRInputType::POSE, .subpath = OpenVRInputSubpath::NONE},
    {.path = "/user/hand/left/pose/openxr_grip", .type = OpenVRInputType::POSE, .subpath = OpenVRInputSubpath::NONE},
    {.path = "/user/hand/right/pose/openxr_grip", .type = OpenVRInputType::POSE, .subpath = OpenVRInputSubpath::NONE},
    {.path = "/user/hand/left/input/trigger", .type = OpenVRInputType::TRIGGER, .subpath = OpenVRInputSubpath::VALUE},
    {.path = "/user/hand/left/input/trigger", .type = OpenVRInputType::TRIGGER, .subpath = OpenVRInputSubpath::TOUCH},
    {.path = "/user/hand/right/input/trigger", .type = OpenVRInputType::TRIGGER, .subpath = OpenVRInputSubpath::VALUE},
    {.path = "/user/hand/right/input/trigger", .type = OpenVRInputType::TRIGGER, .subpath = OpenVRInputSubpath::TOUCH},
    {.path = "/user/hand/left/input/grip", .type = OpenVRInputType::TRIGGER, .subpath = OpenVRInputSubpath::VALUE},
    {.path = "/user/hand/right/input/grip", .type = OpenVRInputType::TRIGGER, .subpath = OpenVRInputSubpath::VALUE},
    {.path = "/user/hand/left/input/joystick", .type = OpenVRInputType::JOYSTICK, .subpath = OpenVRInputSubpath::X},
    {.path = "/user/hand/left/input/joystick", .type = OpenVRInputType::JOYSTICK, .subpath = OpenVRInputSubpath::Y},
    {.path = "/user/hand/left/input/joystick", .type = OpenVRInputType::JOYSTICK, .subpath = OpenVRInputSubpath::CLICK},
    {.path = "/user/hand/left/input/joystick", .type = OpenVRInputType::JOYSTICK, .subpath = OpenVRInputSubpath::TOUCH},
    {.path = "/user/hand/right/input/joystick", .type = OpenVRInputType::JOYSTICK, .subpath = OpenVRInputSubpath::X},
    {.path = "/user/hand/right/input/joystick", .type = OpenVRInputType::JOYSTICK, .subpath = OpenVRInputSubpath::Y},
    {.path = "/user/hand/right/input/joystick", .type = OpenVRInputType::JOYSTICK, .subpath = OpenVRInputSubpath::CLICK},
    {.path = "/user/hand/right/input/joystick", .type = OpenVRInputType::JOYSTICK, .subpath = OpenVRInputSubpath::TOUCH},
    {.path = "/user/hand/left/input/x", .type = OpenVRInputType::BUTTON, .subpath = OpenVRInputSubpath::CLICK},
    {.path = "/user/hand/left/input/x", .type = OpenVRInputType::BUTTON, .subpath = OpenVRInputSubpath::TOUCH},
    {.path = "/user/hand/right/input/a", .type = OpenVRInputType::BUTTON, .subpath = OpenVRInputSubpath::CLICK},
    {.path = "/user/hand/right/input/a", .type = OpenVRInputType::BUTTON, .subpath = OpenVRInputSubpath::TOUCH},
    {.path = "/user/hand/left/input/y", .type = OpenVRInputType::BUTTON, .subpath = OpenVRInputSubpath::CLICK},
    {.path = "/user/hand/left/input/y", .type = OpenVRInputType::BUTTON, .subpath = OpenVRInputSubpath::TOUCH},
    {.path = "/user/hand/right/input/b", .type = OpenVRInputType::BUTTON, .subpath = OpenVRInputSubpath::CLICK},
    {.path = "/user/hand/right/input/b", .type = OpenVRInputType::BUTTON, .subpath = OpenVRInputSubpath::TOUCH},
    {.path = "/user/hand/left/input/system", .type = OpenVRInputType::BUTTON, .subpath = OpenVRInputSubpath::CLICK},
    {.path = "/user/hand/left/input/thumbrest", .type = OpenVRInputType::BUTTON, .subpath = OpenVRInputSubpath::TOUCH},
    {.path = "/user/hand/right/input/thumbrest", .type = OpenVRInputType::BUTTON, .subpath = OpenVRInputSubpath::TOUCH},
    {.path = "/user/hand/left/input/skeleton", .type = OpenVRInputType::SKELETON, .subpath = OpenVRInputSubpath::NONE},
    {.path = "/user/hand/right/input/skeleton", .type = OpenVRInputType::SKELETON, .subpath = OpenVRInputSubpath::NONE},
    {.path = "/user/hand/left/output/haptic", .type = OpenVRInputType::HAPTIC, .subpath = OpenVRInputSubpath::NONE},
    {.path = "/user/hand/right/output/haptic", .type = OpenVRInputType::HAPTIC, .subpath = OpenVRInputSubpath::NONE}
};

std::string OculusTouch::getOpenXRInteractionProfileName()
{
    return "/interaction_profiles/oculus/touch_controller";
}

int OculusTouch::getOpenXRInputsCount()
{
    return openXRInputs.size();
}

const OpenXRInputDescription* OculusTouch::getOpenXRInputs()
{
    return openXRInputs.data();
}

std::string OculusTouch::getOpenVRProfileName()
{
    return "oculus_touch";
}

int OculusTouch::getOpenVRInputsCount()
{
    return openVRInputs.size();
}

const OpenVRInputDescription* OculusTouch::getOpenVRInputs()
{
    return openVRInputs.data();
}

LegacyInputDescription OculusTouch::getOpenVRLegacyInputDescription()
{
    return LegacyInputDescription {
        .supportedButtons {
            .system = true, .menu = true,
            .grip = true,
            .dpadLeft = false, .dpadUp = false, .dpadRight = false, .dpadDown = false,
            .buttonA = true,
            .axis0 = true, .axis1 = true, .axis2 = true, .axis3 = false, .axis4 = false
        },
        .axisTypes {
            LegacyInputDescription::AxisType::JOYSTICK, LegacyInputDescription::AxisType::TRIGGER, LegacyInputDescription::AxisType::TRIGGER, LegacyInputDescription::AxisType::NONE, LegacyInputDescription::AxisType::NONE
        }
    };
}

OpenVRInputState OculusTouch::getOpenVRInputState(int inputIndex, const OpenXRInputState* openXRInputStates)
{
    switch (inputIndex)
    {
        case 0:
        case 1:
            return OpenVRInputState {
                .data = {.pose = {
                    .local = openXRInputStates[inputIndex + 2].data.pose.local,
                    .localFloor = openXRInputStates[inputIndex + 2].data.pose.localFloor,
                    .localNextFrame = openXRInputStates[inputIndex + 2].data.pose.localNextFrame,
                    .localFloorNextFrame = openXRInputStates[inputIndex + 2].data.pose.localFloorNextFrame,
                    .offsetMatrix = {
                        {1.0f, 0.0f, 0.0f, 0.0f},
                        {0.0f, std::cos(20.0f * std::numbers::pi / 180.0f), std::sin(20.0f * std::numbers::pi / 180.0f), -0.1f * std::sin(20.0f * std::numbers::pi / 180.0f)},
                        {0.0f, -std::sin(20.0f * std::numbers::pi / 180.0f), std::cos(20.0f * std::numbers::pi / 180.0f), -0.1f * std::cos(20.0f * std::numbers::pi / 180.0f)}
                    }
                }},
                .changeTime = openXRInputStates[inputIndex + 2].changeTime
            };
        case 2:
        case 3:
            return OpenVRInputState {
                .data = {.pose = {
                    .local = openXRInputStates[inputIndex].data.pose.local,
                    .localFloor = openXRInputStates[inputIndex].data.pose.localFloor,
                    .localNextFrame = openXRInputStates[inputIndex].data.pose.localNextFrame,
                    .localFloorNextFrame = openXRInputStates[inputIndex].data.pose.localFloorNextFrame,
                    .offsetMatrix = {
                        {-1.0f, 0.0f, 0.0f, 0.0f},
                        {0.0f, std::cos(20.0f * std::numbers::pi / 180.0f), -std::sin(20.0f * std::numbers::pi / 180.0f), 0.05f * std::sin(20.0f * std::numbers::pi / 180.0f)},
                        {0.0f, -std::sin(20.0f * std::numbers::pi / 180.0f), -std::cos(20.0f * std::numbers::pi / 180.0f), 0.05f * std::cos(20.0f * std::numbers::pi / 180.0f)}
                    }
                }},
                .changeTime = openXRInputStates[inputIndex].changeTime
            };
        case 4:
        case 5:
            return OpenVRInputState {
                .data = {.pose = {
                    .local = openXRInputStates[inputIndex - 2].data.pose.local,
                    .localFloor = openXRInputStates[inputIndex - 2].data.pose.localFloor,
                    .localNextFrame = openXRInputStates[inputIndex - 2].data.pose.localNextFrame,
                    .localFloorNextFrame = openXRInputStates[inputIndex - 2].data.pose.localFloorNextFrame,
                    .offsetMatrix = {
                        {1.0f, 0.0f, 0.0f, 0.0f},
                        {0.0f, std::cos(20.0f * std::numbers::pi / 180.0f), std::sin(20.0f * std::numbers::pi / 180.0f), 0.0f},
                        {0.0f, -std::sin(20.0f * std::numbers::pi / 180.0f), std::cos(20.0f * std::numbers::pi / 180.0f), 0.0f}
                    }
                }},
                .changeTime = openXRInputStates[inputIndex - 2].changeTime
            };
        case 6:
        case 7:
            return OpenVRInputState {
                .data = {.pose = {
                    .local = openXRInputStates[inputIndex - 6].data.pose.local,
                    .localFloor = openXRInputStates[inputIndex - 6].data.pose.localFloor,
                    .localNextFrame = openXRInputStates[inputIndex - 6].data.pose.localNextFrame,
                    .localFloorNextFrame = openXRInputStates[inputIndex - 6].data.pose.localFloorNextFrame,
                    .offsetMatrix = {
                        {1.0f, 0.0f, 0.0f, 0.0f},
                        {0.0f, 1.0f, 0.0f, 0.0f},
                        {0.0f, 0.0f, 1.0f, 0.02f}
                    }
                }},
                .changeTime = openXRInputStates[inputIndex - 6].changeTime
            };
        case 8:
        case 9:
        case 10:
        case 11:
            return OpenVRInputState {
                .data = {.pose = openXRInputStates[inputIndex - 8].data.pose},
                .changeTime = openXRInputStates[inputIndex - 8].changeTime
            };
        case 12:
        case 14:
        case 16:
        case 17:
            return OpenVRInputState {
                .data = {.f = openXRInputStates[inputIndex - 8].data.f},
                .changeTime = openXRInputStates[inputIndex - 8].changeTime
            };
        case 13:
        case 15:
            return OpenVRInputState {
                .data = {.b = openXRInputStates[inputIndex - 8].data.b},
                .changeTime = openXRInputStates[inputIndex - 8].changeTime
            };
        case 18:
        case 22:
            return OpenVRInputState {
                .data = {.f = openXRInputStates[inputIndex == 18 ? 10 : 13].data.vec2.x},
                .changeTime = openXRInputStates[inputIndex == 18 ? 10 : 13].changeTime
            };
        case 19:
        case 23:
            return OpenVRInputState {
                .data = {.f = openXRInputStates[inputIndex == 19 ? 10 : 13].data.vec2.y},
                .changeTime = openXRInputStates[inputIndex == 19 ? 10 : 13].changeTime
            };
        case 20:
        case 21:
        case 24:
        case 25:
            return OpenVRInputState {
                .data = {.b = openXRInputStates[inputIndex < 24 ? (inputIndex - 9) : (inputIndex - 10)].data.b},
                .changeTime = openXRInputStates[inputIndex < 24 ? (inputIndex - 9) : (inputIndex - 10)].changeTime
            };
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 33:
            return OpenVRInputState {
                .data = {.b = openXRInputStates[inputIndex - 10].data.b},
                .changeTime = openXRInputStates[inputIndex - 10].changeTime
            };
        case 34:
            return OpenVRInputState {
                .data = {.b = openXRInputStates[24].data.b},
                .changeTime = openXRInputStates[24].changeTime
            };
        // TODO: thumbrest
        default:
            return OpenVRInputState {
            };
    }
}

OpenVRInputState OculusTouch::getOpenVRControllerPose(int controllerIndex, const OpenVRInputState* openVRInputStates)
{
    if (controllerIndex == 0)
    {
        return openVRInputStates[0];
    }
    else if (controllerIndex == 1)
    {
        return openVRInputStates[1];
    }
}

LegacyInputState OculusTouch::getOpenVRLegacyInputState(int controllerIndex, const OpenXRInputState* openXRInputStates)
{
    return LegacyInputState {
        // TODO: proper threshold for float -> boolean inputs (e.g. grip) (missing from OpenXR side)
        .touch = {
            .system = controllerIndex == 0 ? openXRInputStates[24].data.b : false,
            .menu = openXRInputStates[21 + controllerIndex * 2].data.b,
            .grip = openXRInputStates[8 + controllerIndex].data.f > 0.5f,
            .dpadLeft = false,
            .dpadUp = false,
            .dpadRight = false,
            .dpadDown = false,
            .buttonA = openXRInputStates[17 + controllerIndex * 2].data.b,
            .axis0 = openXRInputStates[12 + controllerIndex * 3].data.b,
            .axis1 = openXRInputStates[5 + controllerIndex * 2].data.b,
            .axis2 = openXRInputStates[8 + controllerIndex].data.f > 0.5f,
            .axis3 = false,
            .axis4 = false
        },
        .click = {
            .system = controllerIndex == 0 ? openXRInputStates[24].data.b : false,
            .menu = openXRInputStates[20 + controllerIndex * 2].data.b,
            .grip = openXRInputStates[8 + controllerIndex].data.f > 0.5f,
            .dpadLeft = false,
            .dpadUp = false,
            .dpadRight = false,
            .dpadDown = false,
            .buttonA = openXRInputStates[16 + controllerIndex * 2].data.b,
            .axis0 = openXRInputStates[11 + controllerIndex * 3].data.b,
            .axis1 = openXRInputStates[4 + controllerIndex * 2].data.f > 0.5f,
            .axis2 = openXRInputStates[8 + controllerIndex].data.f > 0.5f,
            .axis3 = false,
            .axis4 = false
        },
        .axes = {
            {.x = openXRInputStates[10 + controllerIndex * 3].data.vec2.x, .y = openXRInputStates[10 + controllerIndex * 3].data.vec2.y},
            {.x = openXRInputStates[4 + controllerIndex * 2].data.f, .y = 0.0f},
            {.x = openXRInputStates[8 + controllerIndex].data.f, .y = 0.0f},
            {.x = 0.0f, .y = 0.0f},
            {.x = 0.0f, .y = 0.0f}
        }
    };
}

int OculusTouch::getOpenXRHapticActionIndex(int openVRInputIndex)
{
    switch (openVRInputIndex)
    {
        case 39:
            return 25;
        case 40:
            return 26;
    }
}

int OculusTouch::getOpenXRHapticActionIndexForLegacyInput(int controllerIndex)
{
    if (controllerIndex == 0)
    {
        return 25;
    }
    else if (controllerIndex == 1)
    {
        return 26;
    }
}
