#pragma once

#include "math/vec.hpp"

using namespace mv::math;

struct Vertex {
    Vec3 position;
    Vec3 normal;
    Vec2 uv;
};

static_assert(std::is_standard_layout_v<Vertex>);
