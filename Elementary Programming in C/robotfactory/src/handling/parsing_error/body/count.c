/*
** EPITECH PROJECT, 2024
** RobotFactory
** File description:
** count.c
*/

#include "robot.h"

int calculate_param_size(char *param, char *instruction)
{
    int size = 0;

    if (param[0] == 'r')
        size = 1;
    if (param[0] == DIRECT_CHAR) {
        size = (my_strcmp(instruction, "zjmp") == 0
            || my_strcmp(instruction, "ldi") == 0
            || my_strcmp(instruction, "sti") == 0
            || my_strcmp(instruction, "fork") == 0
            || my_strcmp(instruction, "lfork") == 0
            || my_strcmp(instruction, "lldi") == 0) ? 2 : 4;
    }
    if (param[0] != DIRECT_CHAR && param[0] != 'r')
        size = 2;
    return size;
}

int get_instruction_size(char *instruction, char **params)
{
    int size = 1;

    if (my_strcmp(instruction, "live") != 0
        && my_strcmp(instruction, "zjmp") != 0 &&
        my_strcmp(instruction, "fork") != 0
        && my_strcmp(instruction, "lfork") != 0) {
        size += 1;
    }
    for (int i = 0; params[i] != NULL; i++)
        size += calculate_param_size(params[i], instruction);
    return size;
}

int count_bytes_all(char ***output)
{
    int start = get_body_index(output);
    int total_size = 0;

    if (start == -1)
        return PROG_NAME_LENGTH + COMMENT_LENGTH + 16;
    for (int i = start; output[i] != NULL; i++) {
        if (output[i][0] == NULL)
            continue;
        total_size += get_instruction_size(output[i][0], output[i] + 1);
    }
    return total_size;
}
