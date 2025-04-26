#include "mode.h"

#include <algorithm>
#include <cmath>

using namespace openvr::input;

const Mode::Hysteresis::Thresholds Mode::Hysteresis::Thresholds::CLICK_DEFAULT = {.on = 0.25f, .off = 0.2f};
const Mode::Hysteresis::Thresholds Mode::Hysteresis::Thresholds::TOUCH_DEFAULT = {.on = 0.06f, .off = 0.04f};
const Mode::Hysteresis::Thresholds Mode::Hysteresis::Thresholds::STICKY_DEFAULT = {.on = 0.4f, .off = 0.3f};

static int findComponent(const std::string& subpath, vapor::OpenVRInputType type, const std::vector<Mode::ComponentDescription>& availableComponents)
{
    for (int i = 0; i < availableComponents.size(); i++)
    {
        if (availableComponents[i].subpath == subpath && (type == vapor::OpenVRInputType::NONE || availableComponents[i].type == type))
        {
            return i;
        }
    }
    return -1;
}

static Mode::ForceInput readForceInput(const nlohmann::json::object_t& parameters)
{
    if (parameters.contains("force_input"))
    {
        const std::string& forceInputString = parameters.at("force_input");
        if (forceInputString == "click")
        {
            return Mode::ForceInput::CLICK;
        }
        else if (forceInputString == "touch")
        {
            return Mode::ForceInput::TOUCH;
        }
        else if (forceInputString == "position")
        {
            return Mode::ForceInput::POSITION;
        }
        else if (forceInputString == "force")
        {
            return Mode::ForceInput::FORCE;
        }
    }
    return Mode::ForceInput::NONE;
}

static void readThresholds(const nlohmann::json::object_t& parameters, const std::string& prefix, std::optional<float>& activateThreshold, std::optional<float>& deactivateThreshold)
{
    if (parameters.contains(prefix + "_activate_threshold"))
    {
        activateThreshold = parameters.at(prefix + "_activate_threshold");
    }
    if (parameters.contains(prefix + "_deactivate_threshold"))
    {
        deactivateThreshold = parameters.at(prefix + "_deactivate_threshold");
    }
}

//

bool Mode::ClickFilter::tryGrab(Mode::ClickFilter::Source source, Mode::ClickFilter::DefaultThresholdsType defaultThresholdsType, std::optional<float> activateThresholdOverride, std::optional<float> deactivateThresholdOverride, const std::vector<ComponentDescription>& availableComponents, std::vector<int>& grabbedComponents)
{
    convertFromScalar = false;
    convertFromVector = false;

    Hysteresis::Thresholds thresholds;
    switch (defaultThresholdsType)
    {
        case DefaultThresholdsType::CLICK:
            thresholds = Hysteresis::Thresholds::CLICK_DEFAULT;
            break;
        case DefaultThresholdsType::TOUCH:
            thresholds = Hysteresis::Thresholds::TOUCH_DEFAULT;
            break;
    }

    int index1 = -1;
    int index2 = -1;
    switch (source)
    {
        case Source::BASE:
            if ((index1 = findComponent("", vapor::OpenVRInputType::NONE, availableComponents)) == -1)
            {
                return false;
            }
            break;
        case Source::CLICK:
            if ((index1 = findComponent("click", vapor::OpenVRInputType::BOOLEAN, availableComponents)) == -1)
            {
                return false;
            }
            break;
        case Source::TOUCH:
            if ((index1 = findComponent("touch", vapor::OpenVRInputType::BOOLEAN, availableComponents)) == -1)
            {
                return false;
            }
            break;
        case Source::VALUE:
            if ((index1 = findComponent("value", vapor::OpenVRInputType::FLOAT, availableComponents)) == -1)
            {
                return false;
            }
            convertFromScalar = true;
            break;
        case Source::FORCE:
            if ((index1 = findComponent("force", vapor::OpenVRInputType::FLOAT, availableComponents)) == -1)
            {
                return false;
            }
            convertFromScalar = true;
            break;
        case Source::POSITION:
            if ((index1 = findComponent("x", vapor::OpenVRInputType::FLOAT, availableComponents)) == -1 || (index2 = findComponent("y", vapor::OpenVRInputType::FLOAT, availableComponents)) == -1)
            {
                return false;
            }
            convertFromVector = true;
            thresholds = Hysteresis::Thresholds::CLICK_DEFAULT;
            break;
    }

    if (activateThresholdOverride.has_value())
    {
        thresholds.on = activateThresholdOverride.value();
    }
    if (deactivateThresholdOverride.has_value())
    {
        thresholds.off = deactivateThresholdOverride.value();
    }
    hysteresis = Hysteresis(thresholds);

    grabbedComponents.push_back(index1);
    if (convertFromVector)
    {
        grabbedComponents.push_back(index2);
    }

    return true;
}

void Mode::ClickFilter::grabNone(std::vector<int>& grabbedComponents)
{
    convertFromScalar = false;
    convertFromVector = false;
    grabbedComponents.push_back(-1);
}

