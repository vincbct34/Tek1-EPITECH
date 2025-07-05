/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** my_tabcat.c
*/

#include "../../include/my.h"

char **my_tabcat(char **tab1, char **tab2)
{
    int i = 0;
    int j = 0;
    char **new_tab = NULL;

    if (tab1 == NULL && tab2 == NULL)
        return NULL;
    new_tab = malloc(sizeof(char *) * (my_tablen(tab1) + my_tablen(tab2) + 1));
    if (new_tab == NULL)
        return NULL;
    for (i = 0; tab1 != NULL && tab1[i] != NULL; i++) {
        new_tab[j] = my_strdup(tab1[i]);
        j++;
    }
    for (i = 0; tab2 != NULL && tab2[i] != NULL; i++) {
        new_tab[j] = my_strdup(tab2[i]);
        j++;
    }
    new_tab[j] = NULL;
    return new_tab;
}
