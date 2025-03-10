#pragma once

#include <string>
#include <map>
#include <vector>
#include <cstdint>

#include "openvr/types_input.h"
#include "backend/input.h"
#include "backend/input_profile.h"
#include "input_devices.h"
#include "binding.h"
#include "input_state.h"

namespace openvr
{
    namespace input
    {
        class ActionManager;

        class Action
        {
            friend class ActionManager;

            public:
                Action(InputType type);

                const InputType type;

                struct Source
                {
                    Binding* binding;
                    Device device;
                    std::vector<int> openVRInputIndexes;

                    bool active;
                    bool activePrevious;
                    InputState inputState;
                    InputState inputStatePrevious;
                };
                struct PoseSource
                {
                    Device device;
                    int openVRInputIndex;
                    uint64_t inputSourceHandle;

                    bool active;
                    vapor::PoseSet pose;
                };
                struct HapticOutput
                {
                    Device device;
                    int openVRInputIndex;
                    uint64_t inputSourceHandle;
                };

                // only one of these is used, depending on the action type
                std::vector<Source> sources;
                std::vector<PoseSource> poseSources;
                std::vector<HapticOutput> hapticOutputs;
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

                bool loadBinding(const std::string& filePath, vapor::InputProfile* inputProfile);
                void loadDefaultBindingForControllerProfile(vapor::InputProfile* inputProfile);

                void update(const ActiveActionSet* activeActionSets, int actionSetSize, int activeActionSetsCount, const vapor::OpenVRInputState* inputStates);

                ActionSet* findActionSet(const std::string& name);
                Action* findAction(const std::string& name);

            private:
                std::map<std::string, ActionSet> actionSets;
                std::map<std::string, Action> actions;

                std::map<std::string, std::string> defaultBindingFilePaths;
        };
    }
}
