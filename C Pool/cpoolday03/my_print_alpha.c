/*
** EPITECH PROJECT, 2023
** my_print_alpha.c
** File description:
** task01 day 3
*/

#include <unistd.h>

void my_putchar(char c);

int my_print_alpha(void)
{
    for (char i = 'a'; i <= 'z'; i++) {
        my_putchar(i);
    }
    return (0);
}
