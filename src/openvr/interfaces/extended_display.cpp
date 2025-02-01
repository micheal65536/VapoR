#include "extended_display.h"
#include "../impl/init.h"
#include "log/stub.h"

using namespace openvr;

void ExtendedDisplay_001::getWindowBounds(int32_t* x, int32_t* y, uint32_t* width, uint32_t* height)
{
    openvr::extendedDisplayImpl->getRenderTargetSize(width, height);
    *x = *y = 0;
    *width *= 2;
}

void ExtendedDisplay_001::getEyeOutputViewport(Eye eye, uint32_t* x, uint32_t* y, uint32_t* width, uint32_t* height)
{
    openvr::extendedDisplayImpl->getRenderTargetSize(width, height);
    *x += eye == Eye::EYE_RIGHT ? *width : 0;
    *y = 0;
}

void ExtendedDisplay_001::getDXGIOutputInfo(int32_t* adapterIndex, int32_t* outputIndex)
{
    STUB();
    *adapterIndex = *outputIndex = -1;
}
