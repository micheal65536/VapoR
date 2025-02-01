#include "compositor.h"
#include "../impl/init.h"
#include "log/log.h"
#include "log/stub.h"

using namespace openvr;

static uint32_t errorCodeToString(CompositorError error, char* buffer, uint32_t bufferSize)
{
    // TODO
    STUB();
    return 0;
}

CompositorError Compositor_005::lastError = CompositorError::COMPOSITOR_ERROR_NONE;
CompositorError Compositor_006::lastError = CompositorError::COMPOSITOR_ERROR_NONE;
CompositorError Compositor_007::lastError = CompositorError::COMPOSITOR_ERROR_NONE;
CompositorError Compositor_008::lastError = CompositorError::COMPOSITOR_ERROR_NONE;

DeviceType Compositor_005::deviceType = DeviceType::DEVICE_TYPE_NONE;
DeviceType Compositor_006::deviceType = DeviceType::DEVICE_TYPE_NONE;

uint32_t Compositor_005::getLastError(char* buffer, uint32_t bufferSize)
{
    return errorCodeToString(Compositor_005::lastError, buffer, bufferSize);
}

uint32_t Compositor_006::getLastError(char* buffer, uint32_t bufferSize)
{
    return errorCodeToString(Compositor_006::lastError, buffer, bufferSize);
}

uint32_t Compositor_007::getLastError(char* buffer, uint32_t bufferSize)
{
    return errorCodeToString(Compositor_007::lastError, buffer, bufferSize);
}

uint32_t Compositor_008::getLastError(char* buffer, uint32_t bufferSize)
{
    return errorCodeToString(Compositor_008::lastError, buffer, bufferSize);
}

void Compositor_005::setVSync(bool enabled)
{
    TRACE_F("%d", enabled);
}

void Compositor_006::setVSync(bool enabled)
{
    TRACE_F("%d", enabled);
}

void Compositor_007::setVSync(bool enabled)
{
    TRACE_F("%d", enabled);
}

void Compositor_008::setVSync(bool enabled)
{
    TRACE_F("%d", enabled);
}

bool Compositor_005::getVSync()
{
    TRACE();
    return true;
}

bool Compositor_006::getVSync()
{
    TRACE();
    return true;
}

bool Compositor_007::getVSync()
{
    TRACE();
    return true;
}

bool Compositor_008::getVSync()
{
    TRACE();
    return true;
}

void Compositor_005::setGamma(float gamma)
{
    TRACE();
}

void Compositor_006::setGamma(float gamma)
{
    TRACE();
}

void Compositor_007::setGamma(float gamma)
{
    TRACE();
}

void Compositor_008::setGamma(float gamma)
{
    TRACE();
}

float Compositor_005::getGamma()
{
    STUB();
    return 1.0f;
}

float Compositor_006::getGamma()
{
    STUB();
    return 1.0f;
}

float Compositor_007::getGamma()
{
    STUB();
    return 1.0f;
}

float Compositor_008::getGamma()
{
    STUB();
    return 1.0f;
}

void Compositor_005::setTrackingSpace(TrackingUniverseOrigin origin)
{
    openvr::compositorImpl->setTrackingSpace(origin);
}

void Compositor_006::setTrackingSpace(TrackingUniverseOrigin origin)
{
    openvr::compositorImpl->setTrackingSpace(origin);
}

void Compositor_007::setTrackingSpace(TrackingUniverseOrigin origin)
{
    openvr::compositorImpl->setTrackingSpace(origin);
}

void Compositor_008::setTrackingSpace(TrackingUniverseOrigin origin)
{
    openvr::compositorImpl->setTrackingSpace(origin);
}

void Compositor_009::setTrackingSpace(TrackingUniverseOrigin origin)
{
    openvr::compositorImpl->setTrackingSpace(origin);
}

void Compositor_011::setTrackingSpace(TrackingUniverseOrigin origin)
{
    openvr::compositorImpl->setTrackingSpace(origin);
}

void Compositor_012::setTrackingSpace(TrackingUniverseOrigin origin)
{
    openvr::compositorImpl->setTrackingSpace(origin);
}

void Compositor_013::setTrackingSpace(TrackingUniverseOrigin origin)
{
    openvr::compositorImpl->setTrackingSpace(origin);
}

void Compositor_014::setTrackingSpace(TrackingUniverseOrigin origin)
{
    openvr::compositorImpl->setTrackingSpace(origin);
}

void Compositor_015::setTrackingSpace(TrackingUniverseOrigin origin)
{
    openvr::compositorImpl->setTrackingSpace(origin);
}

void Compositor_016::setTrackingSpace(TrackingUniverseOrigin origin)
{
    openvr::compositorImpl->setTrackingSpace(origin);
}

void Compositor_018::setTrackingSpace(TrackingUniverseOrigin origin)
{
    openvr::compositorImpl->setTrackingSpace(origin);
}

void Compositor_019::setTrackingSpace(TrackingUniverseOrigin origin)
{
    openvr::compositorImpl->setTrackingSpace(origin);
}

void Compositor_020::setTrackingSpace(TrackingUniverseOrigin origin)
{
    openvr::compositorImpl->setTrackingSpace(origin);
}

void Compositor_021::setTrackingSpace(TrackingUniverseOrigin origin)
{
    openvr::compositorImpl->setTrackingSpace(origin);
}

void Compositor_022::setTrackingSpace(TrackingUniverseOrigin origin)
{
    openvr::compositorImpl->setTrackingSpace(origin);
}

void Compositor_024::setTrackingSpace(TrackingUniverseOrigin origin)
{
    openvr::compositorImpl->setTrackingSpace(origin);
}

void Compositor_026::setTrackingSpace(TrackingUniverseOrigin origin)
{
    openvr::compositorImpl->setTrackingSpace(origin);
}

void Compositor_028::setTrackingSpace(TrackingUniverseOrigin origin)
{
    openvr::compositorImpl->setTrackingSpace(origin);
}

TrackingUniverseOrigin Compositor_005::getTrackingSpace()
{
    return openvr::compositorImpl->getTrackingSpace();
}

TrackingUniverseOrigin Compositor_006::getTrackingSpace()
{
    return openvr::compositorImpl->getTrackingSpace();
}

TrackingUniverseOrigin Compositor_007::getTrackingSpace()
{
    return openvr::compositorImpl->getTrackingSpace();
}

TrackingUniverseOrigin Compositor_008::getTrackingSpace()
{
    return openvr::compositorImpl->getTrackingSpace();
}

TrackingUniverseOrigin Compositor_009::getTrackingSpace()
{
    return openvr::compositorImpl->getTrackingSpace();
}

TrackingUniverseOrigin Compositor_011::getTrackingSpace()
{
    return openvr::compositorImpl->getTrackingSpace();
}

TrackingUniverseOrigin Compositor_012::getTrackingSpace()
{
    return openvr::compositorImpl->getTrackingSpace();
}

TrackingUniverseOrigin Compositor_013::getTrackingSpace()
{
    return openvr::compositorImpl->getTrackingSpace();
}

TrackingUniverseOrigin Compositor_014::getTrackingSpace()
{
    return openvr::compositorImpl->getTrackingSpace();
}

TrackingUniverseOrigin Compositor_015::getTrackingSpace()
{
    return openvr::compositorImpl->getTrackingSpace();
}

TrackingUniverseOrigin Compositor_016::getTrackingSpace()
{
    return openvr::compositorImpl->getTrackingSpace();
}

TrackingUniverseOrigin Compositor_018::getTrackingSpace()
{
    return openvr::compositorImpl->getTrackingSpace();
}

TrackingUniverseOrigin Compositor_019::getTrackingSpace()
{
    return openvr::compositorImpl->getTrackingSpace();
}

TrackingUniverseOrigin Compositor_020::getTrackingSpace()
{
    return openvr::compositorImpl->getTrackingSpace();
}

TrackingUniverseOrigin Compositor_021::getTrackingSpace()
{
    return openvr::compositorImpl->getTrackingSpace();
}

TrackingUniverseOrigin Compositor_022::getTrackingSpace()
{
    return openvr::compositorImpl->getTrackingSpace();
}

TrackingUniverseOrigin Compositor_024::getTrackingSpace()
{
    return openvr::compositorImpl->getTrackingSpace();
}

TrackingUniverseOrigin Compositor_026::getTrackingSpace()
{
    return openvr::compositorImpl->getTrackingSpace();
}

TrackingUniverseOrigin Compositor_028::getTrackingSpace()
{
    return openvr::compositorImpl->getTrackingSpace();
}

void Compositor_005::setGraphicsDevice(DeviceType deviceType, void* device)
{
    Compositor_005::deviceType = deviceType;
}

void Compositor_006::setGraphicsDevice(DeviceType deviceType, void* device)
{
    Compositor_006::deviceType = deviceType;
}

void Compositor_005::waitGetPoses(TrackedDevicePose* poses, uint32_t posesCount)
{
    Compositor_005::lastError = openvr::compositorImpl->waitGetPoses(poses, posesCount, nullptr, 0);
}

CompositorError Compositor_006::waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return (Compositor_006::lastError = openvr::compositorImpl->waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount));
}

CompositorError Compositor_007::waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return (Compositor_007::lastError = openvr::compositorImpl->waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount));
}

CompositorError Compositor_008::waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return (Compositor_008::lastError = openvr::compositorImpl->waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount));
}

CompositorError Compositor_009::waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_011::waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_012::waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_013::waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_014::waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_015::waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_016::waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_018::waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_019::waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_020::waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_021::waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_022::waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_024::waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_026::waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_028::waitGetPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->waitGetPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_008::getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return (Compositor_008::lastError = openvr::compositorImpl->getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount));
}

CompositorError Compositor_009::getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_011::getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_012::getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_013::getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_014::getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_015::getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_016::getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_018::getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_019::getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_020::getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_021::getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_022::getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_024::getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_026::getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_028::getLastPoses(TrackedDevicePose* renderPoses, uint32_t renderPosesCount, TrackedDevicePose* gamePoses, uint32_t gamePosesCount)
{
    return openvr::compositorImpl->getLastPoses(renderPoses, renderPosesCount, gamePoses, gamePosesCount);
}

CompositorError Compositor_012::getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose)
{
    return openvr::compositorImpl->getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose);
}

CompositorError Compositor_013::getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose)
{
    return openvr::compositorImpl->getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose);
}

CompositorError Compositor_014::getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose)
{
    return openvr::compositorImpl->getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose);
}

