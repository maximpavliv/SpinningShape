#include "display.h"
#include <ncurses.h>

// Initialize the static instance
Display Display::instance;

// Private constructor
Display::Display() {
    // init screen and sets up screen
    initscr();

    // Define window size
    uint8_t win_height = 30;
    uint8_t win_width = 60;

    uint8_t rows, cols;
    getmaxyx(stdscr, rows, cols);

    // Calculate start position to center the window
    int start_y = (rows - win_height) / 2;
    int start_x = (cols - win_width) / 2;

    // creating a window;
    WINDOW *win = newwin(win_height, win_width, start_y, start_x);
    refresh();

    // making box border with default border styles
    box(win, 0, 0);

    // move and print in window
    mvwprintw(win, 0, 1, "Greeter");
    mvwprintw(win, 1, 1, "Hello");

    // refreshing the window
    wrefresh(win);
}

// Private destructor
Display::~Display() {
    // deallocates memory and ends ncurses
    endwin();
}

// Static method to return the instance
Display& Display::getInstance() {
    return instance;
}
