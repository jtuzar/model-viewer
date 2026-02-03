#include "rendering/renderer.hpp"
#include "rendering/shader_type.hpp"
#include <glad/gl.h>

void Renderer::submit(const Mesh& mesh, const ShaderType shaderType) {
    models_.emplace_back(mesh, shaderType);
}

void Renderer::draw() {
    glClear(GL_COLOR_BUFFER_BIT);

    for (auto& model : models_) {
        shaderRepository_.getShader(model.getShaderType()).use();
        model.bindForDraw();

        if (model.isIndexed()) {
            glDrawElements(GL_TRIANGLES, model.getIndicesCount(), GL_UNSIGNED_INT, nullptr);
        } else {
            glDrawArrays(GL_TRIANGLES, 0, model.getVerticesCount());
        }
    }
}
