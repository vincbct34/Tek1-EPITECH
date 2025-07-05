/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** my_tablen.c
*/

#include "../../include/my.h"

int my_tablen(char **tab)
{
    int i = 0;

    if (tab == NULL)
        return 0;
    for (i = 0; tab[i] != NULL; i++);
    return i;
}
