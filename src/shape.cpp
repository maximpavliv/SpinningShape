#include "shape.h"

Cube::Cube(int edgeLength) : edgeLength(edgeLength) {}

Pyramid::Pyramid(int edgeLength) : edgeLength(edgeLength) {}

Coin::Coin(int radius, int height) : radius(radius), height(height) {}

Donut::Donut(int majorRadius, int minorRadius) : majorRadius(majorRadius), minorRadius(minorRadius) {}
