#pragma once

#include "../types.h"

#include "../impl/chaperone.h"

namespace openvr
{
    struct Chaperone_002
    {
        static ChaperoneCalibrationState getCalibrationState();

        static bool getPlayAreaSize(float* x, float* z);
        static bool getPlayAreaRect(Quad* rect);

        static void reloadInfo();

        static void setSceneColor(Color color);
        static void getBoundsColor(Color* colors, int colorsCount);
        static bool areBoundsVisible();
        static void forceBoundsVisible(bool force);
    
        void* getCalibrationState_ = (void*) getCalibrationState;
        void* getPlayAreaSize_ = (void*) getPlayAreaSize;
        void* getPlayAreaRect_ = (void*) getPlayAreaRect;
        void* reloadInfo_ = (void*) reloadInfo;
        void* setSceneColor_ = (void*) setSceneColor;
        void* getBoundsColor_ = (void*) getBoundsColor;
        void* areBoundsVisible_ = (void*) areBoundsVisible;
        void* forceBoundsVisible_ = (void*) forceBoundsVisible;
    };

    class Chaperone_002_v
    {
        public:
            virtual ChaperoneCalibrationState getCalibrationState() { return Chaperone_002::getCalibrationState(); }
            virtual bool getPlayAreaSize(float* x, float* z) { return Chaperone_002::getPlayAreaSize(x, z); }
            virtual bool getPlayAreaRect(Quad* rect) { return Chaperone_002::getPlayAreaRect(rect); }
            virtual void reloadInfo() { return Chaperone_002::reloadInfo(); }
            virtual void setSceneColor(Color color) { return Chaperone_002::setSceneColor(color); }
            virtual void getBoundsColor(Color* colors, int colorsCount) { return Chaperone_002::getBoundsColor(colors, colorsCount); }
            virtual bool areBoundsVisible() { return Chaperone_002::areBoundsVisible(); }
            virtual void forceBoundsVisible(bool force) { return Chaperone_002::forceBoundsVisible(force); }
    };

    //

    struct Chaperone_003
    {
        static ChaperoneCalibrationState getCalibrationState();

        static bool getPlayAreaSize(float* x, float* z);
        static bool getPlayAreaRect(Quad* rect);

        static void reloadInfo();

        static void setSceneColor(Color color);
        static void getBoundsColor(Color* colors, int colorsCount, float collisionBoundsFadeDistance, Color* cameraColor);
        static bool areBoundsVisible();
        static void forceBoundsVisible(bool force);
    
        void* getCalibrationState_ = (void*) getCalibrationState;
        void* getPlayAreaSize_ = (void*) getPlayAreaSize;
        void* getPlayAreaRect_ = (void*) getPlayAreaRect;
        void* reloadInfo_ = (void*) reloadInfo;
        void* setSceneColor_ = (void*) setSceneColor;
        void* getBoundsColor_ = (void*) getBoundsColor;
        void* areBoundsVisible_ = (void*) areBoundsVisible;
        void* forceBoundsVisible_ = (void*) forceBoundsVisible;
    };

    class Chaperone_003_v
    {
        public:
            virtual ChaperoneCalibrationState getCalibrationState() { return Chaperone_003::getCalibrationState(); }
            virtual bool getPlayAreaSize(float* x, float* z) { return Chaperone_003::getPlayAreaSize(x, z); }
            virtual bool getPlayAreaRect(Quad* rect) { return Chaperone_003::getPlayAreaRect(rect); }
            virtual void reloadInfo() { return Chaperone_003::reloadInfo(); }
            virtual void setSceneColor(Color color) { return Chaperone_003::setSceneColor(color); }
            virtual void getBoundsColor(Color* colors, int colorsCount, float collisionBoundsFadeDistance, Color* cameraColor) { return Chaperone_003::getBoundsColor(colors, colorsCount, collisionBoundsFadeDistance, cameraColor); }
            virtual bool areBoundsVisible() { return Chaperone_003::areBoundsVisible(); }
            virtual void forceBoundsVisible(bool force) { return Chaperone_003::forceBoundsVisible(force); }
    };

