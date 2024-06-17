#include "shape.h"

Sphere::Sphere(float radius) 
    : radius(radius) {}

Cube::Cube(float edgeLength) 
    : edgeLength(edgeLength) {}

Pyramid::Pyramid(float edgeLength) 
    : edgeLength(edgeLength) {}

Coin::Coin(float radius, float height) 
    : radius(radius), height(height) {}

Donut::Donut(float majorRadius, float minorRadius) 
    : majorRadius(majorRadius), minorRadius(minorRadius) {}
