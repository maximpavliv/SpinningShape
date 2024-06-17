#pragma once

class Shape
{};

class Cube : public Shape
{
private:
    int edgeLength;

public:
    Cube(int edgeLength);
};

class Pyramid : public Shape
{
private:
    int edgeLength;

public:
    Pyramid(int edgeLegth);
};

class Coin : public Shape
{
private:
    int radius;
    int height;

public:
    Coin(int radius, int height);
};

class Donut : public Shape
{
private:
    int majorRadius;
    int minorRadius;

public:
    Donut(int majorRadius, int minorRadius);
};