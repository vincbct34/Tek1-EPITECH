/*
** EPITECH PROJECT, 2023
** my_print_digits.c
** File description:
** task03 day 3
*/

#include <unistd.h>

void my_putchar(char c);

int my_print_digits(void)
{
    for (int i = '0'; i <= '9'; i++) {
        my_putchar(i);
    }
    return (0);
}
