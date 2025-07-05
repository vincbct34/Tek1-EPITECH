/*
** EPITECH PROJECT, 2024
** Prime Checker
** File description:
** main.c
*/

#include <stdlib.h>
#include <unistd.h>

int checker(int nb, int div)
{
    if (nb % div == 0) {
        if (write(1, "Not a prime number\n", 19) == -1)
            return 84;
        return 1;
    }
    return 0;
}

int main(int ac, char **av)
{
    int nb = 0;
    int return_value = 0;

    if (ac < 2)
        return 84;
    nb = atoi(av[1]);
    if (nb == 0)
        return 84;
    if (nb == 1)
        return 84;
    for (int div = 2; div < nb; div++) {
        return_value = checker(nb, div);
        if (return_value == 84)
            return 84;
        if (return_value == 1)
            return 0;
    }
    if (write(1, "OK\n", 3) == -1)
        return 84;
    return 0;
}
