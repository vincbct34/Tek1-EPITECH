/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#pragma once
#include <SFML/Graphics.h>
#include "utils.h"
#include "window.h"
#include "plane.h"
#include "tower.h"

void draw_back(sfRenderWindow *window, sfSprite *background);
void draw_pl(sfRenderWindow *render, pl_t *plane, states_t *states);
void draw_tows(sfRenderWindow *window, tow_t **, states_t *states);
