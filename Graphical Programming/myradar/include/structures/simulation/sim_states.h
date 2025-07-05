/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Header file for structure sim_states
*/

#pragma once
#include <SFML/Graphics.h>

typedef sfBool Bool;

typedef struct sim_states {
    Bool show_hitbox;
    Bool show_sprites;
    Bool is_paused;
} sim_states_t;
typedef sim_states_t states_t;

sim_states_t *create_sim_states(void);
void destroy_sim_states(sim_states_t *);
