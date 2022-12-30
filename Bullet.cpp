#include "Bullet.hpp"

int Bullet::getX() { return start_x; }
int Bullet::getY() { return start_y; }

void Bullet::set_exist(bool a)
{
    exists = a;
}
void Bullet::fire(Alien *aliens, int number, int &aliens_num)
{
    int max_y, max_x;
    start_y = ship->getY();
    start_x = ship->getX();
    number_of_aliens = number;
    this->aliens = aliens;
    getmaxyx(board_win, max_y, max_x);
    start_y = max_y - 5;
    wrefresh(board_win);

    /*
    for (int b = 0; b < 28; ++b) // number_of_aliens; ++i)
    {
        if (aliens[b].is_alive() && (aliens[b].getY() == ship->getY() || aliens[b].getX() == ship->getX()))
        {
            game_is_over = true;
            end_game(board_win);
        }
    }
    */
}

void Bullet::alien_fire(Alien &alien, int &lives_count)
{
    start_y = alien.getY() + 1;
    start_x = alien.getX();
    int alien_y=alien.getY();
    set_exist(true);

    if(alien.getY()>ship->getY()-2)
    {
        game_is_over = true;
        end_game(board_win);
    }
}

void Bullet::move_down(int &lives_count)
{
    int max_x, max_y;
    getmaxyx(board_win, max_y, max_x);
    erease();
    start_y++;

    start_color();
    init_pair(4, COLOR_RED, COLOR_BLACK);
    wattron(board_win, COLOR_PAIR(4));
    draw();
    wattroff(board_win, COLOR_PAIR(4));
    wrefresh(board_win);
    if ((start_y == ship->getY()) && (start_x == ship->getX() || start_x == ship->getX() - 1 || start_x == ship->getX() + 1))
    {
        lives_count--;
        set_exist(false);
        erease();
    }


    if (lives_count == 0)
    {
        game_is_over = true;
        end_game(board_win);
    }

    if (start_y >= max_y - 2)
    {
        set_exist(false);
        erease();
    }
}

void Bullet::move_up(int &aliens_num)
{
    start_y++;
    erease();
    start_y--;
    wrefresh(board_win);
    draw();
    wrefresh(board_win);

    int k = 0;
    {

        for (int i = 0; i < number_of_aliens; ++i)
        {
            if (aliens[i].is_alive() && (aliens[i].getY() == start_y) && (start_x == aliens[i].getX() - 1 || start_x == aliens[i].getX() || start_x == aliens[i].getX() + 1))
            {
                aliens[i].set_live(false);
                aliens[i].erease();
                aliens_num--;
                set_exist(false);
                erease();
                if (aliens_num == 0)
                {
                    game_is_over = true;
                    winning = true;
                    end_game(board_win);
                }

                k = 1;
            }

            if (k == 1 || start_y <= 1)
            {
                set_exist(false);
                erease();
                break;
            }
        }
        start_y--;
    }
}

void Bullet::draw()
{

    mvwprintw(board_win, start_y, start_x, "*");
    wrefresh(board_win);
}

void Bullet::erease()
{
    mvwprintw(board_win, start_y, start_x, " ");
}
