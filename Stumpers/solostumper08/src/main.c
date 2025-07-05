/*
** EPITECH PROJECT, 2024
** Fibonacci Checker
** File description:
** main.c
*/

#include <stdlib.h>
#include <unistd.h>

int error_handling(int nb_params)
{
    if (nb_params <= 1)
        return 84;
    if (nb_params > 1 && nb_params <= 3) {
        if (write(1, "Not a Fibonacci sequence\n", 25) == -1)
            return 84;
        return 1;
    }
    return 0;
}

int checker(char *str_before, char *str_before_bis, int nb)
{
    if (atoi(str_before) + atoi(str_before_bis) != nb) {
        if (write(1, "Not a Fibonacci sequence\n", 25) == -1)
            return 84;
        return 1;
    } else
        return 2;
    return 0;
}

int main(int ac, char **av)
{
    int return_value = 0;

    return_value = error_handling(ac);
    if (return_value == 84)
        return 84;
    if (return_value == 1)
        return 0;
    for (int i = 3; av[i]; i++) {
        return_value = checker(av[i - 1], av[i - 2], atoi(av[i]));
        if (return_value == 84)
            return 84;
        if (return_value == 1)
            return 0;
        if (return_value == 2)
            continue;
    }
    if (write(1, "OK\n", 3) == -1)
        return 84;
    return 0;
}
