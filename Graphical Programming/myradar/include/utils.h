/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#pragma once
#include <SFML/Graphics.h>

typedef unsigned int uint;
float angle_from_coord(sfVector2f point_a, sfVector2f point_b);
sfVector2f rotate_point(sfVector2f point, sfVector2f center,
    float angle);
sfVector2f *get_corners(sfFloatRect const rect);
sfVector2f *get_rotated_corners(sfFloatRect hitbox, float angle);
sfFloatRect bound_box_of_rotated(sfFloatRect const hitbox, float angle);
sfBool matchpos(sfVector2f pos_1, sfVector2f pos_2);
sfBool overpos(sfVector2f pos_1, sfVector2f pos_2, float const threshold);
sfBool bound_have_pos(sfIntRect const boundary, sfVector2f const pos);
sfBool bound_over(sfIntRect const boundary, sfIntRect const other);
sfBool bound_in_cir(sfFloatRect const frect,
    sfVector2f circle_center, unsigned int circle_radius);
sfBool point_in_cir(sfVector2f point, sfVector2f circle_center,
    unsigned int circle_radius);
