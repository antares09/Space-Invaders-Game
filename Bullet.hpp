#ifndef _BULLET_H
#define _BULLET_H

#include "Game_controle.hpp"

extern bool game_is_over;
extern bool winning;
extern void end_game(WINDOW *);
class Alien;
class Ship;

class Bullet
{
private:
    WINDOW *board_win;
    int start_y = 0;
    int start_x = 0;
    std::string ball[1]{"*"};
    Alien *aliens;
    int number_of_aliens;
    Ship *ship;

public:
    Bullet() {}
    Bullet(WINDOW *board_win, Ship &ship1)
    {
        this->board_win = board_win;
        ship = &ship1;
    }
    bool exists = false;

    void set_exist(bool);
    void fire(Alien *, int, int &);

    void alien_fire(Alien &alien, int &lives_count);
    void move_down(int &lives_count);

    void draw();
    void erease();
    void move_up(int &);
    int getX();
    int getY();
};

#endif