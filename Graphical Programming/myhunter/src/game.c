/*
** EPITECH PROJECT, 2023
** game.c
** File description:
** Game of the project my_hunter
*/

#include "../header/structure.h"
#include "../header/my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Music.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Event.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

void game(global_t *all)
{
    while (sfRenderWindow_pollEvent(WIN, &all->parameters.event))
        events(all);
    move_bird(all);
    move_second_bird(all);
    move_third_bird(all);
    sfRenderWindow_clear(WIN, sfBlack);
    draw_sprites(all);
    sfRenderWindow_display(WIN);
}
