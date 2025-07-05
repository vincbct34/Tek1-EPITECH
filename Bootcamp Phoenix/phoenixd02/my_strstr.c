/*
** EPITECH PROJECT, 2023
** my_strstr.c
** File description:
** Reproduces the behavior of strstr
*/

#include "include/my.h"
#include <stdio.h>

char *my_strstr(char *str, char const *to_find)
{
    char *str_ptr;
    char const *to_find_ptr;

    if (*to_find == '\0')
        return (char *)str;
    while (*str != '\0') {
        str_ptr = str;
        to_find_ptr = to_find;
        while (*to_find_ptr != '\0' && *str_ptr == *to_find_ptr) {
            str_ptr++;
            to_find_ptr++;
        }
        if (*to_find_ptr == '\0')
            return (char *)str;
        str++;
    }
    return NULL;
}
