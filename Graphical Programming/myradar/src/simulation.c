/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stdio.h>
#include "usage.h"
#include "my_radar.h"
#include "draw.h"
#include "events.h"
#include "utils.h"
#include "collisions.h"
#include "my.h"
#include "utils.h"

int start_simulation(win_t *window, char const *script_path)
{
    sim_t *sim = NULL;

    sim = create_sim_from_script(window, script_path);
    if (sim == NULL) {
        my_puterr("Simulation couldn't be created.\n");
        return (MY_EXIT_FAILURE);
    }
    set_win_back(sim->window, sim->textures->sim_bg);
    sfClock_restart(sim->clock);
    while (sfRenderWindow_isOpen(sim->window->render)) {
        sim_events(sim->window->render, sim->state);
        sfRenderWindow_clear(sim->window->render, sfWhite);
        loop_sim(sim);
        draw_timer(sim->window->render, sim->clock);
        sfRenderWindow_display(sim->window->render);
        if (sim->planes[0] == NULL)
            return (MY_EXIT_SUCCESS);
    }
    sim_destroy(sim);
    return (MY_EXIT_SUCCESS);
}

void loop_sim(sim_t *sim)
{
    uint c_time = sfTime_asSeconds(sfClock_getElapsedTime(sim->clock));

    print_framerate();
    quadtr_clear(sim->quadtree);
    pl_ins_quadtr(sim->planes, sim->quadtree, c_time);
    draw_back(sim->window->render, sim->window->background);
    draw_tows(sim->window->render, sim->towers, sim->state);
    for (unsigned int i = 0; sim->planes[i]; i++)
        loop_pl(sim->planes[i], sim, c_time);
}

static void no_spaces3(unsigned int i, pl_t **planes)
{
    for (unsigned int j = i; planes[j]; j++) {
        planes[j] = planes[j + 1];
    }
}

void remove_pl(pl_t *plane, pl_t **planes)
{
    for (unsigned int i = 0; planes[i]; i++) {
        if (planes[i] == plane) {
            no_spaces3(i, planes);
            return;
        }
    }
}

void loop_pl(pl_t *plane, sim_t *sim, uint c_time)
{
    pl_t *coll_plane = NULL;

    if (plane->delay > c_time)
        return;
    coll_plane = collide_pl(plane, sim->towers, sim->quadtree);
    if (coll_plane) {
        remove_pl(coll_plane, sim->planes);
        remove_pl(plane, sim->planes);
        return;
    }
    draw_pl(sim->window->render, plane, sim->state);
    pl_move(plane, plane->path->step, sim->window->width);
    if (overpos(plane->path->pos, plane->path->end, 10.0)) {
        remove_pl(plane, sim->planes);
        return;
    }
}

void pl_ins_quadtr(pl_t **planes, quadtree_t *quadtree,
    uint c_time)
{
    for (unsigned int i = 0; planes[i]; i++)
        if (planes[i]->delay <= c_time)
            quadtr_ins(quadtree, planes[i]);
}
