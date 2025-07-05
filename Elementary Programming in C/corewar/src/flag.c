/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** flag.c
*/

#include "corewar.h"

int dump_fct(char *str, args_t *data)
{
    (void)data;
    (void)str;
    return 0;
}

int n_fct(char *str, args_t *data)
{
    (void)data;
    (void)str;
    return 0;
}

int a_fct(char *str, args_t *data)
{
    (void)data;
    (void)str;
    return 0;
}

int check_flag(int ac, char **av, args_t *data, int j)
{
    if (j + 1 > ac)
        return 84;
    if (my_strcmp(av[j], "-dump") == 0)
        return dump_fct(av[j + 1], data);
    if (my_strcmp(av[j], "-n") == 0)
        return n_fct(av[j + 1], data);
    if (my_strcmp(av[j], "-a") == 0)
        return a_fct(av[j + 1], data);
    return 0;
}
