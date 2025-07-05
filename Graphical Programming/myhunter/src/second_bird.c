/*
** EPITECH PROJECT, 2023
** second_bird.c
** File description:
** Second entity shown during the game
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

void kill_second_bird(global_t *all)
{
    sfFloatRect bird = sfSprite_getGlobalBounds(SCNDBIRDSPRITE);
    sfVector2i mousePosition = sfMouse_getPositionRenderWindow(WIN);
    sfVector2f mousePositionFloat = sfRenderWindow_mapPixelToCoords(WIN,
        mousePosition, NULL);

    if (sfFloatRect_contains(&bird, mousePositionFloat.x,
        mousePositionFloat.y)) {
        all->count++;
        sfSprite_setPosition(SCNDBIRDSPRITE, (sfVector2f){-200,
            (rand() % 1080)});
        }
}

void move_second_bird(global_t *all)
{
    sfTime time = sfClock_getElapsedTime(all->images[7].clock);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 0.1) {
        move_rect(all, 110, 330);
        sfClock_restart(all->images[8].clock);
    }
    sfSprite_move(SCNDBIRDSPRITE, (sfVector2f){12, 0});
    if (sfSprite_getPosition(SCNDBIRDSPRITE).x > 1920) {
        sfSprite_setPosition(SCNDBIRDSPRITE, (sfVector2f){-200,
        (rand() % 1080)});
        all->life--;
    }
}

void move_rect2(global_t *all, int offset, int max_value)
{
    all->images[8].rect.left = all->images[8].rect.left + offset;
    if (all->images[8].rect.left == max_value)
        all->images[8].rect.left = 0;
    sfSprite_setTextureRect(SCNDBIRDSPRITE, all->images[8].rect);
}

void second_bird_sprite(global_t *all)
{
    all->images[8].texture = sfTexture_createFromFile(SCNDBIRD, NULL);
    SCNDBIRDSPRITE = sfSprite_create();
    all->images[8].rect = (sfIntRect){0, 0, 110, 110};
    all->images[8].clock = sfClock_create();
    sfSprite_setTexture(SCNDBIRDSPRITE, all->images[8].texture, sfTrue);
    sfSprite_setPosition(SCNDBIRDSPRITE, (sfVector2f){0, 0});
}
