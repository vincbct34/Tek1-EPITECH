/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** main.c
*/

#include "paint.h"

static void free_buttons(Buttons *button)
{
    Buttons *tmp;

    while (button != NULL) {
        tmp = button;
        button = button->next;
        sfRectangleShape_destroy(tmp->rect);
        free(tmp->name);
        free(tmp);
    }
}

/*static void free_drop_downs(Drop_down *drop_down)
{
    Drop_down *tmp;

    while (drop_down != NULL) {
        tmp = drop_down;
        drop_down = drop_down->next;
        sfRectangleShape_destroy(tmp->rect);
        sfText_destroy(tmp->text);
        free(tmp->name);
        free(tmp);
    }
}*/
static void free_menus(Menus *menu)
{
    Menus *tmp;

    while (menu != NULL) {
        tmp = menu;
        menu = menu->next;
        sfRectangleShape_destroy(tmp->rect);
        free(tmp->name);
        free(tmp);
    }
}

void free_all(Paint *paint)
{
    if (BUTTON)
        free_buttons(BUTTON);
    if (MENU)
        free_menus(MENU);
    if (paint->font)
        sfFont_destroy(paint->font);
    if (paint->window)
        sfRenderWindow_destroy(paint->window);
    if (AREA->image) {
        sfImage_destroy(AREA->image);
        sfTexture_destroy(AREA->texture);
        sfSprite_destroy(AREA->sprite);
    }
    free(paint);
}

static void malloc_structs(Paint *paint)
{
    MENU = malloc(sizeof(Menus));
    memset(MENU, 0, sizeof(Menus));
    BUTTON = malloc(sizeof(Buttons));
    memset(BUTTON, 0, sizeof(Buttons));
    AREA = malloc(sizeof(Drawing));
    memset(AREA, 0, sizeof(Drawing));
    paint->Mouse = malloc(sizeof(Mouse_t));
}

void init_all(Paint *paint)
{
    paint->font =
        sfFont_createFromFile("assets/fonts/Oswald-VariableFont_wght.ttf");
    MENU->font = paint->font;
    init_window(paint);
    init_drawing_area(paint);
    init_buttons(paint);
    init_menus(paint);
    MENU->is_open = false;
}

static void main_bis(Paint *paint)
{
    sfRenderWindow_clear(paint->window, sfBlack);
    draw_all(paint);
    display_image(paint->window, paint->Area->image);
    if (paint->Mouse->mouse_in_area == true)
        draw_mouse_circle(paint);
    sfRenderWindow_display(paint->window);
}

int main(int ac, char **)
{
    Paint *paint = malloc(sizeof(Paint));

    memset(paint, 0, sizeof(Paint));
    malloc_structs(paint);
    init_all(paint);
    if (ac != 1)
        return (84);
    paint->Mouse->thickness = 5;
    while (sfRenderWindow_isOpen(paint->window)) {
        tools(paint);
        while (sfRenderWindow_pollEvent(paint->window, &paint->event))
            events_handling(paint);
        main_bis(paint);
    }
    free_all(paint);
    return (0);
}
