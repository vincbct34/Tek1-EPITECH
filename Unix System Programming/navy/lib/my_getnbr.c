/*
** EPITECH PROJECT, 2018
** Navy
** File description:
** my_getnbr.c
*/

#include "../include/lib.h"

int my_getnbr(char *str)
{
    int val = 0;

    while (*str) {
        if (*str >= '0' && *str <= '9') {
            val *= 10;
            val += *str - '0';
        } else
            return (-1);
        str++;
    }
    return (val);
}
