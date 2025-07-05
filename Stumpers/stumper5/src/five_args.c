/*
** EPITECH PROJECT, 2024
** Duo stumper
** File description:
** five_args.c
*/

#include "my.h"

int handle_five_args(char **av, int ac)
{
    bool is_group = false;
    bool is_sort = false;

    if (strcmp(av[1], "-r") == 0) {
        is_group = true;
        if (strcmp(av[2], "-t") == 0)
            is_sort = true;
    }
    if (five_args(av, is_group, is_sort) == 84)
        return 84;
    return 0;
}
