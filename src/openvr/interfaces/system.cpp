#include "system.h"
#include "../impl/init.h"
#include "log/log.h"
#include "log/stub.h"

#include <cstring>

using namespace openvr;

void System_003::getWindowBounds(int32_t* x, int32_t* y, uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
    *x = *y = 0;
    *width *= 2;
}

void System_004::getWindowBounds(int32_t* x, int32_t* y, uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
    *x = *y = 0;
    *width *= 2;
}

void System_005::getWindowBounds(int32_t* x, int32_t* y, uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
    *x = *y = 0;
    *width *= 2;
}

void System_006::getWindowBounds(int32_t* x, int32_t* y, uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
    *x = *y = 0;
    *width *= 2;
}

void System_007::getWindowBounds(int32_t* x, int32_t* y, uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
    *x = *y = 0;
    *width *= 2;
}

void System_003::getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
}

void System_004::getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
}

void System_005::getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
}

void System_006::getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
}

void System_007::getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
}

void System_009::getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
}

void System_010::getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
}

void System_011::getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
}

void System_012::getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
}

void System_014::getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
}

void System_015::getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
}

void System_016::getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
}

void System_017::getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
}

void System_019::getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
}

void System_020::getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
}

void System_021::getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
}

void System_022::getRecommendedRenderTargetSize(uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
}

void System_003::getEyeOutputViewport(Eye eye, uint32_t* x, uint32_t* y, uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
    *x += eye == Eye::EYE_RIGHT ? *width : 0;
    *y = 0;
}

void System_004::getEyeOutputViewport(Eye eye, uint32_t* x, uint32_t* y, uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
    *x += eye == Eye::EYE_RIGHT ? *width : 0;
    *y = 0;
}

void System_005::getEyeOutputViewport(Eye eye, uint32_t* x, uint32_t* y, uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
    *x += eye == Eye::EYE_RIGHT ? *width : 0;
    *y = 0;
}

void System_006::getEyeOutputViewport(Eye eye, uint32_t* x, uint32_t* y, uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
    *x += eye == Eye::EYE_RIGHT ? *width : 0;
    *y = 0;
}

void System_007::getEyeOutputViewport(Eye eye, uint32_t* x, uint32_t* y, uint32_t* width, uint32_t* height)
{
    openvr::systemImpl->getRecommendedRenderTargetSize(width, height);
    *x += eye == Eye::EYE_RIGHT ? *width : 0;
    *y = 0;
}

Matrix44 System_003::getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention)
{
    // TODO: matrix convention
    return openvr::systemImpl->getProjectionMatrix(eye, near, far);
}

Matrix44 System_004::getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention)
{
    // TODO: matrix convention
    return openvr::systemImpl->getProjectionMatrix(eye, near, far);
}

Matrix44 System_005::getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention)
{
    // TODO: matrix convention
    return openvr::systemImpl->getProjectionMatrix(eye, near, far);
}

Matrix44 System_006::getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention)
{
    // TODO: matrix convention
    return openvr::systemImpl->getProjectionMatrix(eye, near, far);
}

Matrix44 System_007::getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention)
{
    // TODO: matrix convention
    return openvr::systemImpl->getProjectionMatrix(eye, near, far);
}

Matrix44 System_009::getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention)
{
    // TODO: matrix convention
    return openvr::systemImpl->getProjectionMatrix(eye, near, far);
}

Matrix44 System_010::getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention)
{
    // TODO: matrix convention
    return openvr::systemImpl->getProjectionMatrix(eye, near, far);
}

Matrix44 System_011::getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention)
{
    // TODO: matrix convention
    return openvr::systemImpl->getProjectionMatrix(eye, near, far);
}

Matrix44 System_012::getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention)
{
    // TODO: matrix convention
    return openvr::systemImpl->getProjectionMatrix(eye, near, far);
}

Matrix44 System_014::getProjectionMatrix(Eye eye, float near, float far, MatrixConvention convention)
{
    // TODO: matrix convention
    return openvr::systemImpl->getProjectionMatrix(eye, near, far);
}

Matrix44 System_015::getProjectionMatrix(Eye eye, float near, float far)
{
    return openvr::systemImpl->getProjectionMatrix(eye, near, far);
}

Matrix44 System_016::getProjectionMatrix(Eye eye, float near, float far)
{
    return openvr::systemImpl->getProjectionMatrix(eye, near, far);
}

Matrix44 System_017::getProjectionMatrix(Eye eye, float near, float far)
{
    return openvr::systemImpl->getProjectionMatrix(eye, near, far);
}

Matrix44 System_019::getProjectionMatrix(Eye eye, float near, float far)
{
    return openvr::systemImpl->getProjectionMatrix(eye, near, far);
}

Matrix44 System_020::getProjectionMatrix(Eye eye, float near, float far)
{
    return openvr::systemImpl->getProjectionMatrix(eye, near, far);
}

Matrix44 System_021::getProjectionMatrix(Eye eye, float near, float far)
{
    return openvr::systemImpl->getProjectionMatrix(eye, near, far);
}

Matrix44 System_022::getProjectionMatrix(Eye eye, float near, float far)
{
    return openvr::systemImpl->getProjectionMatrix(eye, near, far);
}

void System_003::getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom)
{
    openvr::systemImpl->getProjectionRaw(eye, left, right, top, bottom);
}

void System_004::getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom)
{
    openvr::systemImpl->getProjectionRaw(eye, left, right, top, bottom);
}

void System_005::getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom)
{
    openvr::systemImpl->getProjectionRaw(eye, left, right, top, bottom);
}

void System_006::getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom)
{
    openvr::systemImpl->getProjectionRaw(eye, left, right, top, bottom);
}

void System_007::getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom)
{
    openvr::systemImpl->getProjectionRaw(eye, left, right, top, bottom);
}

void System_009::getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom)
{
    openvr::systemImpl->getProjectionRaw(eye, left, right, top, bottom);
}

void System_010::getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom)
{
    openvr::systemImpl->getProjectionRaw(eye, left, right, top, bottom);
}

void System_011::getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom)
{
    openvr::systemImpl->getProjectionRaw(eye, left, right, top, bottom);
}

void System_012::getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom)
{
    openvr::systemImpl->getProjectionRaw(eye, left, right, top, bottom);
}

void System_014::getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom)
{
    openvr::systemImpl->getProjectionRaw(eye, left, right, top, bottom);
}

void System_015::getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom)
{
    openvr::systemImpl->getProjectionRaw(eye, left, right, top, bottom);
}

void System_016::getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom)
{
    openvr::systemImpl->getProjectionRaw(eye, left, right, top, bottom);
}

void System_017::getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom)
{
    openvr::systemImpl->getProjectionRaw(eye, left, right, top, bottom);
}

void System_019::getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom)
{
    openvr::systemImpl->getProjectionRaw(eye, left, right, top, bottom);
}

void System_020::getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom)
{
    openvr::systemImpl->getProjectionRaw(eye, left, right, top, bottom);
}

void System_021::getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom)
{
    openvr::systemImpl->getProjectionRaw(eye, left, right, top, bottom);
}

void System_022::getProjectionRaw(Eye eye, float* left, float* right, float* top, float* bottom)
{
    openvr::systemImpl->getProjectionRaw(eye, left, right, top, bottom);
}

DistortionCoordinates System_003::computeDistortion(Eye eye, float u, float v)
{
    DistortionCoordinates distortionCoordinates;
    openvr::systemImpl->computeDistortion(eye, u, v, &distortionCoordinates);
    return distortionCoordinates;
}

DistortionCoordinates System_004::computeDistortion(Eye eye, float u, float v)
{
    DistortionCoordinates distortionCoordinates;
    openvr::systemImpl->computeDistortion(eye, u, v, &distortionCoordinates);
    return distortionCoordinates;
}

DistortionCoordinates System_005::computeDistortion(Eye eye, float u, float v)
{
    DistortionCoordinates distortionCoordinates;
    openvr::systemImpl->computeDistortion(eye, u, v, &distortionCoordinates);
    return distortionCoordinates;
}

DistortionCoordinates System_006::computeDistortion(Eye eye, float u, float v)
{
    DistortionCoordinates distortionCoordinates;
    openvr::systemImpl->computeDistortion(eye, u, v, &distortionCoordinates);
    return distortionCoordinates;
}

DistortionCoordinates System_007::computeDistortion(Eye eye, float u, float v)
{
    DistortionCoordinates distortionCoordinates;
    openvr::systemImpl->computeDistortion(eye, u, v, &distortionCoordinates);
    return distortionCoordinates;
}

DistortionCoordinates System_009::computeDistortion(Eye eye, float u, float v)
{
    DistortionCoordinates distortionCoordinates;
    openvr::systemImpl->computeDistortion(eye, u, v, &distortionCoordinates);
    return distortionCoordinates;
}

DistortionCoordinates System_010::computeDistortion(Eye eye, float u, float v)
{
    DistortionCoordinates distortionCoordinates;
    openvr::systemImpl->computeDistortion(eye, u, v, &distortionCoordinates);
    return distortionCoordinates;
}

DistortionCoordinates System_011::computeDistortion(Eye eye, float u, float v)
{
    DistortionCoordinates distortionCoordinates;
    openvr::systemImpl->computeDistortion(eye, u, v, &distortionCoordinates);
    return distortionCoordinates;
}

DistortionCoordinates System_012::computeDistortion(Eye eye, float u, float v)
{
    DistortionCoordinates distortionCoordinates;
    openvr::systemImpl->computeDistortion(eye, u, v, &distortionCoordinates);
    return distortionCoordinates;
}

bool System_014::computeDistortion(Eye eye, float u, float v, DistortionCoordinates* distortionCoordinates)
{
    return openvr::systemImpl->computeDistortion(eye, u, v, distortionCoordinates);
}

bool System_015::computeDistortion(Eye eye, float u, float v, DistortionCoordinates* distortionCoordinates)
{
    return openvr::systemImpl->computeDistortion(eye, u, v, distortionCoordinates);
}

bool System_016::computeDistortion(Eye eye, float u, float v, DistortionCoordinates* distortionCoordinates)
{
    return openvr::systemImpl->computeDistortion(eye, u, v, distortionCoordinates);
}

bool System_017::computeDistortion(Eye eye, float u, float v, DistortionCoordinates* distortionCoordinates)
{
    return openvr::systemImpl->computeDistortion(eye, u, v, distortionCoordinates);
}

bool System_019::computeDistortion(Eye eye, float u, float v, DistortionCoordinates* distortionCoordinates)
{
    return openvr::systemImpl->computeDistortion(eye, u, v, distortionCoordinates);
}

bool System_020::computeDistortion(Eye eye, float u, float v, DistortionCoordinates* distortionCoordinates)
{
    return openvr::systemImpl->computeDistortion(eye, u, v, distortionCoordinates);
}

bool System_021::computeDistortion(Eye eye, float u, float v, DistortionCoordinates* distortionCoordinates)
{
    return openvr::systemImpl->computeDistortion(eye, u, v, distortionCoordinates);
}

bool System_022::computeDistortion(Eye eye, float u, float v, DistortionCoordinates* distortionCoordinates)
{
    return openvr::systemImpl->computeDistortion(eye, u, v, distortionCoordinates);
}

Matrix34 System_003::getEyeToHeadTransform(Eye eye)
{
    return openvr::systemImpl->getEyeToHeadTransform(eye);
}

Matrix34 System_004::getEyeToHeadTransform(Eye eye)
{
    return openvr::systemImpl->getEyeToHeadTransform(eye);
}

Matrix34 System_005::getEyeToHeadTransform(Eye eye)
{
    return openvr::systemImpl->getEyeToHeadTransform(eye);
}

Matrix34 System_006::getEyeToHeadTransform(Eye eye)
{
    return openvr::systemImpl->getEyeToHeadTransform(eye);
}

Matrix34 System_007::getEyeToHeadTransform(Eye eye)
{
    return openvr::systemImpl->getEyeToHeadTransform(eye);
}

Matrix34 System_009::getEyeToHeadTransform(Eye eye)
{
    return openvr::systemImpl->getEyeToHeadTransform(eye);
}

