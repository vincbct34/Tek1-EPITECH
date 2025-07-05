/*
** EPITECH PROJECT, 2023
** solver.c
** File description:
** Find the biggest square of a map, and replace characters by 'x'
*/

#include "../include/my.h"
#include "../include/structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char **mem_alloc_2d_array(map_t *map)
{
    char **array = malloc(sizeof(char *) * (map->nb_rows + 1));

    for (int i = 0; i < map->nb_rows; i++)
        array[i] = malloc(sizeof(char) * (map->nb_cols + 1));
    return array;
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

char **load_2d_arr_from_file(char const *filepath, map_t *map)
{
    char *buffer = load_file_in_mem(filepath);
    char **arr;
    int j = 0;
    int k = 0;

    map->nb_rows = my_getnbr(buffer);
    for (k = 0; buffer[k] && buffer[k] != '\n'; k++);
    k++;
    map->nb_cols = my_getcolons(buffer, k);
    arr = mem_alloc_2d_array(map);
    for (int i = 0; i < map->nb_rows; i++) {
        for (j = 0; j < map->nb_cols; j++) {
            arr[i][j] = buffer[k];
            k++;
        }
        arr[i][j] = '\0';
        k++;
    }
    free(buffer);
    return arr;
}

int is_square_of_size(char **map, int start_row, int start_col, int size)
{
    int result = 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result = (map[start_row + i][start_col + j] == 'o') ? 0 : result;
        }
    }
    return result;
}

static void replace_biggest_square(char **arr, map_t *map)
{
    for (int row = map->max_square_row;
        row < map->max_square_row + map->square_size_max; row++) {
        for (int col = map->max_square_col;
            col < map->max_square_col + map->square_size_max; col++) {
            arr[row][col] = 'x';
        }
    }
}

static void find_biggest_square_bis(char **arr, map_t *map, int row)
{
    for (int col = 0; col < map->nb_cols; col++) {
        map->square_size = 1;
        while (map->square_size <= map->nb_rows - row &&
            map->square_size <= map->nb_cols - col &&
                is_square_of_size(arr, row, col, map->square_size) == 1)
            map->square_size++;
        map->square_size--;
        if (map->square_size > map->square_size_max) {
            map->square_size_max = map->square_size;
            map->max_square_row = row;
            map->max_square_col = col;
        }
    }
}

int find_biggest_square(char **arr, map_t *map)
{
    map->square_size = 0;
    map->square_size_max = 0;
    map->max_square_row = 0;
    map->max_square_col = 0;
    for (int row = 0; row < map->nb_rows; row++)
        find_biggest_square_bis(arr, map, row);
    replace_biggest_square(arr, map);
    return map->square_size_max;
}
