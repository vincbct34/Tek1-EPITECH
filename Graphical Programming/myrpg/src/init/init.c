/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** init
*/

#include "my_rpg.h"

void init_game(rpg_t *game)
{
    game->player = malloc(sizeof(player_t));
    init_player(game->player);
    game->map = malloc(sizeof(map_t));
    init_map(game->map, game);
    game->map->parsing = malloc(sizeof(parsing_t));
    init_parsing(game->map->parsing);
}

void init_struct(rpg_t *game)
{
    game->in_game = false;
    game->window_data = malloc(sizeof(windows_t));
    init_window(game->window_data);
    game->menu = malloc(sizeof(menu_t));
    init_menu(game->menu);
}
