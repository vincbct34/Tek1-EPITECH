/*
** EPITECH PROJECT, 2023
** my_strupcase.c
** File description:
** Puts every letter of every word in uppercase
*/

#include "include/my.h"

char *my_strupcase(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
    return (str);
}
