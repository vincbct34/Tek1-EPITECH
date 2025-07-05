/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** Library
*/

#include <stdio.h>
#include "my.h"
#include <stddef.h>

int my_getnbr(char const *str)
{
    int neg = 1;
    int n = 0;
    int i = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            neg = neg * -1;
        i = i + 1;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            n = n * 10;
            n = n + str[i] - '0';
            i = i + 1;
        } else {
            return (n * neg);
        }
    }
    return (n * neg);
}
