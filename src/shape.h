#pragma once

class Shape
{};

class Sphere : public Shape
{
private:
    float radius;

public:
    Sphere(float radius);
};

class Cube : public Shape
{
private:
    float edgeLength;

public:
    Cube(float edgeLength);
};

class Pyramid : public Shape
{
private:
    float edgeLength;

public:
    Pyramid(float edgeLegth);
};

class Coin : public Shape
{
private:
    float radius;
    float height;

public:
    Coin(float radius, float height);
};

class Donut : public Shape
{
private:
    float majorRadius;
    float minorRadius;

public:
    Donut(float majorRadius, float minorRadius);
};