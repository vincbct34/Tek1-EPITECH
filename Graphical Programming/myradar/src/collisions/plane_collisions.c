/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#include <SFML/Graphics.h>
#include "sim.h"
#include "collisions.h"
#include "utils.h"

pl_t *collide_pl(pl_t *plane, tow_t **towers,
    quadtree_t *quadtree)
{
    if (pl_in_area(plane->hitbox, towers)) {
        sfRectangleShape_setOutlineColor(plane->outline, sfGreen);
        return (sfFalse);
    } else {
        sfRectangleShape_setOutlineColor(plane->outline, sfYellow);
    }
    return (check_collide(plane, quadtree));
}

sfBool pl_in_area(sfFloatRect hitbox, tow_t **towers)
{
    for (unsigned int i = 0; towers[i]; i++)
        if (bound_in_cir(hitbox, towers[i]->pos, towers[i]->radius))
            return (sfTrue);
    return (sfFalse);
}

pl_t *check_collide(pl_t *plane, quadtree_t *quadtree)
{
    sfIntRect area = (sfIntRect) {plane->path->pos.x - 30.0,
                                plane->path->pos.y - 30.0, 50, 50};
    pl_t **planes = quadtr_qu(quadtree, area);

    if (!planes)
        return (NULL);
    for (unsigned int i = 0; planes[i]; i++)
        if (!(matchpos(plane->path->pos, planes[i]->path->pos)))
            return (planes[i]);
    return (NULL);
}
