#pragma once

#define XR_USE_GRAPHICS_API_OPENGL
#define XR_USE_PLATFORM_XLIB
#define GL_GLEXT_PROTOTYPES

#include <X11/Xlib.h>
#include <GL/glx.h>

#include <openxr/openxr.h>
#include <openxr/openxr_platform.h>

#include "log/abort.h"

#include <string>
#include <vector>

#define ABORT_ON_OPENXR_ERROR(x) \
    { \
        XrResult _r = x; \
        if (!XR_SUCCEEDED(_r)) \
        { \
            ABORT("OpenXR call failed (%d)", _r); \
        } \
    }

namespace OpenXR
{
    const XrPosef IDENTITY_POSE {
        .orientation = XrQuaternionf {
            .x = 0.0f,
            .y = 0.0f,
            .z = 0.0f,
            .w = 1.0f
        },
        .position = XrVector3f {
            .x = 0.0f,
            .y = 0.0f,
            .z = 0.0f
        }
    };

    class Swapchain;
    class Space;
    class ActionSet;
    class Action;

    struct View
    {
        XrPosef pose;
        XrFovf fov;
    };

    struct ViewPair
    {
        View left;
        View right;
    };

    struct Pose
    {
        bool poseValid;
        XrPosef pose;
    };

    struct PoseAndVelocity
    {
        bool poseValid;
        bool linearVelocityValid;
        bool angularVelocityValid;
        XrPosef pose;
        XrVector3f linearVelocity;
        XrVector3f angularVelocity;
    };

    struct Layer
    {
        const Space& space;

        XrPosef leftPose;
        XrFovf leftFov;
        const Swapchain& leftSwapchain;
        int leftImageX;
        int leftImageY;
        int leftImageWidth;
        int leftImageHeight;
        int leftImageIndex;

        XrPosef rightPose;
        XrFovf rightFov;
        const Swapchain& rightSwapchain;
        int rightImageX;
        int rightImageY;
        int rightImageWidth;
        int rightImageHeight;
        int rightImageIndex;
    };

    class Instance
    {
        public:
            Instance(const std::string& applicationName, const std::vector<std::string>& extensions);
            ~Instance();

            XrPath getPath(const std::string& pathString) const;

            XrSystemId getSystem() const;
            void getViewConfiguration(XrSystemId system, int* recommendedWidth, int* recommendedHeight, int* recommendedSampleCount, int* maxWidth, int* maxHeight, int* maxSampleCount) const;

            bool pollEvent(XrEventDataBuffer* event) const;

            XrInstance handle;
    };

    class Session
    {
        public:
            Session(const Instance& instance, XrSystemId system);
            ~Session();

            void attachActionSets(const std::vector<const ActionSet*>& actionSets) const;

            void begin() const;
            void end() const;
            void requestExit() const;

            XrTime waitFrame(bool* shouldRender, XrDuration* displayDuration) const;
            void beginFrame() const;
            void endFrame(XrTime displayTime, const std::vector<Layer>& layers) const;

            ViewPair locateViews(XrTime time, const Space& space) const;
            void syncActions(const std::vector<const ActionSet*>& activeActionSets) const;

            XrSession handle;
            const Instance& instance;
            XrSystemId system;

        private:
            Display* xDisplay;
            GLXContext glxContext;
            GLXPbuffer glxPbuffer;
    };

    class Swapchain
    {
        public:
            Swapchain(const Session& session, int width, int height, int sampleCount, GLenum imageFormat);
            ~Swapchain();

            GLuint acquireImage() const;
            void releaseImage() const;
            bool waitSwapchain(XrDuration timeout) const;

            XrSwapchain handle;

        private:
            GLuint* images;
    };

    class Space
    {
        public:
            Space(const Session& session, XrReferenceSpaceType referenceSpaceType, const XrPosef& pose);
            Space(const Session& session, const Action& action, const std::string& subactionPath, const XrPosef& pose);
            ~Space();

            Pose locate(const Space& base, XrTime time) const;
            PoseAndVelocity locateWithVelocity(const Space& base, XrTime time) const;

            XrSpace handle;
    };

    class ActionSet
    {
        public:
            ActionSet(const Instance& instance, const std::string& name, const std::string& displayName, int priority);
            ~ActionSet();

            struct ActionBinding
            {
                const Action& action;
                std::string path;
            };
            void suggestBindings(const std::string& interactionProfile, const std::vector<ActionBinding>& bindings) const;

            XrActionSet handle;
            const Instance& instance;
    };

    class Action
    {
        public:
            Action(const ActionSet& actionSet, const std::string& name, const std::string& displayName, XrActionType type, std::vector<std::string> subactionPaths);
            ~Action();

            bool getStateBool(const Session& session, const std::string& subactionPath) const;
            bool getStateBool(const Session& session, const std::string& subactionPath, XrTime* lastChangeTime) const;
            float getStateFloat(const Session& session, const std::string& subactionPath) const;
            float getStateFloat(const Session& session, const std::string& subactionPath, XrTime* lastChangeTime) const;
            XrVector2f getStateVector(const Session& session, const std::string& subactionPath) const;
            XrVector2f getStateVector(const Session& session, const std::string& subactionPath, XrTime* lastChangeTime) const;

            void applyHapticFeedback(const Session& session, const std::string& subactionPath, XrDuration duration, float frequency, float amplitude) const;

            XrAction handle;
            const ActionSet& actionSet;
    };
}