InputState Mode::ClickFilter::getInitialState(const uint64_t*& inputSourceHandles)
{
    uint64_t inputSourceHandle1 = *inputSourceHandles++;
    uint64_t inputSourceHandle2 = convertFromVector ? *inputSourceHandles++ : inputSourceHandle1;
    if (convertFromScalar || convertFromVector)
    {
        return InputState {
            .type = InputType::DIGITAL,
            .data = {.digital = false},
            .inputSourceHandle = inputSourceHandle1,
            .changeTime = 0
        };
    }
    else
    {
        return InputState {
           .type = InputType::EMPTY,
           .inputSourceHandle = inputSourceHandle1
        };
    }
}

InputState Mode::ClickFilter::update(const InputState*& inputStates, long currentTime)
{
    const InputState& inputState1 = *inputStates++;
    const InputState& inputState2 = convertFromVector ? *inputStates++ : inputState1;
    if (convertFromScalar || convertFromVector)
    {
        if (inputState1.type != InputType::EMPTY && (convertFromScalar || inputState2.type != InputType::EMPTY))
        {
            float value;
            if (convertFromScalar)
            {
                value = inputState1.data.analog.x;
            }
            else if (convertFromVector)
            {
                value = std::sqrt(inputState1.data.analog.x * inputState1.data.analog.x + inputState2.data.analog.x * inputState2.data.analog.x);
            }
            bool previousState = currentState;
            currentState = hysteresis.update(value);
            if (currentState != previousState)
            {
                currentStateChangeTime = std::max(inputState1.changeTime, inputState2.changeTime);
            }
        }
        return InputState {
            .type = InputType::DIGITAL,
            .data = {.digital = currentState},
            .inputSourceHandle = inputState1.inputSourceHandle,
            .changeTime = currentStateChangeTime
        };
    }
    else
    {
        if (inputState1.type != InputType::EMPTY)
        {
            return InputState {
                .type = InputType::DIGITAL,
                .data = {.digital = inputState1.data.digital},
                .inputSourceHandle = inputState1.inputSourceHandle,
                .changeTime = inputState1.changeTime
            };
        }
        else
        {
            return InputState {
                .type = InputType::EMPTY,
                .inputSourceHandle = inputState1.inputSourceHandle
            };
        }
    }
}

//

bool Mode::LatchingClickFilter::tryGrab(Mode::ClickFilter::Source source, Mode::ClickFilter::DefaultThresholdsType defaultThresholdsType, std::optional<float> activateThresholdOverride, std::optional<float> deactivateThresholdOverride, bool touchy, bool sticky, std::optional<float> stickyActivateThresholdOverride, std::optional<float> stickyDeactivateThresholdOverride, const std::vector<Mode::ComponentDescription>& availableComponents, std::vector<int>& grabbedComponents)
{
    this->touchy = touchy;
    sticky = sticky && (source == ClickFilter::Source::CLICK || source == ClickFilter::Source::TOUCH);
    this->sticky = sticky;

    if (!click.tryGrab(source, defaultThresholdsType, activateThresholdOverride, deactivateThresholdOverride, availableComponents, grabbedComponents))
    {
        this->touchy = false;
        this->sticky = false;
        return false;
    }

    if (touchy)
    {
        int index = findComponent("touch", vapor::OpenVRInputType::BOOLEAN, availableComponents);
        if (index != -1)
        {
            grabbedComponents.push_back(index);
        }
        else
        {
            this->touchy = false;
        }
    }

    if (sticky)
    {
        int index1 = findComponent("x", vapor::OpenVRInputType::FLOAT, availableComponents);
        int index2 = findComponent("y", vapor::OpenVRInputType::FLOAT, availableComponents);
        grabbedComponents.push_back(index1);
        grabbedComponents.push_back(index2);

        Hysteresis::Thresholds stickyThresholds = Hysteresis::Thresholds::STICKY_DEFAULT;
        if (stickyActivateThresholdOverride.has_value())
        {
            stickyThresholds.on = stickyActivateThresholdOverride.value();
        }
        if (stickyDeactivateThresholdOverride.has_value())
        {
            stickyThresholds.off = stickyDeactivateThresholdOverride.value();
        }
        positionHysteresis = Hysteresis(stickyThresholds);
    }

    return true;
}

void Mode::LatchingClickFilter::grabNone(std::vector<int>& grabbedComponents)
{
    click.grabNone(grabbedComponents);
    touchy = false;
    sticky = false;
}

InputState Mode::LatchingClickFilter::getInitialState(const uint64_t*& inputSourceHandles)
{
    InputState clickInitialState = click.getInitialState(inputSourceHandles);
    if (touchy || sticky)
    {
        if (touchy)
        {
            inputSourceHandles += 1;
        }
        if (sticky)
        {
            inputSourceHandles += 2;
        }
        return InputState {
            .type = InputType::DIGITAL,
            .data = {.digital = false},
            .inputSourceHandle = clickInitialState.inputSourceHandle,
            .changeTime = 0
        };
    }
    else
    {
        return clickInitialState;
    }
}