Matrix34 System_010::getEyeToHeadTransform(Eye eye)
{
    return openvr::systemImpl->getEyeToHeadTransform(eye);
}

Matrix34 System_011::getEyeToHeadTransform(Eye eye)
{
    return openvr::systemImpl->getEyeToHeadTransform(eye);
}

Matrix34 System_012::getEyeToHeadTransform(Eye eye)
{
    return openvr::systemImpl->getEyeToHeadTransform(eye);
}

Matrix34 System_014::getEyeToHeadTransform(Eye eye)
{
    return openvr::systemImpl->getEyeToHeadTransform(eye);
}

Matrix34 System_015::getEyeToHeadTransform(Eye eye)
{
    return openvr::systemImpl->getEyeToHeadTransform(eye);
}

Matrix34 System_016::getEyeToHeadTransform(Eye eye)
{
    return openvr::systemImpl->getEyeToHeadTransform(eye);
}

Matrix34 System_017::getEyeToHeadTransform(Eye eye)
{
    return openvr::systemImpl->getEyeToHeadTransform(eye);
}

Matrix34 System_019::getEyeToHeadTransform(Eye eye)
{
    return openvr::systemImpl->getEyeToHeadTransform(eye);
}

Matrix34 System_020::getEyeToHeadTransform(Eye eye)
{
    return openvr::systemImpl->getEyeToHeadTransform(eye);
}

Matrix34 System_021::getEyeToHeadTransform(Eye eye)
{
    return openvr::systemImpl->getEyeToHeadTransform(eye);
}

Matrix34 System_022::getEyeToHeadTransform(Eye eye)
{
    return openvr::systemImpl->getEyeToHeadTransform(eye);
}

bool System_003::getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter)
{
    return openvr::systemImpl->getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter);
}

bool System_004::getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter)
{
    return openvr::systemImpl->getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter);
}

bool System_005::getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter)
{
    return openvr::systemImpl->getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter);
}

bool System_006::getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter)
{
    return openvr::systemImpl->getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter);
}

bool System_007::getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter)
{
    return openvr::systemImpl->getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter);
}

bool System_009::getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter)
{
    return openvr::systemImpl->getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter);
}

bool System_010::getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter)
{
    return openvr::systemImpl->getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter);
}

bool System_011::getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter)
{
    return openvr::systemImpl->getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter);
}

bool System_012::getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter)
{
    return openvr::systemImpl->getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter);
}

bool System_014::getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter)
{
    return openvr::systemImpl->getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter);
}

bool System_015::getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter)
{
    return openvr::systemImpl->getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter);
}

bool System_016::getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter)
{
    return openvr::systemImpl->getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter);
}

bool System_017::getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter)
{
    return openvr::systemImpl->getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter);
}

bool System_019::getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter)
{
    return openvr::systemImpl->getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter);
}

bool System_020::getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter)
{
    return openvr::systemImpl->getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter);
}

bool System_021::getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter)
{
    return openvr::systemImpl->getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter);
}

bool System_022::getTimeSinceLastVsync(float* secondsSinceLastVsync, uint64_t* frameCounter)
{
    return openvr::systemImpl->getTimeSinceLastVsync(secondsSinceLastVsync, frameCounter);
}

int32_t System_003::getD3D9AdapterIndex()
{
    STUB();
    return -1;
}

int32_t System_004::getD3D9AdapterIndex()
{
    STUB();
    return -1;
}

int32_t System_005::getD3D9AdapterIndex()
{
    STUB();
    return -1;
}

int32_t System_006::getD3D9AdapterIndex()
{
    STUB();
    return -1;
}

int32_t System_007::getD3D9AdapterIndex()
{
    STUB();
    return -1;
}

int32_t System_009::getD3D9AdapterIndex()
{
    STUB();
    return -1;
}

int32_t System_010::getD3D9AdapterIndex()
{
    STUB();
    return -1;
}

int32_t System_011::getD3D9AdapterIndex()
{
    STUB();
    return -1;
}

int32_t System_012::getD3D9AdapterIndex()
{
    STUB();
    return -1;
}

int32_t System_014::getD3D9AdapterIndex()
{
    STUB();
    return -1;
}

int32_t System_015::getD3D9AdapterIndex()
{
    STUB();
    return -1;
}

int32_t System_016::getD3D9AdapterIndex()
{
    STUB();
    return -1;
}

int32_t System_017::getD3D9AdapterIndex()
{
    STUB();
    return -1;
}

int32_t System_019::getD3D9AdapterIndex()
{
    STUB();
    return -1;
}

int32_t System_020::getD3D9AdapterIndex()
{
    STUB();
    return -1;
}

int32_t System_021::getD3D9AdapterIndex()
{
    STUB();
    return -1;
}

int32_t System_022::getD3D9AdapterIndex()
{
    STUB();
    return -1;
}

void System_003::getDXGIOutputInfo(int32_t* adapterIndex, int32_t* outputIndex)
{
    STUB();
    *adapterIndex = *outputIndex = -1;
}

void System_004::getDXGIOutputInfo(int32_t* adapterIndex, int32_t* outputIndex)
{
    STUB();
    *adapterIndex = *outputIndex = -1;
}

void System_005::getDXGIOutputInfo(int32_t* adapterIndex, int32_t* outputIndex)
{
    STUB();
    *adapterIndex = *outputIndex = -1;
}

void System_006::getDXGIOutputInfo(int32_t* adapterIndex, int32_t* outputIndex)
{
    STUB();
    *adapterIndex = *outputIndex = -1;
}

void System_007::getDXGIOutputInfo(int32_t* adapterIndex, int32_t* outputIndex)
{
    STUB();
    *adapterIndex = *outputIndex = -1;
}

void System_009::getDXGIOutputInfo(int32_t* adapterIndex)
{
    STUB();
    *adapterIndex = -1;
}

void System_010::getDXGIOutputInfo(int32_t* adapterIndex)
{
    STUB();
    *adapterIndex = -1;
}

void System_011::getDXGIOutputInfo(int32_t* adapterIndex)
{
    STUB();
    *adapterIndex = -1;
}

void System_012::getDXGIOutputInfo(int32_t* adapterIndex)
{
    STUB();
    *adapterIndex = -1;
}

void System_014::getDXGIOutputInfo(int32_t* adapterIndex)
{
    STUB();
    *adapterIndex = -1;
}

void System_015::getDXGIOutputInfo(int32_t* adapterIndex)
{
    STUB();
    *adapterIndex = -1;
}

void System_016::getDXGIOutputInfo(int32_t* adapterIndex)
{
    STUB();
    *adapterIndex = -1;
}

void System_017::getDXGIOutputInfo(int32_t* adapterIndex)
{
    STUB();
    *adapterIndex = -1;
}

void System_019::getDXGIOutputInfo(int32_t* adapterIndex)
{
    STUB();
    *adapterIndex = -1;
}

void System_020::getDXGIOutputInfo(int32_t* adapterIndex)
{
    STUB();
    *adapterIndex = -1;
}

void System_021::getDXGIOutputInfo(int32_t* adapterIndex)
{
    STUB();
    *adapterIndex = -1;
}

void System_022::getDXGIOutputInfo(int32_t* adapterIndex)
{
    STUB();
    *adapterIndex = -1;
}

void System_016::getOutputDevice(uint64_t* device, TextureType textureType)
{
    openvr::systemImpl->getOutputDevice(device, textureType, nullptr);
}

void System_017::getOutputDevice(uint64_t* device, TextureType textureType, VkInstance_T* vkInstance)
{
    openvr::systemImpl->getOutputDevice(device, textureType, vkInstance);
}

void System_019::getOutputDevice(uint64_t* device, TextureType textureType, VkInstance_T* vkInstance)
{
    openvr::systemImpl->getOutputDevice(device, textureType, vkInstance);
}

void System_020::getOutputDevice(uint64_t* device, TextureType textureType, VkInstance_T* vkInstance)
{
    openvr::systemImpl->getOutputDevice(device, textureType, vkInstance);
}

void System_021::getOutputDevice(uint64_t* device, TextureType textureType, VkInstance_T* vkInstance)
{
    openvr::systemImpl->getOutputDevice(device, textureType, vkInstance);
}

void System_022::getOutputDevice(uint64_t* device, TextureType textureType, VkInstance_T* vkInstance)
{
    openvr::systemImpl->getOutputDevice(device, textureType, vkInstance);
}

bool System_003::AttachToWindow(void* hwnd)
{
    STUB();
    return false;
}

bool System_004::AttachToWindow(void* hwnd)
{
    STUB();
    return false;
}

bool System_005::AttachToWindow(void* hwnd)
{
    STUB();
    return false;
}

bool System_006::AttachToWindow(void* hwnd)
{
    STUB();
    return false;
}

bool System_007::AttachToWindow(void* hwnd)
{
    STUB();
    return false;
}

bool System_006::isDisplayOnDesktop()
{
    return false;
}

bool System_007::isDisplayOnDesktop()
{
    return false;
}

bool System_009::isDisplayOnDesktop()
{
    return false;
}

bool System_010::isDisplayOnDesktop()
{
    return false;
}

bool System_011::isDisplayOnDesktop()
{
    return false;
}

bool System_012::isDisplayOnDesktop()
{
    return false;
}

bool System_014::isDisplayOnDesktop()
{
    return false;
}

bool System_015::isDisplayOnDesktop()
{
    return false;
}

bool System_016::isDisplayOnDesktop()
{
    return false;
}

bool System_017::isDisplayOnDesktop()
{
    return false;
}

bool System_019::isDisplayOnDesktop()
{
    return false;
}

bool System_020::isDisplayOnDesktop()
{
    return false;
}

bool System_021::isDisplayOnDesktop()
{
    return false;
}

bool System_022::isDisplayOnDesktop()
{
    return false;
}

bool System_006::setDisplayVisibility(bool visibleOnDesktop)
{
    return false;
}

bool System_007::setDisplayVisibility(bool visibleOnDesktop)
{
    return false;
}

bool System_009::setDisplayVisibility(bool visibleOnDesktop)
{
    return false;
}

bool System_010::setDisplayVisibility(bool visibleOnDesktop)
{
    return false;
}

bool System_011::setDisplayVisibility(bool visibleOnDesktop)
{
    return false;
}

bool System_012::setDisplayVisibility(bool visibleOnDesktop)
{
    return false;
}

bool System_014::setDisplayVisibility(bool visibleOnDesktop)
{
    return false;
}

bool System_015::setDisplayVisibility(bool visibleOnDesktop)
{
    return false;
}

bool System_016::setDisplayVisibility(bool visibleOnDesktop)
{
    return false;
}

bool System_017::setDisplayVisibility(bool visibleOnDesktop)
{
    return false;
}

bool System_019::setDisplayVisibility(bool visibleOnDesktop)
{
    return false;
}

bool System_020::setDisplayVisibility(bool visibleOnDesktop)
{
    return false;
}

bool System_021::setDisplayVisibility(bool visibleOnDesktop)
{
    return false;
}

bool System_022::setDisplayVisibility(bool visibleOnDesktop)
{
    return false;
}

void System_003::getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount)
{
    openvr::systemImpl->getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount);
}

void System_004::getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount)
{
    openvr::systemImpl->getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount);
}

void System_005::getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount)
{
    openvr::systemImpl->getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount);
}

void System_006::getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount)
{
    openvr::systemImpl->getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount);
}

void System_007::getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount)
{
    openvr::systemImpl->getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount);
}

void System_009::getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount)
{
    openvr::systemImpl->getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount);
}

void System_010::getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount)
{
    openvr::systemImpl->getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount);
}

void System_011::getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount)
{
    openvr::systemImpl->getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount);
}

void System_012::getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount)
{
    openvr::systemImpl->getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount);
}

void System_014::getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount)
{
    openvr::systemImpl->getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount);
}

void System_015::getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount)
{
    openvr::systemImpl->getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount);
}

void System_016::getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount)
{
    openvr::systemImpl->getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount);
}

void System_017::getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount)
{
    openvr::systemImpl->getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount);
}

