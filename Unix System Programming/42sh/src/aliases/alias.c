/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-vincent.bichat
** File description:
** alias.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"

void print_flags(alias_t *tmp)
{
    char **str = my_str_to_word_array(tmp->command, "'");

    for (int i = 0; str[i] != NULL; i++)
        my_putstr(str[i]);
}

static void print_alias(alias_t *tmp)
{
    while (tmp != NULL) {
        my_putstr(tmp->alias);
        my_putstr("\t");
        if (flags_or_not_two(tmp) == 0) {
            my_putstr("(");
            print_flags(tmp);
            my_putstr(")");
        } else {
            print_flags(tmp);
        }
        my_putstr("\n");
        tmp = tmp->next;
    }
}

static void delete_alias_bis(alias_t *tmp, minishell_t *minishell,
    alias_t *prev, char *alias_name)
{
    if (my_strcmp(tmp->alias, alias_name) == 0) {
        if (prev == NULL)
            minishell->alias = tmp->next;
        else
            prev->next = tmp->next;
        free(tmp);
        return;
    }
}

static void delete_alias(minishell_t *minishell, char *alias_name)
{
    alias_t *tmp = minishell->alias;
    alias_t *prev = NULL;

    while (tmp != NULL) {
        delete_alias_bis(tmp, minishell, prev, alias_name);
        prev = tmp;
        tmp = tmp->next;
    }
}

static void alias_check_calls_bis(alias_t *tmp, minishell_t *minishell)
{
    if (my_strcmp(tmp->alias, ARGS[1]) == 0){
        print_flags(tmp);
        my_putstr("\n");
        return;
    }
}

void cond_to_add(minishell_t *minishell, alias_t *tmp)
{
    while (tmp != NULL) {
        if (my_strcmp(tmp->alias, ARGS[1]) == 0) {
            delete_alias(minishell, ARGS[1]);
            break;
        }
        tmp = tmp->next;
    }
    add_alias(minishell);
}

void alias_check_calls(minishell_t *minishell)
{
    alias_t *tmp = minishell->alias;

    if (ARGS[1] != NULL && ARGS[2] != NULL)
        cond_to_add(minishell, tmp);
    if (ARGS[1] != NULL && ARGS[2] == NULL) {
        while (tmp != NULL) {
            alias_check_calls_bis(tmp, minishell);
            tmp = tmp->next;
        }
    }
    tmp = minishell->alias;
    if (ARGS[1] == NULL)
        print_alias(tmp);
}

int exec_all_alias(minishell_t *minishell)
{
    if (ARGS[1] != NULL && my_strcmp(ARGS[1], "alias") == 0) {
        my_putstr("alias: Too dangerous to alias that.\n");
        return 0;
    }
    if (my_strcmp(ARGS[0], "alias") == 0) {
        alias_check_calls(minishell);
        return 0;
    }
    if (exec_alias(minishell) == 0)
        return 0;
    if (my_strcmp(ARGS[0], "unalias") == 0) {
        for (int i = 1; ARGS[i] != NULL; i++)
            delete_alias(minishell, ARGS[i]);
        return 0;
    }
    return 2;
}
