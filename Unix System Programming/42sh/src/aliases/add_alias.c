/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-vincent.bichat
** File description:
** add_alias.c
*/

#include "../../include/my.h"

void create_com(alias_t *new_alias, minishell_t *minishell)
{
    char *tmp = NULL;

    for (int i = 3; ARGS[i] != NULL; i++) {
        tmp = my_strdup(new_alias->command);
        new_alias->command = my_strdup(my_strcat2(tmp, ARGS[i]));
        if (ARGS[i + 1] != NULL)
            new_alias->command = my_strdup(my_strcat2(tmp, " "));
        free(tmp);
    }
}

void add_alias_bis(minishell_t *minishell, alias_t *new_alias)
{
    char *tmp = NULL;

    if (ARGS[3] != NULL) {
        tmp = my_strdup(minishell->args[2]);
        new_alias->command = my_strdup(my_strcat2(tmp, " "));
        free(tmp);
        create_com(new_alias, minishell);
    }
}

void add_alias(minishell_t *minishell)
{
    alias_t *new_alias = malloc(sizeof(alias_t));
    alias_t *tmp = minishell->alias;

    new_alias->alias = minishell->args[1];
    add_alias_bis(minishell, new_alias);
    if (ARGS[3] == NULL)
        new_alias->command = my_strdup(minishell->args[2]);
    new_alias->next = NULL;
    if (minishell->alias == NULL) {
        minishell->alias = new_alias;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_alias;
}
