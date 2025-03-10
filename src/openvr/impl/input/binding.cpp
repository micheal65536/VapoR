#include "binding.h"

#include "path_handle_registry.h"

#include <algorithm>

using namespace openvr::input;

// TODO: proper threshold for float -> boolean conversions

int Binding::findOpenVRInput(const std::string& basePath, vapor::OpenVRInputSubpath subpath, const vapor::OpenVRInputDescription* profileInputs, int profileInputsCount)
{
    for (int i = 0; i < profileInputsCount; i++)
    {
        if (profileInputs[i].path == basePath && profileInputs[i].subpath == subpath)
        {
            return i;
        }
    }
    return -1;
}

std::vector<int> ButtonBinding::bindToProfile(vapor::OpenVRInputType inputType, const std::string& basePath, const vapor::OpenVRInputDescription* profileInputs, int profileInputsCount)
{
    std::vector<int> indexes;
    if (input == Input::CLICK)
    {
        if (inputType == vapor::OpenVRInputType::BUTTON || inputType == vapor::OpenVRInputType::JOYSTICK || inputType == vapor::OpenVRInputType::TRACKPAD)
        {
            int index = findOpenVRInput(basePath, vapor::OpenVRInputSubpath::CLICK, profileInputs, profileInputsCount);
            if (index != -1)
            {
                indexes.push_back(index);
                inputSourceHandle = pathHandleRegistry.getHandle(basePath + "/click");
                convertFromFloat = false;
            }
        }
        else if (inputType == vapor::OpenVRInputType::TRIGGER)
        {
            int index = findOpenVRInput(basePath, vapor::OpenVRInputSubpath::VALUE, profileInputs, profileInputsCount);
            if (index != -1)
            {
                indexes.push_back(index);
                inputSourceHandle = pathHandleRegistry.getHandle(basePath + "/value");
                convertFromFloat = true;
            }
        }
    }
    else if (input == Input::TOUCH)
    {
        if (inputType == vapor::OpenVRInputType::BUTTON || inputType == vapor::OpenVRInputType::JOYSTICK || inputType == vapor::OpenVRInputType::TRACKPAD)
        {
            int index = findOpenVRInput(basePath, vapor::OpenVRInputSubpath::TOUCH, profileInputs, profileInputsCount);
            if (index != -1)
            {
                indexes.push_back(index);
                inputSourceHandle = pathHandleRegistry.getHandle(basePath + "/touch");
                convertFromFloat = false;
            }
        }
        else if (inputType == vapor::OpenVRInputType::TRIGGER)
        {
            int index = findOpenVRInput(basePath, vapor::OpenVRInputSubpath::TOUCH, profileInputs, profileInputsCount);
            if (index != -1)
            {
                indexes.push_back(index);
                inputSourceHandle = pathHandleRegistry.getHandle(basePath + "/touch");
                convertFromFloat = false;
            }
            else
            {
                index = findOpenVRInput(basePath, vapor::OpenVRInputSubpath::VALUE, profileInputs, profileInputsCount);
                if (index != -1)
                {
                    indexes.push_back(index);
                    inputSourceHandle = pathHandleRegistry.getHandle(basePath + "/value");
                    convertFromFloat = true;
                }
            }
        }
    }
    return indexes;
}

InputState ButtonBinding::getInitialState()
{
    return InputState {
        .type = InputType::DIGITAL,
        .data = {.digital = false},
        .inputSourceHandle = inputSourceHandle,
        .changeTime = 0
    };
}

InputState ButtonBinding::update(const std::vector<vapor::OpenVRInputState>& inputStates)
{
    if (convertFromFloat)
    {
        return InputState {
            .type = InputType::DIGITAL,
            .data = {.digital = inputStates[0].data.f > 0.5f},
            .inputSourceHandle = inputSourceHandle,
            .changeTime = inputStates[0].changeTime
        };
    }
    else
    {
        return InputState {
            .type = InputType::DIGITAL,
            .data = {.digital = inputStates[0].data.b},
            .inputSourceHandle = inputSourceHandle,
            .changeTime = inputStates[0].changeTime
        };
    }
}

