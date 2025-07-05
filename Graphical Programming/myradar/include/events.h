/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#pragma once
#include <SFML/Graphics.h>
#include "sim.h"

void sim_events(sfRenderWindow *render, states_t *state);
void quit_win(sfEvent *event, sfRenderWindow *window);
void disp_options(sfEvent *event, states_t *states);
