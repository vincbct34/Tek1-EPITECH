/*
** EPITECH PROJECT, 2023
** structure.h
** File description:
** Structure of the Setting Up project
*/

#pragma once

typedef struct map_s {
    char **arr;
    int nb_rows;
    int nb_cols;
    int square_size;
    int square_size_max;
    int max_square_row;
    int max_square_col;
} map_t;
