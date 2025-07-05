/*
** EPITECH PROJECT, 2024
** A-maze-d
** File description:
** is_num.c
*/

#include "maze.h"

int is_num(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return 0;
    return 1;
}
