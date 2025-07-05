/*
** EPITECH PROJECT, 2024
** bsminishell1
** File description:
** get.c
*/

#include "../../include/my.h"

char *replace_tab(char *input)
{
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '\t') {
            input[i] = ' ';
        }
    }
    return input;
}

char *get_input(void)
{
    char *input = NULL;
    size_t len = 0;

    if (getline(&input, &len, stdin) == -1) {
        if (isatty(0)) {
            my_putstr("exit\n");
        }
        exit(0);
    }
    input = replace_tab(input);
    if (my_strlen(input) == 0 ||
    (my_strlen(input) == 1 && input[0] == '\n')) {
        free(input);
        return NULL;
    }
    if (input[my_strlen(input) - 1] == '\n') {
        input[my_strlen(input) - 1] = '\0';
    }
    return input;
}

static char *get_path_bis(minishell_t *minishell, char **path_array,
    char *path, char *temp_path)
{
    for (int i = 0; path_array[i] != NULL; i++) {
        path = my_strcat2(path_array[i], "/");
        temp_path = my_strcat2(path, ARGS[0]);
        free(path);
        if (access(temp_path, F_OK) == 0) {
            return temp_path;
        }
        free(temp_path);
    }
    return ARGS[0];
}

char *get_path(minishell_t *minishell)
{
    char *init_path = NULL;
    char *temp_init = NULL;
    char *path = NULL;
    char *temp_path = NULL;
    char **path_array = NULL;

    for (int i = 0; ENV != NULL; i++) {
        if (my_strncmp(ENV[i], "PATH=", 5) == 0) {
            temp_init = my_strdup(ENV[i]);
            init_path = temp_init + 5;
            path_array = my_str_to_word_array(init_path, ":");
            free(temp_init);
            break;
        }
    }
    return get_path_bis(minishell, path_array, path, temp_path);
}

char *get_env_value(env_t *list, char *name)
{
    env_t *tmp = list;

    while (tmp != NULL) {
        if (my_strcmp(tmp->name, name) == 0) {
            return tmp->value;
        }
        tmp = tmp->next;
    }
    return NULL;
}
