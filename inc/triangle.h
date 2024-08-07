#include "Shape.h"
#include "vec.h"
#include <array>
#include <iostream>
#include <vector>

class triangle : public Shape {
private:
  // A[0] B[1] C[2]
  std::array<Vec3f, 3> vertices;

  float trianglePointArea(const Vec3f point) const {

    float total = 0;

    // ACP
    total += (point - vertices[2]).cross(point - vertices[0]).norm() * .5;

    // CBP
    total += (point - vertices[1]).cross(point - vertices[2]).norm() * .5;

    // ABP
    total += (point - vertices[0]).cross(point - vertices[1]).norm() * .5;

    return total;
  }

public:
  triangle(const std::array<Vec3f, 3> _vertex) : Shape(Vec3f(0, 0, 0)) {
    // no se si Dios perdone la canallada que estoy haciendo
    for (size_t i = 0; i < 3; i++) {
      vertices[i] = _vertex[i];
    }
  };

  bool ray_intersect(const Vec3f &ray, const Vec3f &org, float &l) override {

    // Plane intersection

    Vec3f normal = (vertices[1] - vertices[0]).cross(vertices[2] - vertices[0]);

    float denominator = normal * ray;

    if (std::abs(denominator) == 0)
      return false;

    Vec3f differenceOrg = vertices[0] - pos;

    float numerator = normal * differenceOrg;

    float t = numerator / denominator;

    if (t < 1e-3)
      return false;

    Vec3f point = (ray * t) + org;

    // triangle intersection

    if (trianglePointArea(point) > normal.norm() * .5)
      return false;

    l = ((ray * t) + org).norm();

    return true;
  }

  void talk(float lenght) override {
    std::cout << "I am triangle" << "\n"
              << "I'm  at " << lenght << " units \n";
  };
};
