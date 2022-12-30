#ifndef _MENU_H
#define _MENU_H

#include "Game_controle.hpp"

class Menu
{
public:
    Menu() {}
    void start_menu(WINDOW *board_win, int &highlight);
    void Options();
    void Records();
    friend void start_game(WINDOW *board_win, int &highlight, Menu &menu);

private:
    int max_x = 0, max_y = 0;
    WINDOW *board_win;
    std::string words[4] = {"Play", "Options", "Records", "Quit"};
    int word_num = 4;
    int ft_input();
};

#endif