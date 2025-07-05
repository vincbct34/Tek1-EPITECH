/*
** EPITECH PROJECT, 2024
** secured
** File description:
** library
*/

#include "../includes/structure.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}

void my_putnbr(int nb)
{
    int i = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 10) {
        i = nb % 10;
        nb = nb / 10;
        my_putnbr(nb);
        my_putchar(i + 48);
    } else
        my_putchar(nb + 48);
}
