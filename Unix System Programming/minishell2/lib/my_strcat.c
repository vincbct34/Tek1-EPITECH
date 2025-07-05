/*
** EPITECH PROJECT, 2024
** Minishell 1
** File description:
** my_strcat.c
*/

#include "my.h"

char *my_strcat(char *dest, const char *src)
{
    int dest_len = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return dest;
}
