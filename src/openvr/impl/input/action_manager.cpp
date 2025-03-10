#include "action_manager.h"

#include "log/stub.h"
#include "log/log.h"
#include "log/abort.h"

#include "path_handle_registry.h"
#include "input_source_utils.h"

#include <algorithm>
#include <unordered_set>
#include <cctype>

#include <nlohmann/json.hpp>
#include <fstream>
#include <filesystem>

using namespace openvr::input;

using namespace nlohmann;

ActionManager::ActionManager()
{
    // empty
}

ActionManager::~ActionManager()
{
    // empty
}

Action::Action(InputType type): type(type)
{
    // empty
}

static inline std::string stringToLowercase(const std::string& in)
{
    std::string out = in;
    std::transform(out.begin(), out.end(), out.begin(), [](char c){ return std::tolower(c); });
    return out;
}

static inline InputState getDefaultInputState(const InputType& inputType, uint64_t inputSourceHandle)
{
    switch (inputType)
    {
        case InputType::DIGITAL:
            return InputState {
                .type = InputType::DIGITAL,
                .data = {.digital = false},
                .inputSourceHandle = inputSourceHandle,
                .changeTime = 0
            };
        case InputType::ANALOG:
            return InputState {
                .type = InputType::ANALOG,
                .data = {.analog = {0.0f, 0.0f, 0.0f}},
                .inputSourceHandle = inputSourceHandle,
                .changeTime = 0
            };
    }
}

static inline InputState convertInputType(const InputState& inputState, const InputType& inputType)
{
    if (inputState.type == inputType)
    {
        return inputState;
    }
    switch (inputType)
    {
        case InputType::DIGITAL:
            switch (inputState.type)
            {
                case InputType::ANALOG:
                    return InputState {
                        .type = InputType::DIGITAL,
                        .data = {.digital = inputState.data.analog.x > 0.5f},
                        .inputSourceHandle = inputState.inputSourceHandle,
                        .changeTime = inputState.changeTime
                    };
            }
            break;
        case InputType::ANALOG:
            switch (inputState.type)
            {
                case InputType::DIGITAL:
                    return InputState {
                        .type = InputType::ANALOG,
                        .data = {.analog = {inputState.data.digital ? 1.0f : 0.0f, 0.0f, 0.0f}},
                        .inputSourceHandle = inputState.inputSourceHandle,
                        .changeTime = inputState.changeTime
                    };
            }
            break;
    }
    return getDefaultInputState(inputType, inputState.inputSourceHandle);
}

bool ActionManager::populateFromJSON(const std::string& filePath)
{
    TRACE_F("Reading actions from %s", filePath.c_str());

    try
    {
        std::ifstream stream(filePath);
        json j = json::parse(stream);

        /*if (j.contains("action_sets"))
        {
            json& actionSets = j.at("action_sets");
            for (auto it: actionSets)
            {
                const std::string& name = it.at("name");
                this->actionSets.try_emplace(name);
            }
        }*/

        json& actions = j.at("actions");
        for (auto it: actions)
        {
            const std::string& name = stringToLowercase(it.at("name"));
            const std::string& type = stringToLowercase(it.at("type"));

            if (!name.starts_with("/actions/"))
            {
                return false;
            }
            const std::string& actionSetName = name.substr(0, name.find('/', std::string("/actions/").length()));
            ActionSet& actionSet = this->actionSets[actionSetName];

            InputType inputType;
            if (type == "boolean")
            {
                inputType = InputType::DIGITAL;
            }
            else if (type == "vector1")
            {
                inputType = InputType::ANALOG;
            }
            else if (type == "vector2")
            {
                inputType = InputType::ANALOG;
            }
            else if (type == "vector3")
            {
                inputType = InputType::ANALOG;
            }
            else if (type == "pose")
            {
                inputType = InputType::POSE;
            }
            else if (type == "skeleton")
            {
                inputType = InputType::SKELETON;
            }
            else if (type == "vibration")
            {
                inputType = InputType::HAPTIC;
            }
            else
            {
                TRACE_F("Action has invalid type %s", type.c_str());
                return false;
            }

            this->actions.emplace(name, inputType);
            Action& action = this->actions.at(name);
            actionSet.actions[name] = &action;
        }

        if (j.contains("default_bindings"))
        {
            json& defaultBindings = j.at("default_bindings");
            for (auto it: defaultBindings)
            {
                const std::string& controllerType = stringToLowercase(it.at("controller_type"));
                const std::string& bindingUrl = it.at("binding_url");
                this->defaultBindingFilePaths[controllerType] = (std::filesystem::path(filePath).parent_path() / bindingUrl).string();
            }
        }

        return true;
    }
    catch (const std::exception& exception)
    {
        return false;
    }
}

