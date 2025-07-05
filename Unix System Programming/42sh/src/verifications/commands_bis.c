/*
** EPITECH PROJECT, 2024
** B-PSU-200-MPL-2-1-42sh-vincent.bichat [WSL: Ubuntu-22.04]
** File description:
** commands_bis
*/

#include "../../include/my.h"

static int execute_exit_command(minishell_t *minishell)
{
    if (my_strcmp(ARGS[0], "exit") == 0 &&
        minishell->no_builtin == 0) {
        exit(0);
    }
    return 2;
}

static int execute_cd_command(minishell_t *minishell)
{
    if (my_strcmp(ARGS[0], "cd") == 0 &&
        minishell->no_builtin == 0) {
        return cd_command(minishell);
    }
    return 2;
}

static int execute_env_command(minishell_t *minishell)
{
    if (my_strcmp(ARGS[0], "env") == 0) {
        return print_env(minishell);
    }
    return 2;
}

static int execute_setenv_command(minishell_t *minishell)
{
    if (my_strcmp(ARGS[0], "setenv") == 0) {
        return set_env(minishell, ARGS[1], ARGS[2]);
    }
    return 2;
}

static int execute_unsetenv_command(minishell_t *minishell)
{
    if (my_strcmp(ARGS[0], "unsetenv") == 0) {
        return unset_env(minishell, ARGS[1]);
    }
    return 2;
}

static int execute_history(minishell_t *minishell)
{
    char *commande_found = NULL;

    if (my_strcmp(ARGS[0], "history") == 0) {
        print_history(minishell, ARGS);
        return 0;
    }
    if (ARGS[0][0] == '!') {
        commande_found = history_command(minishell);
        if (commande_found == NULL)
            return 1;
        else {
            minishell->input = my_strdup(commande_found);
            free(commande_found);
            free_array(ARGS);
            ARGS = my_str_to_word_array(minishell->input, " ");
            return 2;
        }
    }
    return 2;
}

int execute_basic_commands(minishell_t *minishell)
{
    int status = execute_exit_command(minishell);

    if (status != 2)
        return status;
    status = execute_cd_command(minishell);
    if (status != 2)
        return status;
    status = execute_env_command(minishell);
    if (status != 2)
        return status;
    status = execute_setenv_command(minishell);
    if (status != 2)
        return status;
    status = execute_unsetenv_command(minishell);
    if (status != 2)
        return status;
    return 2;
}

int execute_alias_and_history(minishell_t *minishell)
{
    int status = execute_history(minishell);

    if (status != 2)
        return status;
    status = exec_all_alias(minishell);
    if (status != 2)
        return status;
    return 2;
}

int built_in_commands(minishell_t *minishell)
{
    int status = execute_basic_commands(minishell);

    if (status != 2)
        return status;
    status = execute_alias_and_history(minishell);
    if (status != 2)
        return status;
    return 2;
}
