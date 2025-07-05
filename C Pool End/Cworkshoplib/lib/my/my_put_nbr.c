/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** Library
*/

#include "my.h"
#include <stdio.h>
#include <unistd.h>

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
    }
    my_putchar('0' + (nb % 10));
    return 0;
}
