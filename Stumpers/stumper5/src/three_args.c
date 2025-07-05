/*
** EPITECH PROJECT, 2024
** Duo stumper
** File description:
** three_args.c
*/

#include "my.h"

int handle_three_args(char **av, int ac)
{
    bool is_group = false;
    bool is_sort = true;

    if (strcmp(av[1], "-r") == 0)
        is_group = true;
    if (strcmp(av[1], "-t") == 0)
        is_sort = true;
    if (three_args(av, is_group, is_sort) == 84)
        return 84;
    return 0;
}
