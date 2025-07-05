/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** init_window.c
*/

#include "paint.h"

void init_window(Paint *paint)
{
    sfVideoMode mode = {1920, 1080, 32};

    paint->window = sfRenderWindow_create(WIN(mode));
}

void draw_window(Paint *paint)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f pos = {0, 0};
    sfVector2f size = {1920, 1080};

    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, sfColor_fromRGB(169, 169, 169));
    sfRenderWindow_drawRectangleShape(paint->window, rect, NULL);
}

void draw_decoration(Paint *paint)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f pos = {0, 0};
    sfVector2f size = {1920, 100};

    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, sfColor_fromRGB(100, 100, 100));
    sfRenderWindow_drawRectangleShape(paint->window, rect, NULL);
}

void draw_shadow(Paint *paint)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f pos = {595, 275};
    sfVector2f size = {750, 750};

    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, sfColor_fromRGB(100, 100, 100));
    sfRenderWindow_drawRectangleShape(paint->window, rect, NULL);
}

void init_drawing_area(Paint *paint)
{
    AREA->image = sfImage_create(750, 750);
    AREA->texture = sfTexture_create(750, 750);
    AREA->sprite = sfSprite_create();
    for (int i = 0; i < 750; i++)
        for (int j = 0; j < 750; j++)
            sfImage_setPixel(AREA->image, i, j,
                sfColor_fromRGB(255, 255, 255));
    sfSprite_setTexture(AREA->sprite, AREA->texture, sfTrue);
    sfSprite_setPosition(AREA->sprite, (sfVector2f){585, 265});
}
