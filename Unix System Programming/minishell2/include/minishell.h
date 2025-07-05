/*
** EPITECH PROJECT, 2024
** Minishell 1
** File description:
** minishell.h
*/

#pragma once
////////////////////////// INCLUDES ////////////////////////////
#include <unistd.h>                                           //
#include <stdio.h>                                            //
#include <stdbool.h>                                          //
#include <string.h>                                           //
#include <stdlib.h>                                           //
#include <sys/types.h>                                        //
#include <sys/wait.h>                                         //
#include <errno.h>                                            //
#include <sys/stat.h>                                         //
#include <fcntl.h>                                            //
///////////////////////// LINKED LIST //////////////////////////
typedef struct env_list_s {                                   //
    char *name;                                               //
    char *value;                                              //
    struct env_list_s *next;                                  //
} env_list;                                                   //
///////////////////////// BINARY TREE //////////////////////////
typedef struct tree_s {                                       //
    char *redirect_l;                                         //
    char *redirect_r;                                         //
    char *redirect_r_r;                                       //
    char *redirect_l_l;                                       //
    char **command;                                           //
    struct tree_s *pipe;                                      //
    struct tree_s *next;                                      //
} tree;                                                       //
////////////////////////// STRUCTURE ///////////////////////////
typedef struct s_minishell {                                  //
    char *input;                                              //
    char **basic_args;                                        //
    char **env;                                               //
    char *path;                                               //
    char *pwd;                                                //
    char *oldpwd;                                             //
    char *home;                                               //
    int return_value;                                         //
    env_list *env_list;                                       //
    tree *tree;                                               //
} minishell;                                                  //
////////////////////////// PROTOTYPES //////////////////////////
env_list *env_to_list(char **env);                            //
char **list_to_env(env_list *list);                           //
void my_minishell(minishell *msh);                            //
char **parsing(minishell *msh);                               //
char *get_path(char **array, char **env);                     //
void error_gest_segfault(int status, minishell *msh);         //
tree *build_binary_tree(minishell *msh);                      //
void commands_tree(minishell *msh);                           //
void get_input(minishell *msh);                               //
void my_exec(minishell *msh);                                 //
void my_builtin(minishell *msh);                              //
void my_exit(minishell *msh);                                 //
void my_cd(minishell *msh);                                   //
void get_home(minishell *msh);                                //
void my_env(minishell *msh);                                  //
void my_setenv(minishell *msh);                               //
void my_unsetenv(minishell *msh);                             //
void display_list(tree *head, int level);                     //
void add_pipe(tree *head, char *command);                     //
void add_right(tree *head, char *command, int is_pipe);       //
void add_left(tree *head, char *command, int is_pipe);        //
void add_double_left(tree *head, char *command, int is_pipe); //
void add_double_right(tree *head, char *command, int is_pipe);//
tree *create_node(void);                                      //
void execute_pipe(tree *head, minishell *msh);                //
void commands_for_tree(tree *head, minishell *msh);           //
void my_cd_tree(minishell *msh, char **command);              //
void my_setenv_tree(minishell *msh, char **command);          //
void my_unsetenv_tree(minishell *msh, char **command);        //
void child_process(tree *head, minishell *msh);               //
void my_exec_tree(tree *head, minishell *msh);                //
void my_pipe(tree *head, minishell *msh);                     //
int check_if_pipe_valid(minishell *msh, tree *head);          //
////////////////////////////////////////////////////////////////
