#pragma once

namespace openvr
{
    namespace utils
    {
        inline float convertXrTimeToSecondsAgo(long timestamp, long now)
        {
            return (float) ((double) (now - timestamp) / 1000000000.0);
        }
    }
}
