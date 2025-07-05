/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** Swap the content of two integers
*/

#include <unistd.h>

void my_swap(int *a, int *b)
{
    int f = *a;

    *a = *b;
    *b = f;
}
