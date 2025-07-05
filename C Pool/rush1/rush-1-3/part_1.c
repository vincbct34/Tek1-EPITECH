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

static void no_lines(int n)
{
    for (int i = 0; i <= n - 1; i ++) {
        if (i < 1 || i == n - 1)
            my_putchar('B');
        else
            my_putchar(' ');
    }
}

static void first_line(int x, int y)
{
    for (int i = 0; i < x; i++) {
        if (i < 1 || i == x - 1 )
            my_putchar('A');
        else
            my_putchar('B');
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
        if (i < 1 || i == x - 1)
            my_putchar('C');
        else
            my_putchar('B');
    }
    my_putchar('\n');
}

void rush(int x, int y)
{
    if (x <= 0 || y <= 0 || x > INT_MAX || y > INT_MAX)
        write(1, "Invalid size\n", 14);
    first_line(x, y);
    height(x, y);
    if (y > 1)
        last_line(x);
}
