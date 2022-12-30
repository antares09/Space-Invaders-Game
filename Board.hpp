#ifndef _BOARD_H
#define _BOARD_H

#include "Game_controle.hpp"

class Board
{
public:
     Board() { construct(0, 0); }
     Board(int height, int width) { construct(height, width); }

     void initialize();

     void board_refresh();

     void draw_boarder();
     void ft_clear();
     void ft_addch(int y, int x, chtype ch);
     chtype ft_get_input();

     WINDOW *get_board_win();

private:
     WINDOW *board_win;
     void construct(int height, int width);
};

#endif