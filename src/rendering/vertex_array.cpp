#include "rendering/vertex_array.hpp"
#include "rendering/vertex.hpp"
#include <glad/gl.h>
#include <cstddef>

VertexArray::VertexArray(GLuint bufferId) {
    glCreateVertexArrays(1, &id_);

    constexpr GLuint bindingIndex = 0;
    glVertexArrayVertexBuffer(id_, bindingIndex, bufferId, 0, sizeof(Vertex));

    glEnableVertexArrayAttrib(id_, 0);
    glVertexAttribFormat(0, Vertex::Position::componentCount, GL_FLOAT, GL_FALSE, 0);
    glVertexAttribBinding(0, bindingIndex);

    glEnableVertexArrayAttrib(id_, 1);
    glVertexAttribFormat(1, Vertex::UV::componentCount, GL_FLOAT, GL_FALSE, offsetof(Vertex, uv));
    glVertexAttribBinding(1, bindingIndex);
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &id_);
}

void VertexArray::bind() {
    glBindVertexArray(id_);
}
