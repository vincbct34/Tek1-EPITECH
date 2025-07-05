/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Header file for path structure
*/

#pragma once
#include <SFML/Graphics.h>
#include "tower.h"
#include "utils.h"

typedef struct path {
    sfVector2f pos;
    sfVector2f end;
    sfVector2f step;
} path_t;

path_t *create_path(sfVector2f beg, sfVector2f end,
    uint speed, uint w_width);
sfVector2f offset_step(sfVector2f point_a, sfVector2f point_b);
path_t *rand_path(uint w_width);