void System_019::getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount)
{
    openvr::systemImpl->getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount);
}

void System_020::getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount)
{
    openvr::systemImpl->getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount);
}

void System_021::getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount)
{
    openvr::systemImpl->getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount);
}

void System_022::getDeviceToAbsoluteTrackingPose(TrackingUniverseOrigin origin, float predictedSecondsToPhotonsFromNow, TrackedDevicePose* trackedDevicePoses, uint32_t trackedDevicePosesCount)
{
    openvr::systemImpl->getDeviceToAbsoluteTrackingPose(origin, predictedSecondsToPhotonsFromNow, trackedDevicePoses, trackedDevicePosesCount);
}

void System_003::resetSeatedZeroPose()
{
    openvr::systemImpl->resetSeatedZeroPose();
}

void System_004::resetSeatedZeroPose()
{
    openvr::systemImpl->resetSeatedZeroPose();
}

void System_005::resetSeatedZeroPose()
{
    openvr::systemImpl->resetSeatedZeroPose();
}

void System_006::resetSeatedZeroPose()
{
    openvr::systemImpl->resetSeatedZeroPose();
}

void System_007::resetSeatedZeroPose()
{
    openvr::systemImpl->resetSeatedZeroPose();
}

void System_009::resetSeatedZeroPose()
{
    openvr::systemImpl->resetSeatedZeroPose();
}

void System_010::resetSeatedZeroPose()
{
    openvr::systemImpl->resetSeatedZeroPose();
}

void System_011::resetSeatedZeroPose()
{
    openvr::systemImpl->resetSeatedZeroPose();
}

void System_012::resetSeatedZeroPose()
{
    openvr::systemImpl->resetSeatedZeroPose();
}

void System_014::resetSeatedZeroPose()
{
    openvr::systemImpl->resetSeatedZeroPose();
}

void System_015::resetSeatedZeroPose()
{
    openvr::systemImpl->resetSeatedZeroPose();
}

void System_016::resetSeatedZeroPose()
{
    openvr::systemImpl->resetSeatedZeroPose();
}

void System_017::resetSeatedZeroPose()
{
    openvr::systemImpl->resetSeatedZeroPose();
}

void System_019::resetSeatedZeroPose()
{
    openvr::systemImpl->resetSeatedZeroPose();
}

void System_020::resetSeatedZeroPose()
{
    openvr::systemImpl->resetSeatedZeroPose();
}

void System_021::resetSeatedZeroPose()
{
    openvr::systemImpl->resetSeatedZeroPose();
}

Matrix34 System_003::getSeatedZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getSeatedZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_004::getSeatedZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getSeatedZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_005::getSeatedZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getSeatedZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_006::getSeatedZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getSeatedZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_007::getSeatedZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getSeatedZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_009::getSeatedZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getSeatedZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_010::getSeatedZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getSeatedZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_011::getSeatedZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getSeatedZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_012::getSeatedZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getSeatedZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_014::getSeatedZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getSeatedZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_015::getSeatedZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getSeatedZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_016::getSeatedZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getSeatedZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_017::getSeatedZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getSeatedZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_019::getSeatedZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getSeatedZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_020::getSeatedZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getSeatedZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_021::getSeatedZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getSeatedZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_022::getSeatedZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getSeatedZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_006::getRawZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getRawZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_007::getRawZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getRawZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_009::getRawZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getRawZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_010::getRawZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getRawZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_011::getRawZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getRawZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_012::getRawZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getRawZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_014::getRawZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getRawZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_015::getRawZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getRawZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_016::getRawZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getRawZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_017::getRawZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getRawZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_019::getRawZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getRawZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_020::getRawZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getRawZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_021::getRawZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getRawZeroPoseToStandingAbsoluteTrackingPose();
}

Matrix34 System_022::getRawZeroPoseToStandingAbsoluteTrackingPose()
{
    return openvr::systemImpl->getRawZeroPoseToStandingAbsoluteTrackingPose();
}

bool System_003::loadRenderModel(const char* modelName, RenderModel_0_9_0* renderModel)
{
    // TODO: needs render model implementation
    STUB();
    return false;
}

void System_003::freeRenderModel(RenderModel_0_9_0* renderModel)
{
    // TODO: needs render model implementation
    STUB();
}

uint32_t System_005::getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex)
{
    return openvr::systemImpl->getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex);
}

uint32_t System_006::getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex)
{
    return openvr::systemImpl->getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex);
}

uint32_t System_007::getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex)
{
    return openvr::systemImpl->getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex);
}

uint32_t System_009::getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex)
{
    return openvr::systemImpl->getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex);
}

uint32_t System_010::getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex)
{
    return openvr::systemImpl->getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex);
}

uint32_t System_011::getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex)
{
    return openvr::systemImpl->getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex);
}

uint32_t System_012::getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex)
{
    return openvr::systemImpl->getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex);
}

uint32_t System_014::getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex)
{
    return openvr::systemImpl->getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex);
}

uint32_t System_015::getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex)
{
    return openvr::systemImpl->getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex);
}

uint32_t System_016::getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex)
{
    return openvr::systemImpl->getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex);
}

uint32_t System_017::getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex)
{
    return openvr::systemImpl->getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex);
}

uint32_t System_019::getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex)
{
    return openvr::systemImpl->getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex);
}

uint32_t System_020::getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex)
{
    return openvr::systemImpl->getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex);
}

uint32_t System_021::getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex)
{
    return openvr::systemImpl->getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex);
}

uint32_t System_022::getSortedTrackedDeviceIndicesOfClass(TrackedDeviceClass trackedDeviceClass, uint32_t* indexes, uint32_t indexesCount, uint32_t relativeToIndex)
{
    return openvr::systemImpl->getSortedTrackedDeviceIndicesOfClass(trackedDeviceClass, indexes, indexesCount, relativeToIndex);
}

DeviceActivityLevel System_006::getTrackedDeviceActivityLevel(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceActivityLevel(index);
}

DeviceActivityLevel System_007::getTrackedDeviceActivityLevel(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceActivityLevel(index);
}

DeviceActivityLevel System_009::getTrackedDeviceActivityLevel(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceActivityLevel(index);
}

DeviceActivityLevel System_010::getTrackedDeviceActivityLevel(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceActivityLevel(index);
}

DeviceActivityLevel System_011::getTrackedDeviceActivityLevel(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceActivityLevel(index);
}

DeviceActivityLevel System_012::getTrackedDeviceActivityLevel(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceActivityLevel(index);
}

DeviceActivityLevel System_014::getTrackedDeviceActivityLevel(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceActivityLevel(index);
}

DeviceActivityLevel System_015::getTrackedDeviceActivityLevel(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceActivityLevel(index);
}

DeviceActivityLevel System_016::getTrackedDeviceActivityLevel(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceActivityLevel(index);
}

DeviceActivityLevel System_017::getTrackedDeviceActivityLevel(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceActivityLevel(index);
}

DeviceActivityLevel System_019::getTrackedDeviceActivityLevel(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceActivityLevel(index);
}

DeviceActivityLevel System_020::getTrackedDeviceActivityLevel(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceActivityLevel(index);
}

DeviceActivityLevel System_021::getTrackedDeviceActivityLevel(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceActivityLevel(index);
}

DeviceActivityLevel System_022::getTrackedDeviceActivityLevel(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceActivityLevel(index);
}

void System_007::applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose& trackedDevicePose, const Matrix34& transform)
{
    openvr::systemImpl->applyTransform(outputPose, &trackedDevicePose, &transform);
}

void System_009::applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform)
{
    openvr::systemImpl->applyTransform(outputPose, trackedDevicePose, transform);
}

void System_010::applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform)
{
    openvr::systemImpl->applyTransform(outputPose, trackedDevicePose, transform);
}

void System_011::applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform)
{
    openvr::systemImpl->applyTransform(outputPose, trackedDevicePose, transform);
}

void System_012::applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform)
{
    openvr::systemImpl->applyTransform(outputPose, trackedDevicePose, transform);
}

void System_014::applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform)
{
    openvr::systemImpl->applyTransform(outputPose, trackedDevicePose, transform);
}

void System_015::applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform)
{
    openvr::systemImpl->applyTransform(outputPose, trackedDevicePose, transform);
}

void System_016::applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform)
{
    openvr::systemImpl->applyTransform(outputPose, trackedDevicePose, transform);
}

void System_017::applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform)
{
    openvr::systemImpl->applyTransform(outputPose, trackedDevicePose, transform);
}

void System_019::applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform)
{
    openvr::systemImpl->applyTransform(outputPose, trackedDevicePose, transform);
}

void System_020::applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform)
{
    openvr::systemImpl->applyTransform(outputPose, trackedDevicePose, transform);
}

void System_021::applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform)
{
    openvr::systemImpl->applyTransform(outputPose, trackedDevicePose, transform);
}

void System_022::applyTransform(TrackedDevicePose* outputPose, const TrackedDevicePose* trackedDevicePose, const Matrix34* transform)
{
    openvr::systemImpl->applyTransform(outputPose, trackedDevicePose, transform);
}

uint32_t System_010::getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole)
{
    return openvr::systemImpl->getTrackedDeviceIndexForControllerRole(controllerRole);
}

uint32_t System_011::getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole)
{
    return openvr::systemImpl->getTrackedDeviceIndexForControllerRole(controllerRole);
}

uint32_t System_012::getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole)
{
    return openvr::systemImpl->getTrackedDeviceIndexForControllerRole(controllerRole);
}

uint32_t System_014::getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole)
{
    return openvr::systemImpl->getTrackedDeviceIndexForControllerRole(controllerRole);
}

uint32_t System_015::getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole)
{
    return openvr::systemImpl->getTrackedDeviceIndexForControllerRole(controllerRole);
}

uint32_t System_016::getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole)
{
    return openvr::systemImpl->getTrackedDeviceIndexForControllerRole(controllerRole);
}

uint32_t System_017::getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole)
{
    return openvr::systemImpl->getTrackedDeviceIndexForControllerRole(controllerRole);
}

uint32_t System_019::getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole)
{
    return openvr::systemImpl->getTrackedDeviceIndexForControllerRole(controllerRole);
}

uint32_t System_020::getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole)
{
    return openvr::systemImpl->getTrackedDeviceIndexForControllerRole(controllerRole);
}

uint32_t System_021::getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole)
{
    return openvr::systemImpl->getTrackedDeviceIndexForControllerRole(controllerRole);
}

uint32_t System_022::getTrackedDeviceIndexForControllerRole(TrackedControllerRole controllerRole)
{
    return openvr::systemImpl->getTrackedDeviceIndexForControllerRole(controllerRole);
}

TrackedControllerRole System_010::getControllerRoleForTrackedDeviceIndex(uint32_t index)
{
    return openvr::systemImpl->getControllerRoleForTrackedDeviceIndex(index);
}

TrackedControllerRole System_011::getControllerRoleForTrackedDeviceIndex(uint32_t index)
{
    return openvr::systemImpl->getControllerRoleForTrackedDeviceIndex(index);
}

TrackedControllerRole System_012::getControllerRoleForTrackedDeviceIndex(uint32_t index)
{
    return openvr::systemImpl->getControllerRoleForTrackedDeviceIndex(index);
}

TrackedControllerRole System_014::getControllerRoleForTrackedDeviceIndex(uint32_t index)
{
    return openvr::systemImpl->getControllerRoleForTrackedDeviceIndex(index);
}

TrackedControllerRole System_015::getControllerRoleForTrackedDeviceIndex(uint32_t index)
{
    return openvr::systemImpl->getControllerRoleForTrackedDeviceIndex(index);
}

TrackedControllerRole System_016::getControllerRoleForTrackedDeviceIndex(uint32_t index)
{
    return openvr::systemImpl->getControllerRoleForTrackedDeviceIndex(index);
}

