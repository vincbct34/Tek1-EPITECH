/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-amazed-vincent.bichat
** File description:
** init
*/

#include "maze.h"

static char *read_redirect(void)
{
    char *maze;
    ssize_t bytes_read;

    maze = malloc(2048 * sizeof(char));
    bytes_read = read(STDIN_FILENO, maze, 2048);
    maze[bytes_read] = '\0';
    return maze;
}

void init_struct(maze_t *maze)
{
    maze->file = NULL;
    maze->tab = NULL;
    maze->file = read_redirect();
    maze->tab = my_str_to_word_array(maze->file, '\n');
    maze->matrix = NULL;
    maze->rooms = NULL;
    maze->nb_rooms = 0;
    maze->nb_pipes = 0;
    maze->nb_robots = 0;
    maze->nb_start = 0;
    maze->nb_end = 0;
    maze->start = -1;
    maze->end = -1;
    maze->parse_stop = 1;
    maze->is_tunnel_passed = false;
}
