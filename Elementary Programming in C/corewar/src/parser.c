/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** parser.c
*/

#include "corewar.h"

static void fill_reg(robot_t *robot)
{
    for (int i = 0; i < REG_NUMBER; i++)
        robot->reg[i] = 0;
}

void header_parser(char *content, robot_t *robot)
{
    (void)content;
    (void)robot;
}

void content_parser(char *content, robot_t *robot)
{
    (void)content;
    (void)robot;
}

void check_placement(corewar_t *corewar, robot_t *robot)
{
    (void)corewar;
    (void)robot;
}

void adding_robot(corewar_t *corewar, robot_t *robot)
{
    (void)corewar;
    (void)robot;
}

void robot_parser(char *nb_robots, char *address, char *content,
    corewar_t *corewar)
{
    robot_t *robot = malloc(sizeof(robot_t));

    robot->address = (address == NULL) ? -1 : my_getnbr(address);
    robot->carry = 0;
    robot->cycle = 0;
    robot->id = (nb_robots == NULL) ? -1 : my_getnbr(nb_robots);
    robot->pc = 0;
    header_parser(content, robot);
    content_parser(content, robot);
    fill_reg(robot);
    robot->reg[0] = robot->id;
    robot->last_execute = -1;
    check_placement(corewar, robot);
    adding_robot(corewar, robot);
}
