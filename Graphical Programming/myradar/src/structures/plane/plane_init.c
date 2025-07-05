/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_radar.h"
#include "plane.h"

static float pl_angle(pl_t *plane, uint w_width)
{
    sfVector2f plane_beg = plane->path->pos;
    float x_diff = plane->path->end.x - plane->path->pos.x;

    if ((plane->path->step.x < 0) != (x_diff < 0)) {
        if ((plane->path->step.x < 0) && (x_diff > 0))
            plane_beg.x += w_width;
        else
            plane_beg.x -= w_width;
    }
    return (angle_from_coord(plane->path->end, plane_beg));
}

static void pl_rotate(pl_t *plane, uint w_width)
{
    sfFloatRect hitbox = {plane->path->pos.x, plane->path->pos.y,
                        PLANE_SPRITE_SIZE, PLANE_SPRITE_SIZE};

    sfSprite_setRotation(plane->sprite, 0.0);
    plane->angle = pl_angle(plane, w_width);
    sfSprite_rotate(plane->sprite, plane->angle);
    plane->hitbox = hitbox;
    plane->hitbox = bound_box_of_rotated(plane->hitbox, plane->angle);
}

pl_t *pl_init(pl_t *plane, path_t *path, uint delay, uint w_width)
{
    plane->delay = delay;
    plane->path = path;
    sfSprite_setPosition(plane->sprite, plane->path->pos);
    sfSprite_move(plane->sprite, (sfVector2f) {10, 10});
    pl_rotate(plane, w_width);
    sfRectangleShape_setPosition(plane->outline, (sfVector2f)
                                {plane->hitbox.left, plane->hitbox.top});
    sfRectangleShape_setSize(plane->outline, (sfVector2f)
                                {plane->hitbox.width, plane->hitbox.height});
    return (plane);
}
