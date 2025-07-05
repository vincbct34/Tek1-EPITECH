/*
** EPITECH PROJECT, 2024
** secured
** File description:
** delete function
*/

#include "../includes/structure.h"
#include "../includes/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (my_strlen(s1) != my_strlen(s2))
        return (1);
    while (s1[i] != '\0') {
        if (s1[i] != s2[i])
            return (1);
        i++;
    }
    return (0);
}

void ht_delete_free(linked_list_t *current)
{
    free(current->data);
    free(current);
}

void ht_delete_bis(linked_list_t *current, linked_list_t *previous,
    unsigned int index, hashtable_t *ht)
{
    if (previous == NULL) {
        ht->array[index] = current->next;
    } else {
        previous->next = current->next;
    }
}

int ht_delete(hashtable_t *ht, char *key)
{
    unsigned int index = hash(key, ht->size) % ht->size;
    int hash_key = hash(key, ht->size);
    linked_list_t *current = ht->array[index];
    linked_list_t *previous = NULL;

    if (ht == NULL || key == NULL)
        return 84;
    while (current != NULL) {
        if (current->key == hash_key) {
            ht_delete_bis(current, previous, index, ht);
            ht_delete_free(current);
            return 0;
        }
        previous = current;
        current = current->next;
    }
    return -1;
}
