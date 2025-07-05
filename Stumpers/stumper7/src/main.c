/*
** EPITECH PROJECT, 2024
** Stumper 7
** File description:
** main.c
*/

#include "crocus.h"

void exit_all(stumper_t *stumper)
{
    if (stumper->argument != NULL)
        free(stumper->argument);
    if (stumper->str != NULL)
        free(stumper->str);
    free(stumper);
    exit(84);
}

void init_values(stumper_t *stumper)
{
    stumper->flag_n = false;
    stumper->flag_s = false;
    stumper->str = NULL;
    stumper->argument = NULL;
}

stumper_t *init_struct(int ac, char **av)
{
    stumper_t *stumper = malloc(sizeof(stumper_t));

    init_values(stumper);
    if (check_flags(ac, av) != 0) {
        free(stumper);
        return NULL;
    }
    if (choose_method(stumper, ac, av) != 0) {
        free(stumper);
        return NULL;
    }
    if (ac == 3)
        stumper->str = strdup("0\0");
    return stumper;
}

int main(int ac, char **av)
{
    stumper_t *stumper = NULL;

    if (ac != 5 && ac != 3)
        return 84;
    stumper = init_struct(ac, av);
    if (stumper == NULL)
        return 84;
    if (stumper->argument == NULL || stumper->str == NULL)
        exit_all(stumper);
    if (stumper->str[0] == '\0')
        exit_all(stumper);
    return logical_application(stumper);
}
