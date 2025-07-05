/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-amazed-vincent.bichat
** File description:
** my_putchar
*/


#include "lib.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