    //

    struct Chaperone_004
    {
        static ChaperoneCalibrationState getCalibrationState();

        static bool getPlayAreaSize(float* x, float* z);
        static bool getPlayAreaRect(Quad* rect);

        static void reloadInfo();

        static void setSceneColor(Color color);
        static void getBoundsColor(Color* colors, int colorsCount, float collisionBoundsFadeDistance, Color* cameraColor);
        static bool areBoundsVisible();
        static void forceBoundsVisible(bool force);

        static void resetZeroPose(TrackingUniverseOrigin origin);
    
        void* getCalibrationState_ = (void*) getCalibrationState;
        void* getPlayAreaSize_ = (void*) getPlayAreaSize;
        void* getPlayAreaRect_ = (void*) getPlayAreaRect;
        void* reloadInfo_ = (void*) reloadInfo;
        void* setSceneColor_ = (void*) setSceneColor;
        void* getBoundsColor_ = (void*) getBoundsColor;
        void* areBoundsVisible_ = (void*) areBoundsVisible;
        void* forceBoundsVisible_ = (void*) forceBoundsVisible;
        void* resetZeroPose_ = (void*) resetZeroPose;
    };

    class Chaperone_004_v
    {
        public:
            virtual ChaperoneCalibrationState getCalibrationState() { return Chaperone_004::getCalibrationState(); }
            virtual bool getPlayAreaSize(float* x, float* z) { return Chaperone_004::getPlayAreaSize(x, z); }
            virtual bool getPlayAreaRect(Quad* rect) { return Chaperone_004::getPlayAreaRect(rect); }
            virtual void reloadInfo() { return Chaperone_004::reloadInfo(); }
            virtual void setSceneColor(Color color) { return Chaperone_004::setSceneColor(color); }
            virtual void getBoundsColor(Color* colors, int colorsCount, float collisionBoundsFadeDistance, Color* cameraColor) { return Chaperone_004::getBoundsColor(colors, colorsCount, collisionBoundsFadeDistance, cameraColor); }
            virtual bool areBoundsVisible() { return Chaperone_004::areBoundsVisible(); }
            virtual void forceBoundsVisible(bool force) { return Chaperone_004::forceBoundsVisible(force); }
            virtual void resetZeroPose(TrackingUniverseOrigin origin) { return Chaperone_004::resetZeroPose(origin); }
    };

    //

    struct ChaperoneSetup_004
    {
        static bool commitWorkingCopy(ChaperoneConfigFile configFile);
        static void revertWorkingCopy();

        static bool getWorkingPlayAreaSize(float* x, float* z);
        static bool getWorkingPlayAreaRect(Quad* rect);
        static bool getWorkingCollisionBoundsInfo(Quad* quadsBuffer, uint32_t* quadsCount);
        static bool getLiveCollisionBoundsInfo(Quad* quadsBuffer, uint32_t* quadsCount);

        static bool getWorkingSeatedZeroPoseToRawTrackingPose(Matrix34* matrix);
        static bool getWorkingStandingZeroPoseToRawTrackingPose(Matrix34* matrix);

        static void setWorkingPlayAreaSize(float x, float z);
        static void setWorkingCollisionBoundsInfo(Quad* quads, uint32_t quadsCount);
        static void setWorkingSeatedZeroPoseToRawTrackingPose(const Matrix34* matrix);
        static void setWorkingStandingZeroPoseToRawTrackingPose(const Matrix34* matrix);

        static void reloadFromDisk(ChaperoneConfigFile configFile);

        static bool getLiveSeatedZeroPoseToRawTrackingPose(Matrix34* matrix);

        static void setWorkingWallTagInfo(uint8_t* buffer, uint32_t tagsCount);
        static bool getLiveWallTagInfo(uint8_t* buffer, uint32_t* tagsCount);
    
