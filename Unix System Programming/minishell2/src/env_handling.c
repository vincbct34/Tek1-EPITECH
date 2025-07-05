/*
** EPITECH PROJECT, 2023
** Minishell 1
** File description:
** env.c
*/

#include "my.h"
#include "minishell.h"

static void fill_list(env_list **list, env_list *new, env_list **tmp)
{
    if (*list == NULL) {
        *list = new;
        *tmp = *list;
    } else {
        (*tmp)->next = new;
        *tmp = new;
    }
}

env_list *env_to_list(char **env)
{
    env_list *list = NULL;
    env_list *tmp = NULL;
    env_list *new;
    char *token;

    for (int i = 0; env[i] != NULL; i++) {
        token = strtok(env[i], "=");
        if (token == NULL)
            continue;
        new = malloc(sizeof(env_list));
        new->name = my_strdup(token);
        token = strtok(NULL, "=");
        if (token == NULL)
            new->value = my_strdup("");
        else
            new->value = my_strdup(token);
        new->next = NULL;
        fill_list(&list, new, &tmp);
    }
    return list;
}

static int env_list_len(env_list *list)
{
    int i = 0;

    for (i = 0; list != NULL; i++)
        list = list->next;
    return i;
}

char **list_to_env(env_list *list)
{
    int i = 0;
    char **env = malloc(sizeof(char *) * (env_list_len(list) + 1));

    for (i = 0; list != NULL; i++) {
        env[i] = malloc(sizeof(char) * (my_strlen(list->name) +
        my_strlen(list->value) + 2));
        my_strcpy(env[i], list->name);
        my_strcat(env[i], "=");
        my_strcat(env[i], list->value);
        list = list->next;
    }
    env[i] = NULL;
    return env;
}
