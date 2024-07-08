#pragma once

#include "shape.hpp"

class Coin : public Shape
{
private:
    float radius;
    float height;

public:
    Coin(const Eigen::Vector3f& position, float radius, float height);
    std::vector<Eigen::Vector3f> intersect(const Ray& ray) const override;
};
