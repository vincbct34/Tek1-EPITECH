/*
** EPITECH PROJECT, 2024
** my_putchar
** File description:
** Solo stumper n°1
*/

#include <unistd.h>

void my_putchar(char ch)
{
    write(1, &ch, 1);
}
