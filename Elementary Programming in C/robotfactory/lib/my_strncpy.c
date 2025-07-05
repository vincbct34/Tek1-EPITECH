/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-robotfactory-vincent.bichat
** File description:
** my_strncpy.c
*/

#include "robot.h"

char *my_strncpy(char *dest, const char *src, int n)
{
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for (; i < n; i++) {
        dest[i] = '\0';
    }
    return dest;
}
