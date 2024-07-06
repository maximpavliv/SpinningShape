#include "shape.h"

Shape::Shape(const Eigen::Vector3f& position) : centerPosition(position) {}

void Shape::rotate(const Eigen::Matrix3f& rotMatrix) {
    rotation = rotMatrix * rotation;
}


Sphere::Sphere(const Eigen::Vector3f& position, float radius)
    : Shape(position), radius(radius) {}

std::vector<Eigen::Vector3f> Sphere::intersect(const Ray& ray) const {
    std::vector<Eigen::Vector3f> intersections;
    return intersections;
}

Cube::Cube(const Eigen::Vector3f& position, float edgeLength)
    : Shape(position), edgeLength(edgeLength) {}

std::vector<Eigen::Vector3f> Cube::intersect(const Ray& ray) const {
    std::vector<Eigen::Vector3f> intersections;
    return intersections;
}

Pyramid::Pyramid(const Eigen::Vector3f& position, float edgeLength)
    : Shape(position), edgeLength(edgeLength) {}

std::vector<Eigen::Vector3f> Pyramid::intersect(const Ray& ray) const {
    std::vector<Eigen::Vector3f> intersections;
    return intersections;
}

Coin::Coin(const Eigen::Vector3f& position, float radius, float height)
    : Shape(position), radius(radius), height(height) {}

std::vector<Eigen::Vector3f> Coin::intersect(const Ray& ray) const {
    std::vector<Eigen::Vector3f> intersections;
    return intersections;
}

Donut::Donut(const Eigen::Vector3f& position, float majorRadius, float minorRadius)
    : Shape(position), majorRadius(majorRadius), minorRadius(minorRadius) {}

std::vector<Eigen::Vector3f> Donut::intersect(const Ray& ray) const {
    std::vector<Eigen::Vector3f> intersections;
    return intersections;
}
