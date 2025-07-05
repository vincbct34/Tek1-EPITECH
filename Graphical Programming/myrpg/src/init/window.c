/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** window
*/

#include "my_rpg.h"

void init_window(windows_t *window_data)
{
    window_data->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 64},
    "Valkyria", sfClose | sfResize, NULL);
    window_data->clock = malloc(sizeof(clock_data_t));
    window_data->clock->clock = sfClock_create();
    sfRenderWindow_setFramerateLimit(window_data->window, 60);
}
