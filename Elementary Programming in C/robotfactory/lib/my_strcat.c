/*
** EPITECH PROJECT, 2024
** RobotFactory
** File description:
** my_strcat.c
*/

#include "robot.h"

char *my_strcat(char *dest, char const *src)
{
    int i;
    int j;

    for (i = 0; dest[i] != '\0'; i++);
    for (j = 0; src[j] != '\0'; j++) {
        dest[i + j] = src[j];
    }
    dest[i + j] = '\0';
    return dest;
}