CompositorError Compositor_015::getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose)
{
    return openvr::compositorImpl->getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose);
}

CompositorError Compositor_016::getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose)
{
    return openvr::compositorImpl->getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose);
}

CompositorError Compositor_018::getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose)
{
    return openvr::compositorImpl->getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose);
}

CompositorError Compositor_019::getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose)
{
    return openvr::compositorImpl->getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose);
}

CompositorError Compositor_020::getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose)
{
    return openvr::compositorImpl->getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose);
}

CompositorError Compositor_021::getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose)
{
    return openvr::compositorImpl->getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose);
}

CompositorError Compositor_022::getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose)
{
    return openvr::compositorImpl->getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose);
}

CompositorError Compositor_024::getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose)
{
    return openvr::compositorImpl->getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose);
}

CompositorError Compositor_026::getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose)
{
    return openvr::compositorImpl->getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose);
}

CompositorError Compositor_028::getLastPoseForTrackedDeviceIndex(uint32_t deviceIndex, TrackedDevicePose* outputPose, TrackedDevicePose* gamePose)
{
    return openvr::compositorImpl->getLastPoseForTrackedDeviceIndex(deviceIndex, outputPose, gamePose);
}

void Compositor_005::submit(Eye eye, void* texture, const TextureBounds* bounds)
{
    TextureType textureType;
    switch (Compositor_005::deviceType)
    {
        case DeviceType::DEVICE_TYPE_OPENGL:
            textureType = TextureType::TEXTURE_TYPE_OPENGL;
            break;
        case DeviceType::DEVICE_TYPE_D3D9:
        case DeviceType::DEVICE_TYPE_D3D9EX:
        case DeviceType::DEVICE_TYPE_D3D10:
        case DeviceType::DEVICE_TYPE_D3D11:
            textureType = TextureType::TEXTURE_TYPE_DIRECTX_11;
            break;
        case DeviceType::DEVICE_TYPE_NONE:
            TRACE_F("called with no device type set!");
            Compositor_005::lastError = CompositorError::COMPOSITOR_ERROR_REQUEST_FAILED;
            return;
    }
    Texture texture_ {
        .handle = texture,
        .type = textureType,
        .colorSpace = ColorSpace::COLOR_SPACE_AUTO // TODO
    };
    Compositor_005::lastError = openvr::compositorImpl->submit(eye, &texture_, bounds, SubmitFlags::SUBMIT_DEFAULT);
}

CompositorError Compositor_006::submit(Eye eye, void* texture, const TextureBounds* bounds)
{
    TextureType textureType;
    switch (Compositor_006::deviceType)
    {
        case DeviceType::DEVICE_TYPE_OPENGL:
            textureType = TextureType::TEXTURE_TYPE_OPENGL;
            break;
        case DeviceType::DEVICE_TYPE_D3D9:
        case DeviceType::DEVICE_TYPE_D3D9EX:
        case DeviceType::DEVICE_TYPE_D3D10:
        case DeviceType::DEVICE_TYPE_D3D11:
            textureType = TextureType::TEXTURE_TYPE_DIRECTX_11;
            break;
        case DeviceType::DEVICE_TYPE_NONE:
            TRACE_F("called with no device type set!");
            return (Compositor_006::lastError = CompositorError::COMPOSITOR_ERROR_REQUEST_FAILED);
    }
    Texture texture_ {
        .handle = texture,
        .type = textureType,
        .colorSpace = ColorSpace::COLOR_SPACE_AUTO // TODO
    };
    return (Compositor_006::lastError = openvr::compositorImpl->submit(eye, &texture_, bounds, SubmitFlags::SUBMIT_DEFAULT));
}

CompositorError Compositor_007::submit(Eye eye, TextureType textureType, void* texture, const TextureBounds* bounds)
{
    Texture texture_ {
        .handle = texture,
        .type = textureType,
        .colorSpace = ColorSpace::COLOR_SPACE_AUTO // TODO
    };
    return (Compositor_007::lastError = openvr::compositorImpl->submit(eye, &texture_, bounds, SubmitFlags::SUBMIT_DEFAULT));
}

CompositorError Compositor_008::submit(Eye eye, TextureType textureType, void* texture, const TextureBounds* bounds)
{
    Texture texture_ {
        .handle = texture,
        .type = textureType,
        .colorSpace = ColorSpace::COLOR_SPACE_AUTO // TODO
    };
    return (Compositor_008::lastError = openvr::compositorImpl->submit(eye, &texture_, bounds, SubmitFlags::SUBMIT_DEFAULT));
}

CompositorError Compositor_009::submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags)
{
    return openvr::compositorImpl->submit(eye, texture, bounds, submitFlags);
}

CompositorError Compositor_011::submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags)
{
    return openvr::compositorImpl->submit(eye, texture, bounds, submitFlags);
}

CompositorError Compositor_012::submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags)
{
    return openvr::compositorImpl->submit(eye, texture, bounds, submitFlags);
}

CompositorError Compositor_013::submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags)
{
    return openvr::compositorImpl->submit(eye, texture, bounds, submitFlags);
}

CompositorError Compositor_014::submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags)
{
    return openvr::compositorImpl->submit(eye, texture, bounds, submitFlags);
}

CompositorError Compositor_015::submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags)
{
    return openvr::compositorImpl->submit(eye, texture, bounds, submitFlags);
}

CompositorError Compositor_016::submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags)
{
    return openvr::compositorImpl->submit(eye, texture, bounds, submitFlags);
}

CompositorError Compositor_018::submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags)
{
    return openvr::compositorImpl->submit(eye, texture, bounds, submitFlags);
}

CompositorError Compositor_019::submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags)
{
    return openvr::compositorImpl->submit(eye, texture, bounds, submitFlags);
}

CompositorError Compositor_020::submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags)
{
    return openvr::compositorImpl->submit(eye, texture, bounds, submitFlags);
}

CompositorError Compositor_021::submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags)
{
    return openvr::compositorImpl->submit(eye, texture, bounds, submitFlags);
}

CompositorError Compositor_022::submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags)
{
    return openvr::compositorImpl->submit(eye, texture, bounds, submitFlags);
}

CompositorError Compositor_024::submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags)
{
    return openvr::compositorImpl->submit(eye, texture, bounds, submitFlags);
}

CompositorError Compositor_026::submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags)
{
    return openvr::compositorImpl->submit(eye, texture, bounds, submitFlags);
}

CompositorError Compositor_028::submit(Eye eye, const Texture* texture, const TextureBounds* bounds, int32_t submitFlags)
{
    return openvr::compositorImpl->submit(eye, texture, bounds, submitFlags);
}

CompositorError Compositor_028::submitWithArrayIndex(Eye eye, const Texture* texture, uint32_t textureArrayIndex, const TextureBounds* bounds, int32_t submitFlags)
{
    return openvr::compositorImpl->submitWithArrayIndex(eye, texture, textureArrayIndex, bounds, submitFlags);
}

void Compositor_005::clearLastSubmittedFrame()
{
    openvr::compositorImpl->clearLastSubmittedFrame();
}

void Compositor_006::clearLastSubmittedFrame()
{
    openvr::compositorImpl->clearLastSubmittedFrame();
}

void Compositor_007::clearLastSubmittedFrame()
{
    openvr::compositorImpl->clearLastSubmittedFrame();
}

void Compositor_008::clearLastSubmittedFrame()
{
    openvr::compositorImpl->clearLastSubmittedFrame();
}

void Compositor_009::clearLastSubmittedFrame()
{
    openvr::compositorImpl->clearLastSubmittedFrame();
}

void Compositor_011::clearLastSubmittedFrame()
{
    openvr::compositorImpl->clearLastSubmittedFrame();
}

void Compositor_012::clearLastSubmittedFrame()
{
    openvr::compositorImpl->clearLastSubmittedFrame();
}

void Compositor_013::clearLastSubmittedFrame()
{
    openvr::compositorImpl->clearLastSubmittedFrame();
}

void Compositor_014::clearLastSubmittedFrame()
{
    openvr::compositorImpl->clearLastSubmittedFrame();
}

void Compositor_015::clearLastSubmittedFrame()
{
    openvr::compositorImpl->clearLastSubmittedFrame();
}

void Compositor_016::clearLastSubmittedFrame()
{
    openvr::compositorImpl->clearLastSubmittedFrame();
}

void Compositor_018::clearLastSubmittedFrame()
{
    openvr::compositorImpl->clearLastSubmittedFrame();
}

void Compositor_019::clearLastSubmittedFrame()
{
    openvr::compositorImpl->clearLastSubmittedFrame();
}

void Compositor_020::clearLastSubmittedFrame()
{
    openvr::compositorImpl->clearLastSubmittedFrame();
}

void Compositor_021::clearLastSubmittedFrame()
{
    openvr::compositorImpl->clearLastSubmittedFrame();
}

void Compositor_022::clearLastSubmittedFrame()
{
    openvr::compositorImpl->clearLastSubmittedFrame();
}

void Compositor_024::clearLastSubmittedFrame()
{
    openvr::compositorImpl->clearLastSubmittedFrame();
}

void Compositor_026::clearLastSubmittedFrame()
{
    openvr::compositorImpl->clearLastSubmittedFrame();
}

void Compositor_028::clearLastSubmittedFrame()
{
    openvr::compositorImpl->clearLastSubmittedFrame();
}

void Compositor_008::postPresentHandoff()
{
    openvr::compositorImpl->postPresentHandoff();
}

void Compositor_009::postPresentHandoff()
{
    openvr::compositorImpl->postPresentHandoff();
}

void Compositor_011::postPresentHandoff()
{
    openvr::compositorImpl->postPresentHandoff();
}

void Compositor_012::postPresentHandoff()
{
    openvr::compositorImpl->postPresentHandoff();
}

void Compositor_013::postPresentHandoff()
{
    openvr::compositorImpl->postPresentHandoff();
}

void Compositor_014::postPresentHandoff()
{
    openvr::compositorImpl->postPresentHandoff();
}

void Compositor_015::postPresentHandoff()
{
    openvr::compositorImpl->postPresentHandoff();
}

void Compositor_016::postPresentHandoff()
{
    openvr::compositorImpl->postPresentHandoff();
}

void Compositor_018::postPresentHandoff()
{
    openvr::compositorImpl->postPresentHandoff();
}

void Compositor_019::postPresentHandoff()
{
    openvr::compositorImpl->postPresentHandoff();
}

