/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell2-vincent.bichat
** File description:
** my_unsetenv_tree.c
*/

#include "my.h"
#include "minishell.h"

static env_list *no_lines_tree(minishell *msh, env_list *current)
{
    if (current == msh->env_list) {
        msh->env_list = current->next;
        msh->env = list_to_env(msh->env_list);
        return current;
    }
    return current;
}

static void no_lines_again_and_again_tree(minishell *msh)
{
    my_puterror("unsetenv: Too few arguments.\n");
        msh->return_value = 1;
}

void my_unsetenv_tree(minishell *msh, char **command)
{
    env_list *current = msh->env_list;
    env_list *prev = msh->env_list;

    if (command[1] == NULL) {
        no_lines_again_and_again_tree(msh);
        return;
    }
    while (current != NULL) {
        if (my_strcmp(current->name, command[1]) == 0) {
            current = no_lines_tree(msh, current);
            prev->next = current->next;
            msh->env = list_to_env(msh->env_list);
            msh->return_value = 0;
            return;
        }
        prev = current;
        current = current->next;
    }
    no_lines_again_and_again_tree(msh);
}