        void* commitWorkingCopy_ = (void*) commitWorkingCopy;
        void* revertWorkingCopy_ = (void*) revertWorkingCopy;
        void* getWorkingPlayAreaSize_ = (void*) getWorkingPlayAreaSize;
        void* getWorkingPlayAreaRect_ = (void*) getWorkingPlayAreaRect;
        void* getWorkingCollisionBoundsInfo_ = (void*) getWorkingCollisionBoundsInfo;
        void* getLiveCollisionBoundsInfo_ = (void*) getLiveCollisionBoundsInfo;
        void* getWorkingSeatedZeroPoseToRawTrackingPose_ = (void*) getWorkingSeatedZeroPoseToRawTrackingPose;
        void* getWorkingStandingZeroPoseToRawTrackingPose_ = (void*) getWorkingStandingZeroPoseToRawTrackingPose;
        void* setWorkingPlayAreaSize_ = (void*) setWorkingPlayAreaSize;
        void* setWorkingCollisionBoundsInfo_ = (void*) setWorkingCollisionBoundsInfo;
        void* setWorkingSeatedZeroPoseToRawTrackingPose_ = (void*) setWorkingSeatedZeroPoseToRawTrackingPose;
        void* setWorkingStandingZeroPoseToRawTrackingPose_ = (void*) setWorkingStandingZeroPoseToRawTrackingPose;
        void* reloadFromDisk_ = (void*) reloadFromDisk;
        void* getLiveSeatedZeroPoseToRawTrackingPose_ = (void*) getLiveSeatedZeroPoseToRawTrackingPose;
        void* setWorkingWallTagInfo_ = (void*) setWorkingWallTagInfo;
        void* getLiveWallTagInfo_ = (void*) getLiveWallTagInfo;
    };

    class ChaperoneSetup_004_v
    {
        public:
            virtual bool commitWorkingCopy(ChaperoneConfigFile configFile) { return ChaperoneSetup_004::commitWorkingCopy(configFile); }
            virtual void revertWorkingCopy() { return ChaperoneSetup_004::revertWorkingCopy(); }
            virtual bool getWorkingPlayAreaSize(float* x, float* z) { return ChaperoneSetup_004::getWorkingPlayAreaSize(x, z); }
            virtual bool getWorkingPlayAreaRect(Quad* rect) { return ChaperoneSetup_004::getWorkingPlayAreaRect(rect); }
            virtual bool getWorkingCollisionBoundsInfo(Quad* quadsBuffer, uint32_t* quadsCount) { return ChaperoneSetup_004::getWorkingCollisionBoundsInfo(quadsBuffer, quadsCount); }
            virtual bool getLiveCollisionBoundsInfo(Quad* quadsBuffer, uint32_t* quadsCount) { return ChaperoneSetup_004::getLiveCollisionBoundsInfo(quadsBuffer, quadsCount); }
            virtual bool getWorkingSeatedZeroPoseToRawTrackingPose(Matrix34* matrix) { return ChaperoneSetup_004::getWorkingSeatedZeroPoseToRawTrackingPose(matrix); }
            virtual bool getWorkingStandingZeroPoseToRawTrackingPose(Matrix34* matrix) { return ChaperoneSetup_004::getWorkingStandingZeroPoseToRawTrackingPose(matrix); }
            virtual void setWorkingPlayAreaSize(float x, float z) { return ChaperoneSetup_004::setWorkingPlayAreaSize(x, z); }
            virtual void setWorkingCollisionBoundsInfo(Quad* quads, uint32_t quadsCount) { return ChaperoneSetup_004::setWorkingCollisionBoundsInfo(quads, quadsCount); }
            virtual void setWorkingSeatedZeroPoseToRawTrackingPose(const Matrix34* matrix) { return ChaperoneSetup_004::setWorkingSeatedZeroPoseToRawTrackingPose(matrix); }
            virtual void setWorkingStandingZeroPoseToRawTrackingPose(const Matrix34* matrix) { return ChaperoneSetup_004::setWorkingStandingZeroPoseToRawTrackingPose(matrix); }
            virtual void reloadFromDisk(ChaperoneConfigFile configFile) { return ChaperoneSetup_004::reloadFromDisk(configFile); }
            virtual bool getLiveSeatedZeroPoseToRawTrackingPose(Matrix34* matrix) { return ChaperoneSetup_004::getLiveSeatedZeroPoseToRawTrackingPose(matrix); }
            virtual void setWorkingWallTagInfo(uint8_t* buffer, uint32_t tagsCount) { return ChaperoneSetup_004::setWorkingWallTagInfo(buffer, tagsCount); }
            virtual bool getLiveWallTagInfo(uint8_t* buffer, uint32_t* tagsCount) { return ChaperoneSetup_004::getLiveWallTagInfo(buffer, tagsCount); }
    };

