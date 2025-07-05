/*
** EPITECH PROJECT, 2023
** show_alphabet.c
** File description:
** Display the alphabet
*/

#include "include/my.h"

void show_combinations_bis(int i, int j)
{
    for (int k = j + 1; k < 10; k++) {
        my_putchar(i + 48);
        my_putchar(j + 48);
        my_putchar(k + 48);
        if (i != 7 || j != 8 || k != 9) {
            my_putchar(',');
            my_putchar(' ');
        }
    }
}

int show_combinations(void)
{
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++)
            show_combinations_bis(i, j);
    }
    return (0);
}
