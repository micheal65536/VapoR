#pragma once

#include "../types.h"
#include <cstdint>
#include <GL/gl.h>
#include <vulkan/vulkan.h>

#include "../impl/compositor.h"

namespace openvr
{
    struct Compositor_005
    {
        static CompositorError lastError;
        static DeviceType deviceType;

        static uint32_t getLastError(char* buffer, uint32_t bufferSize);

        static void setVSync(bool enabled);
        static bool getVSync();
        static void setGamma(float gamma);
        static float getGamma();

        static void setGraphicsDevice(DeviceType deviceType, void* device);

        static void waitGetPoses(TrackedDevicePose* poses, uint32_t posesCount);
        static void submit(Eye eye, void* texture, const TextureBounds* bounds);
        static void clearLastSubmittedFrame();

        static void getOverlayDefaults(OverlaySettings* settings);
        static void setOverlay(void* texture, const OverlaySettings* settings);
        static void setOverlayRaw(void* buffer, uint32_t width, uint32_t height, uint32_t depth, const OverlaySettings* settings);
        static void setOverlayFromFile(const char* filePath, const OverlaySettings* settings);
        static void clearOverlay();

        static bool getFrameTiming(FrameTiming_0_9_0* timing, uint32_t framesAgo);

        static void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background);
        static void fadeGrid(float seconds, bool fadeGridIn);

        static void compositorBringToFront();
        static void compositorGoToBack();
        static void compositorQuit();
        static bool isFullscreen();

        static bool computeOverlayIntersection(const OverlaySettings* settings, float aspectRatio, TrackingUniverseOrigin origin, Vector3 source, Vector3 direction, Vector2* intersectionUV, Vector3* intersectionTrackingSpace);

        static void setTrackingSpace(TrackingUniverseOrigin origin);
        static TrackingUniverseOrigin getTrackingSpace();

