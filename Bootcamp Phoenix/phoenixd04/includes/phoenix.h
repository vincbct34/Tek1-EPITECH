/*
** EPITECH PROJECT, 2023
** phoenix.h
** File description:
** Bootcamp Day 3
*/

#pragma once

typedef struct split_string_s {
    int i;
    int j;
    int k;
    char **dest;
    const char *str;
} split_string_t;

void my_putchar(char c);
int show_number(int nb);
int show_string(char const *str);
char *reverse_string(char *str);
int to_number(char const *str);
int is_prime_number(int nb);
char *my_strcpy(char *dest, char const *src);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strstr(char *str, char const *to_find);
int my_strlen(char const *str);
char *duplicate_string(char const *src);
struct info_param *parameters_to_array(int ac, char **av);
char **split_string(char const *str);
int show_string_array(char const **array);
