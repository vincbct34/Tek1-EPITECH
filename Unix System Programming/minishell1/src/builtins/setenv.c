/*
** EPITECH PROJECT, 2023
** Minishell 1
** File description:
** setenv.c
*/

#include "minishell.h"
#include "my.h"

static env_list *no_lines_again(env_list *current)
{
    while (current->next != NULL)
        current = current->next;
    return current;
}

static void normal_setenv(minishell *msh, env_list *new)
{
    env_list *current = msh->env_list;

    if (is_alpha_num(msh->args[1]) == 1) {
        new->name = msh->args[1];
        new->value = msh->args[2];
        new->next = NULL;
        if (msh->env_list == NULL)
            msh->env_list = new;
        else {
            current = no_lines_again(current);
            current->next = new;
        }
        msh->env = list_to_env(msh->env_list);
        msh->return_value = 0;
    } else {
        my_puterror("setenv: Variable");
        my_puterror(" name must contain alphanumeric characters.\n");
        msh->return_value = 1;
    }
}

void my_setenv(minishell *msh)
{
    env_list *new = malloc(sizeof(env_list));

    if (msh->args[1] == NULL) {
        my_env(msh);
        msh->return_value = 0;
        return;
    }
    if (msh->args[2] == NULL) {
        if (is_alpha_num(msh->args[1]) == 1) {
            msh->args[2] = "\0";
        } else {
            my_puterror("setenv: Variable");
            my_puterror(" name must contain alphanumeric characters.\n");
            msh->return_value = 1;
            return;
        }
    }
    normal_setenv(msh, new);
}
