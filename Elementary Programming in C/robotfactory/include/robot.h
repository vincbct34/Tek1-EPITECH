/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-robotfactory-vincent.bichat
** File description:
** robot.h
*/

#pragma once

#include "op.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

//Structures
typedef struct status_s {
    bool name;
    bool comment;
}status_t;

typedef struct all_s {
    header_t *header;
    status_t *status;
}all_t;

//Header Parsing
char *read_file(char *filepath);

//Lib Parsing
int count_line(char *buffer);
char **my_str_to_line_array(char *buffer);
char **my_str_to_word_array(char *str, char separator);
int check_str(char *str);
void remove_label_lines(char **lines, int num_lines);
char *my_get_file_name(char *file);

//Lib Functions
int my_strlen(char *str);
char *my_strchr(char const *str, char character);
char *my_strrchr(const char *str, char character);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char **my_strtok(const char *str, const char *delim);
void my_putstr(char *str);
char **copy_array(char **array);
char *my_strdup(char *src);
int my_str_isnum(char const *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
char *my_strcat(char *dest, char const *src);
void my_putchar(char c);
int my_strcmp(char *s1, char *s2);

//Linked List Functions
char ***create_3d_array(char **input_2d);
int get_body_index(char ***array);
int compare_output_with_op_tab(char ***output, op_t op_tab[]);
//Verifications Functions
int handling_parsing_error(char **array, all_t *all);
bool is_a_register(char *str);
bool is_a_direct(char *str);
bool is_an_indirect(char *str);

//Params Functions
void remove_trailing_commas(char ***output);
int count_bytes(char ***output);
int count_bytes_all(char ***output);

//Write Functions
int encode_instruction(int fd, char **instruction);
op_t *find_op(char *name);
int write_cor_header(const char *filename, const header_t *header);
