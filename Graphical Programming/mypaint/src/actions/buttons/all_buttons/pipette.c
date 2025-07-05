/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** pipette
*/

#include "paint.h"

sfColor get_pixel_color_from_sfimage(sfImage *image, sfVector2f pos)
{
    sfColor color = sfImage_getPixel(image, pos.x, pos.y);

    return (color);
}

sfBool pipette_action(void *mypaint)
{
    Paint *paint = (Paint *)mypaint;

    paint->Mode = MODE_PIPETTE;
    return (sfTrue);
}
