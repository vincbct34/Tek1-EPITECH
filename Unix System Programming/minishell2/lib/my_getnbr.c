/*
** EPITECH PROJECT, 2024
** Minishell 1
** File description:
** my_getnbr.c
*/

int my_getnbr(char *str)
{
    int i = 0;
    int neg = 1;
    int nb = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            neg = neg * -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10 + (str[i] - 48);
        i++;
    }
    return (nb * neg);
}
