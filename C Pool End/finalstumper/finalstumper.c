/*
** EPITECH PROJECT, 2023
** finalstumper
** File description:
** main file
*/

#include <unistd.h>
#include "include/rush3.h"
#include <stdio.h>


int coords_x(char *str)
{
    int len_x = 0;

    for (int j = 0; str[j] != '\n'; j++)
        len_x += 1;
    return (len_x);
}

int coords_y(char *str)
{
    int len_y = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            len_y += 1;
    }
    return (len_y);
}

static void special_display(char *str, int rush)
{
    if (rush == 6) {
        my_putstr("[rush1-3] ");
        my_put_nbr(coords_x(str));
        my_putchar(' ');
        my_put_nbr(coords_y(str));
        my_putstr(" || [rush1-4] ");
        my_put_nbr(coords_x(str));
        my_putchar(' ');
        my_put_nbr(coords_y(str));
        my_putstr(" || [rush1-5] ");
        my_put_nbr(coords_x(str));
        my_putchar(' ');
        my_put_nbr(coords_y(str));
        my_putchar('\n');
    }
}

static void display(char *str, int rush)
{
    if (rush == 1)
        my_putstr("[rush1-1] ");
    if (rush == 2)
        my_putstr("[rush1-2] ");
    if (rush == 3)
        my_putstr("[rush1-3] ");
    if (rush == 4)
        my_putstr("[rush1-4] ");
    if (rush == 5)
        my_putstr("[rush1-5] ");
    my_put_nbr(coords_x(str));
    my_putchar(' ');
    my_put_nbr(coords_y(str));
    my_putchar('\n');
}

static void special_rush(char *str)
{
    int i = 0;

    while (str[i] != '\n')
        i++;
    if (str[i - 1] == 'A')
        display(str, 3);
    else if (str[my_strlen(str) - 2] == 'C')
        display(str, 4);
    else
        display(str, 5);
}

void rush3(char *str)
{
    if (coords_x(str) <= 0 || coords_y(str) <= 0) {
        my_putstr("none\n");
        return;
    }
    if (coords_x(str) * coords_y(str) > 4096) {
        my_putstr("none\n");
        return;
    }
    if (str[0] == 'o')
        display(str, 1);
    if (str[0] == '/' || str[0] == '*')
        display(str, 2);
    if (str[0] == 'B' && str[1] == 'B')
        special_display(str, 6);
    if (str[0] == 'A')
        special_rush(str);
}

int main(void)
{
    char buff[BUFSIZ + 1];
    int offset = 0;
    int len = read(0, buff + offset, BUFSIZ - offset);

    while (len > 0) {
        offset = offset + len;
        len = read(0, buff + offset, BUFSIZ - offset);
    }
    buff[offset] = '\0';
    if (len < 0)
        return 84;
    rush3(buff);
    return 0;
}
