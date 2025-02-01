#include "oculus_touch.h"

#include <vector>

using namespace vapor;
using namespace vapor::input_profiles;

std::string OculusTouch::getOpenXRInteractionProfileName()
{
    return "/interaction_profiles/oculus/touch_controller";
}

static const std::vector<OpenXRInputDescription> openXRInputs = (std::vector<OpenXRInputDescription>) {
    {.path = "/user/hand/left/input/aim/pose", .type = InputType::POSE},
    {.path = "/user/hand/right/input/aim/pose", .type = InputType::POSE},
    {.path = "/user/hand/left/input/grip/pose", .type = InputType::POSE},
    {.path = "/user/hand/right/input/grip/pose", .type = InputType::POSE},
    {.path = "/user/hand/left/input/trigger/value", .type = InputType::FLOAT},
    {.path = "/user/hand/right/input/trigger/value", .type = InputType::FLOAT},
    {.path = "/user/hand/left/input/squeeze/value", .type = InputType::FLOAT},
    {.path = "/user/hand/right/input/squeeze/value", .type = InputType::FLOAT},
    {.path = "/user/hand/left/input/thumbstick", .type = InputType::VECTOR2},
    {.path = "/user/hand/left/input/thumbstick/click", .type = InputType::BOOLEAN},
    {.path = "/user/hand/right/input/thumbstick", .type = InputType::VECTOR2},
    {.path = "/user/hand/right/input/thumbstick/click", .type = InputType::BOOLEAN},
    {.path = "/user/hand/left/input/x/click", .type = InputType::BOOLEAN},
    {.path = "/user/hand/left/input/y/click", .type = InputType::BOOLEAN},
    {.path = "/user/hand/right/input/a/click", .type = InputType::BOOLEAN},
    {.path = "/user/hand/right/input/b/click", .type = InputType::BOOLEAN},
    {.path = "/user/hand/left/input/menu/click", .type = InputType::BOOLEAN},
    {.path = "/user/hand/left/output/haptic", .type = InputType::HAPTIC},
    {.path = "/user/hand/right/output/haptic", .type = InputType::HAPTIC}
};

static const std::vector<OpenVRInputDescription> openVRInputs = (std::vector<OpenVRInputDescription>) {
    {.path = "/user/hand/left/pose/raw", .type = InputType::POSE},
    {.path = "/user/hand/right/pose/raw", .type = InputType::POSE},
    {.path = "/user/hand/left/pose/base", .type = InputType::POSE},
    {.path = "/user/hand/right/pose/base", .type = InputType::POSE},
    {.path = "/user/hand/left/pose/handgrip", .type = InputType::POSE},
    {.path = "/user/hand/right/pose/handgrip", .type = InputType::POSE},
    {.path = "/user/hand/left/pose/tip", .type = InputType::POSE},
    {.path = "/user/hand/right/pose/tip", .type = InputType::POSE},
    {.path = "/user/hand/left/input/trigger", .type = InputType::FLOAT, .touch = true},
    {.path = "/user/hand/right/input/trigger", .type = InputType::FLOAT, .touch = true},
    {.path = "/user/hand/left/input/grip", .type = InputType::FLOAT, .touch = true},
    {.path = "/user/hand/right/input/grip", .type = InputType::FLOAT, .touch = true},
    {.path = "/user/hand/left/input/joystick", .type = InputType::VECTOR2, .click = true, .touch = true},
    {.path = "/user/hand/right/input/joystick", .type = InputType::VECTOR2, .click = true, .touch = true},
    {.path = "/user/hand/left/input/x", .type = InputType::BOOLEAN, .touch = true},
    {.path = "/user/hand/right/input/a", .type = InputType::BOOLEAN, .touch = true},
    {.path = "/user/hand/left/input/y", .type = InputType::BOOLEAN, .touch = true},
    {.path = "/user/hand/right/input/b", .type = InputType::BOOLEAN, .touch = true},
    {.path = "/user/hand/left/input/system", .type = InputType::BOOLEAN, .touch = true},
    {.path = "/user/hand/left/input/thumbrest", .type = InputType::NONE, .touch = true},
    {.path = "/user/hand/right/input/thumbrest", .type = InputType::NONE, .touch = true},
    {.path = "/user/hand/left/output/haptic", .type = InputType::HAPTIC},
    {.path = "/user/hand/right/output/haptic", .type = InputType::HAPTIC}
};

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

