#include "shapes/cube.hpp"

const float Cube::DEFAULT_CUBE_EDGE = 10.0;

Cube::Cube() : Cube(DEFAULT_SHAPE_POSITION, DEFAULT_CUBE_EDGE) {}

Cube::Cube(const Eigen::Vector3f& position, float edgeLength)
    : Shape(position), edgeLength(edgeLength) {}

std::vector<Eigen::Vector3f> Cube::intersect(const Ray& ray) const {
    std::vector<Eigen::Vector3f> intersections;
    return intersections;
}
