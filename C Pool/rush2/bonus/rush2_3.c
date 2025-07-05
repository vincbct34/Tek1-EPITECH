/*
** EPITECH PROJECT, 2023
** Rush2-3
** File description:
** Troisième partie
*/

#include <stdlib.h>
#include "include/my.h"

int count_char(char *str)
{
    int result = my_strlen(str);

    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] < 65 || str[i] > 90) && (str[i] < 97 || str[i] > 122))
            result--;
    return (result);
}

int displ_float(int nb)
{
    my_put_nbr(nb / 100);
    my_putchar('.');
    my_put_nbr((nb / 10) % 10);
    my_put_nbr(nb % 10);
    return (0);
}

void no_lines2(char *str, char *letter, char *up_low)
{
    int i = 0;
    int l = 0;
    int nb = 0;

    if (str[i] == letter[l] || str[i] == up_low[l])
        nb++;
}

void displ_multiple(int ac, char *str, char *letter, char *up_low)
{
    int nb = 0;

    for (int l = 0; l < ac - 2; l++) {
        for (int i = 0; str[i] != '\0'; i++)
            no_lines2(str, letter, up_low);
    my_putchar(letter[l]);
    my_putchar(':');
    my_put_nbr(nb);
    my_putstr(" (");
    displ_float(10000 * nb / count_char(str));
    my_putstr("%)");
    my_putchar('\n');
    nb = 0;
    }
}

int main(int ac, char **av)
{
    char *str = av[1];
    char *letter = malloc(sizeof(char) * (ac - 2));
    char *up_low = malloc(sizeof(char) * (ac - 2));

    for (int i = 0; i < ac - 2; i++) {
        letter[i] = av[i + 2][0];
        if (my_strlen(av[i + 2]) > 1 || ((letter[i] < 65 || letter[i] > 90) &&
            (letter[i] < 97 || letter[i] > 122)))
            return (84);
        if (letter[i] >= 65 && letter[i] <= 90)
            up_low[i] = letter[i] + 32;
        if (letter[i] >= 97 && letter[i] <= 122)
            up_low[i] = letter[i] - 32;
    }
    displ_multiple(ac, str, letter, up_low);
    return (0);
}
