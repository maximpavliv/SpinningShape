#include "shape_factory.hpp"
#include <set>
#include <iostream>

#include "shapes/sphere.hpp"
#include "shapes/cube.hpp"
#include "shapes/pyramid.hpp"
#include "shapes/coin.hpp"
#include "shapes/donut.hpp"

// Initialize the static instance
ShapeFactory ShapeFactory::instance;

ShapeFactory& ShapeFactory::getInstance() {
    return instance;
}

// Private constructor
ShapeFactory::ShapeFactory() {
    registerCreator("Sphere", []() {
        return std::make_unique<Sphere>();
    });
    registerCreator("Cube", []() {
        return std::make_unique<Cube>();
    });
    registerCreator("Pyramid", []() {
        return std::make_unique<Pyramid>();
    });
    registerCreator("Coin", []() {
        return std::make_unique<Coin>();
    });
    registerCreator("Donut", []() {
        return std::make_unique<Donut>();
    });
}

// Private destructor
ShapeFactory::~ShapeFactory() {}


void ShapeFactory::registerCreator(const std::string& key, CreatorFunc creator) {
    creators[key] = creator;
}

std::set<std::string> ShapeFactory::getValidShapeNames() {
    std::set<std::string> shapes;
    std::transform(creators.begin(), creators.end(), std::inserter(shapes, shapes.end()),
                   [](const std::pair<std::string, CreatorFunc>& pair)
                   { return pair.first; });
    return shapes;
}

std::unique_ptr<Shape> ShapeFactory::createShape(const std::string& key) {
    auto it = creators.find(key);
    if (it != creators.end()) {
        return it->second();
    } else {
        throw std::invalid_argument("Invalid requested shape.");
    }
}
