/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** buttons_handling
*/


#include "paint.h"

static sfBool is_release_button_bis(Buttons *currentItem, sfFloatRect rect,
    sfVector2f click, Paint *mypaint)
{
    if (currentItem->rect != NULL) {
        rect = sfRectangleShape_getGlobalBounds(currentItem->rect);
        click = (sfVector2f){mypaint->event.mouseButton.x,
            mypaint->event.mouseButton.y};
        if (sfFloatRect_contains(&rect, click.x, click.y))
            return sfTrue;
    }
    return sfFalse;
}

sfBool is_release_button(void *paint)
{
    Paint *mypaint = (Paint *)paint;
    Buttons *currentItem = mypaint->Buttons;
    sfFloatRect rect;
    sfVector2f click;

    while (currentItem != NULL) {
        if (is_release_button_bis(currentItem, rect, click, mypaint))
            return sfTrue;
        currentItem = currentItem->next;
    }
    return sfFalse;
}

static sfBool is_hover_button_bis(Buttons *currentItem, sfFloatRect rect,
    sfVector2f mousePosition)
{
    if (currentItem->rect != NULL) {
        rect = sfRectangleShape_getGlobalBounds(currentItem->rect);
        if (sfFloatRect_contains(&rect, mousePosition.x, mousePosition.y))
            return sfTrue;
    }
    return sfFalse;
}

sfBool is_hover_button(void *paint)
{
    Paint *mypaint = (Paint *)paint;
    Buttons *currentItem = mypaint->Buttons;
    sfFloatRect rect;
    sfVector2f mousePosition;

    mousePosition = (sfVector2f){mypaint->event.mouseMove.x,
        mypaint->event.mouseMove.y};
    while (currentItem != NULL) {
        if (is_hover_button_bis(currentItem, rect, mousePosition))
            return sfTrue;
        currentItem = currentItem->next;
    }
    return sfFalse;
}

static sfBool is_clicked_button_bis(Buttons *currentItem, sfFloatRect rect,
    sfVector2f click, Paint *mypaint)
{
    if (currentItem->rect != NULL) {
        rect = sfRectangleShape_getGlobalBounds(currentItem->rect);
        click = (sfVector2f){mypaint->event.mouseButton.x,
            mypaint->event.mouseButton.y};
        if (sfFloatRect_contains(&rect, click.x, click.y))
            return sfTrue;
    }
    return sfFalse;
}

sfBool is_clicked_button(void *paint)
{
    Paint *mypaint = (Paint *)paint;
    Buttons *currentItem = mypaint->Buttons;
    sfFloatRect rect;
    sfVector2f click;

    while (currentItem != NULL) {
        if (is_clicked_button_bis(currentItem, rect, click, mypaint))
            return sfTrue;
        currentItem = currentItem->next;
    }
    return sfFalse;
}

static sfBool is_not_hover_button_bis(Buttons *currentItem, sfFloatRect rect,
    sfVector2f mousePosition)
{
    if (currentItem->rect != NULL) {
        rect = sfRectangleShape_getGlobalBounds(currentItem->rect);
        if (!sfFloatRect_contains(&rect, mousePosition.x, mousePosition.y))
            return sfTrue;
    }
    return sfFalse;
}

sfBool is_not_hover_button(void *paint)
{
    Paint *mypaint = (Paint *)paint;
    Buttons *currentItem = mypaint->Buttons;
    sfFloatRect rect;
    sfVector2f mousePosition;

    mousePosition = (sfVector2f){mypaint->event.mouseMove.x,
        mypaint->event.mouseMove.y};
    while (currentItem != NULL) {
        if (is_not_hover_button_bis(currentItem, rect, mousePosition))
            return sfTrue;
        currentItem = currentItem->next;
    }
    return sfFalse;
}
