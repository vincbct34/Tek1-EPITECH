/*
** EPITECH PROJECT, 2024
** Stumper 7
** File description:
** is_alphanum.c
*/

#include "crocus.h"

int is_alphanum(char a)
{
    if (a > '0' && a < '9')
        return 0;
    if (a >= 'a' && a <= 'z')
        return 0;
    if (a >= 'A' && a <= 'Z')
        return 0;
    return 1;
}
