/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** corewar.h
*/

#pragma once
#include "my.h"
#include "op.h"

typedef struct robot_s {
    char name[PROG_NAME_LENGTH + 1];
    char comment[COMMENT_LENGTH + 1];
    int pc;
    int reg[REG_NUMBER];
    int carry;
    int cycle;
    char *content;
    int alive;
    int size;
    int id;
    int last_live;
    int address;
    int last_execute;
}robot_t;

typedef struct corewar_s {
    int *map;
    int die_cycle;
    int cycle;
    robot_t **robots;
    long dmp_cycle;
    char *survivor;
    int survivor_id;
} corewar_t;

typedef struct args_s {
    char *address;
    char *nb_robots;
    corewar_t *corewar;
    char *dmp;
} args_t;

corewar_t *init_corewar(void);
void fill_map(corewar_t *corewar);

/*file.c*/
int file_verification(char *filepath, char **content);
int check_file(char *filepath, corewar_t *corewar, args_t *data);

/*argument.c*/
args_t *init_data(corewar_t *corewar);
int check_args(int ac, char **av, corewar_t *corewar);

/*flag.c*/
int check_flag(int ac, char **av, args_t *data, int j);

/*others*/
int print_usage(int ac, char **av);
void robot_parser(char *nb_robots, char *address, char *content,
    corewar_t *corewar);
