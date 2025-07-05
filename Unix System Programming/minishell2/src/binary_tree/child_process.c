/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-minishell2-vincent.bichat
** File description:
** child_process.c
*/

#include "my.h"
#include "minishell.h"

static void redirect_left(char *file)
{
    int fd = open(file, O_RDONLY);

    if (fd == -1) {
        my_puterror(file);
        my_puterror(": No such file or directory.\n");
        exit(EXIT_FAILURE);
    }
    dup2(fd, 0);
    close(fd);
}

static void redirect_right(char *file)
{
    int fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        my_puterror(file);
        my_puterror(": No such file or directory.\n");
        exit(EXIT_FAILURE);
    }
    dup2(fd, 1);
    close(fd);
}

static void redirect_double_right(char *file)
{
    int fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd == -1) {
        my_puterror(file);
        my_puterror(": No such file or directory.\n");
        exit(EXIT_FAILURE);
    }
    dup2(fd, 1);
    close(fd);
}

static void redirect_double_left(char *file)
{
    int fd = open(file, O_RDONLY);

    if (fd == -1) {
        my_puterror(file);
        my_puterror(": No such file or directory.\n");
        exit(EXIT_FAILURE);
    }
    dup2(fd, 0);
    close(fd);
}

void child_process(tree *head, minishell *msh)
{
    char *path = NULL;

    if (head->redirect_l != NULL)
        redirect_left(head->redirect_l);
    if (head->redirect_r != NULL)
        redirect_right(head->redirect_r);
    if (head->redirect_r_r != NULL)
        redirect_double_right(head->redirect_r_r);
    if (head->redirect_l_l != NULL)
        redirect_double_left(head->redirect_l_l);
    path = get_path(head->command, msh->env);
    if (execve(path, head->command, msh->env) && errno == ENOEXEC) {
        my_puterror(path);
        my_puterror(": Exec format error. Wrong Architecture.\n");
        exit(EXIT_FAILURE);
    } else {
        my_puterror(path);
        my_puterror(": Command not found.\n");
        exit(EXIT_FAILURE);
    }
}
