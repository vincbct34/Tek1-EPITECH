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
#include <string.h>                                           //
#include <stdlib.h>                                           //
#include <sys/types.h>                                        //
#include <sys/wait.h>                                         //
#include <errno.h>                                            //
#include <sys/stat.h>                                         //
///////////////////////// LINKED LIST //////////////////////////
typedef struct env_list_s {                                   //
    char *name;                                               //
    char *value;                                              //
    struct env_list_s *next;                                  //
} env_list;                                                   //
////////////////////////// STRUCTURE ///////////////////////////
typedef struct s_minishell {                                  //
    char *input;                                              //
    char **args;                                              //
    char **env;                                               //
    char *path;                                               //
    char *pwd;                                                //
    char *oldpwd;                                             //
    char *home;                                               //
    int return_value;                                         //
    env_list *env_list;                                       //
} minishell;                                                  //
////////////////////////// PROTOTYPES //////////////////////////
env_list *env_to_list(char **env);                            //
void free_env_list(env_list *list);                           //
char **list_to_env(env_list *list);                           //
void my_minishell(minishell *msh);                            //
char **parsing(minishell *msh);                               //
void get_input(minishell *msh);                               //
void my_exec(minishell *msh);                                 //
void my_builtin(minishell *msh);                              //
void my_exit(minishell *msh);                                 //
void my_cd(minishell *msh);                                   //
void my_env(minishell *msh);                                  //
void my_setenv(minishell *msh);                               //
void my_unsetenv(minishell *msh);                             //
////////////////////////////////////////////////////////////////
