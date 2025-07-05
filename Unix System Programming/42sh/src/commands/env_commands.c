/*
** EPITECH PROJECT, 2024
** bsminishell1
** File description:
** env_function.c
*/

#include "../../include/my.h"

int print_env(minishell_t *minishell)
{
    for (int i = 0; ENV[i] != NULL; i++) {
        my_putstr(ENV[i]);
        my_putstr("\n");
    }
    return 0;
}

int set_env(minishell_t *minishell, char *name, char *value)
{
    if (push_back(minishell, &ENV_LIST, name, value) != 0)
        return 1;
    ENV = list_to_double_array(ENV_LIST);
    if (ENV == NULL)
        return 1;
    return 0;
}

int unset_env(minishell_t *minishell, char *name)
{
    if (delete_element(&ENV_LIST, name) != 0)
        return 1;
    ENV = list_to_double_array(ENV_LIST);
    if (ENV == NULL)
        return 1;
    return 0;
}
