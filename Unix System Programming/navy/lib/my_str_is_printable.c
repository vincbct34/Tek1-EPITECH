/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** my_str_is_printable.c
*/

#include "../include/lib.h"

int my_str_is_printable(const char *str)
{
    for (int i = 0; str[i]; i++)
        if (!(str[i] >= 32 && str[i] <= 126))
            return (0);
    return (1);
}
