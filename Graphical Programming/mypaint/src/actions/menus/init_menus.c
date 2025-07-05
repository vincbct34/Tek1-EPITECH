/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** init_menus.c
*/

#include "paint.h"

void draw_menus(Paint *paint)
{
    Menus *tmp = MENU;

    while (tmp != NULL) {
        if (tmp->rect && tmp->name)
            sfRenderWindow_drawRectangleShape(paint->window, tmp->rect, NULL);
        if (tmp->text)
            sfRenderWindow_drawText(paint->window, tmp->text, NULL);
        tmp = tmp->next;
    }
}

static void add_menu_to_list(Menus **list, Menus *menu)
{
    Menus *tmp = *list;

    if (*list == NULL) {
        *list = menu;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = menu;
}

void set_menu_position(Menus *menu)
{
    sfFloatRect textRect;
    sfVector2f origin;
    sfVector2f textPos;

    sfRectangleShape_setPosition(menu->rect, menu->pos);
    sfRectangleShape_setSize(menu->rect, menu->size);
    sfRectangleShape_setFillColor(menu->rect, menu->color);
    sfText_setString(menu->text, menu->name);
    sfText_setFont(menu->text, menu->font);
    sfText_setCharacterSize(menu->text, 30);
    textRect = sfText_getLocalBounds(menu->text);
    origin = (sfVector2f){textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f};
    sfText_setOrigin(menu->text, origin);
    textPos = (sfVector2f){menu->pos.x + 50, menu->pos.y + 25};
    sfText_setPosition(menu->text, textPos);
    sfText_setColor(menu->text, sfWhite);
    sfText_setOutlineColor(menu->text, sfBlack);
    sfText_setOutlineThickness(menu->text, 1);
}

void add_menu(Paint *paint, char *name, sfVector2f pos)
{
    Menus *menu = malloc(sizeof(Menus));

    menu->name = my_strdup(name);
    menu->pos = pos;
    menu->size = (sfVector2f){100, 50};
    menu->color = sfColor_fromRGB(220, 220, 220);
    menu->rect = sfRectangleShape_create();
    menu->text = sfText_create();
    menu->font = paint->font;
    set_menu_position(menu);
    menu->next = NULL;
    add_menu_to_list(&MENU, menu);
}

void init_drop_down(Paint *paint)
{
    MENU->tmp_pos = (sfVector2f){785, 50};
    add_drop_down(MENU, "New");
    MENU->tmp_pos = (sfVector2f){785, 100};
    add_drop_down(MENU, "Open");
    MENU->tmp_pos = (sfVector2f){785, 150};
    add_drop_down(MENU, "Save");
    MENU->tmp_pos = (sfVector2f){910, 50};
    add_drop_down(MENU, "Undo");
    MENU->tmp_pos = (sfVector2f){1035, 50};
    add_drop_down(MENU, "About");
    MENU->tmp_pos = (sfVector2f){1035, 100};
    add_drop_down(MENU, "Help");
}

void init_menus(Paint *paint)
{
    add_menu(paint, "File", (sfVector2f){785, 0});
    add_menu(paint, "Edit", (sfVector2f){910, 0});
    add_menu(paint, "Help", (sfVector2f){1035, 0});
    init_drop_down(paint);
}
