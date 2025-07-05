/*
** EPITECH PROJECT, 2023
** Minishell 1
** File description:
** unsetenv.c
*/

#include "my.h"
#include "minishell.h"

static env_list *no_lines(minishell *msh, env_list *current)
{
    if (current == msh->env_list) {
        msh->env_list = current->next;
        msh->env = list_to_env(msh->env_list);
        return current;
    }
    return current;
}

static void no_lines_again_and_again(minishell *msh)
{
    my_puterror("unsetenv: Too few arguments.\n");
        msh->return_value = 1;
}

void my_unsetenv(minishell *msh)
{
    env_list *current = msh->env_list;
    env_list *prev = msh->env_list;

    if (msh->args[1] == NULL) {
        no_lines_again_and_again(msh);
        return;
    }
    while (current != NULL) {
        if (my_strcmp(current->name, msh->args[1]) == 0) {
            current = no_lines(msh, current);
            prev->next = current->next;
            free(current);
            msh->env = list_to_env(msh->env_list);
            msh->return_value = 0;
            return;
        }
        prev = current;
        current = current->next;
    }
    no_lines_again_and_again(msh);
}
