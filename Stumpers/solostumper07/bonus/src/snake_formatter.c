/*
** EPITECH PROJECT, 2024
** Solo Stumper 07
** File description:
** snake_formatter.c
*/

#include "lib.h"

static int skip_if_first_space(char c, int i)
{
    if (i == 0)
        if (c == ' ')
            return 84;
    return 0;
}

static int break_if_last_space(char c, int i, int len)
{
    if (i == len - 1)
        if (c == ' ')
            return 84;
    return 0;
}

static int conditions_of_print(char c)
{
    if (c >= 'A' && c <= 'Z')
        c += 32;
    if ((c < 'a' || c > 'z') && (c < '0' || c > '9'))
        c = '_';
    if (my_putchar(c) == 84)
        return 84;
    return 0;
}

static int is_whole_word(char *str, int i)
{
    if (str[i] > 'a' && str[i] < 'z')
        if (str[i + 1] > '0' && str[i + 1] < '9')
            return 0;
    if (str[i] > '0' && str[i] < '9')
        if (str[i + 1] > 'a' && str[i + 1] < 'z')
            return 0;
    return 1;
}

int is_multiple_space(char *str, int i)
{
    if (str[i] == ' ' && str[i - 1] == ' ')
        return 84;
    else
        if (conditions_of_print(str[i]) == 84)
            return 84;
    return 0;
}

int snake_formatter(char *str)
{
    int len = my_strlen(str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (skip_if_first_space(str[i], i) == 84)
            i++;
        if (break_if_last_space(str[i], i, len) == 84)
            break;
        if (is_multiple_space(str, i) == 84)
            continue;
        if (is_whole_word(str, i) == 0)
            my_putchar('_');
    }
    if (my_putchar('\n') == 84)
        return 84;
    return 0;
}
