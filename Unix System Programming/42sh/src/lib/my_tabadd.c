/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** my_tabadd.c
*/

#include "../../include/my.h"

char **my_tabadd(char **tab, char *str)
{
    char **new_tab = NULL;
    int i = 0;

    if (tab == NULL && str == NULL)
        return NULL;
    new_tab = malloc(sizeof(char *) * (my_tablen(tab) + 2));
    if (new_tab == NULL)
        return NULL;
    for (i = 0; tab != NULL && tab[i] != NULL; i++)
        new_tab[i] = my_strdup(tab[i]);
    new_tab[i] = my_strdup(str);
    new_tab[i + 1] = NULL;
    return new_tab;
}
