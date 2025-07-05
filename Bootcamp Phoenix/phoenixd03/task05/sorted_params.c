/*
** EPITECH PROJECT, 2023
** show_params.c
** File description:
** Bootcamp Day 3
*/

#include "../includes/phoenix.h"
#include <stddef.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;
    if (s1[i] > s2[i])
        return (1);
    if (s1[i] < s2[i])
        return (-1);
    else
        return (0);
}

void sorted_params_bis(int, char **argv, int i, int j)
{
    char *tmp = NULL;

    if (my_strcmp(argv[i], argv[j]) > 0) {
        tmp = argv[i];
        argv[i] = argv[j];
        argv[j] = tmp;
    }
}

int sorted_params(int argc, char **argv)
{
    for (int i = 0; i < argc; i++) {
        for (int j = i + 1; j < argc; j++)
            sorted_params_bis(argc, argv, i, j);
        show_string(argv[i]);
        my_putchar('\n');
    }
    return (0);
}

int main(int argc, char **argv)
{
    sorted_params(argc, argv);
    return (0);
}
