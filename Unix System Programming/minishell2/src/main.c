/*
** EPITECH PROJECT, 2023
** Minishell 1
** File description:
** main.c
*/

#include "my.h"
#include "minishell.h"

static void free_env_list(minishell *msh)
{
    env_list *cur = msh->env_list;
    env_list *next = NULL;

    while (cur != NULL) {
        next = cur->next;
        free(cur->name);
        free(cur->value);
        free(cur);
        cur = next;
    }
}

static void main_free(minishell *msh)
{
    if (msh->input != NULL)
        free(msh->input);
    if (msh->basic_args != NULL)
        free(msh->basic_args);
    if (msh->tree != NULL)
        free(msh->tree);
    if (msh->env != NULL)
        free(msh->env);
    if (msh->env_list != NULL)
        free_env_list(msh);
    free(msh);
}

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
    main_free(msh);
    return msh->return_value;
}
