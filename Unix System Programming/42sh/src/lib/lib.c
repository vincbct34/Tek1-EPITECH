/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** lib.c
*/

#include "../../include/my.h"

static void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
}

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return -1;
    for (; str[i] != '\0'; i++);
    return i;
}

static int show_number_long(long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10) {
        show_number(nb / 10);
        show_number(nb % 10);
    } else
        my_putchar(nb + '0');
    return 0;
}

int show_number(int nb)
{
    show_number_long(nb);
    return 0;
}

char *my_strdup(char *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    for (; dest[i] != '\0'; i++);
    for (; src[j] != '\0'; j++) {
        dest[i] = src[j];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