bool ActionManager::loadBinding(const std::string& filePath, vapor::InputProfile* inputProfile)
{
    TRACE_F("Loading bindings from %s", filePath.c_str());

    for (auto& it: this->actions)
    {
        Action& action = it.second;
        for (Action::Source& source: action.sources)
        {
            delete source.binding;
        }
        action.sources.clear();
        action.poseSources.clear();
        action.hapticOutputs.clear();
    }

    try
    {
        std::ifstream stream(filePath);
        json j = json::parse(stream);

        if (j.contains("controller_type"))
        {
            if (j.at("controller_type") != inputProfile->getOpenVRProfileName())
            {
                LOG("Bindings file controller type %s does not match profile %s", j.at("controller_type").get<std::string>().c_str(), inputProfile->getOpenVRProfileName().c_str());
                return false;
            }
        }

        for (const auto& it: j.at("bindings").items())
        {
            const std::string& actionSetName = stringToLowercase(it.key());

            if (it.value().contains("sources"))
            {
                for (const auto& source: it.value().at("sources"))
                {
                    const std::string& basePath = stringToLowercase(source.at("path"));
                    vapor::OpenVRInputType inputType = vapor::OpenVRInputType::NONE;
                    for (int i = 0; i < inputProfile->getOpenVRInputsCount(); i++)
                    {
                        if (inputProfile->getOpenVRInputs()[i].path == basePath)
                        {
                            inputType = inputProfile->getOpenVRInputs()[i].type;
                            break;
                        }
                    }
                    if (inputType == vapor::OpenVRInputType::NONE)
                    {
                        LOG("Input source path %s not found in profile %s", basePath.c_str(), inputProfile->getOpenVRProfileName().c_str());
                        continue;
                    }

                    // TODO: toggle_button mode, scalar_constant mode
                    enum class SourceMode
                    {
                        BUTTON,
                        TRIGGER,
                        JOYSTICK,
                        DPAD_TOUCH,
                        DPAD_CLICK
                    };
                    const std::string& mode = stringToLowercase(source.at("mode"));
                    SourceMode sourceMode;
                    if (mode == "button")
                    {
                        sourceMode = SourceMode::BUTTON;
                    }
                    else if (mode == "trigger")
                    {
                        sourceMode = SourceMode::TRIGGER;
                    }
                    else if (mode == "joystick")
                    {
                        sourceMode = SourceMode::JOYSTICK;
                    }
                    else if (mode == "dpad")
                    {
                        if (!source.contains("parameters") || !source.at("parameters").contains("sub_mode"))
                        {
                            sourceMode = SourceMode::DPAD_CLICK;
                        }
                        else
                        {
                            const std::string& subMode = source.at("parameters").at("sub_mode");
                            if (subMode == "touch")
                            {
                                sourceMode = SourceMode::DPAD_TOUCH;
                            }
                            else if (subMode == "click")
                            {
                                sourceMode = SourceMode::DPAD_CLICK;
                            }
                            else
                            {
                                LOG("Unknown dpad sub mode %s", subMode.c_str());
                                continue;
                            }
                        }
                    }
                    else
                    {
                        LOG("Unknown source mode %s", mode.c_str());
                        continue;
                    }

                    for (const auto& input: source.at("inputs").items())
                    {
                        const std::string& actionName = stringToLowercase(input.value().at("output"));
                        // TODO: does "output" object ever contain extra parameters?
                        if (!actionName.starts_with(actionSetName + "/"))
                        {
                            LOG("Action name %s is not valid for action set %s", actionName.c_str(), actionSetName.c_str());
                            continue;
                        }
                        Action* action = this->findAction(actionName);
                        if (action == nullptr)
                        {
                            LOG("Action %s does not exist", actionName.c_str());
                            continue;
                        }

                        Binding* binding = nullptr;
                        const std::string& inputName = stringToLowercase(input.key());
                        switch (sourceMode)
                        {
                            case SourceMode::BUTTON:
                                if (inputName == "click")
                                {
                                    binding = new ButtonBinding(ButtonBinding::Input::CLICK);
                                }
                                else if (inputName == "touch")
                                {
                                    binding = new ButtonBinding(ButtonBinding::Input::TOUCH);
                                }
                                break;
                            case SourceMode::TRIGGER:
                                if (inputName == "pull")
                                {
                                    binding = new TriggerBinding(TriggerBinding::Input::PULL);
                                }
                                else if (inputName == "click")
                                {
                                    binding = new TriggerBinding(TriggerBinding::Input::CLICK);
                                }
                                else if (inputName == "touch")
                                {
                                    binding = new TriggerBinding(TriggerBinding::Input::TOUCH);
                                }
                                break;
                            case SourceMode::JOYSTICK:
                                if (inputName == "position")
                                {
                                    binding = new JoystickBinding(JoystickBinding::Input::POSITION);
                                }
                                else if (inputName == "click")
                                {
                                    binding = new JoystickBinding(JoystickBinding::Input::CLICK);
                                }
                                else if (inputName == "touch")
                                {
                                    binding = new JoystickBinding(JoystickBinding::Input::TOUCH);
                                }
                                break;
                            case SourceMode::DPAD_TOUCH:
                            case SourceMode::DPAD_CLICK:
                                if (inputName == "north")
                                {
                                    binding = new DpadBinding(DpadBinding::Input::NORTH, sourceMode == SourceMode::DPAD_CLICK);
                                }
                                else if (inputName == "east")
                                {
                                    binding = new DpadBinding(DpadBinding::Input::EAST, sourceMode == SourceMode::DPAD_CLICK);
                                }
                                else if (inputName == "south")
                                {
                                    binding = new DpadBinding(DpadBinding::Input::SOUTH, sourceMode == SourceMode::DPAD_CLICK);
                                }
                                else if (inputName == "west")
                                {
                                    binding = new DpadBinding(DpadBinding::Input::WEST, sourceMode == SourceMode::DPAD_CLICK);
                                }
                                else if (inputName == "center")
                                {
                                    binding = new DpadBinding(DpadBinding::Input::CENTER, sourceMode == SourceMode::DPAD_CLICK);
                                }
                                break;
                        }
                        if (binding == nullptr)
                        {
                            LOG("Unknown input %s for source mode %s", inputName.c_str(), mode.c_str());
                            continue;
                        }

                        std::vector<int> openVRInputIndexes = binding->bindToProfile(inputType, basePath, inputProfile->getOpenVRInputs(), inputProfile->getOpenVRInputsCount());
                        if (openVRInputIndexes.size() == 0)
                        {
                            LOG("Unable to bind mode %s to path %s", mode.c_str(), basePath.c_str());
                            continue;
                        }

                        Action::Source source {
                            .binding = binding,
                            .device = getDeviceFromInputSourcePath(basePath, true),
                            .openVRInputIndexes = openVRInputIndexes,

                            .active = false,
                            .activePrevious = false,
                            .inputState = binding->getInitialState(),
                            .inputStatePrevious = binding->getInitialState()
                        };
                        action->sources.push_back(source);
                    }
                }
            }

            if (it.value().contains("poses"))
            {
                for (const auto& source: it.value().at("poses"))
                {
                    const std::string& path = stringToLowercase(source.at("path"));
                    int openVRInputIndex = -1;
                    for (int i = 0; i < inputProfile->getOpenVRInputsCount(); i++)
                    {
                        if (inputProfile->getOpenVRInputs()[i].type == vapor::OpenVRInputType::POSE && inputProfile->getOpenVRInputs()[i].path == path)
                        {
                            openVRInputIndex = i;
                            break;
                        }
                    }
                    if (openVRInputIndex == -1)
                    {
                        LOG("Input source path %s with pose type not found in profile %s", path.c_str(), inputProfile->getOpenVRProfileName().c_str());
                        continue;
                    }

                    const std::string& actionName = stringToLowercase(source.at("output"));
                    if (!actionName.starts_with(actionSetName + "/"))
                    {
                        LOG("Action name %s is not valid for action set %s", actionName.c_str(), actionSetName.c_str());
                        continue;
                    }
                    Action* action = this->findAction(actionName);
                    if (action == nullptr)
                    {
                        LOG("Action %s does not exist", actionName.c_str());
                        continue;
                    }
                    if (action->type != InputType::POSE)
                    {
                        LOG("Action %s is not of pose type", actionName.c_str());
                        continue;
                    }

                    Action::PoseSource poseSource {
                        .device = getDeviceFromInputSourcePath(path, true),
                        .openVRInputIndex = openVRInputIndex,
                        .inputSourceHandle = pathHandleRegistry.getHandle(path),

                        .active = false
                    };
                    action->poseSources.push_back(poseSource);
                }
            }

            if (it.value().contains("haptics"))
            {
                for (const auto& haptic: it.value().at("haptics"))
                {
                    const std::string& path = stringToLowercase(haptic.at("path"));
                    int openVRInputIndex = -1;
                    for (int i = 0; i < inputProfile->getOpenVRInputsCount(); i++)
                    {
                        if (inputProfile->getOpenVRInputs()[i].type == vapor::OpenVRInputType::HAPTIC && inputProfile->getOpenVRInputs()[i].path == path)
                        {
                            openVRInputIndex = i;
                            break;
                        }
                    }
                    if (openVRInputIndex == -1)
                    {
                        LOG("Input source path %s with haptic type not found in profile %s", path.c_str(), inputProfile->getOpenVRProfileName().c_str());
                        continue;
                    }

                    const std::string& actionName = stringToLowercase(haptic.at("output"));
                    if (!actionName.starts_with(actionSetName + "/"))
                    {
                        LOG("Action name %s is not valid for action set %s", actionName.c_str(), actionSetName.c_str());
                        continue;
                    }
                    Action* action = this->findAction(actionName);
                    if (action == nullptr)
                    {
                        LOG("Action %s does not exist", actionName.c_str());
                        continue;
                    }
                    if (action->type != InputType::HAPTIC)
                    {
                        LOG("Action %s is not of haptic type", actionName.c_str());
                        continue;
                    }

                    Action::HapticOutput hapticOutput {
                        .device = getDeviceFromInputSourcePath(path, true),
                        .openVRInputIndex = openVRInputIndex,
                        .inputSourceHandle = pathHandleRegistry.getHandle(path)
                    };
                    action->hapticOutputs.push_back(hapticOutput);
                }
            }
        }

        return true;
    }
    catch (const std::exception& exception)
    {
        TRACE_F("Exception");
        return false;
    }
}

