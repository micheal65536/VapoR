#include "chaperone.h"
#include "../impl/init.h"
#include "log/stub.h"

using namespace openvr;

ChaperoneCalibrationState Chaperone_002::getCalibrationState()
{
    return openvr::chaperoneImpl->getCalibrationState();
}

ChaperoneCalibrationState Chaperone_003::getCalibrationState()
{
    return openvr::chaperoneImpl->getCalibrationState();
}

ChaperoneCalibrationState Chaperone_004::getCalibrationState()
{
    return openvr::chaperoneImpl->getCalibrationState();
}

bool Chaperone_002::getPlayAreaSize(float* x, float* z)
{
    return openvr::chaperoneImpl->getPlayAreaSize(x, z);
}

bool Chaperone_003::getPlayAreaSize(float* x, float* z)
{
    return openvr::chaperoneImpl->getPlayAreaSize(x, z);
}

bool Chaperone_004::getPlayAreaSize(float* x, float* z)
{
    return openvr::chaperoneImpl->getPlayAreaSize(x, z);
}

bool Chaperone_002::getPlayAreaRect(Quad* rect)
{
    return openvr::chaperoneImpl->getPlayAreaRect(rect);
}

bool Chaperone_003::getPlayAreaRect(Quad* rect)
{
    return openvr::chaperoneImpl->getPlayAreaRect(rect);
}

bool Chaperone_004::getPlayAreaRect(Quad* rect)
{
    return openvr::chaperoneImpl->getPlayAreaRect(rect);
}

void Chaperone_002::reloadInfo()
{
    openvr::chaperoneImpl->reloadInfo();
}

void Chaperone_003::reloadInfo()
{
    openvr::chaperoneImpl->reloadInfo();
}

void Chaperone_004::reloadInfo()
{
    openvr::chaperoneImpl->reloadInfo();
}

void Chaperone_002::setSceneColor(Color color)
{
    openvr::chaperoneImpl->setSceneColor(color);
}

void Chaperone_003::setSceneColor(Color color)
{
    openvr::chaperoneImpl->setSceneColor(color);
}

void Chaperone_004::setSceneColor(Color color)
{
    openvr::chaperoneImpl->setSceneColor(color);
}

void Chaperone_002::getBoundsColor(Color* colors, int colorsCount)
{
    Color cameraColor;
    openvr::chaperoneImpl->getBoundsColor(colors, colorsCount, 0.0f, &cameraColor); // TODO: value for collisionBoundsFadeDistance???
}

void Chaperone_003::getBoundsColor(Color* colors, int colorsCount, float collisionBoundsFadeDistance, Color* cameraColor)
{
    openvr::chaperoneImpl->getBoundsColor(colors, colorsCount, collisionBoundsFadeDistance, cameraColor);
}

void Chaperone_004::getBoundsColor(Color* colors, int colorsCount, float collisionBoundsFadeDistance, Color* cameraColor)
{
    openvr::chaperoneImpl->getBoundsColor(colors, colorsCount, collisionBoundsFadeDistance, cameraColor);
}

bool Chaperone_002::areBoundsVisible()
{
    return openvr::chaperoneImpl->areBoundsVisible();
}

bool Chaperone_003::areBoundsVisible()
{
    return openvr::chaperoneImpl->areBoundsVisible();
}

bool Chaperone_004::areBoundsVisible()
{
    return openvr::chaperoneImpl->areBoundsVisible();
}

void Chaperone_002::forceBoundsVisible(bool force)
{
    openvr::chaperoneImpl->forceBoundsVisible(force);
}

void Chaperone_003::forceBoundsVisible(bool force)
{
    openvr::chaperoneImpl->forceBoundsVisible(force);
}

void Chaperone_004::forceBoundsVisible(bool force)
{
    openvr::chaperoneImpl->forceBoundsVisible(force);
}

void Chaperone_004::resetZeroPose(TrackingUniverseOrigin origin)
{
    openvr::chaperoneImpl->resetZeroPose(origin);
}

//

bool ChaperoneSetup_004::commitWorkingCopy(ChaperoneConfigFile configFile)
{
    return openvr::chaperoneSetupImpl->commitWorkingCopy(configFile);
}

