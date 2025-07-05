/*
** EPITECH PROJECT, 2023
** structure.h
** File description:
** Structures for My_Hunter
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Event.h>
#include <stdio.h>
#include <SFML/Audio.h>
#pragma once

typedef struct parameter {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
} parameter_t;

typedef struct theme {
    sfMusic *theme;
    sfMusic *backmusic;
    sfMusic *trollmusic;
    sfMusic *shootmusic;
} theme_t;

typedef struct sprite {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f scale;
    sfVector2f size;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    float seconds;
} sprite_t;

typedef struct mouse {
    sfVector2i position;
    int cursor_x;
    int cursor_y;
    sfVector2f sprite;
} mouse_t;

typedef struct global {
    parameter_t parameters;
    theme_t music;
    sprite_t *images;
    mouse_t mouse;
    int status;
    int count;
    int life;
} global_t;
