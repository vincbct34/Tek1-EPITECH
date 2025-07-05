/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** main_menu
*/

#pragma once

#include "csfml_lib.h"
#include "utils.h"

typedef struct main_menu_s {
    sfText *txt_title;
    sfTexture *texture;
    sfSprite *spt_mid_button[2];
    sfText *txt_mid_button[2];
    sfFont *font;
    sfTexture *back_texture;
    sfSprite *background;
} main_menu_t;

typedef struct loading_menu_s {
    sfText *txt_title;
    sfText *txt_loading;
    sfRectangleShape *background;
} loading_menu_t;

typedef struct menu_s {
    main_menu_t *main_menu;
    loading_menu_t *loading_menu;
} menu_t;
