/*
** EPITECH PROJECT, 2024
** Solo Stumper 5
** File description:
** my_strlen.c
*/

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i - 1;
}
