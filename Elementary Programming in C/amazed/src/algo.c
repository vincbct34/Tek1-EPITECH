/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-amazed-vincent.bichat
** File description:
** algo
*/

#include "maze.h"
#include <limits.h>

static int get_path_length(int *path, int end)
{
    int length = 0;

    for (int i = 0; path[i] != -1; i++) {
        if (path[i] == end)
            break;
        length++;
    }
    return length;
}

static int get_index(dfs_params_t *all_path_params, int *path_lengths)
{
    int index = 0;
    int min = INT_MAX;

    for (int j = 0; j < all_path_params->all_paths_index; j++) {
        if (path_lengths[j] < min) {
            min = path_lengths[j];
            index = j;
        }
    }
    return index;
}

static data_robots_t *assign_paths_to_robots(maze_t *maze, int dest,
    dfs_params_t *all_path_params)
{
    data_robots_t *robots = malloc(sizeof(data_robots_t) * maze->nb_robots);
    int *path_lengths = malloc(sizeof(int) * all_path_params->all_paths_index);
    int *original_path_lengths = malloc(sizeof(int) *
        all_path_params->all_paths_index);
    int index = 0;

    for (int i = 0; i < all_path_params->all_paths_index; i++) {
        path_lengths[i] = get_path_length(all_path_params->all_paths[i], dest);
        original_path_lengths[i] = path_lengths[i];
    }
    for (int i = 0; i < maze->nb_robots; i++) {
        index = get_index(all_path_params, path_lengths);
        robots[i].path = all_path_params->all_paths[index];
        path_lengths[index] += 1;
        if (path_lengths[index] / 2 == original_path_lengths[index])
            path_lengths[index] -= 1;
        robots[i].id_room = maze->start;
        robots[i].last_id_room = -1;
    }
    return robots;
}

static int robot_finish(maze_t *maze, data_robots_t *robots,
    int i, int robot_arrived)
{
    robot_arrived += 1;
    maze->matrix[robots[i].last_id_room]
        [robots[i].path[robots[i].id_in_path]] = 1;
    maze->matrix[robots[i].path[robots[i].id_in_path]]
        [robots[i].last_id_room] = 1;
    robots[i].id_room = -1;
    return robot_arrived;
}

void go_to_next_room(data_robots_t *robots, maze_t *maze, int i)
{
    if (robots[i].last_id_room != -1) {
        maze->matrix[robots[i].last_id_room]
            [robots[i].path[robots[i].id_in_path]] = 1;
        maze->matrix[robots[i].path[robots[i].id_in_path]]
            [robots[i].last_id_room] = 1;
    }
    maze->matrix[robots[i].id_room][robots[i].path
        [robots[i].id_in_path + 1]] = 2;
    maze->matrix[robots[i].path[robots[i].
        id_in_path + 1]][robots[i].id_room] = 2;
    robots[i].last_id_room = robots[i].id_room;
    robots[i].id_room = robots[i].path[robots[i].id_in_path + 1];
    robots[i].id_in_path++;
    my_putchar('P');
    my_putnbr(i + 1);
    my_putchar('-');
    my_putnbr(robots[i].id_room);
    my_putchar(' ');
}

void check_if_near_end(data_robots_t *robots, maze_t *maze, int i)
{
    if (robots[i + 1].id_room == maze->end)
        go_to_next_room(robots, maze, i);
}

int cycle_robots(data_robots_t *robots, maze_t *maze, int robot_arrived)
{
    for (int i = 0; i != maze->nb_robots; i++) {
        if (robots[i].id_room == maze->end) {
            robot_arrived = robot_finish(maze, robots, i, robot_arrived);
            continue;
        }
        if (robots[i].id_room == -1)
            continue;
        if (maze->matrix[robots[i].id_room]
            [robots[i].path[robots[i].id_in_path + 1]] == 1 ||
        maze->matrix[robots[i].path[robots[i].id_in_path + 1]]
            [robots[i].id_room] == 1) {
            go_to_next_room(robots, maze, i);
        } else {
            check_if_near_end(robots, maze, i);
            continue;
        }
    }
    return robot_arrived;
}

void robots_run(data_robots_t *robots, maze_t *maze)
{
    int robot_arrived = 0;

    while (robot_arrived != maze->nb_robots) {
        robot_arrived = cycle_robots(robots, maze, robot_arrived);
        if (robot_arrived != maze->nb_robots)
            my_putchar('\n');
    }
}

void dijkstra(maze_t *maze, int pos, int dest)
{
    dfs_params_t *path_params = find_all_paths(maze, pos, dest);
    data_robots_t *robots = assign_paths_to_robots(maze, dest, path_params);

    robots_run(robots, maze);
}
