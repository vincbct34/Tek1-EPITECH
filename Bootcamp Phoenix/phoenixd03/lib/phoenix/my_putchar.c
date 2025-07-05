/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** Bootcamp Day 3
*/

#include "../../includes/phoenix.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
