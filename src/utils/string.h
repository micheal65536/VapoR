#pragma once

#include <string>
#include <algorithm>

namespace utils
{
    inline std::string stringToLowercase(const std::string& in)
    {
        std::string out = in;
        std::transform(out.begin(), out.end(), out.begin(), [](char c){ return std::tolower(c); });
        return out;
    }
}
