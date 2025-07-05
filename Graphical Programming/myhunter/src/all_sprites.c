/*
** EPITECH PROJECT, 2023
** all_sprites.c
** File description:
** all sprites of the project my_hunter
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

void initialize_sprites(global_t *all)
{
    all->images = malloc(sizeof(sprite_t) * 13);
    background_sprite(all);
    titlesprite(all);
    playsprite(all);
    settingsprite(all);
    quitsprite(all);
    scoresprite(all);
    shooter_sprite(all);
    bird_sprite(all);
    second_bird_sprite(all);
    third_bird_sprite(all);
    set_sprite(all);
    troll_sprite(all);
}

static void status_zero(global_t *all)
{
    sfRenderWindow_setMouseCursorVisible(WIN, sfTrue);
    sfRenderWindow_drawSprite(WIN, TITLESPRITE, NULL);
    sfRenderWindow_drawSprite(WIN, PLAYSPRITE, NULL);
    sfRenderWindow_drawSprite(WIN, SETTINGSPRITE, NULL);
    sfRenderWindow_drawSprite(WIN, QUITSPRITE, NULL);
}

static void status_one(global_t *all)
{
    sfRenderWindow_setMouseCursorVisible(WIN, sfFalse);
    sfRenderWindow_drawSprite(WIN, BIRDSPRITE, NULL);
    sfRenderWindow_drawSprite(WIN, SCNDBIRDSPRITE, NULL);
    sfRenderWindow_drawSprite(WIN, THRBIRDSPRITE, NULL);
    sfRenderWindow_drawSprite(WIN, SHOOTERSPRITE, NULL);
}

static void status_two(global_t *all)
{
    sfRenderWindow_setMouseCursorVisible(WIN, sfTrue);
    sfRenderWindow_drawSprite(WIN, SETSPRITE, NULL);
    sfRenderWindow_drawSprite(WIN, TROLLSPRITE, NULL);
}

static void status_three(global_t *all)
{
    sfRenderWindow_setMouseCursorVisible(WIN, sfTrue);
    sfRenderWindow_drawSprite(WIN, SETSPRITE, NULL);
}

void draw_sprites(global_t *all)
{
    sfRenderWindow_drawSprite(WIN, BACKSPRITE, NULL);
    if (all->status == 0)
        status_zero(all);
    if (all->status == 1)
        status_one(all);
    if (all->status == 2)
        status_two(all);
    if (all->status == 3)
        status_three(all);
}
