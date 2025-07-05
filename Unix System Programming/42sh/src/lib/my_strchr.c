/*
** EPITECH PROJECT, 2024
** B-PSU-200
** File description:
** my_strchr
*/

#include "../../include/my.h"

char *my_strchr(char const *str, char character)
{
    while (*str != '\0') {
        if (*str == character) {
            return (char *)str;
        }
        str++;
    }
    if (*str == character) {
        return (char *)str;
    }
    return NULL;
}
