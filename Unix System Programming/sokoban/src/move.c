/*
** EPITECH PROJECT, 2024
** my_sokoban
** File description:
** move_player.c
*/

#include "../include/my.h"
#include "../include/sokoban.h"
#include "../include/structure.h"

static int check_up(sokoban_struct *sokoban)
{
    if (sokoban->map[sokoban->player->player_x - 1][sokoban->player->player_y]
        == '#')
        return 1;
    if (sokoban->map[sokoban->player->player_x - 1][sokoban->player->player_y]
        == 'X' &&
    sokoban->map[sokoban->player->player_x - 2][sokoban->player->player_y]
        == '#')
        return 1;
    if (sokoban->map[sokoban->player->player_x - 1][sokoban->player->player_y]
        == 'X' && sokoban->map[sokoban->player->player_x- 2]
        [sokoban->player->player_y] == 'X')
        return 1;
    return 0;
}

void move_up(sokoban_struct *sokoban)
{
    if (check_up(sokoban) == 1)
        return;
    box_up(sokoban);
    display_map(sokoban);
}

static int check_down(sokoban_struct *sokoban)
{
    if (sokoban->map[sokoban->player->player_x + 1][sokoban->player->player_y]
        == '#')
        return 1;
    if (sokoban->map[sokoban->player->player_x + 1][sokoban->player->player_y]
        == 'X' &&
    sokoban->map[sokoban->player->player_x + 2][sokoban->player->player_y]
        == '#')
        return 1;
    if (sokoban->map[sokoban->player->player_x + 1][sokoban->player->player_y]
        == 'X' && sokoban->map[sokoban->player->player_x+ 2]
        [sokoban->player->player_y] == 'X')
        return 1;
    return 0;
}

void move_down(sokoban_struct *sokoban)
{
    if (check_down(sokoban) == 1)
        return;
    box_down(sokoban);
    display_map(sokoban);
}

static int check_left(sokoban_struct *sokoban)
{
    if (sokoban->map[sokoban->player->player_x][sokoban->player->player_y - 1]
        == '#')
        return 1;
    if (sokoban->map[sokoban->player->player_x][sokoban->player->player_y - 1]
        == 'X' &&
    sokoban->map[sokoban->player->player_x][sokoban->player->player_y - 2]
        == '#')
        return 1;
    if (sokoban->map[sokoban->player->player_x][sokoban->player->player_y - 1]
        == 'X' && sokoban->map[sokoban->player->player_x]
        [sokoban->player->player_y - 2] == 'X')
        return 1;
    return 0;
}

void move_left(sokoban_struct *sokoban)
{
    if (check_left(sokoban) == 1)
        return;
    box_left(sokoban);
    display_map(sokoban);
}

static int check_right(sokoban_struct *sokoban)
{
    if (sokoban->map[sokoban->player->player_x][sokoban->player->player_y + 1]
        == '#')
        return 1;
    if (sokoban->map[sokoban->player->player_x][sokoban->player->player_y + 1]
        == 'X' &&
    sokoban->map[sokoban->player->player_x][sokoban->player->player_y + 2]
        == '#')
        return 1;
    if (sokoban->map[sokoban->player->player_x][sokoban->player->player_y + 1]
        == 'X' && sokoban->map[sokoban->player->player_x]
        [sokoban->player->player_y + 2] == 'X')
        return 1;
    return 0;
}

void move_right(sokoban_struct *sokoban)
{
    if (check_right(sokoban) == 1)
        return;
    box_right(sokoban);
    display_map(sokoban);
}
