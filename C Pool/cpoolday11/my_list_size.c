/*
** EPITECH PROJECT, 2023
** my_list_size
** File description:
** Day 11
*/

#include "my.h"
#include <stdlib.h>

int my_list_size(linked_list_t const *begin)
{
    int size;
    linked_list_t* i;

    i = begin;
    size = 0;
    while(i != NULL) {
        size = size + 1;
        i = i->next;
    }
    return (size);
}