InputState OculusTouch::getOpenVRInputState(int inputIndex, const InputState* openXRInputStates)
{
    // TODO
    return InputState {
        .type = openVRInputs[inputIndex].type,
        .data = { .b = false }
    };
}

InputState OculusTouch::getOpenVRControllerPose(int controllerIndex, const InputState* openXRInputStates)
{
    if (controllerIndex == 0)
    {
        return openXRInputStates[2];
    }
    else if (controllerIndex == 1)
    {
        return openXRInputStates[3];
    }
}

LegacyInputState OculusTouch::getOpenVRLegacyInputState(int controllerIndex, const InputState* openXRInputStates)
{
    return LegacyInputState {
        // TODO: proper touch for inputs that support it (missing from OpenXR set)
        // TODO: proper threshold for float -> boolean inputs (e.g. grip) (missing from OpenXR side)
        .touch = {
            .system = controllerIndex == 0 ? openXRInputStates[16].data.b : false,
            .menu = openXRInputStates[13 + controllerIndex * 2].data.b,
            .grip = openXRInputStates[6 + controllerIndex].data.f > 0.5f,
            .dpadLeft = false,
            .dpadUp = false,
            .dpadRight = false,
            .dpadDown = false,
            .buttonA = openXRInputStates[12 + controllerIndex * 2].data.b,
            .axis0 = openXRInputStates[9 + controllerIndex * 2].data.b,
            .axis1 = openXRInputStates[4 + controllerIndex].data.f > 0.5f,
            .axis2 = openXRInputStates[6 + controllerIndex].data.f > 0.5f,
            .axis3 = false,
            .axis4 = false
        },
        .click = {
            .system = controllerIndex == 0 ? openXRInputStates[16].data.b : false,
            .menu = openXRInputStates[13 + controllerIndex * 2].data.b,
            .grip = openXRInputStates[6 + controllerIndex].data.f > 0.5f,
            .dpadLeft = false,
            .dpadUp = false,
            .dpadRight = false,
            .dpadDown = false,
            .buttonA = openXRInputStates[12 + controllerIndex * 2].data.b,
            .axis0 = openXRInputStates[9 + controllerIndex * 2].data.b,
            .axis1 = openXRInputStates[4 + controllerIndex].data.f > 0.5f,
            .axis2 = openXRInputStates[6 + controllerIndex].data.f > 0.5f,
            .axis3 = false,
            .axis4 = false
        },
        .axes = {
            {.x = openXRInputStates[8 + controllerIndex * 2].data.vec2.x, .y = openXRInputStates[8 + controllerIndex * 2].data.vec2.y},
            {.x = openXRInputStates[4 + controllerIndex].data.f, .y = 0.0f},
            {.x = openXRInputStates[6 + controllerIndex].data.f, .y = 0.0f},
            {.x = 0.0f, .y = 0.0f},
            {.x = 0.0f, .y = 0.0f}
        }
    };
}

int OculusTouch::getOpenXRHapticActionIndex(int openVRInputIndex)
{
    switch (openVRInputIndex)
    {
        case 21:
            return 17;
        case 22:
            return 18;
    }
}

int OculusTouch::getOpenXRHapticActionIndexForLegacyInput(int controllerIndex)
{
    if (controllerIndex == 0)
    {
        return 17;
    }
    else if (controllerIndex == 1)
    {
        return 18;
    }
}
