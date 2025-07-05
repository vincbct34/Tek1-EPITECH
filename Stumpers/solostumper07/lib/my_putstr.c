/*
** EPITECH PROJECT, 2024
** Solo Stumper 07
** File description:
** my_putstr.c
*/

#include "lib.h"

int my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (my_putchar(str[i]) == 84)
            return 84;
    return 0;
}
