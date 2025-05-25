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

static inline InputState convertInputType(const InputState& inputState, const InputType& inputType)
{
    if (inputState.type == inputType)
    {
        return inputState;
    }
    if (inputState.type == InputType::EMPTY)
    {
        return inputState;
    }
    switch (inputType)
    {
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
    return InputState {
        .type = InputType::EMPTY
    };
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
        action.sources.clear();
        action.poseSources.clear();
        action.hapticOutputs.clear();
    }
    for (auto& it: this->actionSets)
    {
        ActionSet& actionSet = it.second;
        for (ActionSet::Source& source: actionSet.sources)
        {
            delete source.mode;
        }
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
            ActionSet* actionSet = this->findActionSet(actionSetName);
            if (actionSet == nullptr)
            {
                LOG("Action set %s does not exist", actionSetName.c_str());
                continue;
            }

            if (it.value().contains("sources"))
            {
                actionSet->sources.reserve(it.value().at("sources").size());

                for (const auto& source: it.value().at("sources"))
                {
                    const std::string& basePath = stringToLowercase(source.at("path"));
                    std::vector<Mode::ComponentDescription> components;
                    std::vector<int> componentInputIndexes;
                    for (int i = 0; i < inputProfile->getOpenVRInputsCount(); i++)
                    {
                        const vapor::OpenVRInputDescription& inputDescription = inputProfile->getOpenVRInputs()[i];
                        if (inputDescription.path == basePath || inputDescription.path.starts_with(basePath + "/"))
                        {
                            std::string subpath = inputDescription.path == basePath ? "" : inputDescription.path.substr(basePath.length() + 1);
                            components.push_back({.subpath = subpath, .type = inputDescription.type});
                            componentInputIndexes.push_back(i);
                        }
                    }
                    vapor::OpenVRProfileInputType profileInputType = vapor::OpenVRProfileInputType::NONE;
                    for (int i = 0; i < inputProfile->getOpenVRProfileInputsCount(); i++)
                    {
                        const vapor::OpenVRProfileInputDescription& inputDescription = inputProfile->getOpenVRProfileInputs()[i];
                        if (inputDescription.path == basePath)
                        {
                            profileInputType = inputDescription.type;
                            break;
                        }
                    }

                    Mode* mode;
                    const std::string& modeName = stringToLowercase(source.at("mode"));
                    json::object_t parameters = source.contains("parameters") ? source.at("parameters") : json::object();
                    if (modeName == "button")
                    {
                        mode = new ButtonMode(parameters);
                    }
                    else if (modeName == "trigger")
                    {
                        mode = new TriggerMode(parameters);
                    }
                    else if (modeName == "joystick")
                    {
                        mode = new JoystickMode(parameters);
                    }
                    else if (modeName == "trackpad")
                    {
                        mode = new TrackpadMode(parameters);
                    }
                    else if (modeName == "dpad")
                    {
                        mode = new DpadMode(parameters, profileInputType);
                    }
                    /*else if (modeName == "scroll")
                    {
                        mode = new ScrollMode(parameters, profileInputType);
                    }*/
                    else if (modeName == "toggle_button")
                    {
                        mode = new ToggleButtonMode(parameters);
                    }
                    else if (modeName == "scalar_constant")
                    {
                        mode = new ScalarConstantMode(parameters);
                    }
                    else if (modeName == "force_sensor")
                    {
                        mode = new ForceSensorMode(parameters);
                    }
                    else
                    {
                        LOG("Unknown source mode %s", modeName.c_str());
                        continue;
                    }

                    std::map<std::string, Action*> connectedModeOutputs;
                    for (const auto& input: source.at("inputs").items())
                    {
                        const std::string& actionName = stringToLowercase(input.value().at("output"));
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

                        const std::string& inputName = stringToLowercase(input.key());
                        connectedModeOutputs[inputName] = action;
                    }

                    const std::vector<std::string>& modeOutputs = mode->getProvidedOutputNames();
                    bool connectedOutputs[modeOutputs.size()];
                    for (int i = 0; i < modeOutputs.size(); i++)
                    {
                        connectedOutputs[i] = connectedModeOutputs.contains(modeOutputs[i]);
                    }
                    std::vector<int> modeGrabbedComponentIndexes = mode->connect(components, connectedOutputs);

                    std::vector<ActionSet::Source::OpenVRInput> openVRInputs;
                    uint64_t inputSourceHandles[modeGrabbedComponentIndexes.size()];
                    for (int i = 0; i < modeGrabbedComponentIndexes.size(); i++)
                    {
                        int componentIndex = modeGrabbedComponentIndexes[i];
                        if (componentIndex != -1)
                        {
                            int inputIndex = componentInputIndexes[componentIndex];
                            uint64_t inputSourceHandle = pathHandleRegistry.getHandle(inputProfile->getOpenVRInputs()[inputIndex].path);
                            openVRInputs.push_back(ActionSet::Source::OpenVRInput {
                                .inputIndex = inputIndex,
                                .inputSourceHandle = inputSourceHandle
                            });
                            inputSourceHandles[i] = inputSourceHandle;
                        }
                        else
                        {
                            openVRInputs.push_back(ActionSet::Source::OpenVRInput {
                                .inputIndex = -1,
                                .inputSourceHandle = 0
                            });
                            inputSourceHandles[i] = 0;
                        }
                    }

                    ActionSet::Source actionSetSource {
                        .mode = mode,
                        .device = getDeviceFromInputSourcePath(basePath, true),
                        .openVRInputs = openVRInputs,

                        .inputStates = mode->getInitialStates(inputSourceHandles)
                    };
                    actionSet->sources.push_back(actionSetSource);
                    for (int i = 0; i < modeOutputs.size(); i++)
                    {
                        const std::string& name = modeOutputs[i];
                        if (connectedOutputs[i] && connectedModeOutputs.contains(name))
                        {
                            Action* action = connectedModeOutputs[name];
                            if (action != nullptr)
                            {
                                Action::Source source {
                                    .source = &actionSet->sources.back(),
                                    .sourceOutputIndex = i,
                                    .device = actionSetSource.device,

                                    .inputState = actionSetSource.inputStates[i],
                                    .inputStatePrevious = actionSetSource.inputStates[i]
                                };
                                action->sources.push_back(source);
                            }
                        }
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

static inline InputState convertOpenVRInputState(const vapor::OpenVRInputState& inputState, uint64_t inputSourceHandle)
{
    switch (inputState.type)
    {
        case vapor::OpenVRInputType::BOOLEAN:
            return InputState {
                .type = InputType::DIGITAL,
                .data = {.digital = inputState.data.b},
                .inputSourceHandle = inputSourceHandle,
                .changeTime = inputState.changeTime
            };
        case vapor::OpenVRInputType::FLOAT:
            return InputState {
                .type = InputType::ANALOG,
                .data = {.analog = {inputState.data.f, 0.0f, 0.0f}},
                .inputSourceHandle = inputSourceHandle,
                .changeTime = inputState.changeTime
            };
    }
    return InputState {
        .type = InputType::EMPTY,
        .inputSourceHandle = inputSourceHandle
    };
}

void ActionManager::update(const openvr::ActiveActionSet* activeActionSets, int actionSetSize, int activeActionSetsCount, const vapor::OpenVRInputState* inputStates, long currentTime)
{
    TRACE_F("%d", activeActionSetsCount);

    for (auto& it: this->actions)
    {
        Action& action = it.second;
        for (Action::Source& source: action.sources)
        {
            source.inputStatePrevious = source.inputState;
            source.inputState = InputState {.type = InputType::EMPTY};
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
                for (ActionSet::Source& source: actionSet->sources)
                {
                    if (controllerFilter == 0 || source.device == controllerFilter)
                    {
                        std::vector<InputState> collectedInputStates;
                        for (const ActionSet::Source::OpenVRInput& sourceInput: source.openVRInputs)
                        {
                            if (sourceInput.inputIndex != -1 && !usedInputsCopy.contains(sourceInput.inputIndex))
                            {
                                collectedInputStates.push_back(convertOpenVRInputState(inputStates[sourceInput.inputIndex], sourceInput.inputSourceHandle));
                                usedInputs.insert(sourceInput.inputIndex);
                            }
                            else
                            {
                                collectedInputStates.push_back({.type = InputType::EMPTY, .inputSourceHandle = sourceInput.inputSourceHandle});
                            }
                        }

                        source.inputStates = source.mode->update(collectedInputStates.data(), currentTime);
                    }
                }

                for (auto& it: actionSet->actions)
                {
                    Action* action = it.second;

                    for (Action::Source& source: action->sources)
                    {
                        if (controllerFilter == 0 || source.device == controllerFilter)
                        {
                            source.inputState = convertInputType(source.source->inputStates[source.sourceOutputIndex], action->type);
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
                for (ActionSet::Source& source: actionSet->sources)
                {
                    if (source.device != controllerFilter)
                    {
                        std::vector<InputState> collectedInputStates;
                        for (const ActionSet::Source::OpenVRInput& sourceInput: source.openVRInputs)
                        {
                            if (sourceInput.inputIndex != -1 && !usedInputsCopy.contains(sourceInput.inputIndex))
                            {
                                collectedInputStates.push_back(convertOpenVRInputState(inputStates[sourceInput.inputIndex], sourceInput.inputSourceHandle));
                                usedInputs.insert(sourceInput.inputIndex);
                            }
                            else
                            {
                                collectedInputStates.push_back({.type = InputType::EMPTY, .inputSourceHandle = sourceInput.inputSourceHandle});
                            }
                        }

                        source.inputStates = source.mode->update(collectedInputStates.data(), currentTime);
                    }
                }

                for (auto& it: secondaryActionSet->actions)
                {
                    Action* action = it.second;

                    for (Action::Source& source: action->sources)
                    {
                        if (source.device != controllerFilter)
                        {
                            source.inputState = convertInputType(source.source->inputStates[source.sourceOutputIndex], action->type);
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
