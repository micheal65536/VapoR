#include "opengl.h"

#include <GL/glx.h>
#include <GL/glext.h>

using namespace OpenGL;

//

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

void Texture::getSize(int* width, int* height)
{
    GLuint savedTextureId;
    glGetIntegerv(GL_TEXTURE_BINDING_2D, (GLint*) &savedTextureId);
    glBindTexture(GL_TEXTURE_2D, this->id);
    ABORT_ON_OPENGL_ERROR();

    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, width);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, height);
    ABORT_ON_OPENGL_ERROR();

    if (savedTextureId != this->id)
    {
        glBindTexture(GL_TEXTURE_2D, savedTextureId);
        ABORT_ON_OPENGL_ERROR();
    }
}

void Texture::attachExternalMemory(int width, int height, GLenum internalFormat, const ExternalMemory& externalMemory, uint64_t memoryOffset)
{
    GLuint savedTextureId;
    glGetIntegerv(GL_TEXTURE_BINDING_2D, (GLint*) &savedTextureId);
    glBindTexture(GL_TEXTURE_2D, this->id);
    ABORT_ON_OPENGL_ERROR();

    glTextureParameteri(this->id, GL_TEXTURE_TILING_EXT, GL_OPTIMAL_TILING_EXT);
    ABORT_ON_OPENGL_ERROR();

    PFNGLTEXSTORAGEMEM2DEXTPROC glTexStorageMem2DEXT = (PFNGLTEXSTORAGEMEM2DEXTPROC) glXGetProcAddress((const GLubyte*) "glTexStorageMem2DEXT");
    glTexStorageMem2DEXT(GL_TEXTURE_2D, 1, internalFormat, width, height, externalMemory.id, memoryOffset);
    ABORT_ON_OPENGL_ERROR();

    if (savedTextureId != this->id)
    {
        glBindTexture(GL_TEXTURE_2D, savedTextureId);
        ABORT_ON_OPENGL_ERROR();
    }
}

//

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

//

ExternalMemory::ExternalMemory(int fd, int size): size(size)
{
    PFNGLCREATEMEMORYOBJECTSEXTPROC glCreateMemoryObjectsEXT = (PFNGLCREATEMEMORYOBJECTSEXTPROC) glXGetProcAddress((const GLubyte*) "glCreateMemoryObjectsEXT");
    glCreateMemoryObjectsEXT(1, &this->id);
    ABORT_ON_OPENGL_ERROR();

    PFNGLMEMORYOBJECTPARAMETERIVEXTPROC glMemoryObjectParameterivEXT = (PFNGLMEMORYOBJECTPARAMETERIVEXTPROC) glXGetProcAddress((const GLubyte*) "glMemoryObjectParameterivEXT");
    GLint param = GL_TRUE;
    glMemoryObjectParameterivEXT(this->id, GL_DEDICATED_MEMORY_OBJECT_EXT, &param);
    ABORT_ON_OPENGL_ERROR();

    PFNGLIMPORTMEMORYFDEXTPROC glImportMemoryFdEXT = (PFNGLIMPORTMEMORYFDEXTPROC) glXGetProcAddress((const GLubyte*) "glImportMemoryFdEXT");
    glImportMemoryFdEXT(this->id, size, GL_HANDLE_TYPE_OPAQUE_FD_EXT, fd);
    ABORT_ON_OPENGL_ERROR();
}

ExternalMemory::~ExternalMemory()
{
    PFNGLDELETEMEMORYOBJECTSEXTPROC glDeleteMemoryObjectsEXT = (PFNGLDELETEMEMORYOBJECTSEXTPROC) glXGetProcAddress((const GLubyte*) "glDeleteMemoryObjectsEXT");
    glDeleteMemoryObjectsEXT(1, &this->id);
    ABORT_ON_OPENGL_ERROR();
}

//

AttributeBuffer::AttributeBuffer()
{
    glGenBuffers(1, &this->id);
    ABORT_ON_OPENGL_ERROR();
}

