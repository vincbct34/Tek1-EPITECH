/*
** EPITECH PROJECT, 2024
** stumper
** File description:
** duo
*/

#include "my.h"

int main(int ac, char **av)
{
    if (ac < 2 || ac > 5)
        return 84;
    if (ac == 2) {
        if (basic_count(av[1]) == 84)
            return 84;
    }
    if (ac == 3) {
        if (handle_three_args(av, ac) == 84)
            return 84;
    }
    if (ac == 4) {
        if (handle_four_args(av, ac) == 84)
            return 84;
    }
    if (ac == 5) {
        if (handle_five_args(av, ac) == 84)
            return 84;
    }
    return 0;
}
