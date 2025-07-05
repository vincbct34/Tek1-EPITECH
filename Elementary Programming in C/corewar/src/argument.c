/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** argument.c
*/

#include "corewar.h"

int check_args(int ac, char **av, corewar_t *corewar)
{
    args_t *data = init_data(corewar);
    int i = 1;

    print_usage(ac, av);
    while (i < ac) {
        if (av[i][0] == '-' && check_flag(ac, av, data, i) != 84)
            i += 2;
        if (av[i][0] != '-' && check_file(av[i], corewar, data) != 84)
            i++;
        if (av[i][0] != '-' && (check_file(av[i], corewar, data) == 84
            || check_flag(ac, av, data, i) == 84))
            return 84;
    }
    return 0;
}
