/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** init.c
*/

#include "corewar.h"

void fill_map(corewar_t *corewar)
{
    for (int i = 0; i < MEM_SIZE; i++)
        corewar->map[i] = 0;
}

corewar_t *init_corewar(void)
{
    corewar_t *corewar = malloc(sizeof(corewar_t));

    corewar->cycle = 0;
    corewar->die_cycle = CYCLE_TO_DIE;
    corewar->dmp_cycle = -1;
    corewar->survivor = NULL;
    corewar->survivor_id = -1;
    corewar->robots = NULL;
    corewar->map = malloc(sizeof(int) * MEM_SIZE);
    fill_map(corewar);
    return corewar;
}

args_t *init_data(corewar_t *corewar)
{
    args_t *data = malloc(sizeof(args_t));

    data->address = NULL;
    data->nb_robots = NULL;
    data->dmp = NULL;
    data->corewar = corewar;
    return data;
}
