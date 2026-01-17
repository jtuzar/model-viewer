#pragma once

#include "math/vec2.hpp"
#include "math/vec3.hpp"

struct Vertex {
    using UV = Vec2;
    using Position = Vec3;
    Position position;
    UV uv;
};
