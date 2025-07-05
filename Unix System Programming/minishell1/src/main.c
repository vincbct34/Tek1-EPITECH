/*
** EPITECH PROJECT, 2023
** Minishell 1
** File description:
** main.c
*/

#include "my.h"
#include "minishell.h"

int main(int ac, char **, char **env)
{
    minishell *msh = malloc(sizeof(minishell));

    msh->env_list = env_to_list(env);
    msh->env = list_to_env(msh->env_list);
    if (ac != 1) {
        my_puterror("Error: No arguments needed.\n");
        return 84;
    }
    my_minishell(msh);
    return msh->return_value;
}
