/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** actions_buttons
*/

#include "paint.h"

void call_action_button(char *name, Paint *paint)
{
    if (my_strcmp(name, "plus") == 0) {
        paint->Mouse->thickness += 1;
    }
    if (my_strcmp(name, "moins") == 0) {
        paint->Mouse->thickness -= 1;
    }
    if (my_strcmp(name, "pencil") == 0) {
        paint->Mode = MODE_PENCIL;
    }
    if (my_strcmp(name, "eraser") == 0) {
        paint->Mode = MODE_ERASER;
    }
}

void apply_button_actions_bis(Buttons *currentItem, sfFloatRect rect,
    sfVector2f click, Paint *paint)
{
    if (currentItem->rect != NULL) {
        rect = sfRectangleShape_getGlobalBounds(currentItem->rect);
        click = (sfVector2f){paint->event.mouseButton.x,
            paint->event.mouseButton.y};
        if (sfFloatRect_contains(&rect, click.x, click.y))
            call_action_button(currentItem->name, paint);
    }
}

void apply_button_actions(Paint *paint)
{
    Buttons *currentItem = paint->Buttons;
    sfFloatRect rect;
    sfVector2f click;

    while (currentItem != NULL) {
        apply_button_actions_bis(currentItem, rect, click, paint);
        currentItem = currentItem->next;
    }
}
