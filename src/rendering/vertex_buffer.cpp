#include "assets/vertex.hpp"
#include "rendering/vertex_buffer.hpp"
#include <glad/gl.h>
#include <span>

VertexBuffer::VertexBuffer(std::span<const Vertex> vertices) {
    glCreateBuffers(1, &id_);
    glNamedBufferData(id_, vertices.size_bytes(), vertices.data(), GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &id_);
}
