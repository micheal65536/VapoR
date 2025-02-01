#pragma once

namespace openvr
{
    struct Matrix33
    {
        float m[3][3];
    };

    struct Matrix34
    {
        float m[3][4];
    };

    struct Matrix44
    {
        float m[4][4];
    };

    struct Vector2
    {
        float v[2];
    };

    struct Vector3
    {
        float v[3];
    };

    struct Vector4
    {
        float v[4];
    };

    struct Vector3d
    {
        double v[3];
    };

    struct Quaternionf
    {
        float w;
        float x;
        float y;
        float z;
    };

    struct Quaterniond
    {
        double w;
        double x;
        double y;
        double z;
    };

    struct Color
    {
        float r;
        float g;
        float b;
        float a;
    };

    struct Quad
    {
        Vector3 corners[4];
    };

    struct Rect
    {
        Vector2 topLeft;
        Vector2 bottomRight;
    };
}
