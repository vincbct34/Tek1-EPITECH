/*
** EPITECH PROJECT, 2024
** Solo Stumper 07
** File description:
** my_putchar.c
*/

#include "stumper.h"

int my_putchar(char c)
{
    if (write(1, &c, 1) == -1)
        return 84;
    return 0;
}
