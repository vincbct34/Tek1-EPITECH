/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** my_putstr.c
*/

#include "paint.h"

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}
