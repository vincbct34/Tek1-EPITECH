/*
** EPITECH PROJECT, 2024
** bsminishell1
** File description:
** commands.c
*/

#include "../../include/my.h"

int cd_error(minishell_t *minishell)
{
    if (access(ARGS[1], F_OK) == -1) {
        my_puterror(ARGS[1]);
        my_puterror(": No such file or directory.\n");
        return 1;
    }
    if (access(ARGS[1], F_OK) != -1 && access(ARGS[1], R_OK) != -1) {
        my_puterror(ARGS[1]);
        my_puterror(": Not a directory.\n");
        return 1;
    }
    if (access(ARGS[1], X_OK) == -1) {
        my_puterror(ARGS[1]);
        my_puterror(": Permission denied.\n");
        return 1;
    }
    return 0;
}

int start_error(minishell_t *minishell)
{
    if (chdir(ARGS[1]) == -1)
        return cd_error(minishell);
    return 0;
}

int change_to_home_directory(minishell_t *minishell)
{
    const char *home = NULL;

    modif_value(minishell->env_list, "OLDPWD", getcwd(NULL, 0));
    minishell->old_pwd = getcwd(NULL, 0);
    home = get_env_value(minishell->env_list, "HOME");
    if (home == NULL)
        return 1;
    if (chdir(home) != 0)
        return 1;
    modif_value(minishell->env_list, "PWD", getcwd(NULL, 0));
    minishell->env = list_to_double_array(minishell->env_list);
    return 0;
}

int change_to_directory(minishell_t *minishell, const char *path)
{
    modif_value(minishell->env_list, "OLDPWD", getcwd(NULL, 0));
    minishell->old_pwd = getcwd(NULL, 0);
    if (path == NULL || chdir(path) != 0) {
        if (start_error(minishell) != 0)
            exit(1);
    }
    modif_value(minishell->env_list, "PWD", getcwd(NULL, 0));
    minishell->env = list_to_double_array(minishell->env_list);
    return 0;
}

int cd_command(minishell_t *minishell)
{
    if (minishell->args[1] == NULL) {
        return change_to_home_directory(minishell);
    } else if (minishell->args[1][0] == '-') {
        return change_to_directory(minishell, minishell->old_pwd);
    } else {
        return change_to_directory(minishell, minishell->args[1]);
    }
}
