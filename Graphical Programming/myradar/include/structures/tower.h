/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Header file for tower struct
*/

#pragma once
#include <SFML/Graphics.h>
#define TOWER_SYMBOL            'T'

typedef struct tow {
    sfVector2f pos;
    unsigned int radius;
    sfSprite *sprite;
    sfCircleShape *control_area;
} tow_t;

tow_t *create_tower(sfVector2f pos, sfTexture *texture,
    unsigned int radius);
void destroy_tower(tow_t *tower);
sfVector2f get_random_tower_pos(tow_t **towers);
sfBool vector2f_match(sfVector2f pos_1, sfVector2f pos2);
