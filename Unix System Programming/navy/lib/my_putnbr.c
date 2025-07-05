/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** my_putnbr.c
*/

#include "../include/lib.h"
#include <unistd.h>

int my_putnbr(int nb)
{
    if (nb > 9)
        my_putnbr(nb / 10);
    else if (nb < 0) {
        nb = nb * -1;
        write(1, "-", 1);
        my_putnbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
    return (0);
}
