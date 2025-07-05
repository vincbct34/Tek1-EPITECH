/*
** EPITECH PROJECT, 2023
** my_second_basics
** File description:
** All the basics of LibC
*/

#include "include/rush3.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
