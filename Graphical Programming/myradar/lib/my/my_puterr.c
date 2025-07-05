/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#include <unistd.h>

void my_puterr(char const *str)
{
    for (unsigned int i = 0; str[i]; i++)
        write(2, &(str[i]), 1);
}
