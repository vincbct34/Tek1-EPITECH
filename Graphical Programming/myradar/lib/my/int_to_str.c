/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "my.h"

static void no_spaces(char *strnum, unsigned int i, int nb)
{
    while (nb != 0) {
        i++;
        strnum[i] = nb % 10 + '0';
        nb = nb / 10;
    }
}

char *int_to_str(int nb)
{
    char *strnum = malloc(sizeof(char) * (my_intlen(nb) + 2));
    unsigned int i = 0;
    bool is_neg = (nb < 0) ? true : false;

    if (nb < 0) {
        if (nb == INT_MIN)
            return ("-2147483648");
        nb = -nb;
    } else if (nb == 0)
        return ("0");
    no_spaces(strnum, i, nb);
    if (is_neg) {
        i++;
        strnum[i] = '-';
    }
    strnum[i] = '\0';
    return (my_revstr(strnum));
}
