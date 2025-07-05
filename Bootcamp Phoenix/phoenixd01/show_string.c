/*
** EPITECH PROJECT, 2023
** show_string.c
** File description:
** Display a string
*/

#include "include/my.h"

int show_string(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}
