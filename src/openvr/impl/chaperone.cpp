#include "chaperone.h"
#include "log/log.h"
#include "log/stub.h"

using namespace openvr;

ChaperoneImpl::ChaperoneImpl(ClientCoreImpl& clientCore): clientCore(clientCore)
{
    // empty
}

ChaperoneCalibrationState ChaperoneImpl::getCalibrationState()
{
    TRACE();
    return ChaperoneCalibrationState::CHAPERONE_CALIBRATION_STATE_OK;
}

bool ChaperoneImpl::getPlayAreaSize(float* x, float* z)
{
    STUB();
    return false;
}

bool ChaperoneImpl::getPlayAreaRect(Quad* rect)
{
    STUB();
    return false;
}

void ChaperoneImpl::reloadInfo()
{
    TRACE();
}

void ChaperoneImpl::setSceneColor(Color color)
{
    STUB();
}

void ChaperoneImpl::getBoundsColor(Color* colors, int colorsCount, float collisionBoundsFadeDistance, Color* cameraColor)
{
    STUB_F("%f", collisionBoundsFadeDistance);
}

bool ChaperoneImpl::areBoundsVisible()
{
    TRACE();
    return false;
}

void ChaperoneImpl::forceBoundsVisible(bool force)
{
    TRACE_F("%d", force);
}

void ChaperoneImpl::resetZeroPose(TrackingUniverseOrigin origin)
{
    TRACE_F("%d", origin);
    if (origin == TrackingUniverseOrigin::ORIGIN_SEATED)
    {
        this->clientCore.backend->queueResetSeatedZeroPose(false);
    }
    else if (origin == TrackingUniverseOrigin::ORIGIN_STANDING)
    {
        this->clientCore.backend->queueResetStandingZeroPose(false);
    }
}

//

ChaperoneSetupImpl::ChaperoneSetupImpl(ClientCoreImpl& clientCore): clientCore(clientCore)
{
    // empty
}

bool ChaperoneSetupImpl::commitWorkingCopy(ChaperoneConfigFile configFile)
{
    STUB();
    return false;
}

void ChaperoneSetupImpl::revertWorkingCopy()
{
    STUB();
}

bool ChaperoneSetupImpl::getWorkingPlayAreaSize(float* x, float* z)
{
    STUB();
    return false;
}

bool ChaperoneSetupImpl::getWorkingPlayAreaRect(Quad* rect)
{
    STUB();
    return false;
}

bool ChaperoneSetupImpl::getWorkingCollisionBoundsInfo(Quad* quadsBuffer, uint32_t* quadsCount)
{
    STUB();
    return false;
}

bool ChaperoneSetupImpl::getLiveCollisionBoundsInfo(Quad* quadsBuffer, uint32_t* quadsCount)
{
    STUB();
    return false;
}

bool ChaperoneSetupImpl::getWorkingSeatedZeroPoseToRawTrackingPose(Matrix34* matrix)
{
    STUB();
    return false;
}

bool ChaperoneSetupImpl::getWorkingStandingZeroPoseToRawTrackingPose(Matrix34* matrix)
{
    STUB();
    return false;
}

void ChaperoneSetupImpl::setWorkingPlayAreaSize(float x, float z)
{
    STUB();
}

void ChaperoneSetupImpl::setWorkingCollisionBoundsInfo(Quad* quads, uint32_t quadsCount)
{
    STUB();
}

void ChaperoneSetupImpl::setWorkingPerimeter(Vector2* points, uint32_t pointsCount)
{
    STUB();
}

void ChaperoneSetupImpl::setWorkingSeatedZeroPoseToRawTrackingPose(const Matrix34* matrix)
{
    STUB();
}

void ChaperoneSetupImpl::setWorkingStandingZeroPoseToRawTrackingPose(const Matrix34* matrix)
{
    STUB();
}

void ChaperoneSetupImpl::reloadFromDisk(ChaperoneConfigFile configFile)
{
    STUB();
}

bool ChaperoneSetupImpl::getLiveSeatedZeroPoseToRawTrackingPose(Matrix34* matrix)
{
    STUB();
    return false;
}

void ChaperoneSetupImpl::setWorkingWallTagInfo(uint8_t* buffer, uint32_t tagsCount)
{
    STUB();
}

bool ChaperoneSetupImpl::getLiveWallTagInfo(uint8_t* buffer, uint32_t* tagsCount)
{
    STUB();
    return false;
}

void ChaperoneSetupImpl::setWorkingCollisionBoundsTagsInfo(uint8_t* buffer, uint32_t tagsCount)
{
    STUB();
}

bool ChaperoneSetupImpl::getLiveCollisionBoundsTagsInfo(uint8_t* buffer, uint32_t* tagsCount)
{
    STUB();
    return false;
}

bool ChaperoneSetupImpl::setWorkingPhysicalBoundsInfo(Quad* buffer, uint32_t quadsCount)
{
    STUB();
    return false;
}

bool ChaperoneSetupImpl::getLivePhysicalBoundsInfo(Quad* buffer, uint32_t* quadsCount)
{
    STUB();
    return false;
}

bool ChaperoneSetupImpl::exportLiveToBuffer(char* buffer, uint32_t* bufferSize)
{
    STUB();
    return false;
}

bool ChaperoneSetupImpl::importFromBufferToWorking(const char* buffer, uint32_t importFlags)
{
    STUB();
    return false;
}

void ChaperoneSetupImpl::showWorkingSetPreview()
{
    STUB();
}

void ChaperoneSetupImpl::hideWorkingSetPreview()
{
    STUB();
}

void ChaperoneSetupImpl::roomSetupStarting()
{
    STUB();
}
