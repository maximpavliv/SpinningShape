#include "shapes/pyramid.hpp"

Pyramid::Pyramid(const Eigen::Vector3f& position, float edgeLength)
    : Shape(position), edgeLength(edgeLength) {}

std::vector<Eigen::Vector3f> Pyramid::intersect(const Ray& ray) const {
    std::vector<Eigen::Vector3f> intersections;
    return intersections;
}