AttributeBuffer::~AttributeBuffer()
{
    glDeleteBuffers(1, &this->id);
    ABORT_ON_OPENGL_ERROR();
}

void AttributeBuffer::data(int size, const void* data)
{
    GLuint savedBufferId;
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, (GLint*) &savedBufferId);
    glBindBuffer(GL_ARRAY_BUFFER, this->id);
    ABORT_ON_OPENGL_ERROR();

    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    ABORT_ON_OPENGL_ERROR();

    if (savedBufferId != this->id)
    {
        glBindBuffer(GL_ARRAY_BUFFER, savedBufferId);
        ABORT_ON_OPENGL_ERROR();
    }
}

//

VertexAttributeArray::VertexAttributeArray()
{
    glGenVertexArrays(1, &this->id);
    ABORT_ON_OPENGL_ERROR();
}

VertexAttributeArray::~VertexAttributeArray()
{
    glDeleteVertexArrays(1, &this->id);
    ABORT_ON_OPENGL_ERROR();
}

void VertexAttributeArray::attributePointer(int location, int attributeSize, const AttributeBuffer& buffer, int stride, int offset)
{
    GLuint savedVertexAttributeArrayId;
    GLuint savedBufferId;
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, (GLint*) &savedVertexAttributeArrayId);
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, (GLint*) &savedBufferId);
    glBindVertexArray(this->id);
    glBindBuffer(GL_ARRAY_BUFFER, buffer.id);
    ABORT_ON_OPENGL_ERROR();

    glEnableVertexAttribArray(location);
    glVertexAttribPointer(location, attributeSize, GL_FLOAT, GL_FALSE, stride, (void*) offset);
    ABORT_ON_OPENGL_ERROR();

    if (savedBufferId != buffer.id)
    {
        glBindBuffer(GL_ARRAY_BUFFER, savedBufferId);
        ABORT_ON_OPENGL_ERROR();
    }
    if (savedVertexAttributeArrayId != this->id)
    {
        glBindVertexArray(savedVertexAttributeArrayId);
        ABORT_ON_OPENGL_ERROR();
    }
}

void VertexAttributeArray::elementArrayBuffer(const AttributeBuffer& buffer)
{
    GLuint savedVertexAttributeArrayId;
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, (GLint*) &savedVertexAttributeArrayId);
    glBindVertexArray(this->id);
    ABORT_ON_OPENGL_ERROR();

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer.id);
    ABORT_ON_OPENGL_ERROR();

    if (savedVertexAttributeArrayId != this->id)
    {
        glBindVertexArray(savedVertexAttributeArrayId);
        ABORT_ON_OPENGL_ERROR();
    }
}

//

ShaderProgram::ShaderProgram(const std::string& vertex, const std::string& fragment)
{
    this->vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(this->vertexShaderId, 1, (const char*[]) {vertex.c_str()}, nullptr);
    glCompileShader(this->vertexShaderId);
    ABORT_ON_OPENGL_ERROR();
    this->fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(this->fragmentShaderId, 1, (const char*[]) {fragment.c_str()}, nullptr);
    glCompileShader(this->fragmentShaderId);
    ABORT_ON_OPENGL_ERROR();
    this->id = glCreateProgram();
    glAttachShader(this->id, this->vertexShaderId);
    glAttachShader(this->id, this->fragmentShaderId);
    glLinkProgram(this->id);
    ABORT_ON_OPENGL_ERROR();

    GLint status;
    glGetShaderiv(this->vertexShaderId, GL_COMPILE_STATUS, &status);
    if (status != GL_TRUE)
    {
        GLint length;
        glGetShaderiv(this->vertexShaderId, GL_INFO_LOG_LENGTH, &length);
        char log[length];
        glGetShaderInfoLog(this->vertexShaderId, length, nullptr, log);
        TRACE_F("Vertex shader compilation failed: %s", log);
        ABORT();
    }
    glGetShaderiv(this->fragmentShaderId, GL_COMPILE_STATUS, &status);
    if (status != GL_TRUE)
    {
        GLint length;
        glGetShaderiv(this->fragmentShaderId, GL_INFO_LOG_LENGTH, &length);
        char log[length];
        glGetShaderInfoLog(this->fragmentShaderId, length, nullptr, log);
        TRACE_F("Fragment shader compilation failed: %s", log);
        ABORT();
    }
    glGetProgramiv(this->id, GL_LINK_STATUS, &status);
    if (status != GL_TRUE)
    {
        GLint length;
        glGetProgramiv(this->id, GL_INFO_LOG_LENGTH, &length);
        char log[length];
        glGetProgramInfoLog(this->id, length, nullptr, log);
        TRACE_F("Program link compilation failed: %s", log);
        ABORT();
    }
    ABORT_ON_OPENGL_ERROR();
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(this->id);
    glDeleteShader(this->vertexShaderId);
    glDeleteShader(this->fragmentShaderId);
    ABORT_ON_OPENGL_ERROR();
}

