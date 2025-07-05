/*
** EPITECH PROJECT, 2023
** my_params_to_list
** File description:
** Day 11
*/

#include "my.h"
#include "mylist.h"
#include <stdlib.h>

linked_list_t *push_to_front(linked_list_t *head, linked_list_t *value)
{
    linked_list_t *new = malloc(sizeof(linked_list_t));

    new->data = value;
    new->next = head;
    return new;
}

linked_list_t *my_params_to_list(int ac, char const **av)
{
    linked_list_t *current = malloc(sizeof(linked_list_t));

    for (int i = 0; i != ac - 1; i++)
        current = push_to_front(current, av[i]);
    return current;
}
