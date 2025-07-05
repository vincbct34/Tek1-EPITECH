/*
** EPITECH PROJECT, 2024
** Stumper 7
** File description:
** crocus.h
*/

#pragma once

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct stumper_s {
    bool flag_s;
    bool flag_n;
    char *str;
    char *argument;
} stumper_t;

int is_alphanum(char a);
int return_error(int error);
char *dup_arg(char *str);
char *check_and_dup_arg(char *str);

int check_flags(int ac, char **av);
int choose_method(stumper_t *stumper, int ac, char **av);
int logical_application(stumper_t *stumper);
void exit_all(stumper_t *stumper);
void free_remaining_elements(stumper_t *stumper);
int display_string(char *str, char c);

int draw_0(int line, char c);
int draw_1(int line, char c);
int draw_2(int line, char c);
int draw_3(int line, char c);
int draw_4(int line, char c);
int draw_5(int line, char c);
int draw_6(int line, char c);
int draw_7(int line, char c);
int draw_8(int line, char c);
int draw_9(int line, char c);