TrackedControllerRole System_017::getControllerRoleForTrackedDeviceIndex(uint32_t index)
{
    return openvr::systemImpl->getControllerRoleForTrackedDeviceIndex(index);
}

TrackedControllerRole System_019::getControllerRoleForTrackedDeviceIndex(uint32_t index)
{
    return openvr::systemImpl->getControllerRoleForTrackedDeviceIndex(index);
}

TrackedControllerRole System_020::getControllerRoleForTrackedDeviceIndex(uint32_t index)
{
    return openvr::systemImpl->getControllerRoleForTrackedDeviceIndex(index);
}

TrackedControllerRole System_021::getControllerRoleForTrackedDeviceIndex(uint32_t index)
{
    return openvr::systemImpl->getControllerRoleForTrackedDeviceIndex(index);
}

TrackedControllerRole System_022::getControllerRoleForTrackedDeviceIndex(uint32_t index)
{
    return openvr::systemImpl->getControllerRoleForTrackedDeviceIndex(index);
}

TrackedDeviceClass System_003::getTrackedDeviceClass(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceClass(index);
}

TrackedDeviceClass System_004::getTrackedDeviceClass(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceClass(index);
}

TrackedDeviceClass System_005::getTrackedDeviceClass(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceClass(index);
}

TrackedDeviceClass System_006::getTrackedDeviceClass(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceClass(index);
}

TrackedDeviceClass System_007::getTrackedDeviceClass(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceClass(index);
}

TrackedDeviceClass System_009::getTrackedDeviceClass(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceClass(index);
}

TrackedDeviceClass System_010::getTrackedDeviceClass(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceClass(index);
}

TrackedDeviceClass System_011::getTrackedDeviceClass(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceClass(index);
}

TrackedDeviceClass System_012::getTrackedDeviceClass(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceClass(index);
}

TrackedDeviceClass System_014::getTrackedDeviceClass(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceClass(index);
}

TrackedDeviceClass System_015::getTrackedDeviceClass(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceClass(index);
}

TrackedDeviceClass System_016::getTrackedDeviceClass(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceClass(index);
}

TrackedDeviceClass System_017::getTrackedDeviceClass(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceClass(index);
}

TrackedDeviceClass System_019::getTrackedDeviceClass(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceClass(index);
}

TrackedDeviceClass System_020::getTrackedDeviceClass(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceClass(index);
}

TrackedDeviceClass System_021::getTrackedDeviceClass(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceClass(index);
}

TrackedDeviceClass System_022::getTrackedDeviceClass(uint32_t index)
{
    return openvr::systemImpl->getTrackedDeviceClass(index);
}

bool System_003::isTrackedDeviceConnected(uint32_t index)
{
    return openvr::systemImpl->isTrackedDeviceConnected(index);
}

bool System_004::isTrackedDeviceConnected(uint32_t index)
{
    return openvr::systemImpl->isTrackedDeviceConnected(index);
}

bool System_005::isTrackedDeviceConnected(uint32_t index)
{
    return openvr::systemImpl->isTrackedDeviceConnected(index);
}

bool System_006::isTrackedDeviceConnected(uint32_t index)
{
    return openvr::systemImpl->isTrackedDeviceConnected(index);
}

bool System_007::isTrackedDeviceConnected(uint32_t index)
{
    return openvr::systemImpl->isTrackedDeviceConnected(index);
}

bool System_009::isTrackedDeviceConnected(uint32_t index)
{
    return openvr::systemImpl->isTrackedDeviceConnected(index);
}

bool System_010::isTrackedDeviceConnected(uint32_t index)
{
    return openvr::systemImpl->isTrackedDeviceConnected(index);
}

bool System_011::isTrackedDeviceConnected(uint32_t index)
{
    return openvr::systemImpl->isTrackedDeviceConnected(index);
}

bool System_012::isTrackedDeviceConnected(uint32_t index)
{
    return openvr::systemImpl->isTrackedDeviceConnected(index);
}

bool System_014::isTrackedDeviceConnected(uint32_t index)
{
    return openvr::systemImpl->isTrackedDeviceConnected(index);
}

bool System_015::isTrackedDeviceConnected(uint32_t index)
{
    return openvr::systemImpl->isTrackedDeviceConnected(index);
}

bool System_016::isTrackedDeviceConnected(uint32_t index)
{
    return openvr::systemImpl->isTrackedDeviceConnected(index);
}

bool System_017::isTrackedDeviceConnected(uint32_t index)
{
    return openvr::systemImpl->isTrackedDeviceConnected(index);
}

bool System_019::isTrackedDeviceConnected(uint32_t index)
{
    return openvr::systemImpl->isTrackedDeviceConnected(index);
}

bool System_020::isTrackedDeviceConnected(uint32_t index)
{
    return openvr::systemImpl->isTrackedDeviceConnected(index);
}

bool System_021::isTrackedDeviceConnected(uint32_t index)
{
    return openvr::systemImpl->isTrackedDeviceConnected(index);
}

bool System_022::isTrackedDeviceConnected(uint32_t index)
{
    return openvr::systemImpl->isTrackedDeviceConnected(index);
}

bool System_003::getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getBoolTrackedDeviceProperty(index, property, error);
}

bool System_004::getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getBoolTrackedDeviceProperty(index, property, error);
}

bool System_005::getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getBoolTrackedDeviceProperty(index, property, error);
}

bool System_006::getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getBoolTrackedDeviceProperty(index, property, error);
}

bool System_007::getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getBoolTrackedDeviceProperty(index, property, error);
}

bool System_009::getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getBoolTrackedDeviceProperty(index, property, error);
}

bool System_010::getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getBoolTrackedDeviceProperty(index, property, error);
}

bool System_011::getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getBoolTrackedDeviceProperty(index, property, error);
}

bool System_012::getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getBoolTrackedDeviceProperty(index, property, error);
}

bool System_014::getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getBoolTrackedDeviceProperty(index, property, error);
}

bool System_015::getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getBoolTrackedDeviceProperty(index, property, error);
}

bool System_016::getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getBoolTrackedDeviceProperty(index, property, error);
}

bool System_017::getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getBoolTrackedDeviceProperty(index, property, error);
}

bool System_019::getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getBoolTrackedDeviceProperty(index, property, error);
}

bool System_020::getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getBoolTrackedDeviceProperty(index, property, error);
}

bool System_021::getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getBoolTrackedDeviceProperty(index, property, error);
}

bool System_022::getBoolTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getBoolTrackedDeviceProperty(index, property, error);
}

float System_003::getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getFloatTrackedDeviceProperty(index, property, error);
}

float System_004::getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getFloatTrackedDeviceProperty(index, property, error);
}

float System_005::getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getFloatTrackedDeviceProperty(index, property, error);
}

float System_006::getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getFloatTrackedDeviceProperty(index, property, error);
}

float System_007::getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getFloatTrackedDeviceProperty(index, property, error);
}

float System_009::getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getFloatTrackedDeviceProperty(index, property, error);
}

float System_010::getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getFloatTrackedDeviceProperty(index, property, error);
}

float System_011::getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getFloatTrackedDeviceProperty(index, property, error);
}

float System_012::getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getFloatTrackedDeviceProperty(index, property, error);
}

float System_014::getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getFloatTrackedDeviceProperty(index, property, error);
}

float System_015::getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getFloatTrackedDeviceProperty(index, property, error);
}

float System_016::getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getFloatTrackedDeviceProperty(index, property, error);
}

float System_017::getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getFloatTrackedDeviceProperty(index, property, error);
}

float System_019::getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getFloatTrackedDeviceProperty(index, property, error);
}

float System_020::getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getFloatTrackedDeviceProperty(index, property, error);
}

float System_021::getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getFloatTrackedDeviceProperty(index, property, error);
}

float System_022::getFloatTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getFloatTrackedDeviceProperty(index, property, error);
}

int32_t System_003::getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getInt32TrackedDeviceProperty(index, property, error);
}

int32_t System_004::getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getInt32TrackedDeviceProperty(index, property, error);
}

int32_t System_005::getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getInt32TrackedDeviceProperty(index, property, error);
}

int32_t System_006::getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getInt32TrackedDeviceProperty(index, property, error);
}

int32_t System_007::getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getInt32TrackedDeviceProperty(index, property, error);
}

int32_t System_009::getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getInt32TrackedDeviceProperty(index, property, error);
}

int32_t System_010::getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getInt32TrackedDeviceProperty(index, property, error);
}

int32_t System_011::getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getInt32TrackedDeviceProperty(index, property, error);
}

int32_t System_012::getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getInt32TrackedDeviceProperty(index, property, error);
}

int32_t System_014::getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getInt32TrackedDeviceProperty(index, property, error);
}

int32_t System_015::getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getInt32TrackedDeviceProperty(index, property, error);
}

int32_t System_016::getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getInt32TrackedDeviceProperty(index, property, error);
}

int32_t System_017::getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getInt32TrackedDeviceProperty(index, property, error);
}

int32_t System_019::getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getInt32TrackedDeviceProperty(index, property, error);
}

int32_t System_020::getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getInt32TrackedDeviceProperty(index, property, error);
}

int32_t System_021::getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getInt32TrackedDeviceProperty(index, property, error);
}

int32_t System_022::getInt32TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getInt32TrackedDeviceProperty(index, property, error);
}

uint64_t System_003::getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getUint64TrackedDeviceProperty(index, property, error);
}

uint64_t System_004::getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getUint64TrackedDeviceProperty(index, property, error);
}

uint64_t System_005::getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getUint64TrackedDeviceProperty(index, property, error);
}

uint64_t System_006::getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getUint64TrackedDeviceProperty(index, property, error);
}

uint64_t System_007::getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getUint64TrackedDeviceProperty(index, property, error);
}

uint64_t System_009::getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getUint64TrackedDeviceProperty(index, property, error);
}

uint64_t System_010::getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getUint64TrackedDeviceProperty(index, property, error);
}

uint64_t System_011::getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getUint64TrackedDeviceProperty(index, property, error);
}

uint64_t System_012::getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getUint64TrackedDeviceProperty(index, property, error);
}

uint64_t System_014::getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getUint64TrackedDeviceProperty(index, property, error);
}

uint64_t System_015::getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getUint64TrackedDeviceProperty(index, property, error);
}

uint64_t System_016::getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getUint64TrackedDeviceProperty(index, property, error);
}

uint64_t System_017::getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getUint64TrackedDeviceProperty(index, property, error);
}

uint64_t System_019::getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getUint64TrackedDeviceProperty(index, property, error);
}

uint64_t System_020::getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getUint64TrackedDeviceProperty(index, property, error);
}

uint64_t System_021::getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getUint64TrackedDeviceProperty(index, property, error);
}

uint64_t System_022::getUint64TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getUint64TrackedDeviceProperty(index, property, error);
}

Matrix34 System_003::getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getMatrix34TrackedDeviceProperty(index, property, error);
}

Matrix34 System_004::getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getMatrix34TrackedDeviceProperty(index, property, error);
}

Matrix34 System_005::getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getMatrix34TrackedDeviceProperty(index, property, error);
}

Matrix34 System_006::getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getMatrix34TrackedDeviceProperty(index, property, error);
}

Matrix34 System_007::getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getMatrix34TrackedDeviceProperty(index, property, error);
}

Matrix34 System_009::getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getMatrix34TrackedDeviceProperty(index, property, error);
}

Matrix34 System_010::getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getMatrix34TrackedDeviceProperty(index, property, error);
}

Matrix34 System_011::getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getMatrix34TrackedDeviceProperty(index, property, error);
}

Matrix34 System_012::getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getMatrix34TrackedDeviceProperty(index, property, error);
}

Matrix34 System_014::getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getMatrix34TrackedDeviceProperty(index, property, error);
}

Matrix34 System_015::getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getMatrix34TrackedDeviceProperty(index, property, error);
}

Matrix34 System_016::getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getMatrix34TrackedDeviceProperty(index, property, error);
}

Matrix34 System_017::getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getMatrix34TrackedDeviceProperty(index, property, error);
}

Matrix34 System_019::getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getMatrix34TrackedDeviceProperty(index, property, error);
}

