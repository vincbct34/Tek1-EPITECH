/*
** EPITECH PROJECT, 2017
** my_show_word_array
** File description:
** Task03
*/

#include "mylib.h"

int my_putchar(char c);
int my_putstr(char const *d);

int my_show_word_array(char const **tab)
{
    int i = 0;

    while (tab[i] != 0) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
    return 0;
}
