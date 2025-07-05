/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** Second graphical project
*/

#include <unistd.h>

static void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putnbr(int nb)
{
    int modulo = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 10) {
        modulo = nb % 10;
        nb = nb / 10;
        my_putnbr(nb);
        my_putchar(48 + modulo);
    } else
        my_putchar(48 + nb % 10);
    return (0);
}
