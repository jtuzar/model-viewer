#include <vector>
#include "assets/mesh.hpp"
#include "rendering/model.hpp"
#include "rendering/opengl_context.hpp"
#include "rendering/shader_program.hpp"

class Renderer {
   public:
    explicit Renderer(const OpenGlContext&) {};

    void submit(const Mesh& mesh, const ShaderProgram* const shaderProgram);
    void draw() const;

   private:
    std::vector<Model> models_;
};
