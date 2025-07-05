/*
** EPITECH PROJECT, 2023
** my_print_revalpha.c
** File description:
** task02 day 3
*/

#include <unistd.h>

void my_putchar(char c);

int my_print_revalpha(void)
{
    for (char i = 'z'; i >= 'a'; i--) {
        my_putchar(i);
    }
    return (0);
}
