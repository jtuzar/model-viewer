#pragma once

#include <glm/glm.hpp>
#include <type_traits>

struct Vertex {
    glm::vec3 position{};
    glm::vec3 normal{};
    glm::vec3 uv{};
};

static_assert(std::is_standard_layout_v<Vertex>);
