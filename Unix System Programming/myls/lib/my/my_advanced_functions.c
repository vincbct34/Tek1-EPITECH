/*
** EPITECH PROJECT, 2023
** my_advanced_functions
** File description:
** All the necessary of my_printf
*/

#include "my.h"
#include <unistd.h>

int my_put_float(double nb)
{
    int i = nb;
    int j = nb * 1000000;
    double k = j - i * 1000000;

    if (nb < 0)
        k = k * (-1);
    if (i == 0 && nb < 0)
        my_putchar('-');
    if ((nb * 10000000 - j * 10) > 4 || (nb * 10000000 - j * 10) < -4)
        k = k + 1;
    my_put_nbr(i);
    my_putchar('.');
    for (int z = 0; z + my_intlen(k) < 6; z++)
        my_putchar('0');
    my_put_nbr(k);
    return 0;
}

void no_lines(int count)
{
    if (count < 10)
        my_putchar('0');
    if (count < 0)
        count *= -1;
    my_put_nbr(count);
}

void no_spaces(int count)
{
    if (count < 0)
        my_putchar('-');
    else
        my_putchar('+');
}

int my_put_scientific_up(double nb)
{
    int count = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    while (nb >= 10) {
        nb /= 10;
        count++;
    }
    while (nb < 1 && nb > 0) {
        nb *= 10;
        count--;
    }
    my_put_float(nb);
    my_putchar('E');
    no_spaces(count);
    no_lines(count);
    return 0;
}

int my_put_scientific_low(double nb)
{
    int count = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    while (nb >= 10) {
        nb /= 10;
        count++;
    }
    while (nb < 1 && nb > 0) {
        nb *= 10;
        count--;
    }
    my_put_float(nb);
    my_putchar('e');
    no_spaces(count);
    no_lines(count);
    return 0;
}
