#pragma once

#include <string>
#include <map>
#include <cstdint>

#include "../../types_input.h"
#include "../../../backend/input.h"
#include "../../../backend/input_profile.h"
#include "input_devices.h"

namespace openvr
{
    namespace input
    {
        class ActionManager;

        class Action
        {
            friend class ActionManager;

            public:
                vapor::InputState getCapturedInputState(int device);
                vapor::InputState getPreviousCapturedInputState(int device);

                Action(vapor::InputType type);

                const vapor::InputType type;

            private:
                std::map<int, int> inputBindings;
                std::map<int, vapor::InputState> capturedInputStates;
                std::map<int, vapor::InputState> capturedInputStatesPrevious;
        };

        class ActionSet
        {
            friend class ActionManager;

            public:
                //

            private:
                std::map<std::string, Action*> actions;
        };

        class ActionManager
        {
            public:
                ActionManager();
                ~ActionManager();

                bool populateFromJSON(const std::string& filePath);

                void loadBinding(const std::string& filePath, vapor::InputProfile* inputProfile);
                void loadDefaultBindingForControllerProfile(const std::string& profileName, vapor::InputProfile* inputProfile);

                static void update(const ActiveActionSet* activeActionSets, int actionSetSize, int activeActionSetsCount, const vapor::InputState* inputStates);

                ActionSet* findActionSet(const std::string& name);
                Action* findAction(const std::string& name);

            private:
                std::map<std::string, ActionSet> actionSets;
                std::map<std::string, Action> actions;

                std::map<std::string, std::string> defaultBindingFilePaths;
        };
    }
}