bool ChaperoneSetup_005::commitWorkingCopy(ChaperoneConfigFile configFile)
{
    return openvr::chaperoneSetupImpl->commitWorkingCopy(configFile);
}

bool ChaperoneSetup_006::commitWorkingCopy(ChaperoneConfigFile configFile)
{
    return openvr::chaperoneSetupImpl->commitWorkingCopy(configFile);
}

void ChaperoneSetup_004::revertWorkingCopy()
{
    openvr::chaperoneSetupImpl->revertWorkingCopy();
}

void ChaperoneSetup_005::revertWorkingCopy()
{
    openvr::chaperoneSetupImpl->revertWorkingCopy();
}

void ChaperoneSetup_006::revertWorkingCopy()
{
    openvr::chaperoneSetupImpl->revertWorkingCopy();
}

bool ChaperoneSetup_004::getWorkingPlayAreaSize(float* x, float* z)
{
    return openvr::chaperoneSetupImpl->getWorkingPlayAreaSize(x, z);
}

bool ChaperoneSetup_005::getWorkingPlayAreaSize(float* x, float* z)
{
    return openvr::chaperoneSetupImpl->getWorkingPlayAreaSize(x, z);
}

bool ChaperoneSetup_006::getWorkingPlayAreaSize(float* x, float* z)
{
    return openvr::chaperoneSetupImpl->getWorkingPlayAreaSize(x, z);
}

bool ChaperoneSetup_004::getWorkingPlayAreaRect(Quad* rect)
{
    return openvr::chaperoneSetupImpl->getWorkingPlayAreaRect(rect);
}

bool ChaperoneSetup_005::getWorkingPlayAreaRect(Quad* rect)
{
    return openvr::chaperoneSetupImpl->getWorkingPlayAreaRect(rect);
}

bool ChaperoneSetup_006::getWorkingPlayAreaRect(Quad* rect)
{
    return openvr::chaperoneSetupImpl->getWorkingPlayAreaRect(rect);
}

bool ChaperoneSetup_004::getWorkingCollisionBoundsInfo(Quad* quadsBuffer, uint32_t* quadsCount)
{
    return openvr::chaperoneSetupImpl->getWorkingCollisionBoundsInfo(quadsBuffer, quadsCount);
}

bool ChaperoneSetup_005::getWorkingCollisionBoundsInfo(Quad* quadsBuffer, uint32_t* quadsCount)
{
    return openvr::chaperoneSetupImpl->getWorkingCollisionBoundsInfo(quadsBuffer, quadsCount);
}

bool ChaperoneSetup_006::getWorkingCollisionBoundsInfo(Quad* quadsBuffer, uint32_t* quadsCount)
{
    return openvr::chaperoneSetupImpl->getWorkingCollisionBoundsInfo(quadsBuffer, quadsCount);
}

bool ChaperoneSetup_004::getLiveCollisionBoundsInfo(Quad* quadsBuffer, uint32_t* quadsCount)
{
    return openvr::chaperoneSetupImpl->getLiveCollisionBoundsInfo(quadsBuffer, quadsCount);
}

bool ChaperoneSetup_005::getLiveCollisionBoundsInfo(Quad* quadsBuffer, uint32_t* quadsCount)
{
    return openvr::chaperoneSetupImpl->getLiveCollisionBoundsInfo(quadsBuffer, quadsCount);
}

bool ChaperoneSetup_006::getLiveCollisionBoundsInfo(Quad* quadsBuffer, uint32_t* quadsCount)
{
    return openvr::chaperoneSetupImpl->getLiveCollisionBoundsInfo(quadsBuffer, quadsCount);
}

bool ChaperoneSetup_004::getWorkingSeatedZeroPoseToRawTrackingPose(Matrix34* matrix)
{
    return openvr::chaperoneSetupImpl->getWorkingSeatedZeroPoseToRawTrackingPose(matrix);
}

bool ChaperoneSetup_005::getWorkingSeatedZeroPoseToRawTrackingPose(Matrix34* matrix)
{
    return openvr::chaperoneSetupImpl->getWorkingSeatedZeroPoseToRawTrackingPose(matrix);
}

