/*
** EPITECH PROJECT, 2024
** Navy
** File description:
** struct.h
*/

#pragma once
#include <stdbool.h>

typedef struct placement_s {
    int start;
    int end;
    int fixed;
    bool is_horizontal;
} placement_t;

struct request {
    int *my_grid;
    int *enemy_grid;
    char *file_name;
    char *line;
    int state;
    int callback;
    int player_pid;
    int enemy_pid;
    int enemy_len;
    int tour;
    int wait;
    int running;
    int turn;
};
