/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-amazed-vincent.bichat
** File description:
** parsing.c
*/

#include "maze.h"

static int is_only_digits(const char *str)
{
    if (str[0] == '\0')
        return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!my_isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

static int contains_non_numeric(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!my_isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
            return 1;
    }
    return 0;
}

static int check_bis(index_t *current)
{
    if (my_strchr(current->data, '-') == 0
        && my_strchr(current->data, '#') == 0)
        if (is_only_digits(current->data))
            return 84;
    if (my_strchr(current->data, '-') == 1
        && my_strchr(current->data, '#') == 0)
        if (is_only_digits(current->data))
            return 84;
    if (contains_non_numeric(current->data)
        && my_strchr(current->data, '#') == 0) {
        return 84;
    }
    return 0;
}

int check_if_nb(maze_t *maze)
{
    index_t *current = maze->rooms;

    while (current != NULL) {
        if (current->data[0] == '\0') {
            current = current->next;
            continue;
        }
        if (check_bis(current) == 84)
            return 84;
        current = current->next;
    }
    return 0;
}