Matrix34 System_020::getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getMatrix34TrackedDeviceProperty(index, property, error);
}

Matrix34 System_021::getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getMatrix34TrackedDeviceProperty(index, property, error);
}

Matrix34 System_022::getMatrix34TrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedPropertyError* error)
{
    return openvr::systemImpl->getMatrix34TrackedDeviceProperty(index, property, error);
}

uint32_t System_019::getArrayTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedDevicePropertyType type, void* buffer, uint32_t bufferSize, TrackedPropertyError* error)
{
    return openvr::systemImpl->getArrayTrackedDeviceProperty(index, property, type, buffer, bufferSize, error);
}

uint32_t System_020::getArrayTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedDevicePropertyType type, void* buffer, uint32_t bufferSize, TrackedPropertyError* error)
{
    return openvr::systemImpl->getArrayTrackedDeviceProperty(index, property, type, buffer, bufferSize, error);
}

uint32_t System_021::getArrayTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedDevicePropertyType type, void* buffer, uint32_t bufferSize, TrackedPropertyError* error)
{
    return openvr::systemImpl->getArrayTrackedDeviceProperty(index, property, type, buffer, bufferSize, error);
}

uint32_t System_022::getArrayTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, TrackedDevicePropertyType type, void* buffer, uint32_t bufferSize, TrackedPropertyError* error)
{
    return openvr::systemImpl->getArrayTrackedDeviceProperty(index, property, type, buffer, bufferSize, error);
}

uint32_t System_003::getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error)
{
    return openvr::systemImpl->getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error);
}

uint32_t System_004::getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error)
{
    return openvr::systemImpl->getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error);
}

uint32_t System_005::getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error)
{
    return openvr::systemImpl->getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error);
}

uint32_t System_006::getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error)
{
    return openvr::systemImpl->getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error);
}

uint32_t System_007::getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error)
{
    return openvr::systemImpl->getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error);
}

uint32_t System_009::getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error)
{
    return openvr::systemImpl->getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error);
}

uint32_t System_010::getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error)
{
    return openvr::systemImpl->getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error);
}

uint32_t System_011::getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error)
{
    return openvr::systemImpl->getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error);
}

uint32_t System_012::getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error)
{
    return openvr::systemImpl->getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error);
}

uint32_t System_014::getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error)
{
    return openvr::systemImpl->getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error);
}

uint32_t System_015::getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error)
{
    return openvr::systemImpl->getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error);
}

uint32_t System_016::getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error)
{
    return openvr::systemImpl->getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error);
}

uint32_t System_017::getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error)
{
    return openvr::systemImpl->getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error);
}

uint32_t System_019::getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error)
{
    return openvr::systemImpl->getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error);
}

uint32_t System_020::getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error)
{
    return openvr::systemImpl->getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error);
}

uint32_t System_021::getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error)
{
    return openvr::systemImpl->getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error);
}

uint32_t System_022::getStringTrackedDeviceProperty(uint32_t index, TrackedDeviceProperty property, char* buffer, uint32_t bufferSize, TrackedPropertyError* error)
{
    return openvr::systemImpl->getStringTrackedDeviceProperty(index, property, buffer, bufferSize, error);
}

const char* System_003::getPropErrorNameFromEnum(TrackedPropertyError error)
{
    return openvr::systemImpl->getPropErrorNameFromEnum(error);
}

const char* System_004::getPropErrorNameFromEnum(TrackedPropertyError error)
{
    return openvr::systemImpl->getPropErrorNameFromEnum(error);
}

const char* System_005::getPropErrorNameFromEnum(TrackedPropertyError error)
{
    return openvr::systemImpl->getPropErrorNameFromEnum(error);
}

const char* System_006::getPropErrorNameFromEnum(TrackedPropertyError error)
{
    return openvr::systemImpl->getPropErrorNameFromEnum(error);
}

const char* System_007::getPropErrorNameFromEnum(TrackedPropertyError error)
{
    return openvr::systemImpl->getPropErrorNameFromEnum(error);
}

const char* System_009::getPropErrorNameFromEnum(TrackedPropertyError error)
{
    return openvr::systemImpl->getPropErrorNameFromEnum(error);
}

const char* System_010::getPropErrorNameFromEnum(TrackedPropertyError error)
{
    return openvr::systemImpl->getPropErrorNameFromEnum(error);
}

const char* System_011::getPropErrorNameFromEnum(TrackedPropertyError error)
{
    return openvr::systemImpl->getPropErrorNameFromEnum(error);
}

const char* System_012::getPropErrorNameFromEnum(TrackedPropertyError error)
{
    return openvr::systemImpl->getPropErrorNameFromEnum(error);
}

const char* System_014::getPropErrorNameFromEnum(TrackedPropertyError error)
{
    return openvr::systemImpl->getPropErrorNameFromEnum(error);
}

const char* System_015::getPropErrorNameFromEnum(TrackedPropertyError error)
{
    return openvr::systemImpl->getPropErrorNameFromEnum(error);
}

const char* System_016::getPropErrorNameFromEnum(TrackedPropertyError error)
{
    return openvr::systemImpl->getPropErrorNameFromEnum(error);
}

const char* System_017::getPropErrorNameFromEnum(TrackedPropertyError error)
{
    return openvr::systemImpl->getPropErrorNameFromEnum(error);
}

const char* System_019::getPropErrorNameFromEnum(TrackedPropertyError error)
{
    return openvr::systemImpl->getPropErrorNameFromEnum(error);
}

const char* System_020::getPropErrorNameFromEnum(TrackedPropertyError error)
{
    return openvr::systemImpl->getPropErrorNameFromEnum(error);
}

const char* System_021::getPropErrorNameFromEnum(TrackedPropertyError error)
{
    return openvr::systemImpl->getPropErrorNameFromEnum(error);
}

const char* System_022::getPropErrorNameFromEnum(TrackedPropertyError error)
{
    return openvr::systemImpl->getPropErrorNameFromEnum(error);
}

bool System_003::pollNextEvent(Event_0_9_0* event)
{
    Event_0_9_15 e;
    bool r = openvr::systemImpl->pollNextEvent(&e, sizeof(Event_0_9_15));
    event->type = e.type;
    event->trackedDeviceIndex = e.trackedDeviceIndex;
    event->ageSeconds = e.ageSeconds;
    std::memcpy(&event->data, &e.data, sizeof(Event_0_9_0::EventData));
    return r;
}

bool System_004::pollNextEvent(Event_0_9_0* event)
{
    Event_0_9_15 e;
    bool r = openvr::systemImpl->pollNextEvent(&e, sizeof(Event_0_9_15));
    event->type = e.type;
    event->trackedDeviceIndex = e.trackedDeviceIndex;
    event->ageSeconds = e.ageSeconds;
    std::memcpy(&event->data, &e.data, sizeof(Event_0_9_0::EventData));
    return r;
}

bool System_005::pollNextEvent(Event_0_9_0* event)
{
    Event_0_9_15 e;
    bool r = openvr::systemImpl->pollNextEvent(&e, sizeof(Event_0_9_15));
    event->type = e.type;
    event->trackedDeviceIndex = e.trackedDeviceIndex;
    event->ageSeconds = e.ageSeconds;
    std::memcpy(&event->data, &e.data, sizeof(Event_0_9_0::EventData));
    return r;
}

bool System_006::pollNextEvent(Event_0_9_0* event)
{
    Event_0_9_15 e;
    bool r = openvr::systemImpl->pollNextEvent(&e, sizeof(Event_0_9_15));
    event->type = e.type;
    event->trackedDeviceIndex = e.trackedDeviceIndex;
    event->ageSeconds = e.ageSeconds;
    std::memcpy(&event->data, &e.data, sizeof(Event_0_9_0::EventData));
    return r;
}

bool System_007::pollNextEvent(Event_0_9_0* event)
{
    Event_0_9_15 e;
    bool r = openvr::systemImpl->pollNextEvent(&e, sizeof(Event_0_9_15));
    event->type = e.type;
    event->trackedDeviceIndex = e.trackedDeviceIndex;
    event->ageSeconds = e.ageSeconds;
    std::memcpy(&event->data, &e.data, sizeof(Event_0_9_0::EventData));
    return r;
}

bool System_009::pollNextEvent(Event_0_9_0* event)
{
    Event_0_9_15 e;
    bool r = openvr::systemImpl->pollNextEvent(&e, sizeof(Event_0_9_15));
    event->type = e.type;
    event->trackedDeviceIndex = e.trackedDeviceIndex;
    event->ageSeconds = e.ageSeconds;
    std::memcpy(&event->data, &e.data, sizeof(Event_0_9_0::EventData));
    return r;
}

bool System_010::pollNextEvent(Event_0_9_0* event)
{
    Event_0_9_15 e;
    bool r = openvr::systemImpl->pollNextEvent(&e, sizeof(Event_0_9_15));
    event->type = e.type;
    event->trackedDeviceIndex = e.trackedDeviceIndex;
    event->ageSeconds = e.ageSeconds;
    std::memcpy(&event->data, &e.data, sizeof(Event_0_9_0::EventData));
    return r;
}

bool System_011::pollNextEvent(Event_0_9_15* event, uint32_t bufferSize)
{
    return openvr::systemImpl->pollNextEvent(event, bufferSize);
}

bool System_012::pollNextEvent(Event_0_9_15* event, uint32_t bufferSize)
{
    return openvr::systemImpl->pollNextEvent(event, bufferSize);
}

bool System_014::pollNextEvent(Event_0_9_15* event, uint32_t bufferSize)
{
    return openvr::systemImpl->pollNextEvent(event, bufferSize);
}

bool System_015::pollNextEvent(Event_0_9_15* event, uint32_t bufferSize)
{
    return openvr::systemImpl->pollNextEvent(event, bufferSize);
}

bool System_016::pollNextEvent(Event_0_9_15* event, uint32_t bufferSize)
{
    return openvr::systemImpl->pollNextEvent(event, bufferSize);
}

bool System_017::pollNextEvent(Event_0_9_15* event, uint32_t bufferSize)
{
    return openvr::systemImpl->pollNextEvent(event, bufferSize);
}

bool System_019::pollNextEvent(Event_0_9_15* event, uint32_t bufferSize)
{
    return openvr::systemImpl->pollNextEvent(event, bufferSize);
}

bool System_020::pollNextEvent(Event_0_9_15* event, uint32_t bufferSize)
{
    return openvr::systemImpl->pollNextEvent(event, bufferSize);
}

bool System_021::pollNextEvent(Event_0_9_15* event, uint32_t bufferSize)
{
    return openvr::systemImpl->pollNextEvent(event, bufferSize);
}

bool System_022::pollNextEvent(Event_0_9_15* event, uint32_t bufferSize)
{
    return openvr::systemImpl->pollNextEvent(event, bufferSize);
}

bool System_003::pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_0* event, TrackedDevicePose* trackedDevicePoseOut)
{
    Event_0_9_15 e;
    bool r = openvr::systemImpl->pollNextEventWithPose(origin, &e, sizeof(Event_0_9_15), trackedDevicePoseOut);
    event->type = e.type;
    event->trackedDeviceIndex = e.trackedDeviceIndex;
    event->ageSeconds = e.ageSeconds;
    std::memcpy(&event->data, &e.data, sizeof(Event_0_9_0::EventData));
    return r;
}

bool System_004::pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_0* event, TrackedDevicePose* trackedDevicePoseOut)
{
    Event_0_9_15 e;
    bool r = openvr::systemImpl->pollNextEventWithPose(origin, &e, sizeof(Event_0_9_15), trackedDevicePoseOut);
    event->type = e.type;
    event->trackedDeviceIndex = e.trackedDeviceIndex;
    event->ageSeconds = e.ageSeconds;
    std::memcpy(&event->data, &e.data, sizeof(Event_0_9_0::EventData));
    return r;
}

bool System_005::pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_0* event, TrackedDevicePose* trackedDevicePoseOut)
{
    Event_0_9_15 e;
    bool r = openvr::systemImpl->pollNextEventWithPose(origin, &e, sizeof(Event_0_9_15), trackedDevicePoseOut);
    event->type = e.type;
    event->trackedDeviceIndex = e.trackedDeviceIndex;
    event->ageSeconds = e.ageSeconds;
    std::memcpy(&event->data, &e.data, sizeof(Event_0_9_0::EventData));
    return r;
}

