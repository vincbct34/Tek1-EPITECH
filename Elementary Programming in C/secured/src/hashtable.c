/*
** EPITECH PROJECT, 2024
** secured
** File description:
** hash table
*/

#include "../includes/structure.h"
#include <stdio.h>
#include <stdlib.h>

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *ht = malloc(sizeof(hashtable_t));

    (void)hash;
    ht->size = len;
    ht->array = malloc(sizeof(linked_list_t) * len);
    for (int i = 0; i < len; i++) {
        ht->array[i] = malloc(sizeof(linked_list_t));
        ht->array[i]->data = NULL;
        ht->array[i]->key = -1;
        ht->array[i]->next = NULL;
    }
    return ht;
}

void delete_hashtable(hashtable_t *ht)
{
    linked_list_t *tmp;
    linked_list_t *tmp2;

    for (int i = 0; i < ht->size; i++) {
        tmp = ht->array[i];
        while (tmp != NULL) {
            tmp2 = tmp->next;
            free(tmp->data);
            free(tmp);
            tmp = tmp2;
        }
    }
    free(ht->array);
    free(ht);
}
