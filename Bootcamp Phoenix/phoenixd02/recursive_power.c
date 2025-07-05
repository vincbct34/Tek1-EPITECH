/*
** EPITECH PROJECT, 2023
** recursive_power.c
** File description:
** Returns the first argument raised to the power p
*/

#include "include/my.h"

int recursive_power(int nb, int p)
{
    int result;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    if (p > 0)
        result = nb * recursive_power(nb, p - 1);
    return (result);
}
