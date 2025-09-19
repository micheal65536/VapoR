#pragma once

#include <cstdint>
#include <compare>
#include <cmath>

namespace vapor
{
    namespace input
    {
        enum class InputType
        {
            EMPTY, // for input state which is currently inactive/blocked
            DIGITAL,
            ANALOG,
            POSE,
            SKELETON,
            HAPTIC
        };

        struct InputState
        {
            struct Analog
            {
                float x;
                float y;
                float z;

                inline std::partial_ordering operator<=>(const Analog& rhs) const
                {
                    return std::sqrt(x * x + y * y + z * z) <=> std::sqrt(rhs.x * rhs.x + rhs.y * rhs.y + rhs.z * rhs.z);
                }
            };

            union Data
            {
                bool digital;
                Analog analog;
            };

            InputType type;
            Data data;
            uint64_t inputSourceHandle;
            long changeTime;
        };
    }
}
