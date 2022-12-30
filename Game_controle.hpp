#ifndef _GAME_CONTROLE_H
#define _GAME_CONTROLE_H

#include <ncurses.h>
#include <iostream>
#include <unistd.h>
#include <fstream>

#include "Alien.hpp"
#include "Board.hpp"
#include "Ship.hpp"
#include "Bullet.hpp"
#include "Menu.hpp"

#define BOARD_LEN 20
#define BOARD_ROWS BOARD_LEN * 1
#define BOARD_COL BOARD_LEN * 2.5

class Menu;
void SpaceGame();
void start_program();
void start_game(WINDOW *board_win, int &highlight, Menu &menu);
void end_game(WINDOW *board_win);
#endif