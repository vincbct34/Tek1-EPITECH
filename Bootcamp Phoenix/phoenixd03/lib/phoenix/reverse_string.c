/*
** EPITECH PROJECT, 2023
** reverse_string.c
** File description:
** Bootcamp Day 3
*/

#include "../../includes/phoenix.h"

char *reverse_string(char *str)
{
    int j = 0;
    int k = 0;
    char copy_str[2];

    for (int i = 0; str[i] != '\0'; i++)
        j++;
    while (k < j) {
        copy_str[0] = str[k];
        copy_str[1] = str[j - 1];
        str[k] = copy_str[1];
        str[j - 1] = copy_str[0];
        j--;
        k++;
    }
    return str;
}
