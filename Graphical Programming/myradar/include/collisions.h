/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#pragma once
#include <SFML/Graphics.h>
#include "sim.h"

pl_t *collide_pl(pl_t *plane, tow_t **towers,
    quadtree_t *quadtree);
sfBool pl_in_area(sfFloatRect hitbox, tow_t **towers);
pl_t *check_collide(pl_t *plane, quadtree_t *quadtree);
