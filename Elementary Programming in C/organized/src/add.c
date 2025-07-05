/*
** EPITECH PROJECT, 2023
** add.c
** File description:
** Add something in the list
*/

#include "../include/shell.h"
#include "../include/structure.h"
#include "../include/my.h"
#include <stdlib.h>
#include <stdio.h>

static void display_add(linked_list_t *new_node)
{
    my_putstr(new_node->name);
    my_putstr(" n°");
    my_put_nbr(new_node->index);
    my_putstr(" - \"");
    my_putstr(new_node->type);
    my_putstr("\" added.\n");
}

static int error_gestion_add(char **args)
{
    if (args[0] == NULL) {
        my_putstr("Error : No arguments.\n");
        return (84);
    }
    for (int i = 0; args[i] != NULL; i += 2) {
        if (my_strcmp(args[i], "WIRE") != 0
            && my_strcmp(args[i], "SENSOR") != 0
            && my_strcmp(args[i], "PROCESSOR") != 0
            && my_strcmp(args[i], "ACTUATOR") != 0
                && my_strcmp(args[i], "DEVICE") != 0) {
            my_putstr("Error : Bad arguments.\n");
            return (84);
        }
        if (args[i] != NULL && args[i + 1] == NULL) {
            my_putstr("Error : Too few arguments.\n");
            return (84);
        }
    }
    return 0;
}

int add(void *data, char **args)
{
    static int index = 0;
    linked_list_t *new_node = NULL;
    linked_list_t **head = (linked_list_t **)data;

    if (error_gestion_add(args) == 84)
        return 84;
    for (int i = 0; args[i] && args[i] != NULL; i += 2) {
        new_node = malloc(sizeof(linked_list_t));
        new_node->name = my_strdup(args[i]);
        new_node->type = my_strdup(args[i + 1]);
        new_node->index = index;
        index++;
        new_node->next = *head;
        *head = new_node;
        display_add(new_node);
    }
    return 0;
}
