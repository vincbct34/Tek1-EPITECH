/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** draw_all.c
*/

#include "paint.h"

void draw_all(Paint *paint)
{
    sfRenderWindow_clear(paint->window, sfColor_fromRGB(169, 169, 169));
    draw_shadow(paint);
    sfRenderWindow_drawSprite(paint->window, AREA->sprite, NULL);
    sfTexture_updateFromImage(AREA->texture, AREA->image, 0, 0);
    draw_buttons(paint);
    draw_decoration(paint);
    draw_menus(paint);
    if (MENU->is_open == true)
        draw_drop_down(paint->window, MENU->drop_down);
    sfRenderWindow_display(paint->window);
}
