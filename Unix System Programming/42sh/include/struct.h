/*
** EPITECH PROJECT, 2024
** bsminishell1
** File description:
** struct.h
*/

#include <unistd.h>
#include <termios.h>
#include <ctype.h>
#include <stdbool.h>

#pragma once

typedef struct env_s {
    char *name;
    char *value;
    struct env_s *next;
}env_t;

typedef struct Node_s {
    char *operation;
    struct Node_s *left;
    struct Node_s *right;
}node_t;

typedef struct DelimiterInfo_s {
    int delimiterIndex;
    char *delimiter;
} DelimiterInfo_t;

typedef struct history_s {
    char *prompt;
    char *time;
    struct history_s* prev;
    struct history_s* next;
} history_t;

typedef struct termios_s {
    struct termios old_termios;
    struct termios new_termios;
    char *prompt;
    char *buffer;
    char *clipboard;
} termios_t;

typedef struct alias_s {
    char *alias;
    char *command;
    struct alias_s *next;
} alias_t;

typedef struct minishell_s {
    char *input;
    char *init_path;
    char **args;
    char **args_tmp;
    char **env;
    int return_value;
    int no_builtin;
    int return_glob;
    size_t size;
    char *old_pwd;
    env_t *env_list;
    history_t *history_list;
    termios_t *data_termios;
    alias_t *alias;
}minishell_t;

typedef struct quote_info_s {
    bool in_quotes;
    char quote_char;
    char *delim;
    int count;
    int prev_index;
} quote_info_t;

typedef struct token_info_s {
    int buf_idx;
    bool in_quotes;
    char quote_char;
    char *buffer;
} token_info_t;
