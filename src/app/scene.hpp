#pragma once

#include "assets/mesh.hpp"
#include "rendering/renderer.hpp"
class Scene {
   public:
    enum SceneName { defaultScene };

    Scene(SceneName sceneName, Mesh& mesh) : sceneName_{sceneName}, mesh_{std::move(mesh)} {};

    void render(Renderer& renderer) const;

   private:
    SceneName sceneName_;
    Mesh mesh_;
};
