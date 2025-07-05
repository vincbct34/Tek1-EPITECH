/*
** EPITECH PROJECT, 2023
** Minishell 1
** File description:
** env.c
*/

#include "my.h"
#include "minishell.h"

void my_env(minishell *msh)
{
    for (int i = 0; msh->env[i] != NULL; i++) {
        my_putstr(msh->env[i]);
        my_putchar('\n');
    }
    msh->return_value = 0;
}
