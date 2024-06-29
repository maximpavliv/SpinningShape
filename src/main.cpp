#include <ncurses.h> // TODO delete (with getch)
#include "display.h"

int main() {
    Display::getInstance().initializeDisplay();

    Display::getInstance().renderFrame();

    // pause the screen output
    getch();

    return 0;
}