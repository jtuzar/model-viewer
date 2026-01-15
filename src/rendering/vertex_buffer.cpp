#include "vertex_buffer.hpp"
#include <glad/gl.h>
#include <vector>

VertexBuffer::VertexBuffer(const std::vector<float>* data) {
    glCreateBuffers(1, &id_);
    glNamedBufferData(id_, data->size() * sizeof(float), data->data(), GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer() {
    unbind();
    glDeleteBuffers(1, &id_);
}

void VertexBuffer::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, id_);
}

void VertexBuffer::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
