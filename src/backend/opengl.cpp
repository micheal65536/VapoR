#include "opengl.h"

using namespace OpenGL;

Texture::Texture()
{
    glGenTextures(1, &this->id);
    ABORT_ON_OPENGL_ERROR();
}

Texture::~Texture()
{
    glDeleteTextures(1, &this->id);
    ABORT_ON_OPENGL_ERROR();
}

void Texture::image(int width, int height, GLenum format, GLenum type, GLint internalFormat, const void* data)
{
    GLuint savedTextureId;
    glGetIntegerv(GL_TEXTURE_BINDING_2D, (GLint*) &savedTextureId);
    glBindTexture(GL_TEXTURE_2D, this->id);
    ABORT_ON_OPENGL_ERROR();

    glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, type, data);
    ABORT_ON_OPENGL_ERROR();

    if (savedTextureId != this->id)
    {
        glBindTexture(GL_TEXTURE_2D, savedTextureId);
        ABORT_ON_OPENGL_ERROR();
    }
}

Framebuffer::Framebuffer(int width, int height)
{
    glGenFramebuffers(1, &this->id);
    glGenRenderbuffers(1, &this->colorRenderbufferId);
    glGenRenderbuffers(1, &this->depthRenderbufferId);

    glBindFramebuffer(GL_FRAMEBUFFER, this->id);
    glBindRenderbuffer(GL_RENDERBUFFER, this->colorRenderbufferId);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_RGBA8, width, height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, this->colorRenderbufferId);
    glBindRenderbuffer(GL_RENDERBUFFER, this->depthRenderbufferId);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, this->depthRenderbufferId);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    ABORT_ON_OPENGL_ERROR();
}

Framebuffer::~Framebuffer()
{
    glDeleteFramebuffers(1, &this->id);
    glDeleteRenderbuffers(1, &this->colorRenderbufferId);
    glDeleteRenderbuffers(1, &this->depthRenderbufferId);
    ABORT_ON_OPENGL_ERROR();
}

void Framebuffer::bindTexture(const Texture& texture)
{
    this->bindTexture(texture.id);
}

void Framebuffer::bindTexture(GLuint textureId)
{
    GLuint savedFramebufferId;
    glGetIntegerv(GL_FRAMEBUFFER_BINDING, (GLint*) &savedFramebufferId);
    glBindFramebuffer(GL_FRAMEBUFFER, this->id);
    ABORT_ON_OPENGL_ERROR();

    glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, textureId, 0);
    ABORT_ON_OPENGL_ERROR();

    if (savedFramebufferId != this->id)
    {
        glBindFramebuffer(GL_FRAMEBUFFER, savedFramebufferId);
        ABORT_ON_OPENGL_ERROR();
    }
}
