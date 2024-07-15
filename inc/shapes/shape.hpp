#pragma once

#include <vector>
#include <eigen3/Eigen/Core>
#include <set>
#include "ray.hpp"
#include "surface_point.hpp"

class Shape
{
protected:
    static const Eigen::Vector3f DEFAULT_SHAPE_POSITION;

    Eigen::Vector3f centerPosition;
    Eigen::Matrix3f rotation;

public:
    Shape(const Eigen::Vector3f& position);

    void rotate(const Eigen::Matrix3f& rotMatrix);

    virtual std::vector<SurfacePoint> intersect(const Ray& ray) const = 0;

    // TODO not sure yet which parameters and if should be pure virtual... from an architectural pov i believe it should
    //virtual Eigen::Vector3f normalAt(void) = 0;
};
