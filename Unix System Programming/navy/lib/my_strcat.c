/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** my_strcat.c
*/

#include "../include/lib.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int j = 0;

    for (j = 0; src[j] != '\0'; j++)
        dest[dest_len + j] = src[j];
    dest[dest_len + j] = '\0';
    return (dest);
}
