#pragma once
#include <ncurses.h>
#include "shapes/shape.hpp"

class Display {
public:
    static Display& getInstance();

    Display(Display const&) = delete;
    void operator=(Display const&) = delete;

    void initializeDisplay(void);

    void renderFrame(const Shape& shape);

private:
    bool displayInitialized = false;

    const static int PIXEL_WIDTH;  // in distance units
    const static int PIXEL_HEIGHT; // in distance units
    const static int VIEWPORT_WIDTH;  // in distance units
    const static int VIEWPORT_HEIGHT; // in distance units

    const static float DISTANCE_TO_VIEWPORT; // in distance units

    Display();
    ~Display();

    static Display instance;

    // Each pixel is a character
    const uint8_t NB_PIXELS_WIDTH;
    const uint8_t NB_PIXELS_HEIGHT;

    WINDOW * window;

    char getPixelAsscii(const std::vector<SurfacePoint>& intersections) const;

    const SurfacePoint& getClosestSurfacePoint(const std::vector<SurfacePoint>& surfacePoints) const;
};