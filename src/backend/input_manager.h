#pragma once

#include "input/action_manager.h"
#include "input_profile.h"
#include "legacy_input.h"

#include <vector>
#include <mutex>

namespace vapor
{
    class EventQueue;

    class InputManager
    {
        public:
            InputManager(input_profile::InputProfile* inputProfile);
            ~InputManager();

            void putCurrentInputStates(const std::vector<input_profile::OpenVRInputState>& inputStates);
            const std::vector<input_profile::OpenVRInputState>& getInputStates();

            void setSceneActionManager(input::ActionManager* actionManager);
            input::ActionManager* getSceneActionManager();

            void updateLegacyInputStateAndEmitEvents(EventQueue& eventQueue, long currentTime);
            LegacyInputState& getLegacyInputState(int controllerIndex);

        private:
            input_profile::InputProfile* const inputProfile;

            std::recursive_mutex mutex;

            std::vector<input_profile::OpenVRInputState> currentInputStates;

            input::ActionManager* sceneActionManager = nullptr;

            //input::ActionManager* legacyInputActionManager = nullptr;
            LegacyInputState legacyInputStates[2];
    };
}
