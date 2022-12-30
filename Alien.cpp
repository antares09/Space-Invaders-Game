#include "Alien.hpp"

int Alien::getY()
{
    return y;
}

int Alien::getX()
{
    return x;
}

void Alien::set_live(bool l)
{
    life = l;
}

std::string Alien::get_str()
{
    return alien[1];
}
void Alien::locate(int y, int x, WINDOW *board_win)
{
    getmaxyx(board_win, max_y, max_x);
    this->x = x;
    this->y = y;
    this->board_win = board_win;
    draw();
}

void Alien::draw()
{
    if (life == true)
    {
        mvwprintw(board_win, y, x - 1, "^");
        mvwprintw(board_win, y, x, "_");
        mvwprintw(board_win, y, x + 1, "^");
    }
}

void Alien::erease()
{
    mvwprintw(board_win, y, x - 1, " ");
    mvwprintw(board_win, y, x, " ");
    mvwprintw(board_win, y, x + 1, " ");
}

void Alien::moveLeft()
{
    draw();
    erease();
    x--;
     
    if (x < 3)
    {
        x = 3;
    }
    draw();
   
}

void Alien::moveDown()
{
     int max_x, max_y;
    getmaxyx(board_win, max_y, max_x);
    if (y< max_y-2 && is_alive())
    {
        erease();
        y++;
        start_color();
        init_pair(4, COLOR_GREEN, COLOR_BLACK);
        wattron(board_win, COLOR_PAIR(4));
        draw();
        wattroff(board_win,COLOR_PAIR(4));
        moveLeft();
    }
    if(y>max_y-2)
    {y=max_y-2;
        set_live(false);
        }
    //moveLeft();
}

void Alien::moveRight()
{
    erease();
    x++;
    if (x > max_x - 3)
        x = max_x - 3;
    draw();
}