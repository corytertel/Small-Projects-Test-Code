#include <ncurses.h>

int main(int argc, char** argv) {
    //initializes the screen
    //sets up memory and clears the screen
    initscr();

    int height, width, start_y, start_x;
    height = 10;
    width = 20;
    start_y = start_x = 10;

    WINDOW* win = newwin(height, width, start_y, start_x);
    refresh();

    box(win, 0, 0);
    mvwprintw(win, 1, 1, "this is my box");
    wrefresh(win);

    //what's for user input, returns int value of that key
    int c = getch();

    endwin();
    //deallocates memory and ends ncurses

    return 0;
}
