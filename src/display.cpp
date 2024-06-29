#include "display.h"
#include <ncurses.h>

const int Display::PIXEL_WIDTH  = 1; // in distance units
const int Display::PIXEL_HEIGHT = 2; // in distance units
const int Display::VIEWPORT_WIDTH  = 60; // in distance units
const int Display::VIEWPORT_HEIGHT = 60; // in distance units

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

void Display::renderFrame(void) {
    if (displayInitialized) {
        // move and print in window
        mvwprintw(window, 0, 1, "Greeter");
        mvwprintw(window, 1, 1, "Hello");

        // refreshing the window
        wrefresh(window);
    }
}
