/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** buttons_effects
*/

#include "paint.h"

static void apply_not_hover_button_bis(Buttons *currentItem,
    sfFloatRect rect, sfVector2f mousePosition)
{
    if (!sfFloatRect_contains(&rect, mousePosition.x, mousePosition.y))
        sfRectangleShape_setFillColor(currentItem->rect,
            sfColor_fromRGB(220, 220, 220));
}

void apply_not_hover_button(Paint *paint)
{
    Buttons *currentItem = paint->Buttons;
    sfFloatRect rect;
    sfVector2f mousePosition;

    mousePosition = (sfVector2f){paint->event.mouseMove.x,
        paint->event.mouseMove.y};
    while (currentItem != NULL) {
        if (currentItem->rect != NULL) {
            rect = sfRectangleShape_getGlobalBounds(currentItem->rect);
            apply_not_hover_button_bis(currentItem, rect, mousePosition);
        }
        currentItem = currentItem->next;
    }
}

static void apply_hover_button_bis(Buttons *currentItem,
    sfFloatRect rect, sfVector2f mousePosition)
{
    if (sfFloatRect_contains(&rect, mousePosition.x, mousePosition.y))
        sfRectangleShape_setFillColor(currentItem->rect,
            sfColor_fromRGB(200, 200, 200));
    else
        sfRectangleShape_setFillColor(currentItem->rect,
            sfColor_fromRGB(220, 220, 220));
}

void apply_hover_button(Paint *paint)
{
    Buttons *currentItem = paint->Buttons;
    sfFloatRect rect;
    sfVector2f mousePosition;

    mousePosition = (sfVector2f){paint->event.mouseMove.x,
        paint->event.mouseMove.y};
    while (currentItem != NULL) {
        if (currentItem->rect != NULL) {
            rect = sfRectangleShape_getGlobalBounds(currentItem->rect);
            apply_hover_button_bis(currentItem, rect, mousePosition);
        }
        currentItem = currentItem->next;
    }
}

static void updatebutton(Paint *paint)
{
    paint->Mode = MODE_NONE;
    for (Buttons *btn = paint->Buttons; btn != NULL; btn = btn->next) {
        if (btn->is_active) {
            mode_tools(paint, btn);
            break;
        }
    }
}

static void check_active_button_bis(Paint *paint, Buttons *clickedButton)
{
    for (Buttons *otherButton = paint->Buttons; otherButton != NULL;
        otherButton = otherButton->next) {
        if (otherButton != clickedButton && otherButton->rect != NULL) {
            otherButton->is_active = sfFalse;
            sfRectangleShape_setFillColor(otherButton->rect,
                sfColor_fromRGB(220, 220, 220));
        }
    }
}

static void apply_click_button_bis(Paint *paint, Buttons *clickedButton,
    sfFloatRect rect, sfVector2f click)
{
    sfColor color;

    if (sfFloatRect_contains(&rect, click.x, click.y)) {
        clickedButton->is_active = !clickedButton->is_active;
        color = clickedButton->is_active ?
            sfColor_fromRGB(160, 160, 160) : sfColor_fromRGB(220, 220, 220);
        sfRectangleShape_setFillColor(clickedButton->rect, color);
        call_action_button(clickedButton->name, paint);
        check_active_button_bis(paint, clickedButton);
    }
    updatebutton(paint);
}

void apply_click_button(Paint *paint)
{
    Buttons *currentItem = paint->Buttons;
    sfFloatRect rect;
    sfVector2f click;

    while (currentItem != NULL) {
        if (currentItem->rect != NULL) {
            rect = sfRectangleShape_getGlobalBounds(currentItem->rect);
            click = (sfVector2f){paint->event.mouseButton.x,
                paint->event.mouseButton.y};
            apply_click_button_bis(paint, currentItem, rect, click);
        }
        currentItem = currentItem->next;
    }
}

static void apply_release_button_bis(Buttons *currentItem,
    sfFloatRect rect, sfVector2f click)
{
    if (sfFloatRect_contains(&rect, click.x, click.y))
        sfRectangleShape_setFillColor(currentItem->rect,
            sfColor_fromRGB(200, 200, 200));
}

void apply_release_button(Paint *paint)
{
    Buttons *currentItem = paint->Buttons;
    sfFloatRect rect;
    sfVector2f click;

    while (currentItem != NULL) {
        if (currentItem->rect != NULL) {
            rect = sfRectangleShape_getGlobalBounds(currentItem->rect);
            click = (sfVector2f){paint->event.mouseButton.x,
                paint->event.mouseButton.y};
            apply_release_button_bis(currentItem, rect, click);
        }
        currentItem = currentItem->next;
    }
}
