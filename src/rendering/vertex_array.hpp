#pragma once

class VertexArray {
   public:
    explicit VertexArray(unsigned int vbo, unsigned int ebo);

    VertexArray(const VertexArray&) = delete;
    VertexArray& operator=(const VertexArray&) = delete;

    VertexArray(VertexArray&&);
    VertexArray& operator=(VertexArray&&);

    ~VertexArray();

    void bind();

   private:
    unsigned int id_{};
};
