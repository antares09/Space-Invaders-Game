#ifndef _SHIP_H
#define _SHIP_H

#include "Game_controle.hpp"

class Ship
{
private:
    int y;
    int x;
    int max_x, max_y;
    int lives_count = 3;
    std::string ship[1]{"O_O"};
    WINDOW *board_win;

public:
    Ship() {}
    Ship(WINDOW *board_win)
    {
        this->board_win = board_win;
        getmaxyx(board_win, max_y, max_x);

        x = max_x / 2;
        y = max_y - 3;
    }

    int getX() { return x; }
    int getY() { return y; }
    WINDOW *get_board_win() { return board_win; }

    void locate();
    void draw();
    void erease();
    void moveRight();
    void moveLeft();
};

#endif