InputState Mode::LatchingClickFilter::update(const InputState*& inputStates, long currentTime)
{
    InputState clickState = click.update(inputStates, currentTime);

    if (touchy || sticky)
    {
        InputState touchState;
        if (touchy)
        {
            touchState = *inputStates++;
        }
        else
        {
            touchState = InputState {
                .type = InputType::DIGITAL,
                .data = {.digital = false}
            };
        }

        if (sticky)
        {
            const InputState& xState = *inputStates++;
            const InputState& yState = *inputStates++;
            if (xState.type != InputType::EMPTY)
            {
                float x = xState.data.analog.x;
                float y = yState.type != InputType::EMPTY ? yState.data.analog.x : 0.0f;
                float value = std::sqrt(x * x + y * y);
                positionState = positionHysteresis.update(value);
            }
        }

        if (clickState.type != InputType::EMPTY && touchState.type != InputType::EMPTY)
        {
            currentState = clickState.data.digital || (touchState.data.digital && currentState) || (positionState && currentState);
            currentChangeTime = clickState.changeTime;
        }

        return InputState {
            .type = InputType::DIGITAL,
            .data = {.digital = currentState},
            .inputSourceHandle = clickState.inputSourceHandle,
            .changeTime = currentChangeTime
        };
    }
    else
    {
        return clickState;
    }
}

//

void Mode::BasicButtonFilter::readParameters(const nlohmann::json::object_t& parameters)
{
    forceInput = readForceInput(parameters);
    readThresholds(parameters, "click", clickActivateThreshold, clickDeactivateThreshold);
    readThresholds(parameters, "touch", touchActivateThreshold, touchDeactivateThreshold);
    touchyClick = parameters.contains("touchy_click") ? parameters.at("touchy_click").get<bool>() : false;
    stickyClick = parameters.contains("sticky_click") ? parameters.at("sticky_click").get<bool>() : false;
    readThresholds(parameters, "sticky", stickyActivateThreshold, stickyDeactivateThreshold);
}

bool Mode::BasicButtonFilter::tryGrabClick(ClickFilter::Source source, const std::vector<ComponentDescription>& availableComponents, std::vector<int>& grabbedComponents)
{
    return click.tryGrab(source, ClickFilter::DefaultThresholdsType::CLICK, clickActivateThreshold, clickDeactivateThreshold, touchyClick, stickyClick, stickyActivateThreshold, stickyDeactivateThreshold, availableComponents, grabbedComponents);
}

void Mode::BasicButtonFilter::grabClickNone(std::vector<int>& grabbedComponents)
{
    click.grabNone(grabbedComponents);
}

bool Mode::BasicButtonFilter::tryGrabTouch(ClickFilter::Source source, const std::vector<ComponentDescription>& availableComponents, std::vector<int>& grabbedComponents)
{
    return touch.tryGrab(source, ClickFilter::DefaultThresholdsType::TOUCH, touchActivateThreshold, touchDeactivateThreshold, availableComponents, grabbedComponents);
}

void Mode::BasicButtonFilter::grabTouchNone(std::vector<int>& grabbedComponents)
{
    touch.grabNone(grabbedComponents);
}

InputState Mode::BasicButtonFilter::getInitialClickState(const uint64_t*& inputSourceHandles)
{
    return click.getInitialState(inputSourceHandles);
}

InputState Mode::BasicButtonFilter::getInitialTouchState(const uint64_t*& inputSourceHandles)
{
    return touch.getInitialState(inputSourceHandles);
}

InputState Mode::BasicButtonFilter::updateClick(const InputState*& inputStates, long currentTime)
{
    return click.update(inputStates, currentTime);
}

InputState Mode::BasicButtonFilter::updateTouch(const InputState*& inputStates, long currentTime)
{
    return touch.update(inputStates, currentTime);
}

//

ButtonMode::ButtonMode(const nlohmann::json::object_t& parameters)
{
    button.readParameters(parameters);
}

std::vector<std::string> ButtonMode::getProvidedOutputNames()
{
    static const std::vector<std::string> names = (std::vector<std::string>) {"click", "touch", "long", "held", "double", "position"};
    return names;
}

