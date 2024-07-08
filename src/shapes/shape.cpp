#include "shapes/shape.hpp"

Shape::Shape(const Eigen::Vector3f& position) : centerPosition(position) {}

std::set<std::string> Shape::getValidShapeNames() {
    std::set<std::string> valid_shapes;
    valid_shapes.insert("Sphere");
    valid_shapes.insert("Cube");
    valid_shapes.insert("Pyramid");
    valid_shapes.insert("Coin");
    valid_shapes.insert("Donut");
    return valid_shapes;
}

void Shape::rotate(const Eigen::Matrix3f& rotMatrix) {
    rotation = rotMatrix * rotation;
}