void ShaderProgram::draw(int count)
{
    GLuint savedProgramId;
    glGetIntegerv(GL_CURRENT_PROGRAM, (GLint*) &savedProgramId);
    glUseProgram(this->id);
    ABORT_ON_OPENGL_ERROR();

    glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, (void*) 0);
    ABORT_ON_OPENGL_ERROR();

    if (savedProgramId != this->id)
    {
        glUseProgram(savedProgramId);
        ABORT_ON_OPENGL_ERROR();
    }
}

void ShaderProgram::bindUniform(const std::string& name, float value)
{
    bindUniformInternal(name, value);
}

void ShaderProgram::bindUniform(const std::string& name, float x, float y)
{
    bindUniformInternal(name, x, y);
}

void ShaderProgram::bindUniform(const std::string& name, float x, float y, float z)
{
    bindUniformInternal(name, x, y, z);
}

void ShaderProgram::bindUniform(const std::string& name, float x, float y, float z, float w)
{
    bindUniformInternal(name, x, y, z, w);
}

void ShaderProgram::bindUniform(const std::string& name, const float (&value)[2])
{
    bindUniformInternal(name, value);
}

void ShaderProgram::bindUniform(const std::string& name, const float (&value)[3])
{
    bindUniformInternal(name, value);
}

void ShaderProgram::bindUniform(const std::string& name, const float (&value)[4])
{
    bindUniformInternal(name, value);
}

void ShaderProgram::bindUniform(const std::string& name, int32_t value)
{
    bindUniformInternal(name, value);
}

void ShaderProgram::bindUniform(const std::string& name, int32_t x, int32_t y)
{
    bindUniformInternal(name, x, y);
}

void ShaderProgram::bindUniform(const std::string& name, int32_t x, int32_t y, int32_t z)
{
    bindUniformInternal(name, x, y, z);
}

void ShaderProgram::bindUniform(const std::string& name, int32_t x, int32_t y, int32_t z, int32_t w)
{
    bindUniformInternal(name, x, y, z, w);
}

void ShaderProgram::bindUniform(const std::string& name, const int32_t (&value)[2])
{
    bindUniformInternal(name, value);
}

void ShaderProgram::bindUniform(const std::string& name, const int32_t (&value)[3])
{
    bindUniformInternal(name, value);
}

void ShaderProgram::bindUniform(const std::string& name, const int32_t (&value)[4])
{
    bindUniformInternal(name, value);
}

void ShaderProgram::bindUniform(const std::string& name, uint32_t value)
{
    bindUniformInternal(name, value);
}

void ShaderProgram::bindUniform(const std::string& name, uint32_t x, uint32_t y)
{
    bindUniformInternal(name, x, y);
}

void ShaderProgram::bindUniform(const std::string& name, uint32_t x, uint32_t y, uint32_t z)
{
    bindUniformInternal(name, x, y, z);
}

void ShaderProgram::bindUniform(const std::string& name, uint32_t x, uint32_t y, uint32_t z, uint32_t w)
{
    bindUniformInternal(name, x, y, z, w);
}

