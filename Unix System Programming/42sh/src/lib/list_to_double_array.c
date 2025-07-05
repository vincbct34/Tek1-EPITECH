/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** lib.c
*/

#include "../../include/my.h"

int calculate_list_size(env_t *list)
{
    int size = 0;
    env_t *tmp = list;

    while (tmp != NULL) {
        size++;
        tmp = tmp->next;
    }
    return size;
}

char **allocate_memory(int size)
{
    return malloc(sizeof(char *) * (size + 1));
}

char **fill_array(env_t *list, char **array)
{
    env_t *tmp = list;
    int i = 0;

    while (tmp != NULL) {
        array[i] = malloc(sizeof(char) * (my_strlen(tmp->name)
            + my_strlen(tmp->value) + 2));
        if (array[i] == NULL) {
            free_array(array);
            return NULL;
        }
        my_strcpy(array[i], tmp->name);
        my_strcat(array[i], "=");
        my_strcat(array[i], tmp->value);
        tmp = tmp->next;
        i++;
    }
    array[i] = NULL;
    return array;
}

char **list_to_double_array(env_t *list)
{
    int list_size = calculate_list_size(list);
    char **array = allocate_memory(list_size);

    if (array == NULL)
        return NULL;
    return fill_array(list, array);
}
