#pragma once

#include "../types.h"
#include <cstdint>

#include "../impl/extended_display.h"

namespace openvr
{
    struct ExtendedDisplay_001
    {
        static void getWindowBounds(int32_t* x, int32_t* y, uint32_t* width, uint32_t* height);
        static void getEyeOutputViewport(Eye eye, uint32_t* x, uint32_t* y, uint32_t* width, uint32_t* height);

        static void getDXGIOutputInfo(int32_t* adapterIndex, int32_t* outputIndex);
    
        void* getWindowBounds_ = (void*) getWindowBounds;
        void* getEyeOutputViewport_ = (void*) getEyeOutputViewport;
        void* getDXGIOutputInfo_ = (void*) getDXGIOutputInfo;
    };

    class ExtendedDisplay_001_v
    {
        public:
            virtual void getWindowBounds(int32_t* x, int32_t* y, uint32_t* width, uint32_t* height) { return ExtendedDisplay_001::getWindowBounds(x, y, width, height); }
            virtual void getEyeOutputViewport(Eye eye, uint32_t* x, uint32_t* y, uint32_t* width, uint32_t* height) { return ExtendedDisplay_001::getEyeOutputViewport(eye, x, y, width, height); }
            virtual void getDXGIOutputInfo(int32_t* adapterIndex, int32_t* outputIndex) { return ExtendedDisplay_001::getDXGIOutputInfo(adapterIndex, outputIndex); }
    };
}