std::vector<int> TriggerBinding::bindToProfile(vapor::OpenVRInputType inputType, const std::string& basePath, const vapor::OpenVRInputDescription* profileInputs, int profileInputsCount)
{
    std::vector<int> indexes;
    if (inputType == vapor::OpenVRInputType::TRIGGER)
    {
        if (input == Input::PULL)
        {
            int index = findOpenVRInput(basePath, vapor::OpenVRInputSubpath::VALUE, profileInputs, profileInputsCount);
            if (index != -1)
            {
                indexes.push_back(index);
                inputSourceHandle = pathHandleRegistry.getHandle(basePath + "/value");
            }
        }
        else if (input == Input::CLICK)
        {
            int index = findOpenVRInput(basePath, vapor::OpenVRInputSubpath::VALUE, profileInputs, profileInputsCount);
            if (index != -1)
            {
                indexes.push_back(index);
                inputSourceHandle = pathHandleRegistry.getHandle(basePath + "/value");
            }
        }
        else if (input == Input::TOUCH)
        {
            int index = findOpenVRInput(basePath, vapor::OpenVRInputSubpath::TOUCH, profileInputs, profileInputsCount);
            if (index != -1)
            {
                indexes.push_back(index);
                inputSourceHandle = pathHandleRegistry.getHandle(basePath + "/touch");
                convertFromFloat = false;
            }
            else
            {
                index = findOpenVRInput(basePath, vapor::OpenVRInputSubpath::VALUE, profileInputs, profileInputsCount);
                if (index != -1)
                {
                    indexes.push_back(index);
                    inputSourceHandle = pathHandleRegistry.getHandle(basePath + "/value");
                    convertFromFloat = true;
                }
            }
        }
    }
    return indexes;
}

InputState TriggerBinding::getInitialState()
{
    return InputState {
        .type = InputType::DIGITAL,
        .data = {.digital = false},
        .inputSourceHandle = inputSourceHandle,
        .changeTime = 0
    };
}

InputState TriggerBinding::update(const std::vector<vapor::OpenVRInputState>& inputStates)
{
    if (input == Input::PULL)
    {
        return InputState {
            .type = InputType::ANALOG,
            .data = {.analog = {inputStates[0].data.f, 0.0f, 0.0f}},
            .inputSourceHandle = inputSourceHandle,
            .changeTime = inputStates[0].changeTime
        };
    }
    else if (input == Input::CLICK)
    {
        return InputState {
            .type = InputType::DIGITAL,
            .data = {.digital = inputStates[0].data.f > 0.5f},
            .inputSourceHandle = inputSourceHandle,
            .changeTime = inputStates[0].changeTime
        };
    }
    else if (input == Input::TOUCH)
    {
        if (convertFromFloat)
        {
            return InputState {
                .type = InputType::DIGITAL,
                .data = {.digital = inputStates[0].data.f > 0.5f},
                .inputSourceHandle = inputSourceHandle,
                .changeTime = inputStates[0].changeTime
            };
        }
        else
        {
            return InputState {
                .type = InputType::DIGITAL,
                .data = {.digital = inputStates[0].data.b},
                .inputSourceHandle = inputSourceHandle,
                .changeTime = inputStates[0].changeTime
            };
        }
    }
}

std::vector<int> JoystickBinding::bindToProfile(vapor::OpenVRInputType inputType, const std::string& basePath, const vapor::OpenVRInputDescription* profileInputs, int profileInputsCount)
{
    std::vector<int> indexes;
    if (inputType == vapor::OpenVRInputType::JOYSTICK)
    {
        if (input == Input::POSITION)
        {
            int xIndex = findOpenVRInput(basePath, vapor::OpenVRInputSubpath::X, profileInputs, profileInputsCount);
            int yIndex = findOpenVRInput(basePath, vapor::OpenVRInputSubpath::Y, profileInputs, profileInputsCount);
            if (xIndex != -1 && yIndex != -1)
            {
                indexes.push_back(xIndex);
                indexes.push_back(yIndex);
                inputSourceHandle = pathHandleRegistry.getHandle(basePath + "/x");
            }
        }
        else if (input == Input::CLICK)
        {
            int index = findOpenVRInput(basePath, vapor::OpenVRInputSubpath::CLICK, profileInputs, profileInputsCount);
            if (index != -1)
            {
                indexes.push_back(index);
                inputSourceHandle = pathHandleRegistry.getHandle(basePath + "/click");
            }
        }
        else if (input == Input::TOUCH)
        {
            int index = findOpenVRInput(basePath, vapor::OpenVRInputSubpath::TOUCH, profileInputs, profileInputsCount);
            if (index != -1)
            {
                indexes.push_back(index);
                inputSourceHandle = pathHandleRegistry.getHandle(basePath + "/touch");
            }
        }
    }
    return indexes;
}

InputState JoystickBinding::getInitialState()
{
    if (input == Input::POSITION)
    {
        return InputState {
            .type = InputType::ANALOG,
            .data = {.analog = {0.0f, 0.0f, 0.0f}},
            .inputSourceHandle = inputSourceHandle,
            .changeTime = 0
        };
    }
    else if (input == Input::CLICK || input == Input::TOUCH)
    {
        return InputState {
            .type = InputType::DIGITAL,
            .data = {.digital = false},
            .inputSourceHandle = inputSourceHandle,
            .changeTime = 0
        };
    }
}

