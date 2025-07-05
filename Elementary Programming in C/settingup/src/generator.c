/*
** EPITECH PROJECT, 2023
** generator.c
** File description:
** Generate a arr from a given pattern
*/

#include "../include/my.h"
#include "../include/structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

char **create_square(int ac, char **av, map_t *map)
{
    int index;
    char **arr;
    char *pattern = av[2];
    int length = my_getnbr(av[1]);
    int pattern_length = my_strlen(pattern);

    map->nb_rows = length;
    map->nb_cols = length;
    arr = mem_alloc_2d_array(map);
    ac = ac;
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            index = (i * length + j) % pattern_length;
            arr[i][j] = pattern[index];
        }
        arr[i][length] = '\0';
    }
    find_biggest_square(arr, map);
    return arr;
}
