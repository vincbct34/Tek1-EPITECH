/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#pragma once
#include <SFML/Graphics.h>
#include "sim.h"

int start_simulation(win_t *window, char const *script_path);
void loop_sim(sim_t *sim);
void loop_pl(pl_t *plane, sim_t *sim, unsigned int c_time);
void pl_ins_quadtr(pl_t **planes, quadtree_t *quadtree,
    unsigned int c_time);
