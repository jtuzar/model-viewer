#include "catch2/catch_test_macros.hpp"
#include "math/vec.hpp"
#include "math/dot.hpp"

using namespace mv::math;

TEST_CASE("Dot product") {
    auto expect_dot = [](auto& a, auto& b, float expected) { REQUIRE(dot(a, b) == expected); };

    auto expect_symmetric = [](auto& a, auto& b) { REQUIRE(dot(a, b) == dot(b, a)); };

    SECTION("Vec2 expected output") {
        Vec2 a{1.0f, 2.0f};
        Vec2 b{3.0f, -1.0f};
        expect_dot(a, b, 1.0f);
    }

    SECTION("Vec3 expected output") {
        Vec3 a{1.0f, 2.0f, -3.0f};
        Vec3 b{4.0f, -1.0f, 2.0f};
        expect_dot(a, b, -4.0f);
    }

    SECTION("Vec4 expected output") {
        Vec4 a{1.0f, -2.0f, 0.5f, 3.0f};
        Vec4 b{2.0f, 4.0f, -1.0f, 0.0f};
        expect_dot(a, b, -6.5f);
    }

    SECTION("Vec2 zeros and orthogonality") {
        Vec2 v2a{0.0f, 0.0f};
        Vec2 v2b{5.0f, -7.0f};
        expect_dot(v2a, v2b, 0.0f);

        Vec2 v2c{1.0f, 0.0f};
        Vec2 v2d{0.0f, 1.0f};
        expect_dot(v2c, v2d, 0.0f);
    }

    SECTION("Vec3 zeros and orthogonality") {
        Vec3 v3a{0.0f, 0.0f, 0.0f};
        Vec3 v3b{1.0f, 2.0f, 3.0f};
        expect_dot(v3a, v3b, 0.0f);

        Vec3 v3c{1.0f, 0.0f, 0.0f};
        Vec3 v3d{0.0f, -2.0f, 0.0f};
        expect_dot(v3c, v3d, 0.0f);
    }

    SECTION("Vec4 zeros and orthogonality") {
        Vec4 v4a{0.0f, 0.0f, 0.0f, 0.0f};
        Vec4 v4b{1.0f, -1.0f, 2.0f, -2.0f};
        expect_dot(v4a, v4b, 0.0f);
    }

    SECTION("Symmetry") {
        Vec2 v2a{1.5f, -2.0f};
        Vec2 v2b{-3.0f, 4.5f};
        expect_symmetric(v2a, v2b);

        Vec3 v3a{2.0f, -1.0f, 0.5f};
        Vec3 v3b{4.0f, 3.0f, -2.0f};
        expect_symmetric(v3a, v3b);

        Vec4 v4a{1.0f, 2.0f, 3.0f, 4.0f};
        Vec4 v4b{-1.0f, 0.5f, -2.0f, 3.0f};
        expect_symmetric(v4a, v4b);
    }

    SECTION("Self dot equals squared length") {
        Vec2 v2{3.0f, 4.0f};
        expect_dot(v2, v2, 25.0f);

        Vec3 v3{1.0f, -2.0f, 2.0f};
        expect_dot(v3, v3, 9.0f);

        Vec4 v4{0.5f, -1.0f, 2.0f, -2.5f};
        expect_dot(v4, v4, 11.5f);
    }
}
