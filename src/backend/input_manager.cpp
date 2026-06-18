#include "input_manager.h"

#include "log/log.h"

#include "event_queue.h"

#include "openvr/types_input.h"

using namespace vapor;

InputManager::InputManager(input_profile::InputProfile* inputProfile): inputProfile(inputProfile)
{
    // empty
}

InputManager::~InputManager()
{
    // TODO
    //delete legacyInputActionManager;
    delete sceneActionManager;
}

void InputManager::putCurrentInputStates(const std::vector<input_profile::OpenVRInputState>& inputStates)
{
    mutex.lock();
    currentInputStates = inputStates;
    mutex.unlock();
}

const std::vector<input_profile::OpenVRInputState>& InputManager::getInputStates()
{
    std::unique_lock<std::recursive_mutex> lock(mutex);
    return currentInputStates;
}

bool InputManager::createSceneActionManager(const std::string& manifestPath)
{
    std::unique_lock<std::recursive_mutex> lock(mutex);

    input::ActionManager* actionManager = new input::ActionManager();
    if (!actionManager->populateFromJSON(manifestPath))
    {
        LOG("Failed to read actions from %s", manifestPath.c_str());
        return false;
    }
    else
    {
        LOG("Read actions from %s", manifestPath.c_str());

        if (actionManager->loadBinding("vapor_binding.json", inputProfile))
        {
            LOG("Loaded custom binding");
        }
        else
        {
            LOG("Failed to load custom binding, trying default binding");
            actionManager->loadDefaultBindingForControllerProfile(inputProfile);
        }

        delete sceneActionManager;
        sceneActionManager = actionManager;

        return true;
    }
}

/*void InputManager::setSceneActionManager(input::ActionManager* actionManager)
{
    mutex.lock();
    sceneActionManager = actionManager;
    mutex.unlock();
}*/

input::ActionManager* InputManager::getSceneActionManager()
{
    std::unique_lock<std::recursive_mutex> lock(mutex);
    return sceneActionManager;
}

//

void InputManager::updateLegacyInputStateAndEmitEvents(EventQueue& eventQueue, long currentTime)
{
    std::unique_lock<std::recursive_mutex> lock(mutex);

    if (sceneActionManager != nullptr)
    {
        return;
    }

    // TODO: reimplement legacy input handling using action manager
    for (int controllerIndex = 0; controllerIndex < 2; controllerIndex++)
    {
        LegacyInputState state = this->inputProfile->getOpenVRLegacyInputState(controllerIndex, currentInputStates.data());
        LegacyInputState previousState = this->legacyInputStates[controllerIndex];
        state.packetNum = previousState.packetNum + 1; // TODO

        const PoseSet& controllerPose = this->inputProfile->getOpenVRControllerPose(controllerIndex, currentInputStates.data()).data.pose;
        LegacyInputHelper::compareStatesAndEmitChangeEvents(eventQueue, controllerPose, controllerIndex, previousState, state);

        this->legacyInputStates[controllerIndex] = state;
    }
}

LegacyInputState& InputManager::getLegacyInputState(int controllerIndex)
{
    std::unique_lock<std::recursive_mutex> lock(mutex);
    return legacyInputStates[controllerIndex];
}
