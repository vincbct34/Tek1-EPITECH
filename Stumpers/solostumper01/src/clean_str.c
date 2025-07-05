/*
** EPITECH PROJECT, 2024
** clean_str
** File description:
** Solo stumper n°1
*/

#include "my.h"

void no_lines(char *str, int i)
{
    int j = 0;

    while (str[i + j] == ' ')
        j++;
}

int clean_str(char *str)
{
    int i = 0;
    int len = my_strlen(str);

    if (str[0] == ' ')
        i++;
    if (str[len - 1])
        if (str[len] == ' ')
            return 0;
    for (; str[i] != '\0'; i++) {
        if (str[i] == ' ' && str[i + 1] == ' ') {
            no_lines(str, i);
            i++;
        }
        my_putchar(str[i]);
    }
    my_putchar('\n');
    return 0;
}
