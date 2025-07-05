/*
** EPITECH PROJECT, 2024
** RobotFactory
** File description:
** convert.c
*/

#include "robot.h"

char ***create_3d_array(char **input_2d)
{
    int num_lines = 0;
    char ***output_3d = NULL;
    char **words = NULL;

    while (input_2d[num_lines] != NULL) {
        num_lines++;
    }
    output_3d = (char ***)malloc((num_lines + 1) * sizeof(char **));
    for (int i = 0; i < num_lines; i++) {
        words = my_strtok(input_2d[i], " \t");
        output_3d[i] = words;
    }
    output_3d[num_lines] = NULL;
    return output_3d;
}