void Compositor_020::postPresentHandoff()
{
    openvr::compositorImpl->postPresentHandoff();
}

void Compositor_021::postPresentHandoff()
{
    openvr::compositorImpl->postPresentHandoff();
}

void Compositor_022::postPresentHandoff()
{
    openvr::compositorImpl->postPresentHandoff();
}

void Compositor_024::postPresentHandoff()
{
    openvr::compositorImpl->postPresentHandoff();
}

void Compositor_026::postPresentHandoff()
{
    openvr::compositorImpl->postPresentHandoff();
}

void Compositor_028::postPresentHandoff()
{
    openvr::compositorImpl->postPresentHandoff();
}

bool Compositor_005::getFrameTiming(FrameTiming_0_9_0* timing, uint32_t framesAgo)
{
    return openvr::compositorImpl->getFrameTiming(timing, framesAgo);
}

bool Compositor_006::getFrameTiming(FrameTiming_0_9_0* timing, uint32_t framesAgo)
{
    return openvr::compositorImpl->getFrameTiming(timing, framesAgo);
}

bool Compositor_007::getFrameTiming(FrameTiming_0_9_0* timing, uint32_t framesAgo)
{
    return openvr::compositorImpl->getFrameTiming(timing, framesAgo);
}

bool Compositor_008::getFrameTiming(FrameTiming_0_9_0* timing, uint32_t framesAgo)
{
    return openvr::compositorImpl->getFrameTiming(timing, framesAgo);
}

bool Compositor_009::getFrameTiming(FrameTiming_0_9_0* timing, uint32_t framesAgo)
{
    return openvr::compositorImpl->getFrameTiming(timing, framesAgo);
}

bool Compositor_011::getFrameTiming(FrameTiming_0_9_15* timing, uint32_t framesAgo)
{
    return openvr::compositorImpl->getFrameTiming(timing, framesAgo);
}

bool Compositor_012::getFrameTiming(FrameTiming_0_9_15* timing, uint32_t framesAgo)
{
    return openvr::compositorImpl->getFrameTiming(timing, framesAgo);
}

bool Compositor_013::getFrameTiming(FrameTiming_0_9_15* timing, uint32_t framesAgo)
{
    return openvr::compositorImpl->getFrameTiming(timing, framesAgo);
}

bool Compositor_014::getFrameTiming(FrameTiming_0_9_15* timing, uint32_t framesAgo)
{
    return openvr::compositorImpl->getFrameTiming(timing, framesAgo);
}

bool Compositor_015::getFrameTiming(FrameTiming_0_9_15* timing, uint32_t framesAgo)
{
    return openvr::compositorImpl->getFrameTiming(timing, framesAgo);
}

bool Compositor_016::getFrameTiming(FrameTiming_1_0_2* timing, uint32_t framesAgo)
{
    return openvr::compositorImpl->getFrameTiming(timing, framesAgo);
}

bool Compositor_018::getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo)
{
    return openvr::compositorImpl->getFrameTiming(timing, framesAgo);
}

bool Compositor_019::getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo)
{
    return openvr::compositorImpl->getFrameTiming(timing, framesAgo);
}

bool Compositor_020::getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo)
{
    return openvr::compositorImpl->getFrameTiming(timing, framesAgo);
}

bool Compositor_021::getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo)
{
    return openvr::compositorImpl->getFrameTiming(timing, framesAgo);
}

bool Compositor_022::getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo)
{
    return openvr::compositorImpl->getFrameTiming(timing, framesAgo);
}

bool Compositor_024::getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo)
{
    return openvr::compositorImpl->getFrameTiming(timing, framesAgo);
}

bool Compositor_026::getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo)
{
    return openvr::compositorImpl->getFrameTiming(timing, framesAgo);
}

bool Compositor_028::getFrameTiming(FrameTiming_1_0_4* timing, uint32_t framesAgo)
{
    return openvr::compositorImpl->getFrameTiming(timing, framesAgo);
}

uint32_t Compositor_018::getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames)
{
    return openvr::compositorImpl->getFrameTimings(timings, nFrames);
}

uint32_t Compositor_019::getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames)
{
    return openvr::compositorImpl->getFrameTimings(timings, nFrames);
}

uint32_t Compositor_020::getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames)
{
    return openvr::compositorImpl->getFrameTimings(timings, nFrames);
}

uint32_t Compositor_021::getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames)
{
    return openvr::compositorImpl->getFrameTimings(timings, nFrames);
}

uint32_t Compositor_022::getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames)
{
    return openvr::compositorImpl->getFrameTimings(timings, nFrames);
}

uint32_t Compositor_024::getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames)
{
    return openvr::compositorImpl->getFrameTimings(timings, nFrames);
}

uint32_t Compositor_026::getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames)
{
    return openvr::compositorImpl->getFrameTimings(timings, nFrames);
}

uint32_t Compositor_028::getFrameTimings(FrameTiming_1_0_4* timings, uint32_t nFrames)
{
    return openvr::compositorImpl->getFrameTimings(timings, nFrames);
}

float Compositor_008::getFrameTimeRemaining()
{
    return openvr::compositorImpl->getFrameTimeRemaining();
}

float Compositor_009::getFrameTimeRemaining()
{
    return openvr::compositorImpl->getFrameTimeRemaining();
}

float Compositor_011::getFrameTimeRemaining()
{
    return openvr::compositorImpl->getFrameTimeRemaining();
}

float Compositor_012::getFrameTimeRemaining()
{
    return openvr::compositorImpl->getFrameTimeRemaining();
}

float Compositor_013::getFrameTimeRemaining()
{
    return openvr::compositorImpl->getFrameTimeRemaining();
}

float Compositor_014::getFrameTimeRemaining()
{
    return openvr::compositorImpl->getFrameTimeRemaining();
}

float Compositor_015::getFrameTimeRemaining()
{
    return openvr::compositorImpl->getFrameTimeRemaining();
}

float Compositor_016::getFrameTimeRemaining()
{
    return openvr::compositorImpl->getFrameTimeRemaining();
}

float Compositor_018::getFrameTimeRemaining()
{
    return openvr::compositorImpl->getFrameTimeRemaining();
}

float Compositor_019::getFrameTimeRemaining()
{
    return openvr::compositorImpl->getFrameTimeRemaining();
}

float Compositor_020::getFrameTimeRemaining()
{
    return openvr::compositorImpl->getFrameTimeRemaining();
}

float Compositor_021::getFrameTimeRemaining()
{
    return openvr::compositorImpl->getFrameTimeRemaining();
}

float Compositor_022::getFrameTimeRemaining()
{
    return openvr::compositorImpl->getFrameTimeRemaining();
}

float Compositor_024::getFrameTimeRemaining()
{
    return openvr::compositorImpl->getFrameTimeRemaining();
}

float Compositor_026::getFrameTimeRemaining()
{
    return openvr::compositorImpl->getFrameTimeRemaining();
}

float Compositor_028::getFrameTimeRemaining()
{
    return openvr::compositorImpl->getFrameTimeRemaining();
}

void Compositor_015::getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize)
{
    openvr::compositorImpl->getCumulativeStats(stats, bufferSize);
}

void Compositor_016::getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize)
{
    openvr::compositorImpl->getCumulativeStats(stats, bufferSize);
}

void Compositor_018::getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize)
{
    openvr::compositorImpl->getCumulativeStats(stats, bufferSize);
}

void Compositor_019::getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize)
{
    openvr::compositorImpl->getCumulativeStats(stats, bufferSize);
}

void Compositor_020::getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize)
{
    openvr::compositorImpl->getCumulativeStats(stats, bufferSize);
}

void Compositor_021::getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize)
{
    openvr::compositorImpl->getCumulativeStats(stats, bufferSize);
}

void Compositor_022::getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize)
{
    openvr::compositorImpl->getCumulativeStats(stats, bufferSize);
}

void Compositor_024::getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize)
{
    openvr::compositorImpl->getCumulativeStats(stats, bufferSize);
}

void Compositor_026::getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize)
{
    openvr::compositorImpl->getCumulativeStats(stats, bufferSize);
}

void Compositor_028::getCumulativeStats(CumulativeStats* stats, uint32_t bufferSize)
{
    openvr::compositorImpl->getCumulativeStats(stats, bufferSize);
}

void Compositor_005::getOverlayDefaults(OverlaySettings* settings)
{
    // TODO: requires overlay implementation
    STUB();
}

void Compositor_005::setOverlay(void* texture, const OverlaySettings* settings)
{
    // TODO: requires overlay implementation
    STUB();
}

void Compositor_005::setOverlayRaw(void* buffer, uint32_t width, uint32_t height, uint32_t depth, const OverlaySettings* settings)
{
    // TODO: requires overlay implementation
    STUB();
}

void Compositor_005::setOverlayFromFile(const char* filePath, const OverlaySettings* settings)
{
    // TODO: requires overlay implementation
    STUB();
}

void Compositor_005::clearOverlay()
{
    // TODO: requires overlay implementation
    STUB();
}

void Compositor_005::fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background)
{
    openvr::compositorImpl->fadeToColor(seconds, red, green, blue, alpha, background);
}

void Compositor_006::fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background)
{
    openvr::compositorImpl->fadeToColor(seconds, red, green, blue, alpha, background);
}

void Compositor_007::fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background)
{
    openvr::compositorImpl->fadeToColor(seconds, red, green, blue, alpha, background);
}

void Compositor_008::fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background)
{
    openvr::compositorImpl->fadeToColor(seconds, red, green, blue, alpha, background);
}

void Compositor_009::fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background)
{
    openvr::compositorImpl->fadeToColor(seconds, red, green, blue, alpha, background);
}

void Compositor_011::fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background)
{
    openvr::compositorImpl->fadeToColor(seconds, red, green, blue, alpha, background);
}

void Compositor_012::fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background)
{
    openvr::compositorImpl->fadeToColor(seconds, red, green, blue, alpha, background);
}

void Compositor_013::fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background)
{
    openvr::compositorImpl->fadeToColor(seconds, red, green, blue, alpha, background);
}

void Compositor_014::fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background)
{
    openvr::compositorImpl->fadeToColor(seconds, red, green, blue, alpha, background);
}

void Compositor_015::fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background)
{
    openvr::compositorImpl->fadeToColor(seconds, red, green, blue, alpha, background);
}

void Compositor_016::fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background)
{
    openvr::compositorImpl->fadeToColor(seconds, red, green, blue, alpha, background);
}

void Compositor_018::fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background)
{
    openvr::compositorImpl->fadeToColor(seconds, red, green, blue, alpha, background);
}