void ShaderProgram::bindUniform(const std::string& name, const uint32_t (&value)[2])
{
    bindUniformInternal(name, value);
}

void ShaderProgram::bindUniform(const std::string& name, const uint32_t (&value)[3])
{
    bindUniformInternal(name, value);
}

void ShaderProgram::bindUniform(const std::string& name, const uint32_t (&value)[4])
{
    bindUniformInternal(name, value);
}

void ShaderProgram::bindUniform(const std::string& name, const float (&value)[2][2])
{
    bindUniformInternal(name, value);
}

void ShaderProgram::bindUniform(const std::string& name, const float (&value)[3][3])
{
    bindUniformInternal(name, value);
}

void ShaderProgram::bindUniform(const std::string& name, const float (&value)[4][4])
{
    bindUniformInternal(name, value);
}

void ShaderProgram::bindUniform(const std::string& name, const float (&value)[2][3])
{
    bindUniformInternal(name, value);
}

void ShaderProgram::bindUniform(const std::string& name, const float (&value)[3][2])
{
    bindUniformInternal(name, value);
}

void ShaderProgram::bindUniform(const std::string& name, const float (&value)[2][4])
{
    bindUniformInternal(name, value);
}

void ShaderProgram::bindUniform(const std::string& name, const float (&value)[4][2])
{
    bindUniformInternal(name, value);
}

void ShaderProgram::bindUniform(const std::string& name, const float (&value)[3][4])
{
    bindUniformInternal(name, value);
}

void ShaderProgram::bindUniform(const std::string& name, const float (&value)[4][3])
{
    bindUniformInternal(name, value);
}

template<typename... Ts> void ShaderProgram::bindUniformInternal(const std::string& name, const Ts& ...values)
{
    GLuint savedProgramId;
    glGetIntegerv(GL_CURRENT_PROGRAM, (GLint*) &savedProgramId);
    glUseProgram(this->id);
    ABORT_ON_OPENGL_ERROR();

    GLint location = getUniformLocation(name);
    bindUniformData<Ts...>(location, values...);
    ABORT_ON_OPENGL_ERROR();

    if (savedProgramId != this->id)
    {
        glUseProgram(savedProgramId);
        ABORT_ON_OPENGL_ERROR();
    }
}

template<> void ShaderProgram::bindUniformData(GLint location, const float& value)
{
    glUniform1f(location, value);
}

template<> void ShaderProgram::bindUniformData(GLint location, const float& x, const float& y)
{
    glUniform2f(location, x, y);
}

template<> void ShaderProgram::bindUniformData(GLint location, const float& x, const float& y, const float& z)
{
    glUniform3f(location, x, y, z);
}

template<> void ShaderProgram::bindUniformData(GLint location, const float& x, const float& y, const float& z, const float& w)
{
    glUniform4f(location, x, y, z, w);
}

template<> void ShaderProgram::bindUniformData(GLint location, const float (&value)[2])
{
    glUniform2fv(location, 1, value);
}

template<> void ShaderProgram::bindUniformData(GLint location, const float (&value)[3])
{
    glUniform3fv(location, 1, value);
}

template<> void ShaderProgram::bindUniformData(GLint location, const float (&value)[4])
{
    glUniform4fv(location, 1, value);
}

template<> void ShaderProgram::bindUniformData(GLint location, const int32_t& value)
{
    glUniform1i(location, value);
}

template<> void ShaderProgram::bindUniformData(GLint location, const int32_t& x, const int32_t& y)
{
    glUniform2i(location, x, y);
}

template<> void ShaderProgram::bindUniformData(GLint location, const int32_t& x, const int32_t& y, const int32_t& z)
{
    glUniform3i(location, x, y, z);
}

template<> void ShaderProgram::bindUniformData(GLint location, const int32_t& x, const int32_t& y, const int32_t& z, const int32_t& w)
{
    glUniform4i(location, x, y, z, w);
}

template<> void ShaderProgram::bindUniformData(GLint location, const int32_t (&value)[2])
{
    glUniform2iv(location, 1, value);
}

