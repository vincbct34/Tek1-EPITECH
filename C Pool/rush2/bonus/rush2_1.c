/*
** EPITECH PROJECT, 2023
** Rush2-1
** File description:
** Première partie
*/

#include "my.h"

int no_lines(int ac, char **av, char letter)
{
    if (ac > 3 || my_strlen(av[2]) > 1 || ((letter < 65 || letter > 90)))
        return 84;
    if (letter < 97 || letter > 122)
        return 84;
}

int main(int ac, char **av)
{
    char *str = av[1];
    char letter = av[2][0];
    char up_low;
    int nb = 0;

    no_lines(ac, av, letter);
    if (letter >= 65 && letter <= 90)
        up_low = letter + 32;
    if (letter >= 97 && letter <= 122)
        up_low = letter - 32;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == letter || str[i] == up_low)
            nb++;
    my_putchar(letter);
    my_putchar(':');
    my_put_nbr(nb);
    my_putchar('\n');
    return (0);
}
