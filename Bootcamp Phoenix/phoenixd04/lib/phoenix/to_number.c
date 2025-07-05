/*
** EPITECH PROJECT, 2023
** to_number.c
** File description:
** Bootcamp Day 3
*/

#include "../../includes/phoenix.h"
#include <stdbool.h>
#include <limits.h>

static int get_sign(char const *str, int *i)
{
    int sign = 1;

    while (str[*i] == '-' || str[*i] == '+') {
        if (str[*i] == '-')
            sign *= -1;
        *i = *i + 1;
    }
    return (sign);
}

static bool is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (true);
    return (false);
}

int to_number(char const *str)
{
    int i = 0;
    long long unsigned int nb = 0;
    int sign = get_sign(str, &i);

    while (str[i] != '\0' && is_digit(str[i])) {
        nb = nb * 10 + str[i] - '0';
        i++;
    }
    if ((nb > INT_MAX && sign == 1) || (nb > 2147483648 && sign == -1)
        || nb == ULLONG_MAX)
        nb = 0;
    return (nb * sign);
}
