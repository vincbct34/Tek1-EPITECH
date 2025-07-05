/*
** EPITECH PROJECT, 2024
** Solo Stumper 5
** File description:
** my_putchar.c
*/

#include "my.h"

int my_putchar(char c)
{
    if (write(1, &c, 1) == -1)
        return 84;
    return 0;
}
