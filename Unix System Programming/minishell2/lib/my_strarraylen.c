/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell2-vincent.bichat
** File description:
** my_strarraylen.c
*/

#include "my.h"
#include "minishell.h"

int my_strarraylen(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    return i;
}
