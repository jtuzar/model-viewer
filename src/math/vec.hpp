#pragma once

#include <type_traits>

namespace mv::math {
struct Vec2 {
    float x, y;

    static constexpr unsigned int componentCount = 2;
};

static_assert(std::is_trivially_copy_assignable<Vec2>::value);
static_assert(std::is_trivially_copyable<Vec2>::value);
static_assert(std::is_copy_constructible<Vec2>::value);

struct Vec3 {
    float x, y, z;

    static constexpr unsigned int componentCount = 3;
};

static_assert(std::is_trivially_copy_assignable<Vec3>::value);
static_assert(std::is_trivially_copyable<Vec3>::value);
static_assert(std::is_copy_constructible<Vec3>::value);

struct Vec4 {
    float x, y, z, w;

    static constexpr unsigned int componentCount = 4;
};

static_assert(std::is_trivially_copy_assignable<Vec4>::value);
static_assert(std::is_trivially_copyable<Vec4>::value);
static_assert(std::is_copy_constructible<Vec4>::value);

}  // namespace mv::math
