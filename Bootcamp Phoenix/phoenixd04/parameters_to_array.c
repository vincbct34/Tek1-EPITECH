/*
** EPITECH PROJECT, 2023
** parameters_to_array.c
** File description:
** Bootcamp Day 4
*/

#include "includes/phoenix.h"
#include <stdlib.h>

struct info_param *parameters_to_array(int ac, char **av)
{
    struct info_param *info = malloc(sizeof(struct info_param) * (ac + 1));
    int i = 0;

    for (; i < ac; i++) {
        info[i].str = av[i];
        info[i].length = my_strlen(av[i]);
        info[i].copy = duplicate_string(av[i]);
        info[i].word_array = split_string(info[i].str);
    }
    info[i].str = NULL;
    return info;
}
