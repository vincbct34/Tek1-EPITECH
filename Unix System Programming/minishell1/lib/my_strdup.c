/*
** EPITECH PROJECT, 2024
** Minishell 1
** File description:
** my_strdup.c
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (dest == NULL)
        return NULL;
    my_strcpy(dest, src);
    return dest;
}
