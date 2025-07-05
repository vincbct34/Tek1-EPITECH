/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** Bootcamp Day 3
*/

#include "../../includes/phoenix.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}
