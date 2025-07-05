/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** my_str_isnum.c
*/

#include "../include/lib.h"

int my_str_isnum(const char *str)
{
    for (int i = 0; str[i]; i++)
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
    return (1);
}
