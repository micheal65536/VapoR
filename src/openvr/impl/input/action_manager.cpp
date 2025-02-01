#include "action_manager.h"

#include "log/stub.h"
#include "log/log.h"
#include "log/abort.h"

#include <algorithm>
#include <vector>
#include <unordered_set>
#include <cctype>

#include <nlohmann/json.hpp>
#include <fstream>

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

Action::Action(vapor::InputType type): type(type)
{
    // empty
}

static inline std::string stringToLowercase(const std::string& in)
{
    std::string out = in;
    std::transform(out.begin(), out.end(), out.begin(), [](char c){ return std::tolower(c); });
    return out;
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

            vapor::InputType inputType = vapor::InputType::NONE;
            if (type == "boolean")
            {
                inputType = vapor::InputType::BOOLEAN;
            }
            else if (type == "vector1")
            {
                inputType = vapor::InputType::FLOAT;
            }
            else if (type == "vector2")
            {
                inputType = vapor::InputType::VECTOR2;
            }
            else if (type == "vector3")
            {
                inputType = vapor::InputType::VECTOR3;
            }
            else if (type == "pose")
            {
                inputType = vapor::InputType::POSE;
            }
            else if (type == "skeleton")
            {
                inputType = vapor::InputType::SKELETON;
            }
            else if (type == "vibration")
            {
                inputType = vapor::InputType::HAPTIC;
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
                this->defaultBindingFilePaths[controllerType] = bindingUrl;
            }
        }

        return true;
    }
    catch (const std::exception& exception)
    {
        return false;
    }
}

void ActionManager::loadBinding(const std::string& filePath, vapor::InputProfile* inputProfile)
{
    TRACE_F("Loading bindings from %s", filePath.c_str());

    for (auto it: this->actions)
    {
        it.second.inputBindings.clear();
    }

    // TODO
    STUB();
}

void ActionManager::loadDefaultBindingForControllerProfile(const std::string& profileName, vapor::InputProfile* inputProfile)
{
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

void ActionManager::update(const openvr::ActiveActionSet* activeActionSets, int actionSetSize, int activeActionSetsCount, const vapor::InputState* inputStates)
{
    std::vector<openvr::ActiveActionSet> activeActionSetsCopy;
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
    }
    std::sort(activeActionSetsCopy.begin(), activeActionSetsCopy.end(), [](const openvr::ActiveActionSet& a, const openvr::ActiveActionSet& b){ return b.priority > a.priority; });

    std::unordered_set<int> usedInputs;
    for (const openvr::ActiveActionSet& activeActionSet: activeActionSetsCopy)
    {
        int controllerFilter = activeActionSet.restrictToDevice;
        ActionSet* actionSet = (ActionSet*) activeActionSet.actionSet;
        ActionSet* secondaryActionSet = controllerFilter != 0 ? (ActionSet*) activeActionSet.secondaryActionSet : nullptr;

        if (controllerFilter == 0)
        {
            for (auto it: actionSet->actions)
            {
                Action* action = it.second;

                for (int device = Device::HAND_LEFT; device <= Device::CAMERA; device++)
                {
                    action->capturedInputStatesPrevious[device] = action->capturedInputStates[device];
                    int binding = action->inputBindings.contains(device) ? action->inputBindings[device] : -1;
                    if (binding != -1 && !usedInputs.contains(binding))
                    {
                        usedInputs.insert(binding);
                        action->capturedInputStates[device] = inputStates[binding];
                    }
                    else
                    {
                        action->capturedInputStates[device] = {.type = vapor::InputType::NONE};
                    }
                }
            }
        }
        else
        {
            for (auto it: actionSet->actions)
            {
                Action* action = it.second;

                for (int device = Device::HAND_LEFT; device <= Device::CAMERA; device++)
                {
                    action->capturedInputStatesPrevious[device] = action->capturedInputStates[device];
                    int binding = action->inputBindings.contains(device) ? action->inputBindings[device] : -1;
                    if (controllerFilter == device && binding != -1 && !usedInputs.contains(binding))
                    {
                        usedInputs.insert(binding);
                        action->capturedInputStates[device] = inputStates[binding];
                    }
                    else
                    {
                        action->capturedInputStates[device] = {.type = vapor::InputType::NONE};
                    }
                }
            }

            if (secondaryActionSet != nullptr)
            {
                for (auto it: secondaryActionSet->actions)
                {
                    Action* action = it.second;

                    for (int device = Device::HAND_LEFT; device <= Device::CAMERA; device++)
                    {
                        action->capturedInputStatesPrevious[device] = action->capturedInputStates[device];
                        int binding = action->inputBindings.contains(device) ? action->inputBindings[device] : -1;
                        if (controllerFilter != device && binding != -1 && !usedInputs.contains(binding))
                        {
                            usedInputs.insert(binding);
                            action->capturedInputStates[device] = inputStates[binding];
                        }
                        else
                        {
                            action->capturedInputStates[device] = {.type = vapor::InputType::NONE};
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

vapor::InputState Action::getCapturedInputState(int device)
{
    return this->capturedInputStates.contains(device) ? this->capturedInputStates[device] : (vapor::InputState) {.type = vapor::InputType::NONE};
}

vapor::InputState Action::getPreviousCapturedInputState(int device)
{
    return this->capturedInputStatesPrevious.contains(device) ? this->capturedInputStatesPrevious[device] : (vapor::InputState) {.type = vapor::InputType::NONE};
}
