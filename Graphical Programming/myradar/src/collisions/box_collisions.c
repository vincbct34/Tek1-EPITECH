/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#include <stdlib.h>
#include <math.h>
#include <SFML/Graphics.h>
#include "utils.h"

sfBool bound_have_pos(sfIntRect const boundary, sfVector2f const pos)
{
    return (pos.x >= boundary.left &&
            pos.x < boundary.left + boundary.width &&
            pos.y >= boundary.top &&
            pos.y < boundary.top + boundary.height
    );
}

sfBool bound_over(sfIntRect const boundary, sfIntRect const other)
{
    return !(
        other.left > boundary.left + boundary.width ||
        other.left + other.width < boundary.left ||
        other.top > boundary.top + boundary.height ||
        other.top + other.height < boundary.top
    );
}

sfBool bound_in_cir(sfFloatRect const frect, sfVector2f circle_center,
    unsigned int circle_radius)
{
    sfVector2f *frect_corners = get_corners(frect);
    sfBool in_circle = sfFalse;

    for (unsigned int i = 0; i < 4 && !in_circle; i++)
        if (point_in_cir(frect_corners[i], circle_center, circle_radius))
            in_circle = sfTrue;
    free(frect_corners);
    return (in_circle);
}

sfBool point_in_cir(sfVector2f point, sfVector2f circle_center,
    unsigned int circle_radius)
{
    float x = point.x - circle_center.x;
    float y = point.y - circle_center.y;

    return (pow(x, 2) + pow(y, 2) <= pow(circle_radius, 2));
}
