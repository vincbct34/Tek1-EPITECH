/*
** EPITECH PROJECT, 2023
** is_prime_number.c
** File description:
** Bootcamp Day 3
*/

#include "../../includes/phoenix.h"

int is_prime_number(int nb)
{
    int i = 2;

    if ((nb % 2 == 0 && nb != 2) || nb <= 1)
        return (0);
    while (nb % i != 0 && i <= nb / 2) {
        i++;
    }
    if (nb % i != 0 || i == nb)
        return (1);
    return (0);
}
