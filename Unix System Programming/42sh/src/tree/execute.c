/*
** EPITECH PROJECT, 2024
** B-PSU-200-MPL-2-1-minishell2-axel.pereto
** File description:
** execute
*/

#include "../../include/my.h"

static int handle_first_child(int pipefd[2], node_t *node,
    minishell_t *minishell)
{
    int status = 0;

    close(pipefd[0]);
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);
    status = execute_tree_and_commands(node->left, minishell);
    exit(status == EXIT_SUCCESS ? EXIT_SUCCESS : EXIT_FAILURE);
}

static int handle_second_child(int pipefd[2], node_t *node,
    minishell_t *minishell)
{
    int status = 0;

    close(pipefd[1]);
    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);
    status = execute_tree_and_commands(node->right, minishell);
    exit(status == EXIT_SUCCESS ? EXIT_SUCCESS : EXIT_FAILURE);
}

static int wait_for_children_and_close_pipes(int pipefd[2], pid_t pid1,
    pid_t pid2)
{
    int status1 = 0;
    int status2 = 0;

    close(pipefd[0]);
    close(pipefd[1]);
    waitpid(pid1, &status1, 0);
    waitpid(pid2, &status2, 0);
    if (WIFEXITED(status1) && WEXITSTATUS(status1) == EXIT_SUCCESS &&
        WIFEXITED(status2) && WEXITSTATUS(status2) == EXIT_SUCCESS) {
        return 0;
    }
    return 1;
}

int execute_pipe(node_t *node, minishell_t *minishell)
{
    int pipefd[2];
    pid_t pid1 = 0;
    pid_t pid2 = 0;

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    pid1 = fork();
    if (pid1 == 0) {
        handle_first_child(pipefd, node, minishell);
    }
    pid2 = fork();
    if (pid2 == 0) {
        handle_second_child(pipefd, node, minishell);
    }
    return wait_for_children_and_close_pipes(pipefd, pid1, pid2);
}

static int setup_redirection(char *filepath, char direction)
{
    int fd = open(filepath, direction == '>' ?
        O_WRONLY | O_CREAT | O_TRUNC : O_RDONLY, 0644);

    if (fd == -1)
        return -1;
    if ((direction == '>' && dup2(fd, STDOUT_FILENO) == -1) ||
        (direction == '<' && dup2(fd, STDIN_FILENO) == -1)) {
        close(fd);
        return -1;
    }
    close(fd);
    return 0;
}

static int execute_commands_with_redirection(node_t *node,
    minishell_t *minishell, char direction)
{
    if (setup_redirection(node->right->operation, direction) == -1)
        return 1;
    return execute_tree_and_commands(node->left, minishell);
}

int execute_redirection_bis(node_t *node,
    minishell_t *minishell, char direction)
{
    return execute_commands_with_redirection(node, minishell, direction);
}

int execute_redirection(node_t *node,
    minishell_t *minishell, char direction)
{
    pid_t pid;
    int status = 0;
    int child_status = 0;

    clean_str(node->right->operation, 0);
    pid = fork();
    if (pid == 0) {
        status = execute_redirection_bis(node, minishell, direction);
        exit(status == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
    } else {
        waitpid(pid, &child_status, 0);
        if (WIFEXITED(child_status) && WEXITSTATUS(child_status) != 0) {
            return 1;
        }
    }
    return 0;
}

int execute_redirection_append(node_t *node, minishell_t *minishell)
{
    int fd = open(node->right->operation, O_CREAT | O_WRONLY | O_APPEND, 0644);
    int save_stdout = dup(STDOUT_FILENO);
    int status = 0;

    if (fd == -1)
        return 1;
    if (dup2(fd, STDOUT_FILENO) == -1) {
        close(fd);
        return 1;
    }
    status = execute_tree_and_commands(node->left, minishell);
    if (close(fd) == -1)
        return 1;
    if (dup2(save_stdout, STDOUT_FILENO) == -1) {
        close(save_stdout);
        return 1;
    }
    if (close(save_stdout) == -1)
        return 1;
    return status;
}
