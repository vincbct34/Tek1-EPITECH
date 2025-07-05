/*
** EPITECH PROJECT, 2023
** Minishell 1
** File description:
** cd.c
*/

#include "my.h"
#include "minishell.h"

void get_home(minishell *msh)
{
    char *home_without_prefix;

    for (int i = 0; msh->env[i] != NULL; i++) {
        if (my_strncmp(msh->env[i], "HOME=", 5) == 0) {
            home_without_prefix = msh->env[i] + 5;
            msh->home = malloc(sizeof(char) *
                (my_strlen(home_without_prefix) + 2));
            msh->home = my_strcpy(msh->home, home_without_prefix);
            msh->home = my_strcat(msh->home, "/");
            break;
        }
    }
}

static void error_cd(minishell *msh)
{
    if (access(msh->basic_args[1], F_OK) == -1) {
        my_puterror(msh->basic_args[1]);
        my_puterror(": No such file or directory.\n");
        msh->return_value = 1;
        return;
    }
    if (access(msh->basic_args[1], X_OK) == -1) {
        my_puterror(msh->basic_args[1]);
        my_puterror(": Permission denied.\n");
        msh->return_value = 1;
        return;
    }
    if (access(msh->basic_args[1], F_OK) != -1
        && access(msh->basic_args[1], R_OK) != -1) {
        my_puterror(msh->basic_args[1]);
        my_puterror(": Not a directory.\n");
        msh->return_value = 1;
        return;
    }
}

static void cd_minus(minishell *msh)
{
    chdir(msh->oldpwd);
    msh->oldpwd = msh->pwd;
    msh->pwd = getcwd(NULL, 0);
    msh->oldpwd = msh->pwd;
    msh->return_value = 0;
}

void my_cd(minishell *msh)
{
    get_home(msh);
    msh->pwd = getcwd(NULL, 0);
    if (msh->basic_args[1] == NULL) {
        chdir(msh->home);
        msh->oldpwd = msh->pwd;
        msh->return_value = 0;
    }
    if (msh->basic_args[1] != NULL
        && my_strcmp(msh->basic_args[1], "-") == 0)
        cd_minus(msh);
    if (msh->basic_args[1] != NULL
        && my_strcmp(msh->basic_args[1], "-") != 0) {
        if (chdir(msh->basic_args[1]) == -1)
            error_cd(msh);
        msh->oldpwd = msh->pwd;
        msh->return_value = 0;
    }
}
