#include "ray.h"

Ray::Ray(const Eigen::Vector3f& origin, const Eigen::Vector3f& direction)
    : origin(origin), direction(direction) {}


const Eigen::Vector3f& Ray::getOrigin() const {
    return origin;
}

const Eigen::Vector3f& Ray::getDirection() const {
    return direction;
}

Eigen::Vector3f Ray::at(float t) const {
    return origin + t*direction;
}

// then,  implement virtual rotate (Actually rotate may even not be virtual, it may just be a setter of angles, that are later taken into account in equation resolutions.)
// virtual intersect in shape?