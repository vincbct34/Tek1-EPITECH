/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** Main of the project Setting Up
*/

#include "../include/my.h"
#include "../include/structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

int main(int ac, char **av)
{
    map_t *map = malloc(sizeof(map_t));
    char **arr;

    if (ac == 2 && (av[1][0] < '0' || av[1][0] > '9')) {
        is_file_valid(ac, av, av[1]);
        arr = load_2d_arr_from_file(av[1], map);
        find_biggest_square(arr, map);
    } else if (ac == 3 && my_strlen(av[2]) != 0) {
        error_gestion_gen(ac, av);
        arr = create_square(ac, av, map);
    } else
        return 84;
    for (int i = 0; i < map->nb_rows; i++) {
        if (arr[i])
            write(1, arr[i], map->nb_cols);
        write(1, "\n", 1);
    }
}

int is_file_valid(int ac, char **av, char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat st;

    av = av;
    ac = ac;
    if (fd == -1)
        exit(84);
    stat(filepath, &st);
    if (st.st_size == 0)
        exit(84);
    close(fd);
    return 0;
}

int error_gestion_gen(int ac, char **av)
{
    ac = ac;
    for (int i = 0; av[1][i]; i++) {
        if (av[1][i] < '0' || av[1][i] > '9') {
            exit(84);
        }
    }
    for (int i = 0; av[2][i]; i++) {
        if (av[2][i] != '.' && av[2][i] != 'o') {
            exit(84);
        }
    }
    return 0;
}
