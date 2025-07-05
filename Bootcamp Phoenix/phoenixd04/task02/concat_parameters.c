/*
** EPITECH PROJECT, 2023
** concat_parameters.c
** File description:
** Bootcamp Day 4
*/

#include "../includes/phoenix.h"
#include <stdlib.h>

char *concat_parameters(int ac, char **av)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *dest = malloc(sizeof(char) * ac);

    for (; i < ac; i++) {
        for (; av[i][j] != '\0'; j++) {
            dest[k] = av[i][j];
            k++;
        }
        if (i != ac - 1)
            dest[k] = '\n';
        k++;
        j = 0;
    }
    dest[k] = '\0';
    return (dest);
}
