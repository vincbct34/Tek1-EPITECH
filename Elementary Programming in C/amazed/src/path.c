/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-amazed-vincent.bichat [WSL: Ubuntu-22.04]
** File description:
** path
*/

#include "maze.h"
#include <limits.h>

void dfs2(maze_t *maze, int pos, dfs_params_t *params)
{
    for (int i = 0; i < maze->nb_rooms; i++)
        if (maze->matrix[pos][i] == 1 && !params->visited[i])
            dfs(i, params, maze);
}

void dfs(int pos, dfs_params_t *params, maze_t *maze)
{
    int i = 0;

    params->visited[pos] = true;
    params->path[params->path_index] = pos;
    params->path_index++;
    if (pos == params->dest) {
        params->all_paths[params->all_paths_index] = malloc(sizeof(int) *
            (params->path_index + 1));
        for (; i < params->path_index; i++)
            params->all_paths[params->all_paths_index][i] = params->path[i];
        params->all_paths[params->all_paths_index][i] = -1;
        params->all_paths_index++;
    } else
        dfs2(maze, pos, params);
    params->path_index--;
    params->visited[pos] = false;
}

dfs_params_t *find_all_paths(maze_t *maze, int pos, int dest)
{
    dfs_params_t *params = malloc(sizeof(dfs_params_t));

    params->dest = dest;
    params->visited = malloc(sizeof(bool) * maze->nb_rooms);
    params->path = malloc(sizeof(int) * maze->nb_rooms);
    params->path_index = 0;
    params->all_paths = malloc(sizeof(int *) * maze->nb_rooms);
    params->all_paths_index = 0;
    for (int i = 0; i < maze->nb_rooms; i++)
        params->visited[i] = false;
    dfs(pos, params, maze);
    return params;
}
