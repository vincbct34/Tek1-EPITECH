/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** init_button.c
*/

#include "paint.h"

void draw_buttons(Paint *paint)
{
    Buttons *tmp = BUTTON;

    while (tmp != NULL) {
        if (tmp->rect && tmp->name)
            sfRenderWindow_drawRectangleShape(paint->window, tmp->rect, NULL);
        if (tmp->sprite)
            sfRenderWindow_drawSprite(paint->window, tmp->sprite, NULL);
        tmp = tmp->next;
    }
}

void add_button_to_list(Buttons **list, Buttons *button)
{
    Buttons *tmp = *list;

    if (*list == NULL) {
        *list = button;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = button;
}

void set_position(Buttons *button)
{
    sfVector2u size;
    char path[256] = "assets/symbols/";

    my_strcat(path, button->name);
    my_strcat(path, ".png");
    button->texture = sfTexture_createFromFile(path, NULL);
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    size = sfTexture_getSize(button->texture);
    sfSprite_setScale(button->sprite,
        (sfVector2f){100.0 / size.x, 100.0 / size.y});
    sfSprite_setPosition(button->sprite,
        (sfVector2f){button->pos.x, button->pos.y});
    sfRectangleShape_setPosition(button->rect, button->pos);
    sfRectangleShape_setSize(button->rect, button->size);
    sfRectangleShape_setFillColor(button->rect, button->color);
}

void add_button(Paint *paint,
    char *name, sfVector2f pos, sfBool (*action)(void *))
{
    Buttons *button = malloc(sizeof(Buttons));

    button->name = my_strdup(name);
    button->pos = pos;
    button->size = (sfVector2f){100, 100};
    button->color = sfColor_fromRGB(220, 220, 220);
    button->rect = sfRectangleShape_create();
    set_position(button);
    button->action = action;
    button->next = NULL;
    add_button_to_list(&BUTTON, button);
}

void init_buttons(Paint *paint)
{
    add_button(paint, "pencil", (sfVector2f){250, 600}, &pencil_action);
    add_button(paint, "eraser", (sfVector2f){250, 400}, &eraser_action);
    add_button(paint, "moins", (sfVector2f){1600, 600}, NULL);
    add_button(paint, "plus", (sfVector2f){1600, 400}, NULL);
}
