/*
** EPITECH PROJECT, 2024
** Solo Stumper 07
** File description:
** main.c
*/

#include "lib.h"
#include "stumper.h"

int print_usage(void)
{
    if (my_putstr("\n[USAGE]\n") == 84)
        return 84;
    if (my_putstr("  ./snakecase_formatter <string>\n\n") == 84)
        return 84;
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    if (snake_formatter(av[1]) == 84)
        return 84;
    return 0;
}
