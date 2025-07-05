/*
** EPITECH PROJECT, 2023
** my_second_basics
** File description:
** All the basics of LibC
*/

#include "myprintf.h"
#include <unistd.h>

int my_intlen(long long n)
{
    int count = 0;

    if (n == 0)
        return 1;
    while (n != 0) {
        n = n / 10;
        ++count;
    }
    return count;
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int my_compute_power_rec(int nb, int p)
{
    int result;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    if (p > 0)
        result = nb * my_compute_power_rec(nb, p - 1);
    return (result);
}

int my_strncmp(const char *s1, const char *s2, int n)
{
    if (n == 0)
        return 0;
    for (int i = 0; i < n; i++) {
        if (s1[i] == '\0' || s2[i] == '\0')
            return 0;
        if (s1[i] != s2[i])
            return (int)(s1[i]) - (int)(s2[i]);
    }
    return 0;
}
