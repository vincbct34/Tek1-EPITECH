/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell2-vincent.bichat
** File description:
** execute_with_tree.c
*/

#include "my.h"
#include "minishell.h"

static void my_builtin_tree(tree *head, minishell *msh)
{
    if (my_strcmp(head->command[0], "exit") == 0)
        exit(0);
    if (my_strcmp(head->command[0], "cd") == 0)
        my_cd_tree(msh, head->command);
    if (my_strcmp(head->command[0], "env") == 0)
        my_env(msh);
    if (my_strcmp(head->command[0], "setenv") == 0)
        my_setenv_tree(msh, head->command);
    if (my_strcmp(head->command[0], "unsetenv") == 0)
        my_unsetenv_tree(msh, head->command);
}

static void is_a_directory_tree(char **command)
{
    struct stat sb;

    if (stat(command[0], &sb) == 0 && S_ISDIR(sb.st_mode)) {
        my_puterror(command[0]);
        my_puterror(": Permission denied.\n");
        exit(EXIT_FAILURE);
    }
}

void my_exec_tree(tree *head, minishell *msh)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        is_a_directory_tree(head->command);
        child_process(head, msh);
    } else {
        waitpid(pid, &status, 0);
        error_gest_segfault(status, msh);
    }
}

void commands_for_tree(tree *head, minishell *msh)
{
    (void)msh;
    if ((my_strcmp(head->command[0], "exit") == 0)
        || (my_strcmp(head->command[0], "cd") == 0)
        || (my_strcmp(head->command[0], "env") == 0)
        || (my_strcmp(head->command[0], "setenv") == 0)
        || (my_strcmp(head->command[0], "unsetenv") == 0))
        my_builtin_tree(head, msh);
    else if (head->pipe) {
        my_pipe(head, msh);
        return;
    } else
        my_exec_tree(head, msh);
}