void Compositor_019::fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background)
{
    openvr::compositorImpl->fadeToColor(seconds, red, green, blue, alpha, background);
}

void Compositor_020::fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background)
{
    openvr::compositorImpl->fadeToColor(seconds, red, green, blue, alpha, background);
}

void Compositor_021::fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background)
{
    openvr::compositorImpl->fadeToColor(seconds, red, green, blue, alpha, background);
}

void Compositor_022::fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background)
{
    openvr::compositorImpl->fadeToColor(seconds, red, green, blue, alpha, background);
}

void Compositor_024::fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background)
{
    openvr::compositorImpl->fadeToColor(seconds, red, green, blue, alpha, background);
}

void Compositor_026::fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background)
{
    openvr::compositorImpl->fadeToColor(seconds, red, green, blue, alpha, background);
}

void Compositor_028::fadeToColor(float seconds, float red, float green, float blue, float alpha, bool background)
{
    openvr::compositorImpl->fadeToColor(seconds, red, green, blue, alpha, background);
}

Color Compositor_018::getCurrentFadeColor(bool background)
{
    return openvr::compositorImpl->getCurrentFadeColor(background);
}

Color Compositor_019::getCurrentFadeColor(bool background)
{
    return openvr::compositorImpl->getCurrentFadeColor(background);
}

Color Compositor_020::getCurrentFadeColor(bool background)
{
    return openvr::compositorImpl->getCurrentFadeColor(background);
}

Color Compositor_021::getCurrentFadeColor(bool background)
{
    return openvr::compositorImpl->getCurrentFadeColor(background);
}

Color Compositor_022::getCurrentFadeColor(bool background)
{
    return openvr::compositorImpl->getCurrentFadeColor(background);
}

Color Compositor_024::getCurrentFadeColor(bool background)
{
    return openvr::compositorImpl->getCurrentFadeColor(background);
}

Color Compositor_026::getCurrentFadeColor(bool background)
{
    return openvr::compositorImpl->getCurrentFadeColor(background);
}

Color Compositor_028::getCurrentFadeColor(bool background)
{
    return openvr::compositorImpl->getCurrentFadeColor(background);
}

void Compositor_005::fadeGrid(float seconds, bool fadeGridIn)
{
    openvr::compositorImpl->fadeGrid(seconds, fadeGridIn);
}

void Compositor_006::fadeGrid(float seconds, bool fadeGridIn)
{
    openvr::compositorImpl->fadeGrid(seconds, fadeGridIn);
}

void Compositor_007::fadeGrid(float seconds, bool fadeGridIn)
{
    openvr::compositorImpl->fadeGrid(seconds, fadeGridIn);
}

void Compositor_008::fadeGrid(float seconds, bool fadeGridIn)
{
    openvr::compositorImpl->fadeGrid(seconds, fadeGridIn);
}

void Compositor_009::fadeGrid(float seconds, bool fadeGridIn)
{
    openvr::compositorImpl->fadeGrid(seconds, fadeGridIn);
}

void Compositor_011::fadeGrid(float seconds, bool fadeGridIn)
{
    openvr::compositorImpl->fadeGrid(seconds, fadeGridIn);
}

void Compositor_012::fadeGrid(float seconds, bool fadeGridIn)
{
    openvr::compositorImpl->fadeGrid(seconds, fadeGridIn);
}

void Compositor_013::fadeGrid(float seconds, bool fadeGridIn)
{
    openvr::compositorImpl->fadeGrid(seconds, fadeGridIn);
}

void Compositor_014::fadeGrid(float seconds, bool fadeGridIn)
{
    openvr::compositorImpl->fadeGrid(seconds, fadeGridIn);
}

void Compositor_015::fadeGrid(float seconds, bool fadeGridIn)
{
    openvr::compositorImpl->fadeGrid(seconds, fadeGridIn);
}

void Compositor_016::fadeGrid(float seconds, bool fadeGridIn)
{
    openvr::compositorImpl->fadeGrid(seconds, fadeGridIn);
}

void Compositor_018::fadeGrid(float seconds, bool fadeGridIn)
{
    openvr::compositorImpl->fadeGrid(seconds, fadeGridIn);
}

void Compositor_019::fadeGrid(float seconds, bool fadeGridIn)
{
    openvr::compositorImpl->fadeGrid(seconds, fadeGridIn);
}

void Compositor_020::fadeGrid(float seconds, bool fadeGridIn)
{
    openvr::compositorImpl->fadeGrid(seconds, fadeGridIn);
}

void Compositor_021::fadeGrid(float seconds, bool fadeGridIn)
{
    openvr::compositorImpl->fadeGrid(seconds, fadeGridIn);
}

void Compositor_022::fadeGrid(float seconds, bool fadeGridIn)
{
    openvr::compositorImpl->fadeGrid(seconds, fadeGridIn);
}

void Compositor_024::fadeGrid(float seconds, bool fadeGridIn)
{
    openvr::compositorImpl->fadeGrid(seconds, fadeGridIn);
}

void Compositor_026::fadeGrid(float seconds, bool fadeGridIn)
{
    openvr::compositorImpl->fadeGrid(seconds, fadeGridIn);
}

void Compositor_028::fadeGrid(float seconds, bool fadeGridIn)
{
    openvr::compositorImpl->fadeGrid(seconds, fadeGridIn);
}

float Compositor_018::getCurrentGridAlpha()
{
    return openvr::compositorImpl->getCurrentGridAlpha();
}

float Compositor_019::getCurrentGridAlpha()
{
    return openvr::compositorImpl->getCurrentGridAlpha();
}

float Compositor_020::getCurrentGridAlpha()
{
    return openvr::compositorImpl->getCurrentGridAlpha();
}

float Compositor_021::getCurrentGridAlpha()
{
    return openvr::compositorImpl->getCurrentGridAlpha();
}

float Compositor_022::getCurrentGridAlpha()
{
    return openvr::compositorImpl->getCurrentGridAlpha();
}

float Compositor_024::getCurrentGridAlpha()
{
    return openvr::compositorImpl->getCurrentGridAlpha();
}

float Compositor_026::getCurrentGridAlpha()
{
    return openvr::compositorImpl->getCurrentGridAlpha();
}

float Compositor_028::getCurrentGridAlpha()
{
    return openvr::compositorImpl->getCurrentGridAlpha();
}

void Compositor_008::setSkyboxOverride(TextureType textureType, void* front, void* back, void* left, void* right, void* top, void* bottom)
{
    // TODO: verify that this is correct
    Texture textures[] = {
        Texture {
            .handle = front,
            .type = textureType,
            .colorSpace = ColorSpace::COLOR_SPACE_AUTO // TODO
        },
        Texture {
            .handle = back,
            .type = textureType,
            .colorSpace = ColorSpace::COLOR_SPACE_AUTO // TODO
        },
        Texture {
            .handle = left,
            .type = textureType,
            .colorSpace = ColorSpace::COLOR_SPACE_AUTO // TODO
        },
        Texture {
            .handle = right,
            .type = textureType,
            .colorSpace = ColorSpace::COLOR_SPACE_AUTO // TODO
        },
        Texture {
            .handle = top,
            .type = textureType,
            .colorSpace = ColorSpace::COLOR_SPACE_AUTO // TODO
        },
        Texture {
            .handle = bottom,
            .type = textureType,
            .colorSpace = ColorSpace::COLOR_SPACE_AUTO // TODO
        }
    };
    Compositor_008::lastError = openvr::compositorImpl->setSkyboxOverride(textures, 6);
}

CompositorError Compositor_009::setSkyboxOverride(const Texture* textures, uint32_t texturesCount)
{
    return openvr::compositorImpl->setSkyboxOverride(textures, texturesCount);
}

CompositorError Compositor_011::setSkyboxOverride(const Texture* textures, uint32_t texturesCount)
{
    return openvr::compositorImpl->setSkyboxOverride(textures, texturesCount);
}

CompositorError Compositor_012::setSkyboxOverride(const Texture* textures, uint32_t texturesCount)
{
    return openvr::compositorImpl->setSkyboxOverride(textures, texturesCount);
}

CompositorError Compositor_013::setSkyboxOverride(const Texture* textures, uint32_t texturesCount)
{
    return openvr::compositorImpl->setSkyboxOverride(textures, texturesCount);
}

CompositorError Compositor_014::setSkyboxOverride(const Texture* textures, uint32_t texturesCount)
{
    return openvr::compositorImpl->setSkyboxOverride(textures, texturesCount);
}

CompositorError Compositor_015::setSkyboxOverride(const Texture* textures, uint32_t texturesCount)
{
    return openvr::compositorImpl->setSkyboxOverride(textures, texturesCount);
}

CompositorError Compositor_016::setSkyboxOverride(const Texture* textures, uint32_t texturesCount)
{
    return openvr::compositorImpl->setSkyboxOverride(textures, texturesCount);
}

CompositorError Compositor_018::setSkyboxOverride(const Texture* textures, uint32_t texturesCount)
{
    return openvr::compositorImpl->setSkyboxOverride(textures, texturesCount);
}

CompositorError Compositor_019::setSkyboxOverride(const Texture* textures, uint32_t texturesCount)
{
    return openvr::compositorImpl->setSkyboxOverride(textures, texturesCount);
}

CompositorError Compositor_020::setSkyboxOverride(const Texture* textures, uint32_t texturesCount)
{
    return openvr::compositorImpl->setSkyboxOverride(textures, texturesCount);
}

CompositorError Compositor_021::setSkyboxOverride(const Texture* textures, uint32_t texturesCount)
{
    return openvr::compositorImpl->setSkyboxOverride(textures, texturesCount);
}

CompositorError Compositor_022::setSkyboxOverride(const Texture* textures, uint32_t texturesCount)
{
    return openvr::compositorImpl->setSkyboxOverride(textures, texturesCount);
}

CompositorError Compositor_024::setSkyboxOverride(const Texture* textures, uint32_t texturesCount)
{
    return openvr::compositorImpl->setSkyboxOverride(textures, texturesCount);
}

CompositorError Compositor_026::setSkyboxOverride(const Texture* textures, uint32_t texturesCount)
{
    return openvr::compositorImpl->setSkyboxOverride(textures, texturesCount);
}

CompositorError Compositor_028::setSkyboxOverride(const Texture* textures, uint32_t texturesCount)
{
    return openvr::compositorImpl->setSkyboxOverride(textures, texturesCount);
}

void Compositor_008::clearSkyboxOverride()
{
    openvr::compositorImpl->clearSkyboxOverride();
}

