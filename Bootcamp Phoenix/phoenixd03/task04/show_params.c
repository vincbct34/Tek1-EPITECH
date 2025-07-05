/*
** EPITECH PROJECT, 2023
** show_params.c
** File description:
** Bootcamp Day 3
*/

#include "../includes/phoenix.h"

int show_params(int argc, char **argv)
{
    for (int i = 0; i < argc; i++) {
        show_string(argv[i]);
        my_putchar('\n');
    }
    return (0);
}

int main(int argc, char **argv)
{
    show_params(argc, argv);
    return (0);
}
