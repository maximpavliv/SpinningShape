#pragma once

#include "shape.hpp"

class Donut : public Shape
{
private:
    static const float DEFAULT_DONUT_MAJOR_RADIUS;
    static const float DEFAULT_DONUT_MINOR_RADIUS;

    float majorRadius;
    float minorRadius;

public:
    Donut();
    Donut(const Eigen::Vector3f& position, float majorRadius, float minorRadius);
    std::vector<SurfacePoint> intersect(const Ray& ray) const override;
};
