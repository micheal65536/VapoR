#include "oculus_touch.h"

#include <vector>

#include <cmath>
#include <numbers>

using namespace vapor;
using namespace vapor::input_profile;
using namespace vapor::input_profile::profiles;

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
    {.path = "/user/hand/left/pose/raw", .type = OpenVRInputType::POSE},
    {.path = "/user/hand/right/pose/raw", .type = OpenVRInputType::POSE},
    {.path = "/user/hand/left/pose/base", .type = OpenVRInputType::POSE},
    {.path = "/user/hand/right/pose/base", .type = OpenVRInputType::POSE},
    {.path = "/user/hand/left/pose/handgrip", .type = OpenVRInputType::POSE},
    {.path = "/user/hand/right/pose/handgrip", .type = OpenVRInputType::POSE},
    {.path = "/user/hand/left/pose/tip", .type = OpenVRInputType::POSE},
    {.path = "/user/hand/right/pose/tip", .type = OpenVRInputType::POSE},
    {.path = "/user/hand/left/pose/openxr_aim", .type = OpenVRInputType::POSE},
    {.path = "/user/hand/right/pose/openxr_aim", .type = OpenVRInputType::POSE},
    {.path = "/user/hand/left/pose/openxr_grip", .type = OpenVRInputType::POSE},
    {.path = "/user/hand/right/pose/openxr_grip", .type = OpenVRInputType::POSE},
    {.path = "/user/hand/left/input/trigger/value", .type = OpenVRInputType::FLOAT},
    {.path = "/user/hand/left/input/trigger/touch", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/trigger/value", .type = OpenVRInputType::FLOAT},
    {.path = "/user/hand/right/input/trigger/touch", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/left/input/grip/value", .type = OpenVRInputType::FLOAT},
    {.path = "/user/hand/right/input/grip/value", .type = OpenVRInputType::FLOAT},
    {.path = "/user/hand/left/input/joystick/x", .type = OpenVRInputType::FLOAT},
    {.path = "/user/hand/left/input/joystick/y", .type = OpenVRInputType::FLOAT},
    {.path = "/user/hand/left/input/joystick/click", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/left/input/joystick/touch", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/joystick/x", .type = OpenVRInputType::FLOAT},
    {.path = "/user/hand/right/input/joystick/y", .type = OpenVRInputType::FLOAT},
    {.path = "/user/hand/right/input/joystick/click", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/joystick/touch", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/left/input/x/click", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/left/input/x/touch", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/a/click", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/a/touch", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/left/input/y/click", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/left/input/y/touch", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/b/click", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/b/touch", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/left/input/system/click", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/left/input/thumbrest/touch", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/thumbrest/touch", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/left/input/skeleton", .type = OpenVRInputType::SKELETON},
    {.path = "/user/hand/right/input/skeleton", .type = OpenVRInputType::SKELETON},
    {.path = "/user/hand/left/output/haptic", .type = OpenVRInputType::HAPTIC},
    {.path = "/user/hand/right/output/haptic", .type = OpenVRInputType::HAPTIC}
};

static const std::vector<OpenVRProfileInputDescription> openVRProfileInputs = (std::vector<OpenVRProfileInputDescription>) {
    {.path = "/user/hand/left/pose/raw", .type = OpenVRProfileInputType::POSE},
    {.path = "/user/hand/right/pose/raw", .type = OpenVRProfileInputType::POSE},
    {.path = "/user/hand/left/pose/base", .type = OpenVRProfileInputType::POSE},
    {.path = "/user/hand/right/pose/base", .type = OpenVRProfileInputType::POSE},
    {.path = "/user/hand/left/pose/handgrip", .type = OpenVRProfileInputType::POSE},
    {.path = "/user/hand/right/pose/handgrip", .type = OpenVRProfileInputType::POSE},
    {.path = "/user/hand/left/pose/tip", .type = OpenVRProfileInputType::POSE},
    {.path = "/user/hand/right/pose/tip", .type = OpenVRProfileInputType::POSE},
    {.path = "/user/hand/left/pose/openxr_aim", .type = OpenVRProfileInputType::POSE},
    {.path = "/user/hand/right/pose/openxr_aim", .type = OpenVRProfileInputType::POSE},
    {.path = "/user/hand/left/pose/openxr_grip", .type = OpenVRProfileInputType::POSE},
    {.path = "/user/hand/right/pose/openxr_grip", .type = OpenVRProfileInputType::POSE},
    {.path = "/user/hand/left/input/trigger", .type = OpenVRProfileInputType::TRIGGER, .touch = true, .value = true},
    {.path = "/user/hand/right/input/trigger", .type = OpenVRProfileInputType::TRIGGER, .touch = true, .value = true},
    {.path = "/user/hand/left/input/grip", .type = OpenVRProfileInputType::TRIGGER, .touch = true, .value = true},
    {.path = "/user/hand/right/input/grip", .type = OpenVRProfileInputType::TRIGGER, .touch = true, .value = true},
    {.path = "/user/hand/left/input/joystick", .type = OpenVRProfileInputType::JOYSTICK, .click = true, .touch = true},
    {.path = "/user/hand/right/input/joystick", .type = OpenVRProfileInputType::JOYSTICK, .click = true, .touch = true},
    {.path = "/user/hand/left/input/x", .type = OpenVRProfileInputType::BUTTON, .click = true, .touch = true},
    {.path = "/user/hand/right/input/a", .type = OpenVRProfileInputType::BUTTON, .click = true, .touch = true},
    {.path = "/user/hand/left/input/y", .type = OpenVRProfileInputType::BUTTON, .click = true, .touch = true},
    {.path = "/user/hand/right/input/b", .type = OpenVRProfileInputType::BUTTON, .click = true, .touch = true},
    {.path = "/user/hand/left/input/system", .type = OpenVRProfileInputType::BUTTON, .click = true, .touch = true},
    {.path = "/user/hand/left/input/thumbrest", .type = OpenVRProfileInputType::BUTTON, .click = false, .touch = true},
    {.path = "/user/hand/right/input/thumbrest", .type = OpenVRProfileInputType::BUTTON, .click = false, .touch = true},
    {.path = "/user/hand/left/input/skeleton", .type = OpenVRProfileInputType::SKELETON},
    {.path = "/user/hand/right/input/skeleton", .type = OpenVRProfileInputType::SKELETON},
    {.path = "/user/hand/left/output/haptic", .type = OpenVRProfileInputType::HAPTIC},
    {.path = "/user/hand/right/output/haptic", .type = OpenVRProfileInputType::HAPTIC}
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

int OculusTouch::getOpenVRProfileInputsCount()
{
    return openVRProfileInputs.size();
}

const OpenVRProfileInputDescription* OculusTouch::getOpenVRProfileInputs()
{
    return openVRProfileInputs.data();
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
                .type = OpenVRInputType::POSE,
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
                .type = OpenVRInputType::POSE,
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
                .type = OpenVRInputType::POSE,
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
                .type = OpenVRInputType::POSE,
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
                .type = OpenVRInputType::POSE,
                .data = {.pose = openXRInputStates[inputIndex - 8].data.pose},
                .changeTime = openXRInputStates[inputIndex - 8].changeTime
            };
        case 12:
        case 14:
        case 16:
        case 17:
            return OpenVRInputState {
                .type = OpenVRInputType::FLOAT,
                .data = {.f = openXRInputStates[inputIndex - 8].data.f},
                .changeTime = openXRInputStates[inputIndex - 8].changeTime
            };
        case 13:
        case 15:
            return OpenVRInputState {
                .type = OpenVRInputType::BOOLEAN,
                .data = {.b = openXRInputStates[inputIndex - 8].data.b},
                .changeTime = openXRInputStates[inputIndex - 8].changeTime
            };
        case 18:
        case 22:
            return OpenVRInputState {
                .type = OpenVRInputType::FLOAT,
                .data = {.f = openXRInputStates[inputIndex == 18 ? 10 : 13].data.vec2.x},
                .changeTime = openXRInputStates[inputIndex == 18 ? 10 : 13].changeTime
            };
        case 19:
        case 23:
            return OpenVRInputState {
                .type = OpenVRInputType::FLOAT,
                .data = {.f = openXRInputStates[inputIndex == 19 ? 10 : 13].data.vec2.y},
                .changeTime = openXRInputStates[inputIndex == 19 ? 10 : 13].changeTime
            };
        case 20:
        case 21:
        case 24:
        case 25:
            return OpenVRInputState {
                .type = OpenVRInputType::BOOLEAN,
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
                .type = OpenVRInputType::BOOLEAN,
                .data = {.b = openXRInputStates[inputIndex - 10].data.b},
                .changeTime = openXRInputStates[inputIndex - 10].changeTime
            };
        case 34:
            return OpenVRInputState {
                .type = OpenVRInputType::BOOLEAN,
                .data = {.b = openXRInputStates[24].data.b},
                .changeTime = openXRInputStates[24].changeTime
            };
        // TODO: thumbrest
        default:
            return OpenVRInputState {
                .type = OpenVRInputType::NONE
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

LegacyInputState OculusTouch::getOpenVRLegacyInputState(int controllerIndex, const OpenVRInputState* openVRInputStates)
{
    // TODO: hysteresis for float -> boolean inputs (e.g. grip)
    return LegacyInputState {
        .touch = {
            .system = controllerIndex == 0 ? openVRInputStates[34].data.b : false,
            .menu = openVRInputStates[31 + controllerIndex * 2].data.b,
            .grip = openVRInputStates[16 + controllerIndex].data.f >= 0.06f,
            .dpadLeft = false,
            .dpadUp = false,
            .dpadRight = false,
            .dpadDown = false,
            .buttonA = openVRInputStates[27 + controllerIndex * 2].data.b,
            .axis0 = openVRInputStates[21 + controllerIndex * 4].data.b,
            .axis1 = openVRInputStates[13 + controllerIndex * 2].data.b,
            .axis2 = openVRInputStates[16 + controllerIndex].data.f >= 0.06f,
            .axis3 = false,
            .axis4 = false
        },
        .click = {
            .system = controllerIndex == 0 ? openVRInputStates[34].data.b : false,
            .menu = openVRInputStates[30 + controllerIndex * 2].data.b,
            .grip = openVRInputStates[16 + controllerIndex].data.f >= 0.25f,
            .dpadLeft = false,
            .dpadUp = false,
            .dpadRight = false,
            .dpadDown = false,
            .buttonA = openVRInputStates[26 + controllerIndex * 2].data.b,
            .axis0 = openVRInputStates[20 + controllerIndex * 4].data.b,
            .axis1 = openVRInputStates[12 + controllerIndex * 2].data.f >= 0.25f,
            .axis2 = openVRInputStates[16 + controllerIndex].data.f >= 0.25f,
            .axis3 = false,
            .axis4 = false
        },
        .axes = {
            {.x = openVRInputStates[18 + controllerIndex * 4].data.f, .y = openVRInputStates[19 + controllerIndex * 4].data.f},
            {.x = openVRInputStates[12 + controllerIndex * 2].data.f, .y = 0.0f},
            {.x = openVRInputStates[16 + controllerIndex].data.f, .y = 0.0f},
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
