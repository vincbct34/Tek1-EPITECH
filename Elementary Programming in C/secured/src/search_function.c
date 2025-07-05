/*
** EPITECH PROJECT, 2024
** secured
** File description:
** search function
*/

#include "../includes/structure.h"
#include "../includes/my.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char *ht_search(hashtable_t *ht, char *key)
{
    unsigned int index = hash(key, ht->size) % ht->size;
    int hash_key = hash(key, ht->size);
    linked_list_t *current = ht->array[index];

    if (ht == NULL || key == NULL)
        return NULL;
    while (current != NULL) {
        if (current->key == hash_key) {
            return current->data;
        }
        current = current->next;
    }
    return NULL;
}
