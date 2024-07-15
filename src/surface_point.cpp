#include "surface_point.hpp"

SurfacePoint::SurfacePoint(const Eigen::Vector3f& position, const Eigen::Vector3f& normal)
    : position(position), normal(normal) {}


const Eigen::Vector3f& SurfacePoint::getPosition() const {
    return position;
}

const Eigen::Vector3f& SurfacePoint::getNormal() const {
    return normal;
}
