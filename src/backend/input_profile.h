#pragma once

#include "input.h"
#include "legacy_input.h"

namespace vapor
{
    class InputProfile
    {
        public:
            virtual std::string getOpenXRInteractionProfileName() = 0;
            virtual int getOpenXRInputsCount() = 0;
            virtual const OpenXRInputDescription* getOpenXRInputs() = 0;

            virtual std::string getOpenVRProfileName() = 0;
            virtual int getOpenVRInputsCount() = 0;
            virtual const OpenVRInputDescription* getOpenVRInputs() = 0;
            virtual LegacyInputDescription getOpenVRLegacyInputDescription() = 0;

            virtual InputState getOpenVRInputState(int inputIndex, const InputState* openXRInputStates) = 0;
            virtual InputState getOpenVRControllerPose(int controllerIndex, const InputState* openXRInputStates) = 0;
            virtual LegacyInputState getOpenVRLegacyInputState(int controllerIndex, const InputState* openXRInputStates) = 0;

            virtual int getOpenXRHapticActionIndex(int openVRInputIndex) = 0;
            virtual int getOpenXRHapticActionIndexForLegacyInput(int controllerIndex) = 0;
    };
}