void Compositor_009::clearSkyboxOverride()
{
    openvr::compositorImpl->clearSkyboxOverride();
}

void Compositor_011::clearSkyboxOverride()
{
    openvr::compositorImpl->clearSkyboxOverride();
}

void Compositor_012::clearSkyboxOverride()
{
    openvr::compositorImpl->clearSkyboxOverride();
}

void Compositor_013::clearSkyboxOverride()
{
    openvr::compositorImpl->clearSkyboxOverride();
}

void Compositor_014::clearSkyboxOverride()
{
    openvr::compositorImpl->clearSkyboxOverride();
}

void Compositor_015::clearSkyboxOverride()
{
    openvr::compositorImpl->clearSkyboxOverride();
}

void Compositor_016::clearSkyboxOverride()
{
    openvr::compositorImpl->clearSkyboxOverride();
}

void Compositor_018::clearSkyboxOverride()
{
    openvr::compositorImpl->clearSkyboxOverride();
}

void Compositor_019::clearSkyboxOverride()
{
    openvr::compositorImpl->clearSkyboxOverride();
}

void Compositor_020::clearSkyboxOverride()
{
    openvr::compositorImpl->clearSkyboxOverride();
}

void Compositor_021::clearSkyboxOverride()
{
    openvr::compositorImpl->clearSkyboxOverride();
}

void Compositor_022::clearSkyboxOverride()
{
    openvr::compositorImpl->clearSkyboxOverride();
}

void Compositor_024::clearSkyboxOverride()
{
    openvr::compositorImpl->clearSkyboxOverride();
}

void Compositor_026::clearSkyboxOverride()
{
    openvr::compositorImpl->clearSkyboxOverride();
}

void Compositor_028::clearSkyboxOverride()
{
    openvr::compositorImpl->clearSkyboxOverride();
}

void Compositor_005::compositorBringToFront()
{
    TRACE();
}

void Compositor_006::compositorBringToFront()
{
    TRACE();
}

void Compositor_007::compositorBringToFront()
{
    TRACE();
}

void Compositor_008::compositorBringToFront()
{
    TRACE();
}

void Compositor_009::compositorBringToFront()
{
    TRACE();
}

void Compositor_011::compositorBringToFront()
{
    TRACE();
}

void Compositor_012::compositorBringToFront()
{
    TRACE();
}

void Compositor_013::compositorBringToFront()
{
    TRACE();
}

void Compositor_014::compositorBringToFront()
{
    TRACE();
}

void Compositor_015::compositorBringToFront()
{
    TRACE();
}

void Compositor_016::compositorBringToFront()
{
    TRACE();
}

void Compositor_018::compositorBringToFront()
{
    TRACE();
}

void Compositor_019::compositorBringToFront()
{
    TRACE();
}

void Compositor_020::compositorBringToFront()
{
    TRACE();
}

void Compositor_021::compositorBringToFront()
{
    TRACE();
}

void Compositor_022::compositorBringToFront()
{
    TRACE();
}

void Compositor_024::compositorBringToFront()
{
    TRACE();
}

void Compositor_026::compositorBringToFront()
{
    TRACE();
}

void Compositor_028::compositorBringToFront()
{
    TRACE();
}

void Compositor_005::compositorGoToBack()
{
    TRACE();
}

void Compositor_006::compositorGoToBack()
{
    TRACE();
}

void Compositor_007::compositorGoToBack()
{
    TRACE();
}

void Compositor_008::compositorGoToBack()
{
    TRACE();
}

void Compositor_009::compositorGoToBack()
{
    TRACE();
}

void Compositor_011::compositorGoToBack()
{
    TRACE();
}

void Compositor_012::compositorGoToBack()
{
    TRACE();
}

void Compositor_013::compositorGoToBack()
{
    TRACE();
}

void Compositor_014::compositorGoToBack()
{
    TRACE();
}

void Compositor_015::compositorGoToBack()
{
    TRACE();
}

void Compositor_016::compositorGoToBack()
{
    TRACE();
}

void Compositor_018::compositorGoToBack()
{
    TRACE();
}

void Compositor_019::compositorGoToBack()
{
    TRACE();
}

void Compositor_020::compositorGoToBack()
{
    TRACE();
}

void Compositor_021::compositorGoToBack()
{
    TRACE();
}

void Compositor_022::compositorGoToBack()
{
    TRACE();
}

void Compositor_024::compositorGoToBack()
{
    TRACE();
}

void Compositor_026::compositorGoToBack()
{
    TRACE();
}

void Compositor_028::compositorGoToBack()
{
    TRACE();
}

void Compositor_005::compositorQuit()
{
    TRACE();
}

void Compositor_006::compositorQuit()
{
    TRACE();
}

void Compositor_007::compositorQuit()
{
    TRACE();
}

void Compositor_008::compositorQuit()
{
    TRACE();
}

void Compositor_009::compositorQuit()
{
    TRACE();
}

void Compositor_011::compositorQuit()
{
    TRACE();
}

void Compositor_012::compositorQuit()
{
    TRACE();
}

void Compositor_013::compositorQuit()
{
    TRACE();
}

void Compositor_014::compositorQuit()
{
    TRACE();
}

void Compositor_015::compositorQuit()
{
    TRACE();
}

void Compositor_016::compositorQuit()
{
    TRACE();
}

void Compositor_018::compositorQuit()
{
    TRACE();
}

void Compositor_019::compositorQuit()
{
    TRACE();
}

void Compositor_020::compositorQuit()
{
    TRACE();
}

void Compositor_021::compositorQuit()
{
    TRACE();
}

void Compositor_022::compositorQuit()
{
    TRACE();
}

void Compositor_024::compositorQuit()
{
    TRACE();
}

void Compositor_026::compositorQuit()
{
    TRACE();
}

void Compositor_028::compositorQuit()
{
    TRACE();
}

bool Compositor_005::isFullscreen()
{
    TRACE();
    return true;
}

bool Compositor_006::isFullscreen()
{
    TRACE();
    return true;
}

bool Compositor_007::isFullscreen()
{
    TRACE();
    return true;
}

bool Compositor_008::isFullscreen()
{
    TRACE();
    return true;
}

bool Compositor_009::isFullscreen()
{
    TRACE();
    return true;
}

bool Compositor_011::isFullscreen()
{
    TRACE();
    return true;
}

bool Compositor_012::isFullscreen()
{
    TRACE();
    return true;
}

bool Compositor_013::isFullscreen()
{
    TRACE();
    return true;
}

bool Compositor_014::isFullscreen()
{
    TRACE();
    return true;
}

bool Compositor_015::isFullscreen()
{
    TRACE();
    return true;
}

bool Compositor_016::isFullscreen()
{
    TRACE();
    return true;
}

bool Compositor_018::isFullscreen()
{
    TRACE();
    return true;
}

bool Compositor_019::isFullscreen()
{
    TRACE();
    return true;
}

bool Compositor_020::isFullscreen()
{
    TRACE();
    return true;
}

bool Compositor_021::isFullscreen()
{
    TRACE();
    return true;
}

bool Compositor_022::isFullscreen()
{
    TRACE();
    return true;
}

bool Compositor_024::isFullscreen()
{
    TRACE();
    return true;
}

bool Compositor_026::isFullscreen()
{
    TRACE();
    return true;
}

bool Compositor_028::isFullscreen()
{
    TRACE();
    return true;
}

bool Compositor_005::computeOverlayIntersection(const OverlaySettings* settings, float aspectRatio, TrackingUniverseOrigin origin, Vector3 source, Vector3 direction, Vector2* intersectionUV, Vector3* intersectionTrackingSpace)
{
    // TODO: requires overlay implementation
    STUB();
    return false;
}

uint32_t Compositor_006::getCurrentSceneFocusProcess()
{
    return openvr::compositorImpl->getCurrentSceneFocusProcess();
}

uint32_t Compositor_007::getCurrentSceneFocusProcess()
{
    return openvr::compositorImpl->getCurrentSceneFocusProcess();
}

uint32_t Compositor_008::getCurrentSceneFocusProcess()
{
    return openvr::compositorImpl->getCurrentSceneFocusProcess();
}

uint32_t Compositor_009::getCurrentSceneFocusProcess()
{
    return openvr::compositorImpl->getCurrentSceneFocusProcess();
}

uint32_t Compositor_011::getCurrentSceneFocusProcess()
{
    return openvr::compositorImpl->getCurrentSceneFocusProcess();
}

uint32_t Compositor_012::getCurrentSceneFocusProcess()
{
    return openvr::compositorImpl->getCurrentSceneFocusProcess();
}

uint32_t Compositor_013::getCurrentSceneFocusProcess()
{
    return openvr::compositorImpl->getCurrentSceneFocusProcess();
}

uint32_t Compositor_014::getCurrentSceneFocusProcess()
{
    return openvr::compositorImpl->getCurrentSceneFocusProcess();
}

uint32_t Compositor_015::getCurrentSceneFocusProcess()
{
    return openvr::compositorImpl->getCurrentSceneFocusProcess();
}

uint32_t Compositor_016::getCurrentSceneFocusProcess()
{
    return openvr::compositorImpl->getCurrentSceneFocusProcess();
}

uint32_t Compositor_018::getCurrentSceneFocusProcess()
{
    return openvr::compositorImpl->getCurrentSceneFocusProcess();
}

uint32_t Compositor_019::getCurrentSceneFocusProcess()
{
    return openvr::compositorImpl->getCurrentSceneFocusProcess();
}

uint32_t Compositor_020::getCurrentSceneFocusProcess()
{
    return openvr::compositorImpl->getCurrentSceneFocusProcess();
}

uint32_t Compositor_021::getCurrentSceneFocusProcess()
{
    return openvr::compositorImpl->getCurrentSceneFocusProcess();
}

uint32_t Compositor_022::getCurrentSceneFocusProcess()
{
    return openvr::compositorImpl->getCurrentSceneFocusProcess();
}

uint32_t Compositor_024::getCurrentSceneFocusProcess()
{
    return openvr::compositorImpl->getCurrentSceneFocusProcess();
}

uint32_t Compositor_026::getCurrentSceneFocusProcess()
{
    return openvr::compositorImpl->getCurrentSceneFocusProcess();
}

uint32_t Compositor_028::getCurrentSceneFocusProcess()
{
    return openvr::compositorImpl->getCurrentSceneFocusProcess();
}

uint32_t Compositor_008::getLastFrameRenderer()
{
    return openvr::compositorImpl->getLastFrameRenderer();
}

