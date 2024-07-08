#pragma once

#include "shape.hpp"

class Cube : public Shape
{
private:
    float edgeLength;

public:
    Cube(const Eigen::Vector3f& position, float edgeLength);
    std::vector<Eigen::Vector3f> intersect(const Ray& ray) const override;
};
