#pragma once

#include "shape.hpp"

class Cube : public Shape
{
private:
    static const float DEFAULT_CUBE_EDGE;

    float edgeLength;

public:
    Cube();
    Cube(const Eigen::Vector3f& position, float edgeLength);
    std::vector<Eigen::Vector3f> intersect(const Ray& ray) const override;
};
