#include "app/scene.hpp"
#include "rendering/shader_type.hpp"

void Scene::render(Renderer& renderer) const {
    renderer.submit(mesh_, ShaderType::basic);
}
