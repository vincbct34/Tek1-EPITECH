/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** my_strdup.c
*/

#include "paint.h"

char *my_strdup(char *str)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (new_str == NULL)
        return (NULL);
    for (int i = 0; str[i] != '\0'; i++)
        new_str[i] = str[i];
    new_str[my_strlen(str)] = '\0';
    return (new_str);
}
