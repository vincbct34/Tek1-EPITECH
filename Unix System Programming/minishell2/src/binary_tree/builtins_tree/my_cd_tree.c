/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell2-vincent.bichat
** File description:
** my_cd_tree.c
*/

#include "my.h"
#include "minishell.h"

static void error_cd_tree(minishell *msh, char **command)
{
    if (access(command[1], F_OK) == -1) {
        my_puterror(command[1]);
        my_puterror(": No such file or directory.\n");
        msh->return_value = 1;
        return;
    }
    if (access(command[1], X_OK) == -1) {
        my_puterror(command[1]);
        my_puterror(": Permission denied.\n");
        msh->return_value = 1;
        return;
    }
    if (access(command[1], F_OK) != -1
        && access(command[1], R_OK) != -1) {
        my_puterror(command[1]);
        my_puterror(": Not a directory.\n");
        msh->return_value = 1;
        return;
    }
}

static void cd_minus_tree(minishell *msh)
{
    chdir(msh->oldpwd);
    msh->oldpwd = msh->pwd;
    msh->pwd = getcwd(NULL, 0);
    msh->oldpwd = msh->pwd;
    msh->return_value = 0;
}

void my_cd_tree(minishell *msh, char **command)
{
    get_home(msh);
    msh->pwd = getcwd(NULL, 0);
    if (command[1] == NULL) {
        chdir(msh->home);
        msh->oldpwd = msh->pwd;
        msh->return_value = 0;
    }
    if (command[1] != NULL
        && my_strcmp(command[1], "-") == 0)
        cd_minus_tree(msh);
    if (command[1] != NULL
        && my_strcmp(command[1], "-") != 0) {
        if (chdir(command[1]) == -1)
            error_cd_tree(msh, command);
        msh->oldpwd = msh->pwd;
        msh->return_value = 0;
    }
}
