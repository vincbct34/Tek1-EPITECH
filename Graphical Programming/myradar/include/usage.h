/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#pragma once
#define MY_EXIT_SUCCESS         0
#define MY_EXIT_OPTION          192
#define MY_EXIT_FAILURE         84

int check_args(int ac, char **av);
int check_options(char *arg);
void print_help(void);
void print_bad_ac(int ac, char **av);