uint32_t Compositor_009::getLastFrameRenderer()
{
    return openvr::compositorImpl->getLastFrameRenderer();
}

uint32_t Compositor_011::getLastFrameRenderer()
{
    return openvr::compositorImpl->getLastFrameRenderer();
}

uint32_t Compositor_012::getLastFrameRenderer()
{
    return openvr::compositorImpl->getLastFrameRenderer();
}

uint32_t Compositor_013::getLastFrameRenderer()
{
    return openvr::compositorImpl->getLastFrameRenderer();
}

uint32_t Compositor_014::getLastFrameRenderer()
{
    return openvr::compositorImpl->getLastFrameRenderer();
}

uint32_t Compositor_015::getLastFrameRenderer()
{
    return openvr::compositorImpl->getLastFrameRenderer();
}

uint32_t Compositor_016::getLastFrameRenderer()
{
    return openvr::compositorImpl->getLastFrameRenderer();
}

uint32_t Compositor_018::getLastFrameRenderer()
{
    return openvr::compositorImpl->getLastFrameRenderer();
}

uint32_t Compositor_019::getLastFrameRenderer()
{
    return openvr::compositorImpl->getLastFrameRenderer();
}

uint32_t Compositor_020::getLastFrameRenderer()
{
    return openvr::compositorImpl->getLastFrameRenderer();
}

uint32_t Compositor_021::getLastFrameRenderer()
{
    return openvr::compositorImpl->getLastFrameRenderer();
}

uint32_t Compositor_022::getLastFrameRenderer()
{
    return openvr::compositorImpl->getLastFrameRenderer();
}

uint32_t Compositor_024::getLastFrameRenderer()
{
    return openvr::compositorImpl->getLastFrameRenderer();
}

uint32_t Compositor_026::getLastFrameRenderer()
{
    return openvr::compositorImpl->getLastFrameRenderer();
}

uint32_t Compositor_028::getLastFrameRenderer()
{
    return openvr::compositorImpl->getLastFrameRenderer();
}

bool Compositor_006::canRenderScene()
{
    TRACE();
    return true;
}

bool Compositor_007::canRenderScene()
{
    TRACE();
    return true;
}

bool Compositor_008::canRenderScene()
{
    TRACE();
    return true;
}

bool Compositor_009::canRenderScene()
{
    TRACE();
    return true;
}

bool Compositor_011::canRenderScene()
{
    TRACE();
    return true;
}

bool Compositor_012::canRenderScene()
{
    TRACE();
    return true;
}

bool Compositor_013::canRenderScene()
{
    TRACE();
    return true;
}

bool Compositor_014::canRenderScene()
{
    TRACE();
    return true;
}

bool Compositor_015::canRenderScene()
{
    TRACE();
    return true;
}

bool Compositor_016::canRenderScene()
{
    TRACE();
    return true;
}

bool Compositor_018::canRenderScene()
{
    TRACE();
    return true;
}

bool Compositor_019::canRenderScene()
{
    TRACE();
    return true;
}

bool Compositor_020::canRenderScene()
{
    TRACE();
    return true;
}

bool Compositor_021::canRenderScene()
{
    TRACE();
    return true;
}

bool Compositor_022::canRenderScene()
{
    TRACE();
    return true;
}

bool Compositor_024::canRenderScene()
{
    TRACE();
    return true;
}

bool Compositor_026::canRenderScene()
{
    TRACE();
    return true;
}

bool Compositor_028::canRenderScene()
{
    TRACE();
    return true;
}

void Compositor_008::showMirrorWindow()
{
    openvr::compositorImpl->showMirrorWindow();
}

void Compositor_009::showMirrorWindow()
{
    openvr::compositorImpl->showMirrorWindow();
}

void Compositor_011::showMirrorWindow()
{
    openvr::compositorImpl->showMirrorWindow();
}

void Compositor_012::showMirrorWindow()
{
    openvr::compositorImpl->showMirrorWindow();
}

void Compositor_013::showMirrorWindow()
{
    openvr::compositorImpl->showMirrorWindow();
}

void Compositor_014::showMirrorWindow()
{
    openvr::compositorImpl->showMirrorWindow();
}

void Compositor_015::showMirrorWindow()
{
    openvr::compositorImpl->showMirrorWindow();
}

void Compositor_016::showMirrorWindow()
{
    openvr::compositorImpl->showMirrorWindow();
}

void Compositor_018::showMirrorWindow()
{
    openvr::compositorImpl->showMirrorWindow();
}

void Compositor_019::showMirrorWindow()
{
    openvr::compositorImpl->showMirrorWindow();
}

void Compositor_020::showMirrorWindow()
{
    openvr::compositorImpl->showMirrorWindow();
}

void Compositor_021::showMirrorWindow()
{
    openvr::compositorImpl->showMirrorWindow();
}

void Compositor_022::showMirrorWindow()
{
    openvr::compositorImpl->showMirrorWindow();
}

void Compositor_024::showMirrorWindow()
{
    openvr::compositorImpl->showMirrorWindow();
}

void Compositor_026::showMirrorWindow()
{
    openvr::compositorImpl->showMirrorWindow();
}

void Compositor_028::showMirrorWindow()
{
    openvr::compositorImpl->showMirrorWindow();
}

void Compositor_008::hideMirrorWindow()
{
    openvr::compositorImpl->hideMirrorWindow();
}

void Compositor_009::hideMirrorWindow()
{
    openvr::compositorImpl->hideMirrorWindow();
}

void Compositor_011::hideMirrorWindow()
{
    openvr::compositorImpl->hideMirrorWindow();
}

void Compositor_012::hideMirrorWindow()
{
    openvr::compositorImpl->hideMirrorWindow();
}

void Compositor_013::hideMirrorWindow()
{
    openvr::compositorImpl->hideMirrorWindow();
}

void Compositor_014::hideMirrorWindow()
{
    openvr::compositorImpl->hideMirrorWindow();
}

void Compositor_015::hideMirrorWindow()
{
    openvr::compositorImpl->hideMirrorWindow();
}

void Compositor_016::hideMirrorWindow()
{
    openvr::compositorImpl->hideMirrorWindow();
}

void Compositor_018::hideMirrorWindow()
{
    openvr::compositorImpl->hideMirrorWindow();
}

void Compositor_019::hideMirrorWindow()
{
    openvr::compositorImpl->hideMirrorWindow();
}

void Compositor_020::hideMirrorWindow()
{
    openvr::compositorImpl->hideMirrorWindow();
}

void Compositor_021::hideMirrorWindow()
{
    openvr::compositorImpl->hideMirrorWindow();
}

void Compositor_022::hideMirrorWindow()
{
    openvr::compositorImpl->hideMirrorWindow();
}

void Compositor_024::hideMirrorWindow()
{
    openvr::compositorImpl->hideMirrorWindow();
}

void Compositor_026::hideMirrorWindow()
{
    openvr::compositorImpl->hideMirrorWindow();
}

void Compositor_028::hideMirrorWindow()
{
    openvr::compositorImpl->hideMirrorWindow();
}

bool Compositor_009::isMirrorWindowVisible()
{
    return openvr::compositorImpl->isMirrorWindowVisible();
}

bool Compositor_011::isMirrorWindowVisible()
{
    return openvr::compositorImpl->isMirrorWindowVisible();
}

bool Compositor_012::isMirrorWindowVisible()
{
    return openvr::compositorImpl->isMirrorWindowVisible();
}

bool Compositor_013::isMirrorWindowVisible()
{
    return openvr::compositorImpl->isMirrorWindowVisible();
}

bool Compositor_014::isMirrorWindowVisible()
{
    return openvr::compositorImpl->isMirrorWindowVisible();
}

bool Compositor_015::isMirrorWindowVisible()
{
    return openvr::compositorImpl->isMirrorWindowVisible();
}

bool Compositor_016::isMirrorWindowVisible()
{
    return openvr::compositorImpl->isMirrorWindowVisible();
}

bool Compositor_018::isMirrorWindowVisible()
{
    return openvr::compositorImpl->isMirrorWindowVisible();
}

bool Compositor_019::isMirrorWindowVisible()
{
    return openvr::compositorImpl->isMirrorWindowVisible();
}

bool Compositor_020::isMirrorWindowVisible()
{
    return openvr::compositorImpl->isMirrorWindowVisible();
}

bool Compositor_021::isMirrorWindowVisible()
{
    return openvr::compositorImpl->isMirrorWindowVisible();
}

bool Compositor_022::isMirrorWindowVisible()
{
    return openvr::compositorImpl->isMirrorWindowVisible();
}

bool Compositor_024::isMirrorWindowVisible()
{
    return openvr::compositorImpl->isMirrorWindowVisible();
}

bool Compositor_026::isMirrorWindowVisible()
{
    return openvr::compositorImpl->isMirrorWindowVisible();
}

bool Compositor_028::isMirrorWindowVisible()
{
    return openvr::compositorImpl->isMirrorWindowVisible();
}

void Compositor_008::compositorDumpImages()
{
    openvr::compositorImpl->compositorDumpImages();
}

void Compositor_009::compositorDumpImages()
{
    openvr::compositorImpl->compositorDumpImages();
}

void Compositor_011::compositorDumpImages()
{
    openvr::compositorImpl->compositorDumpImages();
}

void Compositor_012::compositorDumpImages()
{
    openvr::compositorImpl->compositorDumpImages();
}

void Compositor_013::compositorDumpImages()
{
    openvr::compositorImpl->compositorDumpImages();
}

void Compositor_014::compositorDumpImages()
{
    openvr::compositorImpl->compositorDumpImages();
}

void Compositor_015::compositorDumpImages()
{
    openvr::compositorImpl->compositorDumpImages();
}

void Compositor_016::compositorDumpImages()
{
    openvr::compositorImpl->compositorDumpImages();
}

void Compositor_018::compositorDumpImages()
{
    openvr::compositorImpl->compositorDumpImages();
}

void Compositor_019::compositorDumpImages()
{
    openvr::compositorImpl->compositorDumpImages();
}

void Compositor_020::compositorDumpImages()
{
    openvr::compositorImpl->compositorDumpImages();
}

void Compositor_021::compositorDumpImages()
{
    openvr::compositorImpl->compositorDumpImages();
}

void Compositor_022::compositorDumpImages()
{
    openvr::compositorImpl->compositorDumpImages();
}

void Compositor_024::compositorDumpImages()
{
    openvr::compositorImpl->compositorDumpImages();
}

void Compositor_026::compositorDumpImages()
{
    openvr::compositorImpl->compositorDumpImages();
}

