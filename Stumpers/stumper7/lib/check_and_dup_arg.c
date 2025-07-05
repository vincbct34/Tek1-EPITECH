/*
** EPITECH PROJECT, 2024
** Stumper 7
** File description:
** check_and_dup_arg.c
*/

#include "crocus.h"

char *check_and_dup_arg(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return NULL;
    }
    if (str[0] == '\0')
        return NULL;
    return strdup(str);
}
