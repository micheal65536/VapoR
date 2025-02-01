#pragma once

#include "../input_profile.h"

namespace vapor
{
    namespace input_profiles
    {
        class OculusTouch: public InputProfile
        {
            public:
                virtual std::string getOpenXRInteractionProfileName();
                virtual int getOpenXRInputsCount();
                virtual const OpenXRInputDescription* getOpenXRInputs();

                virtual std::string getOpenVRProfileName();
                virtual int getOpenVRInputsCount();
                virtual const OpenVRInputDescription* getOpenVRInputs();
                virtual LegacyInputDescription getOpenVRLegacyInputDescription();

                virtual InputState getOpenVRInputState(int inputIndex, const InputState* openXRInputStates);
                virtual InputState getOpenVRControllerPose(int controllerIndex, const InputState* openXRInputStates);
                virtual LegacyInputState getOpenVRLegacyInputState(int controllerIndex, const InputState* openXRInputStates);

                virtual int getOpenXRHapticActionIndex(int openVRInputIndex);
                virtual int getOpenXRHapticActionIndexForLegacyInput(int controllerIndex);
        };
    }
}
