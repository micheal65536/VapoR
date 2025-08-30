#pragma once

#include "backend/input.h"
#include "backend/input_profile.h"
#include "input_state.h"

#include <vector>
#include <string>
#include <optional>

#include <nlohmann/json.hpp>

namespace openvr
{
    namespace input
    {
        class Mode
        {
            public:
                struct ComponentDescription
                {
                    std::string subpath;
                    vapor::OpenVRInputType type;
                };

                virtual std::vector<std::string> getProvidedOutputNames() = 0;
                virtual std::vector<int> connect(const std::vector<ComponentDescription>& availableComponents, const bool* connectedOutputs) = 0;
                virtual std::vector<InputState> getInitialStates(const uint64_t* inputSourceHandles) = 0;
                virtual std::vector<InputState> update(const InputState* inputStates, long currentTime) = 0;

            protected:
                public: // fuck C++
                enum class ForceInput
                {
                    NONE,
                    CLICK,
                    TOUCH,
                    POSITION,
                    FORCE
                };
                protected:

                class Hysteresis
                {
                    public:
                        struct Thresholds
                        {
                            float on;
                            float off;

                            static const Thresholds CLICK_DEFAULT;
                            static const Thresholds TOUCH_DEFAULT;
                            static const Thresholds STICKY_DEFAULT;
                        };

                        Hysteresis() = default;
                        Hysteresis(const Thresholds& thresholds): thresholds(thresholds) {}

                        inline bool update(float value)
                        {
                            return currentState = currentState ? (value >= thresholds.off) : (value >= thresholds.on);
                        }

                    private:
                        Thresholds thresholds;
                        bool currentState;
                };

                class ClickFilter
                {
                    public:
                        enum class Source
                        {
                            BASE,
                            CLICK,
                            TOUCH,
                            VALUE,
                            FORCE,
                            POSITION
                        };

                        enum class DefaultThresholdsType
                        {   
                            CLICK,
                            TOUCH
                        };

                        bool tryGrab(Source source, DefaultThresholdsType defaultThresholdsType, std::optional<float> activateThresholdOverride, std::optional<float> deactivateThresholdOverride, const std::vector<ComponentDescription>& availableComponents, std::vector<int>& grabbedComponents);
                        void grabNone(std::vector<int>& grabbedComponents);
                        InputState getInitialState(const uint64_t*& inputSourceHandles);
                        InputState update(const InputState*& inputStates, long currentTime);

                    private:
                        bool convertFromScalar;
                        bool convertFromVector;
                        Hysteresis hysteresis;
                        bool currentState = false;
                        long currentStateChangeTime = 0;
                };

                class LatchingClickFilter
                {
                    public:
                        bool tryGrab(ClickFilter::Source source, ClickFilter::DefaultThresholdsType defaultThresholdsType, std::optional<float> activateThresholdOverride, std::optional<float> deactivateThresholdOverride, bool touchy, bool sticky, std::optional<float> stickyActivateThresholdOverride, std::optional<float> stickyDeactivateThresholdOverride, const std::vector<ComponentDescription>& availableComponents, std::vector<int>& grabbedComponents);
                        void grabNone(std::vector<int>& grabbedComponents);
                        InputState getInitialState(const uint64_t*& inputSourceHandles);
                        InputState update(const InputState*& inputStates, long currentTime);

                    private:
                        bool touchy;
                        bool sticky;
                        ClickFilter click;
                        bool currentState = false;
                        long currentChangeTime = 0;
                        Hysteresis positionHysteresis;
                        bool positionState = false;
                };

                class BasicButtonFilter
                {
                    public:
                        void readParameters(const nlohmann::json::object_t& paramters);
                        bool tryGrabClick(ClickFilter::Source source, const std::vector<ComponentDescription>& availableComponents, std::vector<int>& grabbedComponents);
                        void grabClickNone(std::vector<int>& grabbedComponents);
                        bool tryGrabTouch(ClickFilter::Source source, const std::vector<ComponentDescription>& availableComponents, std::vector<int>& grabbedComponents);
                        void grabTouchNone(std::vector<int>& grabbedComponents);
                        InputState getInitialClickState(const uint64_t*& inputSourceHandles);
                        InputState getInitialTouchState(const uint64_t*& inputSourceHandles);
                        InputState updateClick(const InputState*& inputStates, long currentTime);
                        InputState updateTouch(const InputState*& inputStates, long currentTime);

