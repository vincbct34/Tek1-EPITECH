/*
** EPITECH PROJECT, 2024
** Minishell 1
** File description:
** my_strlen.c
*/

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}
