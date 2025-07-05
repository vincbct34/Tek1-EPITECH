/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#include <SFML/Graphics.h>
#include "plane.h"

static void pl_out(pl_t *plane, uint w_width)
{
    sfVector2f offset = {(float)w_width, 0.0};

    if (plane->path->pos.x > w_width)
        offset.x = -offset.x;
    pl_move(plane, offset, w_width);
}

void pl_move(pl_t *plane, sfVector2f const offset, uint w_width)
{
    plane->path->pos.x += offset.x;
    plane->path->pos.y += offset.y;
    plane->hitbox.left += offset.x;
    plane->hitbox.top += offset.y;
    sfSprite_move(plane->sprite, offset);
    sfRectangleShape_setPosition(plane->outline, (sfVector2f)
                                {plane->hitbox.left, plane->hitbox.top});
    if (plane->path->pos.x < 0 || plane->path->pos.x > w_width)
        pl_out(plane, w_width);
}
