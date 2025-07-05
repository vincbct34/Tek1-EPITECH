/*
** EPITECH PROJECT, 2024
** Minishell 1
** File description:
** my.h
*/

#pragma once
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
////////////////////////////////////////////////////////////////