void ActionManager::loadDefaultBindingForControllerProfile(vapor::InputProfile* inputProfile)
{
    const std::string& profileName = inputProfile->getOpenVRProfileName();

    LOG("Loading bindings for %s", profileName.c_str());

    auto it = this->defaultBindingFilePaths.find(profileName);
    if (it == this->defaultBindingFilePaths.end())
    {
        LOG("No default bindings for %s", profileName.c_str());
    }
    else
    {
        this->loadBinding(it->second, inputProfile);
    }
}

static inline bool checkConsumedInput(const std::unordered_set<int>& usedInputs, const std::vector<int>& inputIndexes)
{
    for (int index: inputIndexes)
    {
        if (usedInputs.contains(index))
        {
            return false;
        }
    }
    return true;
}

static inline void markConsumedInput(std::unordered_set<int>& usedInputs, const std::vector<int>& inputIndexes)
{
    for (int index: inputIndexes)
    {
        usedInputs.insert(index);
    }
}

static inline bool hasInputStateChanged(const InputState& a, const InputState& b)
{
    if (a.type != InputType::DIGITAL || b.type != InputType::DIGITAL)
    {
        return true;
    }
    return a.data.digital != b.data.digital || a.inputSourceHandle != b.inputSourceHandle;
}

void ActionManager::update(const openvr::ActiveActionSet* activeActionSets, int actionSetSize, int activeActionSetsCount, const vapor::OpenVRInputState* inputStates)
{
    TRACE_F("%d", activeActionSetsCount);

    for (auto& it: this->actions)
    {
        Action& action = it.second;
        for (Action::Source& source: action.sources)
        {
            source.inputStatePrevious = source.inputState;
            source.activePrevious = source.active;
            source.active = false;
        }
        for (Action::PoseSource& poseSource: action.poseSources)
        {
            poseSource.active = false;
        }
    }

    std::vector<openvr::ActiveActionSet> activeActionSetsCopy;
    int highestPriority = 0;
    for (int i = 0; i < activeActionSetsCount; i++)
    {
        const openvr::ActiveActionSet& activeActionSet = *((const openvr::ActiveActionSet*) ((const void*) activeActionSets + i * actionSetSize));
        ActiveActionSet activeActionSetCopy {
            .actionSet = activeActionSet.actionSet,
            .restrictToDevice = activeActionSet.restrictToDevice,
            .secondaryActionSet = activeActionSet.secondaryActionSet,
            .padding = 0,
            .priority = actionSetSize == sizeof(openvr::ActiveActionSet) ? activeActionSet.priority : 0
        };
        activeActionSetsCopy.push_back(activeActionSetCopy);
        if (activeActionSetCopy.priority > highestPriority)
        {
            highestPriority = activeActionSetCopy.priority;
        }
        TRACE_F("action set %d %d %d %d", activeActionSetCopy.actionSet, activeActionSetCopy.restrictToDevice, activeActionSetCopy.secondaryActionSet, activeActionSetCopy.priority);
    }

    std::unordered_set<int> usedInputs;
    for (int priority = highestPriority; priority >= 0; priority--)
    {
        std::unordered_set<int> usedInputsCopy = usedInputs;

        for (const openvr::ActiveActionSet& activeActionSet: activeActionSetsCopy)
        {
            if (activeActionSet.priority != priority)
            {
                continue;
            }

            int controllerFilter = activeActionSet.restrictToDevice != 0 ? getDeviceFromInputSourcePath(pathHandleRegistry.getPath(activeActionSet.restrictToDevice), false) : 0;
            ActionSet* actionSet = activeActionSet.actionSet != 0 ? this->findActionSet(pathHandleRegistry.getPath(activeActionSet.actionSet)) : nullptr;
            ActionSet* secondaryActionSet = controllerFilter != 0 && activeActionSet.secondaryActionSet != 0 ? this->findActionSet(pathHandleRegistry.getPath(activeActionSet.secondaryActionSet)) : nullptr;

            if (actionSet != nullptr)
            {
                for (auto& it: actionSet->actions)
                {
                    Action* action = it.second;

                    for (Action::Source& source: action->sources)
                    {
                        if (controllerFilter == 0 || source.device == controllerFilter)
                        {
                            source.active = true;
                            if (checkConsumedInput(usedInputsCopy, source.openVRInputIndexes))
                            {
                                std::vector<vapor::OpenVRInputState> collectedInputStates;
                                for (int index: source.openVRInputIndexes)
                                {
                                    collectedInputStates.push_back(inputStates[index]);
                                }
                                InputState inputState = convertInputType(source.binding->update(collectedInputStates), action->type);
                                if (hasInputStateChanged(source.inputState, inputState))
                                {
                                    source.inputState = inputState;
                                }
                                markConsumedInput(usedInputs, source.openVRInputIndexes);
                            }
                        }
                    }

                    for (Action::PoseSource& poseSource: action->poseSources)
                    {
                        if (controllerFilter == 0 || poseSource.device == controllerFilter)
                        {
                            if (!usedInputsCopy.contains(poseSource.openVRInputIndex))
                            {
                                poseSource.active = true;
                                poseSource.pose = inputStates[poseSource.openVRInputIndex].data.pose;
                                usedInputs.insert(poseSource.openVRInputIndex);
                            }
                        }
                    }
                }
            }

            if (secondaryActionSet != nullptr)
            {
                for (auto& it: secondaryActionSet->actions)
                {
                    Action* action = it.second;

                    for (Action::Source& source: action->sources)
                    {
                        if (source.device != controllerFilter)
                        {
                            source.active = true;
                            if (checkConsumedInput(usedInputsCopy, source.openVRInputIndexes))
                            {
                                std::vector<vapor::OpenVRInputState> collectedInputStates;
                                for (int index: source.openVRInputIndexes)
                                {
                                    collectedInputStates.push_back(inputStates[index]);
                                }
                                InputState inputState = convertInputType(source.binding->update(collectedInputStates), action->type);
                                if (hasInputStateChanged(source.inputState, inputState))
                                {
                                    source.inputState = inputState;
                                }
                                markConsumedInput(usedInputs, source.openVRInputIndexes);
                            }
                        }
                    }

                    for (Action::PoseSource& poseSource: action->poseSources)
                    {
                        if (poseSource.device != controllerFilter)
                        {
                            if (!usedInputsCopy.contains(poseSource.openVRInputIndex))
                            {
                                poseSource.active = true;
                                poseSource.pose = inputStates[poseSource.openVRInputIndex].data.pose;
                                usedInputs.insert(poseSource.openVRInputIndex);
                            }
                        }
                    }
                }
            }
        }
    }
}

ActionSet* ActionManager::findActionSet(const std::string& name)
{
    auto it = this->actionSets.find(stringToLowercase(name));
    if (it == this->actionSets.end())
    {
        return nullptr;
    }
    return &it->second;
}

Action* ActionManager::findAction(const std::string& name)
{
    auto it = this->actions.find(stringToLowercase(name));
    if (it == this->actions.end())
    {
        return nullptr;
    }
    return &it->second;
}
