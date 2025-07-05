/*
** EPITECH PROJECT, 2023
** lib.c
** File description:
** Functions needed for Organised
*/

#include <stdlib.h>
#include <unistd.h>

static void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

char *my_strdup(char *str)
{
    int i = 0;
    char *new_str = malloc(sizeof(char) * my_strlen(str) + 1);

    while (str[i] != '\0') {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = '\0';
    return new_str;
}

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i++;
    }
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 10)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + 48);
    return 0;
}

int my_strcmp(char *str1, char *str2)
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i])
            return -1;
        if (str1[i] > str2[i])
            return 1;
        i++;
    }
    if (str1[i] == '\0' && str2[i] != '\0')
        return -1;
    if (str1[i] != '\0' && str2[i] == '\0')
        return 1;
    return 0;
}