    //

    struct ChaperoneSetup_005
    {
        static bool commitWorkingCopy(ChaperoneConfigFile configFile);
        static void revertWorkingCopy();

        static bool getWorkingPlayAreaSize(float* x, float* z);
        static bool getWorkingPlayAreaRect(Quad* rect);
        static bool getWorkingCollisionBoundsInfo(Quad* quadsBuffer, uint32_t* quadsCount);
        static bool getLiveCollisionBoundsInfo(Quad* quadsBuffer, uint32_t* quadsCount);

        static bool getWorkingSeatedZeroPoseToRawTrackingPose(Matrix34* matrix);
        static bool getWorkingStandingZeroPoseToRawTrackingPose(Matrix34* matrix);

        static void setWorkingPlayAreaSize(float x, float z);
        static void setWorkingCollisionBoundsInfo(Quad* quads, uint32_t quadsCount);
        static void setWorkingSeatedZeroPoseToRawTrackingPose(const Matrix34* matrix);
        static void setWorkingStandingZeroPoseToRawTrackingPose(const Matrix34* matrix);

        static void reloadFromDisk(ChaperoneConfigFile configFile);

        static bool getLiveSeatedZeroPoseToRawTrackingPose(Matrix34* matrix);

        static void setWorkingCollisionBoundsTagsInfo(uint8_t* buffer, uint32_t tagsCount);
        static bool getLiveCollisionBoundsTagsInfo(uint8_t* buffer, uint32_t* tagsCount);
        static bool setWorkingPhysicalBoundsInfo(Quad* buffer, uint32_t quadsCount);
        static bool getLivePhysicalBoundsInfo(Quad* buffer, uint32_t* quadsCount);

        static bool exportLiveToBuffer(char* buffer, uint32_t* bufferSize);
        static bool importFromBufferToWorking(const char* buffer, uint32_t importFlags);
    
        void* commitWorkingCopy_ = (void*) commitWorkingCopy;
        void* revertWorkingCopy_ = (void*) revertWorkingCopy;
        void* getWorkingPlayAreaSize_ = (void*) getWorkingPlayAreaSize;
        void* getWorkingPlayAreaRect_ = (void*) getWorkingPlayAreaRect;
        void* getWorkingCollisionBoundsInfo_ = (void*) getWorkingCollisionBoundsInfo;
        void* getLiveCollisionBoundsInfo_ = (void*) getLiveCollisionBoundsInfo;
        void* getWorkingSeatedZeroPoseToRawTrackingPose_ = (void*) getWorkingSeatedZeroPoseToRawTrackingPose;
        void* getWorkingStandingZeroPoseToRawTrackingPose_ = (void*) getWorkingStandingZeroPoseToRawTrackingPose;
        void* setWorkingPlayAreaSize_ = (void*) setWorkingPlayAreaSize;
        void* setWorkingCollisionBoundsInfo_ = (void*) setWorkingCollisionBoundsInfo;
        void* setWorkingSeatedZeroPoseToRawTrackingPose_ = (void*) setWorkingSeatedZeroPoseToRawTrackingPose;
        void* setWorkingStandingZeroPoseToRawTrackingPose_ = (void*) setWorkingStandingZeroPoseToRawTrackingPose;
        void* reloadFromDisk_ = (void*) reloadFromDisk;
        void* getLiveSeatedZeroPoseToRawTrackingPose_ = (void*) getLiveSeatedZeroPoseToRawTrackingPose;
        void* setWorkingCollisionBoundsTagsInfo_ = (void*) setWorkingCollisionBoundsTagsInfo;
        void* getLiveCollisionBoundsTagsInfo_ = (void*) getLiveCollisionBoundsTagsInfo;
        void* setWorkingPhysicalBoundsInfo_ = (void*) setWorkingPhysicalBoundsInfo;
        void* getLivePhysicalBoundsInfo_ = (void*) getLivePhysicalBoundsInfo;
        void* exportLiveToBuffer_ = (void*) exportLiveToBuffer;
        void* importFromBufferToWorking_ = (void*) importFromBufferToWorking;
    };

