/*
** EPITECH PROJECT, 2023
** del.c
** File description:
** Delete element from the list
*/

#include "../include/shell.h"
#include "../include/structure.h"
#include "../include/my.h"
#include <stdlib.h>
#include <stdio.h>

static void display_del(linked_list_t *new_node)
{
    my_putstr(new_node->name);
    my_putstr(" n°");
    my_put_nbr(new_node->index);
    my_putstr(" - \"");
    my_putstr(new_node->type);
    my_putstr("\" deleted.\n");
}

static int error_gestion_del(char **args)
{
    if (args[0] == NULL) {
        my_putstr("Error : No arguments.\n");
        return (84);
    }
    for (int i = 0; args[i]; i++) {
        if (is_nbr(args[i]) == 0) {
            my_putstr("Error : Bad arguments.\n");
            return (84);
        }
    }
    return 0;
}

static int del_bis2(void *data, char **args, int i)
{
    linked_list_t **head = (linked_list_t **)data;
    linked_list_t *tmp = *head;

    if (tmp->next && tmp->next->index == my_getnbr(args[i])) {
        display_del(tmp->next);
        if (tmp->next->next == NULL) {
            tmp->next = NULL;
            return 2;
        }
        tmp->next = tmp->next->next;
        return 0;
    }
    return 1;
}

static int del_bis(void *data, char **args, int i)
{
    linked_list_t **head = (linked_list_t **)data;
    linked_list_t *tmp = *head;

    for (; tmp->next; tmp = tmp->next) {
        if (del_bis2(&tmp, args, i) == 2)
            break;
    }
    return 0;
}

static int is_invalid_index(int index, linked_list_t *head)
{
    linked_list_t *tmp = head;

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->index == index) {
            return 0;
        }
    }
    return 1;
}

static int check_invalid_del_index(void *data, char **args)
{
    linked_list_t **head = (linked_list_t **)data;
    int index;

    for (int i = 0; args[i] != NULL; i++) {
        index = my_getnbr(args[i]);
        if (is_invalid_index(index, *head)) {
            my_putstr("Error: Invalid index.\n");
            return 84;
        }
    }
    return 0;
}

int del(void *data, char **args)
{
    linked_list_t **head = (linked_list_t **)data;

    if (error_gestion_del(args) == 84)
        return 84;
    if (check_invalid_del_index(data, args) == 84)
        return 84;
    for (int i = 0; args[i]; i++) {
        if ((*head)->index == my_getnbr(args[i])) {
            display_del(*head);
            *head = (*head)->next;
            continue;
        }
        del_bis(data, args, i);
    }
    return 0;
}
