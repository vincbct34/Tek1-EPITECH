/*
** EPITECH PROJECT, 2024
** RobotFactory
** File description:
** compare.c
*/

#include "robot.h"

int validate_parameter(char *parameter, int op_index, int param_index)
{
    args_type_t expected_type = op_tab[op_index].type[param_index];
    bool is_valid_param = false;

    if ((expected_type & T_REG) && is_a_register(parameter)) {
        is_valid_param = true;
    }
    if ((expected_type & T_DIR) && is_a_direct(parameter)) {
        is_valid_param = true;
    }
    if ((expected_type & T_IND) && is_an_indirect(parameter)) {
        is_valid_param = true;
    }
    if (is_valid_param == false) {
        return 84;
    }
    return 0;
}

static int find_op_tab_index(char *mnemonique, op_t op_tab[])
{
    int op_tab_index = 0;

    while (op_tab[op_tab_index].mnemonique != NULL) {
        if (my_strcmp(mnemonique, op_tab[op_tab_index].mnemonique) == 0) {
            return op_tab_index;
        }
        op_tab_index++;
    }
    return -1;
}

int count_parameters(char **parameters)
{
    int count = 0;

    while (parameters[count] != NULL) {
        count++;
    }
    return count;
}

int validate_parameters(char **parameters, op_t op)
{
    int param_count = count_parameters(parameters);
    int op_index = find_op_tab_index(op.mnemonique, op_tab);

    if (param_count != op.nbr_args) {
        return 84;
    }
    for (int i = 0; i < param_count; i++) {
        if (validate_parameter(parameters[i], op_index, i) == 84) {
            return 84;
        }
    }
    return 0;
}

static int validate_instruction(char **instruction, op_t op)
{
    char **parameters = &instruction[1];

    if (validate_parameters(parameters, op) == 84) {
        return 84;
    }
    return 0;
}

int compare_output_with_op_tab(char ***output, op_t op_tab[])
{
    int index = get_body_index(output);
    int op_tab_index;
    char *mnemonique;

    if (index == -1)
        return 1;
    while (output[index] != NULL) {
        mnemonique = output[index][0];
        if (mnemonique == NULL || mnemonique[0] == '\0') {
            index++;
            continue;
        }
        op_tab_index = find_op_tab_index(mnemonique, op_tab);
        if (op_tab_index == -1)
            return 84;
        if (validate_instruction(output[index], op_tab[op_tab_index]) == 84)
            return 84;
        index++;
    }
    return 0;
}
