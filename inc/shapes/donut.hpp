#pragma once

#include "shape.hpp"

class Donut : public Shape
{
private:
    float majorRadius;
    float minorRadius;

public:
    Donut(const Eigen::Vector3f& position, float majorRadius, float minorRadius);
    std::vector<Eigen::Vector3f> intersect(const Ray& ray) const override;
};
