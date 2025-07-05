/*
** EPITECH PROJECT, 2023
** disp.c
** File description:
** Display the list
*/

#include "../include/shell.h"
#include "../include/structure.h"
#include "../include/my.h"
#include <stdlib.h>
#include <stdio.h>

int disp(void *data, char **args)
{
    linked_list_t **head = (linked_list_t **)data;
    linked_list_t *tmp = *head;

    if (args[0] != NULL) {
        my_putstr("Error : Too many arguments.\n");
        return 84;
    }
    while (tmp != NULL) {
        my_putstr(tmp->name);
        my_putstr(" n°");
        my_put_nbr(tmp->index);
        my_putstr(" - \"");
        my_putstr(tmp->type);
        my_putstr("\"\n");
        tmp = tmp->next;
    }
    return 0;
}
