#pragma once

#include "assets/vertex.hpp"
#include <span>

class VertexBuffer {
   public:
    explicit VertexBuffer(std::span<const Vertex> data);
    VertexBuffer(const VertexBuffer&) = delete;
    VertexBuffer& operator=(const VertexBuffer&) = delete;
    VertexBuffer(VertexBuffer&&);
    VertexBuffer& operator=(VertexBuffer&&) noexcept;
    ~VertexBuffer();

    unsigned int getName() { return id_; };

   private:
    unsigned int id_;
};
