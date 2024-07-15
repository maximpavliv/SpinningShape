#include "shapes/donut.hpp"

const float Donut::DEFAULT_DONUT_MAJOR_RADIUS = 5.0;
const float Donut::DEFAULT_DONUT_MINOR_RADIUS = 1.0;

Donut::Donut() : Donut(DEFAULT_SHAPE_POSITION, DEFAULT_DONUT_MAJOR_RADIUS,
                        DEFAULT_DONUT_MINOR_RADIUS) {}

Donut::Donut(const Eigen::Vector3f& position, float majorRadius, float minorRadius)
    : Shape(position), majorRadius(majorRadius), minorRadius(minorRadius) {}

std::vector<SurfacePoint> Donut::intersect(const Ray& ray) const {
    std::vector<SurfacePoint> intersections;
    return intersections;
}
