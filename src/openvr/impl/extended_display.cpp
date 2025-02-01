#include "extended_display.h"

using namespace openvr;

ExtendedDisplayImpl::ExtendedDisplayImpl(ClientCoreImpl& clientCore): clientCore(clientCore)
{
    // empty
}

void ExtendedDisplayImpl::getRenderTargetSize(uint32_t* width, uint32_t* height)
{
    *width = this->clientCore.backend->renderWidth;
    *height = this->clientCore.backend->renderHeight;
}
