/*
** EPITECH PROJECT, 2023
** Minishell 1
** File description:
** builtin.c
*/

#include "my.h"
#include "minishell.h"

void my_builtin(minishell *msh)
{
    if (my_strcmp(msh->args[0], "exit") == 0)
        my_exit(msh);
    if (my_strcmp(msh->args[0], "cd") == 0)
        my_cd(msh);
    if (my_strcmp(msh->args[0], "env") == 0)
        my_env(msh);
    if (my_strcmp(msh->args[0], "setenv") == 0)
        my_setenv(msh);
    if (my_strcmp(msh->args[0], "unsetenv") == 0)
        my_unsetenv(msh);
}
