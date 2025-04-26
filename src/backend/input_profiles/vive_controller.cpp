#include "vive_controller.h"

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
    {.path = "/user/hand/left/input/trigger/click", .type = OpenXRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/trigger/value", .type = OpenXRInputType::FLOAT},
    {.path = "/user/hand/right/input/trigger/click", .type = OpenXRInputType::BOOLEAN},
    {.path = "/user/hand/left/input/squeeze/click", .type = OpenXRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/squeeze/click", .type = OpenXRInputType::BOOLEAN},
    {.path = "/user/hand/left/input/trackpad", .type = OpenXRInputType::VECTOR2},
    {.path = "/user/hand/left/input/trackpad/click", .type = OpenXRInputType::BOOLEAN},
    {.path = "/user/hand/left/input/trackpad/touch", .type = OpenXRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/trackpad", .type = OpenXRInputType::VECTOR2},
    {.path = "/user/hand/right/input/trackpad/click", .type = OpenXRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/trackpad/touch", .type = OpenXRInputType::BOOLEAN},
    {.path = "/user/hand/left/input/menu/click", .type = OpenXRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/menu/click", .type = OpenXRInputType::BOOLEAN},
    {.path = "/user/hand/left/input/system/click", .type = OpenXRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/system/click", .type = OpenXRInputType::BOOLEAN},
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
    {.path = "/user/hand/left/pose/grip", .type = OpenVRInputType::POSE},
    {.path = "/user/hand/right/pose/grip", .type = OpenVRInputType::POSE},
    {.path = "/user/hand/left/pose/tip", .type = OpenVRInputType::POSE},
    {.path = "/user/hand/right/pose/tip", .type = OpenVRInputType::POSE},
    {.path = "/user/hand/left/pose/front", .type = OpenVRInputType::POSE},
    {.path = "/user/hand/right/pose/front", .type = OpenVRInputType::POSE},
    {.path = "/user/hand/left/pose/gdc2015", .type = OpenVRInputType::POSE},
    {.path = "/user/hand/right/pose/gdc2015", .type = OpenVRInputType::POSE},
    {.path = "/user/hand/left/pose/openxr_handmodel", .type = OpenVRInputType::POSE},
    {.path = "/user/hand/right/pose/openxr_handmodel", .type = OpenVRInputType::POSE},
    {.path = "/user/hand/left/pose/openxr_handmodel_r", .type = OpenVRInputType::POSE},
    {.path = "/user/hand/right/pose/openxr_handmodel_r", .type = OpenVRInputType::POSE},
    {.path = "/user/hand/left/input/trigger/value", .type = OpenVRInputType::FLOAT},
    {.path = "/user/hand/left/input/trigger/click", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/trigger/value", .type = OpenVRInputType::FLOAT},
    {.path = "/user/hand/right/input/trigger/click", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/left/input/grip/click", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/grip/click", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/left/input/trackpad/x", .type = OpenVRInputType::FLOAT},
    {.path = "/user/hand/left/input/trackpad/y", .type = OpenVRInputType::FLOAT},
    {.path = "/user/hand/left/input/trackpad/click", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/left/input/trackpad/touch", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/trackpad/x", .type = OpenVRInputType::FLOAT},
    {.path = "/user/hand/right/input/trackpad/y", .type = OpenVRInputType::FLOAT},
    {.path = "/user/hand/right/input/trackpad/click", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/trackpad/touch", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/left/input/application_menu/click", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/application_menu/click", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/left/input/system/click", .type = OpenVRInputType::BOOLEAN},
    {.path = "/user/hand/right/input/system/click", .type = OpenVRInputType::BOOLEAN},
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
    {.path = "/user/hand/left/pose/grip", .type = OpenVRProfileInputType::POSE},
    {.path = "/user/hand/right/pose/grip", .type = OpenVRProfileInputType::POSE},
    {.path = "/user/hand/left/pose/tip", .type = OpenVRProfileInputType::POSE},
    {.path = "/user/hand/right/pose/tip", .type = OpenVRProfileInputType::POSE},
    {.path = "/user/hand/left/pose/front", .type = OpenVRProfileInputType::POSE},
    {.path = "/user/hand/right/pose/front", .type = OpenVRProfileInputType::POSE},
    {.path = "/user/hand/left/pose/gdc2015", .type = OpenVRProfileInputType::POSE},
    {.path = "/user/hand/right/pose/gdc2015", .type = OpenVRProfileInputType::POSE},
    {.path = "/user/hand/left/pose/openxr_handmodel", .type = OpenVRProfileInputType::POSE},
    {.path = "/user/hand/right/pose/openxr_handmodel", .type = OpenVRProfileInputType::POSE},
    {.path = "/user/hand/left/pose/openxr_handmodel_r", .type = OpenVRProfileInputType::POSE},
    {.path = "/user/hand/right/pose/openxr_handmodel_r", .type = OpenVRProfileInputType::POSE},
    {.path = "/user/hand/left/input/trigger", .type = OpenVRProfileInputType::TRIGGER, .click = true, .value = true},
    {.path = "/user/hand/right/input/trigger", .type = OpenVRProfileInputType::TRIGGER, .click = true, .value = true},
    {.path = "/user/hand/left/input/grip", .type = OpenVRProfileInputType::BUTTON, .click = true},
    {.path = "/user/hand/right/input/grip", .type = OpenVRProfileInputType::BUTTON, .click = true},
    {.path = "/user/hand/left/input/trackpad", .type = OpenVRProfileInputType::TRACKPAD, .click = true, .touch = true},
    {.path = "/user/hand/right/input/trackpad", .type = OpenVRProfileInputType::TRACKPAD, .click = true, .touch = true},
    {.path = "/user/hand/left/input/application_menu", .type = OpenVRProfileInputType::BUTTON, .click = true},
    {.path = "/user/hand/right/input/application_menu", .type = OpenVRProfileInputType::BUTTON, .click = true},
    {.path = "/user/hand/left/input/system", .type = OpenVRProfileInputType::BUTTON, .click = true},
    {.path = "/user/hand/right/input/system", .type = OpenVRProfileInputType::BUTTON, .click = true},
    {.path = "/user/hand/left/input/skeleton", .type = OpenVRProfileInputType::SKELETON},
    {.path = "/user/hand/right/input/skeleton", .type = OpenVRProfileInputType::SKELETON},
    {.path = "/user/hand/left/output/haptic", .type = OpenVRProfileInputType::HAPTIC},
    {.path = "/user/hand/right/output/haptic", .type = OpenVRProfileInputType::HAPTIC}
};

std::string ViveController::getOpenXRInteractionProfileName()
{
    return "/interaction_profiles/htc/vive_controller";
}

int ViveController::getOpenXRInputsCount()
{
    return openXRInputs.size();
}

const OpenXRInputDescription* ViveController::getOpenXRInputs()
{
    return openXRInputs.data();
}

std::string ViveController::getOpenVRProfileName()
{
    return "vive_controller";
}

int ViveController::getOpenVRInputsCount()
{
    return openVRInputs.size();
}

const OpenVRInputDescription* ViveController::getOpenVRInputs()
{
    return openVRInputs.data();
}

int ViveController::getOpenVRProfileInputsCount()
{
    return openVRProfileInputs.size();
}

const OpenVRProfileInputDescription* ViveController::getOpenVRProfileInputs()
{
    return openVRProfileInputs.data();
}

LegacyInputDescription ViveController::getOpenVRLegacyInputDescription()
{
    return LegacyInputDescription {
        .supportedButtons {
            .system = true, .menu = true,
            .grip = true,
            .dpadLeft = false, .dpadUp = false, .dpadRight = false, .dpadDown = false,
            .buttonA = false,
            .axis0 = true, .axis1 = true, .axis2 = false, .axis3 = false, .axis4 = false
        },
        .axisTypes {
            LegacyInputDescription::AxisType::TRACKPAD, LegacyInputDescription::AxisType::TRIGGER, LegacyInputDescription::AxisType::NONE, LegacyInputDescription::AxisType::NONE, LegacyInputDescription::AxisType::NONE
        }
    };
}

OpenVRInputState ViveController::getOpenVRInputState(int inputIndex, const OpenXRInputState* openXRInputStates)
{
    switch (inputIndex)
    {
        case 0:
        case 1:
        case 12:
        case 13:
            return OpenVRInputState {
                .type = OpenVRInputType::POSE,
                .data = {.pose = {
                    .local = openXRInputStates[(inputIndex % 2) + 2].data.pose.local,
                    .localFloor = openXRInputStates[(inputIndex % 2) + 2].data.pose.localFloor,
                    .localNextFrame = openXRInputStates[(inputIndex % 2) + 2].data.pose.localNextFrame,
                    .localFloorNextFrame = openXRInputStates[(inputIndex % 2) + 2].data.pose.localFloorNextFrame,
                    .offsetMatrix = {
                        {1.0f, 0.0f, 0.0f, 0.0f},
                        {0.0f, std::cos(5.037f * std::numbers::pi / 180.0f), std::sin(5.037f * std::numbers::pi / 180.0f), 0.015f * std::cos(5.037f * std::numbers::pi / 180.0f) - 0.097f * std::sin(5.037f * std::numbers::pi / 180.0f)},
                        {0.0f, -std::sin(5.037f * std::numbers::pi / 180.0f), std::cos(5.037f * std::numbers::pi / 180.0f), -0.015f * std::sin(5.037f * std::numbers::pi / 180.0f) - 0.097f * std::cos(5.037f * std::numbers::pi / 180.0f)}
                    }
                }},
                .changeTime = openXRInputStates[(inputIndex % 2) + 2].changeTime
            };
        case 2:
        case 3:
            return OpenVRInputState {
                .type = OpenVRInputType::POSE,
                .data = {.pose = {
                    .local = openXRInputStates[(inputIndex % 2) + 2].data.pose.local,
                    .localFloor = openXRInputStates[(inputIndex % 2) + 2].data.pose.localFloor,
                    .localNextFrame = openXRInputStates[(inputIndex % 2) + 2].data.pose.localNextFrame,
                    .localFloorNextFrame = openXRInputStates[(inputIndex % 2) + 2].data.pose.localFloorNextFrame,
                    .offsetMatrix = {
                        {1.0f, 0.0f, 0.0f, 0.0f},
                        {0.0f, std::cos(4.216f * std::numbers::pi / 180.0f), -std::sin(4.216f * std::numbers::pi / 180.0f), 0.001f * std::cos(5.037f * std::numbers::pi / 180.0f) + 0.077f * std::sin(5.037f * std::numbers::pi / 180.0f)},
                        {0.0f, -std::sin(4.216f * std::numbers::pi / 180.0f), -std::cos(4.216f * std::numbers::pi / 180.0f), -0.001f * std::sin(5.037f * std::numbers::pi / 180.0f) + 0.077f * std::cos(5.037f * std::numbers::pi / 180.0f)}
                    }
                }},
                .changeTime = openXRInputStates[(inputIndex % 2) + 2].changeTime
            };
        case 4:
        case 5:
            return OpenVRInputState {
                .type = OpenVRInputType::POSE,
                .data = {.pose = {
                    .local = openXRInputStates[(inputIndex % 2) + 2].data.pose.local,
                    .localFloor = openXRInputStates[(inputIndex % 2) + 2].data.pose.localFloor,
                    .localNextFrame = openXRInputStates[(inputIndex % 2) + 2].data.pose.localNextFrame,
                    .localFloorNextFrame = openXRInputStates[(inputIndex % 2) + 2].data.pose.localFloorNextFrame,
                    .offsetMatrix = {
                        {1.0f, 0.0f, 0.0f, 0.0f},
                        {0.0f, 1.0f, 0.0f, 0.018f * std::cos(5.037f * std::numbers::pi / 180.0f)},
                        {0.0f, 0.0f, 1.0f, -0.018f * std::sin(5.037f * std::numbers::pi / 180.0f)}
                    }
                }},
                .changeTime = openXRInputStates[(inputIndex % 2) + 2].changeTime
            };
        case 6:
        case 7:
            return OpenVRInputState {
                .type = OpenVRInputType::POSE,
                .data = {.pose = openXRInputStates[(inputIndex % 2) + 2].data.pose},
                .changeTime = openXRInputStates[(inputIndex % 2) + 2].changeTime
            };
        case 8:
        case 9:
            return OpenVRInputState {
                .type = OpenVRInputType::POSE,
                .data = {.pose = {
                    .local = openXRInputStates[(inputIndex % 2) + 2].data.pose.local,
                    .localFloor = openXRInputStates[(inputIndex % 2) + 2].data.pose.localFloor,
                    .localNextFrame = openXRInputStates[(inputIndex % 2) + 2].data.pose.localNextFrame,
                    .localFloorNextFrame = openXRInputStates[(inputIndex % 2) + 2].data.pose.localFloorNextFrame,
                    .offsetMatrix = {
                        {1.0f, 0.0f, 0.0f, 0.0f},
                        {0.0f, std::cos(3.755f * std::numbers::pi / 180.0f), std::sin(3.755f * std::numbers::pi / 180.0f), 0.005f * std::cos(5.037f * std::numbers::pi / 180.0f) - 0.104f * std::sin(5.037f * std::numbers::pi / 180.0f)},
                        {0.0f, -std::sin(3.755f * std::numbers::pi / 180.0f), std::cos(3.755f * std::numbers::pi / 180.0f), -0.005f * std::sin(5.037f * std::numbers::pi / 180.0f) - 0.104f * std::cos(5.037f * std::numbers::pi / 180.0f)}
                    }
                }},
                .changeTime = openXRInputStates[(inputIndex % 2) + 2].changeTime
            };
        case 10:
        case 11:
            return OpenVRInputState {
                .type = OpenVRInputType::POSE,
                .data = {.pose = {
                    .local = openXRInputStates[(inputIndex % 2) + 2].data.pose.local,
                    .localFloor = openXRInputStates[(inputIndex % 2) + 2].data.pose.localFloor,
                    .localNextFrame = openXRInputStates[(inputIndex % 2) + 2].data.pose.localNextFrame,
                    .localFloorNextFrame = openXRInputStates[(inputIndex % 2) + 2].data.pose.localFloorNextFrame,
                    .offsetMatrix = {
                        {1.0f, 0.0f, 0.0f, 0.0f},
                        {0.0f, std::cos(60.037f * std::numbers::pi / 180.0f), std::sin(60.037f * std::numbers::pi / 180.0f), 0.005f * std::cos(5.037f * std::numbers::pi / 180.0f) - 0.104f * std::sin(5.037f * std::numbers::pi / 180.0f)},
                        {0.0f, -std::sin(60.037f * std::numbers::pi / 180.0f), std::cos(60.037f * std::numbers::pi / 180.0f), -0.005f * std::sin(5.037f * std::numbers::pi / 180.0f) - 0.104f * std::cos(5.037f * std::numbers::pi / 180.0f)}
                    }
                }},
                .changeTime = openXRInputStates[(inputIndex % 2) + 2].changeTime
            };
        case 14:
        case 15:
        case 16:
        case 17:
            return OpenVRInputState {
                .type = OpenVRInputType::POSE,
                .data = {.pose = {
                    .local = openXRInputStates[(inputIndex % 2) + 2].data.pose.local,
                    .localFloor = openXRInputStates[(inputIndex % 2) + 2].data.pose.localFloor,
                    .localNextFrame = openXRInputStates[(inputIndex % 2) + 2].data.pose.localNextFrame,
                    .localFloorNextFrame = openXRInputStates[(inputIndex % 2) + 2].data.pose.localFloorNextFrame,
                    .offsetMatrix = {
                        {1.0f, 0.0f, 0.0f, inputIndex < 16 ? -0.02f : 0.02f},
                        {0.0f, std::cos(3.755f * std::numbers::pi / 180.0f), std::sin(3.755f * std::numbers::pi / 180.0f), -0.0135f * std::cos(5.037f * std::numbers::pi / 180.0f)},
                        {0.0f, -std::sin(3.755f * std::numbers::pi / 180.0f), std::cos(3.755f * std::numbers::pi / 180.0f), 0.0135f * std::sin(5.037f * std::numbers::pi / 180.0f)}
                    }
                }},
                .changeTime = openXRInputStates[(inputIndex % 2) + 2].changeTime
            };
        case 18:
        case 20:
            return OpenVRInputState {
                .type = OpenVRInputType::FLOAT,
                .data = {.f = openXRInputStates[inputIndex - 14].data.f},
                .changeTime = openXRInputStates[inputIndex - 14].changeTime
            };
        case 19:
        case 21:
        case 22:
        case 23:
            return OpenVRInputState {
                .type = OpenVRInputType::BOOLEAN,
                .data = {.b = openXRInputStates[inputIndex - 14].data.b},
                .changeTime = openXRInputStates[inputIndex - 14].changeTime
            };
        case 24:
        case 28:
            return OpenVRInputState {
                .type = OpenVRInputType::FLOAT,
                .data = {.f = openXRInputStates[inputIndex == 24 ? 10 : 13].data.vec2.x},
                .changeTime = openXRInputStates[inputIndex == 24 ? 10 : 13].changeTime
            };
        case 25:
        case 29:
            return OpenVRInputState {
                .type = OpenVRInputType::FLOAT,
                .data = {.f = openXRInputStates[inputIndex == 25 ? 10 : 13].data.vec2.y},
                .changeTime = openXRInputStates[inputIndex == 25 ? 10 : 13].changeTime
            };
        case 26:
        case 27:
        case 30:
        case 31:
            return OpenVRInputState {
                .type = OpenVRInputType::BOOLEAN,
                .data = {.b = openXRInputStates[inputIndex < 30 ? (inputIndex - 15) : (inputIndex - 16)].data.b},
                .changeTime = openXRInputStates[inputIndex < 30 ? (inputIndex - 15) : (inputIndex - 16)].changeTime
            };
        case 32:
        case 33:
        case 34:
        case 35:
            return OpenVRInputState {
                .type = OpenVRInputType::BOOLEAN,
                .data = {.b = openXRInputStates[inputIndex - 16].data.b},
                .changeTime = openXRInputStates[inputIndex - 16].changeTime
            };
        default:
            return OpenVRInputState {
                .type = OpenVRInputType::NONE
            };
    }
}

OpenVRInputState ViveController::getOpenVRControllerPose(int controllerIndex, const OpenVRInputState* openVRInputStates)
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

LegacyInputState ViveController::getOpenVRLegacyInputState(int controllerIndex, const OpenVRInputState* openVRInputStates)
{
    // TODO: hysteresis for float -> boolean inputs (trigger)
    return LegacyInputState {
        .touch = {
            .system = openVRInputStates[34 + controllerIndex].data.b,
            .menu = openVRInputStates[32 + controllerIndex].data.b,
            .grip = openVRInputStates[22 + controllerIndex].data.b,
            .dpadLeft = false,
            .dpadUp = false,
            .dpadRight = false,
            .dpadDown = false,
            .buttonA = false,
            .axis0 = openVRInputStates[27 + controllerIndex * 4].data.b,
            .axis1 = openVRInputStates[18 + controllerIndex * 2].data.f >= 0.06f,
            .axis2 = false,
            .axis3 = false,
            .axis4 = false
        },
        .click = {
            .system = openVRInputStates[34 + controllerIndex].data.b,
            .menu = openVRInputStates[32 + controllerIndex].data.b,
            .grip = openVRInputStates[22 + controllerIndex].data.b,
            .dpadLeft = false,
            .dpadUp = false,
            .dpadRight = false,
            .dpadDown = false,
            .buttonA = false,
            .axis0 = openVRInputStates[26 + controllerIndex * 4].data.b,
            .axis1 = openVRInputStates[18 + controllerIndex * 2].data.f >= 0.25f,
            .axis2 = false,
            .axis3 = false,
            .axis4 = false
        },
        .axes = {
            {.x = openVRInputStates[24 + controllerIndex * 4].data.f, .y = openVRInputStates[25 + controllerIndex * 4].data.f},
            {.x = openVRInputStates[18 + controllerIndex * 2].data.f, .y = 0.0f},
            {.x = 0.0f, .y = 0.0f},
            {.x = 0.0f, .y = 0.0f},
            {.x = 0.0f, .y = 0.0f}
        }
    };
}

int ViveController::getOpenXRHapticActionIndex(int openVRInputIndex)
{
    switch (openVRInputIndex)
    {
        case 38:
            return 20;
        case 39:
            return 21;
    }
}

int ViveController::getOpenXRHapticActionIndexForLegacyInput(int controllerIndex)
{
    if (controllerIndex == 0)
    {
        return 20;
    }
    else if (controllerIndex == 1)
    {
        return 21;
    }
}
