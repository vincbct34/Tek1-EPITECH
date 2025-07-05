/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#include <stdlib.h>
#include <SFML/System.h>
#include "sim.h"
#include "file_manipulation.h"
#include "window.h"
#include "plane.h"
#include "tower.h"

sim_t *create_sim(win_t *window)
{
    sim_t *sim = malloc(sizeof(sim_t));

    if (!sim)
        return (NULL);
    sim->window = window;
    sim->textures = create_sim_textures();
    sim->state = create_sim_states();
    sim->clock = sfClock_create();
    sim->quadtree = quadtr_create((sfIntRect) {0, 0,
                                    sim->window->width, sim->window->height});
    sim->planes = NULL;
    sim->towers = NULL;
    if (!(sim->textures) || !(sim->state))
        return (NULL);
    if (!(sim->quadtree) || !(sim->clock))
        return (NULL);
    return (sim);
}

sim_t *create_sim_from_script(win_t *window, char const *script_path)
{
    sim_t *sim = create_sim(window);

    if (!sim)
        return (NULL);
    if (get_entities_from_file(script_path, sim) != 0)
        return (NULL);
    return (sim);
}

void sim_destroy(sim_t *sim)
{
    destroy_win(sim->window);
    sfClock_destroy(sim->clock);
    destroy_sim_textures(sim->textures);
    destroy_sim_states(sim->state);
    for (unsigned int i = 0; sim->towers[i]; i++)
        destroy_tower(sim->towers[i]);
    for (unsigned int i = 0; sim->planes[i]; i++)
        pl_destroy(sim->planes[i]);
    if (sim->quadtree) {
        quadtr_clear(sim->quadtree);
        free(sim->quadtree);
    }
    if (sim)
        free(sim);
}
