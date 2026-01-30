#include "rendering/internal/gl_buffer.hpp"
#include <glad/gl.h>
#include <cstddef>

namespace rendering {
GLBuffer::~GLBuffer() {
    if (id_ > 0)
        glDeleteBuffers(1, &id_);
}

GLBuffer::GLBuffer(GLBuffer&& other) : id_{other.id_} {
    other.id_ = 0;
}

GLBuffer& GLBuffer::operator=(GLBuffer&& other) noexcept {
    if (&other == this)
        return *this;

    if (id_ > 0)
        glDeleteBuffers(1, &id_);

    id_ = other.id_;
    other.id_ = 0;
    return *this;
}

void GLBuffer::create(std::size_t sizeBytes, const void* data, unsigned int usage) {
    glCreateBuffers(1, &id_);
    glNamedBufferData(id_, static_cast<GLsizeiptr>(sizeBytes), data, usage);
}

GLBuffer createVbo(const std::span<const Vertex> vertices, unsigned int usage) {
    GLBuffer buffer = GLBuffer{};
    buffer.create(vertices.size_bytes(), vertices.data(), usage);
    return buffer;
}

GLBuffer createEbo(const std::span<const unsigned int> indices, unsigned int usage) {
    GLBuffer buffer = GLBuffer{};
    buffer.create(indices.size_bytes(), indices.data(), usage);
    return buffer;
}

}  // namespace rendering
