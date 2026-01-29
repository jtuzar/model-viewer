#include "assets/vertex.hpp"
#include "rendering/vertex_array.hpp"
#include <glad/gl.h>
#include <cstddef>

VertexArray::VertexArray(unsigned int bufferId) {
    glCreateVertexArrays(1, &id_);

    constexpr unsigned int bindingIndex = 0;
    glVertexArrayVertexBuffer(id_, bindingIndex, bufferId, 0, sizeof(Vertex));

    glEnableVertexArrayAttrib(id_, 0);
    glVertexArrayAttribFormat(id_, 0, Vertex::Position::componentCount, GL_FLOAT, GL_FALSE, 0);
    glVertexArrayAttribBinding(id_, 0, bindingIndex);

    glEnableVertexArrayAttrib(id_, 1);
    glVertexArrayAttribFormat(id_, 1, Vertex::UV::componentCount, GL_FLOAT, GL_FALSE,
                              offsetof(Vertex, uv));
    glVertexArrayAttribBinding(id_, 1, bindingIndex);
}

VertexArray::VertexArray(VertexArray&& other) : id_{other.id_} {
    other.id_ = 0;
}
VertexArray& VertexArray::operator=(VertexArray&& other) {
    if (&other == this)
        return *this;

    if (id_ > 0)
        glDeleteVertexArrays(1, &id_);

    id_ = other.id_;
    other.id_ = 0;

    return *this;
}

VertexArray::~VertexArray() {
    if (id_ > 0)
        glDeleteVertexArrays(1, &id_);
}

void VertexArray::bind() {
    glBindVertexArray(id_);
}
