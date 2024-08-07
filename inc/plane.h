#include "Shape.h"
#include "vec.h"
#include <cmath>

class plane : public Shape {
private:
  Vec3f normal;

public:
  plane(const Vec3f &_pos, const Vec3f &_normal)
      : Shape(_pos), normal(_normal){};

  bool ray_intersect(const Vec3f &ray, const Vec3f &org, float &l) override {

    float denominator = normal * ray;

    if (std::abs(denominator) > 0) {

      Vec3f differenceOrg = pos - org;

      float numerator = normal * differenceOrg;

      float t = numerator / denominator;

      if (t > 1e-3)
        l = ((ray * t) + org).norm();

      return t > 1e-3;
    }

    return false;
  };

  void talk(float lenght) override {
    std::cout << "I am plane" << "\n"
              << "I'm  at " << lenght << " units \n";
  };
};
