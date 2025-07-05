/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** main.c
*/

#include "my_rpg.h"

int main(int, char **)
{
    rpg_t *game = malloc(sizeof(rpg_t));

    init_struct(game);
    game_loop(game);
    destroy(game);
    return 0;
}
