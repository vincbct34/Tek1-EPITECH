/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** Task01
*/

#include <stdlib.h>
#include "mylib.h"

int my_strlen(char const *c);

char *my_strdup(char const *src)
{
    char *dest;
    int i = 0;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
