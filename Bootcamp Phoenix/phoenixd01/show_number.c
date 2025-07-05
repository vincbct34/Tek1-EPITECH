/*
** EPITECH PROJECT, 2023
** show_number.c
** File description:
** Display a number
*/

#include "include/my.h"

int show_number(int nb)
{
    long int nb2 = nb;

    if (nb2 < 0) {
        my_putchar('-');
        nb2 = nb2 * -1;
    }
    if (nb2 >= 10)
        show_number(nb2 / 10);
    my_putchar(nb2 % 10 + 48);
    return (0);
}