template<> void ShaderProgram::bindUniformData(GLint location, const int32_t (&value)[3])
{
    glUniform3iv(location, 1, value);
}

template<> void ShaderProgram::bindUniformData(GLint location, const int32_t (&value)[4])
{
    glUniform4iv(location, 1, value);
}

template<> void ShaderProgram::bindUniformData(GLint location, const uint32_t& value)
{
    glUniform1ui(location, value);
}

template<> void ShaderProgram::bindUniformData(GLint location, const uint32_t& x, const uint32_t& y)
{
    glUniform2ui(location, x, y);
}

template<> void ShaderProgram::bindUniformData(GLint location, const uint32_t& x, const uint32_t& y, const uint32_t& z)
{
    glUniform3ui(location, x, y, z);
}

template<> void ShaderProgram::bindUniformData(GLint location, const uint32_t& x, const uint32_t& y, const uint32_t& z, const uint32_t& w)
{
    glUniform4ui(location, x, y, z, w);
}

template<> void ShaderProgram::bindUniformData(GLint location, const uint32_t (&value)[2])
{
    glUniform2uiv(location, 1, value);
}

template<> void ShaderProgram::bindUniformData(GLint location, const uint32_t (&value)[3])
{
    glUniform3uiv(location, 1, value);
}

template<> void ShaderProgram::bindUniformData(GLint location, const uint32_t (&value)[4])
{
    glUniform4uiv(location, 1, value);
}

template<> void ShaderProgram::bindUniformData(GLint location, const float (&value)[2][2])
{
    glUniformMatrix2fv(location, 1, GL_FALSE, (const float*) (const void*) value);
}

template<> void ShaderProgram::bindUniformData(GLint location, const float (&value)[3][3])
{
    glUniformMatrix3fv(location, 1, GL_FALSE, (const float*) (const void*) value);
}

template<> void ShaderProgram::bindUniformData(GLint location, const float (&value)[4][4])
{
    glUniformMatrix4fv(location, 1, GL_FALSE, (const float*) (const void*) value);
}

template<> void ShaderProgram::bindUniformData(GLint location, const float (&value)[2][3])
{
    glUniformMatrix2x3fv(location, 1, GL_FALSE, (const float*) (const void*) value);
}

template<> void ShaderProgram::bindUniformData(GLint location, const float (&value)[3][2])
{
    glUniformMatrix3x2fv(location, 1, GL_FALSE, (const float*) (const void*) value);
}

template<> void ShaderProgram::bindUniformData(GLint location, const float (&value)[2][4])
{
    glUniformMatrix2x4fv(location, 1, GL_FALSE, (const float*) (const void*) value);
}

template<> void ShaderProgram::bindUniformData(GLint location, const float (&value)[4][2])
{
    glUniformMatrix4x2fv(location, 1, GL_FALSE, (const float*) (const void*) value);
}

template<> void ShaderProgram::bindUniformData(GLint location, const float (&value)[3][4])
{
    glUniformMatrix3x4fv(location, 1, GL_FALSE, (const float*) (const void*) value);
}

template<> void ShaderProgram::bindUniformData(GLint location, const float (&value)[4][3])
{
    glUniformMatrix4x3fv(location, 1, GL_FALSE, (const float*) (const void*) value);
}

GLint ShaderProgram::getAttributeLocation(const std::string& name)
{
    auto it = shaderAttributeLocations.find(name);
    if (it != shaderAttributeLocations.end())
    {
        return it->second;
    }
    GLint location = glGetAttribLocation(this->id, name.c_str());
    ABORT_ON_OPENGL_ERROR();
    shaderAttributeLocations[name] = location;
    return location;
}

GLint ShaderProgram::getUniformLocation(const std::string& name)
{
    auto it = shaderUniformLocations.find(name);
    if (it != shaderUniformLocations.end())
    {
        return it->second;
    }
    GLint location = glGetUniformLocation(this->id, name.c_str());
    ABORT_ON_OPENGL_ERROR();
    shaderUniformLocations[name] = location;
    return location;
}
