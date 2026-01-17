#pragma once

#include "assets/vertex.hpp"
#include <span>
#include <glad/gl.h>

class VertexBuffer {
   public:
    explicit VertexBuffer(std::span<const Vertex> data);
    ~VertexBuffer();
    VertexBuffer(const VertexBuffer&) = delete;
    VertexBuffer& operator=(const VertexBuffer&) = delete;

    GLuint getName() { return id_; };

   private:
    unsigned int id_;
};
