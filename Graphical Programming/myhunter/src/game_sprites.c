/*
** EPITECH PROJECT, 2023
** game_sprites.c
** File description:
** Game sprites of the project my_hunter
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

void kill_bird(global_t *all)
{
    sfFloatRect bird = sfSprite_getGlobalBounds(BIRDSPRITE);
    sfVector2i mousePosition = sfMouse_getPositionRenderWindow(WIN);
    sfVector2f mousePositionFloat = sfRenderWindow_mapPixelToCoords(WIN,
        mousePosition, NULL);

    if (sfFloatRect_contains(&bird, mousePositionFloat.x,
        mousePositionFloat.y)) {
        all->count++;
        sfSprite_setPosition(BIRDSPRITE, (sfVector2f){-200, (rand() % 1080)});
        }
}

void move_bird(global_t *all)
{
    sfTime time = sfClock_getElapsedTime(all->images[7].clock);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 0.1) {
        move_rect(all, 110, 330);
        sfClock_restart(all->images[7].clock);
    }
    sfSprite_move(BIRDSPRITE, (sfVector2f){10, 0});
    if (sfSprite_getPosition(BIRDSPRITE).x > 1920) {
        sfSprite_setPosition(BIRDSPRITE, (sfVector2f){-200, (rand() % 1080)});
        all->life--;
    }
}

void shooter_sprite(global_t *all)
{
    all->images[6].texture = sfTexture_createFromFile(SHOOTER, NULL);
    SHOOTERSPRITE = sfSprite_create();
    sfSprite_setTexture(SHOOTERSPRITE, all->images[6].texture, sfTrue);
    sfSprite_setScale(SHOOTERSPRITE, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(SHOOTERSPRITE, (sfVector2f){CURSORX, CURSORY});
}

void move_rect(global_t *all, int offset, int max_value)
{
    all->images[7].rect.left = all->images[7].rect.left + offset;
    if (all->images[7].rect.left == max_value)
        all->images[7].rect.left = 0;
    sfSprite_setTextureRect(BIRDSPRITE, all->images[7].rect);
}

void bird_sprite(global_t *all)
{
    all->images[7].texture = sfTexture_createFromFile(BIRD, NULL);
    BIRDSPRITE = sfSprite_create();
    all->images[7].rect = (sfIntRect){0, 0, 110, 110};
    all->images[7].clock = sfClock_create();
    sfSprite_setTexture(BIRDSPRITE, all->images[7].texture, sfTrue);
    sfSprite_setPosition(BIRDSPRITE, (sfVector2f){0, 0});
}
