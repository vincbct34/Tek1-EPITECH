/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** add_menus.c
*/

#include "paint.h"

void draw_drop_down(sfRenderWindow *window, Drop_down *drop_down)
{
    while (drop_down != NULL) {
        sfRenderWindow_drawRectangleShape(window, drop_down->rect, NULL);
        sfRenderWindow_drawText(window, drop_down->text, NULL);
        drop_down = drop_down->next;
    }
}

void set_drop_down_position(Menus *menu, Drop_down *drop_down)
{
    sfFloatRect textRect;
    sfVector2f origin;
    sfVector2f textPos;

    sfRectangleShape_setPosition(drop_down->rect, menu->tmp_pos);
    sfRectangleShape_setSize(drop_down->rect, drop_down->size);
    sfRectangleShape_setFillColor(drop_down->rect, drop_down->color);
    sfText_setString(drop_down->text, drop_down->name);
    sfText_setFont(drop_down->text, menu->font);
    sfText_setCharacterSize(drop_down->text, 30);
    textRect = sfText_getLocalBounds(drop_down->text);
    origin = (sfVector2f){textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f};
    sfText_setOrigin(drop_down->text, origin);
    textPos = (sfVector2f){menu->tmp_pos.x + 50, menu->tmp_pos.y + 25};
    sfText_setPosition(drop_down->text, textPos);
    sfText_setColor(drop_down->text, sfWhite);
    sfText_setOutlineColor(drop_down->text, sfBlack);
    sfText_setOutlineThickness(drop_down->text, 1);
}

void add_drop_down(Menus *menu, char *subutton)
{
    Drop_down *drop_down_list = malloc(sizeof(Drop_down));

    if (drop_down_list == NULL)
        return;
    drop_down_list->name = subutton;
    drop_down_list->size = (sfVector2f){100, 50};
    drop_down_list->color = sfColor_fromRGB(220, 220, 220);
    drop_down_list->rect = sfRectangleShape_create();
    drop_down_list->text = sfText_create();
    set_drop_down_position(menu, drop_down_list);
    drop_down_list->next = menu->drop_down;
    menu->drop_down = drop_down_list;
}
