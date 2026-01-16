#pragma once

#include <type_traits>

struct Vec4 {
    float x, y, z, w;

    static constexpr unsigned int componentCount = 4;
};

static_assert(std::is_trivially_copy_assignable<Vec4>::value);
static_assert(std::is_trivially_copyable<Vec4>::value);
static_assert(std::is_copy_constructible<Vec4>::value);
