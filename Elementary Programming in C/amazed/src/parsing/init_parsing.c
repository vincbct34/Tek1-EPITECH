/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-amazed-vincent.bichat
** File description:
** init_parsing.c
*/

#include "maze.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

void push_back(index_t **list, index_t *new)
{
    index_t *tmp = *list;

    if (*list == NULL) {
        *list = new;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
}

static int fill_list(maze_t *maze)
{
    int i;
    index_t *new = NULL;

    for (i = 0; my_strchr(maze->tab[i], '#') == 1; i++);
    maze->nb_robots = my_getnbr(maze->tab[i]);
    if (maze->nb_robots <= 0)
        return 84;
    i++;
    for (; maze->tab[i] != NULL; i++) {
        new = malloc(sizeof(index_t));
        new->data = my_strdup(maze->tab[i]);
        new->check_type = my_str_to_word_array(maze->tab[i], ' ');
        new->next = NULL;
        push_back(&maze->rooms, new);
    }
    return 0;
}

static int error_handling(maze_t *maze, index_t *current)
{
    int i;

    current->is_pipe = false;
    current->is_room = false;
    current->is_start = false;
    current->is_end = false;
    for (i = 0; current->check_type[i] != NULL; i++);
    if (i == 3 && my_strchr(current->data, '-') == 0) {
        current->is_room = true;
        maze->nb_rooms++;
        return 0;
    }
    if (i == 1 && my_strchr(current->data, '-') == 1) {
        current->is_pipe = true;
        maze->nb_pipes++;
        return 0;
    }
    if (i == 1 && my_strchr(current->data, '#') == 1)
        return 0;
    return 84;
}

static int check_room_dup(maze_t *maze, index_t *current, int i)
{
    index_t *temp = maze->rooms;

    while (temp != NULL && i > 0) {
        if (temp->is_room == true &&
            my_strcmp(temp->check_type[0], current->check_type[0]) == 0)
            return 84;
        if (temp->is_room == true &&
            my_strcmp(temp->check_type[1], current->check_type[1]) == 0 &&
            temp->is_room == true &&
            my_strcmp(temp->check_type[2], current->check_type[2]) == 0)
            return 84;
        i--;
        temp = temp->next;
    }
    return 0;
}

void adjusting_values(maze_t *maze, index_t *current)
{
    while (current != NULL) {
        if (current->is_room == true
            && check_room_dup(maze, current, maze->wait) == 84)
            break;
        if (my_strcmp(current->data, "\0") == 0)
            break;
        if (my_strcmp(current->data, "##start") == 0) {
            maze->nb_start++;
            current->is_start = true;
        }
        if (my_strcmp(current->data, "##end") == 0) {
            current->is_end = true;
            maze->nb_end++;
        }
        if (maze->nb_start > 1 || maze->nb_end > 1)
            break;
        maze->parse_stop++;
        current = current->next;
        maze->wait++;
    }
}

void update_room_and_pipe_counts(maze_t *maze)
{
    if (my_strchr(maze->rooms->data, '-') == 1
        && my_strchr(maze->rooms->data, '#') == 0)
        maze->nb_pipes--;
    if (my_strchr(maze->rooms->data, '-') == 0
        && my_strchr(maze->rooms->data, '#') == 0)
        maze->nb_rooms--;
}

static void print_things(maze_t *maze)
{
    my_putstr("#number_of_robots\n");
    my_putnbr(maze->nb_robots);
    my_putchar('\n');
    my_putstr("#rooms\n");
}

static void is_special_cases(maze_t *maze, index_t *current)
{
    if (current->is_start == true)
        my_putstr("##start\n");
    if (current->is_end == true)
        my_putstr("##end\n");
    if (current->is_pipe == true && maze->is_tunnel_passed == false) {
        my_putstr("#tunnels\n");
        maze->is_tunnel_passed = true;
    }
}

void print_needed(maze_t *maze)
{
    index_t *current = maze->rooms;

    print_things(maze);
    while (current != NULL) {
        if (maze->parse_stop - 1 == 0) {
            update_room_and_pipe_counts(maze);
            current = current->next;
            continue;
        }
        is_special_cases(maze, current);
        if (current->is_room == true || current->is_pipe == true) {
            my_putstr(current->data);
            my_putchar('\n');
        }
        maze->parse_stop--;
        current = current->next;
    }
}

int parsing(maze_t *maze)
{
    index_t *current;

    maze->wait = 0;
    if (fill_list(maze) == 84)
        return 84;
    if (check_if_nb(maze) == 84)
        return 84;
    current = maze->rooms;
    while (current != NULL) {
        if (error_handling(maze, current) == 84)
            break;
        if (my_strcmp(current->check_type[0], "##start") == 0
            && current->next != NULL)
            maze->start = my_getnbr(current->next->check_type[0]);
        if (my_strcmp(current->check_type[0], "##end") == 0
            && current->next != NULL)
            maze->end = my_getnbr(current->next->check_type[0]);
        current = current->next;
    }
    return 0;
}
