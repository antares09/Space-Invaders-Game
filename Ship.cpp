#include "Ship.hpp"

void Ship::locate()
{
    draw();
    wrefresh(board_win);
}

void Ship::draw()
{

    mvwprintw(board_win, y, x - 1, "O");
    mvwprintw(board_win, y, x, "_");
    mvwprintw(board_win, y, x + 1, "O");
}

void Ship::erease()
{
    mvwprintw(board_win, y, x - 1, " ");
    mvwprintw(board_win, y, x, " ");
    mvwprintw(board_win, y, x + 1, " ");
}

void Ship::moveLeft()
{
    erease();
    x--;
    if (x < 3)
        x = 3;
    draw();
}

void Ship::moveRight()
{
    erease();
    x++;
    if (x > max_x - 3)
        x = max_x - 3;
    draw();
}