/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** my_rpg.h
*/

#pragma once
#include "lib.h"
#include "struct/struct.h"
#include "define.h"

// C
#include <stddef.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/// --- INIT --- ///
void init_struct(rpg_t *game);
void init_game(rpg_t *game);
//window.c
void init_window(windows_t *window);
// create_clock.c
clock_data_t *create_clock(void);
//player.c
void init_player(player_t *player);
void move_player_sprite(enum player_move move, player_sprites_t *sprite,
    player_t *player);
void move_sprite(player_sprites_t *sprite, int height, int width, int skip_md);
//map.c
void init_map(map_t *map, rpg_t *game);
//menu.c
void init_menu(menu_t *menu);

/// --- LOOP --- ///
void game_loop(rpg_t *game);

/// --- DESTROY --- ///
// destroy.c
void destroy(rpg_t *game);
// destroy_map.c
void destroy_map(map_t *map);
// destroy_player.c
void destroy_player(player_t *player);
// destroy_menu.c
void destroy_menu(menu_t *menu);
void destroy_loading_screen(loading_menu_t *loading_menu);
// destroy_loading.c
void destroy_loading_screen(loading_menu_t *loading_menu);

/// --- DISPLAY --- ///
void manager_display(rpg_t *game);
// player.c
void display_player(rpg_t *game, player_sprites_t *sprite);

/// --- EVENT --- ///
// manager.c
void manager_event(rpg_t *game);
// loading_screen.c
void loadin_screen(menu_t *menu, rpg_t *game);
void display_loading_screen(menu_t *menu, rpg_t *game);
// update_mouvement_ped.c
void update_position(enum player_move move, rpg_t *game, int speed);

/// --- PARSING --- ///
int **open_coll_file_as_ints(char *filepath);
void init_parsing(parsing_t *parsing);
int manage_collisions(parsing_t *parsing, rpg_t *game);
