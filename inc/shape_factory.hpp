#pragma once

//#include <map>
//#include <set>
//#include <string>
//#include <functional>
#include <memory>
#include "shapes/shape.hpp"

class ShapeFactory
{
public:
    using CreatorFunc = std::function<std::unique_ptr<Shape>()>;

    static ShapeFactory& getInstance();

    ShapeFactory(ShapeFactory const&) = delete;
    void operator=(ShapeFactory const&) = delete;

    // Static method to retrieve valid shape names
    std::set<std::string> getValidShapeNames();

    std::unique_ptr<Shape> createShape(const std::string& key);

private:
    static ShapeFactory instance;

    ShapeFactory();
    ~ShapeFactory();

    void registerCreator(const std::string& key, CreatorFunc creator);

    std::unordered_map<std::string, CreatorFunc> creators;
};