bool System_006::pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_0* event, TrackedDevicePose* trackedDevicePoseOut)
{
    Event_0_9_15 e;
    bool r = openvr::systemImpl->pollNextEventWithPose(origin, &e, sizeof(Event_0_9_15), trackedDevicePoseOut);
    event->type = e.type;
    event->trackedDeviceIndex = e.trackedDeviceIndex;
    event->ageSeconds = e.ageSeconds;
    std::memcpy(&event->data, &e.data, sizeof(Event_0_9_0::EventData));
    return r;
}

bool System_007::pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_0* event, TrackedDevicePose* trackedDevicePoseOut)
{
    Event_0_9_15 e;
    bool r = openvr::systemImpl->pollNextEventWithPose(origin, &e, sizeof(Event_0_9_15), trackedDevicePoseOut);
    event->type = e.type;
    event->trackedDeviceIndex = e.trackedDeviceIndex;
    event->ageSeconds = e.ageSeconds;
    std::memcpy(&event->data, &e.data, sizeof(Event_0_9_0::EventData));
    return r;
}

bool System_009::pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_0* event, TrackedDevicePose* trackedDevicePoseOut)
{
    Event_0_9_15 e;
    bool r = openvr::systemImpl->pollNextEventWithPose(origin, &e, sizeof(Event_0_9_15), trackedDevicePoseOut);
    event->type = e.type;
    event->trackedDeviceIndex = e.trackedDeviceIndex;
    event->ageSeconds = e.ageSeconds;
    std::memcpy(&event->data, &e.data, sizeof(Event_0_9_0::EventData));
    return r;
}

bool System_010::pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_0* event, TrackedDevicePose* trackedDevicePoseOut)
{
    Event_0_9_15 e;
    bool r = openvr::systemImpl->pollNextEventWithPose(origin, &e, sizeof(Event_0_9_15), trackedDevicePoseOut);
    event->type = e.type;
    event->trackedDeviceIndex = e.trackedDeviceIndex;
    event->ageSeconds = e.ageSeconds;
    std::memcpy(&event->data, &e.data, sizeof(Event_0_9_0::EventData));
    return r;
}

bool System_011::pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut)
{
    return openvr::systemImpl->pollNextEventWithPose(origin, event, bufferSize, trackedDevicePoseOut);
}

bool System_012::pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut)
{
    return openvr::systemImpl->pollNextEventWithPose(origin, event, bufferSize, trackedDevicePoseOut);
}

bool System_014::pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut)
{
    return openvr::systemImpl->pollNextEventWithPose(origin, event, bufferSize, trackedDevicePoseOut);
}

bool System_015::pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut)
{
    return openvr::systemImpl->pollNextEventWithPose(origin, event, bufferSize, trackedDevicePoseOut);
}

bool System_016::pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut)
{
    return openvr::systemImpl->pollNextEventWithPose(origin, event, bufferSize, trackedDevicePoseOut);
}

bool System_017::pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut)
{
    return openvr::systemImpl->pollNextEventWithPose(origin, event, bufferSize, trackedDevicePoseOut);
}

bool System_019::pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut)
{
    return openvr::systemImpl->pollNextEventWithPose(origin, event, bufferSize, trackedDevicePoseOut);
}

bool System_020::pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut)
{
    return openvr::systemImpl->pollNextEventWithPose(origin, event, bufferSize, trackedDevicePoseOut);
}

bool System_021::pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut)
{
    return openvr::systemImpl->pollNextEventWithPose(origin, event, bufferSize, trackedDevicePoseOut);
}

bool System_022::pollNextEventWithPose(TrackingUniverseOrigin origin, Event_0_9_15* event, uint32_t bufferSize, TrackedDevicePose* trackedDevicePoseOut)
{
    return openvr::systemImpl->pollNextEventWithPose(origin, event, bufferSize, trackedDevicePoseOut);
}

const char* System_003::getEventTypeNameFromEnum(EventType type)
{
    return openvr::systemImpl->getEventTypeNameFromEnum(type);
}

const char* System_004::getEventTypeNameFromEnum(EventType type)
{
    return openvr::systemImpl->getEventTypeNameFromEnum(type);
}

const char* System_005::getEventTypeNameFromEnum(EventType type)
{
    return openvr::systemImpl->getEventTypeNameFromEnum(type);
}

const char* System_006::getEventTypeNameFromEnum(EventType type)
{
    return openvr::systemImpl->getEventTypeNameFromEnum(type);
}

const char* System_007::getEventTypeNameFromEnum(EventType type)
{
    return openvr::systemImpl->getEventTypeNameFromEnum(type);
}

const char* System_009::getEventTypeNameFromEnum(EventType type)
{
    return openvr::systemImpl->getEventTypeNameFromEnum(type);
}

const char* System_010::getEventTypeNameFromEnum(EventType type)
{
    return openvr::systemImpl->getEventTypeNameFromEnum(type);
}

const char* System_011::getEventTypeNameFromEnum(EventType type)
{
    return openvr::systemImpl->getEventTypeNameFromEnum(type);
}

const char* System_012::getEventTypeNameFromEnum(EventType type)
{
    return openvr::systemImpl->getEventTypeNameFromEnum(type);
}

const char* System_014::getEventTypeNameFromEnum(EventType type)
{
    return openvr::systemImpl->getEventTypeNameFromEnum(type);
}

const char* System_015::getEventTypeNameFromEnum(EventType type)
{
    return openvr::systemImpl->getEventTypeNameFromEnum(type);
}

const char* System_016::getEventTypeNameFromEnum(EventType type)
{
    return openvr::systemImpl->getEventTypeNameFromEnum(type);
}

const char* System_017::getEventTypeNameFromEnum(EventType type)
{
    return openvr::systemImpl->getEventTypeNameFromEnum(type);
}

const char* System_019::getEventTypeNameFromEnum(EventType type)
{
    return openvr::systemImpl->getEventTypeNameFromEnum(type);
}

const char* System_020::getEventTypeNameFromEnum(EventType type)
{
    return openvr::systemImpl->getEventTypeNameFromEnum(type);
}

const char* System_021::getEventTypeNameFromEnum(EventType type)
{
    return openvr::systemImpl->getEventTypeNameFromEnum(type);
}

const char* System_022::getEventTypeNameFromEnum(EventType type)
{
    return openvr::systemImpl->getEventTypeNameFromEnum(type);
}

HiddenAreaMesh System_003::getHiddenAreaMesh(Eye eye)
{
    return openvr::systemImpl->getHiddenAreaMesh(eye, HiddenAreaMeshType::HIDDEN_AREA_MESH_TYPE_STANDARD);
}

HiddenAreaMesh System_004::getHiddenAreaMesh(Eye eye)
{
    return openvr::systemImpl->getHiddenAreaMesh(eye, HiddenAreaMeshType::HIDDEN_AREA_MESH_TYPE_STANDARD);
}

HiddenAreaMesh System_005::getHiddenAreaMesh(Eye eye)
{
    return openvr::systemImpl->getHiddenAreaMesh(eye, HiddenAreaMeshType::HIDDEN_AREA_MESH_TYPE_STANDARD);
}

HiddenAreaMesh System_006::getHiddenAreaMesh(Eye eye)
{
    return openvr::systemImpl->getHiddenAreaMesh(eye, HiddenAreaMeshType::HIDDEN_AREA_MESH_TYPE_STANDARD);
}

HiddenAreaMesh System_007::getHiddenAreaMesh(Eye eye)
{
    return openvr::systemImpl->getHiddenAreaMesh(eye, HiddenAreaMeshType::HIDDEN_AREA_MESH_TYPE_STANDARD);
}

HiddenAreaMesh System_009::getHiddenAreaMesh(Eye eye)
{
    return openvr::systemImpl->getHiddenAreaMesh(eye, HiddenAreaMeshType::HIDDEN_AREA_MESH_TYPE_STANDARD);
}

HiddenAreaMesh System_010::getHiddenAreaMesh(Eye eye)
{
    return openvr::systemImpl->getHiddenAreaMesh(eye, HiddenAreaMeshType::HIDDEN_AREA_MESH_TYPE_STANDARD);
}

HiddenAreaMesh System_011::getHiddenAreaMesh(Eye eye)
{
    return openvr::systemImpl->getHiddenAreaMesh(eye, HiddenAreaMeshType::HIDDEN_AREA_MESH_TYPE_STANDARD);
}

HiddenAreaMesh System_012::getHiddenAreaMesh(Eye eye)
{
    return openvr::systemImpl->getHiddenAreaMesh(eye, HiddenAreaMeshType::HIDDEN_AREA_MESH_TYPE_STANDARD);
}

HiddenAreaMesh System_014::getHiddenAreaMesh(Eye eye, HiddenAreaMeshType type)
{
    return openvr::systemImpl->getHiddenAreaMesh(eye, type);
}

HiddenAreaMesh System_015::getHiddenAreaMesh(Eye eye, HiddenAreaMeshType type)
{
    return openvr::systemImpl->getHiddenAreaMesh(eye, type);
}

HiddenAreaMesh System_016::getHiddenAreaMesh(Eye eye, HiddenAreaMeshType type)
{
    return openvr::systemImpl->getHiddenAreaMesh(eye, type);
}

HiddenAreaMesh System_017::getHiddenAreaMesh(Eye eye, HiddenAreaMeshType type)
{
    return openvr::systemImpl->getHiddenAreaMesh(eye, type);
}

HiddenAreaMesh System_019::getHiddenAreaMesh(Eye eye, HiddenAreaMeshType type)
{
    return openvr::systemImpl->getHiddenAreaMesh(eye, type);
}

HiddenAreaMesh System_020::getHiddenAreaMesh(Eye eye, HiddenAreaMeshType type)
{
    return openvr::systemImpl->getHiddenAreaMesh(eye, type);
}

HiddenAreaMesh System_021::getHiddenAreaMesh(Eye eye, HiddenAreaMeshType type)
{
    return openvr::systemImpl->getHiddenAreaMesh(eye, type);
}

HiddenAreaMesh System_022::getHiddenAreaMesh(Eye eye, HiddenAreaMeshType type)
{
    return openvr::systemImpl->getHiddenAreaMesh(eye, type);
}

bool System_003::getControllerState(uint32_t index, ControllerState* state)
{
    return openvr::systemImpl->getControllerState(index, state, sizeof(ControllerState));
}

bool System_004::getControllerState(uint32_t index, ControllerState* state)
{
    return openvr::systemImpl->getControllerState(index, state, sizeof(ControllerState));
}

bool System_005::getControllerState(uint32_t index, ControllerState* state)
{
    return openvr::systemImpl->getControllerState(index, state, sizeof(ControllerState));
}

bool System_006::getControllerState(uint32_t index, ControllerState* state)
{
    return openvr::systemImpl->getControllerState(index, state, sizeof(ControllerState));
}

bool System_007::getControllerState(uint32_t index, ControllerState* state)
{
    return openvr::systemImpl->getControllerState(index, state, sizeof(ControllerState));
}

bool System_009::getControllerState(uint32_t index, ControllerState* state)
{
    return openvr::systemImpl->getControllerState(index, state, sizeof(ControllerState));
}

bool System_010::getControllerState(uint32_t index, ControllerState* state)
{
    return openvr::systemImpl->getControllerState(index, state, sizeof(ControllerState));
}

bool System_011::getControllerState(uint32_t index, ControllerState* state)
{
    return openvr::systemImpl->getControllerState(index, state, sizeof(ControllerState));
}

bool System_012::getControllerState(uint32_t index, ControllerState* state)
{
    return openvr::systemImpl->getControllerState(index, state, sizeof(ControllerState));
}

bool System_014::getControllerState(uint32_t index, ControllerState* state, uint32_t bufferSize)
{
    return openvr::systemImpl->getControllerState(index, state, bufferSize);
}

bool System_015::getControllerState(uint32_t index, ControllerState* state, uint32_t bufferSize)
{
    return openvr::systemImpl->getControllerState(index, state, bufferSize);
}

