/*
** EPITECH PROJECT, 2023
** iterative_factorial.c
** File description:
** Returns the factorial of a number
*/

#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>

int iterative_factorial(int nb)
{
    int i = nb;

    if (nb == 0) {
        return 1;
    }
    if (nb < 0 || nb > 12) {
        return 0;
    }
    while (i > 1) {
        i--;
        nb = i * nb;
    }
    return nb;
}
