/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** my_putstr.c
*/

#include "../include/lib.h"

void my_putstr(char const *str)
{
    while (*str) {
        my_putchar(*str);
        str++;
    }
}
