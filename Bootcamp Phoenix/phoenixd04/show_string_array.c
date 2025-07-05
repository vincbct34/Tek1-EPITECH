/*
** EPITECH PROJECT, 2023
** show_string_array.c
** File description:
** Bootcamp Day 4
*/

#include "includes/phoenix.h"
#include <stdlib.h>

int show_string_array(char const **array)
{
    int i = 0;

    for (; array[i] != NULL; i++) {
        show_string(array[i]);
        my_putchar('\n');
    }
    return (0);
}
