#pragma once

#include "shape.hpp"

class Pyramid : public Shape
{
private:
    static const float DEFAULT_PYRAMID_EDGE;

    float edgeLength;

public:
    Pyramid();
    Pyramid(const Eigen::Vector3f& position, float edgeLegth);
    std::vector<SurfacePoint> intersect(const Ray& ray) const override;
};
