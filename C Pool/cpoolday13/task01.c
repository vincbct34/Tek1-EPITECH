/*
** EPITECH PROJECT, 2023
** Task01
** File description:
** Day 13
*/

#include <SFML/Graphics.h>

void no_lines(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

int main(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    sfEvent event;

    window = sfRenderWindow_create(mode, "my_isneg", sfDefaultStyle, NULL);
    while (sfRenderWindow_isOpen(window)) {
        no_lines(window, event);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_display(window);
    }
    return 0;
}
