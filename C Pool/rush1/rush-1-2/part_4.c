/*
** EPITECH PROJECT, 2023
** task4
** File description:
** rush1-3
*/

#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void height(int y)
{
    for (int i = 0; i < y; i++) {
        my_putchar('*');
        my_putchar('\n');
    }
}

void rush(int x, int y)
{
    if (x <= 0 || y <= 0 || x > INT_MAX || y > INT_MAX)
        write(1, "Invalid size\n", 14);
    height(y);
}
