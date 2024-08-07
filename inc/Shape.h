#pragma once
#include "vec.h"
#include <iostream>

class Shape {
protected:
  Vec3f pos;

public:
  virtual bool ray_intersect(const Vec3f &ray, const Vec3f &org, float &l) = 0;
  virtual void talk(float lenght) = 0; // weird name i know
  Shape(const Vec3f &_pos) : pos(_pos){};
};
