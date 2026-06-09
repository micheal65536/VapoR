#include "window_renderer.h"

#include "utils/matrix.h"
#include <cstring>

using namespace vapor::windows;

WindowRenderer::WindowRenderer()
{
    this->shaderProgram = new OpenGL::ShaderProgram(
        "#version 300 es\n"
        "precision highp float;\n"
        "layout(location = 0) in vec3 a_position;\n"
        "layout(location = 1) in vec2 a_uv;\n"
        "uniform mat4 u_projection;\n"
        "uniform mat4 u_eye;\n"
        "uniform mat4 u_head;\n"
        "uniform mat4 u_transform;\n"
        "out vec2 v_uv;\n"
        "void main() {\n"
        "    gl_Position = transpose(u_projection) * vec4((inverse(transpose(u_eye)) * vec4((inverse(transpose(u_head)) * vec4(((transpose(u_transform)) * vec4(a_position, 1.0)).xyz, 1.0)).xyz, 1.0)).xyz, 1.0);\n"
        "    v_uv = a_uv;\n"
        "}",
        "#version 300 es\n"
        "precision highp float;\n"
        "uniform sampler2D u_texture;\n"
        "in vec2 v_uv;\n"
        "void main() {\n"
        "   gl_FragColor = texture(u_texture, v_uv);\n"
        "}"
    );
    this->flatVertices = new OpenGL::AttributeBuffer();
    this->flatVertices->data(sizeof(float) * 20, (float[]) {
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.0f, 1.0f, 1.0f,
        -0.5f, 0.5f, 0.0f, 0.0f, 1.0f
    });
    this->flatIndices = new OpenGL::AttributeBuffer();
    this->flatIndices->data(sizeof(uint32_t) * 6, (uint32_t[]) {0, 1, 2, 0, 2, 3});
    this->flatVAO = new OpenGL::VertexAttributeArray();
    this->flatVAO->attributePointer(0, 3, *this->flatVertices, sizeof(float) * 5, sizeof(float) * 0);
    this->flatVAO->attributePointer(1, 2, *this->flatVertices, sizeof(float) * 5, sizeof(float) * 3);
    this->flatVAO->elementArrayBuffer(*this->flatIndices);
    this->curvedVertices = new OpenGL::AttributeBuffer();
    this->curvedIndices = new OpenGL::AttributeBuffer();
    this->curvedVAO = new OpenGL::VertexAttributeArray();
    this->curvedVAO->attributePointer(0, 3, *this->curvedVertices, sizeof(float) * 5, sizeof(float) * 0);
    this->curvedVAO->attributePointer(1, 2, *this->curvedVertices, sizeof(float) * 5, sizeof(float) * 3);
    this->curvedVAO->elementArrayBuffer(*this->curvedIndices);
}

WindowRenderer::~WindowRenderer()
{
    delete this->shaderProgram;
    delete this->flatVAO;
    delete this->flatVertices;
    delete this->flatIndices;
    delete this->curvedVAO;
    delete this->curvedVertices;
    delete this->curvedIndices;
}

void WindowRenderer::renderFlat(OpenGL::Texture* texture, const float (&headPoseMatrix)[3][4], const OpenXR::View& view, const float (&transformMatrix)[3][4])
{
    // TODO

    float eyeMatrix[4][4];
    float projectionMatrix[4][4];
    utils::poseToMatrix(view.pose, (float (*)[3][4]) &eyeMatrix);
    eyeMatrix[3][0] = 0.0f; eyeMatrix[3][1] = 0.0f; eyeMatrix[3][2] = 0.0f; eyeMatrix[3][3] = 1.0f;
    utils::getProjectionMatrix(view.fov, 0.01f, 100.0f, &projectionMatrix, nullptr, nullptr, nullptr, nullptr);
    float headPoseMatrix4[4][4];
    std::memcpy(headPoseMatrix4, headPoseMatrix, sizeof(float) * 12);
    headPoseMatrix4[3][0] = 0.0f; headPoseMatrix4[3][1] = 0.0f; headPoseMatrix4[3][2] = 0.0f; headPoseMatrix4[3][3] = 1.0f;
    float transformMatrix4[4][4];
    std::memcpy(transformMatrix4, transformMatrix, sizeof(float) * 12);
    transformMatrix4[3][0] = 0.0f; transformMatrix4[3][1] = 0.0f; transformMatrix4[3][2] = 0.0f; transformMatrix4[3][3] = 1.0f;

    this->shaderProgram->bindUniform("u_projection", projectionMatrix);
    this->shaderProgram->bindUniform("u_eye", eyeMatrix);
    this->shaderProgram->bindUniform("u_head", headPoseMatrix4);
    this->shaderProgram->bindUniform("u_transform", transformMatrix4);
    this->shaderProgram->bindUniform("u_texture", 0);

    glBindVertexArray(this->flatVAO->id);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture->id);
    this->shaderProgram->draw(6);
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

/*void WindowRenderer::renderCurved()
{
    // TODO
}*/
