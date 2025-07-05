/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "window.h"

win_t *create_win(unsigned int width, unsigned int height,
    char const *win_title)
{
    win_t *window = malloc(sizeof(*window));
    sfVideoMode mode = {width, height, W_BPP};

    if (!window)
        return (NULL);
    window->render = sfRenderWindow_create(mode, win_title,
                                        sfClose | sfFullscreen, NULL);
    window->width = width;
    window->height = height;
    window->background = NULL;
    sfRenderWindow_setFramerateLimit(window->render, W_MAX_FPS);
    return (window);
}

void destroy_win(win_t *window)
{
    sfRenderWindow_destroy(window->render);
    if (window->background)
        sfSprite_destroy(window->background);
    if (window)
        free(window);
}

void set_win_back(win_t *window, sfTexture *texture)
{
    if (!(window->background))
        window->background = sfSprite_create();
    sfSprite_setTexture(window->background, texture, sfTrue);
}
