/*
** EPITECH PROJECT, 2023
** count_island
** File description:
** Project 2
*/

#include <stddef.h>

int replace_island(char **world, int compt, int y, int x)
{
    if (x < 0 || y < 0 || world[y] == NULL)
        return 0;
    if (world[y] [x] != 'X')
        return 0;
    world[y] [x] = compt + '0';
    replace_island(world, compt, y + 1, x);
    replace_island(world, compt, y - 1, x);
    replace_island(world, compt, y, x + 1);
    replace_island(world, compt, y, x - 1);
    return 0;
}

int count(char **world, int *compt, int k)
{
    for (int i = 0; world[k][i] != '\0'; i++) {
        if (world[k] [i] == 'X') {
            replace_island(world, *compt, k, i);
            *compt = *compt + 1;
        }
    }
    return 0;
}

int count_island(char **world)
{
    int compt = 0;

    for (int i = 0; world[i] != NULL; i++)
        count(world, &compt, i);
    return compt;
}
