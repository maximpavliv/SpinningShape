#include "shapes/donut.hpp"

Donut::Donut(const Eigen::Vector3f& position, float majorRadius, float minorRadius)
    : Shape(position), majorRadius(majorRadius), minorRadius(minorRadius) {}

std::vector<Eigen::Vector3f> Donut::intersect(const Ray& ray) const {
    std::vector<Eigen::Vector3f> intersections;
    return intersections;
}
