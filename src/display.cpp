#include "display.hpp"
#include <ncurses.h>
#include "ray.hpp"

const int Display::PIXEL_WIDTH  = 1; // in distance units
const int Display::PIXEL_HEIGHT = 2; // in distance units
const int Display::VIEWPORT_WIDTH  = 60; // in distance units
const int Display::VIEWPORT_HEIGHT = 60; // in distance units

const float Display::DISTANCE_TO_VIEWPORT = 100; // in distance units

const Eigen::Vector3f Display::LIGHT_DIRECTION = Eigen::Vector3f(0.5, 0.25, 1).stableNormalized();

const char* Display::densities = ".:-+=%#@";
const int Display::nbDensitiesChars = strlen(densities);

// Initialize the static instance
Display Display::instance;

// Private constructor
Display::Display()
    : NB_PIXELS_WIDTH (VIEWPORT_WIDTH  / PIXEL_WIDTH ),
      NB_PIXELS_HEIGHT(VIEWPORT_HEIGHT / PIXEL_HEIGHT) {}

// Private destructor
Display::~Display() {
    if (displayInitialized) {
        // deallocates memory and ends ncurses
        endwin();
    }
}

// Static method to return the instance
Display& Display::getInstance() {
    return instance;
}

void Display::initializeDisplay() {
    // init screen and sets up screen
    initscr();

    // + 2 because the box (margin around the window) takes  1 pixel on each side
    const uint8_t windowWidth  = NB_PIXELS_WIDTH  + 2;
    const uint8_t windowHeight = NB_PIXELS_HEIGHT + 2;

    uint8_t rows, cols;
    getmaxyx(stdscr, rows, cols);

    // Calculate start position to center the window
    int startX = (cols - windowWidth)  / 2;
    int startY = (rows - windowHeight) / 2;

    // creating a window;
    window = newwin(windowHeight, windowWidth, startY, startX);
    refresh();

    // making box border with default border styles
    box(window, 0, 0);

    // refreshing the window
    wrefresh(window);

    displayInitialized = true;
}

void Display::renderFrame(const Shape& shape) {
    for (uint8_t i=0; i<NB_PIXELS_HEIGHT; i++) {
        for (uint8_t j=0; j<NB_PIXELS_WIDTH; j++) {

            Ray ray(Eigen::Vector3f(0,0,0),
                    Eigen::Vector3f(
                        PIXEL_WIDTH  * (j - (float)(NB_PIXELS_WIDTH -1) /2),
                        PIXEL_HEIGHT * (i - (float)(NB_PIXELS_HEIGHT-1)/2),
                        DISTANCE_TO_VIEWPORT));

            std::vector<SurfacePoint> intersections = shape.intersect(ray);

            char pixelAscii = getPixelAsscii(intersections);

            if (displayInitialized) {
                mvwaddch(window, i+1, j+1, pixelAscii);
            }
        }
    }

    // refreshing the window
    if (displayInitialized) {
        wrefresh(window);
    }
}

char Display::getPixelAsscii(const std::vector<SurfacePoint>& intersections) const {
    if (intersections.empty()) {
        return ' ';
    } else {
        SurfacePoint closestIntersection = getClosestSurfacePoint(intersections);
        float scalarProduct = closestIntersection.getNormal().dot(LIGHT_DIRECTION);
        return getCharFromBrightness(-scalarProduct);
    }
}

const SurfacePoint& Display::getClosestSurfacePoint(const std::vector<SurfacePoint>& surfacePoints) const {
    if (surfacePoints.empty()) {
        throw std::invalid_argument("Received surfacePoints list is empty");
    } else {
        auto closestSurfacePoint = std::min_element(surfacePoints.begin(),
            surfacePoints.end(),
            [](const SurfacePoint &a, const SurfacePoint &b) {
                return a.getPosition().z() < b.getPosition().z();
            });
        return *closestSurfacePoint;
    }
}

char Display::getCharFromBrightness(float brightness) {
    if (brightness < 0) {
        return ' ';
    } else if (brightness < 1) {
        return densities[(int) (brightness * nbDensitiesChars)];
    } else {
        throw std::invalid_argument("Pixel brightness is greater than 1");
    }
}