/*
** EPITECH PROJECT, 2024
** Solo Stumper 5
** File description:
** my_putstr.c
*/

#include "my.h"

int my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (my_putchar(str[i]) == 84)
            return 84;
    return 0;
}
