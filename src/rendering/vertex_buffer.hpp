#pragma once

#include <vector>
class VertexBuffer {
   public:
    explicit VertexBuffer(const std::vector<float>* data);
    ~VertexBuffer();
    VertexBuffer(const VertexBuffer&) = delete;
    VertexBuffer& operator=(const VertexBuffer&) = delete;

    void bind();
    void unbind();

   private:
    unsigned int id_;
};
