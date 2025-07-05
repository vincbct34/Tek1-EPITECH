/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** structure
*/

#pragma once

#include "csfml_lib.h"
#include "utils.h"
#include "player.h"
#include "map.h"
#include "menu.h"
#include <stdbool.h>

/*
Structure of the window
*/
typedef struct windows_s {
    sfRenderWindow* window;
    clock_data_t *clock;
    sfTime time;
    sfEvent event;
} windows_t;

/*
Principal structure of the game
*/
typedef struct s_rpg {
    windows_t *window_data;
    player_t *player;
    map_t *map;
    bool in_game;
    menu_t *menu;
} rpg_t;
