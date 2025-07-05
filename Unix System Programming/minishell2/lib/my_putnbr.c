/*
** EPITECH PROJECT, 2024
** Minishell 1
** File description:
** my_putnbr.c
*/

#include "my.h"

void my_putnbr(int nb)
{
    long int nb2 = nb;

    if (nb2 < 0) {
        my_putchar('-');
        nb2 = nb2 * -1;
    }
    if (nb2 >= 10)
        my_putnbr(nb2 / 10);
    my_putchar(nb2 % 10 + 48);
}
