/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** manager
*/

#include "my_rpg.h"

void manage_display_player(rpg_t *game)
{
    if (game->player->type == KN_SH_1)
        display_player(game, game->player->kn_sh_1__sprite);
    if (game->player->type == KN_SH_2)
        display_player(game, game->player->kn_sh_2__sprite);
    if (game->player->type == KN_SH_3)
        display_player(game, game->player->kn_sh_3__sprite);
    if (game->player->type == KN_BTT)
        display_player(game, game->player->kn_btt_sprite);
}

void set_view_center(sfView *view, map_info_t *map_info)
{
    if (map_info->view_x - map_info->window_size.x / 2 < 25)
        map_info->view_x = 25 + map_info->window_size.x / 2;
    if (map_info->view_x + map_info->window_size.x / 2 > map_info->map_width)
        map_info->view_x = map_info->map_width - map_info->window_size.x / 2;
    if (map_info->view_y - map_info->window_size.y / 2 < 0)
        map_info->view_y = map_info->window_size.y / 2;
    if (map_info->view_y + map_info->window_size.y / 2 > map_info->map_height)
        map_info->view_y = map_info->map_height - map_info->window_size.y / 2;
    sfView_setCenter(view, (sfVector2f){map_info->view_x, map_info->view_y});
}

static bool is_chunk_within_bounds(int chunk_x, int chunk_y)
{
    return (chunk_x >= 0 && chunk_x < 6 && chunk_y >= 0 && chunk_y < 6);
}

static void draw_chunk(sfRenderWindow *window, map_sprites_t *map_sprite,
    int chunk_index)
{
    sfRenderWindow_drawSprite(window, map_sprite->chunk[chunk_index], NULL);
}

static void process_chunk(sfRenderWindow *window, map_sprites_t *map_sprite,
    int chunk_x, int chunk_y)
{
    int chunk_index;

    if (is_chunk_within_bounds(chunk_x, chunk_y)) {
        chunk_index = chunk_y * 6 + chunk_x;
        draw_chunk(window, map_sprite, chunk_index);
    }
}

static void process_sprite_chunks(sfRenderWindow *window,
    map_sprites_t *map_sprite, map_info_t *map_info)
{
    int chunk_x_to_display;
    int chunk_y_to_display;

    for (int y_offset = -map_info->chunks_to_display; y_offset
        <= map_info->chunks_to_display; y_offset++) {
        for (int x_offset = -map_info->chunks_to_display; x_offset
            <= map_info->chunks_to_display; x_offset++) {
            chunk_x_to_display = map_info->chunk_x + x_offset;
            chunk_y_to_display = map_info->chunk_y + y_offset;
            process_chunk(window, map_sprite, chunk_x_to_display,
                chunk_y_to_display);
        }
    }
}

static void draw_visible_chunks(rpg_t *game, map_t *map, map_info_t *map_info)
{
    map_sprites_t *map_sprite;

    for (int i = 0; i < 13; i++) {
        map_sprite = map->map_sprites[i];
        process_sprite_chunks(game->window_data->window,
            map_sprite, map_info);
        if (i == 9)
            manage_display_player(game);
    }
}

void manage_display_map(rpg_t *game, map_t *map)
{
    map_info_t *map_info = malloc(sizeof(map_info_t));
    sfVector2f player_pos = game->player->pos;

    map_info->chunk_x = (int)((player_pos.x + 25) / 1604);
    map_info->chunk_y = (int)(player_pos.y / 1604);
    map_info->chunks_to_display = 2;
    map_info->window_size = sfRenderWindow_getSize(game->window_data->window);
    map_info->view = sfView_create();
    map_info->map_width = 9624;
    map_info->map_height = 9624;
    map_info->view_x = player_pos.x + 25;
    map_info->view_y = player_pos.y;
    sfView_setSize(map_info->view, (sfVector2f){(float)map_info->window_size.x,
        (float)map_info->window_size.y});
    set_view_center(map_info->view, map_info);
    sfRenderWindow_setView(game->window_data->window, map_info->view);
    draw_visible_chunks(game, map, map_info);
    sfView_destroy(map_info->view);
    free(map_info);
}

void display_menu(rpg_t *game, menu_t *menu)
{
    sfRenderWindow_drawSprite(game->window_data->window,
        menu->main_menu->background, NULL);
    sfRenderWindow_drawSprite(game->window_data->window,
        menu->main_menu->spt_mid_button[0], NULL);
    sfRenderWindow_drawSprite(game->window_data->window,
        menu->main_menu->spt_mid_button[1], NULL);
    sfRenderWindow_drawText(game->window_data->window,
        menu->main_menu->txt_title, NULL);
    sfRenderWindow_drawText(game->window_data->window,
        menu->main_menu->txt_mid_button[0], NULL);
    sfRenderWindow_drawText(game->window_data->window,
        menu->main_menu->txt_mid_button[1], NULL);
}

void manager_display(rpg_t *game)
{
    if (!game->in_game) {
        display_menu(game, game->menu);
        return;
    }
    manage_display_map(game, game->map);
}
