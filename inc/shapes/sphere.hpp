#pragma once

#include "shape.hpp"

class Sphere : public Shape
{
private:
    float radius;

public:
    Sphere(const Eigen::Vector3f& position, float radius);
    std::vector<Eigen::Vector3f> intersect(const Ray& ray) const override;
};
