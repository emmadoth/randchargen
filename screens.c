#include <stddef.h>
#include <ncurses.h>

#include "common.h"

void length_screen(size_t* length)
{
        clear();
        printw("Enter length: ");
        refresh();

        scanw("%zu", length);
}

void charset_screen(char charsets[NCHARSETS])
{
        clear();
        printw("1: [a-z]");
        mvprintw(1, 0, "2: [A-Z]");
        mvprintw(2, 0, "3: [0-9]");
        mvprintw(3, 0, "4: [!-~]]");
        mvprintw(4, 0, "Select character sets: ");
        refresh();

        int read = scanw("%s", charsets);
        for(int i = read; i < (NCHARSETS - 1); ++i)
                charsets[i] = '\0';
}

void final_screen(size_t length, char string[length], size_t charset_length, char charset[charset_length], _Bool* regen, _Bool* run)
{
        noecho();
        clear();
        printw("Character set: %.*s", (int)charset_length, charset);
        mvprintw(1, 0, "Length: %zu", length);
        mvprintw(2, 0, "String: %.*s", (int)length, string);

        mvprintw(4, 0, "[s] to start over, [r] to regenerate, [q] to quit: ");
        refresh();

        int input = 1;
        while(input != 0)
        {
                input = getch();
                switch(input)
                {
                        case 'r':
                                input = 0;
                                break;
                        case 's':
                                input = 0;
                                *regen = 0;
                                break;
                        case 'q':
                                input = 0;
                                *run = 0;
                                *regen = 0;
                                break;
                        default:
                                break;
                }
        }
        echo();
}

