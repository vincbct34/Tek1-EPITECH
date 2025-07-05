/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-vincent.bichat
** File description:
** condition_aliases.c
*/

#include "../../include/my.h"

int flags_or_not(minishell_t *minishell)
{
    for (int i = 0; minishell->alias->command[i] != '\0'; i++) {
        if (minishell->alias->command[i] == ' ') {
            return 0;
        }
    }
    return 1;
}

int flags_or_not_two(alias_t *tmp)
{
    for (int i = 0; tmp->command[i] != '\0'; i++) {
        if (tmp->command[i] == ' ') {
            return 0;
        }
    }
    return 1;
}

int check_alias_loop_bis(alias_t *tmp, alias_t *tmp2, minishell_t *minishell)
{
    while (tmp2 != NULL) {
        if ((my_strcmp(tmp->alias, tmp2->command) == 0 ||
        my_strcmp(tmp->command, tmp2->alias) == 0) &&
        (my_strcmp(ARGS[0], tmp->alias) == 0 ||
        my_strcmp(ARGS[0], tmp->command) == 0 ||
        my_strcmp(ARGS[0], tmp2->command) == 0 ||
        my_strcmp(ARGS[0], tmp2->alias) == 0)){
            my_putstr("Alias loop.\n");
            return 0;
        }
        tmp2 = tmp2->next;
    }
    return 1;
}

int check_alias_loop(minishell_t *minishell)
{
    alias_t *tmp = minishell->alias;
    alias_t *tmp2 = minishell->alias;

    while (tmp != NULL) {
        if (check_alias_loop_bis(tmp, tmp2, minishell) == 0)
            return 0;
        tmp = tmp->next;
    }
    return 1;
}

int nbr_args_emi(char **args_emi)
{
    int count = 0;

    for (int i = 0; args_emi[i] != NULL; i++) {
        count++;
    }
    return count;
}
