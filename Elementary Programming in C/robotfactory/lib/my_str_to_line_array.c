/*
** EPITECH PROJECT, 2024
** RobotFactory
** File description:
** my_str_to_line_array.c
*/

#include "robot.h"

int count_line(char *buffer)
{
    int count = 0;

    for (int j = 0; buffer[j] != '\0'; j++) {
        if (buffer[j] == '\n')
            count++;
    }
    return (count);
}

char **my_str_to_line_array(char *buffer)
{
    int count = count_line(buffer);
    char **array = malloc(sizeof(char *) * (count + 1));
    int i = 0;
    int j = 0;

    for (int k = 0; k < count; k++) {
        while (buffer[i] == ' ' || buffer[i] == '\t') {
            i++;
        }
        array[k] = malloc(sizeof(char) * (my_strlen(buffer) + 1));
        for (; buffer[i] != '\n' && buffer[i] != '\0'; i++) {
            array[k][j] = buffer[i];
            j++;
        }
        array[k][j] = '\0';
        j = 0;
        i++;
    }
    array[count] = NULL;
    return array;
}
