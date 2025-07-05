/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** manager
*/

#include "my_rpg.h"

sfRectangleShape* create_rectangle_shape(sfVector2f size,
    sfVector2f position)
{
    sfRectangleShape* shape = sfRectangleShape_create();

    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setPosition(shape, position);
    return shape;
}

int check_collision(sfFloatRect playerBounds, sfVector2f collPos)
{
    sfRectangleShape* collisionArea =
        create_rectangle_shape((sfVector2f){48.0f, 48.0f}, collPos);
    sfFloatRect collisionBounds =
        sfRectangleShape_getGlobalBounds(collisionArea);
    int result = sfFloatRect_intersects(&playerBounds, &collisionBounds, NULL);

    sfRectangleShape_destroy(collisionArea);
    return result;
}

int is_within_collision_radius(float dx, float dy,
    sfFloatRect playerBounds, sfVector2f collPos)
{
    if (dx <= COLLISION_CHECK_RADIUS && dy <= COLLISION_CHECK_RADIUS)
        return check_collision(playerBounds, collPos);
    return 0;
}

int manage_collisions(parsing_t *parsing, rpg_t *game)
{
    sfRectangleShape* playerPoint =
        create_rectangle_shape((sfVector2f){40, 40},
        (sfVector2f){game->player->pos.x + 13, game->player->pos.y + 30});
    sfFloatRect playerBounds = sfRectangleShape_getGlobalBounds(playerPoint);
    float dx;
    float dy;

    for (int i = 0; parsing->coll_file[i] != NULL; i++) {
        dx = fabs(parsing->coll_file[i][0] - game->player->pos.x);
        dy = fabs(parsing->coll_file[i][1] - game->player->pos.y);
        if (is_within_collision_radius(dx, dy, playerBounds,
            (sfVector2f){parsing->coll_file[i][0],
            parsing->coll_file[i][1]})) {
            return 1;
        }
    }
    return 0;
}

static int set_player_move_direction_bis(rpg_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (sfKeyboard_isKeyPressed(sfKeyRight)) {
            game->player->move = DOWN_RIGHT;
            return 1;
        }
        if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
            game->player->move = DOWN_LEFT;
            return 1;
        }
        game->player->move = DOWN;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        game->player->move = RIGHT;
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        game->player->move = LEFT;
    return 0;
}

static void set_player_move_direction(rpg_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (sfKeyboard_isKeyPressed(sfKeyRight)) {
            game->player->move = UP_RIGHT;
            return;
        }
        if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
            game->player->move = UP_LEFT;
            return;
        }
        game->player->move = UP;
    }
    if (set_player_move_direction_bis(game) == 1)
        return;
}

static void update_player_position_if_needed(rpg_t *game)
{
    if (game->player->move != NONE) {
        update_position(game->player->move, game, game->player->speed);
    }
}

static void manage_mouvement(rpg_t *game)
{
    game->player->move = NONE;
    set_player_move_direction(game);
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        game->player->move += 8;
    update_player_position_if_needed(game);
}

static void manage_click_menu(rpg_t *game)
{
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(game->window_data->window);
    sfFloatRect play_button =
        sfSprite_getGlobalBounds(game->menu->main_menu->spt_mid_button[0]);
    sfFloatRect quit_button =
        sfSprite_getGlobalBounds(game->menu->main_menu->spt_mid_button[1]);

    if (sfFloatRect_contains(&play_button, mouse_pos.x, mouse_pos.y)) {
        game->in_game = true;
        loadin_screen(game->menu, game);
        init_game(game);
        destroy_loading_screen(game->menu->loading_menu);
        destroy_menu(game->menu);
        game->menu = NULL;
    }
    if (sfFloatRect_contains(&quit_button, mouse_pos.x, mouse_pos.y))
        sfRenderWindow_close(game->window_data->window);
}

void manager_event(rpg_t *game)
{
    while (sfRenderWindow_pollEvent(game->window_data->window,
        &game->window_data->event)) {
        if (game->window_data->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window_data->window);
        if (!game->in_game &&
            game->window_data->event.type == sfEvtMouseButtonPressed)
            manage_click_menu(game);
    }
    if (game->in_game) {
        manage_mouvement(game);
    }
}
