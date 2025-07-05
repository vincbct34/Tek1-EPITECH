/*
** EPITECH PROJECT, 2024
** my_sokoban
** File description:
** positions.c
*/

#include "../include/my.h"
#include "../include/sokoban.h"
#include "../include/structure.h"

static void pos_x_bis(sokoban_struct *sokoban, int i, int j)
{
    object *new = malloc(sizeof(object));
    object *temp;

    new->box_x = i;
    new->box_y = j;
    new->next = NULL;
    if (sokoban->object == NULL)
        sokoban->object = new;
    else {
        temp = sokoban->object;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }
}

void pos_x(sokoban_struct *sokoban, int i, int j)
{
    if (sokoban->map[i][j] == 'X')
        pos_x_bis(sokoban, i, j);
}

static void pos_o_bis(sokoban_struct *sokoban, int i, int j)
{
    storage *new = malloc(sizeof(storage));
    storage *temp;

    new->storage_x = i;
    new->storage_y = j;
    new->next = NULL;
    if (sokoban->storage == NULL)
        sokoban->storage = new;
    else {
        temp = sokoban->storage;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }
}

void pos_o(sokoban_struct *sokoban, int i, int j)
{
    if (sokoban->map[i][j] == 'O')
        pos_o_bis(sokoban, i, j);
}

static void get_pos_bis(sokoban_struct *sokoban, int i, int j)
{
    if (sokoban->map[i][j] == 'P') {
        sokoban->player->player_x = i;
        sokoban->player->player_y = j;
    }
    if (sokoban->map[i][j] == 'X')
        pos_x(sokoban, i, j);
    if (sokoban->map[i][j] == 'O')
        pos_o(sokoban, i, j);
}

void get_pos(sokoban_struct *sokoban)
{
    for (int i = 0; sokoban->map[i] != NULL; i++) {
        for (int j = 0; sokoban->map[i][j] != '\0'; j++)
            get_pos_bis(sokoban, i, j);
    }
}
