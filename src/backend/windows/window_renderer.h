#pragma once

#include "backend/opengl.h"
#include "backend/openxr.h"
#include <cstdint>

namespace vapor
{
    namespace windows
    {
        class WindowRenderer
        {
            public:
                WindowRenderer();
                ~WindowRenderer();

                void renderFlat(OpenGL::Texture* texture, const float (&textureBounds)[4], const float (&headPoseMatrix)[3][4], const OpenXR::View& view, float widthInMeters, float aspectRatio, const float (&transformMatrix)[3][4], float alpha);
                //void renderCurved();

            private:
                OpenGL::ShaderProgram* flatShaderProgram;
                OpenGL::AttributeBuffer* flatVertices;
                OpenGL::AttributeBuffer* flatIndices;
                OpenGL::VertexAttributeArray* flatVAO;

                OpenGL::AttributeBuffer* curvedVertices;
                OpenGL::AttributeBuffer* curvedIndices;
                OpenGL::VertexAttributeArray* curvedVAO;
        };
    }
}
