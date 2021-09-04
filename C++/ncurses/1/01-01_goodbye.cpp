#include <ncurses.h>

int main() {
    initscr();
    addstr("Goodbye, cruel world!");

    endwin();

    while(true) {};

    return 0;
}
