#pragma once

#include "openvr/types_geometry.h"

#include <cstring>

namespace openvr
{
    namespace utils
    {
        inline void multiplyMatrix(const float (&lhs)[3][4], float (&rhs)[3][4])
        {
            float temp[4];
            temp[0] = lhs[0][0] * rhs[0][0] + lhs[1][0] * rhs[0][1] + lhs[2][0] * rhs[0][2];
            temp[1] = lhs[0][1] * rhs[0][0] + lhs[1][1] * rhs[0][1] + lhs[2][1] * rhs[0][2];
            temp[2] = lhs[0][2] * rhs[0][0] + lhs[1][2] * rhs[0][1] + lhs[2][2] * rhs[0][2];
            temp[3] = lhs[0][3] * rhs[0][0] + lhs[1][3] * rhs[0][1] + lhs[2][3] * rhs[0][2] + rhs[0][3];
            rhs[0][0] = temp[0];
            rhs[0][1] = temp[1];
            rhs[0][2] = temp[2];
            rhs[0][3] = temp[3];
            temp[0] = lhs[0][0] * rhs[1][0] + lhs[1][0] * rhs[1][1] + lhs[2][0] * rhs[1][2];
            temp[1] = lhs[0][1] * rhs[1][0] + lhs[1][1] * rhs[1][1] + lhs[2][1] * rhs[1][2];
            temp[2] = lhs[0][2] * rhs[1][0] + lhs[1][2] * rhs[1][1] + lhs[2][2] * rhs[1][2];
            temp[3] = lhs[0][3] * rhs[1][0] + lhs[1][3] * rhs[1][1] + lhs[2][3] * rhs[1][2] + rhs[1][3];
            rhs[1][0] = temp[0];
            rhs[1][1] = temp[1];
            rhs[1][2] = temp[2];
            rhs[1][3] = temp[3];
            temp[0] = lhs[0][0] * rhs[2][0] + lhs[1][0] * rhs[2][1] + lhs[2][0] * rhs[2][2];
            temp[1] = lhs[0][1] * rhs[2][0] + lhs[1][1] * rhs[2][1] + lhs[2][1] * rhs[2][2];
            temp[2] = lhs[0][2] * rhs[2][0] + lhs[1][2] * rhs[2][1] + lhs[2][2] * rhs[2][2];
            temp[3] = lhs[0][3] * rhs[2][0] + lhs[1][3] * rhs[2][1] + lhs[2][3] * rhs[2][2] + rhs[2][3];
            rhs[2][0] = temp[0];
            rhs[2][1] = temp[1];
            rhs[2][2] = temp[2];
            rhs[2][3] = temp[3];
        }

        inline void multiplyMatrixVector(const float (&lhs)[3][4], float (&rhs)[3], float w)
        {
            float temp[3];
            temp[0] = lhs[0][0] * rhs[0] + lhs[0][1] * rhs[1] + lhs[0][2] * rhs[2] + lhs[0][3] * w;
            temp[1] = lhs[1][0] * rhs[0] + lhs[1][1] * rhs[1] + lhs[1][2] * rhs[2] + lhs[1][3] * w;
            temp[2] = lhs[2][0] * rhs[0] + lhs[2][1] * rhs[1] + lhs[2][2] * rhs[2] + lhs[2][3] * w;
            rhs[0] = temp[0];
            rhs[1] = temp[1];
            rhs[2] = temp[2];
        }
    }
}
