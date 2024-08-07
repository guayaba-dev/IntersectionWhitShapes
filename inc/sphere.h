#include "Shape.h"
#include "vec.h"
#include <cmath>
#include <iostream>

class sphere : public Shape {
private:
  float radius;

public:
  sphere(const Vec3f &_pos, const float &_radius)
      : Shape(_pos), radius(_radius){};

  bool ray_intersect(const Vec3f &ray, const Vec3f &org, float &l) override {

    Vec3f h = pos - org;

    float tca = h * ray;

    float d2 = h * h - tca * tca;

    if (d2 > radius * radius)
      return false;

    float thc = sqrtf(radius * radius - d2);

    l = tca - thc;

    float t1 = tca + thc;

    if (l < 0)
      l = t1;

    if (l < 0)
      return false;

    return true;
  };

  void talk(float lenght) override {
    std::cout << "I am sphere" << "\n"
              << "I'm  at " << lenght << " units \n";
  };
};
