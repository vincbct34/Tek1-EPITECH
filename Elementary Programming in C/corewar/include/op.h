/*
** EPITECH PROJECT, 2024
** Corewar
** File description:
** op.h
*/

#pragma once

#define MEM_SIZE (6 * 1024)
#define IDX_MOD 512 /* modulo of the index < */
#define MAX_ARGS_NUMBER 4 /* this may not be changed 2^*IND_SIZE */

#define COMMENT_CHAR '#'
#define LABEL_CHAR ':'
#define DIRECT_CHAR '%'
#define SEPARATOR_CHAR ','
#define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING ".name"
#define COMMENT_CMD_STRING ".comment"

/*
** regs
*/
#define REG_NUMBER 16 /* r1 <--> rx */

typedef char args_type_t;

#define T_REG 1 /* register */
#define T_DIR 2 /* direct  (ld  #1,r1  put 1 into r1) */
#define T_IND 4
#define T_LAB 8 /* LABEL */

typedef struct op_s {
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
} op_t;

/*
** size (in bytes)
*/
#define IND_SIZE 2
#define DIR_SIZE 4
#define REG_SIZE DIR_SIZE

/*
** op_tab
*/
extern op_t op_tab[];

/*
** header
*/
#define PROG_NAME_LENGTH 128
#define COMMENT_LENGTH 2048
#define COREWAR_EXEC_MAGIC 0xea83f3

typedef struct header_s {
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

/*
** live
*/
#define CYCLE_TO_DIE 1536 /* number of cycle before beig declared dead */
#define CYCLE_DELTA 5
#define NBR_LIVE 40
