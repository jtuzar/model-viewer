#include "assets/vertex.hpp"
#include "rendering/vertex_buffer.hpp"
#include <glad/gl.h>
#include <span>

VertexBuffer::VertexBuffer(std::span<const Vertex> vertices) {
    glCreateBuffers(1, &id_);
    glNamedBufferData(id_, vertices.size_bytes(), vertices.data(), GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer() {
    if (id_ > 0)
        glDeleteBuffers(1, &id_);
}

VertexBuffer::VertexBuffer(VertexBuffer&& other) : id_{other.id_} {
    other.id_ = 0;
}

VertexBuffer& VertexBuffer::operator=(VertexBuffer&& other) noexcept {
    if (&other == this)
        return *this;

    if (id_ > 0)
        glDeleteBuffers(1, &id_);

    id_ = other.id_;
    other.id_ = 0;
    return *this;
}