bool System_016::getControllerState(uint32_t index, ControllerState* state, uint32_t bufferSize)
{
    return openvr::systemImpl->getControllerState(index, state, bufferSize);
}

bool System_017::getControllerState(uint32_t index, ControllerState* state, uint32_t bufferSize)
{
    return openvr::systemImpl->getControllerState(index, state, bufferSize);
}

bool System_019::getControllerState(uint32_t index, ControllerState* state, uint32_t bufferSize)
{
    return openvr::systemImpl->getControllerState(index, state, bufferSize);
}

bool System_020::getControllerState(uint32_t index, ControllerState* state, uint32_t bufferSize)
{
    return openvr::systemImpl->getControllerState(index, state, bufferSize);
}

bool System_021::getControllerState(uint32_t index, ControllerState* state, uint32_t bufferSize)
{
    return openvr::systemImpl->getControllerState(index, state, bufferSize);
}

bool System_022::getControllerState(uint32_t index, ControllerState* state, uint32_t bufferSize)
{
    return openvr::systemImpl->getControllerState(index, state, bufferSize);
}

bool System_003::getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose)
{
    return openvr::systemImpl->getControllerStateWithPose(origin, index, state, sizeof(ControllerState), pose);
}

bool System_004::getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose)
{
    return openvr::systemImpl->getControllerStateWithPose(origin, index, state, sizeof(ControllerState), pose);
}

bool System_005::getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose)
{
    return openvr::systemImpl->getControllerStateWithPose(origin, index, state, sizeof(ControllerState), pose);
}

bool System_006::getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose)
{
    return openvr::systemImpl->getControllerStateWithPose(origin, index, state, sizeof(ControllerState), pose);
}

bool System_007::getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose)
{
    return openvr::systemImpl->getControllerStateWithPose(origin, index, state, sizeof(ControllerState), pose);
}

bool System_009::getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose)
{
    return openvr::systemImpl->getControllerStateWithPose(origin, index, state, sizeof(ControllerState), pose);
}

bool System_010::getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose)
{
    return openvr::systemImpl->getControllerStateWithPose(origin, index, state, sizeof(ControllerState), pose);
}

bool System_011::getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose)
{
    return openvr::systemImpl->getControllerStateWithPose(origin, index, state, sizeof(ControllerState), pose);
}

bool System_012::getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, TrackedDevicePose* pose)
{
    return openvr::systemImpl->getControllerStateWithPose(origin, index, state, sizeof(ControllerState), pose);
}

bool System_014::getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, uint32_t bufferSize, TrackedDevicePose* pose)
{
    return openvr::systemImpl->getControllerStateWithPose(origin, index, state, bufferSize, pose);
}

bool System_015::getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, uint32_t bufferSize, TrackedDevicePose* pose)
{
    return openvr::systemImpl->getControllerStateWithPose(origin, index, state, bufferSize, pose);
}

bool System_016::getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, uint32_t bufferSize, TrackedDevicePose* pose)
{
    return openvr::systemImpl->getControllerStateWithPose(origin, index, state, bufferSize, pose);
}

bool System_017::getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, uint32_t bufferSize, TrackedDevicePose* pose)
{
    return openvr::systemImpl->getControllerStateWithPose(origin, index, state, bufferSize, pose);
}

bool System_019::getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, uint32_t bufferSize, TrackedDevicePose* pose)
{
    return openvr::systemImpl->getControllerStateWithPose(origin, index, state, bufferSize, pose);
}

bool System_020::getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, uint32_t bufferSize, TrackedDevicePose* pose)
{
    return openvr::systemImpl->getControllerStateWithPose(origin, index, state, bufferSize, pose);
}

bool System_021::getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, uint32_t bufferSize, TrackedDevicePose* pose)
{
    return openvr::systemImpl->getControllerStateWithPose(origin, index, state, bufferSize, pose);
}

bool System_022::getControllerStateWithPose(TrackingUniverseOrigin origin, uint32_t index, ControllerState* state, uint32_t bufferSize, TrackedDevicePose* pose)
{
    return openvr::systemImpl->getControllerStateWithPose(origin, index, state, bufferSize, pose);
}

void System_003::triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs)
{
    return openvr::systemImpl->triggerHapticPulse(index, axisId, durationUs);
}

void System_004::triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs)
{
    return openvr::systemImpl->triggerHapticPulse(index, axisId, durationUs);
}

void System_005::triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs)
{
    return openvr::systemImpl->triggerHapticPulse(index, axisId, durationUs);
}

void System_006::triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs)
{
    return openvr::systemImpl->triggerHapticPulse(index, axisId, durationUs);
}

void System_007::triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs)
{
    return openvr::systemImpl->triggerHapticPulse(index, axisId, durationUs);
}

void System_009::triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs)
{
    return openvr::systemImpl->triggerHapticPulse(index, axisId, durationUs);
}

void System_010::triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs)
{
    return openvr::systemImpl->triggerHapticPulse(index, axisId, durationUs);
}

void System_011::triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs)
{
    return openvr::systemImpl->triggerHapticPulse(index, axisId, durationUs);
}

void System_012::triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs)
{
    return openvr::systemImpl->triggerHapticPulse(index, axisId, durationUs);
}

void System_014::triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs)
{
    return openvr::systemImpl->triggerHapticPulse(index, axisId, durationUs);
}

void System_015::triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs)
{
    return openvr::systemImpl->triggerHapticPulse(index, axisId, durationUs);
}

void System_016::triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs)
{
    return openvr::systemImpl->triggerHapticPulse(index, axisId, durationUs);
}

void System_017::triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs)
{
    return openvr::systemImpl->triggerHapticPulse(index, axisId, durationUs);
}

void System_019::triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs)
{
    return openvr::systemImpl->triggerHapticPulse(index, axisId, durationUs);
}

void System_020::triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs)
{
    return openvr::systemImpl->triggerHapticPulse(index, axisId, durationUs);
}

void System_021::triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs)
{
    return openvr::systemImpl->triggerHapticPulse(index, axisId, durationUs);
}

void System_022::triggerHapticPulse(uint32_t index, uint32_t axisId, unsigned short durationUs)
{
    return openvr::systemImpl->triggerHapticPulse(index, axisId, durationUs);
}

const char* System_003::getButtonIdNameFromEnum(ButtonId button)
{
    return openvr::systemImpl->getButtonIdNameFromEnum(button);
}

const char* System_004::getButtonIdNameFromEnum(ButtonId button)
{
    return openvr::systemImpl->getButtonIdNameFromEnum(button);
}

const char* System_005::getButtonIdNameFromEnum(ButtonId button)
{
    return openvr::systemImpl->getButtonIdNameFromEnum(button);
}

const char* System_006::getButtonIdNameFromEnum(ButtonId button)
{
    return openvr::systemImpl->getButtonIdNameFromEnum(button);
}

const char* System_007::getButtonIdNameFromEnum(ButtonId button)
{
    return openvr::systemImpl->getButtonIdNameFromEnum(button);
}

const char* System_009::getButtonIdNameFromEnum(ButtonId button)
{
    return openvr::systemImpl->getButtonIdNameFromEnum(button);
}

const char* System_010::getButtonIdNameFromEnum(ButtonId button)
{
    return openvr::systemImpl->getButtonIdNameFromEnum(button);
}

const char* System_011::getButtonIdNameFromEnum(ButtonId button)
{
    return openvr::systemImpl->getButtonIdNameFromEnum(button);
}

const char* System_012::getButtonIdNameFromEnum(ButtonId button)
{
    return openvr::systemImpl->getButtonIdNameFromEnum(button);
}

const char* System_014::getButtonIdNameFromEnum(ButtonId button)
{
    return openvr::systemImpl->getButtonIdNameFromEnum(button);
}

const char* System_015::getButtonIdNameFromEnum(ButtonId button)
{
    return openvr::systemImpl->getButtonIdNameFromEnum(button);
}

const char* System_016::getButtonIdNameFromEnum(ButtonId button)
{
    return openvr::systemImpl->getButtonIdNameFromEnum(button);
}

const char* System_017::getButtonIdNameFromEnum(ButtonId button)
{
    return openvr::systemImpl->getButtonIdNameFromEnum(button);
}

const char* System_019::getButtonIdNameFromEnum(ButtonId button)
{
    return openvr::systemImpl->getButtonIdNameFromEnum(button);
}

const char* System_020::getButtonIdNameFromEnum(ButtonId button)
{
    return openvr::systemImpl->getButtonIdNameFromEnum(button);
}

const char* System_021::getButtonIdNameFromEnum(ButtonId button)
{
    return openvr::systemImpl->getButtonIdNameFromEnum(button);
}

const char* System_022::getButtonIdNameFromEnum(ButtonId button)
{
    return openvr::systemImpl->getButtonIdNameFromEnum(button);
}

const char* System_003::getControllerAxisTypeNameFromEnum(ControllerAxisType axisType)
{
    return openvr::systemImpl->getControllerAxisTypeNameFromEnum(axisType);
}

const char* System_004::getControllerAxisTypeNameFromEnum(ControllerAxisType axisType)
{
    return openvr::systemImpl->getControllerAxisTypeNameFromEnum(axisType);
}

const char* System_005::getControllerAxisTypeNameFromEnum(ControllerAxisType axisType)
{
    return openvr::systemImpl->getControllerAxisTypeNameFromEnum(axisType);
}

const char* System_006::getControllerAxisTypeNameFromEnum(ControllerAxisType axisType)
{
    return openvr::systemImpl->getControllerAxisTypeNameFromEnum(axisType);
}

const char* System_007::getControllerAxisTypeNameFromEnum(ControllerAxisType axisType)
{
    return openvr::systemImpl->getControllerAxisTypeNameFromEnum(axisType);
}

const char* System_009::getControllerAxisTypeNameFromEnum(ControllerAxisType axisType)
{
    return openvr::systemImpl->getControllerAxisTypeNameFromEnum(axisType);
}

const char* System_010::getControllerAxisTypeNameFromEnum(ControllerAxisType axisType)
{
    return openvr::systemImpl->getControllerAxisTypeNameFromEnum(axisType);
}

const char* System_011::getControllerAxisTypeNameFromEnum(ControllerAxisType axisType)
{
    return openvr::systemImpl->getControllerAxisTypeNameFromEnum(axisType);
}

const char* System_012::getControllerAxisTypeNameFromEnum(ControllerAxisType axisType)
{
    return openvr::systemImpl->getControllerAxisTypeNameFromEnum(axisType);
}

const char* System_014::getControllerAxisTypeNameFromEnum(ControllerAxisType axisType)
{
    return openvr::systemImpl->getControllerAxisTypeNameFromEnum(axisType);
}

const char* System_015::getControllerAxisTypeNameFromEnum(ControllerAxisType axisType)
{
    return openvr::systemImpl->getControllerAxisTypeNameFromEnum(axisType);
}

const char* System_016::getControllerAxisTypeNameFromEnum(ControllerAxisType axisType)
{
    return openvr::systemImpl->getControllerAxisTypeNameFromEnum(axisType);
}

const char* System_017::getControllerAxisTypeNameFromEnum(ControllerAxisType axisType)
{
    return openvr::systemImpl->getControllerAxisTypeNameFromEnum(axisType);
}

const char* System_019::getControllerAxisTypeNameFromEnum(ControllerAxisType axisType)
{
    return openvr::systemImpl->getControllerAxisTypeNameFromEnum(axisType);
}

const char* System_020::getControllerAxisTypeNameFromEnum(ControllerAxisType axisType)
{
    return openvr::systemImpl->getControllerAxisTypeNameFromEnum(axisType);
}

const char* System_021::getControllerAxisTypeNameFromEnum(ControllerAxisType axisType)
{
    return openvr::systemImpl->getControllerAxisTypeNameFromEnum(axisType);
}

const char* System_022::getControllerAxisTypeNameFromEnum(ControllerAxisType axisType)
{
    return openvr::systemImpl->getControllerAxisTypeNameFromEnum(axisType);
}

