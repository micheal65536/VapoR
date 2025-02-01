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

#include <vector>

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
            int refreshRate; // this is determined using the predictedDisplayPeriod from xrWaitFrame, it's possible that this may be unreliable or change throughout the lifetime of the application, use with extreme care

            InputProfile* inputProfile;
            DevicePropertySet* devicePropertySets;
            RenderModelLoader* renderModelLoader;
            std::string* deviceRenderModelNames;

            FrameStateStore frameStates = FrameStateStore(10);
            FrameQueue* frameQueue;

            HapticQueue* hapticQueue;

            EventQueue eventQueue;

        private:
            OpenXR::Instance* instance;
            OpenXR::Session* session;

            OpenXR::Swapchain* swapchains[2];
            OpenGL::Framebuffer* framebuffer;
            OpenGL::Texture* srcTextures[4];
            OpenGL::Framebuffer* srcFramebuffer;
            GLuint externalMemory[4];
            bool externalMemoryImported = false;

            OpenXR::Space* viewSpace;
            OpenXR::Space* localSpace;
            OpenXR::Space* localFloorSpace;

            std::vector<OpenXRInputDescription> openXRInputs;
            OpenXR::ActionSet* actionSet;
            std::vector<OpenXR::Action*> actions;
            std::vector<OpenXR::Space*> actionSpaces;

            void step(XrTime displayTime, XrDuration displayDuration);
            std::vector<OpenXR::Layer> render(XrTime displayTime);
    };
}
