/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-vincent.bichat
** File description:
** my_getnbr.c
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int neg = 1;
    int nb = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            neg = neg * -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10 + (str[i] - '0');
        i++;
    }
    return (nb * neg);
}
