/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Header file for simulation structure
*/

#pragma once
#include <SFML/Graphics.h>
#include "window.h"
#include "quadtree.h"
#include "plane.h"
#include "tower.h"
#include "sim_textures.h"
#include "sim_states.h"

typedef struct sim {
    win_t *window;
    quadtree_t *quadtree;
    pl_t **planes;
    tow_t **towers;
    textures_t *textures;
    states_t *state;
    sfClock *clock;
} sim_t;

sim_t *create_sim(win_t *window);
sim_t *create_sim_from_script(win_t *window, char const *filepath);
void sim_destroy(sim_t *sim);
void init_timer(void);
void draw_timer(sfRenderWindow *window, sfClock *clock);
void print_framerate(void);
