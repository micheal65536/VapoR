#include "overlay.h"
#include "log/log.h"
#include "log/stub.h"

using namespace openvr;

OverlayImpl::OverlayImpl(ClientCoreImpl& clientCore): clientCore(clientCore)
{
    // empty
}

OverlayImpl::~OverlayImpl()
{
    // TODO
}
