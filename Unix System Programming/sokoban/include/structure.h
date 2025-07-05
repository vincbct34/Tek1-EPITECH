/*
** EPITECH PROJECT, 2024
** my_sokoban
** File description:
** structure.h
*/

#pragma once

// Linked list of the boxes

typedef struct linked_list_object {
    int box_x;
    int box_y;
    int nb_x;
    struct linked_list_object *next;
} object;

// Linked list of the storage

typedef struct linked_list_storage {
    int storage_x;
    int storage_y;
    int nb_o;
    struct linked_list_storage *next;
} storage;

// Player structure

typedef struct struct_player {
    int player_x;
    int player_y;
    int nb_p;
} player;

// Sokoban structure

typedef struct sokoban_struct_s {
    char **map;
    player *player;
    object *object;
    storage *storage;
} sokoban_struct;
