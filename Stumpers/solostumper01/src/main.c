/*
** EPITECH PROJECT, 2024
** main
** File description:
** Solo stumper n°1
*/

#include "my.h"
#include <stdlib.h>

int main(int ac, char **av)
{
    if (ac == 1) {
        my_putstr("\n");
        return 0;
    }
    if (ac > 2)
        return 84;
    clean_str(av[1]);
    return 0;
}
