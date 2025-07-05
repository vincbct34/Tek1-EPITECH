/*
** EPITECH PROJECT, 2023
** Minishell 1
** File description:
** exit.c
*/

#include "my.h"
#include "minishell.h"

void my_exit(minishell *msh)
{
    if (msh->basic_args[1] != NULL) {
        my_putstr("exit\n");
        exit(my_getnbr(msh->basic_args[1]));
    } else {
        my_putstr("exit\n");
        exit(0);
    }
}
