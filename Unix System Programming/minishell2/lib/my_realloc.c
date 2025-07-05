/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell2-vincent.bichat
** File description:
** my_realloc.c
*/

#include "my.h"
#include "minishell.h"

char *my_realloc(char *str, char c)
{
    int len;
    char *new_str;

    if (str == NULL) {
        new_str = malloc(sizeof(char) * 2);
        new_str[0] = c;
        new_str[1] = '\0';
        return new_str;
    }
    len = my_strlen(str);
    new_str = malloc(sizeof(char) * (len + 2));
    for (int i = 0; i < len; i++)
        new_str[i] = str[i];
    new_str[len] = c;
    new_str[len + 1] = '\0';
    free(str);
    return new_str;
}
