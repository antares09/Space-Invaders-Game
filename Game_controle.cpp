
#include "Game_controle.hpp"

int seconds = 0;
bool game_is_over = false;
bool winning = false;

//class Menu;
//class Ship;
/*void start_program();
void start_game(WINDOW *board_win, int &highlight, Menu &menu);
void end_game(WINDOW *board_win);
void SpaceGame();
*/

void SpaceGame()
{
    start_program();
}

void end_game(WINDOW *board_win)
{
    int max_y, max_x;
    getmaxyx(board_win, max_y, max_x);
    wclear(board_win);
    box(board_win, 0, 0);
    wrefresh(board_win);

    if (winning == true)
    {
        mvwprintw(board_win, max_y / 2 - 2, max_x / 2 - 7, "YOU WIN!!!");
    }

    if (winning == false)
    {
        mvwprintw(board_win, max_y / 2 - 2, max_x / 2 - 7, "GAME OVER");
        mvwprintw(board_win, max_y / 2, max_x / 2 - 7, "LOOSER ^_^");
    }

    wrefresh(board_win);
    usleep(1000000);
}

void start_game(WINDOW *board_win, int &highlight, Menu &menu)
{
    int max_x, max_y;
    getmaxyx(board_win, max_y, max_x);

    wclear(board_win);
    box(board_win, 0, 0);
    wrefresh(board_win);

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);

    Ship ship(board_win);
    wattron(board_win, COLOR_PAIR(2));
    ship.locate();
    int lives_count = 3;
    wattroff(board_win, COLOR_PAIR(2));

    int key_space = ' ';

    Bullet bullet(board_win, ship);
    Bullet alien_bullet(board_win, ship);
    int aliens_num = 28;
    Alien aliens[aliens_num];

    int rand = aliens_num - 1;
    ;

    int x_loc = 2, y_loc = 2, k = 0;
    for (int i = 0; i < 4; ++i)
    {
        x_loc = 2;
        for (int j = 0; j < 7; ++j)
        {
            wattron(board_win, COLOR_PAIR(1));
            aliens[k].locate(y_loc, x_loc, board_win);
            wattroff(board_win, COLOR_PAIR(1));
            x_loc = x_loc + 4;
            k++;
        }
        y_loc += 2;
    }

    keypad(board_win, true);
    int key;
    const int space_key = int(' ');
    wrefresh(board_win);
    bool move_right = true, move_left = false;

    rand = 27;
    while (true)
    {
        mvwprintw(board_win, 0, 2, "Your lives %d", lives_count);
        if (rand == -1)
            rand = 27;
        while (!aliens[rand].is_alive())
            rand--;
        if (rand == -1)
            rand = 27;

        seconds++;
        if (seconds == 2)
            seconds = 0;
        halfdelay(1);

        key = wgetch(board_win);

        k = 0;
        if (aliens[6].getX() >= max_x - 3)
        {
            move_right = false;
            move_left = true;

            if(seconds==1){
            for(int b=0;b<28;b++)
            {
                if(aliens[b].getY()<max_y-2 && aliens[b].is_alive())
                {
                    //if(b<=20)
                    aliens[b].moveDown();
                }

            }
            }
        }
        if (aliens[0].getX() <= 3)
        {
            move_right = true;
            move_left = false;
            
        }
        if (move_right && seconds == 1)
        {
            k = 27;
            for (int i = 0; i < 28; ++i)
            {
                wattron(board_win, COLOR_PAIR(1));
                aliens[k].moveRight();

                wattroff(board_win, COLOR_PAIR(1));
                k--;
            }
        }

        if (move_left && seconds == 1)
        {
            k = 0;
            for (int i = 0; i < 28; ++i)
            {
                wattron(board_win, COLOR_PAIR(1));
                aliens[k].moveLeft();

                wattroff(board_win, COLOR_PAIR(1));
                k++;
            }
        }

        switch (key)
        {
        case KEY_LEFT:
            wattron(board_win, COLOR_PAIR(2));
            ship.moveLeft();
            wattroff(board_win, COLOR_PAIR(2));
            break;
        case KEY_RIGHT:
            wattron(board_win, COLOR_PAIR(2));
            ship.moveRight();
            wattroff(board_win, COLOR_PAIR(2));
            break;

        case space_key:

            if (!bullet.exists)
            {
                bullet.set_exist(true);
                bullet.fire(aliens, 28, aliens_num);
            }

            if (bullet.exists)
            {

                bullet.move_up(aliens_num);
            }

            key = wgetch(board_win);
            break;
        case 'f':

            if (!bullet.exists)
            {
                bullet.set_exist(true);
                bullet.fire(aliens, 28, aliens_num);
            }

            if (bullet.exists)
            {

                bullet.move_up(aliens_num);
            }

            key = wgetch(board_win);

            break;

        case 'q':

            break;
        }
        if (bullet.exists)
        {
            bullet.move_up(aliens_num);
        }

        if (!alien_bullet.exists && aliens[rand].is_alive() && aliens_num > 2)
        {
            alien_bullet.alien_fire(aliens[rand], lives_count);
        }

        if (alien_bullet.exists)
        {
            alien_bullet.move_down(lives_count);
        }

        wrefresh(board_win);

        if (lives_count == 0)
        {
            end_game(board_win);
            break;
        }

        if(game_is_over)
        {
            game_is_over=false;
            end_game(board_win);
            break;
        }

        if (aliens_num == 0)
        {
            winning = true;
            end_game(board_win);
            winning = false;
            break;
        }
        if (key == 'q')
        {
            end_game(board_win);
            break;
        }
        if (key == 'c')
        {
            winning = true;
            end_game(board_win);
            winning = false;
            break;
        }

        rand--;
    }
}

void start_program()
{
    initscr();
    halfdelay(5);
    refresh();
    curs_set(0);
    noecho();
    refresh();

    Board board(BOARD_ROWS, BOARD_COL);
    WINDOW *board_win = board.get_board_win();

    box(board_win, 0, 0);
    wrefresh(board_win);
    int highlight = 0;
    keypad(board_win, true);
    Menu menu;

    menu.start_menu(board_win, highlight);

    getch();
    endwin();
}
