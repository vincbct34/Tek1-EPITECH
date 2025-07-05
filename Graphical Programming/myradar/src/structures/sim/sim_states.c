/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "sim_states.h"

sim_states_t *create_sim_states(void)
{
    sim_states_t *states = malloc(sizeof(sim_states_t));

    if (!states)
        return (NULL);
    states->show_hitbox = sfTrue;
    states->show_sprites = sfTrue;
    return (states);
}

void destroy_sim_states(sim_states_t *states)
{
    if (states)
        free(states);
}
