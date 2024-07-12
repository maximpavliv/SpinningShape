#include "shapes/shape.hpp"

const Eigen::Vector3f Shape::DEFAULT_SHAPE_POSITION(0.0, 0.0, 200.0);

Shape::Shape(const Eigen::Vector3f& position) : centerPosition(position) {}

void Shape::rotate(const Eigen::Matrix3f& rotMatrix) {
    rotation = rotMatrix * rotation;
}