bool System_003::handleControllerOverlayInteractionAsMouse(const OverlaySettings& overlaySettings, Vector2 windowClientPositionOnScreen, Vector2 windowClientSize, uint32_t controllerDeviceIndex, ControllerEventOutputType outputType)
{
    // TODO: requires overlay implementation
    STUB();
    return false;
}

bool System_003::captureInputFocus()
{
    TRACE();
    return true;
}

bool System_004::captureInputFocus()
{
    TRACE();
    return true;
}

bool System_005::captureInputFocus()
{
    TRACE();
    return true;
}

bool System_006::captureInputFocus()
{
    TRACE();
    return true;
}

bool System_007::captureInputFocus()
{
    TRACE();
    return true;
}

bool System_009::captureInputFocus()
{
    TRACE();
    return true;
}

bool System_010::captureInputFocus()
{
    TRACE();
    return true;
}

bool System_011::captureInputFocus()
{
    TRACE();
    return true;
}

bool System_012::captureInputFocus()
{
    TRACE();
    return true;
}

bool System_014::captureInputFocus()
{
    TRACE();
    return true;
}

bool System_015::captureInputFocus()
{
    TRACE();
    return true;
}

bool System_016::captureInputFocus()
{
    TRACE();
    return true;
}

bool System_017::captureInputFocus()
{
    TRACE();
    return true;
}

void System_003::releaseInputFocus()
{
    TRACE();
}

void System_004::releaseInputFocus()
{
    TRACE();
}

void System_005::releaseInputFocus()
{
    TRACE();
}

void System_006::releaseInputFocus()
{
    TRACE();
}

void System_007::releaseInputFocus()
{
    TRACE();
}

void System_009::releaseInputFocus()
{
    TRACE();
}

void System_010::releaseInputFocus()
{
    TRACE();
}

void System_011::releaseInputFocus()
{
    TRACE();
}

void System_012::releaseInputFocus()
{
    TRACE();
}

void System_014::releaseInputFocus()
{
    TRACE();
}

void System_015::releaseInputFocus()
{
    TRACE();
}

void System_016::releaseInputFocus()
{
    TRACE();
}

void System_017::releaseInputFocus()
{
    TRACE();
}

bool System_003::isInputFocusCapturedByAnotherProcess()
{
    TRACE();
    return false;
}

bool System_004::isInputFocusCapturedByAnotherProcess()
{
    TRACE();
    return false;
}

bool System_005::isInputFocusCapturedByAnotherProcess()
{
    TRACE();
    return false;
}

bool System_006::isInputFocusCapturedByAnotherProcess()
{
    TRACE();
    return false;
}

bool System_007::isInputFocusCapturedByAnotherProcess()
{
    TRACE();
    return false;
}

bool System_009::isInputFocusCapturedByAnotherProcess()
{
    TRACE();
    return false;
}

bool System_010::isInputFocusCapturedByAnotherProcess()
{
    TRACE();
    return false;
}

bool System_011::isInputFocusCapturedByAnotherProcess()
{
    TRACE();
    return false;
}

bool System_012::isInputFocusCapturedByAnotherProcess()
{
    TRACE();
    return false;
}

bool System_014::isInputFocusCapturedByAnotherProcess()
{
    TRACE();
    return false;
}

bool System_015::isInputFocusCapturedByAnotherProcess()
{
    TRACE();
    return false;
}

bool System_016::isInputFocusCapturedByAnotherProcess()
{
    TRACE();
    return false;
}

bool System_017::isInputFocusCapturedByAnotherProcess()
{
    TRACE();
    return false;
}

bool System_019::isInputAvailable()
{
    TRACE();
    return true;
}

bool System_020::isInputAvailable()
{
    TRACE();
    return true;
}

bool System_021::isInputAvailable()
{
    TRACE();
    return true;
}

bool System_022::isInputAvailable()
{
    TRACE();
    return true;
}

bool System_019::isSteamVRDrawingControllers()
{
    return false;
}

bool System_020::isSteamVRDrawingControllers()
{
    return false;
}

bool System_021::isSteamVRDrawingControllers()
{
    return false;
}

bool System_022::isSteamVRDrawingControllers()
{
    return false;
}

bool System_019::shouldApplicationPause()
{
    TRACE();
    return false;
}

bool System_020::shouldApplicationPause()
{
    TRACE();
    return false;
}

bool System_021::shouldApplicationPause()
{
    TRACE();
    return false;
}

bool System_022::shouldApplicationPause()
{
    TRACE();
    return false;
}

bool System_019::shouldApplicationReduceRenderingWork()
{
    return false;
}

bool System_020::shouldApplicationReduceRenderingWork()
{
    return false;
}

bool System_021::shouldApplicationReduceRenderingWork()
{
    return false;
}

bool System_022::shouldApplicationReduceRenderingWork()
{
    return false;
}

uint32_t System_003::driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize)
{
    STUB();
    return 0;
}

uint32_t System_004::driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize)
{
    STUB();
    return 0;
}

uint32_t System_005::driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize)
{
    STUB();
    return 0;
}

uint32_t System_006::driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize)
{
    STUB();
    return 0;
}

uint32_t System_007::driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize)
{
    STUB();
    return 0;
}

uint32_t System_009::driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize)
{
    STUB();
    return 0;
}

uint32_t System_010::driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize)
{
    STUB();
    return 0;
}

uint32_t System_011::driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize)
{
    STUB();
    return 0;
}

uint32_t System_012::driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize)
{
    STUB();
    return 0;
}

uint32_t System_014::driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize)
{
    STUB();
    return 0;
}

uint32_t System_015::driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize)
{
    STUB();
    return 0;
}

uint32_t System_016::driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize)
{
    STUB();
    return 0;
}

uint32_t System_017::driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize)
{
    STUB();
    return 0;
}

uint32_t System_019::driverDebugRequest(uint32_t deviceIndex, const char* request, char* response, uint32_t responseBufferSize)
{
    STUB();
    return 0;
}

FirmwareError System_006::performFirmwareUpdate(uint32_t deviceIndex)
{
    STUB();
    return FirmwareError::FIRMWARE_ERROR_FAIL;
}

FirmwareError System_007::performFirmwareUpdate(uint32_t deviceIndex)
{
    STUB();
    return FirmwareError::FIRMWARE_ERROR_FAIL;
}

FirmwareError System_009::performFirmwareUpdate(uint32_t deviceIndex)
{
    STUB();
    return FirmwareError::FIRMWARE_ERROR_FAIL;
}

FirmwareError System_010::performFirmwareUpdate(uint32_t deviceIndex)
{
    STUB();
    return FirmwareError::FIRMWARE_ERROR_FAIL;
}

FirmwareError System_011::performFirmwareUpdate(uint32_t deviceIndex)
{
    STUB();
    return FirmwareError::FIRMWARE_ERROR_FAIL;
}

FirmwareError System_012::performFirmwareUpdate(uint32_t deviceIndex)
{
    STUB();
    return FirmwareError::FIRMWARE_ERROR_FAIL;
}

FirmwareError System_014::performFirmwareUpdate(uint32_t deviceIndex)
{
    STUB();
    return FirmwareError::FIRMWARE_ERROR_FAIL;
}

FirmwareError System_015::performFirmwareUpdate(uint32_t deviceIndex)
{
    STUB();
    return FirmwareError::FIRMWARE_ERROR_FAIL;
}

FirmwareError System_016::performFirmwareUpdate(uint32_t deviceIndex)
{
    STUB();
    return FirmwareError::FIRMWARE_ERROR_FAIL;
}

FirmwareError System_017::performFirmwareUpdate(uint32_t deviceIndex)
{
    STUB();
    return FirmwareError::FIRMWARE_ERROR_FAIL;
}

FirmwareError System_019::performFirmwareUpdate(uint32_t deviceIndex)
{
    STUB();
    return FirmwareError::FIRMWARE_ERROR_FAIL;
}

FirmwareError System_020::performFirmwareUpdate(uint32_t deviceIndex)
{
    STUB();
    return FirmwareError::FIRMWARE_ERROR_FAIL;
}

FirmwareError System_021::performFirmwareUpdate(uint32_t deviceIndex)
{
    STUB();
    return FirmwareError::FIRMWARE_ERROR_FAIL;
}

FirmwareError System_022::performFirmwareUpdate(uint32_t deviceIndex)
{
    STUB();
    return FirmwareError::FIRMWARE_ERROR_FAIL;
}

void System_009::acknowledgeQuit()
{
    openvr::systemImpl->acknowledgeQuit();
}

void System_010::acknowledgeQuit()
{
    openvr::systemImpl->acknowledgeQuit();
}

void System_011::acknowledgeQuit()
{
    openvr::systemImpl->acknowledgeQuit();
}

void System_012::acknowledgeQuit()
{
    openvr::systemImpl->acknowledgeQuit();
}

void System_014::acknowledgeQuit()
{
    openvr::systemImpl->acknowledgeQuit();
}

void System_015::acknowledgeQuit()
{
    openvr::systemImpl->acknowledgeQuit();
}

void System_016::acknowledgeQuit()
{
    openvr::systemImpl->acknowledgeQuit();
}

void System_017::acknowledgeQuit()
{
    openvr::systemImpl->acknowledgeQuit();
}

void System_019::acknowledgeQuit()
{
    openvr::systemImpl->acknowledgeQuit();
}

void System_020::acknowledgeQuit()
{
    openvr::systemImpl->acknowledgeQuit();
}

void System_021::acknowledgeQuit()
{
    openvr::systemImpl->acknowledgeQuit();
}

void System_022::acknowledgeQuit()
{
    openvr::systemImpl->acknowledgeQuit();
}

void System_009::acknowledgeQuitPrompt()
{
    openvr::systemImpl->acknowledgeQuitPrompt();
}

void System_010::acknowledgeQuitPrompt()
{
    openvr::systemImpl->acknowledgeQuitPrompt();
}

void System_011::acknowledgeQuitPrompt()
{
    openvr::systemImpl->acknowledgeQuitPrompt();
}

void System_012::acknowledgeQuitPrompt()
{
    openvr::systemImpl->acknowledgeQuitPrompt();
}

void System_014::acknowledgeQuitPrompt()
{
    openvr::systemImpl->acknowledgeQuitPrompt();
}

void System_015::acknowledgeQuitPrompt()
{
    openvr::systemImpl->acknowledgeQuitPrompt();
}

void System_016::acknowledgeQuitPrompt()
{
    openvr::systemImpl->acknowledgeQuitPrompt();
}

void System_017::acknowledgeQuitPrompt()
{
    openvr::systemImpl->acknowledgeQuitPrompt();
}

void System_019::acknowledgeQuitPrompt()
{
    openvr::systemImpl->acknowledgeQuitPrompt();
}

void System_020::acknowledgeQuitPrompt()
{
    openvr::systemImpl->acknowledgeQuitPrompt();
}

void System_010::performanceTestEnableCapture(bool enable)
{
    STUB();
}

void System_011::performanceTestEnableCapture(bool enable)
{
    STUB();
}

void System_010::performanceTestReportFidelityLevelChange(int level)
{
    STUB();
}

void System_011::performanceTestReportFidelityLevelChange(int level)
{
    STUB();
}

uint32_t System_020::getAppContainerFilePaths(char* buffer, uint32_t bufferSize)
{
    return openvr::systemImpl->getAppContainerFilePaths(buffer, bufferSize);
}

uint32_t System_021::getAppContainerFilePaths(char* buffer, uint32_t bufferSize)
{
    return openvr::systemImpl->getAppContainerFilePaths(buffer, bufferSize);
}

uint32_t System_022::getAppContainerFilePaths(char* buffer, uint32_t bufferSize)
{
    return openvr::systemImpl->getAppContainerFilePaths(buffer, bufferSize);
}

const char* System_020::getRuntimeVersion()
{
    return openvr::systemImpl->getRuntimeVersion();
}

const char* System_021::getRuntimeVersion()
{
    return openvr::systemImpl->getRuntimeVersion();
}

const char* System_022::getRuntimeVersion()
{
    return openvr::systemImpl->getRuntimeVersion();
}
