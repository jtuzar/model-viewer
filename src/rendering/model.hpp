#pragma once
#include <cstddef>
#include <optional>
#include "assets/mesh.hpp"
#include "rendering/internal/gl_buffer.hpp"
#include "rendering/shader_type.hpp"
#include "rendering/vertex_array.hpp"
class Model {
   public:
    Model(const Mesh& mesh, const ShaderType shaderType);

    void bindForDraw() const;
    std::size_t getIndicesCount() const { return indicesCount_; }
    std::size_t getVerticesCount() const { return verticesCount_; }
    ShaderType getShaderType() const { return shaderType_; }
    bool isIndexed() const { return indicesCount_ != 0; }

   private:
    const std::size_t verticesCount_{0};
    const std::size_t indicesCount_{0};
    const ShaderType shaderType_;
    rendering::GLBuffer vertexBuffer_;
    std::optional<rendering::GLBuffer> elementBuffer_;
    VertexArray vertexArray_;
};
