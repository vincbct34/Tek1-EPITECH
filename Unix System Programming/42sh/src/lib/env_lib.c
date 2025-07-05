/*
** EPITECH PROJECT, 2024
** bsminishell1
** File description:
** env_lib.c
*/

#include "../../include/my.h"

static int check_name(env_t *new, char *name)
{
    if (is_alpha(name) == 1) {
        new->name = my_strdup(name);
    } else {
        my_puterror("setenv: Variable");
        my_puterror(" name must contain alphanumeric characters.\n");
        return 1;
    }
    return 0;
}

static int name_null(minishell_t *minishell, char *name)
{
    if (name == NULL) {
        print_env(minishell);
        return 1;
    }
    return 0;
}

static env_t *create_new_env_node(minishell_t *minishell, char *name,
    char *value)
{
    env_t *new = NULL;

    if (name_null(minishell, name) == 1)
        return NULL;
    new = malloc(sizeof(env_t));
    if (new == NULL || check_name(new, name) == 1) {
        free(new);
        return NULL;
    }
    if (value != NULL) {
        new->value = my_strdup(value);
        if (new->value == NULL) {
            free(new);
            return NULL;
        }
    } else
        new->value = "\0";
    new->next = NULL;
    return new;
}

static void append_env_node(env_t **list, env_t *new)
{
    env_t *tmp = NULL;

    if (*list == NULL) {
        *list = new;
    } else {
        tmp = *list;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new;
    }
}

int push_back(minishell_t *minishell, env_t **list, char *name, char *value)
{
    env_t *new = create_new_env_node(minishell, name, value);

    if (new == NULL) {
        return 1;
    }
    append_env_node(list, new);
    return 0;
}

static void free_delete(env_t *tmp)
{
    free(tmp->name);
    if (tmp->value != NULL)
        free(tmp->value);
    free(tmp);
}

int delete_element(env_t **list, char *name)
{
    env_t *tmp = *list;
    env_t *prev = NULL;

    if (name == NULL)
        return 1;
    if (tmp != NULL && my_strcmp(tmp->name, name) == 0) {
        *list = tmp->next;
        free_delete(tmp);
        return 0;
    }
    while (tmp != NULL && my_strcmp(tmp->name, name) != 0) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return 1;
    prev->next = tmp->next;
    free_delete(tmp);
    return 0;
}

char *my_strndup(char *str, int n)
{
    char *new = malloc(sizeof(char) * (n + 1));

    if (new == NULL)
        return NULL;
    for (int i = 0; i < n; i++)
        new[i] = str[i];
    new[n] = '\0';
    return new;
}
