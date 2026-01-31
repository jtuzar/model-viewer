#include "assets/vertex.hpp"
#include "rendering/vertex_array.hpp"
#include <glad/gl.h>

VertexArray::VertexArray() {
    glCreateVertexArrays(1, &id_);
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

void VertexArray::bind() const {
    glBindVertexArray(id_);
}

void VertexArray::bindVbo(unsigned int vbo) const {
    glVertexArrayVertexBuffer(id_, 0, vbo, 0, sizeof(Vertex));
}

void VertexArray::bindEbo(unsigned int ebo) const {
    glVertexArrayElementBuffer(id_, ebo);
}

void VertexArray::setAttribute(unsigned int location,
                               int size,
                               int type,
                               bool normalized,
                               int offset,
                               unsigned int bindingIndex) {
    glEnableVertexArrayAttrib(id_, location);
    glVertexArrayAttribFormat(id_, location, size, type, normalized, offset);
    glVertexArrayAttribBinding(id_, location, bindingIndex);
}
