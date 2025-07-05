/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** menus'_effects.c
*/

#include "paint.h"

static void apply_not_hover_menu_bis(Menus *currentItem,
    sfFloatRect rect, sfVector2f mousePosition)
{
    if (!sfFloatRect_contains(&rect, mousePosition.x, mousePosition.y))
        sfRectangleShape_setFillColor(currentItem->rect,
            sfColor_fromRGB(220, 220, 220));
}

void apply_not_hover_menu(Paint *paint)
{
    Menus *currentItem = paint->Menus;
    sfFloatRect rect;
    sfVector2f mousePosition;

    mousePosition = (sfVector2f){paint->event.mouseMove.x,
        paint->event.mouseMove.y};
    while (currentItem != NULL) {
        if (currentItem->rect != NULL) {
            rect = sfRectangleShape_getGlobalBounds(currentItem->rect);
            apply_not_hover_menu_bis(currentItem, rect, mousePosition);
        }
        currentItem = currentItem->next;
    }
}

static void apply_hover_menu_bis(Menus *currentItem,
    sfFloatRect rect, sfVector2f mousePosition)
{
    if (sfFloatRect_contains(&rect, mousePosition.x, mousePosition.y))
        sfRectangleShape_setFillColor(currentItem->rect,
            sfColor_fromRGB(200, 200, 200));
    else
        sfRectangleShape_setFillColor(currentItem->rect,
            sfColor_fromRGB(220, 220, 220));
}

void apply_hover_menu(Paint *paint)
{
    Menus *currentItem = paint->Menus;
    sfFloatRect rect;
    sfVector2f mousePosition;

    mousePosition = (sfVector2f){paint->event.mouseMove.x,
        paint->event.mouseMove.y};
    while (currentItem != NULL) {
        if (currentItem->rect != NULL) {
            rect = sfRectangleShape_getGlobalBounds(currentItem->rect);
            apply_hover_menu_bis(currentItem, rect, mousePosition);
        }
        currentItem = currentItem->next;
    }
}

static void apply_click_menu_bis(Paint *paint,
    Menus *currentItem, sfFloatRect rect, sfVector2f click)
{
    if (sfFloatRect_contains(&rect, click.x, click.y)) {
        sfRectangleShape_setFillColor(currentItem->rect,
            sfColor_fromRGB(180, 180, 180));
        MENU->is_open = !MENU->is_open;
    }
}

void apply_click_menu(Paint *paint)
{
    Menus *currentItem = paint->Menus;
    sfFloatRect rect;
    sfVector2f click;

    while (currentItem != NULL) {
        if (currentItem->rect != NULL) {
            rect = sfRectangleShape_getGlobalBounds(currentItem->rect);
            click = (sfVector2f){paint->event.mouseButton.x,
                paint->event.mouseButton.y};
            apply_click_menu_bis(paint, currentItem, rect, click);
        }
        currentItem = currentItem->next;
    }
}

static void apply_release_menu_bis(Menus *currentItem,
    sfFloatRect rect, sfVector2f click)
{
    if (sfFloatRect_contains(&rect, click.x, click.y))
        sfRectangleShape_setFillColor(currentItem->rect,
            sfColor_fromRGB(200, 200, 200));
}

void apply_release_menu(Paint *paint)
{
    Menus *currentItem = paint->Menus;
    sfFloatRect rect;
    sfVector2f click;

    while (currentItem != NULL) {
        if (currentItem->rect != NULL) {
            rect = sfRectangleShape_getGlobalBounds(currentItem->rect);
            click = (sfVector2f){paint->event.mouseButton.x,
                paint->event.mouseButton.y};
            apply_release_menu_bis(currentItem, rect, click);
        }
        currentItem = currentItem->next;
    }
}
