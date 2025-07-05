/*
** EPITECH PROJECT, 2024
** crocus
** File description:
** displayer_letter_56789
*/

#include "crocus.h"

int draw_5(int line, char c)
{
    if (line == 1)
        if (display_string("00000", c) == 0)
            return 84;
    if (line == 2)
        if (display_string("0    ", c) == 0)
            return 84;
    if (line == 3 || line == 5)
        if (display_string("0000 ", c) == 0)
            return 84;
    if (line == 4)
        if (display_string("    0", c) == 0)
            return 84;
    return 0;
}

int draw_6(int line, char c)
{
    if (line == 1)
        if (display_string(" 000 ", c) == 0)
            return 84;
    if (line == 2)
        if (display_string("0    ", c) == 0)
            return 84;
    if (line == 3)
        if (display_string("0000 ", c) == 0)
            return 84;
    if (line == 4)
        if (display_string("0   0", c) == 0)
            return 84;
    if (line == 5)
        if (display_string(" 000 ", c) == 0)
            return 84;
    return 0;
}

int draw_7(int line, char c)
{
    if (line == 1)
        if (display_string("00000", c) == 0)
            return 84;
    if (line == 2)
        if (display_string("    0", c) == 0)
            return 84;
    if (line == 3)
        if (display_string("   0 ", c) == 0)
            return 84;
    if (line == 4)
        if (display_string("  0  ", c) == 0)
            return 84;
    if (line == 5)
        if (display_string(" 0   ", c) == 0)
            return 84;
    return 0;
}

int draw_8(int line, char c)
{
    if (line == 1 || line == 3 || line == 5)
        if (display_string(" 000 ", c) == 0)
            return 84;
    if (line == 2 || line == 4)
        if (display_string("0   0", c) == 0)
            return 84;
    return 0;
}

int draw_9(int line, char c)
{
    if (line == 1 || line == 5)
        if (display_string(" 000 ", c) == 0)
            return 84;
    if (line == 2)
        if (display_string("0   0", c) == 0)
            return 84;
    if (line == 3)
        if (display_string(" 0000", c) == 0)
            return 84;
    if (line == 4)
        if (display_string("    0", c) == 0)
            return 84;
    return 0;
}
