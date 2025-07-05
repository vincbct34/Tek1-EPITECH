/*
** EPITECH PROJECT, 2024
** RobotFactory
** File description:
** my_strdup.c
*/

#include "robot.h"

char *my_strdup(char *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
