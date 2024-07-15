#pragma once

#include<eigen3/Eigen/Core>

class SurfacePoint
{
    Eigen::Vector3f position;
    Eigen::Vector3f normal;
public:
    SurfacePoint(const Eigen::Vector3f& position, const Eigen::Vector3f& normal);

    const Eigen::Vector3f& getPosition() const;

    const Eigen::Vector3f& getNormal() const;
};

