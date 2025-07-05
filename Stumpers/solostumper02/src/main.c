/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** Solo Stumper n°2
*/

#include "my.h"

int compare(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    for (int j = 0; str[j] != '\0'; j++)
        if (str[0] == '-' && str[1] == 'h' && i == 2)
            return 0;
    return 84;
}

int main(int ac, char **av)
{
    if (ac == 2 && compare(av[1]) == 0) {
        print_usage();
        return 0;
    }
    if (error_handling(ac) == 84)
        return 84;
    if (hidenp(av[1], av[2]) == 1)
        return 1;
    else if (hidenp(av[1], av[2]) == 0)
        return 0;
    else
        return 84;
    return 0;
}
