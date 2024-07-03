#pragma once

#include<eigen3/Eigen/Core>

class Ray
{
private:
    // the ray is parametrized by the following equation:
    // P(t) = origin + t*direction
    Eigen::Vector3f origin;
    Eigen::Vector3f direction;
public:
    Ray(const Eigen::Vector3f& origin, const Eigen::Vector3f& direction);

    const Eigen::Vector3f& getOrigin() const;

    const Eigen::Vector3f& getDirection() const;

    Eigen::Vector3f at(float t) const;
};

