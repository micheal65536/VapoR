#pragma once

#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>

#include <cstdint>
#include <string>
#include <unordered_map>

#include "log/abort.h"

#define ABORT_ON_OPENGL_ERROR(x) \
    { \
        x; \
        GLenum _e = glGetError(); \
        if (_e != GL_NO_ERROR) \
        { \
            ABORT("OpenGL error (%d)", _e); \
        } \
    }

namespace OpenGL
{
    class ExternalMemory;

    class Texture
    {
        public:
            Texture();
            ~Texture();

            void image(int width, int height, GLenum format, GLenum type, GLint internalFormat, const void* data);
            void getSize(int* width, int* height);
            void attachExternalMemory(int width, int height, GLenum internalFormat, const ExternalMemory& externalMemory, uint64_t memoryOffset);

            GLuint id;
    };

    class Framebuffer
    {
        public:
            Framebuffer(int width, int height);
            ~Framebuffer();

            void bindTexture(const Texture& texture);
            void bindTexture(GLuint textureId);

            GLuint id;

        private:
            GLuint colorRenderbufferId;
            GLuint depthRenderbufferId;
    };

    class ExternalMemory
    {
        public:
            ExternalMemory(int fd, int size);
            ~ExternalMemory();

            GLuint id;

            const int size;
    };

    class AttributeBuffer
    {
        public:
            AttributeBuffer();
            ~AttributeBuffer();

            void data(int size, const void* data);

            GLuint id;
    };

    class VertexAttributeArray
    {
        public:
            VertexAttributeArray();
            ~VertexAttributeArray();

            void attributePointer(int location, int attributeSize, const AttributeBuffer& buffer, int stride, int offset);
            void elementArrayBuffer(const AttributeBuffer& buffer);

            GLuint id;
    };

    class ShaderProgram
    {
        public:
            ShaderProgram(const std::string& vertex, const std::string& fragment);
            ~ShaderProgram();

            void draw(int count);

            void bindUniform(const std::string& name, float value);
            void bindUniform(const std::string& name, float x, float y);
            void bindUniform(const std::string& name, float x, float y, float z);
            void bindUniform(const std::string& name, float x, float y, float z, float w);
            void bindUniform(const std::string& name, const float (&value)[2]);
            void bindUniform(const std::string& name, const float (&value)[3]);
            void bindUniform(const std::string& name, const float (&value)[4]);
            void bindUniform(const std::string& name, int32_t value);
            void bindUniform(const std::string& name, int32_t x, int32_t y);
            void bindUniform(const std::string& name, int32_t x, int32_t y, int32_t z);
            void bindUniform(const std::string& name, int32_t x, int32_t y, int32_t z, int32_t w);
            void bindUniform(const std::string& name, const int32_t (&value)[2]);
            void bindUniform(const std::string& name, const int32_t (&value)[3]);
            void bindUniform(const std::string& name, const int32_t (&value)[4]);
            void bindUniform(const std::string& name, uint32_t value);
            void bindUniform(const std::string& name, uint32_t x, uint32_t y);
            void bindUniform(const std::string& name, uint32_t x, uint32_t y, uint32_t z);
            void bindUniform(const std::string& name, uint32_t x, uint32_t y, uint32_t z, uint32_t w);
            void bindUniform(const std::string& name, const uint32_t (&value)[2]);
            void bindUniform(const std::string& name, const uint32_t (&value)[3]);
            void bindUniform(const std::string& name, const uint32_t (&value)[4]);
            void bindUniform(const std::string& name, const float (&value)[2][2]);
            void bindUniform(const std::string& name, const float (&value)[3][3]);
            void bindUniform(const std::string& name, const float (&value)[4][4]);
            void bindUniform(const std::string& name, const float (&value)[2][3]);
            void bindUniform(const std::string& name, const float (&value)[3][2]);
            void bindUniform(const std::string& name, const float (&value)[2][4]);
            void bindUniform(const std::string& name, const float (&value)[4][2]);
            void bindUniform(const std::string& name, const float (&value)[3][4]);
            void bindUniform(const std::string& name, const float (&value)[4][3]);

            GLuint id;

        private:
            GLuint vertexShaderId;
            GLuint fragmentShaderId;

            template<typename... Ts> void bindUniformInternal(const std::string& name, const Ts& ...values);
            template<typename... Ts> void bindUniformData(GLint location, const Ts& ...values);

            GLint getAttributeLocation(const std::string& name);
            GLint getUniformLocation(const std::string& name);
            std::unordered_map<std::string, GLint> shaderAttributeLocations;
            std::unordered_map<std::string, GLint> shaderUniformLocations;
    };
}
