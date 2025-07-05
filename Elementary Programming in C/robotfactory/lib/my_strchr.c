/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-robotfactory-vincent.bichat
** File description:
** my_strchr.c
*/

#include "robot.h"

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
