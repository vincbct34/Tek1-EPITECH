/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-mypaint-vincent.bichat
** File description:
** structure.h
*/

#pragma once

// INCLUDE
// Csfml

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

// Standard

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// ENUM

enum States {
    NONE = 0,
    HOVER,
    CLICKED,
    ACTIVE
};

typedef enum {
    MODE_NONE,
    MODE_PENCIL,
    MODE_ERASER,
    MODE_PIPETTE,
    MODE_COLOR
} DrawingMode;

// STRUCTURES
// Main buttons

typedef struct Buttons_s {
    char *name;
    sfRectangleShape *rect;
    sfVector2f pos;
    sfVector2f size;
    sfColor color;
    sfBool is_active;
    sfTexture *texture;
    sfSprite *sprite;
    sfBool (*action)(void *paint);
    struct Buttons_s *next;
} Buttons;

// Menus

typedef struct Drop_down_s {
    char *name;
    sfRectangleShape *rect;
    sfVector2f pos;
    sfVector2f size;
    sfColor color;
    sfText *text;
    sfFont *font;
    sfBool (*action)(void *paint);
    struct Drop_down_s *next;
} Drop_down;

typedef struct Menus_s {
    char *name;
    sfRectangleShape *rect;
    sfVector2f pos;
    sfVector2f tmp_pos;
    sfVector2f size;
    sfColor color;
    sfText *text;
    sfFont *font;
    sfBool (*is_clicked_menu)(void *paint);
    bool is_open;
    Drop_down *drop_down;
    struct Menus_s *next;
} Menus;

// Drawing area

typedef struct Drawing_s {
    sfImage *image;
    sfTexture *texture;
    sfSprite *sprite;
} Drawing;

typedef struct ImageHistory {
    sfImage *image;
    struct ImageHistory *next;
} ImageHistory;

typedef struct Mouse_s {
    sfVector2f mouse_pos;
    sfBool is_mouse_clicked;
    sfBool mouse_in_area;
    sfColor selected_color;
    int thickness;
    sfBool has_selected_color;
} Mouse_t;

// Main structure

typedef struct Paint_s {
    sfRenderWindow *window;
    sfEvent event;
    sfFont *font;
    Menus *Menus;
    Buttons *Buttons;
    Drawing *Area;
    Mouse_t *Mouse;
    DrawingMode Mode;
    sfCircleShape *cursorCircle;
    ImageHistory *History;
} Paint;

// Needed structures for coding style

typedef struct Draw_context_s {
    int dx;
    int dy;
    int sx;
    int sy;
    int err;
    int e2;
} Draw_context;
