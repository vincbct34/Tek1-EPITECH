/*
** EPITECH PROJECT, 2023
** B-PSU-200-MPL-2-1-42sh-vincent.bichat
** File description:
** emi_get_path.c
*/

#include "../../include/my.h"

static char *emi_path_bis(minishell_t *minishell, char **path_array,
    char *path, char *args_emi)
{
    char *temp_path = NULL;

    for (int i = 0; path_array[i] != NULL; i++) {
        path = my_strcat2(path_array[i], "/");
        temp_path = my_strcat2(path, args_emi);
        free(path);
        if (access(temp_path, F_OK) == 0) {
            return temp_path;
        }
        free(temp_path);
    }
    return ARGS[0];
}

char *emi_get_path(minishell_t *minishell, char *args_emi)
{
    char *init_path = NULL;
    char *temp_init = NULL;
    char *path = NULL;
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
    return emi_path_bis(minishell, path_array, path, args_emi);
}