bool ChaperoneSetup_006::getWorkingSeatedZeroPoseToRawTrackingPose(Matrix34* matrix)
{
    return openvr::chaperoneSetupImpl->getWorkingSeatedZeroPoseToRawTrackingPose(matrix);
}

bool ChaperoneSetup_004::getWorkingStandingZeroPoseToRawTrackingPose(Matrix34* matrix)
{
    return openvr::chaperoneSetupImpl->getWorkingStandingZeroPoseToRawTrackingPose(matrix);
}

bool ChaperoneSetup_005::getWorkingStandingZeroPoseToRawTrackingPose(Matrix34* matrix)
{
    return openvr::chaperoneSetupImpl->getWorkingStandingZeroPoseToRawTrackingPose(matrix);
}

bool ChaperoneSetup_006::getWorkingStandingZeroPoseToRawTrackingPose(Matrix34* matrix)
{
    return openvr::chaperoneSetupImpl->getWorkingStandingZeroPoseToRawTrackingPose(matrix);
}

void ChaperoneSetup_004::setWorkingPlayAreaSize(float x, float z)
{
    openvr::chaperoneSetupImpl->setWorkingPlayAreaSize(x, z);
}

void ChaperoneSetup_005::setWorkingPlayAreaSize(float x, float z)
{
    openvr::chaperoneSetupImpl->setWorkingPlayAreaSize(x, z);
}

void ChaperoneSetup_006::setWorkingPlayAreaSize(float x, float z)
{
    openvr::chaperoneSetupImpl->setWorkingPlayAreaSize(x, z);
}

void ChaperoneSetup_004::setWorkingCollisionBoundsInfo(Quad* quads, uint32_t quadsCount)
{
    openvr::chaperoneSetupImpl->setWorkingCollisionBoundsInfo(quads, quadsCount);
}

void ChaperoneSetup_005::setWorkingCollisionBoundsInfo(Quad* quads, uint32_t quadsCount)
{
    openvr::chaperoneSetupImpl->setWorkingCollisionBoundsInfo(quads, quadsCount);
}

void ChaperoneSetup_006::setWorkingCollisionBoundsInfo(Quad* quads, uint32_t quadsCount)
{
    openvr::chaperoneSetupImpl->setWorkingCollisionBoundsInfo(quads, quadsCount);
}

void ChaperoneSetup_006::setWorkingPerimeter(Vector2* points, uint32_t pointsCount)
{
    openvr::chaperoneSetupImpl->setWorkingPerimeter(points, pointsCount);
}

void ChaperoneSetup_004::setWorkingSeatedZeroPoseToRawTrackingPose(const Matrix34* matrix)
{
    openvr::chaperoneSetupImpl->setWorkingSeatedZeroPoseToRawTrackingPose(matrix);
}

void ChaperoneSetup_005::setWorkingSeatedZeroPoseToRawTrackingPose(const Matrix34* matrix)
{
    openvr::chaperoneSetupImpl->setWorkingSeatedZeroPoseToRawTrackingPose(matrix);
}

void ChaperoneSetup_006::setWorkingSeatedZeroPoseToRawTrackingPose(const Matrix34* matrix)
{
    openvr::chaperoneSetupImpl->setWorkingSeatedZeroPoseToRawTrackingPose(matrix);
}

void ChaperoneSetup_004::setWorkingStandingZeroPoseToRawTrackingPose(const Matrix34* matrix)
{
    openvr::chaperoneSetupImpl->setWorkingStandingZeroPoseToRawTrackingPose(matrix);
}

void ChaperoneSetup_005::setWorkingStandingZeroPoseToRawTrackingPose(const Matrix34* matrix)
{
    openvr::chaperoneSetupImpl->setWorkingStandingZeroPoseToRawTrackingPose(matrix);
}

void ChaperoneSetup_006::setWorkingStandingZeroPoseToRawTrackingPose(const Matrix34* matrix)
{
    openvr::chaperoneSetupImpl->setWorkingStandingZeroPoseToRawTrackingPose(matrix);
}