        void* getLastError_ = (void*) getLastError;
        void* setVSync_ = (void*) setVSync;
        void* getVSync_ = (void*) getVSync;
        void* setGamma_ = (void*) setGamma;
        void* getGamma_ = (void*) getGamma;
        void* setGraphicsDevice_ = (void*) setGraphicsDevice;
        void* waitGetPoses_ = (void*) waitGetPoses;
        void* submit_ = (void*) submit;
        void* clearLastSubmittedFrame_ = (void*) clearLastSubmittedFrame;
        void* getOverlayDefaults_ = (void*) getOverlayDefaults;
        void* setOverlay_ = (void*) setOverlay;
        void* setOverlayRaw_ = (void*) setOverlayRaw;
        void* setOverlayFromFile_ = (void*) setOverlayFromFile;
        void* clearOverlay_ = (void*) clearOverlay;
        void* getFrameTiming_ = (void*) getFrameTiming;
        void* fadeToColor_ = (void*) fadeToColor;
        void* fadeGrid_ = (void*) fadeGrid;
        void* compositorBringToFront_ = (void*) compositorBringToFront;
        void* compositorGoToBack_ = (void*) compositorGoToBack;
        void* compositorQuit_ = (void*) compositorQuit;
        void* isFullscreen_ = (void*) isFullscreen;
        void* computeOverlayIntersection_ = (void*) computeOverlayIntersection;
        void* setTrackingSpace_ = (void*) setTrackingSpace;
        void* getTrackingSpace_ = (void*) getTrackingSpace;
    };

    class Compositor_005_v
    {
        public:
            virtual uint32_t getLastError(char* buffer, uint32_t bufferSize) { return Compositor_005::getLastError(buffer, bufferSize); }
            virtual void setVSync(bool enabled) { return Compositor_005::setVSync(enabled); }
            virtual bool getVSync() { return Compositor_005::getVSync(); }
            virtual void setGamma(float gamma) { return Compositor_005::setGamma(gamma); }
            virtual float getGamma() { return Compositor_005::getGamma(); }
            virtual void setGraphicsDevice(DeviceType deviceType, void* device) { return Compositor_005::setGraphicsDevice(deviceType, device); }
            virtual void waitGetPoses(TrackedDevicePose* poses, uint32_t posesCount) { return Compositor_005::waitGetPoses(poses, posesCount); }
            virtual void submit(Eye eye, void* texture, const TextureBounds* bounds) { return Compositor_005::submit(eye, texture, bounds); }
            virtual void clearLastSubmittedFrame() { return Compositor_005::clearLastSubmittedFrame(); }
            virtual void getOverlayDefaults(OverlaySettings* settings) { return Compositor_005::getOverlayDefaults(settings); }
            virtual void setOverlay(void* texture, const OverlaySettings* settings) { return Compositor_005::setOverlay(texture, settings); }
            virtual void setOverlayRaw(void* buffer, uint32_t width, uint32_t height, uint32_t depth, const OverlaySettings* settings) { return Compositor_005::setOverlayRaw(buffer, width, height, depth, settings); }
            virtual void setOverlayFromFile(const char* filePath, const OverlaySettings* settings) { return Compositor_005::setOverlayFromFile(filePath, settings); }
            virtual void clearOverlay() { return Compositor_005::clearOverlay(); }
            virtual bool getFrameTiming(FrameTiming_0_9_0* timing, uint32_t framesAgo) { return Compositor_005::getFrameTiming(timing, framesAgo); }
            virtual void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background) { return Compositor_005::fadeToColor(seconds, red, green, blue, alpha, background); }
            virtual void fadeGrid(float seconds, bool fadeGridIn) { return Compositor_005::fadeGrid(seconds, fadeGridIn); }
            virtual void compositorBringToFront() { return Compositor_005::compositorBringToFront(); }
            virtual void compositorGoToBack() { return Compositor_005::compositorGoToBack(); }
            virtual void compositorQuit() { return Compositor_005::compositorQuit(); }
            virtual bool isFullscreen() { return Compositor_005::isFullscreen(); }
            virtual bool computeOverlayIntersection(const OverlaySettings* settings, float aspectRatio, TrackingUniverseOrigin origin, Vector3 source, Vector3 direction, Vector2* intersectionUV, Vector3* intersectionTrackingSpace) { return Compositor_005::computeOverlayIntersection(settings, aspectRatio, origin, source, direction, intersectionUV, intersectionTrackingSpace); }
            virtual void setTrackingSpace(TrackingUniverseOrigin origin) { return Compositor_005::setTrackingSpace(origin); }
            virtual TrackingUniverseOrigin getTrackingSpace() { return Compositor_005::getTrackingSpace(); }
    };

    //

    struct Compositor_006
    {
        static CompositorError lastError;
        static DeviceType deviceType;

        static uint32_t getLastError(char* buffer, uint32_t bufferSize);

        static void setVSync(bool enabled);
        static bool getVSync();
        static void setGamma(float gamma);
        static float getGamma();

        static void setGraphicsDevice(DeviceType deviceType, void* device);

        static CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError submit(Eye eye, void* texture, const TextureBounds* bounds);
        static void clearLastSubmittedFrame();

        static bool getFrameTiming(FrameTiming_0_9_0* timing, uint32_t framesAgo);

        static void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background);
        static void fadeGrid(float seconds, bool fadeGridIn);

        static void compositorBringToFront();
        static void compositorGoToBack();
        static void compositorQuit();
        static bool isFullscreen();

        static void setTrackingSpace(TrackingUniverseOrigin origin);
        static TrackingUniverseOrigin getTrackingSpace();

        static uint32_t getCurrentSceneFocusProcess();
        static bool canRenderScene();

        void* getLastError_ = (void*) getLastError;
        void* setVSync_ = (void*) setVSync;
        void* getVSync_ = (void*) getVSync;
        void* setGamma_ = (void*) setGamma;
        void* getGamma_ = (void*) getGamma;
        void* setGraphicsDevice_ = (void*) setGraphicsDevice;
        void* waitGetPoses_ = (void*) waitGetPoses;
        void* submit_ = (void*) submit;
        void* clearLastSubmittedFrame_ = (void*) clearLastSubmittedFrame;
        void* getFrameTiming_ = (void*) getFrameTiming;
        void* fadeToColor_ = (void*) fadeToColor;
        void* fadeGrid_ = (void*) fadeGrid;
        void* compositorBringToFront_ = (void*) compositorBringToFront;
        void* compositorGoToBack_ = (void*) compositorGoToBack;
        void* compositorQuit_ = (void*) compositorQuit;
        void* isFullscreen_ = (void*) isFullscreen;
        void* setTrackingSpace_ = (void*) setTrackingSpace;
        void* getTrackingSpace_ = (void*) getTrackingSpace;
        void* getCurrentSceneFocusProcess_ = (void*) getCurrentSceneFocusProcess;
        void* canRenderScene_ = (void*) canRenderScene;
    };

    class Compositor_006_v
    {
        public:
            virtual uint32_t getLastError(char* buffer, uint32_t bufferSize) { return Compositor_006::getLastError(buffer, bufferSize); }
            virtual void setVSync(bool enabled) { return Compositor_006::setVSync(enabled); }
            virtual bool getVSync() { return Compositor_006::getVSync(); }
            virtual void setGamma(float gamma) { return Compositor_006::setGamma(gamma); }
            virtual float getGamma() { return Compositor_006::getGamma(); }
            virtual void setGraphicsDevice(DeviceType deviceType, void* device) { return Compositor_006::setGraphicsDevice(deviceType, device); }
            virtual CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_006::waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError submit(Eye eye, void* texture, const TextureBounds* bounds) { return Compositor_006::submit(eye, texture, bounds); }
            virtual void clearLastSubmittedFrame() { return Compositor_006::clearLastSubmittedFrame(); }
            virtual bool getFrameTiming(FrameTiming_0_9_0* timing, uint32_t framesAgo) { return Compositor_006::getFrameTiming(timing, framesAgo); }
            virtual void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background) { return Compositor_006::fadeToColor(seconds, red, green, blue, alpha, background); }
            virtual void fadeGrid(float seconds, bool fadeGridIn) { return Compositor_006::fadeGrid(seconds, fadeGridIn); }
            virtual void compositorBringToFront() { return Compositor_006::compositorBringToFront(); }
            virtual void compositorGoToBack() { return Compositor_006::compositorGoToBack(); }
            virtual void compositorQuit() { return Compositor_006::compositorQuit(); }
            virtual bool isFullscreen() { return Compositor_006::isFullscreen(); }
            virtual void setTrackingSpace(TrackingUniverseOrigin origin) { return Compositor_006::setTrackingSpace(origin); }
            virtual TrackingUniverseOrigin getTrackingSpace() { return Compositor_006::getTrackingSpace(); }
            virtual uint32_t getCurrentSceneFocusProcess() { return Compositor_006::getCurrentSceneFocusProcess(); }
            virtual bool canRenderScene() { return Compositor_006::canRenderScene(); }
    };

    //

    struct Compositor_007
    {
        static CompositorError lastError;

        static uint32_t getLastError(char* buffer, uint32_t bufferSize);

        static void setVSync(bool enabled);
        static bool getVSync();
        static void setGamma(float gamma);
        static float getGamma();

        static CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError submit(Eye eye, TextureType textureType, void* texture, const TextureBounds* bounds);
        static void clearLastSubmittedFrame();

        static bool getFrameTiming(FrameTiming_0_9_0* timing, uint32_t framesAgo);

        static void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background);
        static void fadeGrid(float seconds, bool fadeGridIn);

        static void compositorBringToFront();
        static void compositorGoToBack();
        static void compositorQuit();
        static bool isFullscreen();

        static void setTrackingSpace(TrackingUniverseOrigin origin);
        static TrackingUniverseOrigin getTrackingSpace();

        static uint32_t getCurrentSceneFocusProcess();
        static bool canRenderScene();

        void* getLastError_ = (void*) getLastError;
        void* setVSync_ = (void*) setVSync;
        void* getVSync_ = (void*) getVSync;
        void* setGamma_ = (void*) setGamma;
        void* getGamma_ = (void*) getGamma;
        void* waitGetPoses_ = (void*) waitGetPoses;
        void* submit_ = (void*) submit;
        void* clearLastSubmittedFrame_ = (void*) clearLastSubmittedFrame;
        void* getFrameTiming_ = (void*) getFrameTiming;
        void* fadeToColor_ = (void*) fadeToColor;
        void* fadeGrid_ = (void*) fadeGrid;
        void* compositorBringToFront_ = (void*) compositorBringToFront;
        void* compositorGoToBack_ = (void*) compositorGoToBack;
        void* compositorQuit_ = (void*) compositorQuit;
        void* isFullscreen_ = (void*) isFullscreen;
        void* setTrackingSpace_ = (void*) setTrackingSpace;
        void* getTrackingSpace_ = (void*) getTrackingSpace;
        void* getCurrentSceneFocusProcess_ = (void*) getCurrentSceneFocusProcess;
        void* canRenderScene_ = (void*) canRenderScene;
    };

    class Compositor_007_v
    {
        public:
            virtual uint32_t getLastError(char* buffer, uint32_t bufferSize) { return Compositor_007::getLastError(buffer, bufferSize); }
            virtual void setVSync(bool enabled) { return Compositor_007::setVSync(enabled); }
            virtual bool getVSync() { return Compositor_007::getVSync(); }
            virtual void setGamma(float gamma) { return Compositor_007::setGamma(gamma); }
            virtual float getGamma() { return Compositor_007::getGamma(); }
            virtual CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_007::waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError submit(Eye eye, TextureType textureType, void* texture, const TextureBounds* bounds) { return Compositor_007::submit(eye, textureType, texture, bounds); }
            virtual void clearLastSubmittedFrame() { return Compositor_007::clearLastSubmittedFrame(); }
            virtual bool getFrameTiming(FrameTiming_0_9_0* timing, uint32_t framesAgo) { return Compositor_007::getFrameTiming(timing, framesAgo); }
            virtual void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background) { return Compositor_007::fadeToColor(seconds, red, green, blue, alpha, background); }
            virtual void fadeGrid(float seconds, bool fadeGridIn) { return Compositor_007::fadeGrid(seconds, fadeGridIn); }
            virtual void compositorBringToFront() { return Compositor_007::compositorBringToFront(); }
            virtual void compositorGoToBack() { return Compositor_007::compositorGoToBack(); }
            virtual void compositorQuit() { return Compositor_007::compositorQuit(); }
            virtual bool isFullscreen() { return Compositor_007::isFullscreen(); }
            virtual void setTrackingSpace(TrackingUniverseOrigin origin) { return Compositor_007::setTrackingSpace(origin); }
            virtual TrackingUniverseOrigin getTrackingSpace() { return Compositor_007::getTrackingSpace(); }
            virtual uint32_t getCurrentSceneFocusProcess() { return Compositor_007::getCurrentSceneFocusProcess(); }
            virtual bool canRenderScene() { return Compositor_007::canRenderScene(); }
    };

    //

    struct Compositor_008
    {
        static CompositorError lastError;

        static uint32_t getLastError(char* buffer, uint32_t bufferSize);

        static void setVSync(bool enabled);
        static bool getVSync();
        static void setGamma(float gamma);
        static float getGamma();

        static CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError submit(Eye eye, TextureType textureType, void* texture, const TextureBounds* bounds);
        static void clearLastSubmittedFrame();

        static bool getFrameTiming(FrameTiming_0_9_0* timing, uint32_t framesAgo);

        static void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background);
        static void fadeGrid(float seconds, bool fadeGridIn);

        static void setSkyboxOverride(TextureType textureType, void* front, void* back, void* left, void* right, void* top, void* bottom);
        static void clearSkyboxOverride();

        static void compositorBringToFront();
        static void compositorGoToBack();
        static void compositorQuit();
        static bool isFullscreen();

        static void setTrackingSpace(TrackingUniverseOrigin origin);
        static TrackingUniverseOrigin getTrackingSpace();

        static uint32_t getCurrentSceneFocusProcess();
        static bool canRenderScene();

        static void showMirrorWindow();
        static void hideMirrorWindow();

        static void compositorDumpImages();

        static float getFrameTimeRemaining();

        static uint32_t getLastFrameRenderer();

        static CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static void postPresentHandoff();

        void* getLastError_ = (void*) getLastError;
        void* setVSync_ = (void*) setVSync;
        void* getVSync_ = (void*) getVSync;
        void* setGamma_ = (void*) setGamma;
        void* getGamma_ = (void*) getGamma;
        void* waitGetPoses_ = (void*) waitGetPoses;
        void* submit_ = (void*) submit;
        void* clearLastSubmittedFrame_ = (void*) clearLastSubmittedFrame;
        void* getFrameTiming_ = (void*) getFrameTiming;
        void* fadeToColor_ = (void*) fadeToColor;
        void* fadeGrid_ = (void*) fadeGrid;
        void* setSkyboxOverride_ = (void*) setSkyboxOverride;
        void* clearSkyboxOverride_ = (void*) clearSkyboxOverride;
        void* compositorBringToFront_ = (void*) compositorBringToFront;
        void* compositorGoToBack_ = (void*) compositorGoToBack;
        void* compositorQuit_ = (void*) compositorQuit;
        void* isFullscreen_ = (void*) isFullscreen;
        void* setTrackingSpace_ = (void*) setTrackingSpace;
        void* getTrackingSpace_ = (void*) getTrackingSpace;
        void* getCurrentSceneFocusProcess_ = (void*) getCurrentSceneFocusProcess;
        void* canRenderScene_ = (void*) canRenderScene;
        void* showMirrorWindow_ = (void*) showMirrorWindow;
        void* hideMirrorWindow_ = (void*) hideMirrorWindow;
        void* compositorDumpImages_ = (void*) compositorDumpImages;
        void* getFrameTimeRemaining_ = (void*) getFrameTimeRemaining;
        void* getLastFrameRenderer_ = (void*) getLastFrameRenderer;
        void* getLastPoses_ = (void*) getLastPoses;
        void* postPresentHandoff_ = (void*) postPresentHandoff;
    };

    class Compositor_008_v
    {
        public:
            virtual uint32_t getLastError(char* buffer, uint32_t bufferSize) { return Compositor_008::getLastError(buffer, bufferSize); }
            virtual void setVSync(bool enabled) { return Compositor_008::setVSync(enabled); }
            virtual bool getVSync() { return Compositor_008::getVSync(); }
            virtual void setGamma(float gamma) { return Compositor_008::setGamma(gamma); }
            virtual float getGamma() { return Compositor_008::getGamma(); }
            virtual CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_008::waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError submit(Eye eye, TextureType textureType, void* texture, const TextureBounds* bounds) { return Compositor_008::submit(eye, textureType, texture, bounds); }
            virtual void clearLastSubmittedFrame() { return Compositor_008::clearLastSubmittedFrame(); }
            virtual bool getFrameTiming(FrameTiming_0_9_0* timing, uint32_t framesAgo) { return Compositor_008::getFrameTiming(timing, framesAgo); }
            virtual void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background) { return Compositor_008::fadeToColor(seconds, red, green, blue, alpha, background); }
            virtual void fadeGrid(float seconds, bool fadeGridIn) { return Compositor_008::fadeGrid(seconds, fadeGridIn); }
            virtual void setSkyboxOverride(TextureType textureType, void* front, void* back, void* left, void* right, void* top, void* bottom) { return Compositor_008::setSkyboxOverride(textureType, front, back, left, right, top, bottom); }
            virtual void clearSkyboxOverride() { return Compositor_008::clearSkyboxOverride(); }
            virtual void compositorBringToFront() { return Compositor_008::compositorBringToFront(); }
            virtual void compositorGoToBack() { return Compositor_008::compositorGoToBack(); }
            virtual void compositorQuit() { return Compositor_008::compositorQuit(); }
            virtual bool isFullscreen() { return Compositor_008::isFullscreen(); }
            virtual void setTrackingSpace(TrackingUniverseOrigin origin) { return Compositor_008::setTrackingSpace(origin); }
            virtual TrackingUniverseOrigin getTrackingSpace() { return Compositor_008::getTrackingSpace(); }
            virtual uint32_t getCurrentSceneFocusProcess() { return Compositor_008::getCurrentSceneFocusProcess(); }
            virtual bool canRenderScene() { return Compositor_008::canRenderScene(); }
            virtual void showMirrorWindow() { return Compositor_008::showMirrorWindow(); }
            virtual void hideMirrorWindow() { return Compositor_008::hideMirrorWindow(); }
            virtual void compositorDumpImages() { return Compositor_008::compositorDumpImages(); }
            virtual float getFrameTimeRemaining() { return Compositor_008::getFrameTimeRemaining(); }
            virtual uint32_t getLastFrameRenderer() { return Compositor_008::getLastFrameRenderer(); }
            virtual CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_008::getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual void postPresentHandoff() { return Compositor_008::postPresentHandoff(); }
    };

    //

    struct Compositor_009
    {
        static void setTrackingSpace(TrackingUniverseOrigin origin);
        static TrackingUniverseOrigin getTrackingSpace();

        static CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags);
        static void clearLastSubmittedFrame();
        static void postPresentHandoff();

        static bool getFrameTiming(FrameTiming_0_9_0* timing, uint32_t framesAgo);
        static float getFrameTimeRemaining();

        static void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background);
        static void fadeGrid(float seconds, bool fadeGridIn);

        static CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount);
        static void clearSkyboxOverride();

        static void compositorBringToFront();
        static void compositorGoToBack();
        static void compositorQuit();
        static bool isFullscreen();
        static uint32_t getCurrentSceneFocusProcess();
        static uint32_t getLastFrameRenderer();
        static bool canRenderScene();

        static void showMirrorWindow();
        static void hideMirrorWindow();
        static bool isMirrorWindowVisible();

        static void compositorDumpImages();

        void* setTrackingSpace_ = (void*) setTrackingSpace;
        void* getTrackingSpace_ = (void*) getTrackingSpace;
        void* waitGetPoses_ = (void*) waitGetPoses;
        void* getLastPoses_ = (void*) getLastPoses;
        void* submit_ = (void*) submit;
        void* clearLastSubmittedFrame_ = (void*) clearLastSubmittedFrame;
        void* postPresentHandoff_ = (void*) postPresentHandoff;
        void* getFrameTiming_ = (void*) getFrameTiming;
        void* getFrameTimeRemaining_ = (void*) getFrameTimeRemaining;
        void* fadeToColor_ = (void*) fadeToColor;
        void* fadeGrid_ = (void*) fadeGrid;
        void* setSkyboxOverride_ = (void*) setSkyboxOverride;
        void* clearSkyboxOverride_ = (void*) clearSkyboxOverride;
        void* compositorBringToFront_ = (void*) compositorBringToFront;
        void* compositorGoToBack_ = (void*) compositorGoToBack;
        void* compositorQuit_ = (void*) compositorQuit;
        void* isFullscreen_ = (void*) isFullscreen;
        void* getCurrentSceneFocusProcess_ = (void*) getCurrentSceneFocusProcess;
        void* getLastFrameRenderer_ = (void*) getLastFrameRenderer;
        void* canRenderScene_ = (void*) canRenderScene;
        void* showMirrorWindow_ = (void*) showMirrorWindow;
        void* hideMirrorWindow_ = (void*) hideMirrorWindow;
        void* isMirrorWindowVisible_ = (void*) isMirrorWindowVisible;
        void* compositorDumpImages_ = (void*) compositorDumpImages;
    };

    class Compositor_009_v
    {
        public:
            virtual void setTrackingSpace(TrackingUniverseOrigin origin) { return Compositor_009::setTrackingSpace(origin); }
            virtual TrackingUniverseOrigin getTrackingSpace() { return Compositor_009::getTrackingSpace(); }
            virtual CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_009::waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_009::getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags) { return Compositor_009::submit(eye, texture, bounds, submitFlags); }
            virtual void clearLastSubmittedFrame() { return Compositor_009::clearLastSubmittedFrame(); }
            virtual void postPresentHandoff() { return Compositor_009::postPresentHandoff(); }
            virtual bool getFrameTiming(FrameTiming_0_9_0* timing, uint32_t framesAgo) { return Compositor_009::getFrameTiming(timing, framesAgo); }
            virtual float getFrameTimeRemaining() { return Compositor_009::getFrameTimeRemaining(); }
            virtual void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background) { return Compositor_009::fadeToColor(seconds, red, green, blue, alpha, background); }
            virtual void fadeGrid(float seconds, bool fadeGridIn) { return Compositor_009::fadeGrid(seconds, fadeGridIn); }
            virtual CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount) { return Compositor_009::setSkyboxOverride(textures, texturesCount); }
            virtual void clearSkyboxOverride() { return Compositor_009::clearSkyboxOverride(); }
            virtual void compositorBringToFront() { return Compositor_009::compositorBringToFront(); }
            virtual void compositorGoToBack() { return Compositor_009::compositorGoToBack(); }
            virtual void compositorQuit() { return Compositor_009::compositorQuit(); }
            virtual bool isFullscreen() { return Compositor_009::isFullscreen(); }
            virtual uint32_t getCurrentSceneFocusProcess() { return Compositor_009::getCurrentSceneFocusProcess(); }
            virtual uint32_t getLastFrameRenderer() { return Compositor_009::getLastFrameRenderer(); }
            virtual bool canRenderScene() { return Compositor_009::canRenderScene(); }
            virtual void showMirrorWindow() { return Compositor_009::showMirrorWindow(); }
            virtual void hideMirrorWindow() { return Compositor_009::hideMirrorWindow(); }
            virtual bool isMirrorWindowVisible() { return Compositor_009::isMirrorWindowVisible(); }
            virtual void compositorDumpImages() { return Compositor_009::compositorDumpImages(); }
    };

    //

    struct Compositor_011
    {
        static void setTrackingSpace(TrackingUniverseOrigin origin);
        static TrackingUniverseOrigin getTrackingSpace();

        static CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags);
        static void clearLastSubmittedFrame();
        static void postPresentHandoff();

        static bool getFrameTiming(FrameTiming_0_9_15* timing, uint32_t framesAgo);
        static float getFrameTimeRemaining();

        static void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background);
        static void fadeGrid(float seconds, bool fadeGridIn);

        static CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount);
        static void clearSkyboxOverride();

        static void compositorBringToFront();
        static void compositorGoToBack();
        static void compositorQuit();
        static bool isFullscreen();
        static uint32_t getCurrentSceneFocusProcess();
        static uint32_t getLastFrameRenderer();
        static bool canRenderScene();

        static void showMirrorWindow();
        static void hideMirrorWindow();
        static bool isMirrorWindowVisible();

        static void compositorDumpImages();

        void* setTrackingSpace_ = (void*) setTrackingSpace;
        void* getTrackingSpace_ = (void*) getTrackingSpace;
        void* waitGetPoses_ = (void*) waitGetPoses;
        void* getLastPoses_ = (void*) getLastPoses;
        void* submit_ = (void*) submit;
        void* clearLastSubmittedFrame_ = (void*) clearLastSubmittedFrame;
        void* postPresentHandoff_ = (void*) postPresentHandoff;
        void* getFrameTiming_ = (void*) getFrameTiming;
        void* getFrameTimeRemaining_ = (void*) getFrameTimeRemaining;
        void* fadeToColor_ = (void*) fadeToColor;
        void* fadeGrid_ = (void*) fadeGrid;
        void* setSkyboxOverride_ = (void*) setSkyboxOverride;
        void* clearSkyboxOverride_ = (void*) clearSkyboxOverride;
        void* compositorBringToFront_ = (void*) compositorBringToFront;
        void* compositorGoToBack_ = (void*) compositorGoToBack;
        void* compositorQuit_ = (void*) compositorQuit;
        void* isFullscreen_ = (void*) isFullscreen;
        void* getCurrentSceneFocusProcess_ = (void*) getCurrentSceneFocusProcess;
        void* getLastFrameRenderer_ = (void*) getLastFrameRenderer;
        void* canRenderScene_ = (void*) canRenderScene;
        void* showMirrorWindow_ = (void*) showMirrorWindow;
        void* hideMirrorWindow_ = (void*) hideMirrorWindow;
        void* isMirrorWindowVisible_ = (void*) isMirrorWindowVisible;
        void* compositorDumpImages_ = (void*) compositorDumpImages;
    };

    class Compositor_011_v
    {
        public:
            virtual void setTrackingSpace(TrackingUniverseOrigin origin) { return Compositor_011::setTrackingSpace(origin); }
            virtual TrackingUniverseOrigin getTrackingSpace() { return Compositor_011::getTrackingSpace(); }
            virtual CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_011::waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_011::getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags) { return Compositor_011::submit(eye, texture, bounds, submitFlags); }
            virtual void clearLastSubmittedFrame() { return Compositor_011::clearLastSubmittedFrame(); }
            virtual void postPresentHandoff() { return Compositor_011::postPresentHandoff(); }
            virtual bool getFrameTiming(FrameTiming_0_9_15* timing, uint32_t framesAgo) { return Compositor_011::getFrameTiming(timing, framesAgo); }
            virtual float getFrameTimeRemaining() { return Compositor_011::getFrameTimeRemaining(); }
            virtual void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background) { return Compositor_011::fadeToColor(seconds, red, green, blue, alpha, background); }
            virtual void fadeGrid(float seconds, bool fadeGridIn) { return Compositor_011::fadeGrid(seconds, fadeGridIn); }
            virtual CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount) { return Compositor_011::setSkyboxOverride(textures, texturesCount); }
            virtual void clearSkyboxOverride() { return Compositor_011::clearSkyboxOverride(); }
            virtual void compositorBringToFront() { return Compositor_011::compositorBringToFront(); }
            virtual void compositorGoToBack() { return Compositor_011::compositorGoToBack(); }
            virtual void compositorQuit() { return Compositor_011::compositorQuit(); }
            virtual bool isFullscreen() { return Compositor_011::isFullscreen(); }
            virtual uint32_t getCurrentSceneFocusProcess() { return Compositor_011::getCurrentSceneFocusProcess(); }
            virtual uint32_t getLastFrameRenderer() { return Compositor_011::getLastFrameRenderer(); }
            virtual bool canRenderScene() { return Compositor_011::canRenderScene(); }
            virtual void showMirrorWindow() { return Compositor_011::showMirrorWindow(); }
            virtual void hideMirrorWindow() { return Compositor_011::hideMirrorWindow(); }
            virtual bool isMirrorWindowVisible() { return Compositor_011::isMirrorWindowVisible(); }
            virtual void compositorDumpImages() { return Compositor_011::compositorDumpImages(); }
    };

    //

    struct Compositor_012
    {
        static void setTrackingSpace(TrackingUniverseOrigin origin);
        static TrackingUniverseOrigin getTrackingSpace();

        static CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose);
        static CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags);
        static void clearLastSubmittedFrame();
        static void postPresentHandoff();

        static bool getFrameTiming(FrameTiming_0_9_15* timing, uint32_t framesAgo);
        static float getFrameTimeRemaining();

        static void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background);
        static void fadeGrid(float seconds, bool fadeGridIn);

        static CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount);
        static void clearSkyboxOverride();

        static void compositorBringToFront();
        static void compositorGoToBack();
        static void compositorQuit();
        static bool isFullscreen();
        static uint32_t getCurrentSceneFocusProcess();
        static uint32_t getLastFrameRenderer();
        static bool canRenderScene();

        static void showMirrorWindow();
        static void hideMirrorWindow();
        static bool isMirrorWindowVisible();

        static void compositorDumpImages();
        static bool shouldAppRenderWithLowResources();

        void* setTrackingSpace_ = (void*) setTrackingSpace;
        void* getTrackingSpace_ = (void*) getTrackingSpace;
        void* waitGetPoses_ = (void*) waitGetPoses;
        void* getLastPoses_ = (void*) getLastPoses;
        void* getLastPoseForTrackedDeviceIndex_ = (void*) getLastPoseForTrackedDeviceIndex;
        void* submit_ = (void*) submit;
        void* clearLastSubmittedFrame_ = (void*) clearLastSubmittedFrame;
        void* postPresentHandoff_ = (void*) postPresentHandoff;
        void* getFrameTiming_ = (void*) getFrameTiming;
        void* getFrameTimeRemaining_ = (void*) getFrameTimeRemaining;
        void* fadeToColor_ = (void*) fadeToColor;
        void* fadeGrid_ = (void*) fadeGrid;
        void* setSkyboxOverride_ = (void*) setSkyboxOverride;
        void* clearSkyboxOverride_ = (void*) clearSkyboxOverride;
        void* compositorBringToFront_ = (void*) compositorBringToFront;
        void* compositorGoToBack_ = (void*) compositorGoToBack;
        void* compositorQuit_ = (void*) compositorQuit;
        void* isFullscreen_ = (void*) isFullscreen;
        void* getCurrentSceneFocusProcess_ = (void*) getCurrentSceneFocusProcess;
        void* getLastFrameRenderer_ = (void*) getLastFrameRenderer;
        void* canRenderScene_ = (void*) canRenderScene;
        void* showMirrorWindow_ = (void*) showMirrorWindow;
        void* hideMirrorWindow_ = (void*) hideMirrorWindow;
        void* isMirrorWindowVisible_ = (void*) isMirrorWindowVisible;
        void* compositorDumpImages_ = (void*) compositorDumpImages;
        void* shouldAppRenderWithLowResources_ = (void*) shouldAppRenderWithLowResources;
    };

    class Compositor_012_v
    {
        public:
            virtual void setTrackingSpace(TrackingUniverseOrigin origin) { return Compositor_012::setTrackingSpace(origin); }
            virtual TrackingUniverseOrigin getTrackingSpace() { return Compositor_012::getTrackingSpace(); }
            virtual CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_012::waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_012::getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose) { return Compositor_012::getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose); }
            virtual CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags) { return Compositor_012::submit(eye, texture, bounds, submitFlags); }
            virtual void clearLastSubmittedFrame() { return Compositor_012::clearLastSubmittedFrame(); }
            virtual void postPresentHandoff() { return Compositor_012::postPresentHandoff(); }
            virtual bool getFrameTiming(FrameTiming_0_9_15* timing, uint32_t framesAgo) { return Compositor_012::getFrameTiming(timing, framesAgo); }
            virtual float getFrameTimeRemaining() { return Compositor_012::getFrameTimeRemaining(); }
            virtual void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background) { return Compositor_012::fadeToColor(seconds, red, green, blue, alpha, background); }
            virtual void fadeGrid(float seconds, bool fadeGridIn) { return Compositor_012::fadeGrid(seconds, fadeGridIn); }
            virtual CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount) { return Compositor_012::setSkyboxOverride(textures, texturesCount); }
            virtual void clearSkyboxOverride() { return Compositor_012::clearSkyboxOverride(); }
            virtual void compositorBringToFront() { return Compositor_012::compositorBringToFront(); }
            virtual void compositorGoToBack() { return Compositor_012::compositorGoToBack(); }
            virtual void compositorQuit() { return Compositor_012::compositorQuit(); }
            virtual bool isFullscreen() { return Compositor_012::isFullscreen(); }
            virtual uint32_t getCurrentSceneFocusProcess() { return Compositor_012::getCurrentSceneFocusProcess(); }
            virtual uint32_t getLastFrameRenderer() { return Compositor_012::getLastFrameRenderer(); }
            virtual bool canRenderScene() { return Compositor_012::canRenderScene(); }
            virtual void showMirrorWindow() { return Compositor_012::showMirrorWindow(); }
            virtual void hideMirrorWindow() { return Compositor_012::hideMirrorWindow(); }
            virtual bool isMirrorWindowVisible() { return Compositor_012::isMirrorWindowVisible(); }
            virtual void compositorDumpImages() { return Compositor_012::compositorDumpImages(); }
            virtual bool shouldAppRenderWithLowResources() { return Compositor_012::shouldAppRenderWithLowResources(); }
    };

    //

    struct Compositor_013
    {
        static void setTrackingSpace(TrackingUniverseOrigin origin);
        static TrackingUniverseOrigin getTrackingSpace();

        static CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose);
        static CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags);
        static void clearLastSubmittedFrame();
        static void postPresentHandoff();

        static bool getFrameTiming(FrameTiming_0_9_15* timing, uint32_t framesAgo);
        static float getFrameTimeRemaining();

        static void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background);
        static void fadeGrid(float seconds, bool fadeGridIn);

        static CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount);
        static void clearSkyboxOverride();

        static void compositorBringToFront();
        static void compositorGoToBack();
        static void compositorQuit();
        static bool isFullscreen();
        static uint32_t getCurrentSceneFocusProcess();
        static uint32_t getLastFrameRenderer();
        static bool canRenderScene();

        static void showMirrorWindow();
        static void hideMirrorWindow();
        static bool isMirrorWindowVisible();

        static void compositorDumpImages();
        static bool shouldAppRenderWithLowResources();
        static void forceInterleavedReprojectionOn(bool on);

        void* setTrackingSpace_ = (void*) setTrackingSpace;
        void* getTrackingSpace_ = (void*) getTrackingSpace;
        void* waitGetPoses_ = (void*) waitGetPoses;
        void* getLastPoses_ = (void*) getLastPoses;
        void* getLastPoseForTrackedDeviceIndex_ = (void*) getLastPoseForTrackedDeviceIndex;
        void* submit_ = (void*) submit;
        void* clearLastSubmittedFrame_ = (void*) clearLastSubmittedFrame;
        void* postPresentHandoff_ = (void*) postPresentHandoff;
        void* getFrameTiming_ = (void*) getFrameTiming;
        void* getFrameTimeRemaining_ = (void*) getFrameTimeRemaining;
        void* fadeToColor_ = (void*) fadeToColor;
        void* fadeGrid_ = (void*) fadeGrid;
        void* setSkyboxOverride_ = (void*) setSkyboxOverride;
        void* clearSkyboxOverride_ = (void*) clearSkyboxOverride;
        void* compositorBringToFront_ = (void*) compositorBringToFront;
        void* compositorGoToBack_ = (void*) compositorGoToBack;
        void* compositorQuit_ = (void*) compositorQuit;
        void* isFullscreen_ = (void*) isFullscreen;
        void* getCurrentSceneFocusProcess_ = (void*) getCurrentSceneFocusProcess;
        void* getLastFrameRenderer_ = (void*) getLastFrameRenderer;
        void* canRenderScene_ = (void*) canRenderScene;
        void* showMirrorWindow_ = (void*) showMirrorWindow;
        void* hideMirrorWindow_ = (void*) hideMirrorWindow;
        void* isMirrorWindowVisible_ = (void*) isMirrorWindowVisible;
        void* compositorDumpImages_ = (void*) compositorDumpImages;
        void* shouldAppRenderWithLowResources_ = (void*) shouldAppRenderWithLowResources;
        void* forceInterleavedReprojectionOn_ = (void*) forceInterleavedReprojectionOn;
    };

    class Compositor_013_v
    {
        public:
            virtual void setTrackingSpace(TrackingUniverseOrigin origin) { return Compositor_013::setTrackingSpace(origin); }
            virtual TrackingUniverseOrigin getTrackingSpace() { return Compositor_013::getTrackingSpace(); }
            virtual CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_013::waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_013::getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose) { return Compositor_013::getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose); }
            virtual CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags) { return Compositor_013::submit(eye, texture, bounds, submitFlags); }
            virtual void clearLastSubmittedFrame() { return Compositor_013::clearLastSubmittedFrame(); }
            virtual void postPresentHandoff() { return Compositor_013::postPresentHandoff(); }
            virtual bool getFrameTiming(FrameTiming_0_9_15* timing, uint32_t framesAgo) { return Compositor_013::getFrameTiming(timing, framesAgo); }
            virtual float getFrameTimeRemaining() { return Compositor_013::getFrameTimeRemaining(); }
            virtual void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background) { return Compositor_013::fadeToColor(seconds, red, green, blue, alpha, background); }
            virtual void fadeGrid(float seconds, bool fadeGridIn) { return Compositor_013::fadeGrid(seconds, fadeGridIn); }
            virtual CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount) { return Compositor_013::setSkyboxOverride(textures, texturesCount); }
            virtual void clearSkyboxOverride() { return Compositor_013::clearSkyboxOverride(); }
            virtual void compositorBringToFront() { return Compositor_013::compositorBringToFront(); }
            virtual void compositorGoToBack() { return Compositor_013::compositorGoToBack(); }
            virtual void compositorQuit() { return Compositor_013::compositorQuit(); }
            virtual bool isFullscreen() { return Compositor_013::isFullscreen(); }
            virtual uint32_t getCurrentSceneFocusProcess() { return Compositor_013::getCurrentSceneFocusProcess(); }
            virtual uint32_t getLastFrameRenderer() { return Compositor_013::getLastFrameRenderer(); }
            virtual bool canRenderScene() { return Compositor_013::canRenderScene(); }
            virtual void showMirrorWindow() { return Compositor_013::showMirrorWindow(); }
            virtual void hideMirrorWindow() { return Compositor_013::hideMirrorWindow(); }
            virtual bool isMirrorWindowVisible() { return Compositor_013::isMirrorWindowVisible(); }
            virtual void compositorDumpImages() { return Compositor_013::compositorDumpImages(); }
            virtual bool shouldAppRenderWithLowResources() { return Compositor_013::shouldAppRenderWithLowResources(); }
            virtual void forceInterleavedReprojectionOn(bool on) { return Compositor_013::forceInterleavedReprojectionOn(on); }
    };

    //

    struct Compositor_014
    {
        static void setTrackingSpace(TrackingUniverseOrigin origin);
        static TrackingUniverseOrigin getTrackingSpace();

        static CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose);
        static CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags);
        static void clearLastSubmittedFrame();
        static void postPresentHandoff();

        static bool getFrameTiming(FrameTiming_0_9_15* timing, uint32_t framesAgo);
        static float getFrameTimeRemaining();

        static void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background);
        static void fadeGrid(float seconds, bool fadeGridIn);

        static CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount);
        static void clearSkyboxOverride();

        static void compositorBringToFront();
        static void compositorGoToBack();
        static void compositorQuit();
        static bool isFullscreen();
        static uint32_t getCurrentSceneFocusProcess();
        static uint32_t getLastFrameRenderer();
        static bool canRenderScene();

        static void showMirrorWindow();
        static void hideMirrorWindow();
        static bool isMirrorWindowVisible();

        static void compositorDumpImages();
        static bool shouldAppRenderWithLowResources();
        static void forceInterleavedReprojectionOn(bool on);
        static void forceReconnectProcess();
        static void suspendRendering(bool suspend);

        void* setTrackingSpace_ = (void*) setTrackingSpace;
        void* getTrackingSpace_ = (void*) getTrackingSpace;
        void* waitGetPoses_ = (void*) waitGetPoses;
        void* getLastPoses_ = (void*) getLastPoses;
        void* getLastPoseForTrackedDeviceIndex_ = (void*) getLastPoseForTrackedDeviceIndex;
        void* submit_ = (void*) submit;
        void* clearLastSubmittedFrame_ = (void*) clearLastSubmittedFrame;
        void* postPresentHandoff_ = (void*) postPresentHandoff;
        void* getFrameTiming_ = (void*) getFrameTiming;
        void* getFrameTimeRemaining_ = (void*) getFrameTimeRemaining;
        void* fadeToColor_ = (void*) fadeToColor;
        void* fadeGrid_ = (void*) fadeGrid;
        void* setSkyboxOverride_ = (void*) setSkyboxOverride;
        void* clearSkyboxOverride_ = (void*) clearSkyboxOverride;
        void* compositorBringToFront_ = (void*) compositorBringToFront;
        void* compositorGoToBack_ = (void*) compositorGoToBack;
        void* compositorQuit_ = (void*) compositorQuit;
        void* isFullscreen_ = (void*) isFullscreen;
        void* getCurrentSceneFocusProcess_ = (void*) getCurrentSceneFocusProcess;
        void* getLastFrameRenderer_ = (void*) getLastFrameRenderer;
        void* canRenderScene_ = (void*) canRenderScene;
        void* showMirrorWindow_ = (void*) showMirrorWindow;
        void* hideMirrorWindow_ = (void*) hideMirrorWindow;
        void* isMirrorWindowVisible_ = (void*) isMirrorWindowVisible;
        void* compositorDumpImages_ = (void*) compositorDumpImages;
        void* shouldAppRenderWithLowResources_ = (void*) shouldAppRenderWithLowResources;
        void* forceInterleavedReprojectionOn_ = (void*) forceInterleavedReprojectionOn;
        void* forceReconnectProcess_ = (void*) forceReconnectProcess;
        void* suspendRendering_ = (void*) suspendRendering;
    };

    class Compositor_014_v
    {
        public:
            virtual void setTrackingSpace(TrackingUniverseOrigin origin) { return Compositor_014::setTrackingSpace(origin); }
            virtual TrackingUniverseOrigin getTrackingSpace() { return Compositor_014::getTrackingSpace(); }
            virtual CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_014::waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_014::getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose) { return Compositor_014::getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose); }
            virtual CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags) { return Compositor_014::submit(eye, texture, bounds, submitFlags); }
            virtual void clearLastSubmittedFrame() { return Compositor_014::clearLastSubmittedFrame(); }
            virtual void postPresentHandoff() { return Compositor_014::postPresentHandoff(); }
            virtual bool getFrameTiming(FrameTiming_0_9_15* timing, uint32_t framesAgo) { return Compositor_014::getFrameTiming(timing, framesAgo); }
            virtual float getFrameTimeRemaining() { return Compositor_014::getFrameTimeRemaining(); }
            virtual void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background) { return Compositor_014::fadeToColor(seconds, red, green, blue, alpha, background); }
            virtual void fadeGrid(float seconds, bool fadeGridIn) { return Compositor_014::fadeGrid(seconds, fadeGridIn); }
            virtual CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount) { return Compositor_014::setSkyboxOverride(textures, texturesCount); }
            virtual void clearSkyboxOverride() { return Compositor_014::clearSkyboxOverride(); }
            virtual void compositorBringToFront() { return Compositor_014::compositorBringToFront(); }
            virtual void compositorGoToBack() { return Compositor_014::compositorGoToBack(); }
            virtual void compositorQuit() { return Compositor_014::compositorQuit(); }
            virtual bool isFullscreen() { return Compositor_014::isFullscreen(); }
            virtual uint32_t getCurrentSceneFocusProcess() { return Compositor_014::getCurrentSceneFocusProcess(); }
            virtual uint32_t getLastFrameRenderer() { return Compositor_014::getLastFrameRenderer(); }
            virtual bool canRenderScene() { return Compositor_014::canRenderScene(); }
            virtual void showMirrorWindow() { return Compositor_014::showMirrorWindow(); }
            virtual void hideMirrorWindow() { return Compositor_014::hideMirrorWindow(); }
            virtual bool isMirrorWindowVisible() { return Compositor_014::isMirrorWindowVisible(); }
            virtual void compositorDumpImages() { return Compositor_014::compositorDumpImages(); }
            virtual bool shouldAppRenderWithLowResources() { return Compositor_014::shouldAppRenderWithLowResources(); }
            virtual void forceInterleavedReprojectionOn(bool on) { return Compositor_014::forceInterleavedReprojectionOn(on); }
            virtual void forceReconnectProcess() { return Compositor_014::forceReconnectProcess(); }
            virtual void suspendRendering(bool suspend) { return Compositor_014::suspendRendering(suspend); }
    };

    //

    struct Compositor_015
    {
        static void setTrackingSpace(TrackingUniverseOrigin origin);
        static TrackingUniverseOrigin getTrackingSpace();

        static CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose);
        static CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags);
        static void clearLastSubmittedFrame();
        static void postPresentHandoff();

        static bool getFrameTiming(FrameTiming_0_9_15* timing, uint32_t framesAgo);
        static float getFrameTimeRemaining();
        static void getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize);

        static void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background);
        static void fadeGrid(float seconds, bool fadeGridIn);

        static CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount);
        static void clearSkyboxOverride();

        static void compositorBringToFront();
        static void compositorGoToBack();
        static void compositorQuit();
        static bool isFullscreen();
        static uint32_t getCurrentSceneFocusProcess();
        static uint32_t getLastFrameRenderer();
        static bool canRenderScene();

        static void showMirrorWindow();
        static void hideMirrorWindow();
        static bool isMirrorWindowVisible();

        static void compositorDumpImages();
        static bool shouldAppRenderWithLowResources();
        static void forceInterleavedReprojectionOn(bool on);
        static void forceReconnectProcess();
        static void suspendRendering(bool suspend);

        static CompositorError requestScreenshot(ScreenshotType screenshotType, const char* destinationFilename, const char* vrDestinationFilename);
        static ScreenshotType getCurrentScreenshotType();

        static CompositorError getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView);
        static CompositorError getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle);
        static bool releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle);
        static void lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle);
        static void unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle);

        void* setTrackingSpace_ = (void*) setTrackingSpace;
        void* getTrackingSpace_ = (void*) getTrackingSpace;
        void* waitGetPoses_ = (void*) waitGetPoses;
        void* getLastPoses_ = (void*) getLastPoses;
        void* getLastPoseForTrackedDeviceIndex_ = (void*) getLastPoseForTrackedDeviceIndex;
        void* submit_ = (void*) submit;
        void* clearLastSubmittedFrame_ = (void*) clearLastSubmittedFrame;
        void* postPresentHandoff_ = (void*) postPresentHandoff;
        void* getFrameTiming_ = (void*) getFrameTiming;
        void* getFrameTimeRemaining_ = (void*) getFrameTimeRemaining;
        void* getCumulativeStats_ = (void*) getCumulativeStats;
        void* fadeToColor_ = (void*) fadeToColor;
        void* fadeGrid_ = (void*) fadeGrid;
        void* setSkyboxOverride_ = (void*) setSkyboxOverride;
        void* clearSkyboxOverride_ = (void*) clearSkyboxOverride;
        void* compositorBringToFront_ = (void*) compositorBringToFront;
        void* compositorGoToBack_ = (void*) compositorGoToBack;
        void* compositorQuit_ = (void*) compositorQuit;
        void* isFullscreen_ = (void*) isFullscreen;
        void* getCurrentSceneFocusProcess_ = (void*) getCurrentSceneFocusProcess;
        void* getLastFrameRenderer_ = (void*) getLastFrameRenderer;
        void* canRenderScene_ = (void*) canRenderScene;
        void* showMirrorWindow_ = (void*) showMirrorWindow;
        void* hideMirrorWindow_ = (void*) hideMirrorWindow;
        void* isMirrorWindowVisible_ = (void*) isMirrorWindowVisible;
        void* compositorDumpImages_ = (void*) compositorDumpImages;
        void* shouldAppRenderWithLowResources_ = (void*) shouldAppRenderWithLowResources;
        void* forceInterleavedReprojectionOn_ = (void*) forceInterleavedReprojectionOn;
        void* forceReconnectProcess_ = (void*) forceReconnectProcess;
        void* suspendRendering_ = (void*) suspendRendering;
        void* requestScreenshot_ = (void*) requestScreenshot;
        void* getCurrentScreenshotType_ = (void*) getCurrentScreenshotType;
        void* getMirrorTextureD3D11_ = (void*) getMirrorTextureD3D11;
        void* getMirrorTextureGL_ = (void*) getMirrorTextureGL;
        void* releaseSharedGLTexture_ = (void*) releaseSharedGLTexture;
        void* lockGLSharedTextureForAccess_ = (void*) lockGLSharedTextureForAccess;
        void* unlockGLSharedTextureForAccess_ = (void*) unlockGLSharedTextureForAccess;
    };

    class Compositor_015_v
    {
        public:
            virtual void setTrackingSpace(TrackingUniverseOrigin origin) { return Compositor_015::setTrackingSpace(origin); }
            virtual TrackingUniverseOrigin getTrackingSpace() { return Compositor_015::getTrackingSpace(); }
            virtual CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_015::waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_015::getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose) { return Compositor_015::getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose); }
            virtual CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags) { return Compositor_015::submit(eye, texture, bounds, submitFlags); }
            virtual void clearLastSubmittedFrame() { return Compositor_015::clearLastSubmittedFrame(); }
            virtual void postPresentHandoff() { return Compositor_015::postPresentHandoff(); }
            virtual bool getFrameTiming(FrameTiming_0_9_15* timing, uint32_t framesAgo) { return Compositor_015::getFrameTiming(timing, framesAgo); }
            virtual float getFrameTimeRemaining() { return Compositor_015::getFrameTimeRemaining(); }
            virtual void getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize) { return Compositor_015::getCumulativeStats(stats, bufferSize); }
            virtual void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background) { return Compositor_015::fadeToColor(seconds, red, green, blue, alpha, background); }
            virtual void fadeGrid(float seconds, bool fadeGridIn) { return Compositor_015::fadeGrid(seconds, fadeGridIn); }
            virtual CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount) { return Compositor_015::setSkyboxOverride(textures, texturesCount); }
            virtual void clearSkyboxOverride() { return Compositor_015::clearSkyboxOverride(); }
            virtual void compositorBringToFront() { return Compositor_015::compositorBringToFront(); }
            virtual void compositorGoToBack() { return Compositor_015::compositorGoToBack(); }
            virtual void compositorQuit() { return Compositor_015::compositorQuit(); }
            virtual bool isFullscreen() { return Compositor_015::isFullscreen(); }
            virtual uint32_t getCurrentSceneFocusProcess() { return Compositor_015::getCurrentSceneFocusProcess(); }
            virtual uint32_t getLastFrameRenderer() { return Compositor_015::getLastFrameRenderer(); }
            virtual bool canRenderScene() { return Compositor_015::canRenderScene(); }
            virtual void showMirrorWindow() { return Compositor_015::showMirrorWindow(); }
            virtual void hideMirrorWindow() { return Compositor_015::hideMirrorWindow(); }
            virtual bool isMirrorWindowVisible() { return Compositor_015::isMirrorWindowVisible(); }
            virtual void compositorDumpImages() { return Compositor_015::compositorDumpImages(); }
            virtual bool shouldAppRenderWithLowResources() { return Compositor_015::shouldAppRenderWithLowResources(); }
            virtual void forceInterleavedReprojectionOn(bool on) { return Compositor_015::forceInterleavedReprojectionOn(on); }
            virtual void forceReconnectProcess() { return Compositor_015::forceReconnectProcess(); }
            virtual void suspendRendering(bool suspend) { return Compositor_015::suspendRendering(suspend); }
            virtual CompositorError requestScreenshot(ScreenshotType screenshotType, const char* destinationFilename, const char* vrDestinationFilename) { return Compositor_015::requestScreenshot(screenshotType, destinationFilename, vrDestinationFilename); }
            virtual ScreenshotType getCurrentScreenshotType() { return Compositor_015::getCurrentScreenshotType(); }
            virtual CompositorError getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView) { return Compositor_015::getMirrorTextureD3D11(eye, deviceOrResource, shaderResourceView); }
            virtual CompositorError getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle) { return Compositor_015::getMirrorTextureGL(eye, textureId, sharedTextureHandle); }
            virtual bool releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle) { return Compositor_015::releaseSharedGLTexture(textureId, sharedTextureHandle); }
            virtual void lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle) { return Compositor_015::lockGLSharedTextureForAccess(sharedTextureHandle); }
            virtual void unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle) { return Compositor_015::unlockGLSharedTextureForAccess(sharedTextureHandle); }
    };

    //

    struct Compositor_016
    {
        static void setTrackingSpace(TrackingUniverseOrigin origin);
        static TrackingUniverseOrigin getTrackingSpace();

        static CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose);
        static CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags);
        static void clearLastSubmittedFrame();
        static void postPresentHandoff();

        static bool getFrameTiming(FrameTiming_1_0_2* timing, uint32_t framesAgo);
        static float getFrameTimeRemaining();
        static void getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize);

        static void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background);
        static void fadeGrid(float seconds, bool fadeGridIn);

        static CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount);
        static void clearSkyboxOverride();

        static void compositorBringToFront();
        static void compositorGoToBack();
        static void compositorQuit();
        static bool isFullscreen();
        static uint32_t getCurrentSceneFocusProcess();
        static uint32_t getLastFrameRenderer();
        static bool canRenderScene();

        static void showMirrorWindow();
        static void hideMirrorWindow();
        static bool isMirrorWindowVisible();

        static void compositorDumpImages();
        static bool shouldAppRenderWithLowResources();
        static void forceInterleavedReprojectionOn(bool on);
        static void forceReconnectProcess();
        static void suspendRendering(bool suspend);

        static CompositorError getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView);
        static CompositorError getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle);
        static bool releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle);
        static void lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle);
        static void unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle);

        void* setTrackingSpace_ = (void*) setTrackingSpace;
        void* getTrackingSpace_ = (void*) getTrackingSpace;
        void* waitGetPoses_ = (void*) waitGetPoses;
        void* getLastPoses_ = (void*) getLastPoses;
        void* getLastPoseForTrackedDeviceIndex_ = (void*) getLastPoseForTrackedDeviceIndex;
        void* submit_ = (void*) submit;
        void* clearLastSubmittedFrame_ = (void*) clearLastSubmittedFrame;
        void* postPresentHandoff_ = (void*) postPresentHandoff;
        void* getFrameTiming_ = (void*) getFrameTiming;
        void* getFrameTimeRemaining_ = (void*) getFrameTimeRemaining;
        void* getCumulativeStats_ = (void*) getCumulativeStats;
        void* fadeToColor_ = (void*) fadeToColor;
        void* fadeGrid_ = (void*) fadeGrid;
        void* setSkyboxOverride_ = (void*) setSkyboxOverride;
        void* clearSkyboxOverride_ = (void*) clearSkyboxOverride;
        void* compositorBringToFront_ = (void*) compositorBringToFront;
        void* compositorGoToBack_ = (void*) compositorGoToBack;
        void* compositorQuit_ = (void*) compositorQuit;
        void* isFullscreen_ = (void*) isFullscreen;
        void* getCurrentSceneFocusProcess_ = (void*) getCurrentSceneFocusProcess;
        void* getLastFrameRenderer_ = (void*) getLastFrameRenderer;
        void* canRenderScene_ = (void*) canRenderScene;
        void* showMirrorWindow_ = (void*) showMirrorWindow;
        void* hideMirrorWindow_ = (void*) hideMirrorWindow;
        void* isMirrorWindowVisible_ = (void*) isMirrorWindowVisible;
        void* compositorDumpImages_ = (void*) compositorDumpImages;
        void* shouldAppRenderWithLowResources_ = (void*) shouldAppRenderWithLowResources;
        void* forceInterleavedReprojectionOn_ = (void*) forceInterleavedReprojectionOn;
        void* forceReconnectProcess_ = (void*) forceReconnectProcess;
        void* suspendRendering_ = (void*) suspendRendering;
        void* getMirrorTextureD3D11_ = (void*) getMirrorTextureD3D11;
        void* getMirrorTextureGL_ = (void*) getMirrorTextureGL;
        void* releaseSharedGLTexture_ = (void*) releaseSharedGLTexture;
        void* lockGLSharedTextureForAccess_ = (void*) lockGLSharedTextureForAccess;
        void* unlockGLSharedTextureForAccess_ = (void*) unlockGLSharedTextureForAccess;
    };

    class Compositor_016_v
    {
        public:
            virtual void setTrackingSpace(TrackingUniverseOrigin origin) { return Compositor_016::setTrackingSpace(origin); }
            virtual TrackingUniverseOrigin getTrackingSpace() { return Compositor_016::getTrackingSpace(); }
            virtual CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_016::waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_016::getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose) { return Compositor_016::getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose); }
            virtual CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags) { return Compositor_016::submit(eye, texture, bounds, submitFlags); }
            virtual void clearLastSubmittedFrame() { return Compositor_016::clearLastSubmittedFrame(); }
            virtual void postPresentHandoff() { return Compositor_016::postPresentHandoff(); }
            virtual bool getFrameTiming(FrameTiming_1_0_2* timing, uint32_t framesAgo) { return Compositor_016::getFrameTiming(timing, framesAgo); }
            virtual float getFrameTimeRemaining() { return Compositor_016::getFrameTimeRemaining(); }
            virtual void getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize) { return Compositor_016::getCumulativeStats(stats, bufferSize); }
            virtual void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background) { return Compositor_016::fadeToColor(seconds, red, green, blue, alpha, background); }
            virtual void fadeGrid(float seconds, bool fadeGridIn) { return Compositor_016::fadeGrid(seconds, fadeGridIn); }
            virtual CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount) { return Compositor_016::setSkyboxOverride(textures, texturesCount); }
            virtual void clearSkyboxOverride() { return Compositor_016::clearSkyboxOverride(); }
            virtual void compositorBringToFront() { return Compositor_016::compositorBringToFront(); }
            virtual void compositorGoToBack() { return Compositor_016::compositorGoToBack(); }
            virtual void compositorQuit() { return Compositor_016::compositorQuit(); }
            virtual bool isFullscreen() { return Compositor_016::isFullscreen(); }
            virtual uint32_t getCurrentSceneFocusProcess() { return Compositor_016::getCurrentSceneFocusProcess(); }
            virtual uint32_t getLastFrameRenderer() { return Compositor_016::getLastFrameRenderer(); }
            virtual bool canRenderScene() { return Compositor_016::canRenderScene(); }
            virtual void showMirrorWindow() { return Compositor_016::showMirrorWindow(); }
            virtual void hideMirrorWindow() { return Compositor_016::hideMirrorWindow(); }
            virtual bool isMirrorWindowVisible() { return Compositor_016::isMirrorWindowVisible(); }
            virtual void compositorDumpImages() { return Compositor_016::compositorDumpImages(); }
            virtual bool shouldAppRenderWithLowResources() { return Compositor_016::shouldAppRenderWithLowResources(); }
            virtual void forceInterleavedReprojectionOn(bool on) { return Compositor_016::forceInterleavedReprojectionOn(on); }
            virtual void forceReconnectProcess() { return Compositor_016::forceReconnectProcess(); }
            virtual void suspendRendering(bool suspend) { return Compositor_016::suspendRendering(suspend); }
            virtual CompositorError getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView) { return Compositor_016::getMirrorTextureD3D11(eye, deviceOrResource, shaderResourceView); }
            virtual CompositorError getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle) { return Compositor_016::getMirrorTextureGL(eye, textureId, sharedTextureHandle); }
            virtual bool releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle) { return Compositor_016::releaseSharedGLTexture(textureId, sharedTextureHandle); }
            virtual void lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle) { return Compositor_016::lockGLSharedTextureForAccess(sharedTextureHandle); }
            virtual void unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle) { return Compositor_016::unlockGLSharedTextureForAccess(sharedTextureHandle); }
    };

    //

    struct Compositor_018
    {
        static void setTrackingSpace(TrackingUniverseOrigin origin);
        static TrackingUniverseOrigin getTrackingSpace();

        static CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose);
        static CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags);
        static void clearLastSubmittedFrame();
        static void postPresentHandoff();

        static bool getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo);
        static uint32_t getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames);
        static float getFrameTimeRemaining();
        static void getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize);

        static void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background);
        static Color getCurrentFadeColor(bool background);
        static void fadeGrid(float seconds, bool fadeGridIn);
        static float getCurrentGridAlpha();

        static CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount);
        static void clearSkyboxOverride();

        static void compositorBringToFront();
        static void compositorGoToBack();
        static void compositorQuit();
        static bool isFullscreen();
        static uint32_t getCurrentSceneFocusProcess();
        static uint32_t getLastFrameRenderer();
        static bool canRenderScene();

        static void showMirrorWindow();
        static void hideMirrorWindow();
        static bool isMirrorWindowVisible();

        static void compositorDumpImages();
        static bool shouldAppRenderWithLowResources();
        static void forceInterleavedReprojectionOn(bool on);
        static void forceReconnectProcess();
        static void suspendRendering(bool suspend);

        static CompositorError getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView);
        static CompositorError getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle);
        static bool releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle);
        static void lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle);
        static void unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle);

        void* setTrackingSpace_ = (void*) setTrackingSpace;
        void* getTrackingSpace_ = (void*) getTrackingSpace;
        void* waitGetPoses_ = (void*) waitGetPoses;
        void* getLastPoses_ = (void*) getLastPoses;
        void* getLastPoseForTrackedDeviceIndex_ = (void*) getLastPoseForTrackedDeviceIndex;
        void* submit_ = (void*) submit;
        void* clearLastSubmittedFrame_ = (void*) clearLastSubmittedFrame;
        void* postPresentHandoff_ = (void*) postPresentHandoff;
        void* getFrameTiming_ = (void*) getFrameTiming;
        void* getFrameTimings_ = (void*) getFrameTimings;
        void* getFrameTimeRemaining_ = (void*) getFrameTimeRemaining;
        void* getCumulativeStats_ = (void*) getCumulativeStats;
        void* fadeToColor_ = (void*) fadeToColor;
        void* getCurrentFadeColor_ = (void*) getCurrentFadeColor;
        void* fadeGrid_ = (void*) fadeGrid;
        void* getCurrentGridAlpha_ = (void*) getCurrentGridAlpha;
        void* setSkyboxOverride_ = (void*) setSkyboxOverride;
        void* clearSkyboxOverride_ = (void*) clearSkyboxOverride;
        void* compositorBringToFront_ = (void*) compositorBringToFront;
        void* compositorGoToBack_ = (void*) compositorGoToBack;
        void* compositorQuit_ = (void*) compositorQuit;
        void* isFullscreen_ = (void*) isFullscreen;
        void* getCurrentSceneFocusProcess_ = (void*) getCurrentSceneFocusProcess;
        void* getLastFrameRenderer_ = (void*) getLastFrameRenderer;
        void* canRenderScene_ = (void*) canRenderScene;
        void* showMirrorWindow_ = (void*) showMirrorWindow;
        void* hideMirrorWindow_ = (void*) hideMirrorWindow;
        void* isMirrorWindowVisible_ = (void*) isMirrorWindowVisible;
        void* compositorDumpImages_ = (void*) compositorDumpImages;
        void* shouldAppRenderWithLowResources_ = (void*) shouldAppRenderWithLowResources;
        void* forceInterleavedReprojectionOn_ = (void*) forceInterleavedReprojectionOn;
        void* forceReconnectProcess_ = (void*) forceReconnectProcess;
        void* suspendRendering_ = (void*) suspendRendering;
        void* getMirrorTextureD3D11_ = (void*) getMirrorTextureD3D11;
        void* getMirrorTextureGL_ = (void*) getMirrorTextureGL;
        void* releaseSharedGLTexture_ = (void*) releaseSharedGLTexture;
        void* lockGLSharedTextureForAccess_ = (void*) lockGLSharedTextureForAccess;
        void* unlockGLSharedTextureForAccess_ = (void*) unlockGLSharedTextureForAccess;
    };

    class Compositor_018_v
    {
        public:
            virtual void setTrackingSpace(TrackingUniverseOrigin origin) { return Compositor_018::setTrackingSpace(origin); }
            virtual TrackingUniverseOrigin getTrackingSpace() { return Compositor_018::getTrackingSpace(); }
            virtual CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_018::waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_018::getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose) { return Compositor_018::getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose); }
            virtual CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags) { return Compositor_018::submit(eye, texture, bounds, submitFlags); }
            virtual void clearLastSubmittedFrame() { return Compositor_018::clearLastSubmittedFrame(); }
            virtual void postPresentHandoff() { return Compositor_018::postPresentHandoff(); }
            virtual bool getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo) { return Compositor_018::getFrameTiming(timing, framesAgo); }
            virtual uint32_t getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames) { return Compositor_018::getFrameTimings(timings, nFrames); }
            virtual float getFrameTimeRemaining() { return Compositor_018::getFrameTimeRemaining(); }
            virtual void getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize) { return Compositor_018::getCumulativeStats(stats, bufferSize); }
            virtual void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background) { return Compositor_018::fadeToColor(seconds, red, green, blue, alpha, background); }
            virtual Color getCurrentFadeColor(bool background) { return Compositor_018::getCurrentFadeColor(background); }
            virtual void fadeGrid(float seconds, bool fadeGridIn) { return Compositor_018::fadeGrid(seconds, fadeGridIn); }
            virtual float getCurrentGridAlpha() { return Compositor_018::getCurrentGridAlpha(); }
            virtual CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount) { return Compositor_018::setSkyboxOverride(textures, texturesCount); }
            virtual void clearSkyboxOverride() { return Compositor_018::clearSkyboxOverride(); }
            virtual void compositorBringToFront() { return Compositor_018::compositorBringToFront(); }
            virtual void compositorGoToBack() { return Compositor_018::compositorGoToBack(); }
            virtual void compositorQuit() { return Compositor_018::compositorQuit(); }
            virtual bool isFullscreen() { return Compositor_018::isFullscreen(); }
            virtual uint32_t getCurrentSceneFocusProcess() { return Compositor_018::getCurrentSceneFocusProcess(); }
            virtual uint32_t getLastFrameRenderer() { return Compositor_018::getLastFrameRenderer(); }
            virtual bool canRenderScene() { return Compositor_018::canRenderScene(); }
            virtual void showMirrorWindow() { return Compositor_018::showMirrorWindow(); }
            virtual void hideMirrorWindow() { return Compositor_018::hideMirrorWindow(); }
            virtual bool isMirrorWindowVisible() { return Compositor_018::isMirrorWindowVisible(); }
            virtual void compositorDumpImages() { return Compositor_018::compositorDumpImages(); }
            virtual bool shouldAppRenderWithLowResources() { return Compositor_018::shouldAppRenderWithLowResources(); }
            virtual void forceInterleavedReprojectionOn(bool on) { return Compositor_018::forceInterleavedReprojectionOn(on); }
            virtual void forceReconnectProcess() { return Compositor_018::forceReconnectProcess(); }
            virtual void suspendRendering(bool suspend) { return Compositor_018::suspendRendering(suspend); }
            virtual CompositorError getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView) { return Compositor_018::getMirrorTextureD3D11(eye, deviceOrResource, shaderResourceView); }
            virtual CompositorError getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle) { return Compositor_018::getMirrorTextureGL(eye, textureId, sharedTextureHandle); }
            virtual bool releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle) { return Compositor_018::releaseSharedGLTexture(textureId, sharedTextureHandle); }
            virtual void lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle) { return Compositor_018::lockGLSharedTextureForAccess(sharedTextureHandle); }
            virtual void unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle) { return Compositor_018::unlockGLSharedTextureForAccess(sharedTextureHandle); }
    };

    //

    struct Compositor_019
    {
        static void setTrackingSpace(TrackingUniverseOrigin origin);
        static TrackingUniverseOrigin getTrackingSpace();

        static CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose);
        static CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags);
        static void clearLastSubmittedFrame();
        static void postPresentHandoff();

        static bool getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo);
        static uint32_t getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames);
        static float getFrameTimeRemaining();
        static void getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize);

        static void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background);
        static Color getCurrentFadeColor(bool background);
        static void fadeGrid(float seconds, bool fadeGridIn);
        static float getCurrentGridAlpha();

        static CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount);
        static void clearSkyboxOverride();

        static void compositorBringToFront();
        static void compositorGoToBack();
        static void compositorQuit();
        static bool isFullscreen();
        static uint32_t getCurrentSceneFocusProcess();
        static uint32_t getLastFrameRenderer();
        static bool canRenderScene();

        static void showMirrorWindow();
        static void hideMirrorWindow();
        static bool isMirrorWindowVisible();

        static void compositorDumpImages();
        static bool shouldAppRenderWithLowResources();
        static void forceInterleavedReprojectionOn(bool on);
        static void forceReconnectProcess();
        static void suspendRendering(bool suspend);

        static CompositorError getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView);
        static CompositorError getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle);
        static bool releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle);
        static void lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle);
        static void unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle);

        static uint32_t getVulkanInstanceExtensionsRequired(char* value, uint32_t bufferSize);
        static uint32_t getVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* device, char* value, uint32_t bufferSize);

        void* setTrackingSpace_ = (void*) setTrackingSpace;
        void* getTrackingSpace_ = (void*) getTrackingSpace;
        void* waitGetPoses_ = (void*) waitGetPoses;
        void* getLastPoses_ = (void*) getLastPoses;
        void* getLastPoseForTrackedDeviceIndex_ = (void*) getLastPoseForTrackedDeviceIndex;
        void* submit_ = (void*) submit;
        void* clearLastSubmittedFrame_ = (void*) clearLastSubmittedFrame;
        void* postPresentHandoff_ = (void*) postPresentHandoff;
        void* getFrameTiming_ = (void*) getFrameTiming;
        void* getFrameTimings_ = (void*) getFrameTimings;
        void* getFrameTimeRemaining_ = (void*) getFrameTimeRemaining;
        void* getCumulativeStats_ = (void*) getCumulativeStats;
        void* fadeToColor_ = (void*) fadeToColor;
        void* getCurrentFadeColor_ = (void*) getCurrentFadeColor;
        void* fadeGrid_ = (void*) fadeGrid;
        void* getCurrentGridAlpha_ = (void*) getCurrentGridAlpha;
        void* setSkyboxOverride_ = (void*) setSkyboxOverride;
        void* clearSkyboxOverride_ = (void*) clearSkyboxOverride;
        void* compositorBringToFront_ = (void*) compositorBringToFront;
        void* compositorGoToBack_ = (void*) compositorGoToBack;
        void* compositorQuit_ = (void*) compositorQuit;
        void* isFullscreen_ = (void*) isFullscreen;
        void* getCurrentSceneFocusProcess_ = (void*) getCurrentSceneFocusProcess;
        void* getLastFrameRenderer_ = (void*) getLastFrameRenderer;
        void* canRenderScene_ = (void*) canRenderScene;
        void* showMirrorWindow_ = (void*) showMirrorWindow;
        void* hideMirrorWindow_ = (void*) hideMirrorWindow;
        void* isMirrorWindowVisible_ = (void*) isMirrorWindowVisible;
        void* compositorDumpImages_ = (void*) compositorDumpImages;
        void* shouldAppRenderWithLowResources_ = (void*) shouldAppRenderWithLowResources;
        void* forceInterleavedReprojectionOn_ = (void*) forceInterleavedReprojectionOn;
        void* forceReconnectProcess_ = (void*) forceReconnectProcess;
        void* suspendRendering_ = (void*) suspendRendering;
        void* getMirrorTextureD3D11_ = (void*) getMirrorTextureD3D11;
        void* getMirrorTextureGL_ = (void*) getMirrorTextureGL;
        void* releaseSharedGLTexture_ = (void*) releaseSharedGLTexture;
        void* lockGLSharedTextureForAccess_ = (void*) lockGLSharedTextureForAccess;
        void* unlockGLSharedTextureForAccess_ = (void*) unlockGLSharedTextureForAccess;
        void* getVulkanInstanceExtensionsRequired_ = (void*) getVulkanInstanceExtensionsRequired;
        void* getVulkanDeviceExtensionsRequired_ = (void*) getVulkanDeviceExtensionsRequired;
    };

    class Compositor_019_v
    {
        public:
            virtual void setTrackingSpace(TrackingUniverseOrigin origin) { return Compositor_019::setTrackingSpace(origin); }
            virtual TrackingUniverseOrigin getTrackingSpace() { return Compositor_019::getTrackingSpace(); }
            virtual CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_019::waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_019::getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose) { return Compositor_019::getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose); }
            virtual CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags) { return Compositor_019::submit(eye, texture, bounds, submitFlags); }
            virtual void clearLastSubmittedFrame() { return Compositor_019::clearLastSubmittedFrame(); }
            virtual void postPresentHandoff() { return Compositor_019::postPresentHandoff(); }
            virtual bool getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo) { return Compositor_019::getFrameTiming(timing, framesAgo); }
            virtual uint32_t getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames) { return Compositor_019::getFrameTimings(timings, nFrames); }
            virtual float getFrameTimeRemaining() { return Compositor_019::getFrameTimeRemaining(); }
            virtual void getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize) { return Compositor_019::getCumulativeStats(stats, bufferSize); }
            virtual void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background) { return Compositor_019::fadeToColor(seconds, red, green, blue, alpha, background); }
            virtual Color getCurrentFadeColor(bool background) { return Compositor_019::getCurrentFadeColor(background); }
            virtual void fadeGrid(float seconds, bool fadeGridIn) { return Compositor_019::fadeGrid(seconds, fadeGridIn); }
            virtual float getCurrentGridAlpha() { return Compositor_019::getCurrentGridAlpha(); }
            virtual CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount) { return Compositor_019::setSkyboxOverride(textures, texturesCount); }
            virtual void clearSkyboxOverride() { return Compositor_019::clearSkyboxOverride(); }
            virtual void compositorBringToFront() { return Compositor_019::compositorBringToFront(); }
            virtual void compositorGoToBack() { return Compositor_019::compositorGoToBack(); }
            virtual void compositorQuit() { return Compositor_019::compositorQuit(); }
            virtual bool isFullscreen() { return Compositor_019::isFullscreen(); }
            virtual uint32_t getCurrentSceneFocusProcess() { return Compositor_019::getCurrentSceneFocusProcess(); }
            virtual uint32_t getLastFrameRenderer() { return Compositor_019::getLastFrameRenderer(); }
            virtual bool canRenderScene() { return Compositor_019::canRenderScene(); }
            virtual void showMirrorWindow() { return Compositor_019::showMirrorWindow(); }
            virtual void hideMirrorWindow() { return Compositor_019::hideMirrorWindow(); }
            virtual bool isMirrorWindowVisible() { return Compositor_019::isMirrorWindowVisible(); }
            virtual void compositorDumpImages() { return Compositor_019::compositorDumpImages(); }
            virtual bool shouldAppRenderWithLowResources() { return Compositor_019::shouldAppRenderWithLowResources(); }
            virtual void forceInterleavedReprojectionOn(bool on) { return Compositor_019::forceInterleavedReprojectionOn(on); }
            virtual void forceReconnectProcess() { return Compositor_019::forceReconnectProcess(); }
            virtual void suspendRendering(bool suspend) { return Compositor_019::suspendRendering(suspend); }
            virtual CompositorError getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView) { return Compositor_019::getMirrorTextureD3D11(eye, deviceOrResource, shaderResourceView); }
            virtual CompositorError getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle) { return Compositor_019::getMirrorTextureGL(eye, textureId, sharedTextureHandle); }
            virtual bool releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle) { return Compositor_019::releaseSharedGLTexture(textureId, sharedTextureHandle); }
            virtual void lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle) { return Compositor_019::lockGLSharedTextureForAccess(sharedTextureHandle); }
            virtual void unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle) { return Compositor_019::unlockGLSharedTextureForAccess(sharedTextureHandle); }
            virtual uint32_t getVulkanInstanceExtensionsRequired(char* value, uint32_t bufferSize) { return Compositor_019::getVulkanInstanceExtensionsRequired(value, bufferSize); }
            virtual uint32_t getVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* device, char* value, uint32_t bufferSize) { return Compositor_019::getVulkanDeviceExtensionsRequired(device, value, bufferSize); }
    };

    //

    struct Compositor_020
    {
        static void setTrackingSpace(TrackingUniverseOrigin origin);
        static TrackingUniverseOrigin getTrackingSpace();

        static CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose);
        static CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags);
        static void clearLastSubmittedFrame();
        static void postPresentHandoff();

        static bool getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo);
        static uint32_t getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames);
        static float getFrameTimeRemaining();
        static void getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize);

        static void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background);
        static Color getCurrentFadeColor(bool background);
        static void fadeGrid(float seconds, bool fadeGridIn);
        static float getCurrentGridAlpha();

        static CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount);
        static void clearSkyboxOverride();

        static void compositorBringToFront();
        static void compositorGoToBack();
        static void compositorQuit();
        static bool isFullscreen();
        static uint32_t getCurrentSceneFocusProcess();
        static uint32_t getLastFrameRenderer();
        static bool canRenderScene();

        static void showMirrorWindow();
        static void hideMirrorWindow();
        static bool isMirrorWindowVisible();

        static void compositorDumpImages();
        static bool shouldAppRenderWithLowResources();
        static void forceInterleavedReprojectionOn(bool on);
        static void forceReconnectProcess();
        static void suspendRendering(bool suspend);

        static CompositorError getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView);
        static void releaseMirrorTextureD3D11(void* shaderResourceView);
        static CompositorError getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle);
        static bool releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle);
        static void lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle);
        static void unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle);

        static uint32_t getVulkanInstanceExtensionsRequired(char* value, uint32_t bufferSize);
        static uint32_t getVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* device, char* value, uint32_t bufferSize);

        void* setTrackingSpace_ = (void*) setTrackingSpace;
        void* getTrackingSpace_ = (void*) getTrackingSpace;
        void* waitGetPoses_ = (void*) waitGetPoses;
        void* getLastPoses_ = (void*) getLastPoses;
        void* getLastPoseForTrackedDeviceIndex_ = (void*) getLastPoseForTrackedDeviceIndex;
        void* submit_ = (void*) submit;
        void* clearLastSubmittedFrame_ = (void*) clearLastSubmittedFrame;
        void* postPresentHandoff_ = (void*) postPresentHandoff;
        void* getFrameTiming_ = (void*) getFrameTiming;
        void* getFrameTimings_ = (void*) getFrameTimings;
        void* getFrameTimeRemaining_ = (void*) getFrameTimeRemaining;
        void* getCumulativeStats_ = (void*) getCumulativeStats;
        void* fadeToColor_ = (void*) fadeToColor;
        void* getCurrentFadeColor_ = (void*) getCurrentFadeColor;
        void* fadeGrid_ = (void*) fadeGrid;
        void* getCurrentGridAlpha_ = (void*) getCurrentGridAlpha;
        void* setSkyboxOverride_ = (void*) setSkyboxOverride;
        void* clearSkyboxOverride_ = (void*) clearSkyboxOverride;
        void* compositorBringToFront_ = (void*) compositorBringToFront;
        void* compositorGoToBack_ = (void*) compositorGoToBack;
        void* compositorQuit_ = (void*) compositorQuit;
        void* isFullscreen_ = (void*) isFullscreen;
        void* getCurrentSceneFocusProcess_ = (void*) getCurrentSceneFocusProcess;
        void* getLastFrameRenderer_ = (void*) getLastFrameRenderer;
        void* canRenderScene_ = (void*) canRenderScene;
        void* showMirrorWindow_ = (void*) showMirrorWindow;
        void* hideMirrorWindow_ = (void*) hideMirrorWindow;
        void* isMirrorWindowVisible_ = (void*) isMirrorWindowVisible;
        void* compositorDumpImages_ = (void*) compositorDumpImages;
        void* shouldAppRenderWithLowResources_ = (void*) shouldAppRenderWithLowResources;
        void* forceInterleavedReprojectionOn_ = (void*) forceInterleavedReprojectionOn;
        void* forceReconnectProcess_ = (void*) forceReconnectProcess;
        void* suspendRendering_ = (void*) suspendRendering;
        void* getMirrorTextureD3D11_ = (void*) getMirrorTextureD3D11;
        void* releaseMirrorTextureD3D11_ = (void*) releaseMirrorTextureD3D11;
        void* getMirrorTextureGL_ = (void*) getMirrorTextureGL;
        void* releaseSharedGLTexture_ = (void*) releaseSharedGLTexture;
        void* lockGLSharedTextureForAccess_ = (void*) lockGLSharedTextureForAccess;
        void* unlockGLSharedTextureForAccess_ = (void*) unlockGLSharedTextureForAccess;
        void* getVulkanInstanceExtensionsRequired_ = (void*) getVulkanInstanceExtensionsRequired;
        void* getVulkanDeviceExtensionsRequired_ = (void*) getVulkanDeviceExtensionsRequired;
    };

    class Compositor_020_v
    {
        public:
            virtual void setTrackingSpace(TrackingUniverseOrigin origin) { return Compositor_020::setTrackingSpace(origin); }
            virtual TrackingUniverseOrigin getTrackingSpace() { return Compositor_020::getTrackingSpace(); }
            virtual CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_020::waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_020::getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose) { return Compositor_020::getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose); }
            virtual CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags) { return Compositor_020::submit(eye, texture, bounds, submitFlags); }
            virtual void clearLastSubmittedFrame() { return Compositor_020::clearLastSubmittedFrame(); }
            virtual void postPresentHandoff() { return Compositor_020::postPresentHandoff(); }
            virtual bool getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo) { return Compositor_020::getFrameTiming(timing, framesAgo); }
            virtual uint32_t getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames) { return Compositor_020::getFrameTimings(timings, nFrames); }
            virtual float getFrameTimeRemaining() { return Compositor_020::getFrameTimeRemaining(); }
            virtual void getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize) { return Compositor_020::getCumulativeStats(stats, bufferSize); }
            virtual void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background) { return Compositor_020::fadeToColor(seconds, red, green, blue, alpha, background); }
            virtual Color getCurrentFadeColor(bool background) { return Compositor_020::getCurrentFadeColor(background); }
            virtual void fadeGrid(float seconds, bool fadeGridIn) { return Compositor_020::fadeGrid(seconds, fadeGridIn); }
            virtual float getCurrentGridAlpha() { return Compositor_020::getCurrentGridAlpha(); }
            virtual CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount) { return Compositor_020::setSkyboxOverride(textures, texturesCount); }
            virtual void clearSkyboxOverride() { return Compositor_020::clearSkyboxOverride(); }
            virtual void compositorBringToFront() { return Compositor_020::compositorBringToFront(); }
            virtual void compositorGoToBack() { return Compositor_020::compositorGoToBack(); }
            virtual void compositorQuit() { return Compositor_020::compositorQuit(); }
            virtual bool isFullscreen() { return Compositor_020::isFullscreen(); }
            virtual uint32_t getCurrentSceneFocusProcess() { return Compositor_020::getCurrentSceneFocusProcess(); }
            virtual uint32_t getLastFrameRenderer() { return Compositor_020::getLastFrameRenderer(); }
            virtual bool canRenderScene() { return Compositor_020::canRenderScene(); }
            virtual void showMirrorWindow() { return Compositor_020::showMirrorWindow(); }
            virtual void hideMirrorWindow() { return Compositor_020::hideMirrorWindow(); }
            virtual bool isMirrorWindowVisible() { return Compositor_020::isMirrorWindowVisible(); }
            virtual void compositorDumpImages() { return Compositor_020::compositorDumpImages(); }
            virtual bool shouldAppRenderWithLowResources() { return Compositor_020::shouldAppRenderWithLowResources(); }
            virtual void forceInterleavedReprojectionOn(bool on) { return Compositor_020::forceInterleavedReprojectionOn(on); }
            virtual void forceReconnectProcess() { return Compositor_020::forceReconnectProcess(); }
            virtual void suspendRendering(bool suspend) { return Compositor_020::suspendRendering(suspend); }
            virtual CompositorError getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView) { return Compositor_020::getMirrorTextureD3D11(eye, deviceOrResource, shaderResourceView); }
            virtual void releaseMirrorTextureD3D11(void* shaderResourceView) { return Compositor_020::releaseMirrorTextureD3D11(shaderResourceView); }
            virtual CompositorError getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle) { return Compositor_020::getMirrorTextureGL(eye, textureId, sharedTextureHandle); }
            virtual bool releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle) { return Compositor_020::releaseSharedGLTexture(textureId, sharedTextureHandle); }
            virtual void lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle) { return Compositor_020::lockGLSharedTextureForAccess(sharedTextureHandle); }
            virtual void unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle) { return Compositor_020::unlockGLSharedTextureForAccess(sharedTextureHandle); }
            virtual uint32_t getVulkanInstanceExtensionsRequired(char* value, uint32_t bufferSize) { return Compositor_020::getVulkanInstanceExtensionsRequired(value, bufferSize); }
            virtual uint32_t getVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* device, char* value, uint32_t bufferSize) { return Compositor_020::getVulkanDeviceExtensionsRequired(device, value, bufferSize); }
    };

    //

    struct Compositor_021
    {
        static void setTrackingSpace(TrackingUniverseOrigin origin);
        static TrackingUniverseOrigin getTrackingSpace();

        static CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose);
        static CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags);
        static void clearLastSubmittedFrame();
        static void postPresentHandoff();

        static bool getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo);
        static uint32_t getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames);
        static float getFrameTimeRemaining();
        static void getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize);

        static void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background);
        static Color getCurrentFadeColor(bool background);
        static void fadeGrid(float seconds, bool fadeGridIn);
        static float getCurrentGridAlpha();

        static CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount);
        static void clearSkyboxOverride();

        static void compositorBringToFront();
        static void compositorGoToBack();
        static void compositorQuit();
        static bool isFullscreen();
        static uint32_t getCurrentSceneFocusProcess();
        static uint32_t getLastFrameRenderer();
        static bool canRenderScene();

        static void showMirrorWindow();
        static void hideMirrorWindow();
        static bool isMirrorWindowVisible();

        static void compositorDumpImages();
        static bool shouldAppRenderWithLowResources();
        static void forceInterleavedReprojectionOn(bool on);
        static void forceReconnectProcess();
        static void suspendRendering(bool suspend);

        static CompositorError getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView);
        static void releaseMirrorTextureD3D11(void* shaderResourceView);
        static CompositorError getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle);
        static bool releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle);
        static void lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle);
        static void unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle);

        static uint32_t getVulkanInstanceExtensionsRequired(char* value, uint32_t bufferSize);
        static uint32_t getVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* device, char* value, uint32_t bufferSize);

        static void setExplicitTimingMode(bool explicitTimingMode);
        static CompositorError submitExplicitTimingData();

        void* setTrackingSpace_ = (void*) setTrackingSpace;
        void* getTrackingSpace_ = (void*) getTrackingSpace;
        void* waitGetPoses_ = (void*) waitGetPoses;
        void* getLastPoses_ = (void*) getLastPoses;
        void* getLastPoseForTrackedDeviceIndex_ = (void*) getLastPoseForTrackedDeviceIndex;
        void* submit_ = (void*) submit;
        void* clearLastSubmittedFrame_ = (void*) clearLastSubmittedFrame;
        void* postPresentHandoff_ = (void*) postPresentHandoff;
        void* getFrameTiming_ = (void*) getFrameTiming;
        void* getFrameTimings_ = (void*) getFrameTimings;
        void* getFrameTimeRemaining_ = (void*) getFrameTimeRemaining;
        void* getCumulativeStats_ = (void*) getCumulativeStats;
        void* fadeToColor_ = (void*) fadeToColor;
        void* getCurrentFadeColor_ = (void*) getCurrentFadeColor;
        void* fadeGrid_ = (void*) fadeGrid;
        void* getCurrentGridAlpha_ = (void*) getCurrentGridAlpha;
        void* setSkyboxOverride_ = (void*) setSkyboxOverride;
        void* clearSkyboxOverride_ = (void*) clearSkyboxOverride;
        void* compositorBringToFront_ = (void*) compositorBringToFront;
        void* compositorGoToBack_ = (void*) compositorGoToBack;
        void* compositorQuit_ = (void*) compositorQuit;
        void* isFullscreen_ = (void*) isFullscreen;
        void* getCurrentSceneFocusProcess_ = (void*) getCurrentSceneFocusProcess;
        void* getLastFrameRenderer_ = (void*) getLastFrameRenderer;
        void* canRenderScene_ = (void*) canRenderScene;
        void* showMirrorWindow_ = (void*) showMirrorWindow;
        void* hideMirrorWindow_ = (void*) hideMirrorWindow;
        void* isMirrorWindowVisible_ = (void*) isMirrorWindowVisible;
        void* compositorDumpImages_ = (void*) compositorDumpImages;
        void* shouldAppRenderWithLowResources_ = (void*) shouldAppRenderWithLowResources;
        void* forceInterleavedReprojectionOn_ = (void*) forceInterleavedReprojectionOn;
        void* forceReconnectProcess_ = (void*) forceReconnectProcess;
        void* suspendRendering_ = (void*) suspendRendering;
        void* getMirrorTextureD3D11_ = (void*) getMirrorTextureD3D11;
        void* releaseMirrorTextureD3D11_ = (void*) releaseMirrorTextureD3D11;
        void* getMirrorTextureGL_ = (void*) getMirrorTextureGL;
        void* releaseSharedGLTexture_ = (void*) releaseSharedGLTexture;
        void* lockGLSharedTextureForAccess_ = (void*) lockGLSharedTextureForAccess;
        void* unlockGLSharedTextureForAccess_ = (void*) unlockGLSharedTextureForAccess;
        void* getVulkanInstanceExtensionsRequired_ = (void*) getVulkanInstanceExtensionsRequired;
        void* getVulkanDeviceExtensionsRequired_ = (void*) getVulkanDeviceExtensionsRequired;
        void* setExplicitTimingMode_ = (void*) setExplicitTimingMode;
        void* submitExplicitTimingData_ = (void*) submitExplicitTimingData;
    };

    class Compositor_021_v
    {
        public:
            virtual void setTrackingSpace(TrackingUniverseOrigin origin) { return Compositor_021::setTrackingSpace(origin); }
            virtual TrackingUniverseOrigin getTrackingSpace() { return Compositor_021::getTrackingSpace(); }
            virtual CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_021::waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_021::getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose) { return Compositor_021::getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose); }
            virtual CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags) { return Compositor_021::submit(eye, texture, bounds, submitFlags); }
            virtual void clearLastSubmittedFrame() { return Compositor_021::clearLastSubmittedFrame(); }
            virtual void postPresentHandoff() { return Compositor_021::postPresentHandoff(); }
            virtual bool getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo) { return Compositor_021::getFrameTiming(timing, framesAgo); }
            virtual uint32_t getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames) { return Compositor_021::getFrameTimings(timings, nFrames); }
            virtual float getFrameTimeRemaining() { return Compositor_021::getFrameTimeRemaining(); }
            virtual void getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize) { return Compositor_021::getCumulativeStats(stats, bufferSize); }
            virtual void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background) { return Compositor_021::fadeToColor(seconds, red, green, blue, alpha, background); }
            virtual Color getCurrentFadeColor(bool background) { return Compositor_021::getCurrentFadeColor(background); }
            virtual void fadeGrid(float seconds, bool fadeGridIn) { return Compositor_021::fadeGrid(seconds, fadeGridIn); }
            virtual float getCurrentGridAlpha() { return Compositor_021::getCurrentGridAlpha(); }
            virtual CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount) { return Compositor_021::setSkyboxOverride(textures, texturesCount); }
            virtual void clearSkyboxOverride() { return Compositor_021::clearSkyboxOverride(); }
            virtual void compositorBringToFront() { return Compositor_021::compositorBringToFront(); }
            virtual void compositorGoToBack() { return Compositor_021::compositorGoToBack(); }
            virtual void compositorQuit() { return Compositor_021::compositorQuit(); }
            virtual bool isFullscreen() { return Compositor_021::isFullscreen(); }
            virtual uint32_t getCurrentSceneFocusProcess() { return Compositor_021::getCurrentSceneFocusProcess(); }
            virtual uint32_t getLastFrameRenderer() { return Compositor_021::getLastFrameRenderer(); }
            virtual bool canRenderScene() { return Compositor_021::canRenderScene(); }
            virtual void showMirrorWindow() { return Compositor_021::showMirrorWindow(); }
            virtual void hideMirrorWindow() { return Compositor_021::hideMirrorWindow(); }
            virtual bool isMirrorWindowVisible() { return Compositor_021::isMirrorWindowVisible(); }
            virtual void compositorDumpImages() { return Compositor_021::compositorDumpImages(); }
            virtual bool shouldAppRenderWithLowResources() { return Compositor_021::shouldAppRenderWithLowResources(); }
            virtual void forceInterleavedReprojectionOn(bool on) { return Compositor_021::forceInterleavedReprojectionOn(on); }
            virtual void forceReconnectProcess() { return Compositor_021::forceReconnectProcess(); }
            virtual void suspendRendering(bool suspend) { return Compositor_021::suspendRendering(suspend); }
            virtual CompositorError getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView) { return Compositor_021::getMirrorTextureD3D11(eye, deviceOrResource, shaderResourceView); }
            virtual void releaseMirrorTextureD3D11(void* shaderResourceView) { return Compositor_021::releaseMirrorTextureD3D11(shaderResourceView); }
            virtual CompositorError getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle) { return Compositor_021::getMirrorTextureGL(eye, textureId, sharedTextureHandle); }
            virtual bool releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle) { return Compositor_021::releaseSharedGLTexture(textureId, sharedTextureHandle); }
            virtual void lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle) { return Compositor_021::lockGLSharedTextureForAccess(sharedTextureHandle); }
            virtual void unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle) { return Compositor_021::unlockGLSharedTextureForAccess(sharedTextureHandle); }
            virtual uint32_t getVulkanInstanceExtensionsRequired(char* value, uint32_t bufferSize) { return Compositor_021::getVulkanInstanceExtensionsRequired(value, bufferSize); }
            virtual uint32_t getVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* device, char* value, uint32_t bufferSize) { return Compositor_021::getVulkanDeviceExtensionsRequired(device, value, bufferSize); }
            virtual void setExplicitTimingMode(bool explicitTimingMode) { return Compositor_021::setExplicitTimingMode(explicitTimingMode); }
            virtual CompositorError submitExplicitTimingData() { return Compositor_021::submitExplicitTimingData(); }
    };

    //

    struct Compositor_022
    {
        static void setTrackingSpace(TrackingUniverseOrigin origin);
        static TrackingUniverseOrigin getTrackingSpace();

        static CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose);
        static CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags);
        static void clearLastSubmittedFrame();
        static void postPresentHandoff();

        static bool getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo);
        static uint32_t getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames);
        static float getFrameTimeRemaining();
        static void getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize);

        static void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background);
        static Color getCurrentFadeColor(bool background);
        static void fadeGrid(float seconds, bool fadeGridIn);
        static float getCurrentGridAlpha();

        static CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount);
        static void clearSkyboxOverride();

        static void compositorBringToFront();
        static void compositorGoToBack();
        static void compositorQuit();
        static bool isFullscreen();
        static uint32_t getCurrentSceneFocusProcess();
        static uint32_t getLastFrameRenderer();
        static bool canRenderScene();

        static void showMirrorWindow();
        static void hideMirrorWindow();
        static bool isMirrorWindowVisible();

        static void compositorDumpImages();
        static bool shouldAppRenderWithLowResources();
        static void forceInterleavedReprojectionOn(bool on);
        static void forceReconnectProcess();
        static void suspendRendering(bool suspend);

        static CompositorError getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView);
        static void releaseMirrorTextureD3D11(void* shaderResourceView);
        static CompositorError getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle);
        static bool releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle);
        static void lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle);
        static void unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle);

        static uint32_t getVulkanInstanceExtensionsRequired(char* value, uint32_t bufferSize);
        static uint32_t getVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* device, char* value, uint32_t bufferSize);

        static void setExplicitTimingMode(CompositorTimingMode timingMode);
        static CompositorError submitExplicitTimingData();

        static bool isMotionSmoothingEnabled();
        static bool isMotionSmoothingSupported();

        static bool isCurrentSceneFocusAppLoading();

        void* setTrackingSpace_ = (void*) setTrackingSpace;
        void* getTrackingSpace_ = (void*) getTrackingSpace;
        void* waitGetPoses_ = (void*) waitGetPoses;
        void* getLastPoses_ = (void*) getLastPoses;
        void* getLastPoseForTrackedDeviceIndex_ = (void*) getLastPoseForTrackedDeviceIndex;
        void* submit_ = (void*) submit;
        void* clearLastSubmittedFrame_ = (void*) clearLastSubmittedFrame;
        void* postPresentHandoff_ = (void*) postPresentHandoff;
        void* getFrameTiming_ = (void*) getFrameTiming;
        void* getFrameTimings_ = (void*) getFrameTimings;
        void* getFrameTimeRemaining_ = (void*) getFrameTimeRemaining;
        void* getCumulativeStats_ = (void*) getCumulativeStats;
        void* fadeToColor_ = (void*) fadeToColor;
        void* getCurrentFadeColor_ = (void*) getCurrentFadeColor;
        void* fadeGrid_ = (void*) fadeGrid;
        void* getCurrentGridAlpha_ = (void*) getCurrentGridAlpha;
        void* setSkyboxOverride_ = (void*) setSkyboxOverride;
        void* clearSkyboxOverride_ = (void*) clearSkyboxOverride;
        void* compositorBringToFront_ = (void*) compositorBringToFront;
        void* compositorGoToBack_ = (void*) compositorGoToBack;
        void* compositorQuit_ = (void*) compositorQuit;
        void* isFullscreen_ = (void*) isFullscreen;
        void* getCurrentSceneFocusProcess_ = (void*) getCurrentSceneFocusProcess;
        void* getLastFrameRenderer_ = (void*) getLastFrameRenderer;
        void* canRenderScene_ = (void*) canRenderScene;
        void* showMirrorWindow_ = (void*) showMirrorWindow;
        void* hideMirrorWindow_ = (void*) hideMirrorWindow;
        void* isMirrorWindowVisible_ = (void*) isMirrorWindowVisible;
        void* compositorDumpImages_ = (void*) compositorDumpImages;
        void* shouldAppRenderWithLowResources_ = (void*) shouldAppRenderWithLowResources;
        void* forceInterleavedReprojectionOn_ = (void*) forceInterleavedReprojectionOn;
        void* forceReconnectProcess_ = (void*) forceReconnectProcess;
        void* suspendRendering_ = (void*) suspendRendering;
        void* getMirrorTextureD3D11_ = (void*) getMirrorTextureD3D11;
        void* releaseMirrorTextureD3D11_ = (void*) releaseMirrorTextureD3D11;
        void* getMirrorTextureGL_ = (void*) getMirrorTextureGL;
        void* releaseSharedGLTexture_ = (void*) releaseSharedGLTexture;
        void* lockGLSharedTextureForAccess_ = (void*) lockGLSharedTextureForAccess;
        void* unlockGLSharedTextureForAccess_ = (void*) unlockGLSharedTextureForAccess;
        void* getVulkanInstanceExtensionsRequired_ = (void*) getVulkanInstanceExtensionsRequired;
        void* getVulkanDeviceExtensionsRequired_ = (void*) getVulkanDeviceExtensionsRequired;
        void* setExplicitTimingMode_ = (void*) setExplicitTimingMode;
        void* submitExplicitTimingData_ = (void*) submitExplicitTimingData;
        void* isMotionSmoothingEnabled_ = (void*) isMotionSmoothingEnabled;
        void* isMotionSmoothingSupported_ = (void*) isMotionSmoothingSupported;
        void* isCurrentSceneFocusAppLoading_ = (void*) isCurrentSceneFocusAppLoading;
    };

    class Compositor_022_v
    {
        public:
            virtual void setTrackingSpace(TrackingUniverseOrigin origin) { return Compositor_022::setTrackingSpace(origin); }
            virtual TrackingUniverseOrigin getTrackingSpace() { return Compositor_022::getTrackingSpace(); }
            virtual CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_022::waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_022::getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose) { return Compositor_022::getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose); }
            virtual CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags) { return Compositor_022::submit(eye, texture, bounds, submitFlags); }
            virtual void clearLastSubmittedFrame() { return Compositor_022::clearLastSubmittedFrame(); }
            virtual void postPresentHandoff() { return Compositor_022::postPresentHandoff(); }
            virtual bool getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo) { return Compositor_022::getFrameTiming(timing, framesAgo); }
            virtual uint32_t getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames) { return Compositor_022::getFrameTimings(timings, nFrames); }
            virtual float getFrameTimeRemaining() { return Compositor_022::getFrameTimeRemaining(); }
            virtual void getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize) { return Compositor_022::getCumulativeStats(stats, bufferSize); }
            virtual void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background) { return Compositor_022::fadeToColor(seconds, red, green, blue, alpha, background); }
            virtual Color getCurrentFadeColor(bool background) { return Compositor_022::getCurrentFadeColor(background); }
            virtual void fadeGrid(float seconds, bool fadeGridIn) { return Compositor_022::fadeGrid(seconds, fadeGridIn); }
            virtual float getCurrentGridAlpha() { return Compositor_022::getCurrentGridAlpha(); }
            virtual CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount) { return Compositor_022::setSkyboxOverride(textures, texturesCount); }
            virtual void clearSkyboxOverride() { return Compositor_022::clearSkyboxOverride(); }
            virtual void compositorBringToFront() { return Compositor_022::compositorBringToFront(); }
            virtual void compositorGoToBack() { return Compositor_022::compositorGoToBack(); }
            virtual void compositorQuit() { return Compositor_022::compositorQuit(); }
            virtual bool isFullscreen() { return Compositor_022::isFullscreen(); }
            virtual uint32_t getCurrentSceneFocusProcess() { return Compositor_022::getCurrentSceneFocusProcess(); }
            virtual uint32_t getLastFrameRenderer() { return Compositor_022::getLastFrameRenderer(); }
            virtual bool canRenderScene() { return Compositor_022::canRenderScene(); }
            virtual void showMirrorWindow() { return Compositor_022::showMirrorWindow(); }
            virtual void hideMirrorWindow() { return Compositor_022::hideMirrorWindow(); }
            virtual bool isMirrorWindowVisible() { return Compositor_022::isMirrorWindowVisible(); }
            virtual void compositorDumpImages() { return Compositor_022::compositorDumpImages(); }
            virtual bool shouldAppRenderWithLowResources() { return Compositor_022::shouldAppRenderWithLowResources(); }
            virtual void forceInterleavedReprojectionOn(bool on) { return Compositor_022::forceInterleavedReprojectionOn(on); }
            virtual void forceReconnectProcess() { return Compositor_022::forceReconnectProcess(); }
            virtual void suspendRendering(bool suspend) { return Compositor_022::suspendRendering(suspend); }
            virtual CompositorError getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView) { return Compositor_022::getMirrorTextureD3D11(eye, deviceOrResource, shaderResourceView); }
            virtual void releaseMirrorTextureD3D11(void* shaderResourceView) { return Compositor_022::releaseMirrorTextureD3D11(shaderResourceView); }
            virtual CompositorError getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle) { return Compositor_022::getMirrorTextureGL(eye, textureId, sharedTextureHandle); }
            virtual bool releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle) { return Compositor_022::releaseSharedGLTexture(textureId, sharedTextureHandle); }
            virtual void lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle) { return Compositor_022::lockGLSharedTextureForAccess(sharedTextureHandle); }
            virtual void unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle) { return Compositor_022::unlockGLSharedTextureForAccess(sharedTextureHandle); }
            virtual uint32_t getVulkanInstanceExtensionsRequired(char* value, uint32_t bufferSize) { return Compositor_022::getVulkanInstanceExtensionsRequired(value, bufferSize); }
            virtual uint32_t getVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* device, char* value, uint32_t bufferSize) { return Compositor_022::getVulkanDeviceExtensionsRequired(device, value, bufferSize); }
            virtual void setExplicitTimingMode(CompositorTimingMode timingMode) { return Compositor_022::setExplicitTimingMode(timingMode); }
            virtual CompositorError submitExplicitTimingData() { return Compositor_022::submitExplicitTimingData(); }
            virtual bool isMotionSmoothingEnabled() { return Compositor_022::isMotionSmoothingEnabled(); }
            virtual bool isMotionSmoothingSupported() { return Compositor_022::isMotionSmoothingSupported(); }
            virtual bool isCurrentSceneFocusAppLoading() { return Compositor_022::isCurrentSceneFocusAppLoading(); }
    };

    //

    struct Compositor_024
    {
        static void setTrackingSpace(TrackingUniverseOrigin origin);
        static TrackingUniverseOrigin getTrackingSpace();

        static CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose);
        static CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags);
        static void clearLastSubmittedFrame();
        static void postPresentHandoff();

        static bool getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo);
        static uint32_t getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames);
        static float getFrameTimeRemaining();
        static void getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize);

        static void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background);
        static Color getCurrentFadeColor(bool background);
        static void fadeGrid(float seconds, bool fadeGridIn);
        static float getCurrentGridAlpha();

        static CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount);
        static void clearSkyboxOverride();

        static void compositorBringToFront();
        static void compositorGoToBack();
        static void compositorQuit();
        static bool isFullscreen();
        static uint32_t getCurrentSceneFocusProcess();
        static uint32_t getLastFrameRenderer();
        static bool canRenderScene();

        static void showMirrorWindow();
        static void hideMirrorWindow();
        static bool isMirrorWindowVisible();

        static void compositorDumpImages();
        static bool shouldAppRenderWithLowResources();
        static void forceInterleavedReprojectionOn(bool on);
        static void forceReconnectProcess();
        static void suspendRendering(bool suspend);

        static CompositorError getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView);
        static void releaseMirrorTextureD3D11(void* shaderResourceView);
        static CompositorError getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle);
        static bool releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle);
        static void lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle);
        static void unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle);

        static uint32_t getVulkanInstanceExtensionsRequired(char* value, uint32_t bufferSize);
        static uint32_t getVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* device, char* value, uint32_t bufferSize);

        static void setExplicitTimingMode(CompositorTimingMode timingMode);
        static CompositorError submitExplicitTimingData();

        static bool isMotionSmoothingEnabled();
        static bool isMotionSmoothingSupported();

        static bool isCurrentSceneFocusAppLoading();

        static CompositorError setStageOverride(const char* modelPath, const Matrix34* transform, const StageRenderSettings* renderSettings, uint32_t renderSettingsSize);
        static void clearStageOverride();

        void* setTrackingSpace_ = (void*) setTrackingSpace;
        void* getTrackingSpace_ = (void*) getTrackingSpace;
        void* waitGetPoses_ = (void*) waitGetPoses;
        void* getLastPoses_ = (void*) getLastPoses;
        void* getLastPoseForTrackedDeviceIndex_ = (void*) getLastPoseForTrackedDeviceIndex;
        void* submit_ = (void*) submit;
        void* clearLastSubmittedFrame_ = (void*) clearLastSubmittedFrame;
        void* postPresentHandoff_ = (void*) postPresentHandoff;
        void* getFrameTiming_ = (void*) getFrameTiming;
        void* getFrameTimings_ = (void*) getFrameTimings;
        void* getFrameTimeRemaining_ = (void*) getFrameTimeRemaining;
        void* getCumulativeStats_ = (void*) getCumulativeStats;
        void* fadeToColor_ = (void*) fadeToColor;
        void* getCurrentFadeColor_ = (void*) getCurrentFadeColor;
        void* fadeGrid_ = (void*) fadeGrid;
        void* getCurrentGridAlpha_ = (void*) getCurrentGridAlpha;
        void* setSkyboxOverride_ = (void*) setSkyboxOverride;
        void* clearSkyboxOverride_ = (void*) clearSkyboxOverride;
        void* compositorBringToFront_ = (void*) compositorBringToFront;
        void* compositorGoToBack_ = (void*) compositorGoToBack;
        void* compositorQuit_ = (void*) compositorQuit;
        void* isFullscreen_ = (void*) isFullscreen;
        void* getCurrentSceneFocusProcess_ = (void*) getCurrentSceneFocusProcess;
        void* getLastFrameRenderer_ = (void*) getLastFrameRenderer;
        void* canRenderScene_ = (void*) canRenderScene;
        void* showMirrorWindow_ = (void*) showMirrorWindow;
        void* hideMirrorWindow_ = (void*) hideMirrorWindow;
        void* isMirrorWindowVisible_ = (void*) isMirrorWindowVisible;
        void* compositorDumpImages_ = (void*) compositorDumpImages;
        void* shouldAppRenderWithLowResources_ = (void*) shouldAppRenderWithLowResources;
        void* forceInterleavedReprojectionOn_ = (void*) forceInterleavedReprojectionOn;
        void* forceReconnectProcess_ = (void*) forceReconnectProcess;
        void* suspendRendering_ = (void*) suspendRendering;
        void* getMirrorTextureD3D11_ = (void*) getMirrorTextureD3D11;
        void* releaseMirrorTextureD3D11_ = (void*) releaseMirrorTextureD3D11;
        void* getMirrorTextureGL_ = (void*) getMirrorTextureGL;
        void* releaseSharedGLTexture_ = (void*) releaseSharedGLTexture;
        void* lockGLSharedTextureForAccess_ = (void*) lockGLSharedTextureForAccess;
        void* unlockGLSharedTextureForAccess_ = (void*) unlockGLSharedTextureForAccess;
        void* getVulkanInstanceExtensionsRequired_ = (void*) getVulkanInstanceExtensionsRequired;
        void* getVulkanDeviceExtensionsRequired_ = (void*) getVulkanDeviceExtensionsRequired;
        void* setExplicitTimingMode_ = (void*) setExplicitTimingMode;
        void* submitExplicitTimingData_ = (void*) submitExplicitTimingData;
        void* isMotionSmoothingEnabled_ = (void*) isMotionSmoothingEnabled;
        void* isMotionSmoothingSupported_ = (void*) isMotionSmoothingSupported;
        void* isCurrentSceneFocusAppLoading_ = (void*) isCurrentSceneFocusAppLoading;
        void* setStageOverride_ = (void*) setStageOverride;
        void* clearStageOverride_ = (void*) clearStageOverride;
    };

    class Compositor_024_v
    {
        public:
            virtual void setTrackingSpace(TrackingUniverseOrigin origin) { return Compositor_024::setTrackingSpace(origin); }
            virtual TrackingUniverseOrigin getTrackingSpace() { return Compositor_024::getTrackingSpace(); }
            virtual CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_024::waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_024::getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose) { return Compositor_024::getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose); }
            virtual CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags) { return Compositor_024::submit(eye, texture, bounds, submitFlags); }
            virtual void clearLastSubmittedFrame() { return Compositor_024::clearLastSubmittedFrame(); }
            virtual void postPresentHandoff() { return Compositor_024::postPresentHandoff(); }
            virtual bool getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo) { return Compositor_024::getFrameTiming(timing, framesAgo); }
            virtual uint32_t getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames) { return Compositor_024::getFrameTimings(timings, nFrames); }
            virtual float getFrameTimeRemaining() { return Compositor_024::getFrameTimeRemaining(); }
            virtual void getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize) { return Compositor_024::getCumulativeStats(stats, bufferSize); }
            virtual void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background) { return Compositor_024::fadeToColor(seconds, red, green, blue, alpha, background); }
            virtual Color getCurrentFadeColor(bool background) { return Compositor_024::getCurrentFadeColor(background); }
            virtual void fadeGrid(float seconds, bool fadeGridIn) { return Compositor_024::fadeGrid(seconds, fadeGridIn); }
            virtual float getCurrentGridAlpha() { return Compositor_024::getCurrentGridAlpha(); }
            virtual CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount) { return Compositor_024::setSkyboxOverride(textures, texturesCount); }
            virtual void clearSkyboxOverride() { return Compositor_024::clearSkyboxOverride(); }
            virtual void compositorBringToFront() { return Compositor_024::compositorBringToFront(); }
            virtual void compositorGoToBack() { return Compositor_024::compositorGoToBack(); }
            virtual void compositorQuit() { return Compositor_024::compositorQuit(); }
            virtual bool isFullscreen() { return Compositor_024::isFullscreen(); }
            virtual uint32_t getCurrentSceneFocusProcess() { return Compositor_024::getCurrentSceneFocusProcess(); }
            virtual uint32_t getLastFrameRenderer() { return Compositor_024::getLastFrameRenderer(); }
            virtual bool canRenderScene() { return Compositor_024::canRenderScene(); }
            virtual void showMirrorWindow() { return Compositor_024::showMirrorWindow(); }
            virtual void hideMirrorWindow() { return Compositor_024::hideMirrorWindow(); }
            virtual bool isMirrorWindowVisible() { return Compositor_024::isMirrorWindowVisible(); }
            virtual void compositorDumpImages() { return Compositor_024::compositorDumpImages(); }
            virtual bool shouldAppRenderWithLowResources() { return Compositor_024::shouldAppRenderWithLowResources(); }
            virtual void forceInterleavedReprojectionOn(bool on) { return Compositor_024::forceInterleavedReprojectionOn(on); }
            virtual void forceReconnectProcess() { return Compositor_024::forceReconnectProcess(); }
            virtual void suspendRendering(bool suspend) { return Compositor_024::suspendRendering(suspend); }
            virtual CompositorError getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView) { return Compositor_024::getMirrorTextureD3D11(eye, deviceOrResource, shaderResourceView); }
            virtual void releaseMirrorTextureD3D11(void* shaderResourceView) { return Compositor_024::releaseMirrorTextureD3D11(shaderResourceView); }
            virtual CompositorError getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle) { return Compositor_024::getMirrorTextureGL(eye, textureId, sharedTextureHandle); }
            virtual bool releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle) { return Compositor_024::releaseSharedGLTexture(textureId, sharedTextureHandle); }
            virtual void lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle) { return Compositor_024::lockGLSharedTextureForAccess(sharedTextureHandle); }
            virtual void unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle) { return Compositor_024::unlockGLSharedTextureForAccess(sharedTextureHandle); }
            virtual uint32_t getVulkanInstanceExtensionsRequired(char* value, uint32_t bufferSize) { return Compositor_024::getVulkanInstanceExtensionsRequired(value, bufferSize); }
            virtual uint32_t getVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* device, char* value, uint32_t bufferSize) { return Compositor_024::getVulkanDeviceExtensionsRequired(device, value, bufferSize); }
            virtual void setExplicitTimingMode(CompositorTimingMode timingMode) { return Compositor_024::setExplicitTimingMode(timingMode); }
            virtual CompositorError submitExplicitTimingData() { return Compositor_024::submitExplicitTimingData(); }
            virtual bool isMotionSmoothingEnabled() { return Compositor_024::isMotionSmoothingEnabled(); }
            virtual bool isMotionSmoothingSupported() { return Compositor_024::isMotionSmoothingSupported(); }
            virtual bool isCurrentSceneFocusAppLoading() { return Compositor_024::isCurrentSceneFocusAppLoading(); }
            virtual CompositorError setStageOverride(const char* modelPath, const Matrix34* transform, const StageRenderSettings* renderSettings, uint32_t renderSettingsSize) { return Compositor_024::setStageOverride(modelPath, transform, renderSettings, renderSettingsSize); }
            virtual void clearStageOverride() { return Compositor_024::clearStageOverride(); }
    };

    //

    struct Compositor_026
    {
        static void setTrackingSpace(TrackingUniverseOrigin origin);
        static TrackingUniverseOrigin getTrackingSpace();

        static CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose);
        static CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags);
        static void clearLastSubmittedFrame();
        static void postPresentHandoff();

        static bool getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo);
        static uint32_t getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames);
        static float getFrameTimeRemaining();
        static void getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize);

        static void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background);
        static Color getCurrentFadeColor(bool background);
        static void fadeGrid(float seconds, bool fadeGridIn);
        static float getCurrentGridAlpha();

        static CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount);
        static void clearSkyboxOverride();

        static void compositorBringToFront();
        static void compositorGoToBack();
        static void compositorQuit();
        static bool isFullscreen();
        static uint32_t getCurrentSceneFocusProcess();
        static uint32_t getLastFrameRenderer();
        static bool canRenderScene();

        static void showMirrorWindow();
        static void hideMirrorWindow();
        static bool isMirrorWindowVisible();

        static void compositorDumpImages();
        static bool shouldAppRenderWithLowResources();
        static void forceInterleavedReprojectionOn(bool on);
        static void forceReconnectProcess();
        static void suspendRendering(bool suspend);

        static CompositorError getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView);
        static void releaseMirrorTextureD3D11(void* shaderResourceView);
        static CompositorError getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle);
        static bool releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle);
        static void lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle);
        static void unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle);

        static uint32_t getVulkanInstanceExtensionsRequired(char* value, uint32_t bufferSize);
        static uint32_t getVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* device, char* value, uint32_t bufferSize);

        static void setExplicitTimingMode(CompositorTimingMode timingMode);
        static CompositorError submitExplicitTimingData();

        static bool isMotionSmoothingEnabled();
        static bool isMotionSmoothingSupported();

        static bool isCurrentSceneFocusAppLoading();

        static CompositorError setStageOverride(const char* modelPath, const Matrix34* transform, const StageRenderSettings* renderSettings, uint32_t renderSettingsSize);
        static void clearStageOverride();

        static bool getCompositorBenchmarkResults(BenchmarkResults* benchmarkResults, uint32_t benchmarkResultsSize);

        static CompositorError getLastPosePredictionIDs(uint32_t* renderPosePredictionId, uint32_t* gamePosePredictionId);
        static CompositorError getPosesForFrame(uint32_t posePredictionId, TrackedDevicePose* poses, uint32_t posesCount);

        void* setTrackingSpace_ = (void*) setTrackingSpace;
        void* getTrackingSpace_ = (void*) getTrackingSpace;
        void* waitGetPoses_ = (void*) waitGetPoses;
        void* getLastPoses_ = (void*) getLastPoses;
        void* getLastPoseForTrackedDeviceIndex_ = (void*) getLastPoseForTrackedDeviceIndex;
        void* submit_ = (void*) submit;
        void* clearLastSubmittedFrame_ = (void*) clearLastSubmittedFrame;
        void* postPresentHandoff_ = (void*) postPresentHandoff;
        void* getFrameTiming_ = (void*) getFrameTiming;
        void* getFrameTimings_ = (void*) getFrameTimings;
        void* getFrameTimeRemaining_ = (void*) getFrameTimeRemaining;
        void* getCumulativeStats_ = (void*) getCumulativeStats;
        void* fadeToColor_ = (void*) fadeToColor;
        void* getCurrentFadeColor_ = (void*) getCurrentFadeColor;
        void* fadeGrid_ = (void*) fadeGrid;
        void* getCurrentGridAlpha_ = (void*) getCurrentGridAlpha;
        void* setSkyboxOverride_ = (void*) setSkyboxOverride;
        void* clearSkyboxOverride_ = (void*) clearSkyboxOverride;
        void* compositorBringToFront_ = (void*) compositorBringToFront;
        void* compositorGoToBack_ = (void*) compositorGoToBack;
        void* compositorQuit_ = (void*) compositorQuit;
        void* isFullscreen_ = (void*) isFullscreen;
        void* getCurrentSceneFocusProcess_ = (void*) getCurrentSceneFocusProcess;
        void* getLastFrameRenderer_ = (void*) getLastFrameRenderer;
        void* canRenderScene_ = (void*) canRenderScene;
        void* showMirrorWindow_ = (void*) showMirrorWindow;
        void* hideMirrorWindow_ = (void*) hideMirrorWindow;
        void* isMirrorWindowVisible_ = (void*) isMirrorWindowVisible;
        void* compositorDumpImages_ = (void*) compositorDumpImages;
        void* shouldAppRenderWithLowResources_ = (void*) shouldAppRenderWithLowResources;
        void* forceInterleavedReprojectionOn_ = (void*) forceInterleavedReprojectionOn;
        void* forceReconnectProcess_ = (void*) forceReconnectProcess;
        void* suspendRendering_ = (void*) suspendRendering;
        void* getMirrorTextureD3D11_ = (void*) getMirrorTextureD3D11;
        void* releaseMirrorTextureD3D11_ = (void*) releaseMirrorTextureD3D11;
        void* getMirrorTextureGL_ = (void*) getMirrorTextureGL;
        void* releaseSharedGLTexture_ = (void*) releaseSharedGLTexture;
        void* lockGLSharedTextureForAccess_ = (void*) lockGLSharedTextureForAccess;
        void* unlockGLSharedTextureForAccess_ = (void*) unlockGLSharedTextureForAccess;
        void* getVulkanInstanceExtensionsRequired_ = (void*) getVulkanInstanceExtensionsRequired;
        void* getVulkanDeviceExtensionsRequired_ = (void*) getVulkanDeviceExtensionsRequired;
        void* setExplicitTimingMode_ = (void*) setExplicitTimingMode;
        void* submitExplicitTimingData_ = (void*) submitExplicitTimingData;
        void* isMotionSmoothingEnabled_ = (void*) isMotionSmoothingEnabled;
        void* isMotionSmoothingSupported_ = (void*) isMotionSmoothingSupported;
        void* isCurrentSceneFocusAppLoading_ = (void*) isCurrentSceneFocusAppLoading;
        void* setStageOverride_ = (void*) setStageOverride;
        void* clearStageOverride_ = (void*) clearStageOverride;
        void* getCompositorBenchmarkResults_ = (void*) getCompositorBenchmarkResults;
        void* getLastPosePredictionIDs_ = (void*) getLastPosePredictionIDs;
        void* getPosesForFrame_ = (void*) getPosesForFrame;
    };

    class Compositor_026_v
    {
        public:
            virtual void setTrackingSpace(TrackingUniverseOrigin origin) { return Compositor_026::setTrackingSpace(origin); }
            virtual TrackingUniverseOrigin getTrackingSpace() { return Compositor_026::getTrackingSpace(); }
            virtual CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_026::waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_026::getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose) { return Compositor_026::getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose); }
            virtual CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags) { return Compositor_026::submit(eye, texture, bounds, submitFlags); }
            virtual void clearLastSubmittedFrame() { return Compositor_026::clearLastSubmittedFrame(); }
            virtual void postPresentHandoff() { return Compositor_026::postPresentHandoff(); }
            virtual bool getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo) { return Compositor_026::getFrameTiming(timing, framesAgo); }
            virtual uint32_t getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames) { return Compositor_026::getFrameTimings(timings, nFrames); }
            virtual float getFrameTimeRemaining() { return Compositor_026::getFrameTimeRemaining(); }
            virtual void getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize) { return Compositor_026::getCumulativeStats(stats, bufferSize); }
            virtual void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background) { return Compositor_026::fadeToColor(seconds, red, green, blue, alpha, background); }
            virtual Color getCurrentFadeColor(bool background) { return Compositor_026::getCurrentFadeColor(background); }
            virtual void fadeGrid(float seconds, bool fadeGridIn) { return Compositor_026::fadeGrid(seconds, fadeGridIn); }
            virtual float getCurrentGridAlpha() { return Compositor_026::getCurrentGridAlpha(); }
            virtual CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount) { return Compositor_026::setSkyboxOverride(textures, texturesCount); }
            virtual void clearSkyboxOverride() { return Compositor_026::clearSkyboxOverride(); }
            virtual void compositorBringToFront() { return Compositor_026::compositorBringToFront(); }
            virtual void compositorGoToBack() { return Compositor_026::compositorGoToBack(); }
            virtual void compositorQuit() { return Compositor_026::compositorQuit(); }
            virtual bool isFullscreen() { return Compositor_026::isFullscreen(); }
            virtual uint32_t getCurrentSceneFocusProcess() { return Compositor_026::getCurrentSceneFocusProcess(); }
            virtual uint32_t getLastFrameRenderer() { return Compositor_026::getLastFrameRenderer(); }
            virtual bool canRenderScene() { return Compositor_026::canRenderScene(); }
            virtual void showMirrorWindow() { return Compositor_026::showMirrorWindow(); }
            virtual void hideMirrorWindow() { return Compositor_026::hideMirrorWindow(); }
            virtual bool isMirrorWindowVisible() { return Compositor_026::isMirrorWindowVisible(); }
            virtual void compositorDumpImages() { return Compositor_026::compositorDumpImages(); }
            virtual bool shouldAppRenderWithLowResources() { return Compositor_026::shouldAppRenderWithLowResources(); }
            virtual void forceInterleavedReprojectionOn(bool on) { return Compositor_026::forceInterleavedReprojectionOn(on); }
            virtual void forceReconnectProcess() { return Compositor_026::forceReconnectProcess(); }
            virtual void suspendRendering(bool suspend) { return Compositor_026::suspendRendering(suspend); }
            virtual CompositorError getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView) { return Compositor_026::getMirrorTextureD3D11(eye, deviceOrResource, shaderResourceView); }
            virtual void releaseMirrorTextureD3D11(void* shaderResourceView) { return Compositor_026::releaseMirrorTextureD3D11(shaderResourceView); }
            virtual CompositorError getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle) { return Compositor_026::getMirrorTextureGL(eye, textureId, sharedTextureHandle); }
            virtual bool releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle) { return Compositor_026::releaseSharedGLTexture(textureId, sharedTextureHandle); }
            virtual void lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle) { return Compositor_026::lockGLSharedTextureForAccess(sharedTextureHandle); }
            virtual void unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle) { return Compositor_026::unlockGLSharedTextureForAccess(sharedTextureHandle); }
            virtual uint32_t getVulkanInstanceExtensionsRequired(char* value, uint32_t bufferSize) { return Compositor_026::getVulkanInstanceExtensionsRequired(value, bufferSize); }
            virtual uint32_t getVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* device, char* value, uint32_t bufferSize) { return Compositor_026::getVulkanDeviceExtensionsRequired(device, value, bufferSize); }
            virtual void setExplicitTimingMode(CompositorTimingMode timingMode) { return Compositor_026::setExplicitTimingMode(timingMode); }
            virtual CompositorError submitExplicitTimingData() { return Compositor_026::submitExplicitTimingData(); }
            virtual bool isMotionSmoothingEnabled() { return Compositor_026::isMotionSmoothingEnabled(); }
            virtual bool isMotionSmoothingSupported() { return Compositor_026::isMotionSmoothingSupported(); }
            virtual bool isCurrentSceneFocusAppLoading() { return Compositor_026::isCurrentSceneFocusAppLoading(); }
            virtual CompositorError setStageOverride(const char* modelPath, const Matrix34* transform, const StageRenderSettings* renderSettings, uint32_t renderSettingsSize) { return Compositor_026::setStageOverride(modelPath, transform, renderSettings, renderSettingsSize); }
            virtual void clearStageOverride() { return Compositor_026::clearStageOverride(); }
            virtual bool getCompositorBenchmarkResults(BenchmarkResults* benchmarkResults, uint32_t benchmarkResultsSize) { return Compositor_026::getCompositorBenchmarkResults(benchmarkResults, benchmarkResultsSize); }
            virtual CompositorError getLastPosePredictionIDs(uint32_t* renderPosePredictionId, uint32_t* gamePosePredictionId) { return Compositor_026::getLastPosePredictionIDs(renderPosePredictionId, gamePosePredictionId); }
            virtual CompositorError getPosesForFrame(uint32_t posePredictionId, TrackedDevicePose* poses, uint32_t posesCount) { return Compositor_026::getPosesForFrame(posePredictionId, poses, posesCount); }
    };

    //

    struct Compositor_028
    {
        static void setTrackingSpace(TrackingUniverseOrigin origin);
        static TrackingUniverseOrigin getTrackingSpace();

        static CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose);
        static CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags);
        static CompositorError submitWithArrayIndex(Eye eye, const Texture* texture, uint32_t textureArrayIndex, const TextureBounds* bounds, int32_t submitFlags);
        static void clearLastSubmittedFrame();
        static void postPresentHandoff();

        static bool getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo);
        static uint32_t getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames);
        static float getFrameTimeRemaining();
        static void getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize);

        static void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background);
        static Color getCurrentFadeColor(bool background);
        static void fadeGrid(float seconds, bool fadeGridIn);
        static float getCurrentGridAlpha();

        static CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount);
        static void clearSkyboxOverride();

        static void compositorBringToFront();
        static void compositorGoToBack();
        static void compositorQuit();
        static bool isFullscreen();
        static uint32_t getCurrentSceneFocusProcess();
        static uint32_t getLastFrameRenderer();
        static bool canRenderScene();

        static void showMirrorWindow();
        static void hideMirrorWindow();
        static bool isMirrorWindowVisible();

        static void compositorDumpImages();
        static bool shouldAppRenderWithLowResources();
        static void forceInterleavedReprojectionOn(bool on);
        static void forceReconnectProcess();
        static void suspendRendering(bool suspend);

        static CompositorError getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView);
        static void releaseMirrorTextureD3D11(void* shaderResourceView);
        static CompositorError getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle);
        static bool releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle);
        static void lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle);
        static void unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle);

        static uint32_t getVulkanInstanceExtensionsRequired(char* value, uint32_t bufferSize);
        static uint32_t getVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* device, char* value, uint32_t bufferSize);

        static void setExplicitTimingMode(CompositorTimingMode timingMode);
        static CompositorError submitExplicitTimingData();

        static bool isMotionSmoothingEnabled();
        static bool isMotionSmoothingSupported();

        static bool isCurrentSceneFocusAppLoading();

        static CompositorError setStageOverride(const char* modelPath, const Matrix34* transform, const StageRenderSettings* renderSettings, uint32_t renderSettingsSize);
        static void clearStageOverride();

        static bool getCompositorBenchmarkResults(BenchmarkResults* benchmarkResults, uint32_t benchmarkResultsSize);

        static CompositorError getLastPosePredictionIDs(uint32_t* renderPosePredictionId, uint32_t* gamePosePredictionId);
        static CompositorError getPosesForFrame(uint32_t posePredictionId, TrackedDevicePose* poses, uint32_t posesCount);

        void* setTrackingSpace_ = (void*) setTrackingSpace;
        void* getTrackingSpace_ = (void*) getTrackingSpace;
        void* waitGetPoses_ = (void*) waitGetPoses;
        void* getLastPoses_ = (void*) getLastPoses;
        void* getLastPoseForTrackedDeviceIndex_ = (void*) getLastPoseForTrackedDeviceIndex;
        void* submit_ = (void*) submit;
        void* submitWithArrayIndex_ = (void*) submitWithArrayIndex;
        void* clearLastSubmittedFrame_ = (void*) clearLastSubmittedFrame;
        void* postPresentHandoff_ = (void*) postPresentHandoff;
        void* getFrameTiming_ = (void*) getFrameTiming;
        void* getFrameTimings_ = (void*) getFrameTimings;
        void* getFrameTimeRemaining_ = (void*) getFrameTimeRemaining;
        void* getCumulativeStats_ = (void*) getCumulativeStats;
        void* fadeToColor_ = (void*) fadeToColor;
        void* getCurrentFadeColor_ = (void*) getCurrentFadeColor;
        void* fadeGrid_ = (void*) fadeGrid;
        void* getCurrentGridAlpha_ = (void*) getCurrentGridAlpha;
        void* setSkyboxOverride_ = (void*) setSkyboxOverride;
        void* clearSkyboxOverride_ = (void*) clearSkyboxOverride;
        void* compositorBringToFront_ = (void*) compositorBringToFront;
        void* compositorGoToBack_ = (void*) compositorGoToBack;
        void* compositorQuit_ = (void*) compositorQuit;
        void* isFullscreen_ = (void*) isFullscreen;
        void* getCurrentSceneFocusProcess_ = (void*) getCurrentSceneFocusProcess;
        void* getLastFrameRenderer_ = (void*) getLastFrameRenderer;
        void* canRenderScene_ = (void*) canRenderScene;
        void* showMirrorWindow_ = (void*) showMirrorWindow;
        void* hideMirrorWindow_ = (void*) hideMirrorWindow;
        void* isMirrorWindowVisible_ = (void*) isMirrorWindowVisible;
        void* compositorDumpImages_ = (void*) compositorDumpImages;
        void* shouldAppRenderWithLowResources_ = (void*) shouldAppRenderWithLowResources;
        void* forceInterleavedReprojectionOn_ = (void*) forceInterleavedReprojectionOn;
        void* forceReconnectProcess_ = (void*) forceReconnectProcess;
        void* suspendRendering_ = (void*) suspendRendering;
        void* getMirrorTextureD3D11_ = (void*) getMirrorTextureD3D11;
        void* releaseMirrorTextureD3D11_ = (void*) releaseMirrorTextureD3D11;
        void* getMirrorTextureGL_ = (void*) getMirrorTextureGL;
        void* releaseSharedGLTexture_ = (void*) releaseSharedGLTexture;
        void* lockGLSharedTextureForAccess_ = (void*) lockGLSharedTextureForAccess;
        void* unlockGLSharedTextureForAccess_ = (void*) unlockGLSharedTextureForAccess;
        void* getVulkanInstanceExtensionsRequired_ = (void*) getVulkanInstanceExtensionsRequired;
        void* getVulkanDeviceExtensionsRequired_ = (void*) getVulkanDeviceExtensionsRequired;
        void* setExplicitTimingMode_ = (void*) setExplicitTimingMode;
        void* submitExplicitTimingData_ = (void*) submitExplicitTimingData;
        void* isMotionSmoothingEnabled_ = (void*) isMotionSmoothingEnabled;
        void* isMotionSmoothingSupported_ = (void*) isMotionSmoothingSupported;
        void* isCurrentSceneFocusAppLoading_ = (void*) isCurrentSceneFocusAppLoading;
        void* setStageOverride_ = (void*) setStageOverride;
        void* clearStageOverride_ = (void*) clearStageOverride;
        void* getCompositorBenchmarkResults_ = (void*) getCompositorBenchmarkResults;
        void* getLastPosePredictionIDs_ = (void*) getLastPosePredictionIDs;
        void* getPosesForFrame_ = (void*) getPosesForFrame;
    };

    class Compositor_028_v
    {
        public:
            virtual void setTrackingSpace(TrackingUniverseOrigin origin) { return Compositor_028::setTrackingSpace(origin); }
            virtual TrackingUniverseOrigin getTrackingSpace() { return Compositor_028::getTrackingSpace(); }
            virtual CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_028::waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_028::getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose) { return Compositor_028::getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose); }
            virtual CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags) { return Compositor_028::submit(eye, texture, bounds, submitFlags); }
            virtual CompositorError submitWithArrayIndex(Eye eye, const Texture* texture, uint32_t textureArrayIndex, const TextureBounds* bounds, int32_t submitFlags) { return Compositor_028::submitWithArrayIndex(eye, texture, textureArrayIndex, bounds, submitFlags); }
            virtual void clearLastSubmittedFrame() { return Compositor_028::clearLastSubmittedFrame(); }
            virtual void postPresentHandoff() { return Compositor_028::postPresentHandoff(); }
            virtual bool getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo) { return Compositor_028::getFrameTiming(timing, framesAgo); }
            virtual uint32_t getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames) { return Compositor_028::getFrameTimings(timings, nFrames); }
            virtual float getFrameTimeRemaining() { return Compositor_028::getFrameTimeRemaining(); }
            virtual void getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize) { return Compositor_028::getCumulativeStats(stats, bufferSize); }
            virtual void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background) { return Compositor_028::fadeToColor(seconds, red, green, blue, alpha, background); }
            virtual Color getCurrentFadeColor(bool background) { return Compositor_028::getCurrentFadeColor(background); }
            virtual void fadeGrid(float seconds, bool fadeGridIn) { return Compositor_028::fadeGrid(seconds, fadeGridIn); }
            virtual float getCurrentGridAlpha() { return Compositor_028::getCurrentGridAlpha(); }
            virtual CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount) { return Compositor_028::setSkyboxOverride(textures, texturesCount); }
            virtual void clearSkyboxOverride() { return Compositor_028::clearSkyboxOverride(); }
            virtual void compositorBringToFront() { return Compositor_028::compositorBringToFront(); }
            virtual void compositorGoToBack() { return Compositor_028::compositorGoToBack(); }
            virtual void compositorQuit() { return Compositor_028::compositorQuit(); }
            virtual bool isFullscreen() { return Compositor_028::isFullscreen(); }
            virtual uint32_t getCurrentSceneFocusProcess() { return Compositor_028::getCurrentSceneFocusProcess(); }
            virtual uint32_t getLastFrameRenderer() { return Compositor_028::getLastFrameRenderer(); }
            virtual bool canRenderScene() { return Compositor_028::canRenderScene(); }
            virtual void showMirrorWindow() { return Compositor_028::showMirrorWindow(); }
            virtual void hideMirrorWindow() { return Compositor_028::hideMirrorWindow(); }
            virtual bool isMirrorWindowVisible() { return Compositor_028::isMirrorWindowVisible(); }
            virtual void compositorDumpImages() { return Compositor_028::compositorDumpImages(); }
            virtual bool shouldAppRenderWithLowResources() { return Compositor_028::shouldAppRenderWithLowResources(); }
            virtual void forceInterleavedReprojectionOn(bool on) { return Compositor_028::forceInterleavedReprojectionOn(on); }
            virtual void forceReconnectProcess() { return Compositor_028::forceReconnectProcess(); }
            virtual void suspendRendering(bool suspend) { return Compositor_028::suspendRendering(suspend); }
            virtual CompositorError getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView) { return Compositor_028::getMirrorTextureD3D11(eye, deviceOrResource, shaderResourceView); }
            virtual void releaseMirrorTextureD3D11(void* shaderResourceView) { return Compositor_028::releaseMirrorTextureD3D11(shaderResourceView); }
            virtual CompositorError getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle) { return Compositor_028::getMirrorTextureGL(eye, textureId, sharedTextureHandle); }
            virtual bool releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle) { return Compositor_028::releaseSharedGLTexture(textureId, sharedTextureHandle); }
            virtual void lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle) { return Compositor_028::lockGLSharedTextureForAccess(sharedTextureHandle); }
            virtual void unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle) { return Compositor_028::unlockGLSharedTextureForAccess(sharedTextureHandle); }
            virtual uint32_t getVulkanInstanceExtensionsRequired(char* value, uint32_t bufferSize) { return Compositor_028::getVulkanInstanceExtensionsRequired(value, bufferSize); }
            virtual uint32_t getVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* device, char* value, uint32_t bufferSize) { return Compositor_028::getVulkanDeviceExtensionsRequired(device, value, bufferSize); }
            virtual void setExplicitTimingMode(CompositorTimingMode timingMode) { return Compositor_028::setExplicitTimingMode(timingMode); }
            virtual CompositorError submitExplicitTimingData() { return Compositor_028::submitExplicitTimingData(); }
            virtual bool isMotionSmoothingEnabled() { return Compositor_028::isMotionSmoothingEnabled(); }
            virtual bool isMotionSmoothingSupported() { return Compositor_028::isMotionSmoothingSupported(); }
            virtual bool isCurrentSceneFocusAppLoading() { return Compositor_028::isCurrentSceneFocusAppLoading(); }
            virtual CompositorError setStageOverride(const char* modelPath, const Matrix34* transform, const StageRenderSettings* renderSettings, uint32_t renderSettingsSize) { return Compositor_028::setStageOverride(modelPath, transform, renderSettings, renderSettingsSize); }
            virtual void clearStageOverride() { return Compositor_028::clearStageOverride(); }
            virtual bool getCompositorBenchmarkResults(BenchmarkResults* benchmarkResults, uint32_t benchmarkResultsSize) { return Compositor_028::getCompositorBenchmarkResults(benchmarkResults, benchmarkResultsSize); }
            virtual CompositorError getLastPosePredictionIDs(uint32_t* renderPosePredictionId, uint32_t* gamePosePredictionId) { return Compositor_028::getLastPosePredictionIDs(renderPosePredictionId, gamePosePredictionId); }
            virtual CompositorError getPosesForFrame(uint32_t posePredictionId, TrackedDevicePose* poses, uint32_t posesCount) { return Compositor_028::getPosesForFrame(posePredictionId, poses, posesCount); }
    };

    //

    struct Compositor_029
    {
        static void setTrackingSpace(TrackingUniverseOrigin origin);
        static TrackingUniverseOrigin getTrackingSpace();

        static CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount);
        static CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose);
        static CompositorError getSubmitTexture(Texture* textureOut, bool* needsFlush, CompositorTextureUsage usage, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags);
        static CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags);
        static CompositorError submitWithArrayIndex(Eye eye, const Texture* texture, uint32_t textureArrayIndex, const TextureBounds* bounds, int32_t submitFlags);
        static void clearLastSubmittedFrame();
        static void postPresentHandoff();

        static bool getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo);
        static uint32_t getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames);
        static float getFrameTimeRemaining();
        static void getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize);

        static void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background);
        static Color getCurrentFadeColor(bool background);
        static void fadeGrid(float seconds, bool fadeGridIn);
        static float getCurrentGridAlpha();

        static CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount);
        static void clearSkyboxOverride();

        static void compositorBringToFront();
        static void compositorGoToBack();
        static void compositorQuit();
        static bool isFullscreen();
        static uint32_t getCurrentSceneFocusProcess();
        static uint32_t getLastFrameRenderer();
        static bool canRenderScene();

        static void showMirrorWindow();
        static void hideMirrorWindow();
        static bool isMirrorWindowVisible();

        static void compositorDumpImages();
        static bool shouldAppRenderWithLowResources();
        static void forceInterleavedReprojectionOn(bool on);
        static void forceReconnectProcess();
        static void suspendRendering(bool suspend);

        static CompositorError getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView);
        static void releaseMirrorTextureD3D11(void* shaderResourceView);
        static CompositorError getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle);
        static bool releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle);
        static void lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle);
        static void unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle);

        static uint32_t getVulkanInstanceExtensionsRequired(char* value, uint32_t bufferSize);
        static uint32_t getVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* device, char* value, uint32_t bufferSize);

        static void setExplicitTimingMode(CompositorTimingMode timingMode);
        static CompositorError submitExplicitTimingData();

        static bool isMotionSmoothingEnabled();
        static bool isMotionSmoothingSupported();

        static bool isCurrentSceneFocusAppLoading();

        static CompositorError setStageOverride(const char* modelPath, const Matrix34* transform, const StageRenderSettings* renderSettings, uint32_t renderSettingsSize);
        static void clearStageOverride();

        static bool getCompositorBenchmarkResults(BenchmarkResults* benchmarkResults, uint32_t benchmarkResultsSize);

        static CompositorError getLastPosePredictionIDs(uint32_t* renderPosePredictionId, uint32_t* gamePosePredictionId);
        static CompositorError getPosesForFrame(uint32_t posePredictionId, TrackedDevicePose* poses, uint32_t posesCount);

        void* setTrackingSpace_ = (void*) setTrackingSpace;
        void* getTrackingSpace_ = (void*) getTrackingSpace;
        void* waitGetPoses_ = (void*) waitGetPoses;
        void* getLastPoses_ = (void*) getLastPoses;
        void* getLastPoseForTrackedDeviceIndex_ = (void*) getLastPoseForTrackedDeviceIndex;
        void* getSubmitTexture_ = (void*) getSubmitTexture;
        void* submit_ = (void*) submit;
        void* submitWithArrayIndex_ = (void*) submitWithArrayIndex;
        void* clearLastSubmittedFrame_ = (void*) clearLastSubmittedFrame;
        void* postPresentHandoff_ = (void*) postPresentHandoff;
        void* getFrameTiming_ = (void*) getFrameTiming;
        void* getFrameTimings_ = (void*) getFrameTimings;
        void* getFrameTimeRemaining_ = (void*) getFrameTimeRemaining;
        void* getCumulativeStats_ = (void*) getCumulativeStats;
        void* fadeToColor_ = (void*) fadeToColor;
        void* getCurrentFadeColor_ = (void*) getCurrentFadeColor;
        void* fadeGrid_ = (void*) fadeGrid;
        void* getCurrentGridAlpha_ = (void*) getCurrentGridAlpha;
        void* setSkyboxOverride_ = (void*) setSkyboxOverride;
        void* clearSkyboxOverride_ = (void*) clearSkyboxOverride;
        void* compositorBringToFront_ = (void*) compositorBringToFront;
        void* compositorGoToBack_ = (void*) compositorGoToBack;
        void* compositorQuit_ = (void*) compositorQuit;
        void* isFullscreen_ = (void*) isFullscreen;
        void* getCurrentSceneFocusProcess_ = (void*) getCurrentSceneFocusProcess;
        void* getLastFrameRenderer_ = (void*) getLastFrameRenderer;
        void* canRenderScene_ = (void*) canRenderScene;
        void* showMirrorWindow_ = (void*) showMirrorWindow;
        void* hideMirrorWindow_ = (void*) hideMirrorWindow;
        void* isMirrorWindowVisible_ = (void*) isMirrorWindowVisible;
        void* compositorDumpImages_ = (void*) compositorDumpImages;
        void* shouldAppRenderWithLowResources_ = (void*) shouldAppRenderWithLowResources;
        void* forceInterleavedReprojectionOn_ = (void*) forceInterleavedReprojectionOn;
        void* forceReconnectProcess_ = (void*) forceReconnectProcess;
        void* suspendRendering_ = (void*) suspendRendering;
        void* getMirrorTextureD3D11_ = (void*) getMirrorTextureD3D11;
        void* releaseMirrorTextureD3D11_ = (void*) releaseMirrorTextureD3D11;
        void* getMirrorTextureGL_ = (void*) getMirrorTextureGL;
        void* releaseSharedGLTexture_ = (void*) releaseSharedGLTexture;
        void* lockGLSharedTextureForAccess_ = (void*) lockGLSharedTextureForAccess;
        void* unlockGLSharedTextureForAccess_ = (void*) unlockGLSharedTextureForAccess;
        void* getVulkanInstanceExtensionsRequired_ = (void*) getVulkanInstanceExtensionsRequired;
        void* getVulkanDeviceExtensionsRequired_ = (void*) getVulkanDeviceExtensionsRequired;
        void* setExplicitTimingMode_ = (void*) setExplicitTimingMode;
        void* submitExplicitTimingData_ = (void*) submitExplicitTimingData;
        void* isMotionSmoothingEnabled_ = (void*) isMotionSmoothingEnabled;
        void* isMotionSmoothingSupported_ = (void*) isMotionSmoothingSupported;
        void* isCurrentSceneFocusAppLoading_ = (void*) isCurrentSceneFocusAppLoading;
        void* setStageOverride_ = (void*) setStageOverride;
        void* clearStageOverride_ = (void*) clearStageOverride;
        void* getCompositorBenchmarkResults_ = (void*) getCompositorBenchmarkResults;
        void* getLastPosePredictionIDs_ = (void*) getLastPosePredictionIDs;
        void* getPosesForFrame_ = (void*) getPosesForFrame;
    };

    class Compositor_029_v
    {
        public:
            virtual void setTrackingSpace(TrackingUniverseOrigin origin) { return Compositor_029::setTrackingSpace(origin); }
            virtual TrackingUniverseOrigin getTrackingSpace() { return Compositor_029::getTrackingSpace(); }
            virtual CompositorError waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_029::waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount) { return Compositor_029::getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount); }
            virtual CompositorError getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose) { return Compositor_029::getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose); }
            virtual CompositorError getSubmitTexture(Texture* textureOut, bool* needsFlush, CompositorTextureUsage usage, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags) { return Compositor_029::getSubmitTexture(textureOut, needsFlush, usage, texture, bounds, submitFlags); }
            virtual CompositorError submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags) { return Compositor_029::submit(eye, texture, bounds, submitFlags); }
            virtual CompositorError submitWithArrayIndex(Eye eye, const Texture* texture, uint32_t textureArrayIndex, const TextureBounds* bounds, int32_t submitFlags) { return Compositor_029::submitWithArrayIndex(eye, texture, textureArrayIndex, bounds, submitFlags); }
            virtual void clearLastSubmittedFrame() { return Compositor_029::clearLastSubmittedFrame(); }
            virtual void postPresentHandoff() { return Compositor_029::postPresentHandoff(); }
            virtual bool getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo) { return Compositor_029::getFrameTiming(timing, framesAgo); }
            virtual uint32_t getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames) { return Compositor_029::getFrameTimings(timings, nFrames); }
            virtual float getFrameTimeRemaining() { return Compositor_029::getFrameTimeRemaining(); }
            virtual void getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize) { return Compositor_029::getCumulativeStats(stats, bufferSize); }
            virtual void fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background) { return Compositor_029::fadeToColor(seconds, red, green, blue, alpha, background); }
            virtual Color getCurrentFadeColor(bool background) { return Compositor_029::getCurrentFadeColor(background); }
            virtual void fadeGrid(float seconds, bool fadeGridIn) { return Compositor_029::fadeGrid(seconds, fadeGridIn); }
            virtual float getCurrentGridAlpha() { return Compositor_029::getCurrentGridAlpha(); }
            virtual CompositorError setSkyboxOverride(const Texture* textures, uint32_t texturesCount) { return Compositor_029::setSkyboxOverride(textures, texturesCount); }
            virtual void clearSkyboxOverride() { return Compositor_029::clearSkyboxOverride(); }
            virtual void compositorBringToFront() { return Compositor_029::compositorBringToFront(); }
            virtual void compositorGoToBack() { return Compositor_029::compositorGoToBack(); }
            virtual void compositorQuit() { return Compositor_029::compositorQuit(); }
            virtual bool isFullscreen() { return Compositor_029::isFullscreen(); }
            virtual uint32_t getCurrentSceneFocusProcess() { return Compositor_029::getCurrentSceneFocusProcess(); }
            virtual uint32_t getLastFrameRenderer() { return Compositor_029::getLastFrameRenderer(); }
            virtual bool canRenderScene() { return Compositor_029::canRenderScene(); }
            virtual void showMirrorWindow() { return Compositor_029::showMirrorWindow(); }
            virtual void hideMirrorWindow() { return Compositor_029::hideMirrorWindow(); }
            virtual bool isMirrorWindowVisible() { return Compositor_029::isMirrorWindowVisible(); }
            virtual void compositorDumpImages() { return Compositor_029::compositorDumpImages(); }
            virtual bool shouldAppRenderWithLowResources() { return Compositor_029::shouldAppRenderWithLowResources(); }
            virtual void forceInterleavedReprojectionOn(bool on) { return Compositor_029::forceInterleavedReprojectionOn(on); }
            virtual void forceReconnectProcess() { return Compositor_029::forceReconnectProcess(); }
            virtual void suspendRendering(bool suspend) { return Compositor_029::suspendRendering(suspend); }
            virtual CompositorError getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView) { return Compositor_029::getMirrorTextureD3D11(eye, deviceOrResource, shaderResourceView); }
            virtual void releaseMirrorTextureD3D11(void* shaderResourceView) { return Compositor_029::releaseMirrorTextureD3D11(shaderResourceView); }
            virtual CompositorError getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle) { return Compositor_029::getMirrorTextureGL(eye, textureId, sharedTextureHandle); }
            virtual bool releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle) { return Compositor_029::releaseSharedGLTexture(textureId, sharedTextureHandle); }
            virtual void lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle) { return Compositor_029::lockGLSharedTextureForAccess(sharedTextureHandle); }
            virtual void unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle) { return Compositor_029::unlockGLSharedTextureForAccess(sharedTextureHandle); }
            virtual uint32_t getVulkanInstanceExtensionsRequired(char* value, uint32_t bufferSize) { return Compositor_029::getVulkanInstanceExtensionsRequired(value, bufferSize); }
            virtual uint32_t getVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* device, char* value, uint32_t bufferSize) { return Compositor_029::getVulkanDeviceExtensionsRequired(device, value, bufferSize); }
            virtual void setExplicitTimingMode(CompositorTimingMode timingMode) { return Compositor_029::setExplicitTimingMode(timingMode); }
            virtual CompositorError submitExplicitTimingData() { return Compositor_029::submitExplicitTimingData(); }
            virtual bool isMotionSmoothingEnabled() { return Compositor_029::isMotionSmoothingEnabled(); }
            virtual bool isMotionSmoothingSupported() { return Compositor_029::isMotionSmoothingSupported(); }
            virtual bool isCurrentSceneFocusAppLoading() { return Compositor_029::isCurrentSceneFocusAppLoading(); }
            virtual CompositorError setStageOverride(const char* modelPath, const Matrix34* transform, const StageRenderSettings* renderSettings, uint32_t renderSettingsSize) { return Compositor_029::setStageOverride(modelPath, transform, renderSettings, renderSettingsSize); }
            virtual void clearStageOverride() { return Compositor_029::clearStageOverride(); }
            virtual bool getCompositorBenchmarkResults(BenchmarkResults* benchmarkResults, uint32_t benchmarkResultsSize) { return Compositor_029::getCompositorBenchmarkResults(benchmarkResults, benchmarkResultsSize); }
            virtual CompositorError getLastPosePredictionIDs(uint32_t* renderPosePredictionId, uint32_t* gamePosePredictionId) { return Compositor_029::getLastPosePredictionIDs(renderPosePredictionId, gamePosePredictionId); }
            virtual CompositorError getPosesForFrame(uint32_t posePredictionId, TrackedDevicePose* poses, uint32_t posesCount) { return Compositor_029::getPosesForFrame(posePredictionId, poses, posesCount); }
    };
}
