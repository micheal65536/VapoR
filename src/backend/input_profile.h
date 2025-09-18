#pragma once

#include "pose_set.h"
#include "legacy_input.h"

#include <string>

namespace vapor
{
    namespace input_profile
    {
        enum class OpenXRInputType
        {
            NONE,
            BOOLEAN,
            FLOAT,
            VECTOR2,
            POSE,
            HAPTIC
        };

        struct OpenXRInputDescription
        {
            std::string path;
            OpenXRInputType type;
        };

        enum class OpenVRInputType
        {
            NONE,
            BOOLEAN,
            FLOAT,
            POSE,
            SKELETON,
            HAPTIC
        };

        struct OpenVRInputDescription
        {
            std::string path;
            OpenVRInputType type;
        };

        struct OpenXRInputState
        {
            union Data
            {
                bool b;
                float f;
                XrVector2f vec2;
                PoseSet pose;
            };

            OpenXRInputType type;
            Data data;
            long changeTime;
        };

        struct OpenVRInputState
        {
            union Data
            {
                bool b;
                float f;
                PoseSet pose;
            };

            OpenVRInputType type;
            Data data;
            long changeTime;
        };

        enum class OpenVRProfileInputType
        {
            NONE,
            BUTTON,
            TRIGGER,
            JOYSTICK,
            TRACKPAD,
            POSE,
            SKELETON,
            HAPTIC
        };

        struct OpenVRProfileInputDescription
        {
            std::string path;
            OpenVRProfileInputType type;
            bool click;
            bool touch;
            bool value;
        };

        class InputProfile
        {
            public:
                virtual ~InputProfile() = default;

                virtual std::string getOpenXRInteractionProfileName() = 0;
                virtual int getOpenXRInputsCount() = 0;
                virtual const OpenXRInputDescription* getOpenXRInputs() = 0;

                virtual std::string getOpenVRProfileName() = 0;
                virtual int getOpenVRInputsCount() = 0;
                virtual const OpenVRInputDescription* getOpenVRInputs() = 0;
                virtual int getOpenVRProfileInputsCount() = 0;
                virtual const OpenVRProfileInputDescription* getOpenVRProfileInputs() = 0;
                virtual LegacyInputDescription getOpenVRLegacyInputDescription() = 0;

                virtual OpenVRInputState getOpenVRInputState(int inputIndex, const OpenXRInputState* openXRInputStates) = 0;
                virtual OpenVRInputState getOpenVRControllerPose(int controllerIndex, const OpenVRInputState* openVRInputStates) = 0;
                virtual LegacyInputState getOpenVRLegacyInputState(int controllerIndex, const OpenVRInputState* openVRInputStates) = 0;

                virtual int getOpenXRHapticActionIndex(int openVRInputIndex) = 0;
                virtual int getOpenXRHapticActionIndexForLegacyInput(int controllerIndex) = 0;
        };
    }
}