void Compositor_028::compositorDumpImages()
{
    openvr::compositorImpl->compositorDumpImages();
}

bool Compositor_012::shouldAppRenderWithLowResources()
{
    return false;
}

bool Compositor_013::shouldAppRenderWithLowResources()
{
    return false;
}

bool Compositor_014::shouldAppRenderWithLowResources()
{
    return false;
}

bool Compositor_015::shouldAppRenderWithLowResources()
{
    return false;
}

bool Compositor_016::shouldAppRenderWithLowResources()
{
    return false;
}

bool Compositor_018::shouldAppRenderWithLowResources()
{
    return false;
}

bool Compositor_019::shouldAppRenderWithLowResources()
{
    return false;
}

bool Compositor_020::shouldAppRenderWithLowResources()
{
    return false;
}

bool Compositor_021::shouldAppRenderWithLowResources()
{
    return false;
}

bool Compositor_022::shouldAppRenderWithLowResources()
{
    return false;
}

bool Compositor_024::shouldAppRenderWithLowResources()
{
    return false;
}

bool Compositor_026::shouldAppRenderWithLowResources()
{
    return false;
}

bool Compositor_028::shouldAppRenderWithLowResources()
{
    return false;
}

void Compositor_013::forceInterleavedReprojectionOn(bool on)
{
    STUB_F("%d", on);
}

void Compositor_014::forceInterleavedReprojectionOn(bool on)
{
    STUB_F("%d", on);
}

void Compositor_015::forceInterleavedReprojectionOn(bool on)
{
    STUB_F("%d", on);
}

void Compositor_016::forceInterleavedReprojectionOn(bool on)
{
    STUB_F("%d", on);
}

void Compositor_018::forceInterleavedReprojectionOn(bool on)
{
    STUB_F("%d", on);
}

void Compositor_019::forceInterleavedReprojectionOn(bool on)
{
    STUB_F("%d", on);
}

void Compositor_020::forceInterleavedReprojectionOn(bool on)
{
    STUB_F("%d", on);
}

void Compositor_021::forceInterleavedReprojectionOn(bool on)
{
    STUB_F("%d", on);
}

void Compositor_022::forceInterleavedReprojectionOn(bool on)
{
    STUB_F("%d", on);
}

void Compositor_024::forceInterleavedReprojectionOn(bool on)
{
    STUB_F("%d", on);
}

void Compositor_026::forceInterleavedReprojectionOn(bool on)
{
    STUB_F("%d", on);
}

void Compositor_028::forceInterleavedReprojectionOn(bool on)
{
    STUB_F("%d", on);
}

void Compositor_014::forceReconnectProcess()
{
    STUB();
}

void Compositor_015::forceReconnectProcess()
{
    STUB();
}

void Compositor_016::forceReconnectProcess()
{
    STUB();
}

void Compositor_018::forceReconnectProcess()
{
    STUB();
}

void Compositor_019::forceReconnectProcess()
{
    STUB();
}

void Compositor_020::forceReconnectProcess()
{
    STUB();
}

void Compositor_021::forceReconnectProcess()
{
    STUB();
}

void Compositor_022::forceReconnectProcess()
{
    STUB();
}

void Compositor_024::forceReconnectProcess()
{
    STUB();
}

void Compositor_026::forceReconnectProcess()
{
    STUB();
}

void Compositor_028::forceReconnectProcess()
{
    STUB();
}

void Compositor_014::suspendRendering(bool suspend)
{
    openvr::compositorImpl->suspendRendering(suspend);
}

void Compositor_015::suspendRendering(bool suspend)
{
    openvr::compositorImpl->suspendRendering(suspend);
}

void Compositor_016::suspendRendering(bool suspend)
{
    openvr::compositorImpl->suspendRendering(suspend);
}

void Compositor_018::suspendRendering(bool suspend)
{
    openvr::compositorImpl->suspendRendering(suspend);
}

void Compositor_019::suspendRendering(bool suspend)
{
    openvr::compositorImpl->suspendRendering(suspend);
}

void Compositor_020::suspendRendering(bool suspend)
{
    openvr::compositorImpl->suspendRendering(suspend);
}

void Compositor_021::suspendRendering(bool suspend)
{
    openvr::compositorImpl->suspendRendering(suspend);
}

void Compositor_022::suspendRendering(bool suspend)
{
    openvr::compositorImpl->suspendRendering(suspend);
}

void Compositor_024::suspendRendering(bool suspend)
{
    openvr::compositorImpl->suspendRendering(suspend);
}

void Compositor_026::suspendRendering(bool suspend)
{
    openvr::compositorImpl->suspendRendering(suspend);
}

void Compositor_028::suspendRendering(bool suspend)
{
    openvr::compositorImpl->suspendRendering(suspend);
}

CompositorError Compositor_015::requestScreenshot(ScreenshotType screenshotType, const char* destinationFilename, const char* vrDestinationFilename)
{
    // TODO: requires screenshot API implementation
    STUB();
}

ScreenshotType Compositor_015::getCurrentScreenshotType()
{
    // TODO: requires screenshot API implementation
    STUB();
}

CompositorError Compositor_015::getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView)
{
    STUB();
}

CompositorError Compositor_016::getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView)
{
    STUB();
}

CompositorError Compositor_018::getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView)
{
    STUB();
}

CompositorError Compositor_019::getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView)
{
    STUB();
}

CompositorError Compositor_020::getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView)
{
    STUB();
}

CompositorError Compositor_021::getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView)
{
    STUB();
}

CompositorError Compositor_022::getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView)
{
    STUB();
}

CompositorError Compositor_024::getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView)
{
    STUB();
}

CompositorError Compositor_026::getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView)
{
    STUB();
}

CompositorError Compositor_028::getMirrorTextureD3D11(Eye eye, void* deviceOrResource, void** shaderResourceView)
{
    STUB();
}

void Compositor_020::releaseMirrorTextureD3D11(void* shaderResourceView)
{
    STUB();
}

void Compositor_021::releaseMirrorTextureD3D11(void* shaderResourceView)
{
    STUB();
}

void Compositor_022::releaseMirrorTextureD3D11(void* shaderResourceView)
{
    STUB();
}

void Compositor_024::releaseMirrorTextureD3D11(void* shaderResourceView)
{
    STUB();
}

void Compositor_026::releaseMirrorTextureD3D11(void* shaderResourceView)
{
    STUB();
}

void Compositor_028::releaseMirrorTextureD3D11(void* shaderResourceView)
{
    STUB();
}

CompositorError Compositor_015::getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle)
{
    return openvr::compositorImpl->getMirrorTextureGL(eye, textureId, sharedTextureHandle);
}

CompositorError Compositor_016::getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle)
{
    return openvr::compositorImpl->getMirrorTextureGL(eye, textureId, sharedTextureHandle);
}

CompositorError Compositor_018::getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle)
{
    return openvr::compositorImpl->getMirrorTextureGL(eye, textureId, sharedTextureHandle);
}

CompositorError Compositor_019::getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle)
{
    return openvr::compositorImpl->getMirrorTextureGL(eye, textureId, sharedTextureHandle);
}

CompositorError Compositor_020::getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle)
{
    return openvr::compositorImpl->getMirrorTextureGL(eye, textureId, sharedTextureHandle);
}

CompositorError Compositor_021::getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle)
{
    return openvr::compositorImpl->getMirrorTextureGL(eye, textureId, sharedTextureHandle);
}

CompositorError Compositor_022::getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle)
{
    return openvr::compositorImpl->getMirrorTextureGL(eye, textureId, sharedTextureHandle);
}

CompositorError Compositor_024::getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle)
{
    return openvr::compositorImpl->getMirrorTextureGL(eye, textureId, sharedTextureHandle);
}

CompositorError Compositor_026::getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle)
{
    return openvr::compositorImpl->getMirrorTextureGL(eye, textureId, sharedTextureHandle);
}

CompositorError Compositor_028::getMirrorTextureGL(Eye eye, GLuint* textureId, GLSharedTextureHandle** sharedTextureHandle)
{
    return openvr::compositorImpl->getMirrorTextureGL(eye, textureId, sharedTextureHandle);
}

bool Compositor_015::releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle)
{
    return openvr::compositorImpl->releaseSharedGLTexture(textureId, sharedTextureHandle);
}

bool Compositor_016::releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle)
{
    return openvr::compositorImpl->releaseSharedGLTexture(textureId, sharedTextureHandle);
}

bool Compositor_018::releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle)
{
    return openvr::compositorImpl->releaseSharedGLTexture(textureId, sharedTextureHandle);
}

bool Compositor_019::releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle)
{
    return openvr::compositorImpl->releaseSharedGLTexture(textureId, sharedTextureHandle);
}

bool Compositor_020::releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle)
{
    return openvr::compositorImpl->releaseSharedGLTexture(textureId, sharedTextureHandle);
}

bool Compositor_021::releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle)
{
    return openvr::compositorImpl->releaseSharedGLTexture(textureId, sharedTextureHandle);
}

bool Compositor_022::releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle)
{
    return openvr::compositorImpl->releaseSharedGLTexture(textureId, sharedTextureHandle);
}

bool Compositor_024::releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle)
{
    return openvr::compositorImpl->releaseSharedGLTexture(textureId, sharedTextureHandle);
}

bool Compositor_026::releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle)
{
    return openvr::compositorImpl->releaseSharedGLTexture(textureId, sharedTextureHandle);
}

bool Compositor_028::releaseSharedGLTexture(GLuint textureId, GLSharedTextureHandle* sharedTextureHandle)
{
    return openvr::compositorImpl->releaseSharedGLTexture(textureId, sharedTextureHandle);
}

void Compositor_015::lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle)
{
    openvr::compositorImpl->lockGLSharedTextureForAccess(sharedTextureHandle);
}

void Compositor_016::lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle)
{
    openvr::compositorImpl->lockGLSharedTextureForAccess(sharedTextureHandle);
}

void Compositor_018::lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle)
{
    openvr::compositorImpl->lockGLSharedTextureForAccess(sharedTextureHandle);
}

void Compositor_019::lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle)
{
    openvr::compositorImpl->lockGLSharedTextureForAccess(sharedTextureHandle);
}

void Compositor_020::lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle)
{
    openvr::compositorImpl->lockGLSharedTextureForAccess(sharedTextureHandle);
}

void Compositor_021::lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle)
{
    openvr::compositorImpl->lockGLSharedTextureForAccess(sharedTextureHandle);
}

void Compositor_022::lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle)
{
    openvr::compositorImpl->lockGLSharedTextureForAccess(sharedTextureHandle);
}

