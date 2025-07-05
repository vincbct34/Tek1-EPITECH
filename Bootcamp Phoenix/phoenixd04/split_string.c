/*
** EPITECH PROJECT, 2023
** split_string.c
** File description:
** Bootcamp Day 4
*/

#include "includes/phoenix.h"
#include <stdlib.h>
#include <stdbool.h>

static bool char_is_alphanumeric(char c)
{
    if (c >= '0' && c <= '9')
        return (true);
    if (c >= 'A' && c <= 'Z')
        return (true);
    if (c >= 'a' && c <= 'z')
        return (true);
    return (false);
}

static void split_string_bis(split_string_t *split)
{
    while (char_is_alphanumeric(split->str[split->i])) {
        split->dest[split->j][split->k] = split->str[split->i];
        split->i++;
        split->k++;
    }
    split->dest[split->j][split->k] = '\0';
    split->j++;
}

char **split_string(const char *str)
{
    split_string_t *split = malloc(sizeof(split_string_t));
    int len = my_strlen(str);

    split->str = str;
    split->i = 0;
    split->j = 0;
    split->k = 0;
    split->dest = malloc(sizeof(char *) * (len + 1));
    while (split->str[split->i] != '\0') {
        while (!(char_is_alphanumeric(split->str[split->i])
            || split->str[split->i] == '\0'))
            split->i++;
        if (split->str[split->i] != '\0') {
            split->dest[split->j] = malloc(sizeof(char) * (len + 1));
            split->k = 0;
            split_string_bis(split);
        }
    }
    split->dest[split->j] = NULL;
    return split->dest;
}
