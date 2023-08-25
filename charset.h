#pragma once
#ifndef charset_h
#define charset_h

#include "common.h"

size_t get_charset_length(char charsets[NCHARSETS]);
void create_charset(char charsets[NCHARSETS], size_t length, char charset[length]);
void generate_string(size_t length, char string[length], size_t charset_length, char charset[charset_length]);

#endif // charset_h
