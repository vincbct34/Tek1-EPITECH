/*
** EPITECH PROJECT, 2023
** my_isneg.c
** File description:
** task04 day 3
*/

#include <unistd.h>

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else if (n >= 0) {
        my_putchar('P');
    }
    return (0);
}
