/*
** EPITECH PROJECT, 2024
** my_sokoban
** File description:
** sokoban.h
*/

#pragma once

#include "structure.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <ncurses.h>

// Memory handling

char *load_file_in_mem(char const *filepath);
int fill_map(sokoban_struct *sokoban, char *buffer);
int error_handling(sokoban_struct *sokoban);
void get_pos(sokoban_struct *sokoban);
void free_all(sokoban_struct *sokoban);
void free_all_before_fill(sokoban_struct *sokoban);

// Game handling

int my_sokoban(char *filepath, sokoban_struct *);
int display_map(sokoban_struct *sokoban);

// Player moves

void move_up(sokoban_struct *sokoban);
void move_down(sokoban_struct *sokoban);
void move_left(sokoban_struct *sokoban);
void move_right(sokoban_struct *sokoban);

// Box handling

void box_up(sokoban_struct *sokoban);
void box_down(sokoban_struct *sokoban);
void box_left(sokoban_struct *sokoban);
void box_right(sokoban_struct *sokoban);
