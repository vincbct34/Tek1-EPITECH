/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "tower.h"

tow_t *create_tower(sfVector2f pos, sfTexture *texture, unsigned int radius)
{
    tow_t *tower = malloc(sizeof(*tower));
    sfVector2f circle_pos = {pos.x + 20 - radius, pos.y + 20 - radius};

    if (!tower)
        return (NULL);
    tower->pos = pos;
    tower->radius = radius;
    tower->sprite = sfSprite_create();
    tower->control_area = sfCircleShape_create();
    if (!(tower->sprite) || !(tower->control_area))
        return (NULL);
    sfSprite_setTexture(tower->sprite, texture, sfTrue);
    sfSprite_setPosition(tower->sprite, tower->pos);
    sfCircleShape_setRadius(tower->control_area, radius);
    sfCircleShape_setFillColor(tower->control_area, sfTransparent);
    sfCircleShape_setOutlineColor(tower->control_area, sfBlue);
    sfCircleShape_setOutlineThickness(tower->control_area, 5);
    sfCircleShape_setPosition(tower->control_area, circle_pos);
    return (tower);
}

void destroy_tower(tow_t *tower)
{
    sfSprite_destroy(tower->sprite);
    sfCircleShape_destroy(tower->control_area);
    free(tower);
}
