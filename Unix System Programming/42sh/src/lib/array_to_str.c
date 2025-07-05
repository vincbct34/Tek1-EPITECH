/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** array_to_str.c
*/

#include "../../include/my.h"

char *array_to_str(char **array)
{
    char *str = NULL;
    int len = 0;
    int i = 0;

    if (array == NULL)
        return NULL;
    for (i = 0; array[i] != NULL; i++)
        len += my_strlen(array[i]);
    str = malloc(sizeof(char) * (len + i + 1));
    if (str == NULL)
        return NULL;
    str[0] = '\0';
    for (i = 0; array[i] != NULL; i++) {
        str = my_strcat(str, array[i]);
        if (array[i + 1] != NULL)
            str = my_strcat(str, " ");
    }
    return str;
}
