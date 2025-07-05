/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-amazed-vincent.bichat
** File description:
** matrix
*/

#include "maze.h"

int **fill_matrix(maze_t *maze, int **matrix)
{
    int i = 0;
    int j = 0;

    for (; maze->rooms != NULL; maze->rooms = maze->rooms->next) {
        if (maze->rooms->is_pipe == true) {
            i = my_getnbr(maze->rooms->data);
            j = my_getlastnbr(maze->rooms->data);
            matrix[i][j] = 1;
            matrix[j][i] = 1;
        }
    }
    return matrix;
}

int **create_matrix(maze_t *maze)
{
    int **matrix = malloc(sizeof(int *) * (maze->nb_rooms));

    for (int i = 0; i <= maze->nb_rooms; i++) {
        matrix[i] = malloc(sizeof(int) * (maze->nb_rooms));
        for (int j = 0; j <= maze->nb_rooms; j++)
            matrix[i][j] = 0;
    }
    matrix = fill_matrix(maze, matrix);
    return matrix;
}
