#include "shapes/cube.hpp"

Cube::Cube(const Eigen::Vector3f& position, float edgeLength)
    : Shape(position), edgeLength(edgeLength) {}

std::vector<Eigen::Vector3f> Cube::intersect(const Ray& ray) const {
    std::vector<Eigen::Vector3f> intersections;
    return intersections;
}
