/*
** EPITECH PROJECT, 2024
** my_sokoban
** File description:
** map_handling.c
*/

#include "../include/my.h"
#include "../include/sokoban.h"
#include "../include/structure.h"

static int get_cols(char *buffer)
{
    int max_cols = 0;
    int nb_cols = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        ++nb_cols;
        if (nb_cols > max_cols)
            max_cols = nb_cols;
        if (buffer[i] == '\n')
            nb_cols = 0;
    }
    return max_cols;
}

static int get_rows(char *buffer)
{
    int nb_rows = 1;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            ++nb_rows;
    }
    return nb_rows;
}

char *load_file_in_mem(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat st;
    char *buffer;

    stat(filepath, &st);
    buffer = malloc(sizeof(char) * (st.st_size + 1));
    read(fd, buffer, st.st_size);
    buffer[st.st_size] = '\0';
    close(fd);
    return buffer;
}

int fill_map(sokoban_struct *sokoban, char *buffer)
{
    int row = 0;
    int col = 0;
    int rows = get_rows(buffer);
    int cols = get_cols(buffer);

    sokoban->map = malloc(sizeof(char *) * (rows + 1));
    for (int i = 0; i <= rows; i++)
        sokoban->map[i] = malloc(sizeof(char) * (cols + 1));
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            sokoban->map[row][col] = '\0';
            row++;
            col = 0;
        } else {
            sokoban->map[row][col] = buffer[i];
            col++;
        }
    }
    return 0;
}

static void error_handling_p(sokoban_struct *sokoban, int i, int j)
{
    if (sokoban->map[i][j] == 'P')
        sokoban->player->nb_p++;
}

static void error_handling_x(sokoban_struct *sokoban, int i, int j)
{
    if (sokoban->map[i][j] == 'X')
        sokoban->object->nb_x++;
}

static void error_handling_o(sokoban_struct *sokoban, int i, int j)
{
    if (sokoban->map[i][j] == 'O')
        sokoban->storage->nb_o++;
}

void error_handling_bis(sokoban_struct *sokoban, int i, int j)
{
    if (sokoban->map[i][j] != 'P'
        && sokoban->map[i][j] != 'X'
        && sokoban->map[i][j] != 'O'
        && sokoban->map[i][j] != ' '
        && sokoban->map[i][j] != '#')
        exit(84);
}

int error_handling(sokoban_struct *sokoban)
{
    sokoban->player->nb_p = 0;
    sokoban->object->nb_x = 0;
    sokoban->storage->nb_o = 0;
    for (int i = 0; sokoban->map[i] != NULL; i++) {
        for (int j = 0; sokoban->map[i][j] != '\0'; j++) {
            error_handling_p(sokoban, i, j);
            error_handling_x(sokoban, i, j);
            error_handling_o(sokoban, i, j);
            error_handling_bis(sokoban, i, j);
        }
    }
    if (sokoban->player->nb_p != 1
        || sokoban->object->nb_x != sokoban->storage->nb_o)
        return 84;
    return 0;
}
