/*
** EPITECH PROJECT, 2023
** Minishell 1
** File description:
** exec.c
*/

#include "my.h"
#include "minishell.h"

#include <string.h>

static char *get_path_array(char *token, char *full_path,
    char **array, char *path_copy)
{
    while (token != NULL) {
        full_path = malloc((my_strlen(token)
            + my_strlen(array[0]) + 2) * sizeof(char));
        if (full_path == NULL)
            return NULL;
        my_strcpy(full_path, token);
        my_strcat(full_path, "/");
        my_strcat(full_path, array[0]);
        if (access(full_path, F_OK) == 0) {
            free(path_copy);
            return full_path;
        }
        free(full_path);
        token = strtok(NULL, ":");
    }
    free(path_copy);
    return array[0];
}

char *get_path(char **array, char **env)
{
    char *path = NULL;
    char *full_path = NULL;
    char *path_copy = NULL;
    char *token = NULL;
    int i = 0;

    for (i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "PATH=", 5) == 0) {
            path = my_strdup(env[i]);
            path += 5;
            path_copy = my_strdup(path);
            break;
        }
    }
    token = strtok(path_copy, ":");
    array[0] = get_path_array(token, full_path, array, path_copy);
    return array[0];
}

void error_gest_segfault(int status, minishell *msh)
{
    if (WIFEXITED(status)) {
        msh->return_value = WEXITSTATUS(status);
    }
    if (WIFSIGNALED(status)) {
        if (WCOREDUMP(status))
            my_puterror("Segmentation fault (core dumped)\n");
        else
            my_puterror("Segmentation fault\n");
        msh->return_value = 139;
    }
}

static void is_a_directory(minishell *msh)
{
    struct stat sb;

    if (stat(msh->basic_args[0], &sb) == 0 && S_ISDIR(sb.st_mode)) {
        my_puterror(msh->basic_args[0]);
        my_puterror(": Permission denied.\n");
        exit(EXIT_FAILURE);
    }
}

void my_exec(minishell *msh)
{
    pid_t pid = fork();
    int status;
    char *path;

    if (pid == 0) {
        is_a_directory(msh);
        path = get_path(msh->basic_args, msh->env);
        if (execve(path, msh->basic_args, msh->env) && errno == ENOEXEC) {
            my_puterror(path);
            my_puterror(": Exec format error. Wrong Architecture.\n");
            exit(EXIT_FAILURE);
        } else {
            my_puterror(path);
            my_puterror(": Command not found.\n");
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, &status, 0);
        error_gest_segfault(status, msh);
    }
}
