#include "shape.h"

Shape::Shape(const Eigen::Vector3f& position) : centerPosition(position) {}



Sphere::Sphere(const Eigen::Vector3f& position, float radius)
    : Shape(position), radius(radius) {}

Cube::Cube(const Eigen::Vector3f& position, float edgeLength)
    : Shape(position), edgeLength(edgeLength) {}

Pyramid::Pyramid(const Eigen::Vector3f& position, float edgeLength)
    : Shape(position), edgeLength(edgeLength) {}

Coin::Coin(const Eigen::Vector3f& position, float radius, float height)
    : Shape(position), radius(radius), height(height) {}

Donut::Donut(const Eigen::Vector3f& position, float majorRadius, float minorRadius)
    : Shape(position), majorRadius(majorRadius), minorRadius(minorRadius) {}
