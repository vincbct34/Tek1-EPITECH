/*
** EPITECH PROJECT, 2022
** secured
** File description:
** structure
*/

#pragma once

typedef struct linked_list_s {
    int key;
    char *data;
    struct linked_list_s *next;
} linked_list_t;

typedef struct hashtable_s {
    int size;
    linked_list_t **array;
} hashtable_t;
