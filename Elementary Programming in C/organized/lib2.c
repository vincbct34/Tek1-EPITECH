/*
** EPITECH PROJECT, 2023
** lib2.c
** File description:
** Functions needed for Organised
*/

#include <stdlib.h>
#include <unistd.h>

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;
    int neg = 1;

    if (str == NULL)
        return (0);
    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            neg = neg * -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10 + (str[i] - 48);
        i++;
    }
    nb = nb * neg;
    return (nb);
}

int is_nbr(char *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i]) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}
