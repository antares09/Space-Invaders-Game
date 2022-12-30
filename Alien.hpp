#ifndef _ALIEN_H
#define _ALIEN_H

#include "Game_controle.hpp"
class Alien;

class Alien
{
private:
    int x;
    int y;
    std::string alien[1] = {"^_^"};
    WINDOW *board_win;
    int max_y, max_x;
    bool life = true;

public:
    Alien() {}
    bool is_alive() { return life; }
    void set_live(bool);
    std::string get_str();
    int getX();
    int getY();
    void locate(int y, int x, WINDOW *board_win);
    void draw();
    void erease();
    void moveRight();
    void moveLeft();
    void moveDown();
};

#endif