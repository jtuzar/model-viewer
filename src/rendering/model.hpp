#pragma once
#include "assets/mesh.hpp"
#include "rendering/internal/gl_buffer.hpp"
#include "rendering/shader_program.hpp"
#include "rendering/vertex_array.hpp"
class Model {
   public:
    Model(const Mesh&, ShaderProgram);

    void makeActive() const;
    unsigned long getIndicesCount() const { return indicesCount_; }
    unsigned long getVerticesCount() const { return verticesCount_; }

   private:
    unsigned long verticesCount_, indicesCount_;
    ShaderProgram shaderProgram_;
    rendering::GLBuffer vertexBuffer_;
    rendering::GLBuffer elementBuffer_;
    VertexArray vertexArray_;
};
