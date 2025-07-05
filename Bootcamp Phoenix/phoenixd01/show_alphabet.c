/*
** EPITECH PROJECT, 2023
** show_alphabet.c
** File description:
** Display the alphabet
*/

#include "include/my.h"

int show_alphabet(void)
{
    for (char i = 97; i < 123; i++)
        my_putchar(i);
    return (0);
}
