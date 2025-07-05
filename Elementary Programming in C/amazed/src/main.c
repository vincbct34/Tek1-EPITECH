/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-amazed-vincent.bichat
** File description:
** main
*/

#include "maze.h"

static void free_rooms(maze_t *maze)
{
    for (; maze->rooms != NULL; maze->rooms = maze->rooms->next) {
        free(maze->rooms->data);
        for (int i = 0; maze->rooms->check_type[i] != NULL; i++)
            free(maze->rooms->check_type[i]);
        free(maze->rooms->check_type);
        free(maze->rooms);
    }
}

static void free_all(maze_t *maze)
{
    free(maze->file);
    for (int i = 0; maze->tab[i] != NULL; i++)
        free(maze->tab[i]);
    free(maze->tab);
    free_rooms(maze);
    free(maze);
}

static int check_algo(maze_t *maze)
{
    if (maze->nb_rooms <= 0 || maze->nb_pipes <= 0)
        return 84;
    if (maze->nb_start != 1 || maze->nb_end != 1)
        return 84;
    return 0;
}

int main(int ac, char **)
{
    maze_t *maze = malloc(sizeof(maze_t));

    init_struct(maze);
    if (ac != 1 || parsing(maze) == 84)
        return 84;
    adjusting_values(maze, maze->rooms);
    print_needed(maze);
    if (check_algo(maze) != 84) {
        maze->matrix = create_matrix(maze);
        my_putstr("#moves\n");
        dijkstra(maze, maze->start, maze->end);
    }
    free_all(maze);
    return 0;
}
