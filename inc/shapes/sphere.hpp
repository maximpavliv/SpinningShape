#pragma once

#include "shape.hpp"

class Sphere : public Shape
{
private:
    static const float DEFAULT_SPHERE_RADIUS;

    float radius;

public:
    Sphere();
    Sphere(const Eigen::Vector3f& position, float radius);
    std::vector<Eigen::Vector3f> intersect(const Ray& ray) const override;
};