                        ForceInput forceInput = ForceInput::NONE;
                        std::optional<float> clickActivateThreshold;
                        std::optional<float> clickDeactivateThreshold;
                        std::optional<float> touchActivateThreshold;
                        std::optional<float> touchDeactivateThreshold;
                        bool touchyClick = false;
                        bool stickyClick = false;
                        std::optional<float> stickyActivateThreshold;
                        std::optional<float> stickyDeactivateThreshold;

                    private:
                        LatchingClickFilter click;
                        ClickFilter touch;
                };
        };

        //

        class ButtonMode: public Mode
        {
            public:
                ButtonMode(const nlohmann::json::object_t& parameters);
                virtual std::vector<std::string> getProvidedOutputNames();
                virtual std::vector<int> connect(const std::vector<ComponentDescription>& availableComponents, const bool* connectedOutputs);
                virtual std::vector<InputState> getInitialStates(const uint64_t* inputSourceHandles);
                virtual std::vector<InputState> update(const InputState* inputStates, long currentTime);

            private:
                static const long LONG_PRESS_TIMEOUT = 1000000000;
                static const long DOUBLE_PRESS_TIMEOUT = 250000000;

                BasicButtonFilter button;
                bool advancedOutput;

                bool clickState = false;
                long clickChangeTime = 0;
                bool clickFireOnNextUpdate = false;
                bool longPressState = false;
                long longPressChangeTime = 0;
                bool doublePressState = false;
                long doublePressChangeTime = 0;
                bool doublePressTestState = false;
                long doublePressPreviousPressTime = -1;
                bool heldState = false;
                long heldChangeTime = 0;
        };

        class TriggerMode: public Mode
        {
            public:
                TriggerMode(const nlohmann::json::object_t& parameters);
                virtual std::vector<std::string> getProvidedOutputNames();
                virtual std::vector<int> connect(const std::vector<ComponentDescription>& availableComponents, const bool* connectedOutputs);
                virtual std::vector<InputState> getInitialStates(const uint64_t* inputSourceHandles);
                virtual std::vector<InputState> update(const InputState* inputStates, long currentTime);

            private:
                BasicButtonFilter button;
        };

        class JoystickMode: public Mode
        {
            public:
                JoystickMode(const nlohmann::json::object_t& parameters);
                virtual std::vector<std::string> getProvidedOutputNames();
                virtual std::vector<int> connect(const std::vector<ComponentDescription>& availableComponents, const bool* connectedOutputs);
                virtual std::vector<InputState> getInitialStates(const uint64_t* inputSourceHandles);
                virtual std::vector<InputState> update(const InputState* inputStates, long currentTime);

            private:
                bool invertX;
                bool invertY;
                float deadZone = 0.0f;
                float maxZone = 1.0f;
                float exponent = 1.0f;

                BasicButtonFilter button;
        };

        class TrackpadMode: public JoystickMode
        {
            // currently haven't observed any difference between joystick and trackpad mode

            public:
                TrackpadMode(const nlohmann::json::object_t& parameters): JoystickMode(parameters) {}
        };

        class DpadMode: public Mode
        {
            public:
                DpadMode(const nlohmann::json::object_t& parameters, vapor::OpenVRProfileInputType profileInputType);
                virtual std::vector<std::string> getProvidedOutputNames();
                virtual std::vector<int> connect(const std::vector<ComponentDescription>& availableComponents, const bool* connectedOutputs);
                virtual std::vector<InputState> getInitialStates(const uint64_t* inputSourceHandles);
                virtual std::vector<InputState> update(const InputState* inputStates, long currentTime);

