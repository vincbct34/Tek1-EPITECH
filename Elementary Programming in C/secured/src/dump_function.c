/*
** EPITECH PROJECT, 2024
** secured
** File description:
** dump function
*/

#include "../includes/structure.h"
#include "../includes/my.h"
#include <stdio.h>
#include <stdlib.h>

void ht_dump_bis(hashtable_t *ht, int i)
{
    my_putstr("> ");
    my_putnbr(ht->array[i]->key);
    my_putstr(" - ");
    my_putstr(ht->array[i]->data);
    my_putchar('\n');
}

void ht_dump_tmp(linked_list_t *tmp)
{
    my_putstr("> ");
    my_putnbr(tmp->key);
    my_putstr(" - ");
    my_putstr(tmp->data);
    my_putchar('\n');
}

void ht_dump_index(int i)
{
    my_putchar('[');
    my_putnbr(i);
    my_putstr("]\n");
}

void ht_dump(hashtable_t *ht)
{
    linked_list_t *tmp;

    if (ht == NULL)
        return;
    for (int i = 0; i < ht->size; i++) {
        ht_dump_index(i);
        if (ht->array[i] == NULL || ht->array[i]->data == NULL)
            continue;
        ht_dump_bis(ht, i);
        tmp = ht->array[i]->next;
        while (tmp != NULL) {
            ht_dump_tmp(tmp);
            tmp = tmp->next;
        }
    }
}
