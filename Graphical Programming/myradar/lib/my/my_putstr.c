/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#include <unistd.h>

void my_putstr(char const *str)
{
    for (unsigned int i = 0; str[i]; i++)
        write(1, &(str[i]), 1);
}
