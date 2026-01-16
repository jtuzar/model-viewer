#pragma once

#include <type_traits>

struct Vec2 {
    float x, y;

    static constexpr unsigned int componentCount = 2;
};

static_assert(std::is_trivially_copy_assignable<Vec2>::value);
static_assert(std::is_trivially_copyable<Vec2>::value);
static_assert(std::is_copy_constructible<Vec2>::value);
