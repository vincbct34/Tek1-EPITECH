/*
** EPITECH PROJECT, 2024
** RobotFactory
** File description:
** index.c
*/

#include "robot.h"

int check_line_for_body_start(char ***output, int index, int *body_index)
{
    if (output[index][0] != NULL) {
        if (*body_index != -1)
            return index;
    } else
        *body_index = index;
    return -1;
}

int get_body_index(char ***output)
{
    int index = 0;
    int body_index = -1;
    int result;

    while (output[index] != NULL) {
        result = check_line_for_body_start(output, index, &body_index);
        if (result != -1)
            return result;
        index++;
    }
    return body_index;
}
