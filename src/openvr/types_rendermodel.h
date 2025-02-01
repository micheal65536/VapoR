#pragma once

#include <cstdint>

#include "types_geometry.h"

namespace openvr
{
    enum RenderModelError
    {
        RENDER_MODEL_ERROR_NONE = 0,
        RENDER_MODEL_ERROR_LOADING = 100,
        RENDER_MODEL_ERROR_NOT_SUPPORTED = 200,
        RENDER_MODEL_ERROR_INVALID_ARG = 300,
        RENDER_MODEL_ERROR_INVALID_MODEL = 301,
        RENDER_MODEL_ERROR_BUFFER_TOO_SMALL = 306,
        RENDER_MODEL_ERROR_INVALID_TEXTURE = 400
    };

    struct RenderModelVertex
    {
        Vector3 position;
        Vector3 normal;
        float uv[2];
    };

    struct RenderModel_0_9_0
    {
        struct Texture
        {
            uint16_t width;
            uint16_t height;
            uint8_t* data;
        };

        uint64_t internalHandle;
        RenderModelVertex* vertices;
        uint32_t vertexCount;
        uint16_t* indices;
        uint32_t triangleCount;
        Texture texture;
    };

#if defined(__linux__) || defined(__APPLE__)
#pragma pack(push, 4)
#endif
    struct RenderModel_0_9_12
    {
        RenderModelVertex* vertices;
        uint32_t vertexCount;
        uint16_t* indices;
        uint32_t triangleCount;
        int32_t textureId;
    };
#if defined(__linux__) || defined(__APPLE__)
#pragma pack(pop)
#endif

    enum RenderModelTextureFormat
    {
        RENDER_MODEL_TEXTURE_FORMAT_RGBA8_SRGB = 0,
        RENDER_MODEL_TEXTURE_FORMAT_BC2 = 1,
        RENDER_MODEL_TEXTURE_FORMAT_BC4 = 2,
        RENDER_MODEL_TEXTURE_FORMAT_BC7 = 3,
        RENDER_MODEL_TEXTURE_FORMAT_BC7_SRGB = 4,
        RENDER_MODEL_TEXTURE_FORMAT_RGBA16_FLOAT = 5
    };

#if defined(__linux__) || defined(__APPLE__)
#pragma pack(push, 4)
#endif
    struct RenderModelTextureMap
    {
        uint16_t width;
        uint16_t height;
        uint8_t* data;
        RenderModelTextureFormat format;
        uint16_t mipLevels;
    };
#if defined(__linux__) || defined(__APPLE__)
#pragma pack(pop)
#endif

    struct RenderModelComponentState
    {
        enum ComponentProperty
        {
	        STATIC = 0x01,
	        VISIBLE = 0x02,
	        TOUCHED = 0x04,
	        PRESSED = 0x08,
	        SCROLLED = 0x10,
	        HIGHLIGHTED = 0x20
        };

        Matrix34 renderTransform;
        Matrix34 localSpaceTransform;
        int32_t properties;
    };

    struct RenderModelControllerModeState
    {
        bool scrollWheelVisible;
    };
}
