/*
** EPITECH PROJECT, 2023
** rush1
** File description:
** task01
*/

#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void no_lines(int n)
{
    for (int i = 0; i <= n - 1; i ++) {
        if (i < 1 || i == n - 1)
            my_putchar('*');
        else
            my_putchar(' ');
    }
}

void first_line(int x)
{
    for (int i = 0; i < x; i++) {
        if (i < 1)
            my_putchar('/');
        if (i == x - 1)
            my_putchar(92);
        else
            my_putchar('*');
    }
    my_putchar('\n');
}

void height(int x, int y)
{
    int j = 0;

    while (j < y - 2) {
        no_lines(x);
        j++;
        my_putchar('\n');
    }
}

void last_line(int x)
{
    for (int i = 0; i < x; i++) {
        if (i < 1)
            my_putchar(92);
        if (i == x - 1)
            my_putchar('/');
        else
            my_putchar('*');
    }
    my_putchar('\n');
}

void rush(int x, int y)
{
    if (x == 1 && y == 1) {
        my_putchar('*');
        my_putchar('\n');
    } else if (x <= 0 || y <= 0 || x > INT_MAX || y > INT_MAX) {
        write(1, "Invalid size\n", 14);
    } else {
    first_line(x);
    height(x, y);
    if (y > 1)
        last_line(x);
    }
}
