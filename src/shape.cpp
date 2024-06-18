#include "shape.h"

Shape::Shape(void) : orientation(Eigen::Vector3d(0, 0, 1)) {}

Cube::Cube(int edgeLength) : edgeLength(edgeLength) {}

Pyramid::Pyramid(int edgeLength) : edgeLength(edgeLength) {}

Coin::Coin(int radius, int height) : radius(radius), height(height) {}

Donut::Donut(int majorRadius, int minorRadius) : majorRadius(majorRadius), minorRadius(minorRadius) {}
