/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#pragma once
#include <stdio.h>
#include <SFML/Graphics.h>
#include "sim.h"
#include "plane.h"
#include "tower.h"
#define OPEN_FAILURE_MSG        "File cannot be opened\n"
#define READ_FAILURE_MSG        "File cannot be read\n"

char *file_buff(char const *file_path);
unsigned int size_file(char const *file_path);
int get_entities_from_file(char const *file_path, sim_t *sim);
int fill_entities_by_line(FILE *stream, sim_t *sim);
pl_t *add_plane_from_line(char *current_line, sfTexture *pl_texture,
    unsigned int w_width);
tow_t *add_tower_from_line(char *current_line, sfTexture *);