            private:
                enum class SubMode
                {
                    TOUCH,
                    CLICK
                };
                SubMode subMode;
                float deadZone = 0.25f;
                float overlap = 0.5f;
                bool sticky = false;
                ForceInput clickForceInput = ForceInput::NONE;
                std::optional<float> clickActivateThreshold;
                std::optional<float> clickDeactivateThreshold;
                bool isJoystick;

                bool forceInactive;
                ClickFilter click;
                long lastClickChangeTime = 0;
                float lastX = 0.0f;
                float lastY = 0.0f;
                uint64_t lastPositionInputSourceHandle;
                long lastPositionChangeTime = 0;

                uint64_t outputInputSourceHandle;
                struct DpadOutput
                {
                    bool state = false;
                    long changeTime = 0;

                    void configure(float deadZone, float overlap);
                    bool update(float x, float y);

                    private:
                        float deadZone;
                        float overlap;
                };
                DpadOutput north;
                DpadOutput east;
                DpadOutput south;
                DpadOutput west;
                DpadOutput center;
        };

        /*class ScrollMode: public Mode
        {
            public:
                ScrollMode(const nlohmann::json::object_t& parameters, vapor::OpenVRProfileInputType profileInputType);
                virtual std::vector<std::string> getProvidedOutputNames();
                virtual std::vector<int> connect(const std::vector<ComponentDescription>& availableComponents, const bool* connectedOutputs);
                virtual std::vector<InputState> getInitialStates(const uint64_t* inputSourceHandles);
                virtual std::vector<InputState> update(const InputState* inputStates, long currentTime);

            private:
                // TODO
        };*/

        class ToggleButtonMode: public Mode
        {
            public:
                ToggleButtonMode(const nlohmann::json::object_t& parameters);
                virtual std::vector<std::string> getProvidedOutputNames();
                virtual std::vector<int> connect(const std::vector<ComponentDescription>& availableComponents, const bool* connectedOutputs);
                virtual std::vector<InputState> getInitialStates(const uint64_t* inputSourceHandles);
                virtual std::vector<InputState> update(const InputState* inputStates, long currentTime);

            private:
                bool clickInitialState;
                bool touchInitialState;

                BasicButtonFilter button;
                bool enableTouchOutput;
                bool touchOutputIsClick;

                bool lastClickState = false;
                bool lastTouchState = false;
                bool currentClickState = false;
                long currentClickStateChangeTime = 0;
                bool currentTouchState = false;
                long currentTouchStateChangeTime = 0;
        };

        class ScalarConstantMode: public Mode
        {
            public:
                ScalarConstantMode(const nlohmann::json::object_t& parameters);
                virtual std::vector<std::string> getProvidedOutputNames();
                virtual std::vector<int> connect(const std::vector<ComponentDescription>& availableComponents, const bool* connectedOutputs);
                virtual std::vector<InputState> getInitialStates(const uint64_t* inputSourceHandles);
                virtual std::vector<InputState> update(const InputState* inputStates, long currentTime);

            private:
                float onX;
                float onY;
                float offX;
                float offY;

                BasicButtonFilter button;
                bool currentState = false;
                long currentStateChangeTime = 0;
        };

        class ForceSensorMode: public Mode
        {
            public:
                ForceSensorMode(const nlohmann::json::object_t& parameters);
                virtual std::vector<std::string> getProvidedOutputNames();
                virtual std::vector<int> connect(const std::vector<ComponentDescription>& availableComponents, const bool* connectedOutputs);
                virtual std::vector<InputState> getInitialStates(const uint64_t* inputSourceHandles);
                virtual std::vector<InputState> update(const InputState* inputStates, long currentTime);
        };

        // TODO: "grab" mode - needs investigation, has parameters "force_hold_threshold" and "force_release_threshold"

        // TODO: "radial" mode???

        // TODO: investigate Knuckles "pinch" input - has type "pinch"???

        // TODO: check if there are any other modes that we're missing
    }
}
