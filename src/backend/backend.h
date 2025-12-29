#pragma once

#include "openxr.h"
#include "opengl.h"
#include "frame_state.h"
#include "frame_queue.h"
#include "haptic_queue.h"
#include "event_queue.h"
#include "input_profile.h"
#include "device_property_set.h"
#include "render_model.h"
#include "input/action_manager.h"

#include <vector>
#include <ctime>

namespace vapor
{
    class Backend
    {
        public:
            Backend();
            ~Backend();
            void loop();
            void waitForFirstFrame();
            void requestExit();

            //

            int renderWidth;
            int renderHeight;
            int refreshRate;

            input_profile::InputProfile* inputProfile;
            DevicePropertySet* devicePropertySets;
            RenderModelLoader* renderModelLoader;
            std::string* deviceRenderModelNames;

            FrameStateStore frameStates = FrameStateStore(10);
            FrameQueue* frameQueue;

            HapticQueue* hapticQueue;

            EventQueue eventQueue;

            input::ActionManager* actionManager = nullptr;

            void queueResetSeatedZeroPose(bool fromSystemMenu);
            void queueResetStandingZeroPose(bool fromSystemMenu);

            inline long getCurrentXrTime()
            {
                struct timespec timespec;
                clock_gettime(CLOCK_MONOTONIC, &timespec);
                XrTime xrTime;
                this->xrConvertTimespecTimeToTimeKHR(this->instance->handle, &timespec, &xrTime);
                return xrTime;
            }

        private:
            OpenXR::Instance* instance;
            OpenXR::Session* session;
            PFN_xrConvertTimespecTimeToTimeKHR xrConvertTimespecTimeToTimeKHR;
            PFN_xrGetDisplayRefreshRateFB xrGetDisplayRefreshRateFB;

            OpenXR::Swapchain* swapchains[2];
            OpenGL::Framebuffer* framebuffer;
            OpenGL::Texture* srcTextures[4];
            OpenGL::Framebuffer* srcFramebuffer;
            OpenGL::ExternalMemory* externalMemory[4] = {nullptr, nullptr, nullptr, nullptr};

            OpenXR::Space* viewSpace;
            OpenXR::Space* localSpace;
            OpenXR::Space* localFloorSpace;
            XrTime localReferenceSpaceChangeTime = 0;
            XrTime localFloorReferenceSpaceChangeTime = 0;
        public: // f*ck C++
            struct ZeroPose
            {
                XrVector3f position;
                float yaw;
            };
        private:
            ZeroPose seatedZeroPose;
            ZeroPose standingZeroPose;
            volatile bool needSeatedZeroPoseReset = false;
            volatile bool needStandingZeroPoseReset = false;
            volatile bool needSeatedZeroPoseResetFromSystemMenu = false;
            volatile bool needStandingZeroPoseResetFromSystemMenu = false;
            bool seatedZeroPoseInitialised = false;
            bool standingZeroPoseInitialised = false;

            std::vector<input_profile::OpenXRInputDescription> openXRInputs;
            OpenXR::ActionSet* actionSet;
            std::vector<OpenXR::Action*> actions;
            std::vector<OpenXR::Space*> actionSpaces;

            void step(XrTime displayTime, XrDuration displayDuration);
            std::vector<OpenXR::Layer> render(XrTime displayTime);
    };
}
