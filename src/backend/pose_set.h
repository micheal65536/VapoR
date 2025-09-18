#pragma once

#include <string>

#include "openxr.h"

namespace vapor
{
    struct PoseSet
    {
        OpenXR::PoseAndVelocity local;
        OpenXR::PoseAndVelocity localFloor;
        OpenXR::PoseAndVelocity localNextFrame;
        OpenXR::PoseAndVelocity localFloorNextFrame;

        float offsetMatrix[3][4];
    };
}
