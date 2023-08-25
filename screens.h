#pragma once
#ifndef screens_h
#define screens_h

#include "common.h"

void length_screen(size_t* length);
void charset_screen(char charsets[NCHARSETS]);
void final_screen(size_t length, char string[length], size_t charset_length, char charset[charset_length], _Bool* regen, _Bool* run);

#endif // screens_h