InputState JoystickBinding::update(const std::vector<vapor::OpenVRInputState>& inputStates)
{
    if (input == Input::POSITION)
    {
        return InputState {
            .type = InputType::ANALOG,
            .data = {.analog = {inputStates[0].data.f, inputStates[1].data.f, 0.0f}},
            .inputSourceHandle = inputSourceHandle,
            .changeTime = std::max(inputStates[0].changeTime, inputStates[1].changeTime)
        };
    }
    else if (input == Input::CLICK || input == Input::TOUCH)
    {
        return InputState {
            .type = InputType::DIGITAL,
            .data = {.digital = inputStates[0].data.b},
            .inputSourceHandle = inputSourceHandle,
            .changeTime = inputStates[0].changeTime
        };
    }
}

std::vector<int> DpadBinding::bindToProfile(vapor::OpenVRInputType inputType, const std::string& basePath, const vapor::OpenVRInputDescription* profileInputs, int profileInputsCount)
{
    std::vector<int> indexes;
    if (inputType == vapor::OpenVRInputType::JOYSTICK)
    {
        int xIndex = findOpenVRInput(basePath, vapor::OpenVRInputSubpath::X, profileInputs, profileInputsCount);
        int yIndex = findOpenVRInput(basePath, vapor::OpenVRInputSubpath::Y, profileInputs, profileInputsCount);
        int clickIndex = findOpenVRInput(basePath, vapor::OpenVRInputSubpath::CLICK, profileInputs, profileInputsCount);
        int touchIndex = findOpenVRInput(basePath, vapor::OpenVRInputSubpath::TOUCH, profileInputs, profileInputsCount);
        if (xIndex != -1 && yIndex != -1 && (!click || clickIndex != -1))
        {
            indexes.push_back(xIndex);
            indexes.push_back(yIndex);
            if (clickIndex != -1)
            {
                indexes.push_back(clickIndex);
            }
            if (touchIndex != -1)
            {
                indexes.push_back(touchIndex);
            }
            positionInputSourceHandle = pathHandleRegistry.getHandle(basePath + "/y");
            if (click)
            {
                clickInputSourceHandle = pathHandleRegistry.getHandle(basePath + "/click");
            }
        }
    }
    return indexes;
}

InputState DpadBinding::getInitialState()
{
    return InputState {
        .type = InputType::DIGITAL,
        .data = {.digital = false},
        .inputSourceHandle = click ? clickInputSourceHandle : positionInputSourceHandle,
        .changeTime = 0
    };
}

InputState DpadBinding::update(const std::vector<vapor::OpenVRInputState>& inputStates)
{
    if (click)
    {
        if (!inputStates[2].data.b)
        {
            return InputState {
                .type = InputType::DIGITAL,
                .data = {.digital = false},
                .inputSourceHandle = clickInputSourceHandle,
                .changeTime = inputStates[2].changeTime
            };
        }
    }

    long positionChangeTime = std::max(inputStates[0].changeTime, inputStates[1].changeTime);
    long changeTime = click ? (positionChangeTime > inputStates[2].changeTime ? positionChangeTime : inputStates[2].changeTime) : positionChangeTime;
    uint64_t inputSourceHandle = click ? (positionChangeTime > inputStates[2].changeTime ? positionInputSourceHandle : clickInputSourceHandle) : positionInputSourceHandle;
    switch (input)
    {
        case Input::NORTH:
            return InputState {
                .type = InputType::DIGITAL,
                .data = {.digital = inputStates[1].data.f > 0.5f},
                .inputSourceHandle = inputSourceHandle,
                .changeTime = changeTime
            };
        case Input::EAST:
            return InputState {
                .type = InputType::DIGITAL,
                .data = {.digital = inputStates[0].data.f > 0.5f},
                .inputSourceHandle = inputSourceHandle,
                .changeTime = changeTime
            };
        case Input::SOUTH:
            return InputState {
                .type = InputType::DIGITAL,
                .data = {.digital = inputStates[1].data.f < -0.5f},
                .inputSourceHandle = inputSourceHandle,
                .changeTime = changeTime
            };
        case Input::WEST:
            return InputState {
                .type = InputType::DIGITAL,
                .data = {.digital = inputStates[0].data.f < -0.5f},
                .inputSourceHandle = inputSourceHandle,
                .changeTime = changeTime
            };
        case Input::CENTER:
            return InputState {
                .type = InputType::DIGITAL,
                .data = {.digital = inputStates[0].data.f >= -0.5f && inputStates[0].data.f <= 0.5f && inputStates[1].data.f >= -0.5f && inputStates[1].data.f <= 0.5f},
                .inputSourceHandle = inputSourceHandle,
                .changeTime = changeTime
            };
    }
}
