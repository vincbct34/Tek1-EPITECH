/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-robotfactory-vincent.bichat
** File description:
** write.c
*/

#include "robot.h"

op_t *find_op(char *name)
{
    for (int i = 0; op_tab[i].mnemonique; i++)
        if (my_strcmp(name, op_tab[i].mnemonique) == 0)
            return &op_tab[i];
    return NULL;
}

int encode_instruction(int fd, char **instruction)
{
    op_t *op = find_op(instruction[0]);

    if (!op)
        return 84;
    write(fd, &op->code, 1);
    return 0;
}
