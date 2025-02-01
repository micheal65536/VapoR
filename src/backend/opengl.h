#pragma once

#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>

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
    class Texture
    {
        public:
            Texture();
            ~Texture();

            void image(int width, int height, GLenum format, GLenum type, GLint internalFormat, const void* data);

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
}
