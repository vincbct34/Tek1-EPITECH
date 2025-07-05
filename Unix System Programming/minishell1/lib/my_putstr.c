/*
** EPITECH PROJECT, 2024
** Minishell 1
** File description:
** my_putstr.c
*/

#include "my.h"

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}