void Compositor_024::lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle)
{
    openvr::compositorImpl->lockGLSharedTextureForAccess(sharedTextureHandle);
}

void Compositor_026::lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle)
{
    openvr::compositorImpl->lockGLSharedTextureForAccess(sharedTextureHandle);
}

void Compositor_028::lockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle)
{
    openvr::compositorImpl->lockGLSharedTextureForAccess(sharedTextureHandle);
}

void Compositor_015::unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle)
{
    openvr::compositorImpl->unlockGLSharedTextureForAccess(sharedTextureHandle);
}

void Compositor_016::unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle)
{
    openvr::compositorImpl->unlockGLSharedTextureForAccess(sharedTextureHandle);
}

void Compositor_018::unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle)
{
    openvr::compositorImpl->unlockGLSharedTextureForAccess(sharedTextureHandle);
}

void Compositor_019::unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle)
{
    openvr::compositorImpl->unlockGLSharedTextureForAccess(sharedTextureHandle);
}

void Compositor_020::unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle)
{
    openvr::compositorImpl->unlockGLSharedTextureForAccess(sharedTextureHandle);
}

void Compositor_021::unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle)
{
    openvr::compositorImpl->unlockGLSharedTextureForAccess(sharedTextureHandle);
}

void Compositor_022::unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle)
{
    openvr::compositorImpl->unlockGLSharedTextureForAccess(sharedTextureHandle);
}

void Compositor_024::unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle)
{
    openvr::compositorImpl->unlockGLSharedTextureForAccess(sharedTextureHandle);
}

void Compositor_026::unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle)
{
    openvr::compositorImpl->unlockGLSharedTextureForAccess(sharedTextureHandle);
}

void Compositor_028::unlockGLSharedTextureForAccess(GLSharedTextureHandle* sharedTextureHandle)
{
    openvr::compositorImpl->unlockGLSharedTextureForAccess(sharedTextureHandle);
}

uint32_t Compositor_019::getVulkanInstanceExtensionsRequired(char* value, uint32_t bufferSize)
{
    return openvr::compositorImpl->getVulkanInstanceExtensionsRequired(value, bufferSize);
}

uint32_t Compositor_020::getVulkanInstanceExtensionsRequired(char* value, uint32_t bufferSize)
{
    return openvr::compositorImpl->getVulkanInstanceExtensionsRequired(value, bufferSize);
}

uint32_t Compositor_021::getVulkanInstanceExtensionsRequired(char* value, uint32_t bufferSize)
{
    return openvr::compositorImpl->getVulkanInstanceExtensionsRequired(value, bufferSize);
}

uint32_t Compositor_022::getVulkanInstanceExtensionsRequired(char* value, uint32_t bufferSize)
{
    return openvr::compositorImpl->getVulkanInstanceExtensionsRequired(value, bufferSize);
}

uint32_t Compositor_024::getVulkanInstanceExtensionsRequired(char* value, uint32_t bufferSize)
{
    return openvr::compositorImpl->getVulkanInstanceExtensionsRequired(value, bufferSize);
}

uint32_t Compositor_026::getVulkanInstanceExtensionsRequired(char* value, uint32_t bufferSize)
{
    return openvr::compositorImpl->getVulkanInstanceExtensionsRequired(value, bufferSize);
}

uint32_t Compositor_028::getVulkanInstanceExtensionsRequired(char* value, uint32_t bufferSize)
{
    return openvr::compositorImpl->getVulkanInstanceExtensionsRequired(value, bufferSize);
}

uint32_t Compositor_019::getVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* device, char* value, uint32_t bufferSize)
{
    return openvr::compositorImpl->getVulkanDeviceExtensionsRequired(device, value, bufferSize);
}

uint32_t Compositor_020::getVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* device, char* value, uint32_t bufferSize)
{
    return openvr::compositorImpl->getVulkanDeviceExtensionsRequired(device, value, bufferSize);
}

uint32_t Compositor_021::getVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* device, char* value, uint32_t bufferSize)
{
    return openvr::compositorImpl->getVulkanDeviceExtensionsRequired(device, value, bufferSize);
}

uint32_t Compositor_022::getVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* device, char* value, uint32_t bufferSize)
{
    return openvr::compositorImpl->getVulkanDeviceExtensionsRequired(device, value, bufferSize);
}

uint32_t Compositor_024::getVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* device, char* value, uint32_t bufferSize)
{
    return openvr::compositorImpl->getVulkanDeviceExtensionsRequired(device, value, bufferSize);
}

uint32_t Compositor_026::getVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* device, char* value, uint32_t bufferSize)
{
    return openvr::compositorImpl->getVulkanDeviceExtensionsRequired(device, value, bufferSize);
}

uint32_t Compositor_028::getVulkanDeviceExtensionsRequired(VkPhysicalDevice_T* device, char* value, uint32_t bufferSize)
{
    return openvr::compositorImpl->getVulkanDeviceExtensionsRequired(device, value, bufferSize);
}

void Compositor_021::setExplicitTimingMode(bool explicitTimingMode)
{
    openvr::compositorImpl->setExplicitTimingMode(CompositorTimingMode::COMPOSITOR_TIMING_MODE_EXPLICIT_RUNTIME_PERFORMS_POST_PRESENT_HANDOFF);
}

void Compositor_022::setExplicitTimingMode(CompositorTimingMode timingMode)
{
    openvr::compositorImpl->setExplicitTimingMode(timingMode);
}

void Compositor_024::setExplicitTimingMode(CompositorTimingMode timingMode)
{
    openvr::compositorImpl->setExplicitTimingMode(timingMode);
}

void Compositor_026::setExplicitTimingMode(CompositorTimingMode timingMode)
{
    openvr::compositorImpl->setExplicitTimingMode(timingMode);
}

void Compositor_028::setExplicitTimingMode(CompositorTimingMode timingMode)
{
    openvr::compositorImpl->setExplicitTimingMode(timingMode);
}

CompositorError Compositor_021::submitExplicitTimingData()
{
    return openvr::compositorImpl->submitExplicitTimingData();
}

CompositorError Compositor_022::submitExplicitTimingData()
{
    return openvr::compositorImpl->submitExplicitTimingData();
}

CompositorError Compositor_024::submitExplicitTimingData()
{
    return openvr::compositorImpl->submitExplicitTimingData();
}

CompositorError Compositor_026::submitExplicitTimingData()
{
    return openvr::compositorImpl->submitExplicitTimingData();
}

CompositorError Compositor_028::submitExplicitTimingData()
{
    return openvr::compositorImpl->submitExplicitTimingData();
}

bool Compositor_022::isMotionSmoothingEnabled()
{
    TRACE();
    return false;
}

bool Compositor_024::isMotionSmoothingEnabled()
{
    TRACE();
    return false;
}

bool Compositor_026::isMotionSmoothingEnabled()
{
    TRACE();
    return false;
}

bool Compositor_028::isMotionSmoothingEnabled()
{
    TRACE();
    return false;
}

bool Compositor_022::isMotionSmoothingSupported()
{
    TRACE();
    return false;
}

bool Compositor_024::isMotionSmoothingSupported()
{
    TRACE();
    return false;
}

bool Compositor_026::isMotionSmoothingSupported()
{
    TRACE();
    return false;
}

bool Compositor_028::isMotionSmoothingSupported()
{
    TRACE();
    return false;
}

bool Compositor_022::isCurrentSceneFocusAppLoading()
{
    return openvr::compositorImpl->isCurrentSceneFocusAppLoading();
}

bool Compositor_024::isCurrentSceneFocusAppLoading()
{
    return openvr::compositorImpl->isCurrentSceneFocusAppLoading();
}

bool Compositor_026::isCurrentSceneFocusAppLoading()
{
    return openvr::compositorImpl->isCurrentSceneFocusAppLoading();
}

bool Compositor_028::isCurrentSceneFocusAppLoading()
{
    return openvr::compositorImpl->isCurrentSceneFocusAppLoading();
}

CompositorError Compositor_024::setStageOverride(const char* modelPath, const Matrix34* transform, const StageRenderSettings* renderSettings, uint32_t renderSettingsSize)
{
    return openvr::compositorImpl->setStageOverride(modelPath, transform, renderSettings, renderSettingsSize);
}

CompositorError Compositor_026::setStageOverride(const char* modelPath, const Matrix34* transform, const StageRenderSettings* renderSettings, uint32_t renderSettingsSize)
{
    return openvr::compositorImpl->setStageOverride(modelPath, transform, renderSettings, renderSettingsSize);
}

CompositorError Compositor_028::setStageOverride(const char* modelPath, const Matrix34* transform, const StageRenderSettings* renderSettings, uint32_t renderSettingsSize)
{
    return openvr::compositorImpl->setStageOverride(modelPath, transform, renderSettings, renderSettingsSize);
}

void Compositor_024::clearStageOverride()
{
    openvr::compositorImpl->clearStageOverride();
}

void Compositor_026::clearStageOverride()
{
    openvr::compositorImpl->clearStageOverride();
}

void Compositor_028::clearStageOverride()
{
    openvr::compositorImpl->clearStageOverride();
}

bool Compositor_026::getCompositorBenchmarkResults(BenchmarkResults* benchmarkResults, uint32_t benchmarkResultsSize)
{
    TRACE();
    return false;
}

bool Compositor_028::getCompositorBenchmarkResults(BenchmarkResults* benchmarkResults, uint32_t benchmarkResultsSize)
{
    TRACE();
    return false;
}

CompositorError Compositor_026::getLastPosePredictionIDs(uint32_t* renderPosePredictionId, uint32_t* gamePosePredictionId)
{
    return openvr::compositorImpl->getLastPosePredictionIDs(renderPosePredictionId, gamePosePredictionId);
}

CompositorError Compositor_028::getLastPosePredictionIDs(uint32_t* renderPosePredictionId, uint32_t* gamePosePredictionId)
{
    return openvr::compositorImpl->getLastPosePredictionIDs(renderPosePredictionId, gamePosePredictionId);
}

CompositorError Compositor_026::getPosesForFrame(uint32_t posePredictionId, TrackedDevicePose* poses, uint32_t posesCount)
{
    return openvr::compositorImpl->getPosesForFrame(posePredictionId, poses, posesCount);
}

CompositorError Compositor_028::getPosesForFrame(uint32_t posePredictionId, TrackedDevicePose* poses, uint32_t posesCount)
{
    return openvr::compositorImpl->getPosesForFrame(posePredictionId, poses, posesCount);
}
