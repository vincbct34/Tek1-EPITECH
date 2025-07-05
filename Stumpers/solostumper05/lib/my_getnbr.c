/*
** EPITECH PROJECT, 2024
** Solo Stumper 5
** File description:
** my_getnbr.c
*/

#include "my.h"

int my_getnbr(char ch)
{
    int nb = 0;

    if (ch >= '0' && ch <= '9')
        nb = nb * 10 + (ch - 48);
    else
        return 84;
    return nb;
}
