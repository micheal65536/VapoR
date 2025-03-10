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

                virtual OpenVRInputState getOpenVRInputState(int inputIndex, const OpenXRInputState* openXRInputStates);
                virtual OpenVRInputState getOpenVRControllerPose(int controllerIndex, const OpenVRInputState* openVRInputStates);
                virtual LegacyInputState getOpenVRLegacyInputState(int controllerIndex, const OpenXRInputState* openXRInputStates);

                virtual int getOpenXRHapticActionIndex(int openVRInputIndex);
                virtual int getOpenXRHapticActionIndexForLegacyInput(int controllerIndex);
        };
    }
}
