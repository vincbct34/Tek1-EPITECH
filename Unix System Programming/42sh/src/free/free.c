/*
** EPITECH PROJECT, 2024
** bsminishell1
** File description:
** free.c
*/

#include "../../include/my.h"

void free_alias(minishell_t *minishell)
{
    alias_t *tmp = minishell->alias;
    alias_t *next = NULL;

    while (tmp != NULL) {
        next = tmp->next;
        free(tmp->alias);
        free(tmp->command);
        free(tmp);
        tmp = next;
    }
}

void free_all(minishell_t *minishell)
{
    free(minishell->input);
    free(minishell->args);
    free(minishell->env);
    free_alias(minishell);
}

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}
