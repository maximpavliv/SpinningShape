#pragma once

#include <vector>
#include <eigen3/Eigen/Core>
#include <set>
#include "ray.h"

class Shape
{
protected:
    Eigen::Vector3f centerPosition;
    Eigen::Matrix3f rotation;

public:
    Shape(const Eigen::Vector3f& position);

    // Static method to retrieve valid shape names
    static std::set<std::string> getValidShapeNames();

    void rotate(const Eigen::Matrix3f& rotMatrix);

    virtual std::vector<Eigen::Vector3f> intersect(const Ray& ray) const = 0;

    // TODO not sure yet which parameters and if should be pure virtual... from an architectural pov i believe it should
    //virtual Eigen::Vector3f normalAt(void) = 0;
};

class Sphere : public Shape
{
private:
    float radius;

public:
    Sphere(const Eigen::Vector3f& position, float radius);
    std::vector<Eigen::Vector3f> intersect(const Ray& ray) const override;
};

class Cube : public Shape
{
private:
    float edgeLength;

public:
    Cube(const Eigen::Vector3f& position, float edgeLength);
    std::vector<Eigen::Vector3f> intersect(const Ray& ray) const override;
};

class Pyramid : public Shape
{
private:
    float edgeLength;

public:
    Pyramid(const Eigen::Vector3f& position, float edgeLegth);
    std::vector<Eigen::Vector3f> intersect(const Ray& ray) const override;
};

class Coin : public Shape
{
private:
    float radius;
    float height;

public:
    Coin(const Eigen::Vector3f& position, float radius, float height);
    std::vector<Eigen::Vector3f> intersect(const Ray& ray) const override;
};

class Donut : public Shape
{
private:
    float majorRadius;
    float minorRadius;

public:
    Donut(const Eigen::Vector3f& position, float majorRadius, float minorRadius);
    std::vector<Eigen::Vector3f> intersect(const Ray& ray) const override;
};