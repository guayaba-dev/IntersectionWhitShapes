#include "inc/Shape.h"
#include "inc/plane.h"
#include "inc/sphere.h"
#include "inc/triangle.h"
#include <iostream>
#include <limits>
#include <vector>

int main(int argc, char *argv[]) {

  std::vector<Shape *> figures;

  figures.push_back(new plane(Vec3f(1, 2, 1), Vec3f(1, 2, 1)));
  figures.push_back(new sphere(Vec3f(-1, 8, 1), 4.f));
  figures.push_back(
      new triangle({Vec3f(-3, 4, -2), Vec3f(0, 4, 3), Vec3f(2, 4, -2)}));

  float nearestLenght = std::numeric_limits<float>::max();

  Shape *nearestFigure{nullptr};

  for (auto &i : figures) {
    float currentLenght{0};
    if (i->ray_intersect(Vec3f(0.f, 1.f, 0.f), Vec3f(0, 0, 0), currentLenght)) {
      if (currentLenght <= nearestLenght) {
        nearestLenght = currentLenght;
        nearestFigure = i;
      }
    }
  }

  if (nearestFigure)
    nearestFigure->talk(nearestLenght);
  else
    std::cout << "no intersection" << "\n";

  return 0;
}
