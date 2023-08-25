#include <stdlib.h>
#include <locale.h>
#include <ncurses.h>

#include "common.h"
#include "charset.h"
#include "screens.h"

int main(void)
{
        if(setlocale(LC_ALL, "") == NULL)
                printf("WARN: locale couldn't be set");

        initscr(); cbreak(); echo();

        _Bool run = 1;
        while(run)
        {
                size_t length = 0;
                length_screen(&length);

                char charsets[NCHARSETS];
                charset_screen(charsets);

                _Bool regen = 1;
                while(regen)
                {
                        size_t charset_length = get_charset_length(charsets);
                        char* charset = calloc(charset_length, sizeof(char));
                        char* string  = calloc(length, sizeof(char));

                        create_charset(charsets, charset_length, charset);
                        generate_string(length, string, charset_length, charset);

                        final_screen(length, string, charset_length, charset, &regen, &run);

                        free(charset);
                        free(string);
                }
        }

        endwin();
        return 0;
}
