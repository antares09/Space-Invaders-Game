#include "Menu.hpp"

int Menu::ft_input()
{

    char name[20];
    std::cout << "Enter your name:";
    std::cin >> name;
    std::fstream file;

    file.open("reg.txt", std::fstream::out | std::fstream::trunc);
    file << name << "     ";
    file.close();
    cbreak();
    return 0;
}

void Menu::Records()
{
    wclear(board_win);
    box(board_win, 0, 0);
    wrefresh(board_win);
    int key;

    start_color();
    wmove(board_win, 2, max_x / 2 - 4);
    wattron(board_win, A_BOLD);
    wprintw(board_win, "RECORDS");
    wattroff(board_win, A_BOLD);
    mvwprintw(board_win,9,16,"Nothing here yet");

    while (true)
    {
        key = wgetch(board_win);
        switch (key)
        {
        case 'q':
            break;
        }
        wrefresh(board_win);
        if (key == 'q')
            break;
    }
}

void Menu::Options()
{
    wclear(board_win);
    box(board_win, 0, 0);
    wrefresh(board_win);
    int key;
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
    wmove(board_win, 2, max_x / 2 - 4);
    wattron(board_win, COLOR_PAIR(2));
    wattron(board_win, A_BOLD);
    wprintw(board_win, "OPTIONS");
    wattroff(board_win, A_BOLD);
    wattroff(board_win, COLOR_PAIR(2));

    wattron(board_win, COLOR_PAIR(1));
    mvwprintw(board_win, 6, 2, "1. Use arrow keys to move left and right");

    mvwprintw(board_win, 8, 2, "2. Use key <<F>> or SPACE to shoot");

    mvwprintw(board_win, 10, 2, "3. Use key <<Q>> to exit from any window");
    wattroff(board_win, COLOR_PAIR(1));

    mvwprintw(board_win, 12, 15, " ___");
    mvwprintw(board_win, 13, 15, "| Q |");
    mvwprintw(board_win, 14, 15, "|___|");

    mvwprintw(board_win, 12, 21, " ___");
    mvwprintw(board_win, 13, 21, "| F |");
    mvwprintw(board_win, 14, 21, "|___|");

    mvwprintw(board_win, 14, 9, " ___");
    mvwprintw(board_win, 15, 9, "|<- |");
    mvwprintw(board_win, 16, 9, "|___|");

    mvwprintw(board_win, 14, 28, " ___");
    mvwprintw(board_win, 15, 28, "| ->|");
    mvwprintw(board_win, 16, 28, "|___|");

    mvwprintw(board_win, 15, 16, " _________");
    mvwprintw(board_win, 16, 16, "| SPACE   |");
    mvwprintw(board_win, 17, 16, "|_________|");

    wrefresh(board_win);

    while (true)
    {
        key = wgetch(board_win);
        switch (key)
        {
        case 'q':
            break;
        }
        wrefresh(board_win);
        if (key == 'q')
            break;
    }
}

void Menu::start_menu(WINDOW *board_win, int &highlight)
{
    this->board_win = board_win;
    getmaxyx(board_win, max_y, max_x);
    wclear(board_win);
    box(board_win, 0, 0);
    wrefresh(board_win);
    int choice;
    highlight = 0;
    keypad(board_win, true);
    while (true)
    {
        for (int i = 0; i < word_num; i++)
        {
            if (i != highlight)
                mvwprintw(board_win, 1 + i + i + 3, 20, words[i].c_str());
            if (i == highlight)
            {
                wattron(board_win, A_REVERSE);
                mvwprintw(board_win, 1 + i + i + 3, 20, words[i].c_str());
                wattroff(board_win, A_REVERSE);
            }
        }
        choice = wgetch(board_win);
        switch (choice)
        {
        case KEY_UP:
            highlight--;
            if (highlight == -1)
                highlight = 0;
            break;
        case KEY_DOWN:
            highlight++;
            if (highlight == 4)
                highlight = 3;
            break;
        case 10:
            if (words[highlight] == "Play")
            {

                wrefresh(board_win);
                wclear(board_win);
                box(board_win, 0, 0);

                // ft_input();

                start_game(board_win, highlight, *this);
                wrefresh(board_win);
                wclear(board_win);
                box(board_win, 0, 0);
            }
            if (words[highlight] == "Options")
            {
                Options();
                wrefresh(board_win);
                wclear(board_win);
                box(board_win, 0, 0);
            }
            if (words[highlight] == "Records")
            {
                Records();
                wrefresh(board_win);
                wclear(board_win);
                box(board_win, 0, 0);
            }
            if (words[highlight] == "Quit")
            {
                endwin();
                exit(0);
                break;
            }
            break;
        }
    }
}