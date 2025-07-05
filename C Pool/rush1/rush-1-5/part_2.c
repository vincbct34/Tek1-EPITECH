/*
** EPITECH PROJECT, 2023
** rush1-3
** File description:
** task2
*/

#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static void first_line(int x)
{
    for (int i = 0; i < x; i++) {
            my_putchar('B');
    }
    my_putchar('\n');
}

void rush(int x, int y)
{
    if (x <= 0 || y <= 0 || x > INT_MAX || y > INT_MAX)
        write(1, "Invalid size\n", 14);
    first_line(x);
}
