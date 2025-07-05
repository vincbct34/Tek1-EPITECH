/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** help_action.c
*/

#include "paint.h"

static char *init_help_bis(void)
{
    char *str = "Need Help ?\n\n"
                "Our Paint is simple, you can write with"
                " the \"Pencil\" Button,"
                " erase with the \"Rubber\" one, and you also"
                " have two buttons"
                " to change the size of the cursor to draw / erase.\n\n"
                "You can \"Undo\" your actions, you can save your work,"
                " open a new one or even open an existing one.\n\n"
                "With this menu, you also have the \"About\" section,"
                " which you can find the name of the creators, both"
                " of us.\n\n"
                "To add, a button, I will take the menus for example,"
                " you can just call the"
                " function \"add_menu\", set the parameters correctly,"
                " and then,"
                " add as many sub-buttons as you want,"
                " with \"add_drop_down\".\n\n"
                "Enjoy our application !";

    return (str);
}

static void init_help(sfText *text, sfFont *font, sfRenderWindow *window)
{
    sfVector2f position = {(125), (400)};
    char *str = init_help_bis();

    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 24);
    sfText_setColor(text, sfWhite);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 3);
    sfText_setPosition(text, position);
    sfRenderWindow_clear(window, sfColor_fromRGB(220, 220, 220));
    sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_display(window);
}

static void help_action_bis(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void help_action(void)
{
    sfText *text =
        sfText_create();
    sfFont *font =
        sfFont_createFromFile("assets/fonts/Oswald-VariableFont_wght.ttf");
    sfRenderWindow *window =
        sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
        "Help", sfClose, NULL);
    sfEvent event;

    init_help(text, font, window);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            help_action_bis(window, event);
    }
    sfText_destroy(text);
    sfFont_destroy(font);
    sfRenderWindow_destroy(window);
}
