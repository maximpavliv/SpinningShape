#include "shapes/coin.hpp"

Coin::Coin(const Eigen::Vector3f& position, float radius, float height)
    : Shape(position), radius(radius), height(height) {}

std::vector<Eigen::Vector3f> Coin::intersect(const Ray& ray) const {
    std::vector<Eigen::Vector3f> intersections;
    return intersections;
}
