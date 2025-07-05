/*
** EPITECH PROJECT, 2023
** lib.c
** File description:
** Functions needed for Setting Up project
*/

#include <stdbool.h>
#include <unistd.h>

int my_getnbr(char const *str)
{
    int start = 0;
    int init = 0;
    int nbr = 0;

    while (str[init] != '\0' && str[init] != '\n' && (str[init] < 48 ||
            str[init] > 57)) {
        init++;
    }
    if (str[init] == '\0')
        return 0;
    start = init;
    while (str[start] >= 48 && str[start] <= 57) {
        nbr = nbr * 10 + str[start] - 48;
        start++;
    }
    return nbr;
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i++;
    }
    return 0;
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

int my_is_digit(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 48 || str[i] > 57)
            return 1;
        i++;
    }
    return 0;
}
