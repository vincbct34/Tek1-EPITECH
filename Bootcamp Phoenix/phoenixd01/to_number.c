/*
** EPITECH PROJECT, 2023
** to_number.c
** File description:
** Get a number froma string
*/

#include "include/my.h"
#include <unistd.h>

int to_number_bis(char const *str, int *i, long int *nb, int *neg)
{
    if (str[*i] == '-')
        *neg *= -1;
    if (str[*i] >= '0' && str[*i] <= '9') {
        *nb = *nb * 10 + str[*i] - 48;
        if (str[*i + 1] < '0' || str[*i + 1] > '9')
            return 84;
    }
    return 0;
}

int to_number(char const *str)
{
    int i = 0;
    long int nb = 0;
    int neg = 1;

    for (; str[i] != '\0'; i++)
        if (to_number_bis(str, &i, &nb, &neg) == 84)
            break;
    if (nb > 2147483647 || nb < -2147483648)
        my_putchar('0');
    else
        return(nb * neg);
    return (0);
}
