/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-amazed-vincent.bichat
** File description:
** my_putnbr
*/

#include "lib.h"

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
