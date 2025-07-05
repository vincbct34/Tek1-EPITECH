/*
** EPITECH PROJECT, 2024
** Duo stumper
** File description:
** duo
*/

#pragma once
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <stdbool.h>

//ONE PARAMETER
int basic_count(char *str);

//TWO PARAMETERS
int handle_three_args(char **av, int ac);
int three_args(char **av, bool is_group, bool is_sort);

//THREE PARAMETERS
int handle_four_args(char **av, int ac);
int four_args(char **av, bool is_group, bool is_sort);

//FOUR PARAMETERS
int handle_five_args(char **av, int ac);
int five_args(char **av, bool is_group, bool is_sort);
