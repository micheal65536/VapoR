#pragma once

#include "backend/openxr.h"

#include <cmath>

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

    inline void poseToMatrix(const XrPosef& pose, float (*rhs)[3][4])
    {
        XrVector3f position = pose.position;
        XrQuaternionf orientation = pose.orientation;

        float w = orientation.w;
        float x = orientation.x;
        float y = orientation.y;
        float z = orientation.z;

        float x2 = x + x;
        float y2 = y + y;
        float z2 = z + z;

        float xx2 = x * x2;
        float yy2 = y * y2;
        float zz2 = z * z2;

        float yz2 = y * z2;
        float wx2 = w * x2;
        float xy2 = x * y2;
        float wz2 = w * z2;
        float xz2 = x * z2;
        float wy2 = w * y2;

        float (*m)[4] = *rhs;
        m[0][0] = 1.0f - yy2 - zz2; m[0][1] = xy2 - wz2;        m[0][2] = xz2 + wy2;        m[0][3] = position.x;
        m[1][0] = xy2 + wz2;        m[1][1] = 1.0f - xx2 - zz2; m[1][2] = yz2 - wx2;        m[1][3] = position.y;
        m[2][0] = xz2 - wy2;        m[2][1] = yz2 + wx2;        m[2][2] = 1.0f - xx2 - yy2; m[2][3] = position.z;
    }

    inline void getProjectionMatrix(const XrFovf& fov, float near, float far, float (*matrix)[4][4], float* left, float* right, float* top, float* bottom)
    {
        float _left, _right, _top, _bottom;
        if (left == nullptr) { left = &_left; }
        if (right == nullptr) { right = &_right; }
        if (top == nullptr) { top = &_top; }
        if (bottom == nullptr) { bottom = &_bottom; }
        *left = std::tan(fov.angleLeft);
        *right = std::tan(fov.angleRight);
        // NOTE: I know this looks backwards but it seems to match ALVR and SteamVR native
        *top = std::tan(fov.angleDown);
        *bottom = std::tan(fov.angleUp);

        if (matrix != nullptr)
        {
            float idx = 1.0f / (*right - *left);
            float idy = 1.0f / (*bottom - *top);
            float idz = 1.0f / (far - near);
            float sx = *right + *left;
            float sy = *bottom + *top;

            float (*m)[4] = *matrix;
            m[0][0] = 2.0f * idx; m[0][1] = 0.0f;       m[0][2] = sx * idx;   m[0][3] = 0.0f;
            m[1][0] = 0.0f;       m[1][1] = 2.0f * idy; m[1][2] = sy * idy;   m[1][3] = 0.0f;
            m[2][0] = 0.0f;       m[2][1] = 0.0f;       m[2][2] = -far * idz; m[2][3] = -far * near * idz;
            m[3][0] = 0.0f;       m[3][1] = 0.0f;       m[3][2] = -1.0f;      m[3][3] = 0.0f;
        }
    }
}
