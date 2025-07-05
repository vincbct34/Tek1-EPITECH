/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** library
*/

void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
