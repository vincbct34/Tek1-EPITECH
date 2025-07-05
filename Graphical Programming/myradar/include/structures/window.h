/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Header file for window structure
*/

#pragma once
#include <SFML/Graphics.h>
#define W_WIDTH         1920
#define W_HEIGHT        1080
#define W_BPP           32
#define W_MAX_FPS       60
#define W_TITLE         "my_radar"

typedef struct win {
    sfRenderWindow *render;
    unsigned int width;
    unsigned int height;
    sfSprite *background;
} win_t;

win_t *create_win(unsigned int width, unsigned int height,
    char const *win_title);
void destroy_win(win_t *window);
void set_win_back(win_t *window, sfTexture *texture);
