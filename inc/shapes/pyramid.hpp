#pragma once

#include "shape.hpp"

class Pyramid : public Shape
{
private:
    float edgeLength;

public:
    Pyramid(const Eigen::Vector3f& position, float edgeLegth);
    std::vector<Eigen::Vector3f> intersect(const Ray& ray) const override;
};
