/*
** EPITECH PROJECT, 2024
** A-maze-d
** File description:
** my_getlastnbr.c
*/

#include "maze.h"

int my_getlastnbr(char *str)
{
    int i = 0;
    int nb = 0;

    for (; str[i] != '-'; i++);
    i++;
    for (; str[i] != '\0'; i++)
        nb = nb * 10 + (str[i] - 48);
    return nb;
}
