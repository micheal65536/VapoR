#pragma once

#include <cstdint>
#include "client_core.h"

namespace openvr
{
    class ExtendedDisplayImpl
    {
        public:
            ClientCoreImpl& clientCore;
            ExtendedDisplayImpl(ClientCoreImpl& clientCore);

            //

            void getRenderTargetSize(uint32_t* width, uint32_t* height);
    };
}
