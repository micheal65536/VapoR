#pragma once

#include "backend/input.h"
#include "backend/input_profile.h"
#include "input_state.h"

#include <vector>
#include <string>

namespace openvr
{
    namespace input
    {
        class Binding
        {
            public:
                virtual std::vector<int> bindToProfile(vapor::OpenVRInputType inputType, const std::string& basePath, const vapor::OpenVRInputDescription* profileInputs, int profileInputsCount) = 0;
                virtual InputState getInitialState() = 0;
                virtual InputState update(const std::vector<vapor::OpenVRInputState>& inputStates) = 0;

            protected:
                int findOpenVRInput(const std::string& basePath, vapor::OpenVRInputSubpath subpath, const vapor::OpenVRInputDescription* profileInputs, int profileInputsCount);
        };

        class ButtonBinding: public Binding
        {
            public:
                // TODO: long press/hold/double press/etc. inputs
                enum Input
                {
                    CLICK,
                    TOUCH
                };

                ButtonBinding(Input input): input(input) {};
                virtual std::vector<int> bindToProfile(vapor::OpenVRInputType inputType, const std::string& basePath, const vapor::OpenVRInputDescription* profileInputs, int profileInputsCount);
                virtual InputState getInitialState();
                virtual InputState update(const std::vector<vapor::OpenVRInputState>& inputStates);

            private:
                Input input;
                uint64_t inputSourceHandle;
                bool convertFromFloat;
        };

        class TriggerBinding: public Binding
        {
            public:
                enum Input
                {
                    PULL,
                    CLICK,
                    TOUCH
                };

                TriggerBinding(Input input): input(input) {};
                virtual std::vector<int> bindToProfile(vapor::OpenVRInputType inputType, const std::string& basePath, const vapor::OpenVRInputDescription* profileInputs, int profileInputsCount);
                virtual InputState getInitialState();
                virtual InputState update(const std::vector<vapor::OpenVRInputState>& inputStates);

            private:
                Input input;
                uint64_t inputSourceHandle;
                bool convertFromFloat;
        };

        class JoystickBinding: public Binding
        {
            public:
                enum Input
                {
                    POSITION,
                    CLICK,
                    TOUCH
                };

                JoystickBinding(Input input): input(input) {};
                virtual std::vector<int> bindToProfile(vapor::OpenVRInputType inputType, const std::string& basePath, const vapor::OpenVRInputDescription* profileInputs, int profileInputsCount);
                virtual InputState getInitialState();
                virtual InputState update(const std::vector<vapor::OpenVRInputState>& inputStates);

            private:
                Input input;
                uint64_t inputSourceHandle;
        };

        class DpadBinding: public Binding
        {
            public:
                enum Input
                {
                    NORTH,
                    EAST,
                    SOUTH,
                    WEST,
                    CENTER
                };

                DpadBinding(Input input, bool click): input(input), click(click) {};
                virtual std::vector<int> bindToProfile(vapor::OpenVRInputType inputType, const std::string& basePath, const vapor::OpenVRInputDescription* profileInputs, int profileInputsCount);
                virtual InputState getInitialState();
                virtual InputState update(const std::vector<vapor::OpenVRInputState>& inputStates);

            private:
                Input input;
                bool click;
                uint64_t positionInputSourceHandle;
                uint64_t clickInputSourceHandle;
        };

        // TODO: toggle binding

        // TODO: scalar_constant binding

        // TODO: check if there are any others that we're missing
    }
}
