#pragma once

#include <span>
#include "assets/vertex.hpp"

namespace rendering {

class GLBuffer {
   public:
    GLBuffer() = default;
    GLBuffer(const GLBuffer&) = delete;
    GLBuffer& operator=(const GLBuffer&) = delete;
    GLBuffer(GLBuffer&&);
    GLBuffer& operator=(GLBuffer&&) noexcept;
    ~GLBuffer();

    unsigned int getName() const noexcept { return id_; }

    void create(std::size_t sizeBytes, const void* data, unsigned int usage);

   private:
    unsigned int id_{};
};

GLBuffer createVbo(const std::span<const Vertex> vertices, unsigned int usage);
GLBuffer createEbo(const std::span<const unsigned int> indices, unsigned int usage);
}  // namespace rendering
