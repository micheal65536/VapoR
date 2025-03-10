#pragma once

#include "input.h"
#include "legacy_input.h"

#include <string>

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

            virtual OpenVRInputState getOpenVRInputState(int inputIndex, const OpenXRInputState* openXRInputStates) = 0;
            virtual OpenVRInputState getOpenVRControllerPose(int controllerIndex, const OpenVRInputState* openVRInputStates) = 0;
            virtual LegacyInputState getOpenVRLegacyInputState(int controllerIndex, const OpenXRInputState* openXRInputStates) = 0;

            virtual int getOpenXRHapticActionIndex(int openVRInputIndex) = 0;
            virtual int getOpenXRHapticActionIndexForLegacyInput(int controllerIndex) = 0;
    };
}
