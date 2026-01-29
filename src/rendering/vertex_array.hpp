#pragma once

class VertexArray {
   public:
    explicit VertexArray(unsigned int bufferId);

    VertexArray(const VertexArray&) = delete;
    VertexArray& operator=(const VertexArray&) = delete;

    VertexArray(VertexArray&&);
    VertexArray& operator=(VertexArray&&);

    ~VertexArray();

    void bind();

   private:
    unsigned int id_;
    unsigned int enabled_attrib_count_{0};
};
