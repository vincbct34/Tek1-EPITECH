/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Header file for quadtree structure
*/

#pragma once
#include <SFML/Graphics.h>
#include "plane.h"
#define QT_CAPACITY      4

typedef struct quadtree {
    sfIntRect boundary;
    pl_t **planes;
    unsigned int nb_planes;
    struct quadtree **children;
    sfBool is_divided;
} quadtree_t;

quadtree_t *quadtr_create(sfIntRect boundary);
void quadtr_clear(quadtree_t *quadtree);
int quadtr_ins(quadtree_t *quadtree, pl_t *plane);
pl_t **quadtr_qu(quadtree_t *quadtree, sfIntRect const area);
unsigned int quadtr_nb_pl(quadtree_t *quadtree,
    sfIntRect const area);
int quadtr_div(quadtree_t **quadtree);
