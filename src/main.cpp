#include <ncurses.h> // TODO delete (with getch)
#include <iostream>
#include "display.h"
#include "shape.h"
#include <boost/program_options.hpp>

namespace po = boost::program_options;

std::string parseCommandLine(int argc, char* argv[]) {
    const std::set<std::string> validShapes = Shape::getValidShapeNames();

    try {
        // Define allowed options
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help,h", "produce help message")
            ("shape,s", po::value<std::string>()->required(), "shape")
        ;

        // Define positional options
        po::positional_options_description pos_desc;
        pos_desc.add("shape", 1); // Specify the shape option as positional

        // Variables map to store parsed options
        po::variables_map vm;

        // Parse command line options
        po::store(po::command_line_parser(argc, argv)
                    .options(desc).positional(pos_desc).run(), vm);

        // Check for help option
        if (vm.count("help")) {
            std::cout << desc << std::endl;
            std::cout << "Available shapes: ";
            for (const auto& shape : validShapes) {
                std::cout << shape << " ";
            }
            std::cout << std::endl;
            exit(0);
        }

        po::notify(vm);

        // Check for positional shape argument
        if (vm.count("shape")) {
            std::string shapeType = vm["shape"].as<std::string>();
            if (validShapes.find(shapeType) == validShapes.end()) {
                throw std::invalid_argument("Invalid shape type: " + shapeType);
            }
            return shapeType;
        } else {
            throw std::invalid_argument("Shape argument is required.");
        }
    } catch (const po::error &ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        std::cout << "Usage: [options] <shape>\n" << std::endl;
        exit(1);
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        exit(1);
    }
}

int main(int argc, char *argv[]) {

    std::string shapeType = parseCommandLine(argc, argv);

    Display::getInstance().initializeDisplay();

    Display::getInstance().renderFrame();

    // pause the screen output
    getch();

    return 0;
}