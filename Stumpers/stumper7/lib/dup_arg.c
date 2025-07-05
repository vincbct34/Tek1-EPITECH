/*
** EPITECH PROJECT, 2024
** Stumper 7
** File description:
** dup_arg.c
*/

#include "crocus.h"

char *dup_arg(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_alphanum(str[i]) != 0)
            return NULL;
    }
    return strdup(str);
}