    class ChaperoneSetup_005_v
    {
        public:
            virtual bool commitWorkingCopy(ChaperoneConfigFile configFile) { return ChaperoneSetup_005::commitWorkingCopy(configFile); }
            virtual void revertWorkingCopy() { return ChaperoneSetup_005::revertWorkingCopy(); }
            virtual bool getWorkingPlayAreaSize(float* x, float* z) { return ChaperoneSetup_005::getWorkingPlayAreaSize(x, z); }
            virtual bool getWorkingPlayAreaRect(Quad* rect) { return ChaperoneSetup_005::getWorkingPlayAreaRect(rect); }
            virtual bool getWorkingCollisionBoundsInfo(Quad* quadsBuffer, uint32_t* quadsCount) { return ChaperoneSetup_005::getWorkingCollisionBoundsInfo(quadsBuffer, quadsCount); }
            virtual bool getLiveCollisionBoundsInfo(Quad* quadsBuffer, uint32_t* quadsCount) { return ChaperoneSetup_005::getLiveCollisionBoundsInfo(quadsBuffer, quadsCount); }
            virtual bool getWorkingSeatedZeroPoseToRawTrackingPose(Matrix34* matrix) { return ChaperoneSetup_005::getWorkingSeatedZeroPoseToRawTrackingPose(matrix); }
            virtual bool getWorkingStandingZeroPoseToRawTrackingPose(Matrix34* matrix) { return ChaperoneSetup_005::getWorkingStandingZeroPoseToRawTrackingPose(matrix); }
            virtual void setWorkingPlayAreaSize(float x, float z) { return ChaperoneSetup_005::setWorkingPlayAreaSize(x, z); }
            virtual void setWorkingCollisionBoundsInfo(Quad* quads, uint32_t quadsCount) { return ChaperoneSetup_005::setWorkingCollisionBoundsInfo(quads, quadsCount); }
            virtual void setWorkingSeatedZeroPoseToRawTrackingPose(const Matrix34* matrix) { return ChaperoneSetup_005::setWorkingSeatedZeroPoseToRawTrackingPose(matrix); }
            virtual void setWorkingStandingZeroPoseToRawTrackingPose(const Matrix34* matrix) { return ChaperoneSetup_005::setWorkingStandingZeroPoseToRawTrackingPose(matrix); }
            virtual void reloadFromDisk(ChaperoneConfigFile configFile) { return ChaperoneSetup_005::reloadFromDisk(configFile); }
            virtual bool getLiveSeatedZeroPoseToRawTrackingPose(Matrix34* matrix) { return ChaperoneSetup_005::getLiveSeatedZeroPoseToRawTrackingPose(matrix); }
            virtual void setWorkingCollisionBoundsTagsInfo(uint8_t* buffer, uint32_t tagsCount) { return ChaperoneSetup_005::setWorkingCollisionBoundsTagsInfo(buffer, tagsCount); }
            virtual bool getLiveCollisionBoundsTagsInfo(uint8_t* buffer, uint32_t* tagsCount) { return ChaperoneSetup_005::getLiveCollisionBoundsTagsInfo(buffer, tagsCount); }
            virtual bool setWorkingPhysicalBoundsInfo(Quad* buffer, uint32_t quadsCount) { return ChaperoneSetup_005::setWorkingPhysicalBoundsInfo(buffer, quadsCount); }
            virtual bool getLivePhysicalBoundsInfo(Quad* buffer, uint32_t* quadsCount) { return ChaperoneSetup_005::getLivePhysicalBoundsInfo(buffer, quadsCount); }
            virtual bool exportLiveToBuffer(char* buffer, uint32_t* bufferSize) { return ChaperoneSetup_005::exportLiveToBuffer(buffer, bufferSize); }
            virtual bool importFromBufferToWorking(const char* buffer, uint32_t importFlags) { return ChaperoneSetup_005::importFromBufferToWorking(buffer, importFlags); }
    };

