/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** about_action.c
*/

#include "paint.h"

static void init_about(sfText *text, sfFont *font, sfRenderWindow *window)
{
    char str[256] = "MyPaint\n\nA simple paint program\n\nCreated";

    strcat(str, " by Vincent Bichat\nand Axel Pereto\n\n2024");
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, (sfVector2f){50, 50});
    sfText_setColor(text, sfWhite);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 1);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_display(window);
}

static void about_action_bis(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void about_action(void)
{
    sfText *text =
        sfText_create();
    sfFont *font =
        sfFont_createFromFile("assets/fonts/Oswald-VariableFont_wght.ttf");
    sfRenderWindow *window =
        sfRenderWindow_create((sfVideoMode){500, 500, 32},
        "About", sfClose, NULL);
    sfEvent event;

    init_about(text, font, window);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            about_action_bis(window, event);
    }
    sfText_destroy(text);
    sfFont_destroy(font);
    sfRenderWindow_destroy(window);
}