void ChaperoneSetup_004::reloadFromDisk(ChaperoneConfigFile configFile)
{
    openvr::chaperoneSetupImpl->reloadFromDisk(configFile);
}

void ChaperoneSetup_005::reloadFromDisk(ChaperoneConfigFile configFile)
{
    openvr::chaperoneSetupImpl->reloadFromDisk(configFile);
}

void ChaperoneSetup_006::reloadFromDisk(ChaperoneConfigFile configFile)
{
    openvr::chaperoneSetupImpl->reloadFromDisk(configFile);
}

bool ChaperoneSetup_004::getLiveSeatedZeroPoseToRawTrackingPose(Matrix34* matrix)
{
    return openvr::chaperoneSetupImpl->getLiveSeatedZeroPoseToRawTrackingPose(matrix);
}

bool ChaperoneSetup_005::getLiveSeatedZeroPoseToRawTrackingPose(Matrix34* matrix)
{
    return openvr::chaperoneSetupImpl->getLiveSeatedZeroPoseToRawTrackingPose(matrix);
}

bool ChaperoneSetup_006::getLiveSeatedZeroPoseToRawTrackingPose(Matrix34* matrix)
{
    return openvr::chaperoneSetupImpl->getLiveSeatedZeroPoseToRawTrackingPose(matrix);
}

void ChaperoneSetup_004::setWorkingWallTagInfo(uint8_t* buffer, uint32_t tagsCount)
{
    openvr::chaperoneSetupImpl->setWorkingWallTagInfo(buffer, tagsCount);
}

bool ChaperoneSetup_004::getLiveWallTagInfo(uint8_t* buffer, uint32_t* tagsCount)
{
    return openvr::chaperoneSetupImpl->getLiveWallTagInfo(buffer, tagsCount);
}

void ChaperoneSetup_005::setWorkingCollisionBoundsTagsInfo(uint8_t* buffer, uint32_t tagsCount)
{
    openvr::chaperoneSetupImpl->setWorkingCollisionBoundsTagsInfo(buffer, tagsCount);
}

bool ChaperoneSetup_005::getLiveCollisionBoundsTagsInfo(uint8_t* buffer, uint32_t* tagsCount)
{
    return openvr::chaperoneSetupImpl->getLiveCollisionBoundsTagsInfo(buffer, tagsCount);
}

bool ChaperoneSetup_005::setWorkingPhysicalBoundsInfo(Quad* buffer, uint32_t quadsCount)
{
    return openvr::chaperoneSetupImpl->setWorkingPhysicalBoundsInfo(buffer, quadsCount);
}

bool ChaperoneSetup_005::getLivePhysicalBoundsInfo(Quad* buffer, uint32_t* quadsCount)
{
    return openvr::chaperoneSetupImpl->getLivePhysicalBoundsInfo(buffer, quadsCount);
}

bool ChaperoneSetup_005::exportLiveToBuffer(char* buffer, uint32_t* bufferSize)
{
    return openvr::chaperoneSetupImpl->exportLiveToBuffer(buffer, bufferSize);
}

bool ChaperoneSetup_006::exportLiveToBuffer(char* buffer, uint32_t* bufferSize)
{
    return openvr::chaperoneSetupImpl->exportLiveToBuffer(buffer, bufferSize);
}

bool ChaperoneSetup_005::importFromBufferToWorking(const char* buffer, uint32_t importFlags)
{
    return openvr::chaperoneSetupImpl->importFromBufferToWorking(buffer, importFlags);
}

bool ChaperoneSetup_006::importFromBufferToWorking(const char* buffer, uint32_t importFlags)
{
    return openvr::chaperoneSetupImpl->importFromBufferToWorking(buffer, importFlags);
}

void ChaperoneSetup_006::showWorkingSetPreview()
{
    openvr::chaperoneSetupImpl->showWorkingSetPreview();
}

void ChaperoneSetup_006::hideWorkingSetPreview()
{
    openvr::chaperoneSetupImpl->showWorkingSetPreview();
}

void ChaperoneSetup_006::roomSetupStarting()
{
    openvr::chaperoneSetupImpl->showWorkingSetPreview();
}
