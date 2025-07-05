/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell2-vincent.bichat
** File description:
** my_setenv_tree.c
*/

#include "my.h"
#include "minishell.h"

static env_list *no_lines_again_tree(env_list *current)
{
    while (current->next != NULL)
        current = current->next;
    return current;
}

static void normal_setenv_tree(minishell *msh, env_list *new, char **command)
{
    env_list *current = msh->env_list;

    if (is_alpha_num(command[1]) == 1) {
        new->name = command[1];
        new->value = command[2];
        new->next = NULL;
        if (msh->env_list == NULL)
            msh->env_list = new;
        else {
            current = no_lines_again_tree(current);
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

void my_setenv_tree(minishell *msh, char **command)
{
    env_list *new = malloc(sizeof(env_list));

    if (command[1] == NULL) {
        my_env(msh);
        msh->return_value = 0;
        return;
    }
    if (command[2] == NULL) {
        if (is_alpha_num(command[1]) == 1) {
            command[2] = "\0";
        } else {
            my_puterror("setenv: Variable");
            my_puterror(" name must contain alphanumeric characters.\n");
            msh->return_value = 1;
            return;
        }
    }
    normal_setenv_tree(msh, new, command);
}
