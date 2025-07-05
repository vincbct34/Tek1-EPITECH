/*
** EPITECH PROJECT, 2024
** RobotFactory
** File description:
** my_strcmp.c
*/

#include "robot.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
        i++;
    }
    return (s1[i] - s2[i]);
}