    //

    struct ChaperoneSetup_006
    {
        static bool commitWorkingCopy(ChaperoneConfigFile configFile);
        static void revertWorkingCopy();

        static bool getWorkingPlayAreaSize(float* x, float* z);
        static bool getWorkingPlayAreaRect(Quad* rect);
        static bool getWorkingCollisionBoundsInfo(Quad* quadsBuffer, uint32_t* quadsCount);
        static bool getLiveCollisionBoundsInfo(Quad* quadsBuffer, uint32_t* quadsCount);

        static bool getWorkingSeatedZeroPoseToRawTrackingPose(Matrix34* matrix);
        static bool getWorkingStandingZeroPoseToRawTrackingPose(Matrix34* matrix);

        static void setWorkingPlayAreaSize(float x, float z);
        static void setWorkingCollisionBoundsInfo(Quad* quads, uint32_t quadsCount);
        static void setWorkingPerimeter(Vector2* points, uint32_t pointsCount);
        static void setWorkingSeatedZeroPoseToRawTrackingPose(const Matrix34* matrix);
        static void setWorkingStandingZeroPoseToRawTrackingPose(const Matrix34* matrix);

        static void reloadFromDisk(ChaperoneConfigFile configFile);

        static bool getLiveSeatedZeroPoseToRawTrackingPose(Matrix34* matrix);

        static bool exportLiveToBuffer(char* buffer, uint32_t* bufferSize);
        static bool importFromBufferToWorking(const char* buffer, uint32_t importFlags);

        static void showWorkingSetPreview();
        static void hideWorkingSetPreview();

        static void roomSetupStarting();
    
        void* commitWorkingCopy_ = (void*) commitWorkingCopy;
        void* revertWorkingCopy_ = (void*) revertWorkingCopy;
        void* getWorkingPlayAreaSize_ = (void*) getWorkingPlayAreaSize;
        void* getWorkingPlayAreaRect_ = (void*) getWorkingPlayAreaRect;
        void* getWorkingCollisionBoundsInfo_ = (void*) getWorkingCollisionBoundsInfo;
        void* getLiveCollisionBoundsInfo_ = (void*) getLiveCollisionBoundsInfo;
        void* getWorkingSeatedZeroPoseToRawTrackingPose_ = (void*) getWorkingSeatedZeroPoseToRawTrackingPose;
        void* getWorkingStandingZeroPoseToRawTrackingPose_ = (void*) getWorkingStandingZeroPoseToRawTrackingPose;
        void* setWorkingPlayAreaSize_ = (void*) setWorkingPlayAreaSize;
        void* setWorkingCollisionBoundsInfo_ = (void*) setWorkingCollisionBoundsInfo;
        void* setWorkingPerimeter_ = (void*) setWorkingPerimeter;
        void* setWorkingSeatedZeroPoseToRawTrackingPose_ = (void*) setWorkingSeatedZeroPoseToRawTrackingPose;
        void* setWorkingStandingZeroPoseToRawTrackingPose_ = (void*) setWorkingStandingZeroPoseToRawTrackingPose;
        void* reloadFromDisk_ = (void*) reloadFromDisk;
        void* getLiveSeatedZeroPoseToRawTrackingPose_ = (void*) getLiveSeatedZeroPoseToRawTrackingPose;
        void* exportLiveToBuffer_ = (void*) exportLiveToBuffer;
        void* importFromBufferToWorking_ = (void*) importFromBufferToWorking;
        void* showWorkingSetPreview_ = (void*) showWorkingSetPreview;
        void* hideWorkingSetPreview_ = (void*) hideWorkingSetPreview;
        void* roomSetupStarting_ = (void*) roomSetupStarting;
    };

