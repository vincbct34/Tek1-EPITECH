/*
** EPITECH PROJECT, 2024
** bsminishell1
** File description:
** env_lib2.c
*/

#include "../../include/my.h"

int modif_value(env_t *list, char *name, char *value)
{
    env_t *tmp = list;

    while (tmp != NULL) {
        if (my_strcmp(tmp->name, name) == 0) {
            free(tmp->value);
            tmp->value = my_strdup(value);
            return 0;
        }
        tmp = tmp->next;
    }
    return 1;
}

int my_list_size(env_t *list)
{
    env_t *tmp = list;
    int i = 0;

    while (tmp != NULL) {
        tmp = tmp->next;
        i++;
    }
    return i;
}

void array_to_list(minishell_t *minishell)
{
    char **tmp = NULL;

    minishell->env_list = NULL;
    for (int i = 0; ENV[i] != NULL; i++) {
        tmp = my_str_to_word_array(ENV[i], "=");
        push_back(minishell, &minishell->env_list, tmp[0], tmp[1]);
    }
}

int is_alpha(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9')
            && (str[i] != '_') && (str[i] < 'a' || str[i] > 'z'))
            return 0;
    }
    return 1;
}

char *my_strstr(const char *haystack, const char *needle)
{
    const char *h;
    const char *n;

    if (*needle == '\0')
        return (char *)haystack;
    while (*haystack != '\0') {
        h = haystack;
        n = needle;
        while (*n != '\0' && *h == *n) {
            h++;
            n++;
        }
        if (*n == '\0')
            return (char *)haystack;
        haystack++;
    }
    return NULL;
}
