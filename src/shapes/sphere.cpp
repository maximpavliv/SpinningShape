#include "shapes/sphere.hpp"

Sphere::Sphere(const Eigen::Vector3f& position, float radius)
    : Shape(position), radius(radius) {}

std::vector<Eigen::Vector3f> Sphere::intersect(const Ray& ray) const {
    std::vector<Eigen::Vector3f> intersections;
    return intersections;
}
