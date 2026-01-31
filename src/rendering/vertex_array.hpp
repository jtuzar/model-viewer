#pragma once

class VertexArray {
   public:
    VertexArray();

    VertexArray(const VertexArray&) = delete;
    VertexArray& operator=(const VertexArray&) = delete;

    VertexArray(VertexArray&&);
    VertexArray& operator=(VertexArray&&);

    ~VertexArray();

    void bind() const;
    void bindVbo(unsigned int vbo) const;
    void bindEbo(unsigned int ebo) const;
    void setAttribute(unsigned int location,
                      int size,
                      int type,
                      bool normalized,
                      int offset,
                      unsigned int bindingIndex = 0);

   private:
    unsigned int id_{0};
};
