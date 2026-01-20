#pragma once

#include <type_traits>

struct Vec3 {
    float x{};
    float y{};
    float z{};

    static constexpr unsigned int componentCount = 3;
};

static_assert(std::is_trivially_copy_assignable<Vec3>::value);
static_assert(std::is_trivially_copyable<Vec3>::value);
static_assert(std::is_copy_constructible<Vec3>::value);
