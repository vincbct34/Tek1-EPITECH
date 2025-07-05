/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** my_strlen.c
*/

#include "../include/lib.h"

int my_strlen(const char *str)
{
    int i;

    for (i = 0; str[i]; i++);
    return (i);
}