std::vector<int> ButtonMode::connect(const std::vector<Mode::ComponentDescription>& availableComponents, const bool* connectedOutputs)
{
    std::vector<int> indexes;

    bool clickConnectedOutput = connectedOutputs[0] || connectedOutputs[2] || connectedOutputs[3] || connectedOutputs[4] || connectedOutputs[5];
    advancedOutput = connectedOutputs[2] || connectedOutputs[4];
    if (clickConnectedOutput)
    {
        if (advancedOutput)
        {
            if (findComponent(button.forceInput == ForceInput::TOUCH ? "touch" : "click", vapor::OpenVRInputType::BOOLEAN, availableComponents) != -1)
            {
                switch (button.forceInput)
                {
                    default:
                        if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                        if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                        if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                        if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                        button.grabClickNone(indexes); break;
                    case ForceInput::CLICK:
                        if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                        if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                        button.grabClickNone(indexes); break;
                    case ForceInput::TOUCH:
                        if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                        if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                        if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                        if (button.tryGrabClick(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                        button.grabClickNone(indexes); break;
                    case ForceInput::POSITION:
                        if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                        if (button.tryGrabClick(ClickFilter::Source::POSITION, availableComponents, indexes)) break;
                        if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                        if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                        if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                        button.grabClickNone(indexes); break;
                    case ForceInput::FORCE:
                        if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                        if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                        if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                        if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                        button.grabClickNone(indexes); break;
                }
            }
            else
            {
                button.grabClickNone(indexes);
            }
        }
        else
        {
            switch (button.forceInput)
            {
                default:
                    if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                    if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                    if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                    if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                    if (button.tryGrabClick(ClickFilter::Source::POSITION, availableComponents, indexes)) break;
                    if (button.tryGrabClick(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                    button.grabClickNone(indexes); break;
                case ForceInput::CLICK:
                    if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                    if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                    if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                    if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                    if (button.tryGrabClick(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                    button.grabClickNone(indexes); break;
                case ForceInput::TOUCH:
                    if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                    if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                    if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                    if (button.tryGrabClick(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                    if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                    button.grabClickNone(indexes); break;
                case ForceInput::POSITION:
                    if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                    if (button.tryGrabClick(ClickFilter::Source::POSITION, availableComponents, indexes)) break;
                    if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                    if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                    if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                    if (button.tryGrabClick(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                    button.grabClickNone(indexes); break;
                case ForceInput::FORCE:
                    if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                    if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                    if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                    if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                    if (button.tryGrabClick(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                    button.grabClickNone(indexes); break;
            }
        }
    }
    else
    {
        button.grabClickNone(indexes);
    }

    bool touchConnectedOutput = connectedOutputs[1];
    if (touchConnectedOutput)
    {
        switch (button.forceInput)
        {
            default:
            case ForceInput::CLICK:
            case ForceInput::TOUCH:
            case ForceInput::FORCE:
                if (button.tryGrabTouch(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                if (button.tryGrabTouch(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                button.grabTouchNone(indexes); break;
            case ForceInput::POSITION:
                if (button.tryGrabTouch(ClickFilter::Source::POSITION, availableComponents, indexes)) break;
                if (button.tryGrabTouch(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                if (button.tryGrabTouch(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                button.grabTouchNone(indexes); break;
        }
    }
    else
    {
        button.grabTouchNone(indexes);
    }

    return indexes;
}

std::vector<InputState> ButtonMode::getInitialStates(const uint64_t* inputSourceHandles)
{
    InputState clickInitialState = button.getInitialClickState(inputSourceHandles);
    InputState touchInitialState = button.getInitialTouchState(inputSourceHandles);
    InputState emptyInitialState = InputState {
       .type = InputType::EMPTY,
       .inputSourceHandle = clickInitialState.inputSourceHandle
    };
    return std::vector<InputState> {clickInitialState, touchInitialState, clickInitialState, clickInitialState, clickInitialState, advancedOutput ? emptyInitialState : clickInitialState};
}

std::vector<InputState> ButtonMode::update(const InputState* inputStates, long currentTime)
{
    InputState clickInputState = button.updateClick(inputStates, currentTime);
    InputState touchInputState = button.updateTouch(inputStates, currentTime);
    InputState emptyInputState = InputState {
        .type = InputType::EMPTY
    };

    if (!advancedOutput)
    {
        return std::vector<InputState> {clickInputState, touchInputState, emptyInputState, clickInputState, emptyInputState, clickInputState};
    }
    else
    {
        InputState longPressInputState;
        InputState heldInputState;
        InputState doublePressInputState;

        if (clickInputState.type == InputType::EMPTY)
        {
            longPressInputState = heldInputState = doublePressInputState = emptyInputState;
            clickState = longPressState = doublePressState = heldState = false;
            clickChangeTime = longPressChangeTime = doublePressChangeTime = heldChangeTime = -1;
            clickFireOnNextUpdate = false;
            doublePressTestState = false;
            doublePressPreviousPressTime = -1;
        }
        else
        {
            if (clickState)
            {
                clickState = false;
                clickChangeTime = currentTime;
            }

            if (clickInputState.data.digital)
            {
                clickFireOnNextUpdate = false;

                if (!longPressState && !doublePressState)
                {
                    if (currentTime - clickInputState.changeTime >= LONG_PRESS_TIMEOUT)
                    {
                        longPressState = true;
                        longPressChangeTime = clickInputState.changeTime;
                    }
                }

                if (!doublePressTestState)
                {
                    doublePressTestState = true;

                    if (doublePressPreviousPressTime != -1 && clickInputState.changeTime - doublePressPreviousPressTime < DOUBLE_PRESS_TIMEOUT && !longPressState)
                    {
                        doublePressState = true;
                        doublePressChangeTime = clickInputState.changeTime;
                        doublePressPreviousPressTime = -1;
                    }
                    else
                    {
                        doublePressPreviousPressTime = clickInputState.changeTime;
                    }
                }

                if (!heldState)
                {
                    if (!longPressState && !doublePressState)
                    {
                        heldState = true;
                        heldChangeTime = clickInputState.changeTime;
                    }
                    else if (longPressState)
                    {
                        heldChangeTime = longPressChangeTime;
                    }
                }
                else
                {
                    if (longPressState)
                    {
                        heldState = false;
                        // NOTE: SteamVR does **not** reset change time here!
                    }
                }
            }
            else
            {
                if (clickFireOnNextUpdate)
                {
                    clickState = true;
                    clickChangeTime = heldChangeTime;
                    clickFireOnNextUpdate = false;
                }

                if (heldState)
                {
                    heldState = false;
                    heldChangeTime = clickInputState.changeTime;

                    if (!longPressState)
                    {
                        clickFireOnNextUpdate = true;
                    }
                }

                if (longPressState)
                {
                    longPressState = false;
                    longPressChangeTime = currentTime; // SteamVR returns current time here not the time that the button was released
                }

                if (doublePressState)
                {
                    doublePressState = false;
                    doublePressChangeTime = currentTime; // SteamVR returns current time here not the time that the button was released
                }
                doublePressTestState = false;
            }

            longPressInputState = longPressChangeTime != -1 ? InputState {
                .type = InputType::DIGITAL,
                .data = {.digital = longPressState},
                .inputSourceHandle = clickInputState.inputSourceHandle,
                .changeTime = longPressChangeTime
            } : emptyInputState;
            doublePressInputState = doublePressChangeTime != -1 ? InputState {
                .type = InputType::DIGITAL,
                .data = {.digital = doublePressState},
                .inputSourceHandle = clickInputState.inputSourceHandle,
                .changeTime = doublePressChangeTime
            } : emptyInputState;
            heldInputState = heldChangeTime != -1 ? InputState {
                .type = InputType::DIGITAL,
                .data = {.digital = heldState},
                .inputSourceHandle = clickInputState.inputSourceHandle,
                .changeTime = heldChangeTime
            } : emptyInputState;
            clickInputState = clickChangeTime != -1 ? InputState {
                .type = InputType::DIGITAL,
                .data = {.digital = clickState},
                .inputSourceHandle = clickInputState.inputSourceHandle,
                .changeTime = clickChangeTime
            } : emptyInputState;
        }

        return std::vector<InputState> {clickInputState, touchInputState, longPressInputState, heldInputState, doublePressInputState, emptyInputState};
    }
}

//

TriggerMode::TriggerMode(const nlohmann::json::object_t& parameters)
{
    button.readParameters(parameters);
}

std::vector<std::string> TriggerMode::getProvidedOutputNames()
{
    static const std::vector<std::string> names = (std::vector<std::string>) {"pull", "click", "touch"};
    return names;
}

std::vector<int> TriggerMode::connect(const std::vector<Mode::ComponentDescription>& availableComponents, const bool* connectedOutputs)
{
    std::vector<int> indexes;

    if (connectedOutputs[0])
    {
        int index = findComponent("value", vapor::OpenVRInputType::FLOAT, availableComponents);
        if (index == -1)
        {
            index = findComponent("", vapor::OpenVRInputType::FLOAT, availableComponents);
        }
        indexes.push_back(index);
    }
    else
    {
        indexes.push_back(-1);
    }

    if (connectedOutputs[1])
    {
        switch (button.forceInput)
        {
            default:
            case ForceInput::CLICK:
                if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                button.grabClickNone(indexes); break;
            case ForceInput::TOUCH:
                if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                if (findComponent("click", vapor::OpenVRInputType::BOOLEAN, availableComponents) != -1 && button.tryGrabClick(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                button.grabClickNone(indexes); break;
            case ForceInput::POSITION:
                if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::POSITION, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                button.grabClickNone(indexes); break;
            case ForceInput::FORCE:
                if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                button.grabClickNone(indexes); break;
        }
    }
    else
    {
        button.grabClickNone(indexes);
    }

    if (connectedOutputs[2])
    {
        switch (button.forceInput)
        {
            default:
            case ForceInput::CLICK:
            case ForceInput::TOUCH:
            case ForceInput::FORCE:
                if (button.tryGrabTouch(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                if (button.tryGrabTouch(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                button.grabTouchNone(indexes); break;
            case ForceInput::POSITION:
                if (button.tryGrabTouch(ClickFilter::Source::POSITION, availableComponents, indexes)) break;
                if (button.tryGrabTouch(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                if (button.tryGrabTouch(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                button.grabTouchNone(indexes); break;
        }
    }
    else
    {
        button.grabTouchNone(indexes);
    }

    return indexes;
}

std::vector<InputState> TriggerMode::getInitialStates(const uint64_t* inputSourceHandles)
{
    InputState pullInitialState = InputState {
       .type = InputType::EMPTY,
       .inputSourceHandle = inputSourceHandles[0]
    };
    inputSourceHandles += 1;
    InputState clickInitialState = button.getInitialClickState(inputSourceHandles);
    InputState touchInitialState = button.getInitialTouchState(inputSourceHandles);
    return std::vector<InputState> {pullInitialState, clickInitialState, touchInitialState};
}

std::vector<InputState> TriggerMode::update(const InputState* inputStates, long currentTime)
{
    InputState pullInputState = inputStates[0];
    inputStates += 1;
    InputState clickInputState = button.updateClick(inputStates, currentTime);
    InputState touchInputState = button.updateTouch(inputStates, currentTime);
    return std::vector<InputState> {pullInputState, clickInputState, touchInputState};
}

//

JoystickMode::JoystickMode(const nlohmann::json::object_t& parameters)
{
    if (parameters.contains("invert"))
    {
        const std::string& invert = parameters.at("invert");
        invertX = invert == "x" || invert == "xy";
        invertY = invert == "y" || invert == "xy";
    }
    else
    {
        invertX = invertY = false;
    }
    if (parameters.contains("deadzone_pct"))
    {
        deadZone = parameters.at("deadzone_pct").get<float>() / 100.0f;
    }
    if (parameters.contains("maxzone_pct"))
    {
        maxZone = parameters.at("maxzone_pct").get<float>() / 100.0f;
    }
    if (parameters.contains("exponent"))
    {
        exponent = parameters.at("exponent").get<float>();
    }

    button.readParameters(parameters);
}

std::vector<std::string> JoystickMode::getProvidedOutputNames()
{
    static const std::vector<std::string> names = (std::vector<std::string>) {"position", "click", "touch"};
    return names;
}

std::vector<int> JoystickMode::connect(const std::vector<Mode::ComponentDescription>& availableComponents, const bool* connectedOutputs)
{
    std::vector<int> indexes;

    if (connectedOutputs[0])
    {
        int index1 = findComponent("x", vapor::OpenVRInputType::FLOAT, availableComponents);
        int index2 = findComponent("y", vapor::OpenVRInputType::FLOAT, availableComponents);
        if (index1 != -1 && index2 != -1)
        {
            indexes.push_back(index1);
            indexes.push_back(index2);
        }
        else
        {
            indexes.push_back(-1);
            indexes.push_back(-1);
        }
    }
    else
    {
        indexes.push_back(-1);
        indexes.push_back(-1);
    }

    if (connectedOutputs[1])
    {
        switch (button.forceInput)
        {
            default:
                if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                button.grabClickNone(indexes); break;
            case ForceInput::CLICK:
                if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                button.grabClickNone(indexes); break;
            case ForceInput::TOUCH:
                if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                button.grabClickNone(indexes); break;
            case ForceInput::POSITION:
                if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::POSITION, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                button.grabClickNone(indexes); break;
            case ForceInput::FORCE:
                if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                button.grabClickNone(indexes); break;
        }
    }
    else
    {
        button.grabClickNone(indexes);
    }

    if (connectedOutputs[2])
    {
        switch (button.forceInput)
        {
            default:
            case ForceInput::CLICK:
            case ForceInput::TOUCH:
            case ForceInput::FORCE:
                if (button.tryGrabTouch(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                if (button.tryGrabTouch(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                button.grabTouchNone(indexes); break;
            case ForceInput::POSITION:
                if (button.tryGrabTouch(ClickFilter::Source::POSITION, availableComponents, indexes)) break;
                if (button.tryGrabTouch(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                if (button.tryGrabTouch(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                button.grabTouchNone(indexes); break;
        }
    }
    else
    {
        button.grabTouchNone(indexes);
    }

    return indexes;
}

std::vector<InputState> JoystickMode::getInitialStates(const uint64_t* inputSourceHandles)
{
    InputState positionInitialState = InputState {
       .type = InputType::EMPTY,
       .inputSourceHandle = inputSourceHandles[0]
    };
    inputSourceHandles += 2;
    InputState clickInitialState = button.getInitialClickState(inputSourceHandles);
    InputState touchInitialState = button.getInitialTouchState(inputSourceHandles);
    return std::vector<InputState> {positionInitialState, clickInitialState, touchInitialState};
}

std::vector<InputState> JoystickMode::update(const InputState* inputStates, long currentTime)
{
    InputState positionInputState;
    if (inputStates[0].type != InputType::EMPTY && inputStates[1].type != InputType::EMPTY)
    {
        float x = inputStates[0].data.analog.x;
        float y = inputStates[1].data.analog.x;
        if (deadZone != 0.0f || maxZone != 1.0f || exponent != 1.0f)
        {
            float d = std::sqrt(x * x + y * y);
            if (d > 0.0f)
            {
                float d1 = (d - deadZone) / (maxZone - deadZone);
                d1 = std::min(std::max(d1, 0.0f), 1.0f);
                d1 = std::pow(d1, exponent);
                d1 = std::min(std::max(d1, 0.0f), 1.0f);
                x = d1 * (x / d);
                y = d1 * (y / d);
            }
        }
        if (invertX)
        {
            x = -x;
        }
        if (invertY)
        {
            y = -y;
        }
        positionInputState = InputState {
            .type = InputType::ANALOG,
            .data = {.analog = {x, y, 0.0f}},
            .inputSourceHandle = inputStates[0].inputSourceHandle,
            .changeTime = std::max(inputStates[0].changeTime, inputStates[1].changeTime)
        };
    }
    else
    {
        positionInputState = InputState {
            .type = InputType::EMPTY,
            .inputSourceHandle = inputStates[0].inputSourceHandle
        };
    }
    inputStates += 2;

    InputState clickInputState = button.updateClick(inputStates, currentTime);
    InputState touchInputState = button.updateTouch(inputStates, currentTime);

    return std::vector<InputState> {positionInputState, clickInputState, touchInputState};
}

//

/*DpadMode::DpadMode(const nlohmann::json::object_t& parameters)
{
    subMode = parameters.contains("sub_mode") && parameters.at("sub_mode") == "touch" ? SubMode::TOUCH : SubMode::CLICK;

    // TODO
    // sticky
    // deadzone stuff
    // click activate threshold ?
}

std::vector<std::string> DpadMode::getProvidedOutputNames()
{
    static const std::vector<std::string> names = (std::vector<std::string>) {"north", "east", "south", "west", "center"};
    return names;
}

std::vector<int> DpadMode::connect(const std::vector<Mode::ComponentDescription>& availableComponents, const bool* connectedOutputs)
{
    // TODO
}

std::vector<InputState> DpadMode::getInitialStates(const uint64_t* inputSourceHandles)
{
    // TODO
}

std::vector<InputState> DpadMode::update(const InputState* inputStates, long currentTime)
{
    // TODO
}*/

//

ToggleButtonMode::ToggleButtonMode(const nlohmann::json::object_t& parameters)
{
    clickInitialState = parameters.contains("click_initial_state") ? parameters.at("click_initial_state").get<bool>() : false;
    touchInitialState = parameters.contains("touch_initial_state") ? parameters.at("touch_initial_state").get<bool>() : false;

    button.readParameters(parameters);
}

std::vector<std::string> ToggleButtonMode::getProvidedOutputNames()
{
    static const std::vector<std::string> names = (std::vector<std::string>) {"click", "touch"};
    return names;
}

std::vector<int> ToggleButtonMode::connect(const std::vector<Mode::ComponentDescription>& availableComponents, const bool* connectedOutputs)
{
    std::vector<int> indexes;

    enableTouchOutput = findComponent("touch", vapor::OpenVRInputType::BOOLEAN, availableComponents) != -1 || findComponent("value", vapor::OpenVRInputType::FLOAT, availableComponents) != -1 || (button.forceInput == ForceInput::POSITION && findComponent("x", vapor::OpenVRInputType::FLOAT, availableComponents) != -1 && findComponent("y", vapor::OpenVRInputType::FLOAT, availableComponents) != -1);

    if (connectedOutputs[0])
    {
        touchOutputIsClick = true;

        switch (button.forceInput)
        {
            default:
                if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                button.grabClickNone(indexes); break;
            case ForceInput::CLICK:
                if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                button.grabClickNone(indexes); break;
            case ForceInput::TOUCH:
                if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                button.grabClickNone(indexes); break;
            case ForceInput::POSITION:
                if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::POSITION, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                button.grabClickNone(indexes); break;
            case ForceInput::FORCE:
                if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                button.grabClickNone(indexes); break;
        }
        button.grabTouchNone(indexes);
    }
    else
    {
        touchOutputIsClick = false;

        button.grabClickNone(indexes);
        if (connectedOutputs[1])
        {
            switch (button.forceInput)
            {
                default:
                case ForceInput::CLICK:
                case ForceInput::TOUCH:
                case ForceInput::FORCE:
                    if (button.tryGrabTouch(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                    if (button.tryGrabTouch(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                    button.grabTouchNone(indexes); break;
                case ForceInput::POSITION:
                    if (button.tryGrabTouch(ClickFilter::Source::POSITION, availableComponents, indexes)) break;
                    if (button.tryGrabTouch(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                    if (button.tryGrabTouch(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                    button.grabTouchNone(indexes); break;
            }
        }
        else
        {
            button.grabTouchNone(indexes);
        }
    }

    currentClickState = clickInitialState;
    currentTouchState = touchOutputIsClick ? clickInitialState : touchInitialState;

    return indexes;
}

std::vector<InputState> ToggleButtonMode::getInitialStates(const uint64_t* inputSourceHandles)
{
    InputState clickInitialState = button.getInitialClickState(inputSourceHandles);
    InputState touchInitialState = button.getInitialTouchState(inputSourceHandles);
    if (touchOutputIsClick)
    {
        touchInitialState = clickInitialState;
    }

    currentClickStateChangeTime = clickInitialState.inputSourceHandle != 0 && clickInitialState.type == InputType::EMPTY ? 0 : -1;
    currentTouchStateChangeTime = touchInitialState.inputSourceHandle != 0 && touchInitialState.type == InputType::EMPTY ? 0 : -1;

    clickInitialState = currentClickStateChangeTime != -1 ? InputState {
        .type = InputType::DIGITAL,
        .data = {.digital = currentClickState},
        .inputSourceHandle = clickInitialState.inputSourceHandle,
        .changeTime = currentClickStateChangeTime
    } : InputState {
        .type = InputType::EMPTY
    };
    touchInitialState = enableTouchOutput && currentTouchStateChangeTime != -1 ? InputState {
        .type = InputType::DIGITAL,
        .data = {.digital = currentTouchState},
        .inputSourceHandle = touchInitialState.inputSourceHandle,
        .changeTime = currentTouchStateChangeTime
    } : InputState {
        .type = InputType::EMPTY
    };
    return std::vector<InputState> {clickInitialState, touchInitialState};
}

std::vector<InputState> ToggleButtonMode::update(const InputState* inputStates, long currentTime)
{
    InputState clickInputState = button.updateClick(inputStates, currentTime);
    InputState touchInputState = button.updateTouch(inputStates, currentTime);
    if (touchOutputIsClick)
    {
        touchInputState = clickInputState;
    }
    bool clickState = clickInputState.type != InputType::EMPTY ? clickInputState.data.digital : lastClickState;
    bool touchState = touchInputState.type != InputType::EMPTY ? touchInputState.data.digital : lastTouchState;

    if (clickState != lastClickState)
    {
        lastClickState = clickState;
        if (clickState)
        {
            currentClickState = !currentClickState;
            currentClickStateChangeTime = clickInputState.changeTime;
        }
    }

    if (touchState != lastTouchState)
    {
        lastTouchState = touchState;
        if (touchState)
        {
            currentTouchState = !currentTouchState;
            currentTouchStateChangeTime = touchInputState.changeTime;
        }
    }

    clickInputState = currentClickStateChangeTime != -1 ? InputState {
        .type = InputType::DIGITAL,
        .data = {.digital = currentClickState},
        .inputSourceHandle = clickInputState.inputSourceHandle,
        .changeTime = currentClickStateChangeTime
    } : InputState {
        .type = InputType::EMPTY
    };
    touchInputState = enableTouchOutput && currentTouchStateChangeTime != -1 ? InputState {
        .type = InputType::DIGITAL,
        .data = {.digital = currentTouchState},
        .inputSourceHandle = touchInputState.inputSourceHandle,
        .changeTime = currentTouchStateChangeTime
    } : InputState {
        .type = InputType::EMPTY
    };
    return std::vector<InputState> {clickInputState, touchInputState};
}

//

ScalarConstantMode::ScalarConstantMode(const nlohmann::json::object_t& parameters)
{
    onX = parameters.contains("on/x") ? parameters.at("on/x").get<float>() : 1.0f;
    onY = parameters.contains("on/y") ? parameters.at("on/y").get<float>() : 1.0f;
    offX = parameters.contains("off/x") ? parameters.at("off/x").get<float>() : 0.0f;
    offY = parameters.contains("off/y") ? parameters.at("off/y").get<float>() : 0.0f;

    button.readParameters(parameters);
}

std::vector<std::string> ScalarConstantMode::getProvidedOutputNames()
{
    static const std::vector<std::string> names = (std::vector<std::string>) {"value"};
    return names;
}

std::vector<int> ScalarConstantMode::connect(const std::vector<Mode::ComponentDescription>& availableComponents, const bool* connectedOutputs)
{
    std::vector<int> indexes;

    if (connectedOutputs[0])
    {
        switch (button.forceInput)
        {
            default:
                if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                button.grabClickNone(indexes); break;
            case ForceInput::CLICK:
                if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                button.grabClickNone(indexes); break;
            case ForceInput::TOUCH:
                if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::TOUCH, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                button.grabClickNone(indexes); break;
            case ForceInput::POSITION:
                if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::POSITION, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                button.grabClickNone(indexes); break;
            case ForceInput::FORCE:
                if (button.tryGrabClick(ClickFilter::Source::BASE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::FORCE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::VALUE, availableComponents, indexes)) break;
                if (button.tryGrabClick(ClickFilter::Source::CLICK, availableComponents, indexes)) break;
                button.grabClickNone(indexes); break;
        }
    }
    else
    {
        button.grabClickNone(indexes);
    }

    return indexes;
}

std::vector<InputState> ScalarConstantMode::getInitialStates(const uint64_t* inputSourceHandles)
{
    InputState initialState = InputState {
        .type = InputType::ANALOG,
        .data = {.analog = {currentState ? onX : offX, currentState ? onY : offY, 0.0f}},
        .inputSourceHandle = button.getInitialClickState(inputSourceHandles).inputSourceHandle,
        .changeTime = currentStateChangeTime
    };
    return std::vector<InputState> {initialState};
}

std::vector<InputState> ScalarConstantMode::update(const InputState* inputStates, long currentTime)
{
    InputState clickState = button.updateClick(inputStates, currentTime);
    if (clickState.type != InputType::EMPTY)
    {
        currentState = clickState.data.digital;
        currentStateChangeTime = clickState.changeTime;
    }
    InputState inputState = InputState {
        .type = InputType::ANALOG,
        .data = {.analog = {currentState ? onX : offX, currentState ? onY : offY, 0.0f}},
        .inputSourceHandle = clickState.inputSourceHandle,
        .changeTime = currentStateChangeTime
    };
    return std::vector<InputState> {inputState};
}

//

ForceSensorMode::ForceSensorMode(const nlohmann::json::object_t& parameters)
{
    // empty
}

std::vector<std::string> ForceSensorMode::getProvidedOutputNames()
{
    static const std::vector<std::string> names = (std::vector<std::string>) {"force"};
    return names;
}

std::vector<int> ForceSensorMode::connect(const std::vector<Mode::ComponentDescription>& availableComponents, const bool* connectedOutputs)
{
    std::vector<int> indexes;
    indexes.push_back(findComponent("force", vapor::OpenVRInputType::FLOAT, availableComponents));
    return indexes;
}

std::vector<InputState> ForceSensorMode::getInitialStates(const uint64_t* inputSourceHandles)
{
    InputState initialState = InputState {
       .type = InputType::EMPTY,
       .inputSourceHandle = inputSourceHandles[0]
    };
    return std::vector<InputState> {initialState};
}

std::vector<InputState> ForceSensorMode::update(const InputState* inputStates, long currentTime)
{
    return std::vector<InputState> {inputStates[0]};
}
