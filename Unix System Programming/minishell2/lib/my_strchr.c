/*
** EPITECH PROJECT, 2023
** Minishell 1
** File description:
** my_strchr.c
*/

int my_strchr(char *str, char c)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}
