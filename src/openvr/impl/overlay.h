#pragma once

#include "../types.h"
#include <cstdint>
#include "client_core.h"

namespace openvr
{
    class OverlayImpl
    {
        public:
            ClientCoreImpl& clientCore;
            OverlayImpl(ClientCoreImpl& clientCore);
            ~OverlayImpl();

            //

            // TODO
    };
}
