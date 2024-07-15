#include "shapes/pyramid.hpp"

const float Pyramid::DEFAULT_PYRAMID_EDGE = 10.0;

Pyramid::Pyramid() : Pyramid(DEFAULT_SHAPE_POSITION, DEFAULT_PYRAMID_EDGE) {}

Pyramid::Pyramid(const Eigen::Vector3f& position, float edgeLength)
    : Shape(position), edgeLength(edgeLength) {}

std::vector<SurfacePoint> Pyramid::intersect(const Ray& ray) const {
    std::vector<SurfacePoint> intersections;
    return intersections;
}
