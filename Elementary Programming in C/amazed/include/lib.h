/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-amazed-vincent.bichat
** File description:
** lib
*/

#pragma once
////////////////////////// INCLUDES ////////////////////////////
#include <unistd.h>                                           //
#include <stdio.h>                                            //
#include <stdbool.h>                                          //
#include <string.h>                                           //
#include <stdlib.h>                                           //
#include <stddef.h>                                           //
///////////////////////////// LIB //////////////////////////////
int my_getnbr(char const *str);                               //
int my_strcmp(char *s1, char *s2);                            //
void my_putchar(char c);                                      //
void my_putstr(char *str);                                    //
int my_strlen(char *str);                                     //
char *my_strcpy(char *dest, char const *src);                 //
void my_putnbr(int nb);                                       //
int my_strncmp(char *s1, char *s2, int n);                    //
char *my_strcat(char *dest, char const *src);                 //
char *my_strdup(char *src);                                   //
char **my_str_to_word_array(char *str, char separator);       //
int my_strchr(char *str, char c);                             //
int is_alpha_num(char *str);                                  //
char *my_strncpy(char *dest, char const *src, int n);         //
void my_puterror(char *str);                                  //
int my_strarraylen(char **array);                             //
char *my_realloc(char *str, char c);                          //
int is_delim(char c);                                         //
void clean_str(char *str, int i);                             //
int my_strstr(char *str, char *to_find);                      //
int my_getlastnbr(char *str);                                 //
int is_num(char *str);                                        //
int my_isdigit(char c);                                       //
////////////////////////////////////////////////////////////////
