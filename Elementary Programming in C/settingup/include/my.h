/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** Header
*/

#pragma once
#include "structure.h"

int my_putstr(char const *str);
int my_getnbr(char const *str);
char **load_2d_arr_from_file(char const *filepath, map_t *map);
char *load_file_in_mem(char const *filepath);
char **mem_alloc_2d_array(map_t *map);
int is_square_of_size(char **map, int start_row, int start_col, int size);
int find_biggest_square(char **arr, map_t *map);
void generate_map(int size, char *pathern);
int my_getcolons(char *buffer, int k);
char **create_square(int ac, char **av, map_t *map);
int my_strlen(char const *str);
int my_is_digit(char *str);
int error_gestion_gen(int ac, char **av);
int is_file_valid(int ac, char **av, char *filepath);
