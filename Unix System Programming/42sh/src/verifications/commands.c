/*
** EPITECH PROJECT, 2024
** bsminishell1
** File description:
** built_in_commands.c
*/

#include "../../include/my.h"

int check_directory(minishell_t *minishell)
{
    struct stat st;

    if (stat(ARGS[0], &st) == 0 && S_ISDIR(st.st_mode)) {
        my_puterror(ARGS[0]);
        my_puterror(": Permission denied.\n");
        exit(1);
    }
    return 0;
}

static char **remove_hidden_files(char **tab)
{
    char **new_tab = NULL;

    for (int i = 0; tab[i] != NULL; i++) {
        if (tab[i][0] != '.')
            new_tab = my_tabadd(new_tab, tab[i]);
    }
    return new_tab;
}

static char **get_globbings(char *arg)
{
    glob_t globbing;
    char **new_arr = NULL;

    if (arg == NULL)
        return NULL;
    else if (strcmp(arg, "..") == 0) {
        new_arr = my_str_to_word_array(arg, " ");
        return new_arr;
    }
    if (glob(arg, GLOB_PERIOD | GLOB_NOSORT | GLOB_NOCHECK | GLOB_NOMAGIC,
    NULL, &globbing) == GLOB_NOMATCH)
        return NULL;
    new_arr = my_tabdup(globbing.gl_pathv);
    new_arr = remove_hidden_files(new_arr);
    globfree(&globbing);
    return new_arr;
}

char **my_globbings(char **array)
{
    char **new_inp = NULL;
    char **temp_tab = NULL;

    if (array == NULL || my_tablen(array) == 1)
        return array;
    for (int i = 0; array[i] != NULL; i++) {
        temp_tab = get_globbings(array[i]);
        new_inp = my_tabcat(new_inp, temp_tab);
    }
    free(array);
    return new_inp;
}

static void check_match(minishell_t *minishell, char **tmp_tab)
{
    for (int i = 0; tmp_tab[i] != NULL; i++) {
        if (ARGS[i] == NULL) {
            my_puterror(tmp_tab[0]);
            my_puterror(": No match.\n");
            exit(1);
        }
    }
}

int write_error(minishell_t *minishell)
{
    char **tmp_tab = my_tabdup(ARGS);

    ARGS = my_globbings(ARGS);
    check_match(minishell, tmp_tab);
    for (int i = 0; tmp_tab[i] != NULL; i++)
        free(tmp_tab[i]);
    free(tmp_tab);
    if (execve(INPUT, ARGS, ENV) && errno == ENOEXEC) {
        my_puterror(ARGS[0]);
        my_puterror(": Exec format error. Wrong Architecture.\n");
        return 1;
    } else {
        my_puterror(INPUT);
        my_puterror(": Command not found.\n");
        return 1;
    }
    return 0;
}

void execute_child_process(minishell_t *minishell)
{
    int status;

    status = check_directory(minishell);
    if (status == 1)
        exit(EXIT_FAILURE);
    minishell->input = get_path(minishell);
    status = write_error(minishell);
    if (status == 1)
        exit(EXIT_FAILURE);
    exit(EXIT_SUCCESS);
}

static int wait_and_analyze_child(pid_t pid)
{
    int status;

    waitpid(pid, &status, 0);
    return analyse_status(status);
}

int verif_commands(minishell_t *minishell)
{
    int status = built_in_commands(minishell);
    pid_t pid = 0;

    if (status != 2)
        return status;
    pid = fork();
    if (pid == 0) {
        execute_child_process(minishell);
    } else {
        status = wait_and_analyze_child(pid);
        if (status != 0) {
            return status;
        }
    }
    return 0;
}
