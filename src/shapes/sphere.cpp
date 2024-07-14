#include "shapes/sphere.hpp"
#include <math.h>

const float Sphere::DEFAULT_SPHERE_RADIUS = 50;

Sphere::Sphere() : Sphere(DEFAULT_SHAPE_POSITION, DEFAULT_SPHERE_RADIUS) {}

Sphere::Sphere(const Eigen::Vector3f& position, float radius)
    : Shape(position), radius(radius) {}

std::vector<Eigen::Vector3f> Sphere::intersect(const Ray& ray) const {
    std::vector<Eigen::Vector3f> intersections;

    const float& d_x = ray.getDirection().x();
    const float& d_y = ray.getDirection().y();
    const float& d_z = ray.getDirection().z();

    const float& p_0x = ray.getOrigin().x();
    const float& p_0y = ray.getOrigin().y();
    const float& p_0z = ray.getOrigin().z();

    const float& c_x = centerPosition.x();
    const float& c_y = centerPosition.y();
    const float& c_z = centerPosition.z();

    float a = pow(d_x, 2) + pow(d_y, 2) + pow(d_z, 2);
    float b = 2*(d_x*(p_0x-c_x) + d_y*(p_0y-c_y) + d_z*(p_0z-c_z));
    float c = pow(p_0x-c_x, 2) + pow(p_0y-c_y, 2) + pow(p_0z-c_z, 2) - pow(radius, 2);

    float delta = pow(b, 2) - 4*a*c;

    if (delta < 0) {
    } else if (delta == 0) {
        float lambda = -b / (2*a);
        intersections.push_back(ray.getOrigin() + lambda*ray.getDirection());
    } else {
        float lambda_1 = (-b - sqrt(delta)) / (2*a);
        intersections.push_back(ray.getOrigin() + lambda_1*ray.getDirection());
        float lambda_2 = (-b + sqrt(delta)) / (2*a);
        intersections.push_back(ray.getOrigin() + lambda_2*ray.getDirection());
    }

    return intersections;
}
