/*
** EPITECH PROJECT, 2024
** Solo Stumper 5
** File description:
** main.c
*/

#include "my.h"
#include "luhn.h"

static int is_superior_to_nine(int nb, int total_nb)
{
    if (nb > 9)
        nb -= 9;
    total_nb += nb;
    return total_nb;
}

static int calculation(char **av)
{
    int nb = 0;
    int total_nb = 0;
    int len = my_strlen(av[1]);

    for (; len >= 0; len--) {
        if (my_getnbr(av[1][len]) == 84)
            return 84;
        nb = my_getnbr(av[1][len]);
        total_nb += nb;
        len--;
        if (my_getnbr(av[1][len]) == 84)
            return 84;
        nb = my_getnbr(av[1][len]);
        nb *= 2;
        total_nb = is_superior_to_nine(nb, total_nb);
    }
    return total_nb;
}

int main(int ac, char **av)
{
    int total_nb = 0;

    if (ac != 2)
        return 84;
    if (av[1][0] == '\0')
        return 84;
    total_nb = calculation(av);
    if (total_nb == 84)
        return 84;
    if (total_nb % 10 == 0) {
        if (my_putstr("valid\n") == 84)
            return 84;
    } else {
        if (my_putstr("invalid\n") == 84)
            return 84;
    }
}
