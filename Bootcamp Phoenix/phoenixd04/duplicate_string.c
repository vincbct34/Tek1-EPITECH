/*
** EPITECH PROJECT, 2023
** duplicate_string.c
** File description:
** Bootcamp Day 4
*/

#include "includes/phoenix.h"
#include <stdlib.h>

char *duplicate_string(char const *src)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * my_strlen(src) + 1);

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
