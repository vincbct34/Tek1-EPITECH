/*
** EPITECH PROJECT, 2023
** Rush2_2
** File description:
** Deuxième partie
*/

#include <stdlib.h>
#include "my.h"

void no_lines2(char *str, char *letter, char *up_low, int l)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == letter[l] || str[i] == up_low[l])
            nb++;
    }
    my_putchar(letter[l]);
    my_putchar(':');
    my_put_nbr(nb);
    my_putchar('\n');
    nb = 0;
}

int displ(int ac, char *str, char *letter, char *up_low)
{
    int nb = 0;

    for (int l = 0; l < ac - 2; l++) {
        no_lines2(str, letter, up_low, l);
    }
    return 0;
}

int main(int ac, char **av)
{
    char *str = av[1];
    char *letter;
    char *up_low;

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
    displ(ac, str, letter, up_low);
    return (0);
}
