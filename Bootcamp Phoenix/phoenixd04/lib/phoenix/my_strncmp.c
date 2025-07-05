/*
** EPITECH PROJECT, 2023
** my_strncmp.c
** File description:
** Bootcamp Day 3
*/

#include "../../includes/phoenix.h"

int my_strncmp(const char *s1, const char *s2, int n)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && i < n) {
        if (s1[i] < s2[i])
            return (-1);
        if (s1[i] > s2[i])
            return (1);
        i++;
    }
    if (i == n)
        return (0);
    if (s1[i] == '\0' && s2[i] != '\0')
        return (-1);
    if (s1[i] != '\0' && s2[i] == '\0')
        return (1);
    return (0);
}
