#pragma once

#include <eigen3/Eigen/Core>

class Shape
{
protected:
    Eigen::Vector3f centerPosition;

public:
    Shape(const Eigen::Vector3f& position);
};

class Sphere : public Shape
{
private:
    float radius;

public:
    Sphere(const Eigen::Vector3f& position, float radius);
};

class Cube : public Shape
{
private:
    float edgeLength;

public:
    Cube(const Eigen::Vector3f& position, float edgeLength);
};

class Pyramid : public Shape
{
private:
    float edgeLength;

public:
    Pyramid(const Eigen::Vector3f& position, float edgeLegth);
};

class Coin : public Shape
{
private:
    float radius;
    float height;

public:
    Coin(const Eigen::Vector3f& position, float radius, float height);
};

class Donut : public Shape
{
private:
    float majorRadius;
    float minorRadius;

public:
    Donut(const Eigen::Vector3f& position, float majorRadius, float minorRadius);
};