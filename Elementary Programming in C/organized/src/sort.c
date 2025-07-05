/*
** EPITECH PROJECT, 2023
** sort.c
** File description:
** Sort the list
*/

#include "../include/shell.h"
#include "../include/structure.h"
#include "../include/my.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int compare(linked_list_t *left, linked_list_t *right,
    char *tag, int reverse)
{
    int result = 0;

    if (my_strcmp(tag, "NAME") == 0)
        result = my_strcmp(left->type, right->type);
    if (my_strcmp(tag, "TYPE") == 0)
        result = my_strcmp(left->name, right->name);
    if (my_strcmp(tag, "ID") == 0)
        result = left->index - right->index;
    if (reverse)
        result *= -1;
    return result;
}

static linked_list_t *merge(linked_list_t *left, linked_list_t *right,
    char **tags, int reverse)
{
    linked_list_t *result = NULL;
    int comparison = 0;

    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    for (int i = 0; tags[i] != NULL; i++) {
        comparison = compare(left, right, tags[i], reverse);
        if (comparison != 0)
            break;
    }
    if (comparison <= 0) {
        result = left;
        result->next = merge(left->next, right, tags, reverse);
    } else {
        result = right;
        result->next = merge(left, right->next, tags, reverse);
    }
    return result;
}

static linked_list_t *merge_sort(linked_list_t *head, char **tags, int reverse)
{
    linked_list_t *middle = head;
    linked_list_t *fast = head->next;
    linked_list_t *left;
    linked_list_t *right;

    if (head == NULL || head->next == NULL)
        return head;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
            middle = middle->next;
        }
    }
    left = head;
    right = middle->next;
    middle->next = NULL;
    left = merge_sort(left, tags, reverse);
    right = merge_sort(right, tags, reverse);
    return merge(left, right, tags, reverse);
}

static int error_gestion_sort(char **args)
{
    if (args[0] == NULL) {
        my_putstr("Error: No sorting tags specified.\n");
        return (84);
    }
    if (my_strcmp(args[0], "NAME") != 0 && my_strcmp(args[0], "TYPE") != 0
        && my_strcmp(args[0], "ID") != 0) {
        my_putstr("Error: Invalid sorting tag.\n");
        return (84);
    }
    return 0;
}

int sort(void *data, char **args)
{
    linked_list_t **head = (linked_list_t **)data;
    int reverse = 0;
    int tagCount = 0;

    if (error_gestion_sort(args) == 84)
        return 84;
    while (args[tagCount] != NULL && my_strcmp(args[tagCount], "-r") != 0)
        tagCount++;
    if (args[tagCount] != NULL && my_strcmp(args[tagCount], "-r") == 0)
        reverse = 1;
    *head = merge_sort(*head, args, reverse);
    return 0;
}
