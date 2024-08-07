#pragma once
#include <cmath>

struct Vec3f {
  float x, y, z = 0;

  Vec3f(float const &_x, const float &_y, const float &_z)
      : x(_x), y(_y), z(_z){};

  Vec3f() = default;

  float operator*(const Vec3f &other) const {
    return (x * other.x + y * other.y + z * other.z);
  }

  Vec3f operator*(const float &k) const { return Vec3f(x * k, y * k, z * k); }

  Vec3f operator-(const Vec3f &other) const {
    return Vec3f(x - other.x, y - other.y, z - other.z);
  }

  Vec3f operator+(const Vec3f &other) const {
    return Vec3f(x + other.x, y + other.y, z + other.z);
  }

  Vec3f cross(const Vec3f &B) const {
    // Cross product "formula" just use variables and u'll see what is this
    return Vec3f(y * B.z - B.y * z, B.x * z - B.z * x, x * B.y - y * B.x);
  }

  float norm() { return sqrtf(x * x + y * y + z * z); }
};
