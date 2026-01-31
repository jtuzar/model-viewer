#include <catch2/catch_test_macros.hpp>

#include <type_traits>

#include "math/vec2.hpp"
#include "math/vec3.hpp"
#include "math/vec4.hpp"

TEST_CASE("VecN have expected componentCount") {
    STATIC_REQUIRE(Vec2::componentCount == 2);
    STATIC_REQUIRE(Vec3::componentCount == 3);
    STATIC_REQUIRE(Vec4::componentCount == 4);
}

TEST_CASE("VecN are trivially copyable") {
    STATIC_REQUIRE(std::is_trivially_copyable_v<Vec2>);
    STATIC_REQUIRE(std::is_trivially_copyable_v<Vec3>);
    STATIC_REQUIRE(std::is_trivially_copyable_v<Vec4>);
}

TEST_CASE("VecN have expected size") {
    STATIC_REQUIRE(sizeof(Vec2) == 2 * sizeof(float));
    STATIC_REQUIRE(sizeof(Vec3) == 3 * sizeof(float));
    STATIC_REQUIRE(sizeof(Vec4) == 4 * sizeof(float));
}
