/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell2-vincent.bichat
** File description:
** pipe.c
*/

#include "my.h"
#include "minishell.h"

static void pid1_exec(int fd[2], tree *head, minishell *msh)
{
    close(fd[0]);
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
    my_exec_tree(head, msh);
    exit(EXIT_SUCCESS);
}

static void pid2_exec(int fd[2], tree *head, minishell *msh)
{
    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    close(fd[0]);
    my_exec_tree(head->pipe, msh);
    exit(EXIT_SUCCESS);
}

static void close_waitpid(int fd[2], pid_t pid1, pid_t pid2)
{
    close(fd[0]);
    close(fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}

void my_pipe(tree *head, minishell *msh)
{
    pid_t pid1;
    pid_t pid2;
    int fd[2];

    if (pipe(fd) == -1)
        exit(84);
    pid1 = fork();
    if (pid1 == 0) {
        pid1_exec(fd, head, msh);
        return;
    } else {
        pid2 = fork();
        if (pid2 == 0)
            pid2_exec(fd, head, msh);
        else
            close_waitpid(fd, pid1, pid2);
    }
}
