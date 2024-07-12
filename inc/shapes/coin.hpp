#pragma once

#include "shape.hpp"

class Coin : public Shape
{
private:
    static const float DEFAULT_COIN_RADIUS;
    static const float DEFAULT_COIN_HEIGHT;

    float radius;
    float height;

public:
    Coin();
    Coin(const Eigen::Vector3f& position, float radius, float height);
    std::vector<Eigen::Vector3f> intersect(const Ray& ray) const override;
};
