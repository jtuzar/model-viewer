#include "rendering/vertex_array.hpp"
#include "rendering/vertex.hpp"
#include <glad/gl.h>
#include <cstddef>

VertexArray::VertexArray(GLuint bufferId) {
    glCreateVertexArrays(1, &id_);

    constexpr GLuint bindingIndex = 0;
    glVertexArrayVertexBuffer(id_, bindingIndex, bufferId, 0, sizeof(Vertex));

    glEnableVertexArrayAttrib(id_, 0);
    glVertexArrayAttribFormat(id_, 0, Vertex::Position::componentCount, GL_FLOAT, GL_FALSE, 0);
    glVertexArrayAttribBinding(id_, 0, bindingIndex);

    glEnableVertexArrayAttrib(id_, 1);
    glVertexArrayAttribFormat(id_, 1, Vertex::UV::componentCount, GL_FLOAT, GL_FALSE,
                              offsetof(Vertex, uv));
    glVertexArrayAttribBinding(id_, 1, bindingIndex);
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &id_);
}

void VertexArray::bind() {
    glBindVertexArray(id_);
}
