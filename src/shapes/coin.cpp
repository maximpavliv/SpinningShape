#include "shapes/coin.hpp"

const float Coin::DEFAULT_COIN_RADIUS = 5.0;
const float Coin::DEFAULT_COIN_HEIGHT = 2.0;

Coin::Coin() : Coin(DEFAULT_SHAPE_POSITION, DEFAULT_COIN_RADIUS, DEFAULT_COIN_HEIGHT) {}

Coin::Coin(const Eigen::Vector3f& position, float radius, float height)
    : Shape(position), radius(radius), height(height) {}

std::vector<SurfacePoint> Coin::intersect(const Ray& ray) const {
    std::vector<SurfacePoint> intersections;
    return intersections;
}
