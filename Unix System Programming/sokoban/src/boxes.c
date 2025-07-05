/*
** EPITECH PROJECT, 2024
** my_sokoban
** File description:
** boxes.c
*/

#include "../include/my.h"
#include "../include/sokoban.h"
#include "../include/structure.h"

void box_up(sokoban_struct *sokoban)
{
    int player_x = sokoban->player->player_x;
    int player_y = sokoban->player->player_y;

    if (sokoban->map[player_x - 1][player_y] == 'X')
        sokoban->map[player_x - 2][player_y] = 'X';
    sokoban->map[player_x - 1][player_y] = 'P';
    sokoban->map[player_x][player_y] = ' ';
    sokoban->player->player_x -= 1;
    for (object *box = sokoban->object; box != NULL; box = box->next) {
        if (box->box_x == player_x - 1 && box->box_y == player_y) {
            box->box_x -= 1;
            break;
        }
    }
}

void box_down(sokoban_struct *sokoban)
{
    int player_x = sokoban->player->player_x;
    int player_y = sokoban->player->player_y;

    if (sokoban->map[player_x + 1][player_y] == 'X')
        sokoban->map[player_x + 2][player_y] = 'X';
    sokoban->map[player_x + 1][player_y] = 'P';
    sokoban->map[player_x][player_y] = ' ';
    sokoban->player->player_x += 1;
    for (object *box = sokoban->object; box != NULL; box = box->next) {
        if (box->box_x == player_x + 1 && box->box_y == player_y) {
            box->box_x += 1;
            break;
        }
    }
}

void box_left(sokoban_struct *sokoban)
{
    int player_x = sokoban->player->player_x;
    int player_y = sokoban->player->player_y;

    if (sokoban->map[player_x][player_y - 1] == 'X')
        sokoban->map[player_x][player_y - 2] = 'X';
    sokoban->map[player_x][player_y - 1] = 'P';
    sokoban->map[player_x][player_y] = ' ';
    sokoban->player->player_y -= 1;
    for (object *box = sokoban->object; box != NULL; box = box->next) {
        if (box->box_x == player_x && box->box_y == player_y - 1) {
            box->box_y -= 1;
            break;
        }
    }
}

void box_right(sokoban_struct *sokoban)
{
    int player_x = sokoban->player->player_x;
    int player_y = sokoban->player->player_y;

    if (sokoban->map[player_x][player_y + 1] == 'X')
        sokoban->map[player_x][player_y + 2] = 'X';
    sokoban->map[player_x][player_y + 1] = 'P';
    sokoban->map[player_x][player_y] = ' ';
    sokoban->player->player_y += 1;
    for (object *box = sokoban->object; box != NULL; box = box->next) {
        if (box->box_x == player_x && box->box_y == player_y + 1) {
            box->box_y += 1;
            break;
        }
    }
}
