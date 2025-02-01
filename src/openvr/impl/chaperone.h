#pragma once

#include "../types.h"
#include "client_core.h"

namespace openvr
{
    class ChaperoneImpl
    {
        public:
            ClientCoreImpl& clientCore;
            ChaperoneImpl(ClientCoreImpl& clientCore);

            //

            ChaperoneCalibrationState getCalibrationState();

            bool getPlayAreaSize(float* x, float* z);
            bool getPlayAreaRect(Quad* rect);

            void reloadInfo();

            void setSceneColor(Color color);
            void getBoundsColor(Color* colors, int colorsCount, float collisionBoundsFadeDistance, Color* cameraColor);
            bool areBoundsVisible();
            void forceBoundsVisible(bool force);

            void resetZeroPose(TrackingUniverseOrigin origin);
    };

    class ChaperoneSetupImpl
    {
        public:
            ClientCoreImpl& clientCore;
            ChaperoneSetupImpl(ClientCoreImpl& clientCore);

            //

            bool commitWorkingCopy(ChaperoneConfigFile configFile);
            void revertWorkingCopy();

            bool getWorkingPlayAreaSize(float* x, float* z);
            bool getWorkingPlayAreaRect(Quad* rect);
            bool getWorkingCollisionBoundsInfo(Quad* quadsBuffer, uint32_t* quadsCount);
            bool getLiveCollisionBoundsInfo(Quad* quadsBuffer, uint32_t* quadsCount);

            bool getWorkingSeatedZeroPoseToRawTrackingPose(Matrix34* matrix);
            bool getWorkingStandingZeroPoseToRawTrackingPose(Matrix34* matrix);

            void setWorkingPlayAreaSize(float x, float z);
            void setWorkingCollisionBoundsInfo(Quad* quads, uint32_t quadsCount);
            void setWorkingPerimeter(Vector2* points, uint32_t pointsCount);
            void setWorkingSeatedZeroPoseToRawTrackingPose(const Matrix34* matrix);
            void setWorkingStandingZeroPoseToRawTrackingPose(const Matrix34* matrix);

            void reloadFromDisk(ChaperoneConfigFile configFile);

            bool getLiveSeatedZeroPoseToRawTrackingPose(Matrix34* matrix);

            void setWorkingWallTagInfo(uint8_t* buffer, uint32_t tagsCount);
            bool getLiveWallTagInfo(uint8_t* buffer, uint32_t* tagsCount);
            void setWorkingCollisionBoundsTagsInfo(uint8_t* buffer, uint32_t tagsCount);
            bool getLiveCollisionBoundsTagsInfo(uint8_t* buffer, uint32_t* tagsCount);
            bool setWorkingPhysicalBoundsInfo(Quad* buffer, uint32_t quadsCount);
            bool getLivePhysicalBoundsInfo(Quad* buffer, uint32_t* quadsCount);

            bool exportLiveToBuffer(char* buffer, uint32_t* bufferSize);
            bool importFromBufferToWorking(const char* buffer, uint32_t importFlags);

            void showWorkingSetPreview();
            void hideWorkingSetPreview();

            void roomSetupStarting();
    };
}
