/*
** EPITECH PROJECT, 2024
** RobotFactory
** File description:
** copy_array.c
*/

#include "robot.h"

int my_arraylen(char **array)
{
    int i = 0;

    for (i = 0; array[i] != NULL; i++);
    return i;
}

char **copy_array(char **array)
{
    int i = 0;
    char **new_array = malloc(sizeof(char *) * (my_arraylen(array) + 1));

    for (i = 0; array[i] != NULL; i++) {
        new_array[i] = my_strdup(array[i]);
    }
    new_array[i] = NULL;
    return new_array;
}
