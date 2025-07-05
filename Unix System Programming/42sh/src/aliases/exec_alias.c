/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-vincent.bichat
** File description:
** exec_alias.c
*/

#include "../../include/my.h"

void emi_write_error(minishell_t *minishell, char **args_emi)
{
    if (execve(INPUT, args_emi, ENV) && errno == ENOEXEC) {
        my_puterror(INPUT);
        my_puterror(": Exec format error. Wrong Architecture.\n");
    } else {
        my_puterror(INPUT);
        my_puterror(": Command not found.\n");
    }
}

int exec_alias_bis(minishell_t *minishell, char **args_emi, alias_t *tmp)
{
    if (my_strcmp(tmp->alias, ARGS[0]) == 0) {
        if (alias_with_param(minishell, args_emi, tmp) == 0)
            return 0;
        if (alias_with_flags(minishell, args_emi, tmp) == 0)
            return 0;
        ARGS[0] = my_strdup(tmp->command);
        verif_commands(minishell);
        return 0;
    }
    return 1;
}

int exec_alias(minishell_t *minishell)
{
    alias_t *tmp = minishell->alias;
    char **args_emi = NULL;

    if (check_alias_loop(minishell) == 0)
        return 0;
    while (tmp != NULL) {
        if (exec_alias_bis(minishell, args_emi, tmp) == 0)
            return 0;
        tmp = tmp->next;
    }
    return 1;
}
