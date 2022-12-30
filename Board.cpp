#include "Board.hpp"

WINDOW *Board::get_board_win()
{
     return board_win;
}

void Board::draw_boarder()
{
     box(board_win, 0, 0);
}

void Board::board_refresh()
{
     wrefresh(board_win);
}

void Board::initialize()
{
     ft_clear();
     board_refresh();
}

void Board::ft_clear()
{
     wclear(board_win);
     draw_boarder();
}

void Board::ft_addch(int y, int x, chtype ch)
{
     mvwaddch(board_win, y, x, ch);
}

chtype Board::ft_get_input()
{
     return wgetch(board_win);
}

void Board::construct(int height, int width)
{
     int x_Max, y_Max;
     getmaxyx(stdscr, y_Max, x_Max);
     board_win = newwin(height, width, (y_Max / 2) - (height / 2), (x_Max / 2) - (width / 2));
}