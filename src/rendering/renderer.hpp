#pragma once

#include <vector>
#include "assets/mesh.hpp"
#include "rendering/model.hpp"
#include "rendering/opengl_context.hpp"
#include "rendering/shader_repository.hpp"
#include "rendering/shader_type.hpp"

class Renderer {
   public:
    explicit Renderer(const OpenGlContext&) {};

    void submit(const Mesh& mesh, const ShaderType shaderType);
    void draw();

   private:
    std::vector<Model> models_;
    rendering::ShaderRepository shaderRepository_;
};
