#include "shapes/sphere.hpp"

const float Sphere::DEFAULT_SPHERE_RADIUS = 50;

Sphere::Sphere() : Sphere(DEFAULT_SHAPE_POSITION, DEFAULT_SPHERE_RADIUS) {}

Sphere::Sphere(const Eigen::Vector3f& position, float radius)
    : Shape(position), radius(radius) {}

std::vector<Eigen::Vector3f> Sphere::intersect(const Ray& ray) const {
    std::vector<Eigen::Vector3f> intersections;
    return intersections;
}
