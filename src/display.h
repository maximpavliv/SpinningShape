#pragma once
#include <ncurses.h>

class Display {
public:
    static Display& getInstance();

    Display(Display const&) = delete;
    void operator=(Display const&) = delete;

    void initializeDisplay(void);

    void renderFrame(void);

private:
    bool displayInitialized = false;

    const static int PIXEL_WIDTH;  // in distance units
    const static int PIXEL_HEIGHT; // in distance units
    const static int VIEWPORT_WIDTH;  // in distance units
    const static int VIEWPORT_HEIGHT; // in distance units

    Display();
    ~Display();

    static Display instance;

    // Each pixel is a character
    const uint8_t NB_PIXELS_WIDTH;
    const uint8_t NB_PIXELS_HEIGHT;

    WINDOW * window;
};