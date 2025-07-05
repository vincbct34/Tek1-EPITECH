/*
** EPITECH PROJECT, 2024
** bsminishell1
** File description:
** my.h
*/

#include "struct.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>
#include <glob.h>

#pragma once

#define ENV minishell->env
#define INPUT minishell->input
#define ARGS minishell->args
#define ENV_LIST minishell->env_list
#define MINPUT minishell.input

int count_args(char *args);
int command_created(char **arg);
void execute_command(char **arg, char **env);
char *my_strcat(char *dest, char const *src);
char *my_strcat2(char *dest, char *src);
char *concat_path(char *path, char **arg, char *path_command);
void exec_command(minishell_t *minishell);
int check_directory(minishell_t *minishell);
void execute_child_process(minishell_t *minishell);

//LIB FUNCTIONS
void my_putstr(char *str);
int my_strlen(char const *str);
int show_number(int nb);
char *my_strdup(char *src);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2, int n);
char **my_str_to_word_array(char *str, char *separator);
char *my_strcpy(char *dest, char const *src);
char *my_strchr(char const *str, char character);
char *my_strndup(char *str, int n);
char *my_strstr(const char *haystack, const char *needle);
int is_empty_or_space(const char *str);
void clean_str(char *str, int i);
char **my_tabcat(char **tab1, char **tab2);
char **my_tabdup(char **tab);
int my_tablen(char **tab);
char **my_tabadd(char **tab, char *str);
char *array_to_str(char **array);
char **my_calloc(int rows, int cols);

//PROCESS FUNCTIONS
void child_process(char **arg, char **env, int status);
void child_cat_process(char **arg, char **env, int status, char *path_command);

//PRINT FUNCTIONS
void prompt(void);
void print_path(void);
char *get_prompte(void);

//COMMANDS FUNCTIONS
int verif_commands(minishell_t *minishell);
int built_in_commands(minishell_t *minishell);

//GETS FUNCTIONS
char *my_get_input(minishell_t minishell);
char *get_path(minishell_t *minishell);
char *get_input(void);
char *get_env_value(env_t *list, char *name);

//STATUS FUNCTIONS
int analyse_status(int status);

//STRTOK FUNCTIONS
char **malloc_strtok(char *args);
char **strtok_sep(char *args, char *sep);

//FREE FUNCTIONS
void free_all(minishell_t *minishell);
void free_array(char **array);

//ENV FUNCTIONS
void print_list(env_t *list);
int my_list_size(env_t *list);
void array_to_list(minishell_t *minishell);
char **list_to_double_array(env_t *list);
int modif_value(env_t *list, char *name, char *value);
int delete_element(env_t **list, char *name);
int push_back(minishell_t *minishell, env_t **list, char *name, char *value);
int is_alpha(char *str);
char *remove_tab(char *str);

//ENV COMMANDS
int set_env(minishell_t *minishell, char *name, char *value);
int print_env(minishell_t *minishell);
int unset_env(minishell_t *minishell, char *name);

//CD FUNCTIONS
int cd_command(minishell_t *minishell);

//ERROR FUNCTIONS
void my_puterror(char *str);
void check_error_delim(char *delimiter, char *leftExpr, char *rightExpr);

//TREE FUNCTIONS
node_t *build_tree(char *expr);
void print_tree(node_t *node, int space);
int find_main_delimiter(char *expr, int *delimiterIndex, char **delimiter);
node_t *create_node(char *operation);
int build_tree_to_array_and_execute(char **array, minishell_t *minishell);
int execute_tree_and_commands(node_t *node, minishell_t *minishell);
int execute_redirection(node_t *node, minishell_t *minishell, char direction);
int execute_redirection_bis(node_t *node, minishell_t *minishell,
    char direction);
int execute_pipe(node_t *node, minishell_t *minishell);
int execute_redirection_append(node_t *node, minishell_t *minishell);

// TERMIOS
void init_termios(termios_t *data_termios);
char init_terminal(minishell_t *shell);
char *my_realloc(char *str);
void copy(minishell_t shell, int *cursor_ind);
void paste(minishell_t shell, int *ind, int *cursor_ind);
void cut_line(minishell_t shell, int *ind, int *cursor_ind);

// HISTORY FUNCTIONS
void up_arrow(minishell_t *shell, int *ind, int *cursor_ind);
void down_arrow(minishell_t *shell, int *ind, int *cursor_ind);
void print_history(minishell_t *shell, char **args);
char *history_command(minishell_t *shell);

// IHIBIDORS
bool is_delim(char c, char *delim);
char *extract_token(char *str, int *index, char *delim);
void handle_quotes(char c, quote_info_t *info);
void handle_token_count(char c, quote_info_t *info);
void handle_char(char c, quote_info_t *info);
void handle_quoted_char(char c, token_info_t *info);
//ALIAS FUNCTIONS
void alias_check_calls(minishell_t *minishell);
int exec_alias(minishell_t *minishell);
int exec_all_alias(minishell_t *minishell);
char *emi_get_path(minishell_t *minishell, char *args_emi);
int exec_alias(minishell_t *minishell);
int flags_or_not(minishell_t *minishell);
int check_alias_loop(minishell_t *minishell);
int nbr_args_emi(char **args_emi);
int alias_with_param(minishell_t *minishell, char **args_emi, alias_t *tmp);
void emi_write_error(minishell_t *minishell, char **args_emi);
int param_or_not(minishell_t *minishell);
int flags_or_not_two(alias_t *tmp);
int alias_with_flags(minishell_t *minishell, char **args_emi, alias_t *tmp);
void add_alias(minishell_t *minishell);

// Test
int change_to_home_directory(minishell_t *minishell);
int change_to_directory(minishell_t *minishell, const char *path);
void free_alias(minishell_t *minishell);
void clean_str2(bool *space_encountered, char *str, int *j);
int my_tablen(char **tab);
int fill_tokens(char **tab, char *str, char *separator);
char **create_empty_tab(void);
int calculate_list_size(env_t *list);
char *my_strncpy(char *dest, char const *src, int n);
char *get_input_end(minishell_t shell, char c, int index);
void my_getinput3(minishell_t *shell, int *index, int *cursor_index, char c);
void my_getinput2(minishell_t *shell, int *index, int *cursor_index, char c);
char *my_get_input(minishell_t shell);
int handler(void);
void print_flags(alias_t *tmp);
void cond_to_add(minishell_t *minishell, alias_t *tmp);
void assign_parameter_bis(int m, int a_l, minishell_t *minishell, char **prm);
int exec_alias_bis(minishell_t *minishell, char **args_emi, alias_t *tmp);
int cd_error(minishell_t *minishell);
int start_error(minishell_t *minishell);
int execute_basic_commands(minishell_t *minishell);
int execute_alias_and_history(minishell_t *minishell);
int built_in_commands(minishell_t *minishell);
char *replace_tab(char *input);
