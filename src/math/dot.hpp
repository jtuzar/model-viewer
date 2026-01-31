#include "math/vec.hpp"

namespace mv::math {
float dot(Vec2& a, Vec2& b) {
    return a.x * b.x + a.y * b.y;
}

float dot(Vec3& a, Vec3& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

float dot(Vec4& a, Vec4& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

}  // namespace mv::math
