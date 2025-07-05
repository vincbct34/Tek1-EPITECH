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
#include <math.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

void ht_insert_free(linked_list_t *current, linked_list_t *new_node,
    char *value)
{
    free(current->data);
    current->data = my_strdup(value);
    free(new_node->data);
    free(new_node);
}

int is_existing(hashtable_t *ht, int index, int key_hash, char *value)
{
    linked_list_t *tmp = ht->array[index];

    while (tmp != NULL) {
        if (tmp->key == key_hash) {
            tmp->data = my_strdup(value);
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    unsigned int index = hash(key, ht->size) % ht->size;
    int hash_key = hash(key, ht->size);
    linked_list_t *new_node = malloc(sizeof(linked_list_t));
    linked_list_t *current = ht->array[index];

    if (ht == NULL || key == NULL || value == NULL)
        return 84;
    new_node->data = my_strdup(value);
    new_node->key = hash_key;
    new_node->next = NULL;
    if (current == NULL || current->key == -1) {
        ht->array[index] = new_node;
    } else {
        if (is_existing(ht, index, hash_key, value) == 1)
            return 0;
        new_node->next = ht->array[index];
        ht->array[index] = new_node;
    }
    return 0;
}
