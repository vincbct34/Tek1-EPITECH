/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Header file for airplane structure
*/

#pragma once
#include <SFML/Graphics.h>
#include "tower.h"
#include "path.h"
#include "utils.h"
#define PLANE_SYMBOL            'A'
#define PLANE_SPRITE_SIZE       20.0

typedef struct pl {
    path_t *path;
    unsigned int delay;
    float angle;
    sfFloatRect hitbox;
    sfSprite *sprite;
    sfRectangleShape *outline;
} pl_t;

pl_t *pl_create(path_t *path, sfTexture *texture, uint delay,
    uint w_width);
pl_t *pl_init(pl_t *plane, path_t *path, uint delay, uint w_width);
void pl_destroy(pl_t *plane);
void pl_move(pl_t *plane, sfVector2f const offset, uint w_width);
