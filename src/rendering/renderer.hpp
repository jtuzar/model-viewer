#include <vector>
#include "assets/mesh.hpp"
#include "rendering/model.hpp"
#include "rendering/opengl_context.hpp"
#include "rendering/shader_program.hpp"

class Renderer {
   public:
    explicit Renderer(const OpenGlContext&) {};

    void submit(const Mesh&, const ShaderProgram&);
    void draw() const;

   private:
    std::vector<Model> models_;
};
