/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** my_tabdup.c
*/

#include "../../include/my.h"

char **my_tabdup(char **tab)
{
    int i = 0;
    char **new_tab = NULL;

    if (tab == NULL)
        return NULL;
    new_tab = malloc(sizeof(char *) * (my_tablen(tab) + 1));
    if (new_tab == NULL)
        return NULL;
    for (i = 0; tab[i] != NULL; i++)
        new_tab[i] = my_strdup(tab[i]);
    new_tab[i] = NULL;
    return new_tab;
}
