/*
** EPITECH PROJECT, 2023
** show_parameters_array.c
** File description:
** Bootcamp Day 4
*/

#include "includes/phoenix.h"
#include <stdlib.h>

int show_parameters_array(struct info_param const *par)
{
    int i = 0;

    while (par[i].str != NULL) {
        show_string(par[i].str);
        my_putchar('\n');
        show_number(par[i].length);
        my_putchar('\n');
        show_string_array((char const **)par[i].word_array);
        i++;
    }
    return 0;
}
