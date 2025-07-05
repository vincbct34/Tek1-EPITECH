/*
** EPITECH PROJECT, 2023
** menu.c
** File description:
** Menu of the project my_hunter
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

void main_menu(global_t *all)
{
    while (sfRenderWindow_pollEvent(WIN, &all->parameters.event))
        events(all);
    sfRenderWindow_clear(WIN, sfBlack);
    sfRenderWindow_drawSprite(WIN, BACKSPRITE, NULL);
    draw_sprites(all);
    sfRenderWindow_display(WIN);
}
