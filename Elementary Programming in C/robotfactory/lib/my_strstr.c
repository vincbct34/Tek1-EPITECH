/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-robotfactory-vincent.bichat
** File description:
** my_strstr.c
*/

#include "robot.h"

char *my_strstr(char *str, const char *to_find)
{
    const char *ptr1 = NULL;
    const char *ptr2 = NULL;

    if (*to_find == '\0') {
        return (char *)str;
    }
    while (*str != '\0') {
        ptr1 = str;
        ptr2 = to_find;
        while (*ptr1 == *ptr2 && *ptr1 != '\0' && *ptr2 != '\0') {
            ptr1++;
            ptr2++;
        }
        if (*ptr2 == '\0') {
            return (char *)str;
        }
        str++;
    }
    return NULL;
}