    class ChaperoneSetup_006_v
    {
        public:
            virtual bool commitWorkingCopy(ChaperoneConfigFile configFile) { return ChaperoneSetup_006::commitWorkingCopy(configFile); }
            virtual void revertWorkingCopy() { return ChaperoneSetup_006::revertWorkingCopy(); }
            virtual bool getWorkingPlayAreaSize(float* x, float* z) { return ChaperoneSetup_006::getWorkingPlayAreaSize(x, z); }
            virtual bool getWorkingPlayAreaRect(Quad* rect) { return ChaperoneSetup_006::getWorkingPlayAreaRect(rect); }
            virtual bool getWorkingCollisionBoundsInfo(Quad* quadsBuffer, uint32_t* quadsCount) { return ChaperoneSetup_006::getWorkingCollisionBoundsInfo(quadsBuffer, quadsCount); }
            virtual bool getLiveCollisionBoundsInfo(Quad* quadsBuffer, uint32_t* quadsCount) { return ChaperoneSetup_006::getLiveCollisionBoundsInfo(quadsBuffer, quadsCount); }
            virtual bool getWorkingSeatedZeroPoseToRawTrackingPose(Matrix34* matrix) { return ChaperoneSetup_006::getWorkingSeatedZeroPoseToRawTrackingPose(matrix); }
            virtual bool getWorkingStandingZeroPoseToRawTrackingPose(Matrix34* matrix) { return ChaperoneSetup_006::getWorkingStandingZeroPoseToRawTrackingPose(matrix); }
            virtual void setWorkingPlayAreaSize(float x, float z) { return ChaperoneSetup_006::setWorkingPlayAreaSize(x, z); }
            virtual void setWorkingCollisionBoundsInfo(Quad* quads, uint32_t quadsCount) { return ChaperoneSetup_006::setWorkingCollisionBoundsInfo(quads, quadsCount); }
            virtual void setWorkingPerimeter(Vector2* points, uint32_t pointsCount) { return ChaperoneSetup_006::setWorkingPerimeter(points, pointsCount); }
            virtual void setWorkingSeatedZeroPoseToRawTrackingPose(const Matrix34* matrix) { return ChaperoneSetup_006::setWorkingSeatedZeroPoseToRawTrackingPose(matrix); }
            virtual void setWorkingStandingZeroPoseToRawTrackingPose(const Matrix34* matrix) { return ChaperoneSetup_006::setWorkingStandingZeroPoseToRawTrackingPose(matrix); }
            virtual void reloadFromDisk(ChaperoneConfigFile configFile) { return ChaperoneSetup_006::reloadFromDisk(configFile); }
            virtual bool getLiveSeatedZeroPoseToRawTrackingPose(Matrix34* matrix) { return ChaperoneSetup_006::getLiveSeatedZeroPoseToRawTrackingPose(matrix); }
            virtual bool exportLiveToBuffer(char* buffer, uint32_t* bufferSize) { return ChaperoneSetup_006::exportLiveToBuffer(buffer, bufferSize); }
            virtual bool importFromBufferToWorking(const char* buffer, uint32_t importFlags) { return ChaperoneSetup_006::importFromBufferToWorking(buffer, importFlags); }
            virtual void showWorkingSetPreview() { return ChaperoneSetup_006::showWorkingSetPreview(); }
            virtual void hideWorkingSetPreview() { return ChaperoneSetup_006::hideWorkingSetPreview(); }
            virtual void roomSetupStarting() { return ChaperoneSetup_006::roomSetupStarting(); }
    };
}
