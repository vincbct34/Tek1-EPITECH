/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** My_putstr and my_putchar
*/

#include <unistd.h>

static void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    int x = 0;

    while (str[x] != '\0') {
        my_putchar(str[x]);
        x++;
    }
}

void my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0 && nb <= 9)
        my_putchar(nb + 48);
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
}
