#include <string.h>

#include "common.h"
#include "charset.h"
#include "charsets.h"

/* calculates the length of the to-be-built character set, based on the user's choices */
size_t get_charset_length(char charsets[NCHARSETS])
{
        size_t length = 0;
        for(size_t i = 0; i < NCHARSETS; ++i)
        {
                switch(charsets[i])
                {
                        // sizeof - 1 is to subtract null terminator
                        case '1':
                                length += sizeof(LOWERCASE) - 1;
                                break;
                        case '2':
                                length += sizeof(UPPERCASE) - 1;
                                break;
                        case '3':
                                length += sizeof(NUMBERS) - 1;
                                break;
                        case '4':
                                length += sizeof(SYMBOLS) - 1;
                                break;
                        default:
                                break;
                }
        }
        return length;
}

/* builds the character set to take characters from */
void create_charset(char charsets[NCHARSETS], size_t length, char charset[length])
{
        for(size_t i = 0; i < NCHARSETS; ++i)
        {
                switch(charsets[i])
                {
                        case '1':
                                strncat(charset,  LOWERCASE, length);
                                break;
                        case '2':
                                strncat(charset, UPPERCASE, length);
                                break;
                        case '3':
                                strncat(charset,  NUMBERS, length);
                                break;
                        case '4':
                                strncat(charset, SYMBOLS, length);
                                break;
                        default:
                                break;
                }

        }
}

void generate_string(size_t length, char string[length], size_t charset_length, char charset[charset_length])
{
        for(unsigned int i = 0; (size_t)i < length; ++i)
                string[i] = charset[rdrand() % charset_length];
}

