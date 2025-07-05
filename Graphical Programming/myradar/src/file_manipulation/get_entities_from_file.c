/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** Second graphical project
*/

#include <stdio.h>
#include <stdlib.h>
#include "file_manipulation.h"
#include "sim.h"
#include "plane.h"
#include "path.h"
#include "tower.h"
#include "my.h"

int get_entities_from_file(char const *file_path, sim_t *sim)
{
    char *file_buffer = file_buff(file_path);
    unsigned int nb_planes = 0;
    unsigned int nb_towers = 0;
    FILE *stream = NULL;

    if (!file_buffer)
        return (1);
    nb_planes = nb_char(file_buffer, PLANE_SYMBOL);
    nb_towers = nb_char(file_buffer, TOWER_SYMBOL);
    sim->planes = malloc(sizeof(pl_t *) * (nb_planes + 1));
    sim->towers = malloc(sizeof(tow_t *) * (nb_towers + 1));
    stream = fopen(file_path, "r");
    if (!(sim->planes) || !(sim->towers) || !(stream))
        return (1);
    if (fill_entities_by_line(stream, sim) != 0)
        return (1);
    fclose(stream);
    return (0);
}

int fill_entities_by_line(FILE *stream, sim_t *sim)
{
    char *current_line = NULL;
    long unsigned int size = 50;
    unsigned int plane_index = 0;
    unsigned int tower_index = 0;

    while (getline(&current_line, &size, stream) != -1) {
        if (current_line[0] == PLANE_SYMBOL) {
            sim->planes[plane_index] = add_plane_from_line(current_line,
                sim->textures->plane, sim->window->width);
            plane_index++;
        }
        if (current_line[0] == TOWER_SYMBOL) {
            sim->towers[tower_index] = add_tower_from_line(current_line,
                sim->textures->tower);
            tower_index++;
        }
    }
    sim->planes[plane_index] = NULL;
    sim->towers[tower_index] = NULL;
    return (0);
}

pl_t *add_plane_from_line(char *current_line, sfTexture *pl_texture,
    unsigned int w_width)
{
    path_t *path = NULL;
    sfVector2f departure;
    sfVector2f arrival;
    unsigned int speed = 0;
    unsigned int delay = 0;

    current_line++;
    departure.x = my_strtol(current_line, &current_line);
    departure.y = my_strtol(current_line, &current_line);
    arrival.x = my_strtol(current_line, &current_line);
    arrival.y = my_strtol(current_line, &current_line);
    speed = my_strtol(current_line, &current_line);
    delay = my_strtol(current_line, &current_line);
    path = create_path(departure, arrival, speed, w_width);
    if (path == NULL)
        return (NULL);
    return (pl_create(path, pl_texture, delay, w_width));
}

tow_t *add_tower_from_line(char *current_line, sfTexture *tow_texture)
{
    sfVector2f pos;
    unsigned int radius = 0;

    current_line++;
    pos.x = my_strtol(current_line, &current_line);
    pos.y = my_strtol(current_line, &current_line);
    radius = my_strtol(current_line, &current_line);
    return (create_tower(pos, tow_texture, radius));
}
